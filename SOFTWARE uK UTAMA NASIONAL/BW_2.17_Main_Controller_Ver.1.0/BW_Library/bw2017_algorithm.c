/*==============================================================================================
								   PROJECT BW 2017 Ver.1.0
								     BW ALGORITHM LIBRARY
===============================================================================================*/

#include "bw2017_algorithm.h"
/*==============================================================================================
								   PRE-TRIAL FUNCTION
===============================================================================================*/

/* func      : void BW_Dimension_Check(void)
 * brief     : Detecting dimension checking condition and configuring locomotion to fit the dimension check box
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, October 15th 2015)
 * Revised BY: N/A
 * programmer's Note: Trigger the BW Dimension check routine by putting your hands <= 10 cm away from RIGHT and LEFT PING)))
 *
 */
void BW_Dimension_Check(void)
{
	BW_Buzz(3);

	while( (Ping[PING_LEFT]<=10)&&(Ping[PING_RIGHT]<=10) )
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_3cm(3,FAST_LEVEL_3);
		mov_fwd_2cm(2,FAST_LEVEL_3);
		BW_Buzz(1);
	}

	BW_Buzz(3);
}


void Sensor_Menu(void)
{
	int MENU_VAR=0;

//	while(BUTTON_IDLE)
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"SENSOR MONITOR");lcd_putstr(lcd);
//		delay_ms(100);
//	}

	if(BW_BUTTON_CLICKED)
	{
//		while(BUTTON_IDLE)
//		{
//			BW_Buzz(1);
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
//			lcd_gotoxy(0,1);sprintf(lcd,"SENSOR MONITOR");lcd_putstr(lcd);
//			delay_ms(100);
//		}

		while(1)
		{
			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				MENU_VAR++;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				MENU_VAR--;
			}

			if(MENU_VAR>10) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=10;

			switch(MENU_VAR)
			{
				case 0:
						{
							Display_Ping_Status ();
							Send_Ping_Status ();
						}break;

				case 1:
						{
							Get_IR();
							Display_Sharp_Status();
//							Display_IR_Stat();
						}break;
				case 2:
						{
							Display_Bumper_Stat();

						}break;
				case 3:
						{
							Display_FlameSense();
						}break;

				case 4:
						{
//							RoomTypeDetector();
							RoomDetector(1);
						}break;
				case 5:
						{
							PushTo_Burst();
//							BW_BLDC_Fight();
						}break;
				case 6:
						{
							Display_Yaw_Angle();
						}break;
				case 7:
						{
							Get_Data_Status();
						}break;

				case 8:
						{
							Get_TPA81();
						}break;
				case 9:
						{
							BW_Home_Detection_check();
						}break;

			}

		}

	}

}

void Nav_Test_Menu(void)
{
	int MENU_VAR=0;

	if(BW_BUTTON_CLICKED)
	{
		delay_ms(300);
		while(1)
		{

			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				MENU_VAR++;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				MENU_VAR--;
			}

			if(MENU_VAR>27) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=27;

			switch(MENU_VAR)
			{
				case 0:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_2();
						}break;

				case 1:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_3();
						}break;
				case 2:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_4A();
						}break;
				case 3:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_4B();
						}break;

				case 4:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1B to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1B_To_2();
						}break;
				case 5:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_2();
						}break;
				case 6:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_3();
						}break;
				case 7:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_4A();
						}break;
				case 8:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_4B();
						}break;
				case 9:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_1A();
						}break;
				case 10:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_3();
						}break;
				case 11:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_4A();
						}break;
				case 12:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_4B();
						}break;
				case 13:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_4B();
						}break;
				case 14:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2A to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2A_To_1BC();
						}break;
				case 15:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2B to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2B_To_1BC();
						}break;
				case 16:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_1A();
						}break;
				case 17:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_1BC();
						}break;
				case 18:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_2();
						}break;
				case 19:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_4A();
						}break;
				case 20:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_4B();
						}break;
				case 21:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4A to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4A_To_1A_VER2();
						}break;
				case 22:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4A to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4A_To_2();
						}break;
				case 23:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4A to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4A_To_3();
						}break;
				case 24:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_1A();
						}break;
				case 25:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_1BC();
						}break;
				case 26:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_2();
						}break;
				case 27:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_3();
						}break;

			}

		}

	}
}

/* func      : void BW_Home_Detection(void)
 * brief     : Detecting Home
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Sunday, October 15th 2015)
 * Revised BY: Ver.2 -> Ryan (Monday, March 15th 2016)
 * 				Configured for the KRPAI 2016 Rule (Red Zone Version)
 * programmer's Note:
 *
 */
void BW_Home_Detection(void)
{
	unsigned int HOME;
	int counter=0;

	HOME=1;
	if (HOME==1)
	{
		if (Ping[PING_FRONT]>25)
		{
//			BW_Buzz(1);
			if( Ping[PING_LEFT]>16 || Ping[PING_ASKEW_LEFT]>16)
			{
				if(Ping[PING_RIGHT]<16)
				{
					while(Ping[PING_RIGHT]<16)
					{
						mov_rot_right(FAST,FAR);
					}
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					while(Ping[PING_FRONT]<16)
					{
						mov_rot_right(FAST,FAR);
					}
					mov_fwd_5cm(5,FAST);
				}
				else
				{
					mov_rot_left(FAST,FAR); //adjust to correct position
					mov_rot_left(FAST,FAR); //adjust to correct position
					mov_rot_left(FAST,FAR); //adjust to correct position
					mov_rot_left(FAST,FAR);
//					mov_rot_left(FAST,FAR);
					while(
							(Ping[PING_LEFT]>=15) && (Ping[PING_ASKEW_LEFT]>=15)
						 )
					{
						mov_rot_left(FAST,FAR);
						mov_rot_left(FAST,FAR);
	//					mov_rot_left(FAST_LEVEL_3,CLOSE);
						if(Ping[PING_FRONT]<=13 )
						{
							mov_bwd_5cm(5,FAST);
						}
						counter++;

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROT COUNTER: %d",counter);lcd_putstr(lcd);
						delay_ms(100);

						if(counter>=1)
						{
							BW_Buzz(1);
							mov_deflect_left(FAST,CLOSE);
							mov_deflect_left(FAST,CLOSE);
							mov_deflect_left(FAST,CLOSE);

							mov_rot_left(FAST,FAR);
//							mov_fwd_5cm(5,FAST);

							BW_Buzz(1);
							BW_PID_Init();
							follow_left_counter(5);
						}

					}
				}
			}
		}

		else if(Ping[PING_FRONT]<=25)
		{
			BW_Buzz(2);

			while(
				   ( (Ping[PING_FRONT]<=25) && (Ping[PING_LEFT]>=15) ) ||
				   ( (Ping[PING_FRONT]<=25 && Ping[PING_LEFT]<=15)   )
				 )
			{
				if(Ping[PING_FRONT]<=13 )
				{
					mov_bwd_5cm(5,FAST);
				}
				mov_rot_right(FAST,FAR);
//				mov_rot_right(FAST_LEVEL_2,FAR);
			}
			while(Ping[PING_ASKEW_LEFT]<=15)
			{
				mov_rot_right(FAST,FAR);
//				mov_rot_right(FAST_LEVEL_2,FAR);
			}
		}

	}
}

/* func      : void BW_Home_Detection_Ver2(void)
 * brief     : Detecting Home
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (Wed, Dec 7th 2016)
 * Revised BY: Hafidin (Tue, Feb 28th 2017)
 *
 * programmer's Note:
 *
 */

void BW_Home_Detection_Ver2(void)
{
//	int counter=0;

	if(Ping[PING_ASKEW_LEFT]<15)
	{
		Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
		Dynamx_MovFwd3cm(3,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
	}

	if(Ping[PING_FRONT]<20)
	{
		while(((Ping[PING_ASKEW_LEFT]+1)!=Ping[PING_LEFT]) || ((Ping[PING_ASKEW_LEFT])!=Ping[PING_LEFT]))
		{
			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_CLOSE,IKCALC_ENABLE);
			if(((Ping[PING_ASKEW_LEFT]+1)==Ping[PING_LEFT]) || ((Ping[PING_ASKEW_LEFT])==Ping[PING_LEFT]))break;
		}
	}
	else if((Ping[PING_ASKEW_RIGHT]<20) && (Ping[PING_RIGHT]<20))
	{
		while(((Ping[PING_ASKEW_LEFT]+1)!=Ping[PING_LEFT]) || ((Ping[PING_ASKEW_LEFT])!=Ping[PING_LEFT]))
		{
			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_CLOSE,IKCALC_ENABLE);
			if(((Ping[PING_ASKEW_LEFT]+1)==Ping[PING_LEFT]) || ((Ping[PING_ASKEW_LEFT])==Ping[PING_LEFT]))break;
		}
	}
	else
	{
		while(((Ping[PING_ASKEW_LEFT]+1)!=Ping[PING_LEFT]) || ((Ping[PING_ASKEW_LEFT])!=Ping[PING_LEFT]))
		{
			Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_CLOSE,IKCALC_ENABLE);
			if(((Ping[PING_ASKEW_LEFT]+1)==Ping[PING_LEFT]) || ((Ping[PING_ASKEW_LEFT])==Ping[PING_LEFT]))break;
		}
	}

	Dynamx_MovFwd3cm(6,HEXSPD_ULTRAFAST,IKCALC_ENABLE);

	if(Ping[PING_ASKEW_LEFT]>25)
	{
		Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

		Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
		Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//		Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
		Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
//		Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);

		while(Ping[PING_RIGHT]<20)
		{
			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_CLOSE,IKCALC_ENABLE);
		}

		while(Ping[PING_FRONT]<20)
		{
			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_CLOSE,IKCALC_ENABLE);
		}
	}
}

/* func      : void BW_Home_Detection_Ver3(void)
 * brief     : Detecting Home
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Hafidin (Sunday, March 12th 2017)
 * Revised BY:
 *
 * programmer's Note:
 *
 */

void BW_Home_Detection_Ver3(void)
{
	if((Ping[PING_FRONT]<20) || (Ping[PING_ASKEW_LEFT]<20))
	{
		while(((Ping[PING_ASKEW_LEFT]>12) && (Ping[PING_REAR_LEFT]>12)) && ((Ping[PING_REAR_LEFT])!=(Ping[PING_ASKEW_LEFT]+1)))
		{
			Dynamx_Rot_Right(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);
			Dynamx_Rot_Right(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);
			if(((Ping[PING_ASKEW_LEFT]<12) && (Ping[PING_REAR_LEFT]<12)) && ((Ping[PING_REAR_LEFT])==(Ping[PING_ASKEW_LEFT]+1)))break;
		}
		Dynamx_Rot_Right(HEXSPD_SLOW,HEXSTEP_MED,IKCALC_ENABLE);
//		Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
	}
	else
	{
		while(((Ping[PING_ASKEW_LEFT]>12) && (Ping[PING_REAR_LEFT]>12)) && ((Ping[PING_REAR_LEFT])!=(Ping[PING_ASKEW_LEFT]+1)))
		{
			Dynamx_Rot_Left(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);
			Dynamx_Rot_Left(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);
			if(((Ping[PING_ASKEW_LEFT]<12) && (Ping[PING_REAR_LEFT]<12)) && ((Ping[PING_REAR_LEFT])==(Ping[PING_ASKEW_LEFT]+1)))break;
		}
		Dynamx_Rot_Left(HEXSPD_SLOW,HEXSTEP_MED,IKCALC_ENABLE);
//		Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
	}
}

/* func      : void BW_Home_Detection_2017(void)
 * brief     : Detecting Home and Positioning
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Hafidin (MISSING NOTES)
 * Revised BY: Ver.2: Ryan (Saturday, April 22nd, 2017)
 * 					Added Get_West_Status() function calls
 * 			   Ver.3: Ryan (Sunday, April 23rd, 2017)
 * 					New parameter for determining robot position
 * 			   Ver.4: Ryan (Sunday, April 23rd, 2017)
 * 					Rotation parameter when correcting robot's position in case of HOME CIRCLE CORNER POSITION
 * programmer's Note:
 */
void BW_Home_Detection_2017(void)
{

//	if	(( (Ping[PING_ASKEW_RIGHT]<15) && (Ping[PING_REAR_RIGHT]<15))	||
//		 ( (Ping[PING_REAR_RIGHT]<15) && (Ping[PING_REAR_LEFT]<15))		||
//		 ( (Ping[PING_ASKEW_LEFT]<15) && (Ping[PING_REAR_LEFT]<15))		||
//		 ( (Ping[PING_ASKEW_LEFT]<15) && (Ping[PING_ASKEW_RIGHT]<15))
//		)
	/*
	 *  Ryan (Sunday, April 23rd, 2017
	 *  Hafidin (Sunday, June 4th, 2017)
	 */
	if  (
			( (Ping[PING_LEFT]<=20) && ((Ping[PING_ASKEW_LEFT]<=25)||(Ping[PING_REAR_LEFT]<=25)))
			||
			( (Ping[PING_RIGHT]<=20) && ((Ping[PING_ASKEW_RIGHT]<=25)||(Ping[PING_REAR_RIGHT]<=25)))
			||
				//KONDISI ROBOT DI POJOK RUANG MENGHADAP KE TENGAH RUANGAN
			(
					((Ping[PING_REAR_LEFT]<=25)||(Ping[PING_LEFT]<=20))
					&&
					((Ping[PING_REAR_RIGHT]<=25)||(Ping[PING_RIGHT]<=20))
			)

			||

			((Ping[PING_ASKEW_RIGHT]<=25) && (Ping[PING_ASKEW_LEFT]<=25))
		)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
		delay_ms(50);

		HOME_POS=POJOK;

		Get_IR();
		if((INFRARED[IR_MID_RIGHT]==IR_DETECTED) && (Ping[PING_LEFT]<20) && (Ping[PING_FRONT]<20))
		{
			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
			FOLLOW_FLAG=KIRI;
		}
		else
		{
			if((Ping[PING_FRONT]>20) && (Ping[PING_LEFT]<20))
			{
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				while((Ping[PING_FRONT]>20) && (Ping[PING_RIGHT]>17))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}
			}

			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
			FOLLOW_FLAG=KANAN;
		}
//		if(Ping[PING_FRONT]<17)
//		if  (
//				(Ping[PING_LEFT]+Ping[PING_ASKEW_LEFT]+Ping[PING_REAR_LEFT])
//				<=
//				(Ping[PING_RIGHT]+Ping[PING_ASKEW_RIGHT]+Ping[PING_REAR_RIGHT])
//			)
//		{
//			while(Ping[PING_FRONT]<20)
//			{
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//			}
//			FOLLOW_FLAG=KIRI;
//
//
//		}
//		else
//		{
//			while(Ping[PING_FRONT]<20)
//			{
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//			}
//			FOLLOW_FLAG=KANAN;
//
//		}
	}
	else
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
		delay_ms(50);

		HOME_POS=TENGAH;
		//====================================================================//
		ARENA_FLAG=CMPS_INACTIVE;
		Get_East_Status();

		while(ARENA_FLAG==CMPS_INACTIVE)
		{
			Get_East_Status();

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
			delay_ms(20);

			if(ARENA_FLAG==CMPS_ACTIVE)
			{
				lcd_gotoxy(0,2);sprintf(lcd,"CMPSFLG ACTIVE");lcd_putstr(lcd);
			}
			else
			{
				lcd_gotoxy(0,2);sprintf(lcd,"CMPSFLG INACTIVE");lcd_putstr(lcd);
			}

//			if(CMPS11_Angle>NORTH_THRESHOLD_UPPER)
			if(CMPS11_Angle>WEST_THRESHOLD_UPPER)
//			if(CMPS11_Angle>SOUTH_THRESHOLD_UPPER)
//			if(CMPS11_Angle>EAST_THRESHOLD_UPPER)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				TRESH_FLAG=TRESH_UPPER;
			}
//			else if(CMPS11_Angle<NORTH_THRESHOLD_UPPER)
			else if(CMPS11_Angle<WEST_THRESHOLD_UPPER)
//			else if(CMPS11_Angle<SOUTH_THRESHOLD_UPPER)
//			else if(CMPS11_Angle<EAST_THRESHOLD_UPPER)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				TRESH_FLAG=TRESH_LOWER;
			}
			else break;
		}

//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

//		THIS SECTIONS OMITTED DUE TO ORIENTATION FLAG CHANGES

//		if(Ping[PING_FRONT]>34)		//khusus ruang 1
//		{
////			while((a<330) || (a>30))
////			{
////				GetCMPS11_Angle8Bit();
////				a=BW_CMPS11.Compass8Bit;
////
////				lcd_display_clear();
////				lcd_gotoxy(0,0);sprintf(lcd,"ANGLE: %d",a);lcd_putstr(lcd);
////				delay_ms(20);
////
////				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
////			}
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//		}
	}
}

void BW_Home_Detection_2017_2(void)
{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
	delay_ms(50);

	HOME_POS=POJOK;

	if(Ping[PING_RIGHT]>20)
	{
		Get_IR();
		if((INFRARED[IR_MID_RIGHT]==IR_DETECTED
				) && (Ping[PING_LEFT]<20) && (Ping[PING_FRONT]<20))
		{
			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			if(((Ping[PING_ASKEW_LEFT] && Ping[PING_REAR_LEFT])<=11) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

				if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
//							{
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
//								{
//									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//									if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
//									{
//										Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//									}
//								}
//							}
						}
					}
				}

			FOLLOW_FLAG=KIRI;
		}
		else if(Ping[PING_FRONT]<20)
		{
			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

			if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//						{
//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//							{
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//								{
//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								}
//							}
//						}
					}
				}
			}

			FOLLOW_FLAG=KANAN;
		}
		else
		{
			if (Ping[PING_LEFT]<20)
			{
				while(Ping[PING_FRONT]>20)
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//							{
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//								{
//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//									if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//									{
//										Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//									}
//								}
//							}
						}
					}
				}
			}
			else
			{
				while(Ping[PING_RIGHT]>20)
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//							{
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//								{
//									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//									if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//									{
//										Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//									}
//								}
//							}
						}
					}
				}

			}
			FOLLOW_FLAG=KANAN;
		}
	}
	else
	{
		//Get_IR();
		if((((Ping[PING_ASKEW_RIGHT]<9) && (Ping[PING_RIGHT]<9) && (Ping[PING_REAR_RIGHT]<9)) && (Ping[PING_FRONT]<10) && ((Ping[PING_LEFT]<30) || (Ping[PING_ASKEW_LEFT]<30))) && (Ping[PING_REAR]>50))//(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED))
		{
			while(Ping[PING_RIGHT]<20)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			if(((Ping[PING_ASKEW_LEFT] && Ping[PING_REAR_LEFT])<=11) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

			if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
//							{
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
//								{
//									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								}
//							}
//						}
					}
				}
			}

			FOLLOW_FLAG=KIRI;
		}
		else if((Ping[PING_RIGHT]<20) && (Ping[PING_LEFT]<20))
		{
			while(Ping[PING_LEFT]<20)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
			while(Ping[PING_LEFT]>20)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

			if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//						{
//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//							{
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//								{
//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								}
//							}
//						}
					}
				}
			}

			FOLLOW_FLAG=KANAN;
		}
		else
		{
			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

			if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//						{
//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//							{
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
//								{
//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								}
//							}
//						}
					}
				}
			}

			FOLLOW_FLAG=KANAN;
		}
	}
}

/* func      : void BW_Home_Detection_2017(void)
 * brief     : Detecting Home and Positioning
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Toni(Tuesday, December 12th
 * Revised BY:
 * programmer's Note:
 */
void BW_Home_Detection_2017_3(void)
{
	int a=0;
	if  (
			( (Ping[PING_LEFT]<=20) && ((Ping[PING_ASKEW_LEFT]<=25)&&(Ping[PING_REAR_LEFT]<=25)))
			||
			( (Ping[PING_RIGHT]<=20) && ((Ping[PING_ASKEW_RIGHT]<=25)&&(Ping[PING_REAR_RIGHT]<=25)))
			||
				//KONDISI ROBOT DI POJOK RUANG MENGHADAP KE TENGAH RUANGAN
			(
					((Ping[PING_REAR_LEFT]<=25)||(Ping[PING_LEFT]<=20))
					&&
					((Ping[PING_REAR_RIGHT]<=25)||(Ping[PING_RIGHT]<=20))
					&&
					(Ping[PING_REAR]<=25)
			)

			||

			((Ping[PING_ASKEW_RIGHT]<=25) && (Ping[PING_ASKEW_LEFT]<=25))
		)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
		delay_ms(50);

		HOME_POS=POJOK;

		if(Ping[PING_RIGHT]>20)
		{
			//Get_IR();
			if((Ping[PING_REAR]<=20) && (Ping[PING_LEFT]<20) && (Ping[PING_FRONT]<20))
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT] && Ping[PING_REAR_LEFT])<=11) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
							{
								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//							if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
	//							{
	//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
	//								{
	//									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//									if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
	//									{
	//										Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//									}
	//								}
	//							}
							}
						}
					}

//				FOLLOW_FLAG=KIRI;
				FOLLOW_FLAG=KANAN;
			}
			else if(Ping[PING_FRONT]<20)
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//						{
	//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//							{
	//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//								{
	//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								}
	//							}
	//						}
						}
					}
				}

				FOLLOW_FLAG=KANAN;
			}
			else
			{
				if (Ping[PING_LEFT]<20)
				{

					while(Ping[PING_FRONT]>20)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						a++;
						if(a>10)break;
					}
					while(Ping[PING_FRONT]<20)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					}

					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					}

					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
							{
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//							{
	//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//								{
	//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//									if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//									{
	//										Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//									}
	//								}
	//							}
							}
						}
					}
				}
				else
				{
					while(Ping[PING_RIGHT]>20)
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						a++;
						if(a>10)break;

					}

					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					}

					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
							{
								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//							{
	//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//								{
	//									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//									if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//									{
	//										Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//									}
	//								}
	//							}
							}
						}
					}

				}
				FOLLOW_FLAG=KANAN;
			}
		}
		else
		{
			//Get_IR();
			if((((Ping[PING_ASKEW_RIGHT]<9) && (Ping[PING_RIGHT]<9) && (Ping[PING_REAR_RIGHT]<9)) && (Ping[PING_FRONT]<10) && ((Ping[PING_LEFT]<30) || (Ping[PING_ASKEW_LEFT]<30))) && (Ping[PING_REAR]>50))//(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED))
			{
				while(Ping[PING_RIGHT]<20)
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT] && Ping[PING_REAR_LEFT])<=11) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
	//						{
	//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//							if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
	//							{
	//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
	//								{
	//									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								}
	//							}
	//						}
						}
					}
				}

				FOLLOW_FLAG=KIRI;
			}
			else if((Ping[PING_RIGHT]<10) && (Ping[PING_LEFT]<10))
			{
				while(Ping[PING_LEFT]<20)
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}
				while(Ping[PING_LEFT]>20)
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					a++;
					if(a>10)break;

				}

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//						{
	//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//							{
	//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//								{
	//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								}
	//							}
	//						}
						}
					}
				}

				FOLLOW_FLAG=KANAN;
			}
			else
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT] && Ping[PING_REAR_RIGHT])<=11) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//						{
	//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//							{
	//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
	//								{
	//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//								}
	//							}
	//						}
						}
					}
				}

				FOLLOW_FLAG=KANAN;
			}
		}
	}
	else
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
		delay_ms(50);

		HOME_POS=TENGAH;

//		ARENA_FLAG=CMPS_INACTIVE;
//		Get_North_Status();

//		while(ARENA_FLAG==CMPS_INACTIVE)
//		{
//			Get_North_Status();
			GetCMPS11_Angle8Bit();
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
			delay_ms(20);

//			if(ARENA_FLAG==CMPS_ACTIVE)
//			{
//				lcd_gotoxy(0,2);sprintf(lcd,"CMPSFLG ACTIVE");lcd_putstr(lcd);
//			}
//			else
//			{
//				lcd_gotoxy(0,2);sprintf(lcd,"CMPSFLG INACTIVE");lcd_putstr(lcd);
//			}

//			if(CMPS11_Angle>NORTH_THRESHOLD_UPPER)
//			if((CMPS11_Angle>(R4B_THRESHOLD_LOWER-25))&&(CMPS11_Angle<R4A_THRESHOLD_MIDDLE))
			if((CMPS11_Angle<(START_MIDDLE-10))||(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))

//			if(CMPS11_Angle>SOUTH_THRESHOLD_UPPER)
//			if(CMPS11_Angle>EAST_THRESHOLD_UPPER)
			{
				while((CMPS11_Angle<(START_MIDDLE-10))||(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					GetCMPS11_Angle8Bit();
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);

				}
//				TRESH_FLAG=TRESH_UPPER;
			}
//			else if(CMPS11_Angle<NORTH_THRESHOLD_UPPER)
			else if((CMPS11_Angle>(START_MIDDLE+10))&&(CMPS11_Angle<R4A_THRESHOLD_MIDDLE))
//			else if(CMPS11_Angle<SOUTH_THRESHOLD_UPPER)
//			else if(CMPS11_Angle<EAST_THRESHOLD_UPPER)

			{
				while((CMPS11_Angle>(START_MIDDLE+10))&&(CMPS11_Angle<R4A_THRESHOLD_MIDDLE))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					GetCMPS11_Angle8Bit();
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
				}
//				TRESH_FLAG=TRESH_LOWER;
			}
//			else break;
//		}

//		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle<START_MIDDLE)||(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION RIGHT");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
//			delay_ms(20);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle<START_MIDDLE)||(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				GetCMPS11_Angle8Bit();
				if((CMPS11_Angle<START_MIDDLE)||(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}

			}
		}
		else if((CMPS11_Angle>START_MIDDLE)&&(CMPS11_Angle<R4A_THRESHOLD_MIDDLE))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION LEFT");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
//			delay_ms(20);

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle>START_MIDDLE)&&(CMPS11_Angle<R4A_THRESHOLD_MIDDLE))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				GetCMPS11_Angle8Bit();
				if((CMPS11_Angle>START_MIDDLE)&&(CMPS11_Angle<R4A_THRESHOLD_MIDDLE))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}

			}
		}
		if(ROOM_TYPE == GRAY_ROOM)
		{
			int geser=0;
//			while(Ping[PING_RIGHT]>=12 && geser<5) //REGIONAL SPEED ULTRAFAST
			while(Ping[PING_RIGHT]>=12 && geser<7)
			{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				geser++;
			}
			FOLLOW_FLAG=KANAN;
			ROOM1A_SP_EXIT_FLAG=FLAG_INACTIVE;

		}
		else if(Ping[PING_RIGHT]>40)
		{
			while(Ping[PING_FRONT]>=12)
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			FOLLOW_FLAG=KIRI;
			ROOM1A_SP_EXIT_FLAG=FLAG_INACTIVE;
		}
		else if(Ping[PING_RIGHT]>=12)
		{
			int geser=0;
//			while(Ping[PING_RIGHT]>=12 && geser<5) //REGIONAL SPEED ULTRAFAST
			while(Ping[PING_RIGHT]>=10 && geser<7)
			{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				geser++;
			}
			if(Ping[PING_ASKEW_RIGHT]>35 || Ping[PING_REAR_RIGHT]>35)
			{
				while(Ping[PING_FRONT]>=12)
				{
					TRACER_STAT= TRACER_BLACK;
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					TCSlave_Check();
					if(TRACER_STAT==TRACER_WHITE)break;
				}
				FOLLOW_FLAG=KIRI;
				ROOM1A_SP_EXIT_FLAG=FLAG_ACTIVE;
			}
			else
			{
				FOLLOW_FLAG=KANAN;
				ROOM1A_SP_EXIT_FLAG=FLAG_INACTIVE;
			}
		}

/*
		//============================= CARA LAMA ==============================//
		ARENA_FLAG=CMPS_INACTIVE;
		Get_East_Status();

		while(ARENA_FLAG==CMPS_INACTIVE)
		{
			Get_East_Status();

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
			delay_ms(20);

			if(ARENA_FLAG==CMPS_ACTIVE)
			{
				lcd_gotoxy(0,2);sprintf(lcd,"CMPSFLG ACTIVE");lcd_putstr(lcd);
			}
			else
			{
				lcd_gotoxy(0,2);sprintf(lcd,"CMPSFLG INACTIVE");lcd_putstr(lcd);
			}

//			if(CMPS11_Angle>NORTH_THRESHOLD_UPPER)
			if((CMPS11_Angle>WEST_THRESHOLD_UPPER)||(CMPS11_Angle<EAST_THRESHOLD_MIDDLE))
//			if(CMPS11_Angle>SOUTH_THRESHOLD_UPPER)
//			if(CMPS11_Angle>EAST_THRESHOLD_UPPER)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				TRESH_FLAG=TRESH_UPPER;
			}
//			else if(CMPS11_Angle<NORTH_THRESHOLD_UPPER)
			else if((CMPS11_Angle<WEST_THRESHOLD_UPPER)&&(CMPS11_Angle>EAST_THRESHOLD_MIDDLE))
//			else if(CMPS11_Angle<SOUTH_THRESHOLD_UPPER)
//			else if(CMPS11_Angle<EAST_THRESHOLD_UPPER)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				TRESH_FLAG=TRESH_LOWER;
			}
			else break;
		}
		while(Ping[PING_FRONT]>=15)
		{
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}

		FOLLOW_FLAG=KANAN;
*/



//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

//		THIS SECTIONS OMITTED DUE TO ORIENTATION FLAG CHANGES

//		if(Ping[PING_FRONT]>34)		//khusus ruang 1
//		{
////			while((a<330) || (a>30))
////			{
////				GetCMPS11_Angle8Bit();
////				a=BW_CMPS11.Compass8Bit;
////
////				lcd_display_clear();
////				lcd_gotoxy(0,0);sprintf(lcd,"ANGLE: %d",a);lcd_putstr(lcd);
////				delay_ms(20);
////
////				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
////			}
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//		}

	}

}

/* func      : void BW_Home_Detection_2017(void)
 * brief     : Detecting Home and Positioning
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Toni(Tuesday, December 12th
 * Revised BY:
 * programmer's Note:
 */
void BW_Home_Detection_check(void)
{
	if  (
			( (Ping[PING_LEFT]<=20) && ((Ping[PING_ASKEW_LEFT]<=25)&&(Ping[PING_REAR_LEFT]<=25)))
			||
			( (Ping[PING_RIGHT]<=20) && ((Ping[PING_ASKEW_RIGHT]<=25)&&(Ping[PING_REAR_RIGHT]<=25)))
			||
				//KONDISI ROBOT DI POJOK RUANG MENGHADAP KE TENGAH RUANGAN
			(
					((Ping[PING_REAR_LEFT]<=25)||(Ping[PING_LEFT]<=20))
					&&
					((Ping[PING_REAR_RIGHT]<=25)||(Ping[PING_RIGHT]<=20))
					&&
					(Ping[PING_REAR]<=25)
			)

			||

			((Ping[PING_ASKEW_RIGHT]<=25) && (Ping[PING_ASKEW_LEFT]<=25))
		)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW KIRI");lcd_putstr(lcd);
		delay_ms(50);

		HOME_POS=POJOK;

		if(Ping[PING_RIGHT]>20)
		{
			//Get_IR();
			if((Ping[PING_REAR]<=20) && (Ping[PING_LEFT]<20) && (Ping[PING_FRONT]<20))
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW KIRI");lcd_putstr(lcd);
				delay_ms(50);
				FOLLOW_FLAG=KIRI;
			}
			else if(Ping[PING_FRONT]<20)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW KANAN");lcd_putstr(lcd);
				delay_ms(50);
				FOLLOW_FLAG=KANAN;
			}
			else
			{
				if (Ping[PING_LEFT]<20)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW KIRI");lcd_putstr(lcd);
					delay_ms(50);
				}
				else
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW KANAN");lcd_putstr(lcd);
					delay_ms(50);
					FOLLOW_FLAG=KANAN;
				}
			}
		}
		else
		{
			//Get_IR();
			if((((Ping[PING_ASKEW_RIGHT]<9) && (Ping[PING_RIGHT]<9) && (Ping[PING_REAR_RIGHT]<9)) && (Ping[PING_FRONT]<10) && ((Ping[PING_LEFT]<30) || (Ping[PING_ASKEW_LEFT]<30))) && (Ping[PING_REAR]>50))//(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED))
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW KIRI");lcd_putstr(lcd);
				delay_ms(50);
				FOLLOW_FLAG=KIRI;
			}
			else if((Ping[PING_RIGHT]<10) && (Ping[PING_LEFT]<10))
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW KANAN");lcd_putstr(lcd);
				delay_ms(50);
				FOLLOW_FLAG=KANAN;
			}
			else
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW KANAN");lcd_putstr(lcd);
				delay_ms(50);
				FOLLOW_FLAG=KANAN;
			}
		}
	}
	else
	{
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
//		delay_ms(50);

		HOME_POS=TENGAH;

		ARENA_FLAG=CMPS_INACTIVE;
		Get_North_Status();

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(20);
	}
}

void Home_HallwaySC_Detector(void)
{
//	RoomTypeDetector();
//	mov_static();
//	delay_ms(100);

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	delay_ms(100);

	if	(
			(TCS3200_SLV_DATA[0]==COLOUR_GRAY)
		)

	{
//		BW_Buzz(1);
//		BW_PID_Init();
//		follow_right_counter(4);

		if ( (Ping[PING_FRONT]>=85) && (Ping[PING_LEFT]<=30) && (Ping[PING_RIGHT]<=30) )
		{
			ROOM[1]= HALLWAY_SC;
			ROOM_COUNTER++;

			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"HALLWAY SC");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
			delay_ms(100);

		}

	}


}



/* func      : void Escape_Home(void)
 * brief     : BW Escape from Home sequences
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Ryan (*MISSING NOTES*)
 * Revised BY: Ver.3 -> Ryan (Monday, March 15 2016)
 * 						Configured for the 2016 Rule (Simplified version from before)
 * 						Ryan (Friday, April 1st 2016)
 * 						Configured for the new TCS3200 Processor interfacing
 * 			   Ver.4 -> Hafidin (Monday, March 6 2017)
 * programmer's Note:
 *
 */
void Escape_Home(void)
{
	int h=0;
	int tanda=0;
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"ESCAPE HOME");lcd_putstr(lcd);
	delay_ms(100);

	BW_PID_Init();

	if(Ping[PING_FRONT]<25)
	{
		tanda=1;
		while(Ping[PING_LEFT]<25)
		{
			Dynamx_Rot_Left(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);
			Dynamx_Rot_Left(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);
//			BW_FollowCounter_Right(1);
		}
		Dynamx_Rot_Left(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);

		if(Ping[PING_FRONT]<18)
		{
			Dynamx_Rot_Left(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);
			Dynamx_Rot_Left(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);
		}
		Dynamx_Rot_Left(HEXSPD_SLOW,HEXSTEP_FAR,IKCALC_ENABLE);
	}
	else
	{
		if((Ping[PING_ASKEW_LEFT]<18) && (Ping[PING_REAR_LEFT]<18))
		{
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			BW_FollowCounter_Left(1);
		}
		else if ((Ping[PING_ASKEW_RIGHT]<18) && (Ping[PING_REAR_RIGHT]<18))
		{
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			BW_FollowCounter_Right(1);
		}
		else
		{
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			BW_FollowCounter_Left(1);
		}
	}

	TCSlave_Check();
	BW_PID_Init();

	while(( (TCS3200_SLV_DATA[0]==COLOUR_WHITE) || (TCS3200_SLV_DATA[1]==TRACER_WHITE) ) && (h>=6))
	{
		TCSlave_Check();
		h++;
		if(tanda==1)
		{
			BW_FollowCounter_Right(1);
		}
		else
		{
			if((Ping[PING_ASKEW_LEFT]<18) && (Ping[PING_REAR_LEFT]<18))
			{
				BW_FollowCounter_Left(1);
//				FOLLOW_FLAG=KIRI;
			}
			else if ((Ping[PING_ASKEW_RIGHT]<18) && (Ping[PING_REAR_RIGHT]<18))
			{
				BW_FollowCounter_Right(1);
//				FOLLOW_FLAG=KANAN;
			}
			else
			{
				BW_FollowCounter_Left(1);
//				FOLLOW_FLAG=KIRI;
			}
		}
	}

//	BW_PID_Init();
//	BW_FollowCounter_Left(1);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"EXIT ROOM");lcd_putstr(lcd);
	delay_ms(100);
}

/* func      : void Escape_Home(void)
 * brief     : BW Escape from Home sequences
 * param     : N/A
 * retval    : N/A
 * Ver       : 5
 * written By: Hafidin (*MISSING NOTES*)
 * Revised BY:	Ver. 2: Ryan (Saturday, April 22nd, 2017)
 * 				Ver. 3: Ryan (Sunday, April 23rd, 2017)
 * 				Ver. 4: Ryan (Sunday, April 23rd, 2017)
 * 						Added wall following direction option when escape home corner
 * 				Ver. 5: Hafidin (Tue, May 2nd 2017)
 * programmer's Note:
 *
 */
void Escape_Home_2017(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"ESCAPE HOME");lcd_putstr(lcd);
	delay_ms(100);

	if(HOME_POS==POJOK)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"ESCAPE HOME");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"CORNER");lcd_putstr(lcd);
		delay_ms(100);

		TCSlave_Check();
		BW_PID_Init_Room();

		if(FOLLOW_FLAG==KIRI)
		{
			while( (TCS3200_SLV_DATA[0]==COLOUR_WHITE) || (TCS3200_SLV_DATA[1]==TRACER_WHITE) )
			{
				TCSlave_Check();
				BW_FollowCounter_Left(1);
			}
		}
		else
		{
			while( (TCS3200_SLV_DATA[0]==COLOUR_WHITE) || (TCS3200_SLV_DATA[1]==TRACER_WHITE) )
			{
				TCSlave_Check();
				BW_FollowCounter_Right(1);
			}
		}

	}
	else if(HOME_POS==TENGAH)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"ESCAPE HOME");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"MIDDLE");lcd_putstr(lcd);
		delay_ms(100);

		if(TRESH_FLAG==TRESH_UPPER)
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		}
		else
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		}

		if(Ping[PING_FRONT]>16)
		{
			Bumper_Action();
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			if(Ping[PING_FRONT]>16)
			{
				Bumper_Action();
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			if(Ping[PING_FRONT]>16)
			{
				Bumper_Action();
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			if(Ping[PING_FRONT]>16)
			{
				Bumper_Action();
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			if(Ping[PING_FRONT]>16)
			{
				Bumper_Action();
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			if(Ping[PING_FRONT]>16)
			{
				Bumper_Action();
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			Bumper_Action();
		}

		if(Ping[PING_FRONT]<=28)
		{
			Get_IR();
			if(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

				while(Ping[PING_RIGHT]>20)
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				}
			}
			else
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

				while(Ping[PING_LEFT]>20)
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				}
			}
		}

//		if(Ping[PING_FRONT]<20)
//		{
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//
//			if(Ping[PING_FRONT]<20)
//			{
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			}
//			if(Ping[PING_FRONT]<20)
//			{
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			}
//		}


		TCSlave_Check();
		BW_PID_Init_Room();

//		if ((Ping[PING_LEFT]<Ping[PING_RIGHT]) || (Ping[PING_ASKEW_LEFT]<Ping[PING_ASKEW_RIGHT]))
		if ( (Ping[PING_LEFT]<35) && ((Ping[PING_ASKEW_LEFT]<40)||(Ping[PING_REAR_LEFT]<40))  )
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ESCAPE :");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"LEFT RULE");lcd_putstr(lcd);
			delay_ms(50);

//			BW_PID_Init_Room();
//			BW_FollowTracer_Left();
			FOLLOW_FLAG=KIRI;
		}
		else
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ESCAPE :");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"RIGHT RULE");lcd_putstr(lcd);
			delay_ms(50);

//			BW_PID_Init_Room();
//			BW_FollowTracer_Right();
			FOLLOW_FLAG=KANAN;
		}

		BW_PID_Init_Room();

		while( (TCS3200_SLV_DATA[0]==COLOUR_WHITE) || (TCS3200_SLV_DATA[1]==TRACER_WHITE) )
		{
			TCSlave_Check();
//			BW_FollowCounter_Right(3);
			if(FOLLOW_FLAG==KIRI)
			{
				BW_FollowCounter_Left(3);
			}
			else
			{

				BW_FollowCounter_Right(3);
			}
		}
	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"EXIT ROOM");lcd_putstr(lcd);
	delay_ms(100);
}


void BW_FireFighter(void)
{
//====================================BW DEFAULT ROUTINES=====================================//
	//PING_FRONT FAILCHECK
	while(Ping[PING_FRONT]==0)
	{
		BW_Buzz(1);
		delay_ms(100);
	}

	Sendto_PC(USART1,"\r BW BLUE FIGHTER WHILE INFINITE LOOP \r");

	BW_Home_Detection();

	BW_Buzz(4);
	Escape_Home();
	Evade_Wall();
//==============================================================================================//

}

void BW_Arbitrary_Start(void)
{
	BW_LOCATION[PRESENT_LOC]=LOCATION_ROOM;
	BW_Buzz(2);
}

void BW_Non_Arbitrary_Start(void)
{
	BW_LOCATION[PRESENT_LOC]=LOCATION_CORRIDOR;
	BW_Buzz(2);
}


void Evade_Wall(void)
{

//	Get_IR();
//	GetBumper();
//	GetFlame();
//
////	if(BW_LOCATION[0]==LOCATION_ROOM)
////	{
////		if(SHARP[SHARP_LEFT]<7)
////		{
////			while(SHARP[SHARP_LEFT]<6)
////			{
////				mov_deflect_right(FAST,CLOSE);
////			}
////		}
////
////		else if (SHARP[SHARP_RIGHT]<9)
////		{
////			while(SHARP[SHARP_RIGHT]<7)
////			{
////				mov_deflect_left(FAST,CLOSE);
////			}
////		}
////	}
////
////	else if(BW_LOCATION[0]==LOCATION_CORRIDOR)
////	{
////		if(SHARP[SHARP_LEFT]<6)
////		{
////			while(SHARP[SHARP_LEFT]<5)
////			{
////				mov_deflect_right(FAST,CLOSE);
////			}
////		}
////
////		else if (SHARP[SHARP_RIGHT]<6)
////		{
////			while(SHARP[SHARP_RIGHT]<5)
////			{
////				mov_deflect_left(FAST,CLOSE);
////			}
////		}
////	}
//
//	if(BW_LOCATION[0]==LOCATION_ROOM)
//	{
//		if(Ping[PING_LEFT]<10)
//		{
//			while(Ping[PING_LEFT]<10)
//			{
////				mov_deflect_right(FAST,CLOSE);
//				mov_deflect_right(FAST,CLOSE);
//			}
//		}
//
//		else if (Ping[PING_RIGHT]<10)
//		{
//			while(Ping[PING_RIGHT]<10)
//			{
////				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//			}
//		}
//	}
//
//	else if(BW_LOCATION[0]==LOCATION_CORRIDOR)
//	{
//		if(Ping[PING_LEFT]<10)
//		{
//			while(Ping[PING_LEFT]<10)
//			{
////				mov_deflect_right(FAST,CLOSE);
//				mov_deflect_right(FAST,CLOSE);
//			}
//		}
//
//		else if (Ping[PING_RIGHT]<10)
//		{
//			while(Ping[PING_RIGHT]<10)
//			{
////				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//			}
//		}
//	}
//
////	if(Ping[PING_LEFT]<6)
////	{
////		while(Ping[PING_LEFT]<5)
////		{
////			mov_deflect_right(FAST,CLOSE);
////		}
////	}
////
////	else if (Ping[PING_RIGHT]<6)
////	{
////		while(Ping[PING_RIGHT]<5)
////		{
////			mov_deflect_left(FAST,CLOSE);
////		}
////	}
//
////	if	(
////			((INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) || (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED))
////
////	 	 )
////	{
////		while( (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) )
////		{
////			//RIGHT OVERFLOW RESET
////			RIGHT_OVERFLOW_COUNTER=0;
////
////			//COUNTING LEFT OVERFLOW
////			LEFT_OVERFLOW_COUNTER++;
////
////			Get_IR();
////			mov_deflect_left(FAST,CLOSE);
////
////			if(LEFT_OVERFLOW_COUNTER>=13)
////			{-
////				LEFT_OVERFLOW_COUNTER=0;
////				lcd_display_clear();
////				lcd_gotoxy(0,0);sprintf(lcd,"DEFLECT LEFT");lcd_putstr(lcd);
////				lcd_gotoxy(0,1);sprintf(lcd,"OVERFLOW");lcd_putstr(lcd);
////				delay_ms(100);
////
////				mov_fwd_5cm(15,FAST_LEVEL_3);
////			}
////		}
////
////		while( (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED) )
////		{
////			//LEFT OVERFLOW RESET
////			LEFT_OVERFLOW_COUNTER=0;
////
////			//COUNTING LEFT OVERFLOW
////			RIGHT_OVERFLOW_COUNTER++;
////
////			Get_IR();
////			mov_deflect_right(FAST,CLOSE);
////
////			if(RIGHT_OVERFLOW_COUNTER>=13)
////			{
////				RIGHT_OVERFLOW_COUNTER=0;
////				lcd_display_clear();
////				lcd_gotoxy(0,0);sprintf(lcd,"DEFLECT RIGHT");lcd_putstr(lcd);
////				lcd_gotoxy(0,1);sprintf(lcd,"OVERFLOW");lcd_putstr(lcd);
////				delay_ms(100);
////
////				mov_fwd_5cm(15,FAST_LEVEL_3);
////			}
////
////		}
////	}
//
//
//
//
//	if	(
//			 	 ((BUMPER[LEFT]==ACTIVE) && (BUMPER[RIGHT]==INACTIVE))
//			)
//	{
//		BW_Buzz(1);
//		Sendto_PC(USART1,"BW ROT RIGHT in Evade Wall: IR_FRONT_RIGHT DETECTS OBSTACLE \r");
//		//mov_bwd(5,FAST_LEVEL_3);
//		if(TCS3200_SLV_DATA[1]==1)
//		{
//			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//		}
////		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//		if(TCS3200_SLV_DATA[1]==1)
//		{
//			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//		}
////		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//
////		Get_IR();
////		while( INFRARED[IR_FRONT_LEFT]==IR_DETECTED )
////		{
////			if(TCS3200_SLV_DATA[1]==1)
////			{
////				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
////			}
////			mov_rot_right(FAST_LEVEL_3,CLOSE);
////
////			Get_IR();
////		}
//	}
//	else if	(
//				((BUMPER[RIGHT]==ACTIVE) && (BUMPER[LEFT]==INACTIVE))
//			)
//	{
//		BW_Buzz(1);
//
//		Sendto_PC(USART1,"BW ROT LEFT in Evade Wall: IR_FRONT_LEFT DETECTS OBSTACLE \r");
//		//mov_bwd(5,FAST_LEVEL_3);
//
//		if(TCS3200_SLV_DATA[1]==1)
//		{
//			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//		}
////		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//		if(TCS3200_SLV_DATA[1]==1)
//		{
//			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//		}
////		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//
////		Get_IR();
////		while( INFRARED[IR_FRONT_RIGHT]==IR_DETECTED )
////		{
////			if(TCS3200_SLV_DATA[1]==1)
////			{
////				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
////			}
////			mov_rot_left(FAST_LEVEL_3,CLOSE);
////			Get_IR();
////		}
//	}
}

void Evade_Wall_Room(void)
{
	Get_IR();
	GetBumper();
//	GetFlame();

//	if	(
//			((INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) || (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED)) &&
//			(( FLAME_SENSOR[FLM_RIGHT]==FLAME_NOT_DETECTED) || ( FLAME_SENSOR[FLM_LEFT]==FLAME_NOT_DETECTED))
//	 	 )
//	{
//		while( (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) && ( FLAME_SENSOR[FLM_RIGHT]==FLAME_NOT_DETECTED) )
//		{
//			Get_IR();
//			mov_deflect_left(FAST,CLOSE);
//		}
//
//		while( (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED) && ( FLAME_SENSOR[FLM_LEFT]==FLAME_NOT_DETECTED) )
//		{
//			Get_IR();
//			mov_deflect_right(FAST,CLOSE);
//		}
//	}

//	if(SHARP[SHARP_LEFT]<7)
//	{
//		while(SHARP[SHARP_LEFT]<6)
//		{
//			mov_deflect_right(FAST,CLOSE);
//		}
//	}
//
//	else if (SHARP[SHARP_RIGHT]<7)
//	{
//		while(SHARP[SHARP_RIGHT]<6)
//		{
//			mov_deflect_left(FAST,CLOSE);
//		}
//	}

	if(Ping[PING_LEFT]<7)
	{
		while(Ping[PING_LEFT]<6)
		{
//			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);
		}
	}

	else if (Ping[PING_RIGHT]<7)
	{
		while(Ping[PING_RIGHT]<6)
		{
//			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
		}
	}

	if	(
			(Ping[PING_LEFT]<=5) || (Ping[PING_RIGHT]<=5)
	 	 )
	{
		while( (Ping[PING_LEFT]<=5) && (Ping[PING_RIGHT]>5) )
		{
			Get_IR();
//			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);
		}

		while( (Ping[PING_RIGHT]<=5) && (Ping[PING_LEFT]>5) )
		{
			Get_IR();
//			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
		}
	}

	else if	(
			 	 ((BUMPER[LEFT]==ACTIVE) && (BUMPER[RIGHT]==INACTIVE))
			)
	{
		BW_Buzz(1);
		Sendto_PC(USART1,"BW ROT RIGHT in Evade Wall: IR_FRONT_RIGHT DETECTS OBSTACLE \r");
		//mov_bwd(5,FAST_LEVEL_3);
		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);

		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);


//		Get_IR();
//		while( INFRARED[IR_FRONT_LEFT]==IR_DETECTED )
//		{
//			if(TCS3200_SLV_DATA[1]==1)
//			{
//				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//			}
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//			Get_IR();
//		}
//		mov_fwd_5cm(10,FAST_LEVEL_3);
	}
	else if	(
				((BUMPER[RIGHT]==ACTIVE) && (BUMPER[LEFT]==INACTIVE))
			)
	{

		BW_Buzz(1);
		Sendto_PC(USART1,"BW ROT LEFT in Evade Wall: IR_FRONT_LEFT DETECTS OBSTACLE \r");
		//mov_bwd(5,FAST_LEVEL_3);

		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);

		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);

//		Get_IR();
//		while( INFRARED[IR_FRONT_RIGHT]==IR_DETECTED )
//		{
//			if(TCS3200_SLV_DATA[1]==1)
//			{
//				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//			}
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			Get_IR();
//		}
//		mov_fwd_5cm(10,FAST_LEVEL_3);
	}
}


void Bump_Avoider(void)
{

		GetBumper();

		if	(
				 	 ((BUMPER[LEFT]==ACTIVE) && (BUMPER[RIGHT]==INACTIVE))
				)
		{
			Sendto_PC(USART1,"BW ROT RIGHT in Evade Wall: IR_FRONT_RIGHT DETECTS OBSTACLE \r");
			if(TCS3200_SLV_DATA[1]==1)
			{
				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
			}
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}
		else if	(
					((BUMPER[RIGHT]==ACTIVE) && (BUMPER[LEFT]==INACTIVE))
				)
		{

			Sendto_PC(USART1,"BW ROT LEFT in Evade Wall: IR_FRONT_LEFT DETECTS OBSTACLE \r");

			if(TCS3200_SLV_DATA[1]==1)
			{
				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
			}
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
		}

}
void ReturnTo_Room(void)
{
	Get_IR();
	while ( (Ping[PING_FRONT]>=25) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		Get_IR();
	}

	Get_IR();
	while ( Ping[PING_FRONT]<=25 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		Get_IR();
	}
//	mov_fwd_5cm(10,FAST_LEVEL_3);
	mov_fwd_5cm(10,FAST_LEVEL_3);


	RETURN_COUNTER++;

	if(RETURN_COUNTER>=2)
	{
		BW_Buzz(4);

		if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
		{
//			followfire_left_new();
		}
		else
		{
//			followfire_right_new();

		}

	}

}


/* 	  CAT POSSIBLE LOCATION
 * ___________________________
 *  |                         |
 *  |	  xxx				  |
 * 	|    _____                |
 * 	|    |              |     |
 * 	|    |              | xxx |
 * 	|    |              |     |
 * 	|    |              |     |
 *__| 	 |______________|     |
 * 	                          |
 *			xxx               |
 *____________________________|
 *
 *
 *		Ver.3: Ryan (Sunday, April 23rd, 2017)
 *				Added parameter and simplifying the nested if-else
 */

void Cat_Avoider(void)
{

	if(BW_LOCATION[0]==LOCATION_CORRIDOR) //Cat Avoider Routines only active inside room
	{
		Get_IR();
		if(Ping[PING_ASKEW_RIGHT]<20)
		{
			if	 (
						((SHARP[SHARP_FRONT_R]<12) && (SHARP[SHARP_FRONT_L]<12))
						&&
						(Ping[PING_ASKEW_RIGHT]>9)
//						&&
//						(Ping[PING_LEFT]<=21)
//						&&
//						(Ping[PING_RIGHT]<=30) //Tidak mungkin kucing terdeteksi kalau robot terlalu miring
						&&
						((Ping[PING_FRONT]>(SHARP[SHARP_FRONT_R]+25)) && (Ping[PING_FRONT]>40))
			  	 )
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTOR");lcd_putstr(lcd);
				lcd_gotoxy(3,1);sprintf(lcd,"ACTIVATED");lcd_putstr(lcd);
//				delay_ms(100);

				if(SHIFT_ALGORITHM_FLAG==SHIFT_ALGORITHM_ACTIVE)
				{
					CAT_FLAG = CAT_DETECTED;
				}

				BW_Buzz(1);
				if(ROOM4A_CAT_AVOIDER==ROOM4A_CAT_AVOIDER_ACTIVE)
				{
					Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);
					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
				}
			}
		}
		else
		{
			if	 (
					((SHARP[SHARP_FRONT_R]<12) && (SHARP[SHARP_FRONT_L]<12))
					&&
					(Ping[PING_ASKEW_LEFT]>9)
//					&&
//					(Ping[PING_RIGHT]<=21)
//					&&
//					(Ping[PING_LEFT]<=30) //Tidak mungkin kucing terdeteksi kalau robot terlalu miring
					&&
					((Ping[PING_FRONT]>(SHARP[SHARP_FRONT_R]+25)) && (Ping[PING_FRONT]>40))
				 )
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTOR");lcd_putstr(lcd);
				lcd_gotoxy(3,1);sprintf(lcd,"ACTIVATED");lcd_putstr(lcd);
//				delay_ms(100);

				if(SHIFT_ALGORITHM_FLAG==SHIFT_ALGORITHM_ACTIVE)
				{
					CAT_FLAG = CAT_DETECTED;
				}

				BW_Buzz(1);
				if(ROOM4A_CAT_AVOIDER==ROOM4A_CAT_AVOIDER_ACTIVE)
				{
					Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);
					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
				}
			}
		}
	}

}
/*
void Cat_Avoider(void)
{
	if(BW_LOCATION[0]==LOCATION_CORRIDOR) //Cat Avoider Routines only active inside room
	{
		if(Ping[PING_ASKEW_RIGHT]<15)
		{
			if	 (
						((SHARP[SHARP_FRONT_R]>(Ping[PING_FRONT]+15))) //&& (SHARP[SHARP_FRONT_L]>(Ping[PING_FRONT]+15)))
						&&
						((SHARP[SHARP_FRONT_R]>40))// && (SHARP[SHARP_FRONT_L]>40))
						&&
						(Ping[PING_ASKEW_RIGHT]>9)
//						&&
//						(Ping[PING_LEFT]<=21)
//						&&
//						(Ping[PING_RIGHT]<=30) //Tidak mungkin kucing terdeteksi kalau robot terlalu miring
						&&
						(Ping[PING_FRONT]<20)// && (Ping[PING_FRONT]>40))
			  	 )
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTED");lcd_putstr(lcd);
				lcd_gotoxy(3,1);sprintf(lcd,"ACTIVATED");lcd_putstr(lcd);
				delay_ms(100);

				if(SHIFT_ALGORITHM_FLAG==SHIFT_ALGORITHM_ACTIVE)
				{
					CAT_FLAG = CAT_DETECTED;
				}

				BW_Buzz(1);
				if(ROOM4A_CAT_AVOIDER==ROOM4A_CAT_AVOIDER_ACTIVE)
				{
					Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
				}
			}
		}
		else
		{
			if	 (
					((SHARP[SHARP_FRONT_R]>(Ping[PING_FRONT]+15)))// && (SHARP[SHARP_FRONT_L]>(Ping[PING_FRONT]+15)))
					&&
					((SHARP[SHARP_FRONT_R]>40))// && (SHARP[SHARP_FRONT_L]>40))
					&&
					(Ping[PING_ASKEW_LEFT]>9)
//					&&
//					(Ping[PING_RIGHT]<=21)
//					&&
//					(Ping[PING_LEFT]<=30) //Tidak mungkin kucing terdeteksi kalau robot terlalu miring
					&&
					(Ping[PING_FRONT]<20)// && (Ping[PING_FRONT]>40))
				 )
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTED");lcd_putstr(lcd);
				lcd_gotoxy(3,1);sprintf(lcd,"ACTIVATED");lcd_putstr(lcd);
				delay_ms(100);

				if(SHIFT_ALGORITHM_FLAG==SHIFT_ALGORITHM_ACTIVE)
				{
					CAT_FLAG = CAT_DETECTED;
				}

				BW_Buzz(1);
				if(ROOM4A_CAT_AVOIDER==ROOM4A_CAT_AVOIDER_ACTIVE)
				{
					Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
				}
			}
		}
	}

}
*/
/* func      : void PID_Calculate_LeftRule_Interrupt_Init(void)
 * brief     : PID Calculate LeftRule Timer Interrupt Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Toni(Monday, November 13th, 2017)
 * Programmer's Note:
 */
void Cat_Avoider_Interrupt_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 839; //f per count= 84.000.000/(839+1)=100000Hz = 10us (0,00001 s)
	//335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 50;// 0,000001 s x 5000 = 0.05s -> 1 s -> 1 Hz
//	TIM_TimeBaseStructure.TIM_Period = 500;// 0,1 ms x 500 = 50 ms -> 0,5 s -> 2 Hz
			//200; //0,1 X 200 = 20 ms -> 0,2 s -> 5 Hz
	//10000; //0,1ms x 10000 = 1 s
	//0.004*125000=500ms jadi sampling adc setiap 500ms //MAX 65535
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM2, ENABLE); //default di off dulu
//	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/* func      : void TIM2_IRQHandler(void)
 * brief     : Cat_Avoider Timer Handler
 * retval    : N/A
 * Ver       : 1
 * written By: Toni(Monday, November 13th, 2017)
 * Programmer's Note:
 */
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
    	Cat_Avoider();
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}

void Check_Cat_Avoider(void)
{
	CAT_FLAG=CAT_NOT_DETECTED;
	while(CAT_FLAG==CAT_NOT_DETECTED)
	{
		follow_right_counter(1);
	}

	while(1)
	{
		mov_static();
		BW_Buzz(2);
	}
}



/*
 *  FOLLOW RIGHT COUNTER
 *
 */
void follow_right_counter(int limit)
{
	int counter;
//	CAT_FLAG = CAT_NOT_DETECTED;
	//int limit=15;
	for(counter=1;counter<=limit;counter++)
	{
		Cat_Avoider();
		Evade_Wall();

		if (Ping[PING_FRONT]<=15)
//		if (Ping[PING_FRONT]<=20)
		{

//			mov_rot_left(FAST_LEVEL_3, CLOSE);
//			mov_rot_left(FAST_LEVEL_3, CLOSE);
			mov_rot_left(FAST_LEVEL_2,FAR);
			mov_rot_left(FAST_LEVEL_2,FAR);
//			if (Ping[PING_RIGHT]<=20)
//			{
//				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
//			}
//
//			if (Ping[PING_RIGHT]>20)
//			{
//				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
//			}
		}
		else
		{
			PID_follow_right_counter();
		}
	}



}

/* func      : void PID_follow_tracer_right(void)
 * brief     : Wall following using PID controller right rule
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Monday, October 19th 2015)
 * Revised BY: Ver.2 Ryan (Friday, April 16th 2016)
 * 					* Added Follow overflow limit
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_follow_right_counter(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
//	Sendto_PC(USART1,"SHARP ASKEW RIGHT: %d \t",(int)SHARP[SHARP_RIGHT]);
	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_RIGHT]);
	PID_Calc_RightRule();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);

//	BW_Buzz(3);
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"pid_value: %d \r",(int)PID_F_R.pid_value[0]);lcd_putstr(lcd);
//	delay_ms(100);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//			if ( (SHARP[SHARP_RIGHT]<=PID_F_R.set_point_upper) && (SHARP[SHARP_RIGHT]>=PID_F_R.set_point_lower)) //&& ((Ping[PING_RIGHT]<=12) && (Ping[PING_RIGHT]>=16)) )
//			if ( (Ping[PING_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=15)
//					if (Ping[PING_FRONT]<=20)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_2,FAR);
						mov_rot_left(FAST_LEVEL_2,FAR);
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5,FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]>PID_F_R.set_point )
//			else if ( Ping[PING_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=15)
//					if (Ping[PING_FRONT]<=20)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_2,FAR);
						mov_rot_left(FAST_LEVEL_2,FAR);
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						if(WINDUP_RIGHT_COUNTER>=25)
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							GetBumper();
							while(Ping[PING_FRONT]>=15)
//							while(Ping[PING_FRONT]>=20)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
//								Get_IR();		//FUNGSI BARU!!!!!
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
//							while(Ping[PING_RIGHT]>=10)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_2,FAR);
								mov_rot_left(FAST_LEVEL_2,FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;
//							mov_fwd_5cm(12,FAST_LEVEL_3);break;
//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_2);
//							Get_IR();
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]<PID_F_R.set_point )
//			else if ( Ping[PING_RIGHT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP

					}

					if (Ping[PING_FRONT]<=15)
//					if (Ping[PING_FRONT]<=20)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_2,FAR);
						mov_rot_left(FAST_LEVEL_2,FAR);
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
//							while(Ping[PING_FRONT]>=20)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
//							while(Ping[PING_RIGHT]>=10)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_2,FAR);
								mov_rot_left(FAST_LEVEL_2,FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_2);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

void follow_right_counter_reverse(int limit)
{
	int counter;

	for(counter=1;counter<=limit;counter++)
	{
		Cat_Avoider();
		Evade_Wall();

		if (Ping[PING_REAR]<=16)
		{
			mov_rot_right_reverse(FAST_LEVEL_2,FAR);
			mov_rot_right_reverse(FAST_LEVEL_2,FAR);
		}
		else
		{
			PID_follow_right_counter_reverse();
		}
	}
}

void PID_follow_right_counter_reverse(void)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_RIGHT]);
	PID_Calc_RightRule_Reverse();
//	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			if ( (Ping[PING_REAR_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_REAR_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_REAR]<=16)
					{
						mov_rot_right_reverse(FAST_LEVEL_2,FAR);
						mov_rot_right_reverse(FAST_LEVEL_2,FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

//						Sendto_PC(USART1,"BW FORWARD \r");
						mov_bwd_5cm(5,FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_REAR_RIGHT]>PID_F_R.set_point )

			{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=16)
					{
						mov_rot_right_reverse(FAST_LEVEL_2,FAR);
						mov_rot_right_reverse(FAST_LEVEL_2,FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							curve_right_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
//							curve_right_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_REAR_RIGHT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=16)
					{
						mov_rot_right_reverse(FAST_LEVEL_2,FAR);
						mov_rot_right_reverse(FAST_LEVEL_2,FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=16)
							{
								mov_bwd_5cm(5,FAST_LEVEL_3);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
								mov_rot_right_reverse(FAST_LEVEL_2,FAR);
								mov_rot_right_reverse(FAST_LEVEL_2,FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							curve_left_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
//							curve_left_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

void follow_left_counter(int limit)
{
	int counter;
	//int limit=15;
	for(counter=1;counter<=limit;counter++)
	{
		Evade_Wall();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=14)
		{
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//			mov_rot_right(FAST_LEVEL_3, CLOSE);
//			mov_rot_right(FAST_LEVEL_3, CLOSE);
			mov_rot_right(FAST_LEVEL_3, FAR);
			mov_rot_right(FAST_LEVEL_3, FAR);

			GetBumper();
			while(BUMPER[RIGHT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_3);
				mov_rot_right(FAST, FAR);
				mov_rot_right(FAST, FAR);
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[RIGHT]==INACTIVE)break;
			}
			GetBumper();
			while(BUMPER[LEFT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_3);
				mov_rot_right(FAST, FAR);
				mov_rot_right(FAST, FAR);
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[LEFT]==INACTIVE)break;
			}
//			if (Ping[PING_LEFT]>=20)
//			{
//				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
//			}
//
//			if (Ping[PING_LEFT]<20)
//			{
//				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
//			}
		}
		else
		{
			PID_follow_left_counter();
		}
	}



}

/* func      : void PID_follow_left_counter(void)
 * brief     : Wall following using PID controller left rule
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Monday, October 19th 2015)
 * Revised BY: Ver.2 Ryan (Friday, April 16th 2016)
 * 					* Added Follow overflow limit
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_follow_left_counter(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;


	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3, FAR);
								mov_rot_right(FAST_LEVEL_3, FAR);

								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_3);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, FAR);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_3);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, FAR);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_3);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, FAR);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_3);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, FAR);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_2,FAR);
								mov_rot_right(FAST_LEVEL_2,FAR);

								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_3);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, FAR);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_3);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, FAR);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_3);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, FAR);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_3);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, FAR);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

void follow_left_counter_reverse(int limit)
{
	int counter;
	//int limit=15;
	for(counter=1;counter<=limit;counter++)
	{
		Evade_Wall();
		Cat_Avoider();

		if (Ping[PING_REAR]<=14)
		{
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");
			mov_rot_left_reverse(FAST_LEVEL_3, FAR);
			mov_rot_left_reverse(FAST_LEVEL_3, FAR);

		}
		else
		{
			PID_follow_left_counter_reverse();
		}
	}



}

/* func      : void PID_follow_left_counter(void)
 * brief     : Wall following using PID controller left rule
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Monday, October 19th 2015)
 * Revised BY: Ver.2 Ryan (Friday, April 16th 2016)
 * 					* Added Follow overflow limit
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_follow_left_counter_reverse(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;


	PID_Calc_LeftRule_Reverse();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_REAR_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_REAR]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);

					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_bwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_REAR_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);

					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_bwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{

								mov_rot_left_reverse(FAST_LEVEL_3, FAR);
								mov_rot_left_reverse(FAST_LEVEL_3, FAR);

							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);

						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_REAR_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_REAR]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");

						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);

					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_bwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
								mov_rot_left_reverse(FAST_LEVEL_2,FAR);
								mov_rot_left_reverse(FAST_LEVEL_2,FAR);

							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);

						}

						OVERRIDE=1;
					}

				}
		}
	}

}

void curve_right_counter(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right Counter \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3],10,leg-3);
	inv_kine(middle_left,90+beta[1],10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();


	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//5
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//6
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);
}

void curve_right_counter_reverse(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right Counter \r");
	generate_movement_data(0,-STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//1
	inv_kine(front_left,90+beta[5],10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[1],10,leg-3);
	inv_kine(rear_left,90+beta[3],10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();


	//2
	inv_kine(front_left,90-beta[5]+DELTA_RR,10,leg-3);
	inv_kine(front_right,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(middle_left,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(middle_right,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(rear_left,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(rear_right,90+beta[0]+DELTA_FL,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//3
	inv_kine(front_left,90-beta[5]+DELTA_RR,7,leg);
	inv_kine(front_right,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(middle_left,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(middle_right,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(rear_left,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(rear_right,90+beta[0]+DELTA_FL,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//4
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(middle_left,90+beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[0]+DELTA_FL,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//5
	inv_kine(front_left,90+beta[5]-DELTA_RR,7,leg);
	inv_kine(front_right,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(middle_left,90-beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(middle_right,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(rear_left,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(rear_right,90-beta[0]-DELTA_FL,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//6
	inv_kine(front_left,90+beta[5]-DELTA_RR,7,leg);
	inv_kine(front_right,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(middle_left,90-beta[4]+DELTA_MR,7,leg);
	inv_kine(middle_right,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(rear_left,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(rear_right,90-beta[0]-DELTA_FL,7,leg);
	delay_ms(SPEED);
}

void curve_left_counter(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left Counter \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//2
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//3
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//4
	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//5
	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//6
	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);
}

void curve_left_counter_reverse(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left Counter \r");
	generate_movement_data(0,-STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//1
	inv_kine(front_left,90+beta[5]+DELTA_RR,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(rear_left,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//2
	inv_kine(front_left,90-beta[5]-DELTA_RR,10,leg-3);
	inv_kine(front_right,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(middle_left,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(middle_right,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(rear_left,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(rear_right,90+beta[0]-DELTA_FL,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//3
	inv_kine(front_left,90-beta[5]-DELTA_RR,7,leg);
	inv_kine(front_right,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(middle_left,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(middle_right,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(rear_left,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(rear_right,90+beta[0]-DELTA_FL,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//4
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(middle_left,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[0]-DELTA_FL,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//5
	inv_kine(front_left,90+beta[5]+DELTA_RR,7,leg);
	inv_kine(front_right,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(middle_left,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(middle_right,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(rear_left,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(rear_right,90-beta[0]+DELTA_FL,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//6
	inv_kine(front_left,90+beta[5]+DELTA_RR,7,leg);
	inv_kine(front_right,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(middle_left,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(middle_right,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(rear_left,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(rear_right,90-beta[0]+DELTA_FL,7,leg);
	delay_ms(SPEED);
}

/*==============================================================================================
							NEW FEATURES FROM BW Ver.1.0
===============================================================================================*/

void FlameSense_PID_Init(void)
{
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_FLAME.P[0]=0;
	PID_FLAME.P[1]=0;
	PID_FLAME.P[2]=0;
	PID_FLAME.I[0]=0;
	PID_FLAME.I[1]=0;
	PID_FLAME.I[2]=0;
	PID_FLAME.D[0]=0;
	PID_FLAME.D[1]=0;
	PID_FLAME.D[2]=0;

	PID_FLAME.Kp=2;
	PID_FLAME.Ki=0;
	PID_FLAME.Kd=0;

	PID_FLAME.Ts=1;

//	PID_FLAME.set_point_upper=3;
//	PID_FLAME.set_point_lower=3;
	PID_FLAME.set_point=3;

	PID_FLAME.error[0]=0;
	PID_FLAME.error[1]=0;
	PID_FLAME.error[2]=0;
	PID_FLAME.pid_value[0]=0;
	PID_FLAME.pid_value[1]=0;
	PID_FLAME.pid_value[2]=0;
}

/*
 * func      : void PID_Calc(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void FlameSense_PID_Calc(void)
{

	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_FLAME.pid_value[2]=PID_FLAME.pid_value[1];
	PID_FLAME.pid_value[1]=PID_FLAME.pid_value[0];

	PID_FLAME.error[2]=PID_FLAME.error[1];
	PID_FLAME.error[1]=PID_FLAME.error[0];

	if (FlameSense[0]==PID_FLAME.set_point) {PID_FLAME.error[0]=0;}


	else if ( FlameSense[0] > PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = FlameSense[0] - PID_FLAME.set_point;
		}

	else if (FlameSense[0] < PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = PID_FLAME.set_point - FlameSense[0];
		}

	/*
	 * PID FORMULA
	 */
	PID_FLAME.P[2]= PID_FLAME.error[0]-PID_FLAME.error[2];
	PID_FLAME.P[1]= PID_FLAME.Kp;
	PID_FLAME.P[0]= PID_FLAME.P[1]*PID_FLAME.P[2]; //Proportional Controller

	PID_FLAME.I[2]= PID_FLAME.Ki*PID_FLAME.Ts/2;
	PID_FLAME.I[1]= PID_FLAME.error[0]+(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.I[0]= PID_FLAME.I[2]*PID_FLAME.I[1]; //Integral Controller


	PID_FLAME.D[2]= 2*PID_FLAME.Kd/PID_FLAME.Ts;
	PID_FLAME.D[1]= PID_FLAME.error[0]-(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.D[0]= PID_FLAME.D[2]*PID_FLAME.D[1]; //Derivative Controller

//	PID_FLAME.I= ( (PID_FLAME.Ki*PID_FLAME.Ts/2)*(PID_FLAME.error[0]+(2*PID_FLAME.error[1])+PID_FLAME.error[2]) );
//	PID_FLAME.D= ( (2*PID_FLAME.Kd/PID_FLAME.Ts)*(PID_FLAME.error[0]-(2*PID_FLAME.error[1])+PID_FLAME.error[2]));

	PID_FLAME.pid_value[0]= PID_FLAME.pid_value[2] + PID_FLAME.P[0] + PID_FLAME.I[0] + PID_FLAME.D[0];
}

void FlameTracking(void)
{

	Get_UV();
	UV_Lock=1;

	while(UV_Lock==1)
	{
//		FlameSense[1]=FlameSense[0];


		Send_FlameSense();

		PID_FlameTracking();
	}

}

/* func      : void PID_FlameTracking(void)
 * brief     : Wall following using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, October 19th 2015)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FlameTracking(void)
{
	float DUMMY_PIDVALUE=1;
	//int limit= *COMMAND_LOOP;
	//OVERCOMING BLIND SPOTS
	if(FlameSense[0]==0) FlameSense[0]=10;
	Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);

	FlameSense_PID_Calc();
	Sendto_PC(USART1,"PID Value : %d \r",(int)PID_FLAME.pid_value[0]);

	//KONDISI ROBOT SESUAI
	if ( FlameSense[0]==PID_FLAME.set_point)
	{
//		mov_static();
		BW_Buzz(3);
		while(Ping[PING_FRONT]>=20)
		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		BW_FlameScanning();


	}

	else if(FlameSense[0]==10)
	{

		if( (FlameSense[1]==1) )
		{
//			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSense[1]==5) )
		{
//			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSense[1] > PID_FLAME.set_point )
		{
//			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSense[1] < PID_FLAME.set_point )
		{
//			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}



	}
	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSense[0] > PID_FLAME.set_point )
	{
//		if (PID_FLAME.pid_value[0]>5) PID_FLAME.pid_value[0]=5; //WINDUP


//		Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSense[1]=5;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSense[0] < PID_FLAME.set_point )
	{
//		if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP

		FlameSense[1]=1;
//		Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);

	}

}

void Rot_Right_PID(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Rotate Right PID \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL= (2 * *COMMAND_LOOP);
	unsigned int DELTA_FR= (2 * *COMMAND_LOOP);
	unsigned int DELTA_ML= (2 * *COMMAND_LOOP);
	unsigned int DELTA_MR= (2 * *COMMAND_LOOP);
	unsigned int DELTA_RL= (2 * *COMMAND_LOOP);
	unsigned int DELTA_RR= (2 * *COMMAND_LOOP);

	//gait_mode(ROTATE_RIGHT,SPEED);
	//1
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg); //mundur
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3); //mundur
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3); //maju
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg); //maju
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg); //mundur
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3); //mundur
	delay_ms(SPEED);

	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg); //mundur
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg); //mundur
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg); //maju
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg); //maju
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg); //mundur
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg); //mundur
	delay_ms(SPEED);

	//3
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3); //maju
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg); //maju
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg); //mundur
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3); //mundur
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3); //maju
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg); //maju
	delay_ms(SPEED);

	//4
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg); //maju
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg); //maju
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg); //mundur
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg); //mundur
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg); //maju
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg); //maju
	delay_ms(SPEED);
}

void Rot_Left_PID(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Rotate Left PID \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL= (2 * *COMMAND_LOOP);
	unsigned int DELTA_FR= (2 * *COMMAND_LOOP);
	unsigned int DELTA_ML= (2 * *COMMAND_LOOP);
	unsigned int DELTA_MR= (2 * *COMMAND_LOOP);
	unsigned int DELTA_RL= (2 * *COMMAND_LOOP);
	unsigned int DELTA_RR= (2 * *COMMAND_LOOP);

	//gait_mode(ROTATE_LEFT, SPEED);
	//1
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg); //maju /
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3); //maju
	inv_kine(middle_left,90+beta[1]+DELTA_ML,10,leg-3); //mundur /
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg); //mundur /
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg); //maju /
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3); //maju /
	delay_ms(SPEED);

	//2
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg); //maju /
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg); //maju /
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg); //mundur /
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg); //mundur /
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg); //maju /
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg); //maju /
	delay_ms(SPEED);

	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3); //mundur /
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg); //mundur /
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg); //maju /
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3); //maju /
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3); //mundur /
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg); //mundur /
	delay_ms(SPEED);

	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg); //mundur /
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg); //mundur /
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg); //maju /
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg); //maju /
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg); //mundur /
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg); //mundur /
	delay_ms(SPEED);


}
void BW_FlameSense(void)
{
//	while(1)
//	{
//		Send_FlameSense[0]();
//		if(FlameSense[0]<4) mov_rot_right(FAST_LEVEL_3,CLOSE);
//		else if(FlameSense[0]>4) mov_rot_left(FAST_LEVEL_3,CLOSE);
//		else if(FlameSense[0]==4) while(1){mov_static();}
//	}

	while(1)
	{
		Send_FlameSense();
		if( (FlameSense[0]<4) && (FlameSense[0]>0) ) mov_rot_left(FAST_LEVEL_3,CLOSE);
		else if(FlameSense[0]>4) mov_rot_right(FAST_LEVEL_3,CLOSE);
		else if(FlameSense[0]==0) mov_rot_right(FAST_LEVEL_3,CLOSE);
		else if(FlameSense[0]==4) {mov_static();}
	}
}


void BW_FlameScanning(void)
{

	static int right=90,left=90;

	generate_movement_data(0,0,9);
	delay_ms(50);

//	while(FlameSense[0]!=3)
//	{
	if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}

		while(right>=10&&left<=170&&FlameSense[0]!=3)
		{
			Send_FlameSense();
			if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);

		if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
		while(right<=90&&left>=90&&FlameSense[0]!=3)
		{
			Send_FlameSense();
			if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
		while(right<=170&&left>=10&&FlameSense[0]!=3)
		{
			Send_FlameSense();
			if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
		while(right>=90&&left<=90&&FlameSense[0]!=3)
		{
			Send_FlameSense();
			if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);
		if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
//	}

//	while(FlameSense[0]==3) {Send_FlameSense();}
}

void BW_FlameExtinguish(int PRESENT_LEFT, int PRESENT_RIGHT)
{
	generate_movement_data(0,0,9);
	delay_ms(50);
	int counter=1;

	int right=PRESENT_RIGHT,left=PRESENT_LEFT;

	EXTINGUISHER_ON;
	delay_ms(2000);
	for(counter=1;counter<=2;counter++)
	{
		while( ( right>= (PRESENT_RIGHT-40) ) && ( left<= (PRESENT_LEFT+40) ) )
		{
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(15);
			right-=1;
			left+=1;
		}

		while( (right<=PRESENT_RIGHT) && (left>=PRESENT_LEFT) )
		{
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(15);
			right+=1;
			left-=1;
		}

		while( (right<= (PRESENT_RIGHT+40) ) && (left>= (PRESENT_LEFT-40) ) )
		{
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(15);
			right+=1;
			left-=1;
		}

		while( (right<=PRESENT_RIGHT) && (left>=PRESENT_LEFT) )
		{
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(15);
			right-=1;
			left+=1;
		}
	}

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//	if(FlameSense[0]>3)
//	{
//		while(FlameSense[0]!=3)
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}
//	else if(FlameSense[0]<3)
//	{
//		while(FlameSense[0]!=3)
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//	}

//	while(UV_Lock==UVLOCK_ACTIVE)
//	{
		Evade_Wall();

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();


		GetFlame();
		if(FLAME_SENSOR[FLM_ANALOG]<=170)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		while(Ping[PING_FRONT]<=13)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

		//LEFT
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=13)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(Ping[PING_FRONT]<=10)
//		{
//			mov_bwd(5,FAST_LEVEL_3);
//		}


		//CENTER
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=13)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=13)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}


//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(Ping[PING_FRONT]<=10)
//		{
//			mov_bwd(5,FAST_LEVEL_3);
//		}


		//RIGHT
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=5)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(Ping[PING_FRONT]<=10)
//		{
//			mov_bwd(5,FAST_LEVEL_3);
//		}



		//CENTER
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=5)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(Ping[PING_FRONT]<=10)
//		{
//			mov_bwd(5,FAST_LEVEL_3);
//		}



//		while(FlameSense[0]==3)
//		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			UVLock_Refresh();
//			if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//		}
		EXTINGUISHER_OFF;


//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(FlameSense[0]!=3)
//		{
//			UVLock_Refresh();
//			if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//		}
//
//
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(FlameSense[0]==3)
//		{
//			UVLock_Refresh();
//			if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}
//
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//	}


//	delay_ms(500);
//
//
//
//	if(FlameSense[0]>3)
//	{
////		while(FlameSense[0]!=3)
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}
//
//	else if(FlameSense[0]<3)
//	{
////		while(FlameSense[0]!=3)
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//	}
//	mov_fwd_5cm(5,FAST_LEVEL_3);
//
//	delay_ms(500);
//
//	UVLock_Refresh();
//	if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//	if(FlameSense[0]>3)
//	{
////		while(FlameSense[0]!=3)
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}
//	else if(FlameSense[0]<3)
//	{
////		while(FlameSense[0]!=3)
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//	}
//
//	mov_fwd_5cm(5,FAST_LEVEL_3);

//	delay_ms(1000);

	EXTINGUISHER_OFF;

}

void FollowFlame_Left(void)
{
//	int counter;
	//int limit=15;
	while(FlameSense[0]==0)
	{
		if (Ping[PING_FRONT]<=5)
		{
			if (Ping[PING_LEFT]>=20)
			{
				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
			}

			if (Ping[PING_LEFT]<20)
			{
				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
			}
		}
		else
		{
			PID_FollowFlame_Left();
		}
	}

}

void PID_FollowFlame_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP

					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{

//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						CurveRight_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveRight_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveRight_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP

					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{

//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						CurveLeft_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveLeft_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveLeft_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}

				}
		}
	}

}




void CurveRight_FlameSense(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right Counter \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
	//unsigned int DELTA_MR;
	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);

	if(FlameSense[0]!=0){FlameTracking();}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3],10,leg-3);
	inv_kine(middle_left,90+beta[1],10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4],10.5,leg-3);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//5
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//6
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+10,7,leg);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);
}


void CurveLeft_FlameSense(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left Counter \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);

	if(FlameSense[0]!=0){FlameTracking();}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//2
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//3
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//4
	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//5
	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//6
	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);
}

/* func      : void BW_FireFollow(void)
 * brief     : BW Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void BW_FireFollow(void)
{
	FollowFlame_Flag	 = FLAG_INACTIVE;
	FlameTrack_Flag 	 = FLAG_INACTIVE;
	FlameScan_Flag   	 = FLAG_INACTIVE;
	FlameExtinguish_Flag = FLAG_INACTIVE;

	BW_Buzz(2);
	Sendto_PC(USART1,"FollowFlame Initializing \r");
	while(FollowFlame_Flag==FLAG_INACTIVE)
	{
		FollowFlame_Flag = FollowFlame_Left_New();
	}
	BW_Buzz(3);
	Sendto_PC(USART1,"FollowFlame Finished \r");

//	if(FlameSense[0]==5) mov_fwd_5cm(15,FAST_LEVEL_3);
//	if(FlameSense[0]==1) mov_fwd_5cm(15,FAST_LEVEL_3);
	if(FlameSense[0]==1) mov_fwd_5cm(15,FAST_LEVEL_3);
	if(FlameSense[0]==1) mov_fwd_5cm(15,FAST_LEVEL_3);

	BW_Buzz(2);
	Sendto_PC(USART1,"FlameTrack Initializing \r");
	while(FlameTrack_Flag==FLAG_INACTIVE)
	{
//		FlameTrack_Flag = FlameTracking_New();
		FlameTracking_New();
	}
	BW_Buzz(3);
	Sendto_PC(USART1,"FollowTrack Finished \r");

	BW_Buzz(2);
	Sendto_PC(USART1,"FlameApproach Initializing \r");
	while(FlameApproach_Flag==FLAG_INACTIVE)
	{
		FlameApproach();
	}
	BW_Buzz(3);
	Sendto_PC(USART1,"FollowApproach Finished \r");
//
//	while(Ping[PING_FRONT]>=17)
//	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}

	while(Ping[PING_FRONT]>=12)
	{
		FlameApproach();
	}

	BW_Buzz(3);
	while(FlameSense[0]!=0)
	{
		BW_FlameScanning();
	}


}


int FollowFlame_Left_New(void)
{
//	int counter;
	//int limit=15;
	while(FollowFlame_Flag==FLAG_INACTIVE)
	{
		if (Ping[PING_FRONT]<=5)
		{
			if (Ping[PING_LEFT]>=20)
			{
				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
			}

			if (Ping[PING_LEFT]<20)
			{
				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
			}
		}
		else
		{
			PID_FollowFlame_Left_New();
		}
	}
	return 0;
}


void PID_FollowFlame_Left_New(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP

					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{

//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						CurveRight_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveRight_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveRight_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP

					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{

//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						CurveLeft_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveLeft_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveLeft_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}

				}
		}
	}

}


void CurveRight_FlameSense_New(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right FlameSense \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
	//unsigned int DELTA_MR;
	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3],10,leg-3);
	inv_kine(middle_left,90+beta[1],10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4],10.5,leg-3);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//5
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//6
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+10,7,leg);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);
}


void CurveLeft_FlameSense_New(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left FlameSense \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//2
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//3
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//4
	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//5
	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//6
	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);
}



int FlameTracking_New(void)
{
//	int counter;
//	for(counter=1;counter<=10;counter++)
	int flametrack_cnt=0;



	while( (FlameSense[0]!=3) && (UV_Lock==UVLOCK_ACTIVE) )
	{
//		Bump_Avoider();
		Evade_Wall();


//		if(Ping[PING_FRONT]<=13) {mov_bwd(15,FAST_LEVEL_3);}
		if(Ping[PING_FRONT]<=8) {mov_bwd_3cm(12,FAST_LEVEL_3);}

		Send_FlameSense();
		PID_FlameTracking_New();
		lcd_display_clear();

		flametrack_cnt++;
		lcd_gotoxy(0,3);sprintf(lcd,"flametrack: %d",flametrack_cnt);lcd_putstr(lcd);
		if(flametrack_cnt>=35)
		{
			flametrack_cnt=0;
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"FLAMETRACKING");lcd_putstr(lcd);
			lcd_gotoxy(4,0);sprintf(lcd,"OVERFLOW");lcd_putstr(lcd);
			delay_ms(100);
			UVLock_Refresh();

		}
	}
	return 0;
}


int PID_FlameTracking_New(void)
{
	float DUMMY_PIDVALUE=1;
	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;

	//OVERCOMING BLIND SPOTS
	if(FlameSense[0]==0) FlameSense[0]=10;
	Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);

	FlameSense_PID_Calc();
	Sendto_PC(USART1,"PID Value : %d \r",(int)PID_FLAME.pid_value[0]);

	//KONDISI ROBOT SESUAI
	if ( FlameSense[0]==PID_FLAME.set_point)
	{
//		mov_static();
//		BW_Buzz(3);
//		while(Ping[PING_FRONT]>=25)
//		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//		}
//
//		BW_FlameScanning();
		Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);
//		return FLAG_ACTIVE;
		FlameTrack_Flag=FLAG_ACTIVE;
	}
//	else if ( FlameSense[0]==(PID_FLAME.set_point-1))
//	{
//
//		Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);
//		FlameTrack_Flag=FLAG_ACTIVE;
//	}
//	else if ( FlameSense[0]==(PID_FLAME.set_point+1))
//	{
//		Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);
//		FlameTrack_Flag=FLAG_ACTIVE;
//	}


	else if(FlameSense[0]==10)
	{

		if ( (FlameSense[1]==10) || (FlameSense[1]==0) )
		{
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}
		else if( (FlameSense[1]==1) )
		{
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSense[1]==5) )
		{
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSense[1] > PID_FLAME.set_point )
		{
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSense[1] < PID_FLAME.set_point )
		{
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}



	}
	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSense[0] > PID_FLAME.set_point )
	{
//		if (PID_FLAME.pid_value[0]>5) PID_FLAME.pid_value[0]=5; //WINDUP


		Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSense[1]=5;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSense[0] < PID_FLAME.set_point )
	{
//		if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP

		FlameSense[1]=1;
		Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);

	}
	return 0;

}

/* func      : int FlameApproach(void)
 * brief     : BW Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
int FlameApproach(void)
{
	Get_UV();
	Send_FlameSense();
//	Evade_Wall();
	Evade_Wall_Room();
	PID_FlameApproach();

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();

//	Get_IR();
//	if(
//			( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ) &&
//			( (FlameSense[0]!=3) )
//	  )
//	{
//		BW_Buzz(5);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"FURNITURE");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
//		delay_ms(100);
//
//		if(Ping[PING_RIGHT]<=Ping[PING_LEFT])
//		{
//			BW_PID_Init();
//			follow_right_counter(2);
//		}
//
//		else if(Ping[PING_LEFT]<Ping[PING_RIGHT])
//		{
//			BW_PID_Init();
//			follow_left_counter(2);
//		}
////		FlameTracking_New();
//
//	}



	return 0;
}


/* func      : int PID_FlameApproach(void)
 * brief     : Calculating and actuating kinematics for Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called FlameApproach() function
 *
 */
int PID_FlameApproach(void)
{
	float DUMMY_PIDVALUE=5;
	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;

	//OVERCOMING BLIND SPOTS
	if(FlameSense[0]==0) FlameSense[0]=5;
	Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);

	FlameSense_PID_Calc();
	Sendto_PC(USART1,"PID Value : %d \r",(int)PID_FLAME.pid_value[0]);

	//KONDISI ROBOT SESUAI
	if ( FlameSense[0]==PID_FLAME.set_point)
	{
//		FlameApproach_Flag=FLAG_ACTIVE;
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
//		BW_HydroPump();
//		BW_Celebrate();

//		if(Ping[PING_FRONT]<=20)
//		{
//			FlameApproach_Flag=FLAG_ACTIVE;
//		}
	}

	else if(FlameSense[0]==5)
	{

		if ( (FlameSense[1]==0) || (FlameSense[1]==5) )
		{
//			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);

			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if( (FlameSense[1]==1) )
		{
//			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
//			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSense[1]==5) )
		{
//			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
//			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSense[1] > PID_FLAME.set_point )
		{
//			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSense[1] < PID_FLAME.set_point )
		{
//			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}



	}
	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSense[0] > PID_FLAME.set_point )
	{
		if (PID_FLAME.pid_value[0]>10) PID_FLAME.pid_value[0]=10; //WINDUP

//		CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSense[1]=5;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSense[0] < PID_FLAME.set_point )
	{
		if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP

		FlameSense[1]=1;
//		CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);

	}
	return 0;
}

/* func      : void CurveRight_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP)
 * brief     : Applying actuating signal to curve right locomotion
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called FlameApproach() function
 *
 */
void CurveRight_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right FlameSense \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	unsigned int DELTA_FL=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_MR=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_RL=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (4 * *COMMAND_LOOP);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//5
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//6
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);
}

/* func      : void CurveLeft_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP)
 * brief     : Applying actuating signal to curve left locomotion
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called FlameApproach() function
 *
 */
void CurveLeft_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left FlameSense \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_ML=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_RL=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (4 * *COMMAND_LOOP);

//	Evade_Wall();
	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}


	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}

	//2
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//3
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//4
	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//5
	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//6
	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);
}


void RotRight_Angle(void)
{
	int Init_Angle;

	GetCMPS11_Angle8Bit();
	GetCMPS11_Angle8Bit();
	GetCMPS11_Angle8Bit();
	GetCMPS11_Angle8Bit();
	GetCMPS11_Angle8Bit();

	Init_Angle = BW_CMPS11.Compass8Bit+90;

	while( BW_CMPS11.Compass8Bit <= Init_Angle )
	{
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		GetCMPS11_Angle8Bit();
		if(BW_CMPS11.Compass8Bit > Init_Angle) break;
	}

	while(1)
	{
		mov_static();
		BW_Buzz(1);
	}
}

void RotLeft_Angle(void)
{
	int Init_Angle;

	GetCMPS11_Angle16Bit();

	Init_Angle = BW_CMPS11.Compass16Bit[MERGED];

	while( BW_CMPS11.Compass16Bit[MERGED] >= (Init_Angle-90) )
	{
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}
}




/*==============================================================================================
								BW DEMO ROUTINES
===============================================================================================*/
void Obstacle_Avoider(void)
{
	Get_IR();
	while(
			(Ping[PING_FRONT]>=20) &&
			(INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)
		 )
	{
		Get_IR();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);
	}
//	BW_Celebrate();

	BW_Buzz(4);
	if(Ping[PING_RIGHT]>=Ping[PING_LEFT])
	{
		while(Ping[PING_FRONT]<20)
		{
			BW_Buzz(1);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}
	}

	else if(Ping[PING_LEFT]>=Ping[PING_RIGHT])
	{
		while(Ping[PING_FRONT]<20)
		{
			BW_Buzz(1);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
		}
	}
}


void Object_Follow(void)
{
	Get_IR();
	if(
			(Ping[PING_FRONT]<25) &&
			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) &&
			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)
	  )
	{
//		BW_Celebrate();
		mov_static();
		BW_Buzz(2);
	}

	else
	{
		if( (Ping[PING_ASKEW_RIGHT]<60) || (Ping[PING_RIGHT]<60) )
//		if( (SHARP[SHARP_RIGHT]<60) || (Ping[PING_RIGHT]<60) )
		{
			while(
					(Ping[PING_FRONT]>=55)
				 )
			{
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}
		}

		else if( (Ping[PING_ASKEW_LEFT]<60) || (Ping[PING_LEFT]<60) )
//		else if( (SHARP[SHARP_LEFT]<60) || (Ping[PING_LEFT]<60) )
		{
			while(
					(Ping[PING_FRONT]>=55)
				 )
			{
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
			}
		}
	}

	Get_IR();
	while(
			(Ping[PING_FRONT]>=15) &&
			(INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)
		 )
	{
		Get_IR();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);
	}
}

//void Avoider (void)
//{
//	GetBumper();
//
//	if(BUMPER[LEFT]==1)
//	{
//		BW_Action_A();
//	}
//	if(BUMPER[RIGHT]==1)
//	{
//		BW_Celebrate();
//	}
//
//	if(Ping[PING_FRONT]<=30)
//	{
//		while(Ping[PING_FRONT]<=30)
//		{
//			mov_bwd(10,FAST_LEVEL_3);
//		}
//
//	}
//
//	else if (Ping[PING_RIGHT]<=30)
//	{
//		while(Ping[PING_RIGHT]<=30)
//		{
//			mov_deflect_left(FAST,CLOSE);
//		}
//	}
//
//	else if (Ping[PING_LEFT]<=30)
//	{
//		while(Ping[PING_LEFT]<=30)
//		{
//			mov_deflect_right(FAST,CLOSE);
//		}
//	}
//
//	else if (Ping[PING_ASKEW_RIGHT]<=30)
//	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//		if(Ping[PING_FRONT]>=30)
//		{
//			mov_fwd_5cm(20,FAST_LEVEL_3);
//		}
//	}
//
//	else if (Ping[PING_ASKEW_LEFT]<=30)
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//		if(Ping[PING_FRONT]>=30)
//		{
//			mov_fwd_5cm(20,FAST_LEVEL_3);
//		}
//	}
//}

/* func      : void FollowTracer_Right(void)
 * brief     : Wall Following Right Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowTracer_Right(void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;

	CAT_FLAG = CAT_NOT_DETECTED;
//	TRACER_STAT=TRACER_BLACK;
	TCSlave_Check();

	while(
			(TCS3200_SLV_DATA[1]!=TRACER_WHITE) &&
			(TRACER_STAT==TRACER_BLACK) &&
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=15)
		{
			if (TRACER_STAT==TRACER_WHITE)break;

			mov_rot_left(FAST_LEVEL_3, FAR);
			mov_rot_left(FAST_LEVEL_3, FAR);
			GetBumper();
			while(BUMPER[RIGHT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_2);
				mov_rot_left(FAST, FAR);
				mov_rot_left(FAST, CLOSE);
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[RIGHT]==INACTIVE)break;
			}
			GetBumper();
			while(BUMPER[LEFT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_2);
				mov_rot_right(FAST, FAR);
				mov_rot_right(FAST, CLOSE);
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[LEFT]==INACTIVE)break;
			}
		}
		else
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			PID_FollowTracer_Right();
		}
	}
}

/* func      : void PID_FollowTracer_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowTracer_Right(void)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
	PID_Calc_RightRule();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=15)
					{
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_WHITE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=15)
					{
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
								if (TRACER_STAT==TRACER_WHITE)break;
								mov_fwd_5cm(5, FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
								mov_rot_left(FAST_LEVEL_3, FAR);
								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
//									mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE) break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
//									mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_3);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE) break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}


						}

						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
				{

					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=15)
					{
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE) break;

						if(WINDUP_LEFT_COUNTER>=25)
							{
								BW_Buzz(5);
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
								delay_ms(100);

								while(Ping[PING_FRONT]>=15)
								{
									if (TRACER_STAT==TRACER_WHITE)break;
									mov_fwd_5cm(5, FAST_LEVEL_3);
									GetBumper();
									if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
								}
								while(Ping[PING_RIGHT]>=16)
								{
									mov_rot_left(FAST_LEVEL_3, FAR);
									mov_rot_left(FAST_LEVEL_3, FAR);
									GetBumper();
									while(BUMPER[RIGHT]==ACTIVE)
									{
										BW_Buzz(1);
										mov_bwd_3cm(6,FAST_LEVEL_2);
										mov_rot_left(FAST, FAR);
										mov_rot_left(FAST, CLOSE);
//										mov_rot_left(FAST_LEVEL_3, CLOSE);
										GetBumper();
										if(BUMPER[RIGHT]==INACTIVE) break;
									}
									GetBumper();
									while(BUMPER[LEFT]==ACTIVE)
									{
										BW_Buzz(1);
										mov_bwd_3cm(6,FAST_LEVEL_2);
										mov_rot_right(FAST, FAR);
										mov_rot_right(FAST, CLOSE);
//										mov_rot_right(FAST_LEVEL_3, CLOSE);
										GetBumper();
										if(BUMPER[LEFT]==INACTIVE)break;
									}
								}
								//RESET WINDUP RIGHT COUNTER
								WINDUP_LEFT_COUNTER=0;

								//REINIT PID
								BW_PID_Init();
							}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE) break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_3);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void FollowTracer_Right_Reverse(void)
 * brief     : Wall Following Right Reverse Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Wed, Dec 21st 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowTracer_Right_Reverse (void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;

	CAT_FLAG = CAT_NOT_DETECTED;
	TCSlave_Check();

	while(
			(TCS3200_SLV_DATA[1]!=TRACER_WHITE) &&
			(TRACER_STAT==TRACER_BLACK) &&
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_REAR]<=15)
		{
			if (TRACER_STAT==TRACER_WHITE)break;

			mov_rot_right_reverse(FAST_LEVEL_3, FAR);
//			mov_rot_right_reverse(FAST_LEVEL_3, FAR);
		}
		else
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			PID_FollowTracer_Right_Reverse();
		}
	}
}

/* func      : void PID_FollowTracer_Right_Reverse (void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Wed, Dec 21st 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */

void PID_FollowTracer_Right_Reverse (void)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_RightRule_Reverse();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_REAR_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_REAR]<=15)
					{
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
//						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_WHITE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
						mov_bwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_REAR_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=15)
					{
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
//						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								if (TRACER_STAT==TRACER_WHITE)break;
								mov_bwd_5cm(5, FAST_LEVEL_3);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
								mov_rot_right_reverse(FAST_LEVEL_3, FAR);
//								mov_rot_right_reverse(FAST_LEVEL_3, FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_right_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);

							mov_bwd_5cm(5,FAST_LEVEL_2);
//							mov_bwd_3cm(3,FAST_LEVEL_2);
						}
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_REAR_RIGHT]<PID_F_R.set_point )
				{

					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=15)
					{
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
//						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE) break;

						if(WINDUP_LEFT_COUNTER>=25)
							{
								BW_Buzz(5);
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
								delay_ms(100);

								while(Ping[PING_REAR]>=15)
								{
									if (TRACER_STAT==TRACER_WHITE)break;
									mov_bwd_5cm(5, FAST_LEVEL_3);
//									GetBumper();
//									if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
								}
								while(Ping[PING_RIGHT]>=16)
								{
									mov_rot_right_reverse(FAST_LEVEL_3, FAR);
//									mov_rot_right_reverse(FAST_LEVEL_3, FAR);
								}
								//RESET WINDUP RIGHT COUNTER
								WINDUP_LEFT_COUNTER=0;

								//REINIT PID
								BW_PID_Init();
							}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_left_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);

							mov_bwd_5cm(5,FAST_LEVEL_2);
//							mov_bwd_3cm(3,FAST_LEVEL_2);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void FollowTracer_Left(void)
 * brief     : Wall Following Left Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowTracer_Left(void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;
	CAT_FLAG=CAT_NOT_DETECTED;

	TCSlave_Check();

	while(
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(TCS3200_SLV_DATA[1]!=TRACER_WHITE) &&
			(TRACER_STAT==TRACER_BLACK) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=14)
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");
			mov_rot_right(FAST_LEVEL_3, FAR);
			mov_rot_right(FAST_LEVEL_3, FAR);
		}
		else
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			PID_FollowTracer_Left();
		}
	}
}

/* func      : void PID_FollowTracer_Left(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowTracer_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, FAR);

							GetBumper();
							if(BUMPER[LEFT]==INACTIVE) break;
						}
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
//						if (Ping[PING_LEFT]>=15)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<15)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_WHITE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3, FAR);
								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
//									mov_rot_right(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE) break;
								}
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
//									mov_rot_left(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE) break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE) break;
							}
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE) break;
							}
						}


						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE) break;
						}
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3, FAR);
								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
//									mov_rot_right(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE) break;
								}
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
//									mov_rot_left(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE) break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE) break;
							}
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE) break;
							}
						}
						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void FollowTracer_Left(void)
 * brief     : Wall Following Left Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowTracer_Left_Reverse(void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;
	CAT_FLAG=CAT_NOT_DETECTED;

	TCSlave_Check();

	while(
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(TCS3200_SLV_DATA[1]!=TRACER_WHITE) &&
			(TRACER_STAT==TRACER_BLACK) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_REAR]<=14)
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");
			mov_rot_left_reverse(FAST_LEVEL_3, FAR);
			mov_rot_left_reverse(FAST_LEVEL_3, FAR);
		}
		else
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			PID_FollowTracer_Left_Reverse();
		}
	}
}

/* func      : void PID_FollowTracer_Left(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowTracer_Left_Reverse(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule_Reverse();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_REAR_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_REAR]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);

					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_WHITE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_bwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_REAR_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_bwd_5cm(5,FAST_LEVEL_3);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{

								mov_rot_left_reverse(FAST_LEVEL_3, FAR);
								mov_rot_left_reverse(FAST_LEVEL_3, FAR);

							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							mov_bwd_5cm(10,FAST_LEVEL_2);

						}
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_REAR_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_REAR]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");

						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);

					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_bwd_5cm(5,FAST_LEVEL_3);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{

								mov_rot_left_reverse(FAST_LEVEL_3, FAR);
								mov_rot_left_reverse(FAST_LEVEL_3, FAR);

							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							mov_bwd_5cm(10,FAST_LEVEL_2);

						}
						OVERRIDE=1;
					}

				}
		}
	}

}


/* func      : void FollowCarpet_Right(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Wall Following Right Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 *
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, March 18th 2016)
 * Revised By: Ver. 2 -> Ryan (Thursday, April 21st 2016
 * 					Configured for the new Hybrid TCS3200+Tracer Processor
 * programmer's Note:
 *
 */
void FollowCarpet_Right(int CARPET_CODE, int FOLLOW_MODE)
{
//	int counter;
	//int limit=15;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG=CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL: //BW FOLLOW WHILE CARPET == X
				{
					while( (TCS3200_SLV_DATA[0]==CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=16)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, FAR);
							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							if (Ping[PING_RIGHT]<=20)
//							{
//								Sendto_PC(USART1,"BW ROTATE LEFT \r");
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//							}
//
//							if (Ping[PING_RIGHT]>20)
//							{
//								Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//							}
						}
						else
						{
							PID_FollowCarpet_Right();
						}
					}
				}break;


		case INVERSE: ////BW FOLLOW WHILE CARPET != X
				{
					while( (TCS3200_SLV_DATA[0]!=CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=16)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, FAR);
							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							if (Ping[PING_RIGHT]<=20)
//							{
//								Sendto_PC(USART1,"BW ROTATE LEFT \r");
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//							}
//
//							if (Ping[PING_RIGHT]>20)
//							{
//								Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//							}
						}
						else
						{
							PID_FollowCarpet_Right();
						}
					}
				}break;
	}
}


/* func      : void PID_FollowCarpet_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowCarpet_Right(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
	PID_Calc_RightRule();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//			if ( (SHARP[SHARP_RIGHT]<=PID_F_R.set_point_upper) && (SHARP[SHARP_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=16)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=16)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=16)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3, FAR);
								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_3);
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST_LEVEL_3, FAR);
								mov_rot_left(FAST_LEVEL_3, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=16)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=16)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3, FAR);
								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_3);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void FollowCarpet_Right_Reverse(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Wall Following Right Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 *
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Thursday, Feb 2th 2017)
 * Revised By:
 * programmer's Note:
 *
 */
void FollowCarpet_Right_Reverse(int CARPET_CODE, int FOLLOW_MODE)
{
//	int counter;
	//int limit=15;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG=CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL: //BW FOLLOW WHILE CARPET == X
				{
					while( (TCS3200_SLV_DATA[0]==CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_REAR]<=16)
						{
							mov_rot_right_reverse(FAST_LEVEL_3, FAR);
							mov_rot_right_reverse(FAST_LEVEL_3, FAR);
						}
						else
						{
							PID_FollowCarpet_Right_Reverse();
						}
					}
				}break;


		case INVERSE: ////BW FOLLOW WHILE CARPET != X
				{
					while( (TCS3200_SLV_DATA[0]!=CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_REAR]<=16)
						{
							mov_rot_right_reverse(FAST_LEVEL_3, FAR);
							mov_rot_right_reverse(FAST_LEVEL_3, FAR);
						}
						else
						{
							PID_FollowCarpet_Right_Reverse();
						}
					}
				}break;
	}
}


/* func      : void PID_FollowCarpet_Right_Reverse(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Thursday, Feb 2th 2017)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowCarpet_Right_Reverse(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
	PID_Calc_RightRule_Reverse();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_REAR_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_REAR_RIGHT]>=PID_F_R.set_point_lower) )
//			if ( (SHARP[SHARP_RIGHT]<=PID_F_R.set_point_upper) && (SHARP[SHARP_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_REAR]<=16)
					{
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
						mov_bwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_REAR_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=16)
					{
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=16)
							{
								mov_bwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
								mov_rot_right_reverse(FAST_LEVEL_3, FAR);
								mov_rot_right_reverse(FAST_LEVEL_3, FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							curve_right_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);

							mov_bwd_5cm(5,FAST_LEVEL_2);
							mov_bwd_3cm(3,FAST_LEVEL_2);
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_REAR_RIGHT]<PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=16)
					{
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=16)
							{
								mov_bwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
								mov_rot_right_reverse(FAST_LEVEL_3, FAR);
								mov_rot_right_reverse(FAST_LEVEL_3, FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							curve_left_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);

							mov_bwd_5cm(10,FAST_LEVEL_2);
							mov_bwd_3cm(3,FAST_LEVEL_2);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}


/* func      : void FollowCarpet_Left(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Wall Following Left Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 *
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, March 18th 2016)
 * Revised By:
 * 				Ver. 2 -> Ryan (Thursday, April 21st 2016
 * 					Configured for the new Hybrid TCS3200+Tracer Processor
 * programmer's Note:
 *
 */
void FollowCarpet_Left(int CARPET_CODE, int FOLLOW_MODE)
{

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG= CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL:
				{
					while(
							(TCS3200_SLV_DATA[0]==CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)
//							(TCS3200_SLV_DATA[1]==CARPET_CODE)
						 )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=14)
						{
							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, FAR);
							mov_rot_right(FAST_LEVEL_3, FAR);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							if (Ping[PING_LEFT]>=20)
//							{
//								Sendto_PC(USART1,"BW ROTATE LEFT \r");
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//							}
//
//							if (Ping[PING_LEFT]<20)
//							{
//								Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//							}
						}
						else
						{
							PID_FollowCarpet_Left();
						}
					}
				}break;

		case INVERSE:
				{
					while(
							(TCS3200_SLV_DATA[0]!=CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)//||
//							(TCS3200_SLV_DATA[1]!=CARPET_CODE)
						 )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=14)
						{
							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, FAR);
							mov_rot_right(FAST_LEVEL_3, FAR);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							if (Ping[PING_LEFT]>=20)
//							{
//								Sendto_PC(USART1,"BW ROTATE LEFT \r");
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//							}
//
//							if (Ping[PING_LEFT]<20)
//							{
//								Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//							}
						}
						else
						{
							PID_FollowCarpet_Left();
						}
					}
				}break;
	}
}

/* func      : void PID_FollowTracer_Left(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: Ver 3. Toni (Wed, November 30th 2016)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowCarpet_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

//							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
////							mov_rot_right(FAST_LEVEL_3, CLOSE);
////							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, FAR);
//							mov_rot_right(FAST_LEVEL_3, FAR);
//
////							while(Ping[PING_FRONT]>=18)
////							{
////								mov_fwd_5cm(5,FAST_LEVEL_3);
////								GetBumper();
////								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
////							}
////							while(Ping[PING_LEFT]>=15)
////							{
////								mov_rot_right(FAST_LEVEL_3,CLOSE);
////								mov_rot_right(FAST_LEVEL_3,CLOSE);
////							}

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3, FAR);
								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
//									mov_rot_right(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE) break;
								}
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
//									mov_rot_left(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE) break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_2,FAR);
								mov_rot_right(FAST_LEVEL_2,FAR);
								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);

						}
						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void FollowCarpet_Left_Reverse(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Wall Following Left Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 *
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Thursday, Feb 2th 2017)
 * Revised By:
 *
 * programmer's Note:
 *
 */
void FollowCarpet_Left_Reverse(int CARPET_CODE, int FOLLOW_MODE)
{

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG= CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL:
				{
					while(
							(TCS3200_SLV_DATA[0]==CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)
//							(TCS3200_SLV_DATA[1]==CARPET_CODE)
						 )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_REAR]<=14)
						{
//							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
							mov_rot_left_reverse(FAST_LEVEL_3, FAR);
							mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						}
						else
						{
							PID_FollowCarpet_Left_Reverse();
						}
					}
				}break;

		case INVERSE:
				{
					while(
							(TCS3200_SLV_DATA[0]!=CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)//||
//							(TCS3200_SLV_DATA[1]!=CARPET_CODE)
						 )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_REAR]<=14)
						{
//							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
							mov_rot_left_reverse(FAST_LEVEL_3, FAR);
							mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						}
						else
						{
							PID_FollowCarpet_Left_Reverse();
						}
					}
				}break;
	}
}

/* func      : void PID_FollowTracer_Left_Reverse(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Thursday, Feb 2th 2017)
 * Revised BY:
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowCarpet_Left_Reverse(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule_Reverse();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_REAR_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_REAR_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_REAR]<=14)
					{
//						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_bwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_REAR_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

//							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
////							mov_rot_right(FAST_LEVEL_3, CLOSE);
////							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, FAR);
//							mov_rot_right(FAST_LEVEL_3, FAR);
//
////							while(Ping[PING_FRONT]>=18)
////							{
////								mov_fwd_5cm(5,FAST_LEVEL_3);
////								GetBumper();
////								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
////							}
////							while(Ping[PING_LEFT]>=15)
////							{
////								mov_rot_right(FAST_LEVEL_3,CLOSE);
////								mov_rot_right(FAST_LEVEL_3,CLOSE);
////							}

							while(Ping[PING_REAR]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_bwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
								mov_rot_left_reverse(FAST_LEVEL_3, FAR);
								mov_rot_left_reverse(FAST_LEVEL_3, FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							curve_right_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							mov_bwd_5cm(10,FAST_LEVEL_2);
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_REAR_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_REAR]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");

						mov_rot_left_reverse(FAST_LEVEL_3, FAR);
						mov_rot_left_reverse(FAST_LEVEL_3, FAR);

					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_bwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
								mov_rot_left_reverse(FAST_LEVEL_3, FAR);
								mov_rot_left_reverse(FAST_LEVEL_3, FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							curve_left_counter_reverse(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							mov_bwd_5cm(10,FAST_LEVEL_2);

						}
						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void FollowTracer_Right(void)
 * brief     : Wall Following Right Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowHome_Right(void)
{
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	TCSlave_Check();


	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	HOME_CIRCLE_FLAG=HOME_CIRCLE_NOT_DETECTED;

	//ACTIVATE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_ACTIVE;

	CAT_FLAG= CAT_NOT_DETECTED;


	while(
			(HOME_CIRCLE_FLAG==HOME_CIRCLE_NOT_DETECTED) && (CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=13)
		{
			if (Ping[PING_RIGHT]<=20)
			{
				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);

			}

			if (Ping[PING_RIGHT]>20)
			{
				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
			}
		}
		else
		{
			PID_FollowHome_Right();
		}
	}



}

/* func      : void PID_FollowTracer_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowHome_Right(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
//	Sendto_PC(USART1,"SHARP: %d \t",(int)SHARP[SHARP_RIGHT]);
	PID_Calc_RightRule();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//			if ( (SHARP[SHARP_RIGHT]<=PID_F_R.set_point_upper) && (SHARP[SHARP_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_RIGHT]<=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_RIGHT]>20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>6)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=6; //WINDUP
					}

					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_RIGHT]<=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_RIGHT]>20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=13)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=15)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3,CLOSE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]<PID_F_R.set_point )
				{

					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>6)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=6; //WINDUP

					}

					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_RIGHT]<=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3,CLOSE);
							mov_rot_left(FAST_LEVEL_3,CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_RIGHT]>20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=13)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=15)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3,CLOSE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}
		}
	}

}


/* func      : void FollowTracer_Left(void)
 * brief     : Wall Following Left Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowHome_Left(void)
{


//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	TCSlave_Check();

	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	HOME_CIRCLE_FLAG=HOME_CIRCLE_NOT_DETECTED;

	//ACTIVATE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_ACTIVE;

	CAT_FLAG= CAT_NOT_DETECTED;



	while(
			(HOME_CIRCLE_FLAG==HOME_CIRCLE_NOT_DETECTED) && (CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=13)
		{
			if (Ping[PING_LEFT]>=25)
			{
				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
			}

			if (Ping[PING_LEFT]<25)
			{
				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
			}
		}
		else
		{
			PID_FollowHome_Left();
		}
	}



}

/* func      : void PID_FollowTracer_Left(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowHome_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_LEFT]>=25)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<25)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_LEFT]>=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=13)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3,CLOSE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_LEFT]>=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=13)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3,CLOSE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}
		}
	}

}



/* func      : void WallFollow_Tester(void)
 * brief     : Wallfollower Tester
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, March 21st 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void WallFollow_Tester(void)
{
	int MENU_VAR;

	while(BUTTON_IDLE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"WALL FOLLOW TESTER");lcd_putstr(lcd);
		delay_ms(100);
	}

	if(BW_BUTTON_CLICKED)
	{
		while(BUTTON_IDLE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"WALL FOLLOW TESTER");lcd_putstr(lcd);
			delay_ms(100);
		}
		delay_ms(1000);

		while(1)
		{
			while(BW_BUTTON_UNCLICKED)
			{
				if(BUTTON_A_CLICKED)
				{
					BW_Buzz(2);
					while(BUTTON_A_CLICKED){};
					MENU_VAR++;
				}
				if(BUTTON_B_CLICKED)
				{
					BW_Buzz(1);
					while(BUTTON_B_CLICKED){};
					MENU_VAR--;
				}

				if(MENU_VAR>3) MENU_VAR=0;
				else if (MENU_VAR<0) MENU_VAR=3;
			}


			switch(MENU_VAR)
			{
				case 0:
						{
							lcd_display_clear();
							lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW BLACK");lcd_putstr(lcd);
							FollowCarpet_Right(COLOUR_BLACK,INVERSE);
							while(1)
							{
								BW_Buzz(3);
								mov_static();
							}
						}break;

				case 1:
						{
							lcd_display_clear();
							lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW GRAY");lcd_putstr(lcd);
							FollowCarpet_Right(COLOUR_GRAY,INVERSE);
							while(1)
							{
								BW_Buzz(3);
								mov_static();
							}
						}break;
				case 2:
						{
							lcd_display_clear();
							lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW WHITE");lcd_putstr(lcd);
							FollowCarpet_Right(COLOUR_WHITE,INVERSE);
							while(1)
							{
								BW_Buzz(3);
								mov_static();
							}
						}break;
				case 3:
						{
							lcd_display_clear();
							lcd_gotoxy(0,1);sprintf(lcd,"NO FOLLOW");lcd_putstr(lcd);
							while(1)
							{
								BW_Buzz(3);
								mov_static();
							}
						}break;

			}

		}

	}
}


/* func      : void RoomTypeDetector(void)
 * brief     : Detects Room Type, whether it's GRAY_ROOM or NORMAL_ROOM
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Ryan (Monday, March 21st 2016)
 * Revised BY: Hafidin
 * 				Ver.3 : (Saturday, April 22nd, 2017)
 * 				Ver.4 : Hafidin (Tue, May 2nd 2017)
 * 				Ver.5 : Bertoni (Tue, Sept 12nd 2017)
 * programmer's Note:
 *
 */
void RoomTypeDetector(void)
{
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	delay_ms(50);

	if	(
			(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
		)

	{
		BW_Buzz(1);
		ROOM_TYPE= GRAY_ROOM;

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"GRAY ROOM");lcd_putstr(lcd);

		delay_ms(50);

	}
	else if	(
			(TCS3200_SLV_DATA[1]==COLOUR_BLACK)
		)
	{
		ROOM_TYPE= NORMAL_ROOM;

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"NORMAL ROOM");lcd_putstr(lcd);

		delay_ms(50);
	}
	else
	{
		ROOM_TYPE= NORMAL_ROOM;

		BW_PID_Init_Room();

		if(FOLLOW_FLAG==KIRI)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"ID FAILED LEFT");lcd_putstr(lcd);
			delay_ms(50);

			if(Ping[PING_ASKEW_LEFT]>20)
			{
//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST, IKCALC_DISABLE);
				Bumper_Action();
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE, IKCALC_ENABLE);
				Bumper_Action();
			}

			BW_FollowCounter_Left(1);
		}
		else
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"ID FAILED RIGHT");lcd_putstr(lcd);
			delay_ms(50);

			if(Ping[PING_ASKEW_RIGHT]>20)
			{
//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST, IKCALC_DISABLE);
				Bumper_Action();
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE, IKCALC_ENABLE);
				Bumper_Action();
			}

			BW_FollowCounter_Right(1);

		}
		RoomTypeDetector();

	}

}



/* func      : void RoomDetector(void)
 * brief     : Detect room and store the room identifiers
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, March 21st 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void RoomDetector(int ROOM_COUNTER)
{
	Get_IR();
//	if( (Ping[PING_FRONT]>=40)&& ((SHARP[SHARP_FRONT_L]>=30)||(SHARP[SHARP_FRONT_R]>=30)) )
	if(Ping[PING_FRONT]>=50)
	{
		Get_IR();
		if( (Ping[PING_LEFT]<=50) && (Ping[PING_ASKEW_LEFT]<=30) && (Ping[PING_REAR_LEFT]<=30))
		{
			ROOM[ROOM_COUNTER]= ROOM_1C;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DOOR C ");lcd_putstr(lcd);
			delay_ms(100);
		}
		else
		{
			GetCMPS11_Angle8Bit();	// INTERFERENSI PING KANAN
			if(ROOM_TYPE==GRAY_ROOM)
			{
				ROOM[ROOM_COUNTER]= ROOM_2B;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 2");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
				delay_ms(100);
			}

			else if( (Ping[PING_RIGHT]>=50)  )
			{
				ROOM[ROOM_COUNTER]= ROOM_1C;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR C ALT");lcd_putstr(lcd);
				delay_ms(100);
			}
			else
			{
				if((CMPS11_Angle>R4A_THRESHOLD_UPPER) && (CMPS11_Angle<R4A_THRESHOLD_LOWER))
//				if((CMPS11_Angle>R4A_THRESHOLD_UPPER) && (CMPS11_Angle<R4B_THRESHOLD_UPPER))
				{
					ROOM[ROOM_COUNTER]= ROOM_1A;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR A");lcd_putstr(lcd);
					delay_ms(100);
				}
				else
				{
					ROOM[ROOM_COUNTER]= ROOM_1C;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR C ALT");lcd_putstr(lcd);
					delay_ms(100);

				}
			}

		}
	}
	else
	{
		Get_IR();
		if( (Ping[PING_RIGHT]<40) && (Ping[PING_ASKEW_RIGHT]<30) )
//		if( (Ping[PING_RIGHT]<40) && (Ping[PING_ASKEW_RIGHT]<46) && (Ping[PING_REAR_RIGHT]<30) ) // INTERFERENSI 1B
		{
			if(ROOM_TYPE==GRAY_ROOM)
			{
				ROOM[ROOM_COUNTER]= ROOM_2A;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 2");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR A ");lcd_putstr(lcd);
				delay_ms(100);
			}
			else
			{
				ROOM[ROOM_COUNTER]= ROOM_3;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 3");lcd_putstr(lcd);
				delay_ms(100);
			}

		}

		else if( (Ping[PING_LEFT]>=30) && (Ping[PING_RIGHT]>=40) )
//		else if( (Ping[PING_LEFT]>=30) && (Ping[PING_RIGHT]>=25) )// PING KANAN INTERFERENSI
		{

			if( ( (Ping[PING_LEFT]>=30) && (Ping[PING_LEFT]<75) ) && ( (Ping[PING_ASKEW_RIGHT]>=128) || (Ping[PING_RIGHT]>=128) ) )
			{
				ROOM[ROOM_COUNTER]= ROOM_1B;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
				delay_ms(100);

				//BW RE-CHECKING

//				DETECTOR IR USED
//				Get_IR();
//				if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
				if(Ping[PING_REAR]<=70)
				{
					GetCMPS11_Angle8Bit();
					if((CMPS11_Angle<R4A_THRESHOLD_UPPER) && (CMPS11_Angle>R4B_THRESHOLD_UPPER))
/*GOR*/	//			if((CMPS11_Angle>R4A_THRESHOLD_UPPER) && (CMPS11_Angle<R4B_THRESHOLD_UPPER))
					{
						ROOM[ROOM_COUNTER]= ROOM_1B;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
						delay_ms(100);
					}
					else
					{
						ROOM[ROOM_COUNTER]= ROOM_4B;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
						delay_ms(100);
					}

				}
				else
				{
					ROOM[ROOM_COUNTER]= ROOM_1B;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
					delay_ms(100);
				}

			}

			else
			{

				if( ( (Ping[PING_LEFT]>=40) && (Ping[PING_LEFT]<75) ) && (Ping[PING_RIGHT]>=80) && (Ping[PING_ASKEW_RIGHT]>=80))
				{
					ROOM[ROOM_COUNTER]= ROOM_1B;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
					delay_ms(100);

					//BW RE-CHECKING

//					Get_IR();
//					if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
					if(Ping[PING_REAR]<=70)
					{
						GetCMPS11_Angle8Bit();
						if((CMPS11_Angle<R4A_THRESHOLD_UPPER) && (CMPS11_Angle>R4B_THRESHOLD_UPPER))
/*GOR*/	//				if((CMPS11_Angle>R4A_THRESHOLD_UPPER) && (CMPS11_Angle<R4B_THRESHOLD_UPPER))
						{
							ROOM[ROOM_COUNTER]= ROOM_1B;
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
							delay_ms(100);
						}
						else
						{
							ROOM[ROOM_COUNTER]= ROOM_4B;
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
							delay_ms(100);
						}
					}
					else
					{
						ROOM[ROOM_COUNTER]= ROOM_1B;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
						delay_ms(100);
					}
				}

				else
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4AB ");lcd_putstr(lcd);
					delay_ms(100);

					//BW RE-CHECKING

					while(Ping[PING_FRONT]<=12)
					{
						Dynamx_MovBwd(3,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					}
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//					Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_CLOSE,IKCALC_ENABLE);

//					Get_IR();
////					if( ( (Ping[PING_LEFT]>=40) && (Ping[PING_LEFT]<75) ) && (Ping[PING_RIGHT]>=80) && (Ping[PING_ASKEW_RIGHT]>=80))
//					if(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
					if(Ping[PING_REAR]>=70)
					{
						ROOM[ROOM_COUNTER]= ROOM_1B;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"DOOR B");lcd_putstr(lcd);
						delay_ms(100);
					}

					else
					{
						BW_Buzz(1);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4AB ");lcd_putstr(lcd);
						delay_ms(100);

						GetCMPS11_Angle8Bit();
//						if((CMPS11_Angle<R4B_THRESHOLD_LOWER) || (CMPS11_Angle>R4B_THRESHOLD_UPPER))
						if((CMPS11_Angle<R4B_THRESHOLD_UPPER) || (CMPS11_Angle>R4B_THRESHOLD_LOWER))
						{
							ROOM[ROOM_COUNTER]= ROOM_4B;
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
							delay_ms(100);
						}
						else if((CMPS11_Angle<R4A_THRESHOLD_LOWER) && (CMPS11_Angle>R4A_THRESHOLD_UPPER))
///*GOR*/					else if((CMPS11_Angle<R4A_THRESHOLD_LOWER) && (CMPS11_Angle>R4A_THRESHOLD_UPPER))
						{
							ROOM[ROOM_COUNTER]= ROOM_4A;
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"DOOR A ");lcd_putstr(lcd);
							delay_ms(100);
						}

//						if(Ping[PING_RIGHT]>=75)
//						{
//							ROOM[ROOM_COUNTER]= ROOM_4B;
//							lcd_display_clear();
//							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
//							lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
//							delay_ms(100);
//						}
//						else
//						{
//							ROOM[ROOM_COUNTER]= ROOM_4A;
//							lcd_display_clear();
//							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
//							lcd_gotoxy(0,1);sprintf(lcd,"DOOR A ");lcd_putstr(lcd);
//							delay_ms(100);
//						}
					}
				}
			}
		}
		else
		{

//			mov_static();
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"ROOM ID");lcd_putstr(lcd);
			lcd_gotoxy(4,2);sprintf(lcd,"FAILED");lcd_putstr(lcd);
			delay_ms(50);

//			H_Correction_ExitRoom();
			Get_IR();

			if(Ping[PING_FRONT]>15)
			{
				BW_Buzz(1);
//				Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
			else if(Ping[PING_FRONT]<=15)
			{
				BW_Buzz(1);
//				mov_bwd_5cm(5,FAST_LEVEL_3);
				Dynamx_MovBwd(3,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
			}
			RoomDetector(ROOM_COUNTER);

		}
	}
}

/* func      : void RoomDetector_Check(void)
 * brief     : FollowTracer_
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 23rd 2016)
 * Revised BY: TONI (Thursday, December 1st 2016)
 * programmer's Note: Test detektor setelah keluar ruang
 */
void RoomDetector_Check(void)
{
	RoomTypeDetector();
	RoomTypeDetector();
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	FollowTracer_Right();
//	mov_fwd_5cm(15,FAST_LEVEL_3);
	//LOCATION: CORRIDOR
		BW_Buzz(1);
		H_Correction_Left();

		if(Ping[PING_FRONT]>=16)
		{
			mov_fwd_5cm(10, FAST);
		}

		mov_rot_right(FAST,CLOSE);
	//	mov_rot_right(FAST,FAR);
	//	mov_rot_right(FAST_LEVEL_3,CLOSE);
	//	H_Correction_ExitRoom();

	//	BW_Buzz(1);
		if (Ping[PING_RIGHT]<75)
		{
			if((Ping[PING_ASKEW_RIGHT])>(Ping[PING_RIGHT]))
			{
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
		//		mov_rot_right(FAST,CLOSE);
			}
			if((Ping[PING_ASKEW_RIGHT])<(Ping[PING_RIGHT]))
			{
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
		//		mov_rot_left(FAST,CLOSE);
			}
		}
		else
		{
			if((Ping[PING_ASKEW_LEFT])>(Ping[PING_LEFT]))
			{
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
		//		mov_rot_left(FAST,CLOSE);
			}
			if((Ping[PING_ASKEW_LEFT])<(Ping[PING_LEFT]))
			{
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
		//		mov_rot_right(FAST,CLOSE);
			}

		}
	RoomDetector(1);
	while(1)
	{
		RoomDetector(1);
		mov_static();
	}
}

/* func      : void BW_FireFight(void)
 * brief     : BW FireFighting Routines
 * param     : N/A
 * retval    : N/A
 * Ver       : 6
 * written By: Ryan (Thursday, March 23rd 2016)
 * Revised BY: Hafidin (Monday, Feb 27th 2017) Ver.3
 * 				Ver.4: Ryan (Sunday, April 23rd 2017)
 * 						Added special condition for ROOM4AB, bypassing the wall following
 * 						algorithm
 * 				Ver.5 > Hafidin (Fri, April 27th 2017)
 * 				Ver.6 > Hafidin (Tue, May 2nd 2017)
 * programmer's Note:
 */
void BW_FireFight(void)
{
//	int counter=0;
//	int PINPOINT_COUNTER;
	int cnt=0;
	int x,m;

	FlameSenseDigi_PID_Init();

	CANDLE_STICK=0;
	CANDLE_FIRE=0;

	FIRE_LED_BLINK_ON;

	BW_TurnAround=ACTIVE;
	UV_R2FLAG=UV_R2FLAG_INACTIVE;

	/*
	 * 	SPECIAL ROUTINE FOR THE ROOM4AB, BYPASSING THE WALL FOLLOWING ROUTINES
	 */
	if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW FIREFIGHT");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"ROOM4AB MODE");lcd_putstr(lcd);
		delay_ms(100);

//		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

//		RESET THE ROOM4AB FLAG
		ROOM4AB_FLAG=ROOM4AB_INACTIVE;
	}

	/*
	 * 		DEFAULT ROUTINE, AVOIDING THE FURNITURE IN THE MIDDLE OF THE ROOMS
	 */
	else
	{
		if(FIRESCAN_DIRECTION==SCAN_RIGHT)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			delay_ms(100);

//			while((FlameSenseDigi[0]==0) && ((FlameSenseDigi[0]!=7) || (FlameSenseDigi[0]!=6)) )
//			while( (FlameSenseDigi[0]==0) && (FlameSenseDigi[0]!=7) )
			if(FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE)
			{
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				//BW_PID_Init();
				BW_PID_Init_Furniture();
//				BW_PID_Init_Room();

				while(FlameSenseDigi[0]!=4)
				{
	//				mov_rot_right(FAST_LEVEL_2,FAR);
	//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"CNT FOLLOW = %d",cnt);lcd_putstr(lcd);

//					Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//					delay_ms(100);
					TCSlave_Check();

					BW_FollowCounter_Left(1);

//					if(Ping[PING_FRONT]<=16)
//					{
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//					}
							if(cnt>10)
							{
								TCSlave_Check();
								if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;
							}

					cnt++;
					if(cnt>40)break;

	//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5))break;
//					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3))break;
					if(FlameFrontDigi[0]==4)break;
				}
			}
//			else if(SP_FIRE_1B==SP_FIRE_ACTIVE)
//				{
//					FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
//					TRACER_STAT=TRACER_BLACK;
//
//					BW_PID_Init();
//					//BW_PID_Init_Room();
//
//					while(FlameSenseDigi[0]!=4)
//					{
//		//				mov_rot_right(FAST_LEVEL_2,FAR);
//		//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
//						lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
//
//	//					Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//		//				delay_ms(100);
//
//						BW_FollowCounter_Left(1);
//
//						TCSlave_Check();
//						if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;
//
//		//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
//						if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==2))break;
//	//					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3))break;
//						if(FlameFrontDigi[0]==4)break;
//					}
//				}
			else if(SP_FIRE_R3==SP_FIRE_ACTIVE)
				{
					FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
					TRACER_STAT=TRACER_BLACK;

//					BW_PID_Init();
					BW_PID_Init_Furniture();

					while(FlameSenseDigi[0]!=4)
					{
		//				mov_rot_right(FAST_LEVEL_2,FAR);
		//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);

						BW_FollowCounter_Left(1);

						TCSlave_Check();
						if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;

		//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
						if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==2))break;
	//					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3))break;
						if(FlameFrontDigi[0]==4)break;
					}
				}
			else if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
			{
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

		//						BW_PID_Init();
				BW_PID_Init_Furniture();

				while(FlameSenseDigi[0]!=4)
				{
				//				mov_rot_right(FAST_LEVEL_2,FAR);
				//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);

					BW_FollowCounter_Left(1);

					TCSlave_Check();
					if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;

				//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
								if(FlameSenseDigi[0]!=0)break;
			//					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3))break;
								if(FlameFrontDigi[0]==4)break;
							}
						}
			else if(FIREROOM_R1A_FLAG==ROOM1A_SP_MIDDLE_FLAG)
			{
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

//					BW_PID_Init();
				BW_PID_Init_Furniture();

				while(FlameSenseDigi[0]!=4)
				{
					//				mov_rot_right(FAST_LEVEL_2,FAR);
					//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);

					BW_FollowCounter_Left(1);

					TCSlave_Check();
					if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;

					//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;
				}

			}
			else if(ROOM[2]==ROOM_2A)
			{
				//BW_PID_Init();
				BW_PID_Init_Furniture();
				TRACER_STAT=TRACER_BLACK;

				while(FlameSenseDigi[0]!=4)
				{
	//				mov_rot_right(FAST_LEVEL_2,FAR);
	//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"CNT FOLLOW = %d",cnt);lcd_putstr(lcd);
					lcd_gotoxy(0,3);sprintf(lcd,"ROOM 2A",FlameSenseDigi[0]);lcd_putstr(lcd);

//					delay_ms(100);

					BW_FollowCounter_Left(1);

							if(cnt>10)
							{
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
			//						break;
									TRACER_STAT=TRACER_BLACK;
								}
							}

//					cnt++;
//					if(cnt>28)break;

	//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5)|| (FlameSenseDigi[0]==2))break;
//					if((FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==3))break;
					if(FlameFrontDigi[0]==4)break;
				}

			}
			else
			{
				TRACER_STAT=TRACER_BLACK;

				//BW_PID_Init();
				BW_PID_Init_Furniture();

				while(FlameSenseDigi[0]!=4)
				{
	//				mov_rot_right(FAST_LEVEL_2,FAR);
	//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"CNT FOLLOW = %d",cnt);lcd_putstr(lcd);
	//				delay_ms(100);

					BW_FollowCounter_Left(1);

							if(cnt>5)
							{
								TCSlave_Check();
								if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;
							}

					cnt++;
					if(cnt>28)break;

	//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
//					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5))break;
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==2))break;
					if(FlameFrontDigi[0]==4)break;
				}
			}

			if(((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5)) && (Ping[PING_FRONT]>30))
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			FIRESCAN_DIRECTION=SCAN_RIGHT;
		}

		else if(FIRESCAN_DIRECTION==SCAN_LEFT)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
			delay_ms(100);

//			while((FlameSenseDigi[0]==0) && ((FlameSenseDigi[0]!=1) || (FlameSenseDigi[0]!=2)) )
//			while( (FlameSenseDigi[0]==0) && (FlameSenseDigi[0]!=1) )
			if(SP_FIRE_1C==SP_FIRE_ACTIVE)
			{
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				//BW_PID_Init();
				BW_PID_Init_Furniture();
				while(FlameSenseDigi[0]!=4)
				{
	//				mov_rot_right(FAST_LEVEL_2,FAR);
	//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"CNT FOLLOW = %d",cnt);lcd_putstr(lcd);

//					Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
	//				delay_ms(100);

					BW_FollowCounter_Right(1);

							if(cnt>5)
							{
								TCSlave_Check();
								if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;
							}

					cnt++;
					if(cnt>60)break;

					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) /*|| (FlameSenseDigi[0]==1)*/)break;
					if(FlameFrontDigi[0]==4)break;
				}
			}
			else if(SP_FIRE_R3==SP_FIRE_ACTIVE)
						{
							//BW_PID_Init();
							BW_PID_Init_Furniture();
							while(FlameSenseDigi[0]!=4)
							{
				//				mov_rot_left(FAST_LEVEL_2,FAR);
				//				Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
								if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) /*|| (FlameSenseDigi[0]==1)*/ || (FlameSenseDigi[0]==7))break;
								if(FlameFrontDigi[0]==4)break;

								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
								lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
								lcd_gotoxy(0,2);sprintf(lcd,"CNT FOLLOW = %d",cnt);lcd_putstr(lcd);
//				delay_ms(100);

								BW_FollowCounter_Right(1);

								cnt++;
								if(cnt>28)break;

//								if(cnt>5){if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5)|| (FlameSenseDigi[0]==3))break;}
								if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5))break;
								if(FlameFrontDigi[0]==4)break;
							}
							SP_FIRE_R3=SP_FIRE_INACTIVE;
						}

			else
			{
				TRACER_STAT=TRACER_BLACK;
				//BW_PID_Init();
				BW_PID_Init_Furniture();
				while(FlameSenseDigi[0]!=4)
				{
	//				mov_rot_left(FAST_LEVEL_2,FAR);
	//				Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5))break; ///*|| (FlameSenseDigi[0]==1)*/ || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"CNT FOLLOW = %d",cnt);lcd_putstr(lcd);

					//				delay_ms(100);

					BW_FollowCounter_Right(1);

					if(cnt>5)
					{
						TCSlave_Check();
						if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;
					}

					cnt++;
					if(cnt>28)break;

					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5))break;
					if(FlameFrontDigi[0]==4)break;
				}
			}


			if(((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5)) && (Ping[PING_FRONT]>30))
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			FIRESCAN_DIRECTION=SCAN_LEFT;
		}
		else if(FIRESCAN_DIRECTION==NO_WALL_PARAM)
		{
			while(FlameSenseDigi[0]==0)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"NO WALL PARAM");lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"CNT = %d",cnt);lcd_putstr(lcd);
//				delay_ms(100);
//				mov_rot_left(FAST_LEVEL_2,FAR);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				cnt++;
				if(cnt>30)
				{
					Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
				}

			}
		}
	}

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);


		//Lilin Pojok Jauh (Variable Door), Robot masuk dari pintu 1A
		if((FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE) && (FlameSenseDigi[0]==0) && (TRACER_BREAK==1))
		{
//			FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

			Dynamx_MovBwd(9,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FIRE");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"CANDLE 1A");lcd_putstr(lcd);
			delay_ms(50);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

			for(m=0;m<=6;m++)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
				delay_ms(50);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==1)  || (FlameSenseDigi[0]==7) || (FlameFrontDigi[0]==4))break;
			}

//			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}
		else if((SP_FIRE_1C==SP_FIRE_ACTIVE) && (FlameSenseDigi[0]==0) && (TRACER_BREAK==1))
		{
			SP_FIRE_1C=SP_FIRE_INACTIVE;

			Dynamx_MovBwd(9,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FIRE");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"CANDLE 1C");lcd_putstr(lcd);
			delay_ms(50);

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			//Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

			for(m=0;m<=6;m++)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
				delay_ms(50);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==1)  || (FlameSenseDigi[0]==7) || (FlameFrontDigi[0]==4))break;
			}

//			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}

		else if((SP_FIRE_1B==SP_FIRE_ACTIVE) && (FlameSenseDigi[0]==0) && (TRACER_BREAK==1))
		{
//			SP_FIRE_1B=SP_FIRE_INACTIVE;

			Dynamx_MovBwd(9,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
			Nav_TurnAround(TURN_RIGHT);
			for(m=0;m<=6;m++)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1B");lcd_putstr(lcd);
				delay_ms(50);
				BW_FollowCounter_Left(1);
				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==1)  || (FlameSenseDigi[0]==7) || (FlameFrontDigi[0]==4) || (FlameSenseDigi[0]==2) || (FlameFrontDigi[0]==6))break;
			}

		}
		else if((SP_FIRE_R3==SP_FIRE_ACTIVE) && (FlameSenseDigi[0]==0) && (TRACER_BREAK==1))
		{
			Dynamx_MovBwd(9,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
			Nav_TurnAround(TURN_RIGHT);
			if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3))
				{
					Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
				}
			else
			{
				if((Ping[PING_ASKEW_LEFT])<(Ping[PING_REAR_LEFT]))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_ASKEW_LEFT])<(Ping[PING_REAR_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					}
				}
				else {
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_ASKEW_LEFT])>(Ping[PING_REAR_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					}
				}
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				int i=0;
				while(Ping[PING_RIGHT]>10 && i<5)
				{
					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
					i++;
				}
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					FIRESCAN_DIRECTION=SCAN_LEFT;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE R3");lcd_putstr(lcd);
					delay_ms(50);
				}
			SP_FIRE_R3=SP_FIRE_INACTIVE;
		}

//		else if (FlameSenseDigi[0]==0)
//		{
//			Dynamx_MovBwd(18,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//
//			Nav_TurnAround(TURN_RIGHT);
//
//			BW_PID_Init();
//
//			while(FlameSenseDigi[0]!=4)
//			{
////				mov_rot_right(FAST_LEVEL_2,FAR);
////				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
//				lcd_gotoxy(0,2);sprintf(lcd,"WHITE DETECTED");lcd_putstr(lcd);
////				delay_ms(100);
////				BW_Buzz_New(2);
//
//				BW_FollowCounter_Left(1);
//
//				cnt++;
//				if(cnt>28)break;
//
////				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
////					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5))break;
//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3))break;
//				if(FlameFrontDigi[0]==4)break;
//			}
//		}

			FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

		FlameTracking_Ver3();

		//CHECKING WALL/FURNITURE
//		if((Ping[PING_FRONT]>30) || ((SHARP[SHARP_FRONT_R]>30) || (SHARP[SHARP_FRONT_L]>30)))
//		{
//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//			//RE-CHECKING
//			if((Ping[PING_FRONT]>30) || ((SHARP[SHARP_FRONT_R]>30) || (SHARP[SHARP_FRONT_L]>30)))
//			{
//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			}
//		}

		//FURNITURE CHECK
//		Furniture_Check();
//		if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
//		{
//			ROOM4AB_FLAG=ROOM4AB_INACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BW FIREFIGHT");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"TRACKING");lcd_putstr(lcd);
			delay_ms(100);

			if (ROOM[2]==ROOM_1A)
			{
				for(x=0;x<=3;x++)
				{
					FlameTracking_Center();
//					Bumper_Follow();

					while(SHARP[SHARP_FRONT_R]>30 && SHARP[SHARP_FRONT_L]>30)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

						Dynamx_MovFwd4cm_slow(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						Furniture_Avoider();
						Bumper_Follow();

						if(FlameFrontDigi[0]!=4)break;
					}

					FlameTracking_Center();

					Bumper_Follow();

					while(SHARP[SHARP_FRONT_R]>30 && SHARP[SHARP_FRONT_L]>30)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

						Dynamx_MovFwd4cm_slow(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						Furniture_Avoider();
						Bumper_Follow();

						if(FlameFrontDigi[0]!=4)break;
					}

					Bumper_Follow();
				}

			}
			else if((ROOM[2]==ROOM_1B) || (ROOM[2]==ROOM_1C) || (ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_3))
			{
				for(x=0;x<=3;x++)
				{
					FlameTracking_Center();
//					Bumper_Follow();

					while(SHARP[SHARP_FRONT_R]>25 && SHARP[SHARP_FRONT_L]>25)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

						Dynamx_MovFwd4cm_slow(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

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

						Dynamx_MovFwd4cm_slow(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						Furniture_Avoider();
						Bumper_Follow();

						if(FlameFrontDigi[0]!=4)break;
					}

					Bumper_Follow();
				}

			}
			else
			{
				for(x=0;x<=3;x++)
				{
					FlameTracking_Center();
//					Bumper_Follow();

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
			}

		if(((SHARP[SHARP_FRONT_R]<15)) || (SHARP[SHARP_FRONT_L]<15))
		{
			Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
		}

//		FlameTracking_Center();
//		Dynamx_Mov_Tracking(HEXSPD_MED);

		UV_R2FLAG=UV_R2FLAG_INACTIVE;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH 1.0");lcd_putstr(lcd);
//			delay_ms(100);
//			FlameTracking_Ver3();

			FlameTracking_Center();

			Dynamx_Mov_Static(HEXSPD_SLOW,IKCALC_DISABLE);
//			BW_HydroPump();
//			BW_HydroPump_2();
		}

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 2.0");lcd_putstr(lcd);
//			delay_ms(100);

			BW_HydroPump_2();
		}

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			Dynamx_Mov_Tracking(HEXSPD_SLOW);
			lcd_gotoxy(0,0);sprintf(lcd,"TRACKING AGAIN ");lcd_putstr(lcd);
			delay_ms(100);
			while(((SHARP[SHARP_FRONT_R]>30) && (SHARP[SHARP_FRONT_L]>30)) || (Ping[PING_FRONT]>40))
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FIRE MOVE FORWARD ");lcd_putstr(lcd);
				delay_ms(100);

				Furniture_Avoider();
				Bumper_Follow();

			//if(FlameFrontDigi[0]!=4)break;
			}
		}


		UVLock_Refresh();
		delay_ms(1000);
		UVLock_Refresh();


		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH 1.1");lcd_putstr(lcd);
//			delay_ms(100);
//			FlameTracking_Ver3();

//			BW_HydroPump();
			BW_HydroPump_2();
		}

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 2.1");lcd_putstr(lcd);
			delay_ms(100);

			BW_HydroPump_2();
		}

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			Dynamx_Mov_Tracking(HEXSPD_SLOW);
			lcd_gotoxy(0,0);sprintf(lcd,"TRACKING AGAIN ");lcd_putstr(lcd);
			delay_ms(100);

			while((SHARP[SHARP_FRONT_R]>30) /*&& (SHARP[SHARP_FRONT_L]>30))*/ || (Ping[PING_FRONT]>40))
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FIRE MOVE FORWARD ");lcd_putstr(lcd);
				delay_ms(100);

				Furniture_Avoider();
				Bumper_Follow();

			//if(FlameFrontDigi[0]!=4)break;
			}
		}
		UVLock_Refresh();
		while(UV_Lock==UVLOCK_ACTIVE)
		{

			BW_TurnAround=INACTIVE;

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
					delay_ms(100);
					FlameTracking_Center();
//					Dynamx_Mov_Tracking(HEXSPD_SLOW);
				}

/////////////////////////////////////////////////////////////////////////////////

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 3");lcd_putstr(lcd);
					delay_ms(100);
//					BW_BLDC_Fight();
//					BW_HydroPump();
					BW_HydroPump_2();
				}

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 4");lcd_putstr(lcd);
					delay_ms(100);
//					BW_BLDC_Extinguish();
					BW_HydroPump_2();
				}

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					Dynamx_Mov_Tracking(HEXSPD_SLOW);

					lcd_gotoxy(0,0);sprintf(lcd,"TRACKING AGAIN ");lcd_putstr(lcd);
					delay_ms(100);

					while((SHARP[SHARP_FRONT_R]>30) /*&& (SHARP[SHARP_FRONT_L]>30))*/ || (Ping[PING_FRONT]>40))
					{
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FIRE MOVE FORWARD ");lcd_putstr(lcd);
						delay_ms(100);


						Furniture_Avoider();
						Bumper_Follow();

					//if(FlameFrontDigi[0]!=4)break;
					}
				}
				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
//					mov_rot_right(FAST_LEVEL_3,CLOSE);
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
					delay_ms(100);
//					FlameTracking_Center();

					Dynamx_Mov_Tracking(HEXSPD_SLOW);

					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 5");lcd_putstr(lcd);
					delay_ms(100);
//					BW_BLDC_Fight();
					BW_HydroPump();

					UVLock_Refresh();
					if(UV_Lock==UVLOCK_ACTIVE)
					{
						BW_Buzz(1);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 6");lcd_putstr(lcd);
						delay_ms(100);
//						BW_BLDC_Extinguish();
						BW_HydroPump_2();
					}
				}
			}
			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;
		}

	EXTINGUISHER_OFF;
	EXTINGUISHED_FIRE=1;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
	delay_ms(200);
}

void UVLock_Refresh(void)
{
	Get_UV();
	if(UV_state==UVSTATE_INACTIVE)
	{
		UV_Lock=UVLOCK_INACTIVE;
	}
}

/* func      : void BW_Navi(int STARTING_POINT, int DESTINATION)
 * brief     : BW NAVIGATION ROUTINES
 * param     : int STARTING_POINT->Initial location | int DESTINATION -> BW's target location
 *     					STARTING POINT 					DESTINATION
 * 				HALLWAY_SC			(1A, 1B, 1C, 2A, 2B, 3, 4A, 4B					)
 * 				ROOM_1A				(HALLWAY_SC, 2A, 2B, 3, 4A, 4B				)
 * 				ROOM_1B				( 				N/A								)
 * 				ROOM_1C				(HALLWAY_SC, 2A, 2B, 3, 4A, 4B				)
 * 				ROOM_2A/2B			(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3, 4A, 4B	)
 * 				ROOM_3				(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3, 4A, 4B	)
 * 				ROOM_4A				(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3			)
 * 				ROOM_4B				(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3					)
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void BW_Navi(int STARTING_POINT, int DESTINATION)
{
	int DEPARTURE=99;

	DEPARTURE = STARTING_POINT;
	//STARTING POINT == HALLWAY SC
	if(DEPARTURE==HALLWAY_SC)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1A:
				{
					Nav_HallwaySC_To_1A(2);
				}break;

			case NAV_ROOM_1B:
				{
					Nav_HallwaySC_To_1B();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_HallwaySC_To_1B();
				}break;

			case NAV_ROOM_2A:
				{
					Nav_HallwaySC_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_HallwaySC_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_HallwaySC_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_HallwaySC_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_HallwaySC_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 1A
	else if (DEPARTURE==NAV_ROOM_1A)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_1A_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_1A_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_1A_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_1A_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_1A_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
//					Nav_1A_To_4A();
					Nav_1A_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 1B
	else if (DEPARTURE==NAV_ROOM_1B)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_1C_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_1B_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_1B_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_1C_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_1C_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_1C_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 1C
	else if (DEPARTURE==NAV_ROOM_1C)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_1C_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_1C_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_1C_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_1C_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_1C_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_1C_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 2A
	else if ( (DEPARTURE==NAV_ROOM_2A)  )
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_2_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					Nav_2_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					Nav_2A_To_1BC();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_2A_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_2B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_3:
				{
					Nav_2_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_2_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_2_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 2B
	else if ( (DEPARTURE==NAV_ROOM_2B) )
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_2_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					Nav_2_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					Nav_2B_To_1BC();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_2B_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_2B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_3:
				{
					Nav_2_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_2_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_2_To_4B();
				}break;
		}
	}


	//STARTING POINT == ROOM 3
	else if (DEPARTURE==NAV_ROOM_3)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_3_To_HallwaySC();
				}break;

			case NAV_ROOM_1A:
				{
					Nav_3_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					Nav_3_To_1BC();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_3_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					Nav_3_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_3_To_2();
				}break;

			case NAV_ROOM_3:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_4A:
				{
					Nav_3_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_3_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 4A
	else if (DEPARTURE==NAV_ROOM_4A)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_4A_To_HallwaySC();
				}break;

			case NAV_ROOM_1A:
				{
					Nav_4A_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_4A_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_4A_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_4A_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_4B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;
		}
	}

	//STARTING POINT == ROOM 4B
	else if (DEPARTURE==NAV_ROOM_4B)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_4B_To_HallwaySC();
				}break;
			case NAV_ROOM_1A:
				{
					Nav_4B_To_1A();
				}break;
			case NAV_ROOM_1C:
				{
					Nav_4B_To_1BC();
				}break;
			case NAV_ROOM_1B:
				{
					Nav_4B_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					Nav_4B_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_4B_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_4B_To_3();
				}break;
		}
	}

	//WRONG CASE
	else
	{
		while(1)
		{
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"NAVIGATION");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			mov_static();

			delay_ms(500);

			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"ERROR");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			mov_static();

			delay_ms(500);
		}
	}


}

/* func      : void Nav_HallwaySC_To_3(void)
 * brief     : Navigate from HallwaySC to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_BLACK,INVERSE);

//	mov_deflect_right(FAST,CLOSE);
//	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);

//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Right();


}

/* func      : void Nav_HallwaySC_To_2(void)
 * brief     : Navigate from HallwaySC to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_ASKEW_LEFT]<=70)
//	while(SHARP[SHARP_LEFT]<=70)
	{
		BW_PID_Init();
		follow_right_counter(1);
	}
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	while(Ping[PING_RIGHT]>=20)
	{
		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}
	BW_PID_Init();
	FollowTracer_Right();

}

/* func      : void Nav_HallwaySC_To_4B(void)
 * brief     : Navigate from HallwaySC to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_4B(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO 4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_PID_Init();
	FollowTracer_Left();
	mov_fwd_5cm(15,FAST_LEVEL_3);
	while(1)
	{
		BW_Buzz(2);
		mov_static();
	}
}

/* func      : void Nav_HallwaySC_To_4A(void)
 * brief     : Navigate from HallwaySC to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_4A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while ( (Ping[PING_FRONT]>=25) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		if(Ping[PING_FRONT]<=5) mov_bwd(5,FAST_LEVEL_3);
		Get_IR();
	}

	Get_IR();
	while ( Ping[PING_FRONT]<=25 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		if(Ping[PING_FRONT]<=5) mov_bwd(5,FAST_LEVEL_3);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);

		Get_IR();
	}

	BW_PID_Init();
	FollowTracer_Right();


}

/* func      : void Nav_HallwaySC_To_1B(void)
 * brief     : Navigate from HallwaySC to Room 1B
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_1B(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R1B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_ASKEW_LEFT]<=70)
//	while(SHARP[SHARP_LEFT])
	{
		follow_right_counter(1);
	}
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	while(Ping[PING_RIGHT]>=20)
	{
		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		mov_fwd_5cm(5,FAST_LEVEL_3);

		Get_IR();

		if(
			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
			(Ping[PING_FRONT]<=25)
		  )
		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

		}
	}

	BW_PID_Init();
	FollowTracer_Left();

}

/* func      : void Nav_HallwaySC_To_1A(void)
 * brief     : Navigate from HallwaySC to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_1A(int OPTION)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	switch(OPTION)
	{
		case 1:
				{

					BW_PID_Init();
					FollowTracer_Left();
					mov_fwd_5cm(15,FAST_LEVEL_3);

				}break;
		case 2:
				{
					FollowCarpet_Left(COLOUR_BLACK,INVERSE);

					BW_Buzz(5);
					BW_PID_Init();
					FollowTracer_Right();

				}break;
	}

}

/* func      : void Nav_3_To_HallwaySC(void)
 * brief     : Navigate from Room 3 to HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_3_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_FRONT]<=25)
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowHome_Left();

}

/* func      : void Nav_3_To_2(void)
 * brief     : Navigate from Room 3 to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: Ver2 : Hafidin (Thurs, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_3_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R2");lcd_putstr(lcd);
	delay_ms(100);
//	int m=0;

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	TRACER_STAT=TRACER_BLACK;

//	for(m=0;m<=3;m++)
//	{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//		if(Ping[PING_FRONT]<13)break;
//	}

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Right();
}

/* func      : void Nav_3_To_1A(void)
 * brief     : Navigate from Room 3 to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_3_To_1A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R1A");lcd_putstr(lcd);
//	delay_ms(100);

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if(Ping[PING_RIGHT]<15)
	{
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	}

	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init_Room();
	BW_FollowCounter_Left(18);

	if(Ping[PING_ASKEW_LEFT]<(Ping[PING_REAR_LEFT]-5))
	{
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	}
	while(Ping[PING_FRONT]>23)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
	}

	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	BW_Buzz(1);
	BW_PID_Init_FAR();
	BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

	if(CAT_FLAG==CAT_DETECTED)
	{
		CAT_FLAG_A=CAT_DETECTED;
		CAT_DETECTOR=CAT_DIACTIVATED;
		R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		//Activate special route
		R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
		R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

		Dynamx_MovBwd(8,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		while(Ping[PING_RIGHT]>25)
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		Dynamx_MovFwd4cm(20,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		if(Ping[PING_LEFT]>18)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			if(Ping[PING_LEFT]>18)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}
		}

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();
		FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

	}
	else
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		BW_Buzz(1);
		BW_PID_Init_Room();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init_Room();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		if(Ping[PING_ASKEW_LEFT]<(Ping[PING_REAR_LEFT]-5))
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}

		while(Ping[PING_FRONT]>23)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}

		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		if(CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			CAT_FLAG_B=CAT_DETECTED;

			Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

//			Nav_TurnAround(TURN_LEFT);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init_FAR();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			if((Ping[PING_ASKEW_LEFT]>30) || (Ping[PING_LEFT]>30))
			{

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();

			}
			else
			{
				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left();
			}
			ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();
			FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;
			CAT_FLAG_C=CAT_DETECTED;

		}
	}


}
/* func      : void Nav_3_To_1BC(void)
 * brief     : Navigate from Room 3 to Room 1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: Ver2 : Hafidin (Thurs, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_3_To_1BC(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

//	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

	if(Ping[PING_ASKEW_LEFT]>=30 || Ping[PING_LEFT]>=30)
	{
		SP_FIRE_1B=SP_FIRE_ACTIVE;
		//	recheck
//		if(SP_FIRE_1C==SP_FIRE_ACTIVE)
//		{
//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			if(Ping[PING_ASKEW_LEFT]>=30 || Ping[PING_LEFT]>=30)
//				{
//					SP_FIRE_1C==SP_FIRE_INACTIVE;
//				}
//			else
//				{
//					SP_FIRE_1B=SP_FIRE_INACTIVE;
//				}
//		}
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

	}
	else
	{
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		SP_FIRE_1C=SP_FIRE_ACTIVE;

	}

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left();

}

/* func      : void Nav_3_To_4A(void)
 * brief     : Navigate from Room 3 to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: Ver2 : Hafidin (Friday, Feb 24th 2017)
 * programmer's Note:
 */
void Nav_3_To_4A(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

	Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowCounter_Left(15);


//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;



	//DEFAULT ROUTE
	if (R2TO4A_SP_ROUTE==R2TO4A_SP_INACTIVE)
	{
		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//			BW_Buzz(1);
//			BW_PID_Init();
//			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			if(Ping[PING_ASKEW_RIGHT]<30)
			{
				Nav_TurnAround(TURN_RIGHT);

				BW_PID_Init();
				BW_FollowTracer_Left();
			}
			else
			{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				BW_PID_Init();
				BW_FollowTracer_Right();
			}
		}

		if(CAT_FLAG==CAT_DETECTED)
		{
			/*
			 * SPECIAL ROUTE FOR RETURN TRIP TO R3 TRIGGERED
			 */
			R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_MovBwd(12,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);



			Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
	//		BW_Buzz(1);
	//		BW_PID_Init();
	//		BW_FollowCounter_Right(8);

			CAT_FLAG=CAT_NOT_DETECTED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

//			BW_Buzz(1);
//			BW_PID_Init();
//			BW_FollowTracer_Left();

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,NORMAL);
//
			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,NORMAL);
//
//					BW_Buzz(1);
//					BW_PID_Init();
//					BW_FollowCounter_Left(3);
//
			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,NORMAL);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,NORMAL);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			if(Ping[PING_RIGHT]<=15)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}

			if((Ping[PING_LEFT]>=20) && (Ping[PING_ASKEW_LEFT]>=20))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
			else
			{
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();
		}
	}
	else if (R2TO4A_SP_ROUTE==R2TO4A_SP_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"SPECIAL");lcd_putstr(lcd);
		lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
		lcd_gotoxy(3,2);sprintf(lcd,"R3 TO R4B");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"CAT CONFIG A");lcd_putstr(lcd);
		delay_ms(100);

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Nav_TurnAround(TURN_RIGHT);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		if(Ping[PING_RIGHT]<=15)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		}

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);


		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Left();
	}

	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */
	ROOM4AB_FLAG=ROOM4AB_ACTIVE;

}

/* func      : void Nav_3_To_4B(void)
 * brief     : Navigate from Room 3 to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: Ver.2 - Ryan (Wednesday, May 19th 2016)
 * 			   Ver.3 - Hafidin (Friday, Feb 24th 2017)
 * programmer's Note:
 */
void Nav_3_To_4B(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowCounter_Left(15);

	Nav_TurnAround(TURN_RIGHT);

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left();

	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */
	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

/* func      : void Nav_2_To_HallwaySC(void)
 * brief     : Navigate from Room 2 to HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 13.
 * *.3.*
 * +--
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_2_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
		Evade_Wall();
	}

	BW_Buzz(2);
	BW_PID_Init();
	while( (Ping[PING_ASKEW_LEFT]<=80) || (Ping[PING_ASKEW_RIGHT]<=80))
//	while( (SHARP[SHARP_LEFT]<=80) || (SHARP[SHARP_RIGHT]<=80))
	{
		follow_left_counter(1);
	}

	BW_Buzz(2);
	while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
	{
		Get_IR();
		if(
			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
			(Ping[PING_FRONT]<=25)
		  )
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}

		Evade_Wall();
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(2);
	while( (Ping[PING_LEFT]>=30) || (Ping[PING_RIGHT]>=30) )
	{
		Get_IR();
		if(
			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
			(Ping[PING_FRONT]<=25)
		  )
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}

		Evade_Wall();
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowHome_Left();

}

/* func      : void Nav_2A_To_1BC(void)
 * brief     : Navigate from Room 2 to Room 1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_2A_To_1BC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2A TO R1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//
//	if(Ping[PING_RIGHT]>15)
//	{
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	}
//	if(Ping[PING_RIGHT]>15)
//	{
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	}
//	if(Ping[PING_RIGHT]>15)
//	{
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	}

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Right();
}

/* func      : void Nav_2B_To_1BC(void)
 * brief     : Navigate from Room 2 to Room 1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Wednesday, April 14th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_2B_To_1BC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2B TO ROOM 1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	TRACER_STAT=TRACER_BLACK;

//	if(Ping[PING_RIGHT]>15)
//	{
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	}
//	if(Ping[PING_RIGHT]>15)
//	{
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	}
//	if(Ping[PING_RIGHT]>15)
//	{
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	}

//	if(Ping[PING_FRONT]>15)
//	{
//		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	}
//	if(Ping[PING_FRONT]>15)
//	{
//		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	}
//	if(Ping[PING_FRONT]<15)
//	{
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//	}

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Right();
}


/* func      : void Nav_2_To_3(void)
 * brief     : Navigate from Room 2 to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_2_To_3(void)
{
//	int counter;
//	int p;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if(EXTINGUISHED_FIRE==1)
	{
		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
		}
		else
		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_RIGHT])<(Ping[PING_ASKEW_RIGHT]))
			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
		}
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
	}
	else
	{
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	}
	Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);


//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

//	for(p=0;p<=5;p++)
//	{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
////		if(Ping[PING_FRONT]<15)break;
//		Bumper_Action();
//	}
//
//	if(Ping[PING_FRONT]<15)
//	{
//		Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	}
//
//	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//
//	if(Ping[PING_LEFT]>20)
//	{
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//	}

//	BW_Buzz(1);
//	BW_PID_Init();
//	BW_FollowCounter_Left(3);

	BW_PID_Init();
	BW_FollowTracer_Left();
}

/* func      : void Nav_2_To_4A(void)
 * brief     : Navigate from Room 2 to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * 			   Ver3 : Toni (Thursday, Sept 14th 2017)
 * programmer's Note:
 */
void Nav_2_To_4A(void)
{
//	int counter;
	int g;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}
	else
	{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if((Ping[PING_REAR_RIGHT])<(Ping[PING_ASKEW_RIGHT]))
		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}

	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

	for(g=0;g<=5;g++)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		Bumper_Action();
		if(Ping[PING_ASKEW_LEFT]<20 || Ping[PING_ASKEW_RIGHT]<20)break;
	}
	Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

	if(EXTINGUISHED_FIRE==0)
	{
//		if(Ping[PING_RIGHT]<30)
//		{
////		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			if(Ping[PING_RIGHT]>20)
//			{
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				if(Ping[PING_RIGHT]>20)
//				{
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				}
//			}
//			BW_Buzz(1);
//			BW_PID_Init();
//			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);
//
//			BW_Buzz(1);
//			BW_PID_Init();
//			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);
//
//		}
//
//		else
//		{
		//	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			if(Ping[PING_LEFT]>20)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>20)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				}
			}

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

	//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

//		}


//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

		Dynamx_MovFwd4cm(8,HEXSPD_FAST,IKCALC_DISABLE);

		if(Ping[PING_RIGHT]<10)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		}
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		if((Ping[PING_ASKEW_LEFT]>30) || (Ping[PING_LEFT]>30))
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

//			Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
			for(g=0;g<=3;g++)
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				Bumper_Action();

				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				TCSlave_Check();
				if(TRACER_STAT==TRACER_WHITE)break;
				if((Ping[PING_ASKEW_LEFT]<15) || (Ping[PING_ASKEW_RIGHT]<15))break;
			}

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		}
		else
		{
//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				Nav_TurnAround(TURN_LEFT);
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				Cat_Avoider();
				CAT_FLAG=CAT_NOT_DETECTED;

//				BW_Buzz(1);
//				BW_PID_Init();
//				BW_FollowTracer_Right();

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowCounter_Right(9);

//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				if(Ping[PING_LEFT]>15)
//				{
//					Dynamx_Slide_Left(HEXSTEP_M  ED,HEXSPD_MEDFAST);
//					if(Ping[PING_LEFT]>15)
//					{
//						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					}
//				}
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

				BW_Buzz(1);
				//if (EXTINGUISHED_FIRE==1){BW_PID_Init();}
				BW_PID_Init_FAR();
				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

	//			if(CAT_FLAG==CAT_NOT_DETECTED)
	//			{
	//				BW_Buzz(1);
	//				BW_PID_Init();
	//				BW_FollowTracer_Right();
	//			}

				if(CAT_FLAG==CAT_DETECTED)
				{
					CAT_DETECTOR=CAT_DIACTIVATED;
					R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;

					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
					//Activate special route
					R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
					R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

					Dynamx_MovBwd(15,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

					while(Ping[PING_RIGHT]>25)
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					Dynamx_MovFwd4cm(16,HEXSPD_MEDFAST,IKCALC_DISABLE);

					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					if(Ping[PING_LEFT]>18)
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						if(Ping[PING_LEFT]>18)
						{
							Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

						}

					}
//					BW_Buzz(1);
//					BW_PID_Init();
//					BW_FollowCounter_Right(8);
//
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					if(Ping[PING_LEFT]>18)
//					{
//						while(Ping[PING_LEFT]>18)
//						{
//							Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//						}
//					}
					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Left();


/*			=================== ALGORITMA SAAT PING SERING INTERFERENSI =========
					//			Start of changes
										BW_Buzz(1);
										BW_PID_Init();
										BWFollowCarpet_Left(COLOUR_GRAY,NORMAL);
					//
										BW_Buzz(1);
										BW_PID_Init();
										BWFollowCarpet_Left(COLOUR_BLACK,NORMAL);
					//
//										Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
										if(Ping[PING_LEFT]>15)
										{
											Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
										}

					//					BW_Buzz(1);
					//					BW_PID_Init();
					//					BW_FollowCounter_Left(3);
					//
										BW_Buzz(1);
										BW_PID_Init();
										BWFollowCarpet_Left(COLOUR_GRAY,NORMAL);

										BW_Buzz(1);
										BW_PID_Init();
										BWFollowCarpet_Left(COLOUR_BLACK,NORMAL);

//										if(Ping[PING_LEFT]>15)
//										{
//											Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//										}

										Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

										BW_Buzz(1);
										BW_PID_Init();
										BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

										if(Ping[PING_RIGHT]<=15)
										{
											Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
								//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
								//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
										}

										if((Ping[PING_LEFT]>=20) && (Ping[PING_ASKEW_LEFT]>=20))
										{
											Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
										}
										else
										{
								//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
								//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

											Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
											Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
										}

										BW_Buzz(1);
										BW_PID_Init();
										BW_FollowTracer_Left();
*/
				}
				/*
				 * TRIGGER SPECIAL ROUTE FOR RETURN TRIP FROM R4A TO R1BC
				 */
				else
				{
					lcd_display_clear();
					lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
					lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"FLAG TRIGGERED");lcd_putstr(lcd);
					lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R1BC");lcd_putstr(lcd);
					R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

						Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
						Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//						Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);


						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						BW_Buzz(1);
						BW_PID_Init();
						BW_FollowTracer_Right();

				}
		}
	}
	else
	{
		//DEFAULT ROUTE
		if (R2TO4A_SP_ROUTE==R2TO4A_SP_INACTIVE)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			if(Ping[PING_FRONT]<15)
			{
				Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			Dynamx_MovBwd(12,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			Nav_TurnAround(TURN_RIGHT);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowCounter_Left(12);

			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			if(CAT_FLAG==CAT_NOT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right();
			}

			if (CAT_FLAG==CAT_DETECTED)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
				lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
				lcd_gotoxy(3,1);sprintf(lcd,"R2 TO R4B");lcd_putstr(lcd);
				delay_ms(100);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_MovBwd(12,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowCounter_Right(5);

				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left();
			}

		}
		else if (R2TO4A_SP_ROUTE==R2TO4A_SP_ACTIVE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SPECIAL");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			lcd_gotoxy(3,2);sprintf(lcd,"R2 TO R4B");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"CAT CONFIG A");lcd_putstr(lcd);
			delay_ms(100);

			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	//		BW_Buzz(1);

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			if(Ping[PING_RIGHT]<=15)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();
		}
	}

	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */
	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

/* func      : void Nav_2_To_4A_NEW(void)
 * brief     : Navigate from Room 2 to Room 4A Alternatif CAT A NOT CHECKED
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Toni (Friday, Nov 17th 2017)
 * Revised BY:
 * programmer's Note:
 */
void Nav_2_To_4A_NEW(void)
{
//	int counter;
//	int g;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R4A NEW");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//	if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//	{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		}
//	}
//	else
//	{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		if((Ping[PING_REAR_RIGHT])<(Ping[PING_ASKEW_RIGHT]))
//		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		}
//	}
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//
//	for(g=0;g<=5;g++)
//	{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//		Bumper_Action();
//		if(Ping[PING_ASKEW_LEFT]<20 || Ping[PING_ASKEW_RIGHT]<20)break;
//	}
//	Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

	if(EXTINGUISHED_FIRE==0)
	{
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			if(Ping[PING_LEFT]>20)
//			{
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				if(Ping[PING_LEFT]>20)
//				{
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				}
//			}

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd," BELOK KE 4B");lcd_putstr(lcd);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);


	//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

	//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

//		}


//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

//		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//		if(Ping[PING_RIGHT]<10)
//		{
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		}
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if((Ping[PING_ASKEW_LEFT]>30) || (Ping[PING_LEFT]>30))
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

//			Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			for(g=0;g<=3;g++)
//			{
//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				Bumper_Action();
//
//				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
//				TRACER_STAT=TRACER_BLACK;
//
//				TCSlave_Check();
//				if(TRACER_STAT==TRACER_WHITE)break;
//				if((Ping[PING_ASKEW_LEFT]<15) || (Ping[PING_ASKEW_RIGHT]<15))break;
//			}

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();

//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		}
		else
		{
			if(CAT_FLAG_C==CAT_DETECTED)
			{

				Nav_TurnAround(TURN_LEFT);

				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right();

			}
			else
			{
				Cat_Avoider();
				CAT_FLAG=CAT_NOT_DETECTED;
				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init_FAR();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init_FAR();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				if(CAT_FLAG==CAT_DETECTED)			// CAT C
				{
					CAT_DETECTOR=CAT_DIACTIVATED;
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
					CAT_FLAG_C=CAT_DETECTED;

					Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

					Nav_TurnAround(TURN_LEFT);

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right();

				}
				else //CAT C KOSONG
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

					BW_Buzz(1);
					BW_PID_Init_FAR();
					BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

					if(CAT_FLAG==CAT_DETECTED)			// CAT B
					{
						CAT_DETECTOR=CAT_DIACTIVATED;
						CAT_FLAG=CAT_NOT_DETECTED;
						CAT_FLAG_B=CAT_DETECTED;
						REVERSE_FLAG=REVERSEFLAG_ACTIVE;
						SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

						R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
						lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
						//delay_ms(100);

						Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

				//		Nav_TurnAround(TURN_LEFT);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						BW_Buzz(1);
						BW_PID_Init();
						BW_FollowTracer_Right();

					}
					else //CAT B kosong
					{
						CAT_DETECTOR=CAT_DIACTIVATED;
						R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;

						SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
						//Activate special route
						R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
						R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						BW_Buzz(1);
						BW_PID_Init();
						BW_FollowTracer_Left();

					}

				}

			}
		}
	}

}

/* func      : void Nav_2_To_4A_NEW_VER2(void)
 * brief     : Navigate from Room 2 to Room 4A Alternatif CAT A NOT CHECKED
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Toni (Monday, March 12th 2018)
 * Revised BY:
 * programmer's Note:
 */
void Nav_2_To_4A_NEW_VER2(void)
{
//	int counter;
//	int g;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R4A NEW");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//	if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//	{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		}
//	}
//	else
//	{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		if((Ping[PING_REAR_RIGHT])<(Ping[PING_ASKEW_RIGHT]))
//		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		}
//	}
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//
//	for(g=0;g<=5;g++)
//	{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//		Bumper_Action();
//		if(Ping[PING_ASKEW_LEFT]<20 || Ping[PING_ASKEW_RIGHT]<20)break;
//	}
//	Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

	if(EXTINGUISHED_FIRE==0)
	{
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			if(Ping[PING_LEFT]>20)
//			{
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				if(Ping[PING_LEFT]>20)
//				{
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				}
//			}

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd," BELOK KE 4B");lcd_putstr(lcd);


	//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

	//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd," FOLLOW CARPET");lcd_putstr(lcd);
			lcd_gotoxy(0,0);sprintf(lcd," HITAM 1");lcd_putstr(lcd);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);


//		}


//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

//		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//		if(Ping[PING_RIGHT]<10)
//		{
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		}
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if((Ping[PING_ASKEW_LEFT]>30) || (Ping[PING_LEFT]>30))
		{
			Cat_Avoider();
			CAT_FLAG=CAT_NOT_DETECTED;
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

//			BW_Buzz(1);
//			BW_PID_Init_FAR();
//			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd," FOLLOW CARPET");lcd_putstr(lcd);
			lcd_gotoxy(0,0);sprintf(lcd," ABU 1");lcd_putstr(lcd);

			BW_Buzz(1);
			BW_PID_Init_FAR();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			if(CAT_FLAG==CAT_DETECTED)			// CAT C
			{
				CAT_DETECTOR=CAT_DIACTIVATED;
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
				CAT_FLAG_C=CAT_DETECTED;

				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

				Nav_TurnAround(TURN_RIGHT);

//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left();

				FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

			}
			else //CAT C KOSONG
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//
//				if(CAT_FLAG_A==CAT_NOT_DETECTED && CAT_FLAG_B==CAT_NOT_DETECTED && CAT_FLAG_C==CAT_NOT_DETECTED)
//				{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
//				}

				BW_Buzz(1);
				BW_PID_Init_FAR();
				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

				if(CAT_FLAG==CAT_DETECTED)			// CAT B
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					CAT_DETECTOR=CAT_DIACTIVATED;
					CAT_FLAG=CAT_NOT_DETECTED;
					CAT_FLAG_B=CAT_DETECTED;
					REVERSE_FLAG=REVERSEFLAG_ACTIVE;

					R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
					lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
					//delay_ms(100);

					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

//					Nav_TurnAround(TURN_LEFT);
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right();

				}
				else //CAT B kosong
				{
//					CAT_FLAG_A=CAT_DETECTED;
//					CAT_DETECTOR=CAT_DIACTIVATED;
					R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;

					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
					//Activate special route
					R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
					R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

//					BW_Buzz(1);
//					BW_PID_Init_FAR();
//					BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);
//
//					if(CAT_FLAG==CAT_DETECTED)			// CAT A
//					{
					Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);

					CAT_DETECTOR=CAT_DIACTIVATED;
					CAT_FLAG=CAT_NOT_DETECTED;
					CAT_FLAG_B=CAT_DETECTED; // FOR RETURN TRIP

					R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"CAT A");lcd_putstr(lcd);
					lcd_gotoxy(8,1);sprintf(lcd,"FLAG ACTIVE");lcd_putstr(lcd);
					//delay_ms(100);

//					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

					Nav_TurnAround(TURN_LEFT);

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right();

//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//
//					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//					BW_Buzz(1);
//					BW_PID_Init();
//					BW_FollowTracer_Left();
				}
			}
		}
		else
		{
			if(CAT_FLAG_C==CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Nav_TurnAround(TURN_LEFT);

				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right();

			}
			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	//			BW_Buzz(1);
	//			BW_PID_Init();
	//			BW_FollowTracer_Right();

				Cat_Avoider();
				CAT_FLAG=CAT_NOT_DETECTED;
				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init_FAR();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init_FAR();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				if(CAT_FLAG==CAT_DETECTED)			// CAT C
				{
					CAT_DETECTOR=CAT_DIACTIVATED;
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
					CAT_FLAG_C=CAT_DETECTED;
					CAT_FLAG=CAT_NOT_DETECTED;

					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

					Nav_TurnAround(TURN_LEFT);

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Left();

					FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

				}
				else //CAT C KOSONG
				{
					CAT_FLAG=CAT_NOT_DETECTED;
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
	//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

	//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
	//
	//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

					BW_Buzz(1);
					BW_PID_Init_FAR();
					BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

					if(CAT_FLAG==CAT_DETECTED)			// CAT B
					{
						CAT_DETECTOR=CAT_DIACTIVATED;
						CAT_FLAG=CAT_NOT_DETECTED;
						CAT_FLAG_B=CAT_DETECTED;
						REVERSE_FLAG=REVERSEFLAG_ACTIVE;

						SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

						R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
						lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
						//delay_ms(100);

						Dynamx_MovBwd(2,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

	//					Nav_TurnAround(TURN_LEFT);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						BW_Buzz(1);
						BW_PID_Init();
						BW_FollowTracer_Right();

					}
					else //CAT B kosong
					{
						CAT_DETECTOR=CAT_DIACTIVATED;
						CAT_FLAG=CAT_NOT_DETECTED;
						R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;

						SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
						//Activate special route
						R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
						R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

//						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//
//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//
//						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						BW_Buzz(1);
						BW_PID_Init();
						BW_FollowTracer_Left();

						CAT_FLAG_A=CAT_DETECTED;

					}

				}

			}

		}
	}

}


/* func      : void Nav_2_To_4B(void)
 * brief     : Navigate from Room 2 to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: ver2 : Ryan (Friday, December 2nd 2016
 *		       Ver3 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_2_To_4B(void)
{
//	int counter;
	int g;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}
	else
	{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if((Ping[PING_REAR_RIGHT])<(Ping[PING_ASKEW_RIGHT]))
		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}
	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"1");lcd_putstr(lcd);
	delay_ms(100);


	for(g=0;g<=5;g++)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		Bumper_Action();
		if(Ping[PING_ASKEW_LEFT]<20)break;
	}
	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"2");lcd_putstr(lcd);
	delay_ms(100);

	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

//	if(Ping[PING_LEFT]>20)
//	{
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//	}

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"3");lcd_putstr(lcd);
	delay_ms(100);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSPD_MEDFAST,IKCALC_ENABLE);

	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

//	for(g=0;g<=3;g++)
//	{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//		Bumper_Action();
//
//		FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
//		TRACER_STAT=TRACER_BLACK;
//
//		TCSlave_Check();
//		if(TRACER_STAT==TRACER_WHITE)break;
//		if((Ping[PING_ASKEW_LEFT]<15) || (Ping[PING_ASKEW_RIGHT]<15))break;
//	}

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left();

	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */
	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

/* func      : void Nav_2_To_1A(void)
 * brief     : Navigate from Room 2 to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: Ver.2 : Ryan (Tuesday, April 5th 2016)
 * programmer's Note:
 */
void Nav_2_To_1A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	BW_Buzz(2);
//	BW_PID_Init();
//	follow_right_counter(7);
//
//	BW_Buzz(2);
//	BW_PID_Init();
//	FollowTracer_Left();
	while(1)
	{
		Dynamx_Mov_Static(HEXSPD_ULTRAFAST,IKCALC_ENABLE);
	}
}

/* func      : void Nav_1A_To_4A(void)
 * brief     : Navigate from Room 1A to Room HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1A_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);
	}

	//CAT DETECTED IN CONFIG B (RIGHT SIDE OF ROOM 4
	if(CAT_FLAG==CAT_DETECTED)
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTED");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"CONFIG B");lcd_putstr(lcd);
		delay_ms(100);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"GRAY");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FORWARD TO");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"CROSSROAD");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
		{
			Get_IR();
			if(
				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
				(Ping[PING_FRONT]<=25)
			  )
			{
				mov_rot_right(FAST_LEVEL_3,CLOSE);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}

			Evade_Wall();
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOW RIGHT");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"10 STEP");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		follow_right_counter(10);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"DEFLECT LEFT");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"3 TIMES");lcd_putstr(lcd);
		delay_ms(100);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWHOME");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"LEFT RULE");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		FollowHome_Left();
	}

	//CAT NOT DETECTED IN CONFIG B
	else
	{
		BW_Buzz(2);
		BW_PID_Init();
		FollowHome_Right();

		//CAT DETECTED IN CONFIG A
		if(CAT_FLAG==CAT_DETECTED)
		{
			lcd_display_clear();
			lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTED");lcd_putstr(lcd);
			lcd_gotoxy(3,1);sprintf(lcd,"CONFIG A");lcd_putstr(lcd);
			delay_ms(100);

			BW_Buzz(2);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(2);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(2);
			while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
			{
				Get_IR();
				if(
					(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
					(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
					(Ping[PING_FRONT]<=25)
				  )
				{
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
				}

				Evade_Wall();
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

			BW_Buzz(2);
			BW_PID_Init();
			follow_right_counter(10);

			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);

			BW_Buzz(2);
			BW_PID_Init();
			FollowHome_Left();
		}

		//CAT OBSTACLE NOT DETECTED
		else
		{
			BW_Buzz(2);
			BW_PID_Init();
			FollowHome_Right();
		}

	}



}


///* func      : void Nav_1A_To_2(void)
// * brief     : Navigate from Room 1A to Room 2
// * param     : N/A
// * retval    : N/A
// * Ver       : 6
// * written By: Ryan (Thursday, March 28th 2016)
// * Revised BY: Ver.2 : Ryan (Tuesday, April 5th 2016)
// * 			   Ver.3 : Hafidin (Wed, Feb 22th 2017)
// * 			   Ver.4 : Ryan (Thursday, April 20th 2017)
// * 			   Ver.5 : Ryan (Sunday, April 23rd 2017)
// * 			   Ver.6 : Hafidin (Tue, May 2nd, 2017)
// * programmer's Note:
// */
//void Nav_1A_To_2(void)
//{
//	BW_Buzz(1);
//	lcd_display_clear();
//	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
//	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R2");lcd_putstr(lcd);
//	delay_ms(100);
//
//	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
//	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
//	CAT_FLAG=CAT_NOT_DETECTED;
//
//
//
////	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
////	Ryan (Thursday, April 20th, 2017)
////	Start of changes
////	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////
////	if(Ping[PING_RIGHT]<=113)
////	{
////		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////
////		if(Ping[PING_ASKEW_RIGHT]<=113)
////		{
////			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////		}
////	}
////	End of changes
//
//	if(ROOM1A_SP_EXIT_FLAG==ROOM1A_SP_EXIT_FLAG_ACTIVE)
//	{
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//		while((Ping[PING_LEFT]>=30) || (Ping[PING_ASKEW_LEFT]>=30))
//		{
//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST, IKCALC_DISABLE);
//
//		}
//		if((Ping[PING_LEFT]>=25) || (Ping[PING_ASKEW_LEFT]>=25))
//		{
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		}
//		if((Ping[PING_LEFT]>=25) || (Ping[PING_ASKEW_LEFT]>=25))
//				{
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				}
//
//		BW_Buzz(1);
//		lcd_display_clear();
//		lcd_gotoxy(2,0);sprintf(lcd,"ABU 1");lcd_putstr(lcd);
//		BW_PID_Init();
//		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);
//
//		//		BW_Buzz(1);
//		//		lcd_display_clear();
//		//		lcd_gotoxy(0,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
//		//		lcd_gotoxy(0,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
//		//		delay_ms(1000);
//
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"HITAM 1");lcd_putstr(lcd);
//				BW_PID_Init();
//				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
//		//		BW_Buzz(1);
//		//		lcd_display_clear();
//		//		lcd_gotoxy(0,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
//		//		lcd_gotoxy(0,1);sprintf(lcd,"GRAY");lcd_putstr(lcd);
//		//		delay_ms(1000);
//
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"ABU 2");lcd_putstr(lcd);
//				BW_PID_Init();
//				BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);
//
//		//		BW_Buzz(1);
//		//		lcd_display_clear();
//		//		lcd_gotoxy(0,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
//		//		lcd_gotoxy(0,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
//		//		delay_ms(1000);
//
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"HITAM 2");lcd_putstr(lcd);
//				BW_PID_Init();
//				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
//
//		//		BW_Buzz(1);
//		//		lcd_display_clear();
//		//		lcd_gotoxy(0,0);sprintf(lcd,"FOLLOWTRACER");lcd_putstr(lcd);
//		//		lcd_gotoxy(0,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
//		//		delay_ms(1000);
//
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//
//				BW_Buzz(1);
//				BW_PID_Init();
//				BW_FollowTracer_Right();
//
//	}
//	else if (ROOM1A_SP_EXIT_FLAG==ROOM1A_SP_EXIT_FLAG_INACTIVE)
//	{
//		BW_Buzz(1);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//		while(((Ping[PING_LEFT]>=25) || (Ping[PING_ASKEW_LEFT]>=25)) && (CAT_FLAG==CAT_NOT_DETECTED))
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,2);sprintf(lcd,"CAT DETECTION");lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"INITIATED");lcd_putstr(lcd);
//		Cat_Avoider();
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST, IKCALC_DISABLE);
//
//		Bumper_Action();
//		if(CAT_FLAG==CAT_DETECTED)break;
//		if(TCS3200_SLV_DATA[1]==COLOUR_GRAY){lcd_display_clear();lcd_gotoxy(0,0);sprintf(lcd,"TRACER BREAK");lcd_putstr(lcd);break;}
//	}
//
//	if(CAT_FLAG==CAT_NOT_DETECTED)
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,2);sprintf(lcd,"CAT DETECTION");lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"STOPPED");lcd_putstr(lcd);
//
//		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST, IKCALC_DISABLE);
//
////		BW_Buzz(1);
////		lcd_display_clear();
////		lcd_gotoxy(0,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
////		lcd_gotoxy(0,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
////		delay_ms(1000);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
////		BW_Buzz(1);
////		lcd_display_clear();
////		lcd_gotoxy(0,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
////		lcd_gotoxy(0,1);sprintf(lcd,"GRAY");lcd_putstr(lcd);
////		delay_ms(1000);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);
//
////		BW_Buzz(1);
////		lcd_display_clear();
////		lcd_gotoxy(0,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
////		lcd_gotoxy(0,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
////		delay_ms(1000);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
//
////		BW_Buzz(1);
////		lcd_display_clear();
////		lcd_gotoxy(0,0);sprintf(lcd,"FOLLOWTRACER");lcd_putstr(lcd);
////		lcd_gotoxy(0,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
////		delay_ms(1000);
//
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BW_FollowTracer_Right();
//	}
//
//	if (CAT_FLAG==CAT_DETECTED)
//	{
//		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//
//		Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//
///*		< OLD >
//		Dynamx_MovBwd(15,HEXSPD_MEDFAST,IKCALC_DISABLE);
//*/
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);
//
//		Nav_TurnAround(TURN_LEFT);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BW_FollowTracer_Right();
//	}
//	}
//
//}

/* func      : void Nav_1A_To_2(void)
 * brief     : Navigate from Room 1A to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 6
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: Ver.2 : Ryan (Tuesday, April 5th 2016)
 * 			   Ver.3 : Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.4 : Ryan (Thursday, April 20th 2017)
 * 			   Ver.5 : Ryan (Sunday, April 23rd 2017)
 * 			   Ver.6 : Hafidin (Tue, May 2nd, 2017)
 * 			   Ver.7 : Toni (Wednesday, November 22th, 2017)
 * programmer's Note:
 */
void Nav_1A_To_2(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R2");lcd_putstr(lcd);
	delay_ms(100);

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	Cat_Avoider();
	CAT_FLAG=CAT_NOT_DETECTED;

	if(Ping[PING_RIGHT]>=10)
	{
		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
	}

	if(CAT_FLAG_A==CAT_DETECTED || CAT_FLAG_B==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();

	}
	else
	{
	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

	if(CAT_FLAG_C==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	}
	else
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	}

	BW_Buzz(1);
	BW_PID_Init_FAR();
	BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		if(CAT_FLAG_C==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		}
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);
		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			Dynamx_MovBwd(2,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right();
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			Dynamx_MovBwd(8,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			if(Ping[PING_RIGHT]<20)
			{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_RIGHT]<20)
						{Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
						}
			}
			while(Ping[PING_RIGHT]<20)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowCounter_Left(10);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right();
		}

	}
	else
	{
		CAT_DETECTOR=CAT_DIACTIVATED;
		CAT_FLAG=CAT_NOT_DETECTED;
		REVERSE_FLAG=REVERSEFLAG_ACTIVE;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
		lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
		delay_ms(100);

		Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

		Nav_TurnAround(TURN_LEFT);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();
	}
}
}

/* func      : void Nav_1A_To_3(void)
 * brief     : Navigate from Room 1A to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: Ver.2 : Hafidin (Wed, Feb 23th 2017)
 * 			   Ver.3 : Hafidin (Tue, May 2nd, 2017)
 * 			   Ver.3 : Toni (Wednesday, November 22th, 2017)
 * programmer's Note:
 */
void Nav_1A_To_3(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R3");lcd_putstr(lcd);
	delay_ms(100);

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	Cat_Avoider();
//	CAT_FLAG=CAT_NOT_DETECTED;

	if(CAT_FLAG_A==CAT_DETECTED || CAT_FLAG_B==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
		Nav_TurnAround(TURN_RIGHT);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Left();

	}
	else
	{

		if(Ping[PING_RIGHT]>=10)
		{
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
		}
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		if(CAT_FLAG_C==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		}

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			if(CAT_FLAG_C==CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			}
			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
			}

			BW_Buzz(1);
			BW_PID_Init_FAR();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			if(CAT_FLAG==CAT_NOT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right();
			}
			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

				while(Ping[PING_RIGHT]<20)
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowCounter_Left(12);

				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				Nav_TurnAround(TURN_RIGHT);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left();
			}
		}
		else
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			CAT_FLAG=CAT_NOT_DETECTED;
			REVERSE_FLAG=REVERSEFLAG_ACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_MovBwd(2,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			//					Nav_TurnAround(TURN_LEFT);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			Nav_TurnAround(TURN_RIGHT);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();

		}
	}
}

///* func      : void Nav_1A_To_3(void)
// * brief     : Navigate from Room 1A to Room 3
// * param     : N/A
// * retval    : N/A
// * Ver       : 3
// * written By: Ryan (Thursday, March 28th 2016)
// * Revised BY: Ver.2 : Hafidin (Wed, Feb 23th 2017)
// * 			   Ver.3 : Hafidin (Tue, May 2nd, 2017)
// * programmer's Note:
// */
//void Nav_1A_To_3(void)
//{
//	BW_Buzz(1);
//	lcd_display_clear();
//	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
//	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R3");lcd_putstr(lcd);
//	delay_ms(100);
//
//	int CNT;
//	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
//	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
//
//	BW_Buzz(1);
//	//Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//	//	Start of changes
////		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//
////		if(Ping[PING_RIGHT]<=113)
////		{
////			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////
//
//	//			if(Ping[PING_ASKEW_RIGHT]<=113)
////			{
////				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////			}
////		}
//	//	End of changes
//
//		while(((Ping[PING_LEFT]>=25) || (Ping[PING_ASKEW_LEFT]>=25)) && (CAT_FLAG==CAT_NOT_DETECTED))
//		{
//			lcd_display_clear();
//			lcd_gotoxy(0,2);sprintf(lcd,"CAT DETECTION");lcd_putstr(lcd);
//			lcd_gotoxy(0,3);sprintf(lcd,"INITIATED");lcd_putstr(lcd);
//			Cat_Avoider();
//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST, IKCALC_DISABLE);
//			Bumper_Action();
////			CNT++;
////			if(CNT>7){lcd_display_clear();lcd_gotoxy(0,0);sprintf(lcd,"COUNT BREAK");lcd_putstr(lcd);break;
//			if(CAT_FLAG==CAT_DETECTED)break;
//			if(TCS3200_SLV_DATA[1]==COLOUR_GRAY){lcd_display_clear();lcd_gotoxy(0,0);sprintf(lcd,"TRACER BREAK");lcd_putstr(lcd);break;}
//		}
//
//	if(CAT_FLAG==CAT_NOT_DETECTED)
//	{
//		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//
//		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
//		Nav_TurnAround(TURN_RIGHT);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BW_FollowTracer_Left();
//	}
//
//	if(CAT_FLAG==CAT_DETECTED)
//	{
//		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//
//		Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//	/*  OLD VERSION
//		Dynamx_MovBwd(15,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	*/
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BW_FollowTracer_Right();
//	}
//}

/* func      : void Nav_1A_To_4B(void)
 * brief     : Navigate from Room 1A to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: Ver.2 : Ryan (Tuesday, April 5th 2016)
 * 			   Ver.3 : Hafidin (Wed, Feb 23th 2017)
 * 			   Ver.4 : Hafidin (Tue, May 2nd, 2017)
 * programmer's Note:
 */
void Nav_1A_To_4B(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	if((CAT_FLAG_A==CAT_DETECTED) || (CAT_FLAG_B==CAT_DETECTED))
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();
	}
	else if(CAT_FLAG_C==CAT_DETECTED)
	{
		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	//	Evade_Wall();
	//	Cat_Avoider();
		CAT_FLAG=CAT_NOT_DETECTED;

		if(Ping[PING_RIGHT]>=10)
		{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
		}
		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Left();
	}
	else
	{
		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

	//	Evade_Wall();
	//	Cat_Avoider();
		CAT_FLAG=CAT_NOT_DETECTED;

		if(Ping[PING_RIGHT]>=10)
		{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
		//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
		//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
		}
		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		if(CAT_FLAG_C==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		}

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			BW_Buzz(1);
			BW_PID_Init_FAR();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			if(Ping[PING_ASKEW_LEFT]>=30 || Ping[PING_LEFT]>=30)
			{
				ROOM4A_FLAG = ROOM4AFLAG_ACTIVE;
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left();

			}
			else
			{
				ROOM4B_FLAG = ROOM4BFLAG_ACTIVE;
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				if(CAT_FLAG_C==CAT_DETECTED)
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
				}
				else
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
				}

				if(Ping[PING_ASKEW_RIGHT]>Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
				else
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}

				BW_Buzz(1);
				BW_PID_Init_FAR();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				if(CAT_FLAG==CAT_DETECTED)
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					CAT_DETECTOR=CAT_DIACTIVATED;
					CAT_FLAG=CAT_NOT_DETECTED;
					REVERSE_FLAG=REVERSEFLAG_ACTIVE;

					R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
					lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
					delay_ms(100);

					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

					Nav_TurnAround(TURN_LEFT);

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

					//Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right();
				}

				else
				{
					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Left();
				}

			}

		}

		else if(CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			CAT_FLAG=CAT_NOT_DETECTED;
			REVERSE_FLAG=REVERSEFLAG_ACTIVE;

			R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			delay_ms(100);

	//		Evade_Wall();

			Dynamx_MovBwd(2,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

	//					Nav_TurnAround(TURN_LEFT);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			if((Ping[PING_ASKEW_RIGHT]>30)||(Ping[PING_ASKEW_RIGHT]>30))
			{
				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right();
			}
			else
			{
				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				if(Ping[PING_ASKEW_RIGHT]<15)
				{
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right();
			}
		}
	}


// ================ OLD ALGORITM =========================///
//	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
//	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
//
//	BW_Buzz(1);
//	//Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//	//	Start of changes
////		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//
////		if(Ping[PING_RIGHT]<=113)
////		{
////			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////
////			if(Ping[PING_ASKEW_RIGHT]<=113)
////			{
////				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////			}
////		}
//	//	End of changes
//
//		while(((Ping[PING_LEFT]>=25) || (Ping[PING_ASKEW_LEFT]>=25)) && (CAT_FLAG==CAT_NOT_DETECTED))
//		{
//			lcd_display_clear();
//			lcd_gotoxy(0,2);sprintf(lcd,"CAT DETECTION");lcd_putstr(lcd);
//			lcd_gotoxy(0,3);sprintf(lcd,"INITIATED");lcd_putstr(lcd);
//			Cat_Avoider();
//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST, IKCALC_DISABLE);
//			Bumper_Action();
//			if(CAT_FLAG==CAT_DETECTED)break;
//			if(TCS3200_SLV_DATA[1]==COLOUR_GRAY){lcd_display_clear();lcd_gotoxy(0,0);sprintf(lcd,"TRACER BREAK");lcd_putstr(lcd);break;}
//		}
//
//	if(CAT_FLAG==CAT_NOT_DETECTED)
//	{
//		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BW_FollowTracer_Right();
//	}
//
//	if(CAT_FLAG==CAT_DETECTED)
//	{
//		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//
//		Dynamx_MovBwd(9,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);
//
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BW_FollowTracer_Left();
//	}
//
	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */

	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

/* func      : void Nav_1A_To_4A(void)
 * brief     : Navigate from Room 1A to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: Ver.2 : Hafidin (Wed, Feb 23th 2017)
 * 			   Ver.3 : Ryan (Saturday, April 22nd 2017)
 * 			   			Added special route flag to R1BC when cat has been determined in config B/C
 *			   Ver.4 : Ryan (Sunday, April 23rd 2017)
 * 			   			Changes the wall following directions when CAT is not in config B
 * programmer's Note:
 */
void Nav_1A_To_4A(void)
{
//	int counter=0;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	if(CAT_FLAG_B == CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();
	}
	else
	{
	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

//	Evade_Wall();
//	Cat_Avoider();
	CAT_FLAG=CAT_NOT_DETECTED;

//	if(Ping[PING_RIGHT]>=16)
//	{
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
////		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	}

	if(Ping[PING_RIGHT]>=10)
	{
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
	//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
	//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
	}
	BW_Buzz(1);
	BW_PID_Init_FAR();
	BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

	if(CAT_FLAG_C==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	}
	else
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	}

	BW_Buzz(1);
	BW_PID_Init_FAR();
	BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		if(Ping[PING_ASKEW_LEFT]>=30 || Ping[PING_LEFT]>=30)
		{
			ROOM4A_FLAG = ROOM4AFLAG_ACTIVE;
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();

		}
		else
		{
			ROOM4B_FLAG = ROOM4BFLAG_ACTIVE;
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			if(CAT_FLAG_C==CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			}
			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
			}

			if(Ping[PING_ASKEW_RIGHT]>Ping[PING_REAR_RIGHT])
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
			else
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}

			BW_Buzz(1);
			BW_PID_Init_FAR();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			if(CAT_FLAG==CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				CAT_DETECTOR=CAT_DIACTIVATED;
				CAT_FLAG=CAT_NOT_DETECTED;
				REVERSE_FLAG=REVERSEFLAG_ACTIVE;

				R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
				lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
				delay_ms(100);

				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

				Nav_TurnAround(TURN_LEFT);

				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				//Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right();
			}

			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left();
			}

		}

	}

	else if(CAT_FLAG==CAT_DETECTED)
	{
		CAT_DETECTOR=CAT_DIACTIVATED;
		CAT_FLAG=CAT_NOT_DETECTED;
		REVERSE_FLAG=REVERSEFLAG_ACTIVE;

		R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
		lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
		delay_ms(100);

//		Evade_Wall();

		Dynamx_MovBwd(2,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

//					Nav_TurnAround(TURN_LEFT);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		if((Ping[PING_ASKEW_RIGHT]>30)||(Ping[PING_ASKEW_RIGHT]>30))
		{
			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right();
		}
		else
		{
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		if(Ping[PING_ASKEW_RIGHT]<15)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();
		}
	}
	}
	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */
	ROOM4AB_FLAG=ROOM4AB_ACTIVE;

}


/* func      : void Nav_1C_To_HallwaySC(void)
 * brief     : Navigate from Room 1C to HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, April 10th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1C_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);

	BW_Buzz(2);
	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(2);
	BW_PID_Init();
	while( (Ping[PING_ASKEW_LEFT]<=100) || (Ping[PING_ASKEW_RIGHT]<=100))
//	while( (SHARP[SHARP_LEFT]<=100) || (SHARP[SHARP_RIGHT]<=100))
//	while (SHARP[SHARP_LEFT]<=100)
	{
		follow_left_counter(1);
	}

	//CROSSING CROSSROAD
	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowHome_Left();
}



/* func      : void Nav_1C_To_2(void)
 * brief     : Navigate from Room 1C to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_1C_To_2(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	GetCMPS11_Angle8Bit();
//	if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			GetCMPS11_Angle8Bit();
//			if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				GetCMPS11_Angle8Bit();
//				if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					GetCMPS11_Angle8Bit();
//					if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					}
//
//				}
//			}
//		}
//	else if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE)
//		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			GetCMPS11_Angle8Bit();
//			if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE)
//			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				GetCMPS11_Angle8Bit();
//				if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE)
//				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					GetCMPS11_Angle8Bit();
//				}
//			}
//		}

	if(Ping[PING_LEFT]>15)
	{
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	}
	if(Ping[PING_LEFT]>15)
	{
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	}

	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left();
}

/* func      : void Nav_1B_To_2(void)
 * brief     : Navigate from Room 1B to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Wed, Feb 23th 2017)
 * Revised BY: N/A
 * programmer's Note:
 */

void Nav_1B_To_2(void)
{
//	int f;
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1B TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	GetCMPS11_Angle8Bit();
//	if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			GetCMPS11_Angle8Bit();
//			if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				GetCMPS11_Angle8Bit();
//				if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					GetCMPS11_Angle8Bit();
//					if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					}
//
//				}
//			}
//		}
//	else if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE)
//		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			GetCMPS11_Angle8Bit();
//			if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE)
//			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				GetCMPS11_Angle8Bit();
//				if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE)
//				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					GetCMPS11_Angle8Bit();
//				}
//			}
//		}


	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);


//	for(f=0;f<=5;f++)
//	{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//		Bumper_Action();
//		if((Ping[PING_ASKEW_LEFT]<17) || (Ping[PING_FRONT]<17))break;
//	}

//	while(Ping[PING_FRONT]<20)
//	{
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	}
//	Nav_TurnAround(TURN_LEFT);

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left();
//	BW_FollowTracer_Right();
}

/* func      : void Nav_1C_To_3(void)
 * brief     : Navigate from Room 1C to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_1C_To_3(void)
{
	int p;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	if(Ping[PING_FRONT]<40)
//	{
//	GetCMPS11_Angle8Bit();
//	if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			GetCMPS11_Angle8Bit();
//			if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				GetCMPS11_Angle8Bit();
//				if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				}
//			}
//		}
//
//	else if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE)
//		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			GetCMPS11_Angle8Bit();
//			if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE)
//			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				GetCMPS11_Angle8Bit();
//				if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE)
//				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				}
//			}
//		}
//	}
//	else
//	{
//		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//			}
//		}
//		else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
//		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
//				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//			}
//		}
//
//	}
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

//			if(Ping[PING_FRONT]<40)
//			{
////				Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
////				Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			}
//			else
//			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				GetCMPS11_Angle8Bit();
				if(CMPS11_Angle<R4A_THRESHOLD_MIDDLE && CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
				{
					while(CMPS11_Angle<(R4A_THRESHOLD_MIDDLE-15) && CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
					{
					lcd_display_clear();
					lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
					lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION ");lcd_putstr(lcd);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					GetCMPS11_Angle8Bit();
					}
				}
//			}
//					if(CMPS11_Angle<R4A_THRESHOLD_MIDDLE || CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//						{	lcd_display_clear();
//							lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//							lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION 2");lcd_putstr(lcd);
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							GetCMPS11_Angle8Bit();
//							if(CMPS11_Angle<R4A_THRESHOLD_MIDDLE || CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//							{	lcd_display_clear();
//								lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//								lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION 3");lcd_putstr(lcd);
//
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							}
//							}
//						}
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R3");lcd_putstr(lcd);
			delay_ms(100);

//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			for(p=0;p<=2;p++)
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		//		if(Ping[PING_FRONT]<15)break;
				Bumper_Action();
			}

//			if(Ping[PING_RIGHT]<10)
//			{
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			}
			if(Ping[PING_FRONT]<10)
			{
				Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();
//	}
//	else
//	{
////		while(Ping[PING_FRONT]>16)
////		{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
////		}
//
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
////		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
////		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
////		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		BW_FollowTracer_Left();
//	}

}

/* func      : void Nav_1C_To_4A(void)
 * brief     : Navigate from Room 1C to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_1C_To_4A(void)
{
//	int counter;
	int g;

	BW_Buzz(1);\
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	GetCMPS11_Angle8Bit();
//	if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			GetCMPS11_Angle8Bit();
//			if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				GetCMPS11_Angle8Bit();
//				if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					GetCMPS11_Angle8Bit();
//					if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					}
//
//				}
//			}
//		}
//	if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//	{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//		}
//	}

//	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
	GetCMPS11_Angle8Bit();
	if(CMPS11_Angle<R4A_THRESHOLD_MIDDLE && CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
	{
		while(CMPS11_Angle<(R4A_THRESHOLD_MIDDLE-15) && CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
		{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION ");lcd_putstr(lcd);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		GetCMPS11_Angle8Bit();
		}
	}
//	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

	for(g=0;g<=3;g++)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Bumper_Action();

//			GetBumper();
//			if( (BUMPER[LEFT]||BUMPER[RIGHT])==ACTIVE)
//			{
//				Dynamx_MovBwd(6,HEXSPD_MEDFAST,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			}

		if(Ping[PING_ASKEW_RIGHT]<20)break;

		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		if(TCS3200_SLV_DATA[0]==COLOUR_GRAY)break;

	}
//	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	Dynamx_MovFwd4cm(20,HEXSPD_MEDFAST,IKCALC_DISABLE);

//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

	if(EXTINGUISHED_FIRE==0)
	{
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if(Ping[PING_RIGHT]<10)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		}

//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		if((Ping[PING_ASKEW_LEFT]>30) || (Ping[PING_LEFT]>50))
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);


			for(g=0;g<=2;g++)
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				Bumper_Action();

				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				TCSlave_Check();
				if(TRACER_STAT==TRACER_WHITE)break;
				if((Ping[PING_ASKEW_LEFT]<15) || (Ping[PING_ASKEW_RIGHT]<15))break;
			}

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		}
		else
		{
//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				Nav_TurnAround(TURN_LEFT);

				Cat_Avoider();
				CAT_FLAG=CAT_NOT_DETECTED;

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowCounter_Right(9);

//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

				BW_Buzz(1);
				if (EXTINGUISHED_FIRE==1){BW_PID_Init();}
				else {BW_PID_Init_FAR();}
				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

//				if(CAT_FLAG==CAT_NOT_DETECTED)
//				{
//					BW_Buzz(1);
//					BW_PID_Init();
//					BW_FollowTracer_Right();
//				}

				if(CAT_FLAG==CAT_DETECTED)
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					//Activate special route
					R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
					R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

					Dynamx_MovBwd(12,HEXSPD_ULTRAFAST,IKCALC_DISABLE);


					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

					while(Ping[PING_RIGHT]>25)
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

					Dynamx_MovFwd4cm(15,HEXSPD_MEDFAST,IKCALC_DISABLE);

//					Dynamx_Slide_Left(5,HEXSPD_MEDFAST);
//					Dynamx_Slide_Left(5,HEXSPD_MEDFAST);
//					BW_Buzz(1);
//					BW_PID_Init();
//					BW_FollowCounter_Right(8);

//					BW_Buzz(1);
//					BW_PID_Init();
//					BW_FollowTracer_Left();

//					Start of changes
					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left(COLOUR_GRAY,NORMAL);
//
					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left(COLOUR_BLACK,NORMAL);
//
//					BW_Buzz(1);
//					BW_PID_Init();
//					BW_FollowCounter_Left(3);
//
					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left(COLOUR_GRAY,NORMAL);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left(COLOUR_BLACK,NORMAL);

					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

					if(Ping[PING_RIGHT]<=15)
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					}

					if((Ping[PING_LEFT]>=20) && (Ping[PING_ASKEW_LEFT]>=20))
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					}
					else
					{
			//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					}

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Left();
//
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//
//					BW_Buzz(1);
//					BW_PID_Init();
//					BW_FollowTracer_Left();
					//end of changes
				}
				else
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

//					Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right();
				}
		}
	}
	else
	{
		if(R2TO4A_SP_ROUTE==R2TO4A_SP_ACTIVE)
		{
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

//			Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			if(Ping[PING_RIGHT]<=15)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			Dynamx_MovBwd(12,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			Nav_TurnAround(TURN_RIGHT);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowCounter_Left(12);

		//	BW_Buzz(1);
		//	BW_PID_Init();
		//	BW_FollowCounter_Right(3);

			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

			Cat_Avoider();
			CAT_FLAG=CAT_NOT_DETECTED;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		//	BW_Buzz(1);
		//	BW_PID_Init();
		//	while( (CAT_FLAG==CAT_NOT_DETECTED) && (counter<=14) )
		//	{
		//		Cat_Avoider();
		//		if(CAT_FLAG==CAT_DETECTED)break;
		////		Evade_Wall();
		//		if(CAT_FLAG==CAT_DETECTED)break;
		//		BW_FollowCounter_Right(1);
		//		if(CAT_FLAG==CAT_DETECTED)break;
		//
		//		counter++;
		//	}
	//		BW_Buzz(1);
	//		BW_PID_Init();
	//		BW_FollowTracer_Right();

	//		if(CAT_FLAG==CAT_NOT_DETECTED)
	//		{
	//			BW_Buzz(1);
	//			BW_PID_Init();
	//			BW_FollowTracer_Right();
	//		}

			if(CAT_FLAG==CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_MovBwd(12,HEXSPD_ULTRAFAST,IKCALC_DISABLE);


				while(Ping[PING_RIGHT]>25)
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				Dynamx_MovFwd4cm(20,HEXSPD_MEDFAST,IKCALC_DISABLE);

	//			BW_Buzz(1);
	//			BW_PID_Init();
	//			BW_FollowCounter_Right(8);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left();

	//			Start of changes
	//			BW_Buzz(1);
	//			BW_PID_Init();
	//			BWFollowCarpet_Left(COLOUR_GRAY,NORMAL);
	//
	//			BW_Buzz(1);
	//			BW_PID_Init();
	//			BWFollowCarpet_Left(COLOUR_BLACK,NORMAL);
	//
	//			BW_Buzz(1);
	//			BW_PID_Init();
	//			BW_FollowCounter_Left(5);
	//
	//			BW_Buzz(1);
	//			BW_PID_Init();
	//			BWFollowCarpet_Left(COLOUR_GRAY,NORMAL);
	//
	//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
	//
	//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	//
	//			BW_Buzz(1);
	//			BW_PID_Init();
	//			BW_FollowTracer_Left();
	//end of changes

			}
			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right();
			}
		}

	}

	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */
	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

/* func      : void Nav_2_To_4A_NEW(void)
 * brief     : Navigate from Room 2 to Room 4A Alternatif CAT A NOT CHECKED
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Toni (Monday, Nov 20th 2017)
 * Revised BY:
 * programmer's Note:
 */
void Nav_1C_To_4A_NEW(void)
{
//	int counter;
	int g;

	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	GetCMPS11_Angle8Bit();
//	if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			GetCMPS11_Angle8Bit();
//			if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				GetCMPS11_Angle8Bit();
//				if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					GetCMPS11_Angle8Bit();
//					if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					}
//
//				}
//			}
//		}

//	if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//	{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//		}
//	}

	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
	GetCMPS11_Angle8Bit();
	if(CMPS11_Angle<R4A_THRESHOLD_MIDDLE && CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
	{
		while(CMPS11_Angle<(R4A_THRESHOLD_MIDDLE-15) && CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
		{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION ");lcd_putstr(lcd);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		GetCMPS11_Angle8Bit();
		}
	}

	for(g=0;g<=3;g++)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Bumper_Action();

//			GetBumper();
//			if( (BUMPER[LEFT]||BUMPER[RIGHT])==ACTIVE)
//			{
//				Dynamx_MovBwd(6,HEXSPD_MEDFAST,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			}

		if(Ping[PING_ASKEW_RIGHT]<20)break;

		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		if(TCS3200_SLV_DATA[0]==COLOUR_GRAY)break;

	}
//	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	Dynamx_MovFwd4cm(20,HEXSPD_MEDFAST,IKCALC_DISABLE);

	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

	if(EXTINGUISHED_FIRE==0)
	{
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if((Ping[PING_ASKEW_LEFT]>30) || (Ping[PING_LEFT]>30))
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

//			Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			for(g=0;g<=3;g++)
//			{
//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				Bumper_Action();
//
//				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
//				TRACER_STAT=TRACER_BLACK;
//
//				TCSlave_Check();
//				if(TRACER_STAT==TRACER_WHITE)break;
//				if((Ping[PING_ASKEW_LEFT]<15) || (Ping[PING_ASKEW_RIGHT]<15))break;
//			}

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		}
		else
		{
//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

//			BW_Buzz(1);
//			BW_PID_Init();
//			BW_FollowTracer_Right();

			Cat_Avoider();
			CAT_FLAG=CAT_NOT_DETECTED;
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

			BW_Buzz(1);
			BW_PID_Init_FAR();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

			BW_Buzz(1);
			BW_PID_Init_FAR();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			if(CAT_FLAG==CAT_DETECTED)			// CAT C
			{
				CAT_DETECTOR=CAT_DIACTIVATED;
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				R4ATO3_SP_ROUTE=R4ATO3_SP_INACTIVE;

				Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

				Nav_TurnAround(TURN_LEFT);

				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right();

			}
			else //CAT C KOSONG
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init_FAR();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				if(CAT_FLAG==CAT_DETECTED)			// CAT B
				{
					CAT_DETECTOR=CAT_DIACTIVATED;
					CAT_FLAG=CAT_NOT_DETECTED;
					REVERSE_FLAG=REVERSEFLAG_ACTIVE;
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
					lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
					//delay_ms(100);

//					Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					Dynamx_MovBwd(2,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

//					Nav_TurnAround(TURN_LEFT);
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right();

				}
				else //CAT B kosong
				{
					CAT_DETECTOR=CAT_DIACTIVATED;
					R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;

					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
					//Activate special route
					R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
					R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Left();

				}

			}
		}
	}
}


/* func      : void Nav_1C_To_4B(void)
 * brief     : Navigate from Room 1C to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_1C_To_4B(void)
{
//	int counter;
	int g;

	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	GetCMPS11_Angle8Bit();
//	if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			GetCMPS11_Angle8Bit();
//			if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				GetCMPS11_Angle8Bit();
//				if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					GetCMPS11_Angle8Bit();
//					if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					}
//
//				}
//			}
//		}

	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
	GetCMPS11_Angle8Bit();
	if(CMPS11_Angle<R4A_THRESHOLD_MIDDLE && CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
	{
		while(CMPS11_Angle<(R4A_THRESHOLD_MIDDLE-15) && CMPS11_Angle>R1BC_THRESHOLD_MIDDLE)
		{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION ");lcd_putstr(lcd);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		GetCMPS11_Angle8Bit();
		}
	}

	for(g=0;g<=3;g++)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Bumper_Action();

//			GetBumper();
//			if( (BUMPER[LEFT]||BUMPER[RIGHT])==ACTIVE)
//			{
//				Dynamx_MovBwd(6,HEXSPD_MEDFAST,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			}

		if(Ping[PING_ASKEW_RIGHT]<20)break;

		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		if(TCS3200_SLV_DATA[0]==COLOUR_GRAY)break;

	}

	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

//	BW_Buzz(1);
//	BW_PID_Init();
//	BW_FollowCounter_Right(3);

//	Dynamx_Slide_Left(5,HEXSPD_ULTRAFAST);
//	Dynamx_Slide_Left(5,HEXSPD_ULTRAFAST);
//	Dynamx_Slide_Left(5,HEXSPD_ULTRAFAST);
//	Dynamx_Slide_Left(5,HEXSPD_ULTRAFAST);

	Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

//			Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
	for(g=0;g<=3;g++)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		Bumper_Action();

		FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
		TRACER_STAT=TRACER_BLACK;

		TCSlave_Check();
		if(TRACER_STAT==TRACER_WHITE)break;
		if((Ping[PING_ASKEW_LEFT]<15) || (Ping[PING_ASKEW_RIGHT]<15))break;
	}

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left();

	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */
	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

/* func      : void Nav_4A_To_HallwaySC(void)
 * brief     : Navigate from Room 4A to Hallway SC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, April 10th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4A_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);


	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		BW_Buzz(2);
		BW_PID_Init();
		FollowHome_Right();
	}

	if(CAT_FLAG==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		BW_Buzz(2);
		BW_PID_Init();
		follow_left_counter(15);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		follow_left_counter(15);

		BW_Buzz(2);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		follow_right_counter(25);

		BW_Buzz(2);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowHome_Left();
	}

}

/* func      : void Nav_4A_To_3(void)
 * brief     : Navigate from Room 4A to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Friday, Feb 24th 2017)
 * 			   Ver3 : Toni (Tuesday, Nov 2th 2017)
 * programmer's Note:
 */
void Nav_4A_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R3");lcd_putstr(lcd);
	delay_ms(100);

//	Evade_Wall();

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//	CAT_FLAG=CAT_NOT_DETECTED;


//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//	Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);


	if(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
	{
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	}
//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

	if(R4ATO3_SP_ROUTE==R4ATO3_SP_ACTIVE)
	{
		R4ATO3_SP_ROUTE=R4ATO3_SP_INACTIVE;
		R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		while(Ping[PING_FRONT]>15)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}

		while(Ping[PING_FRONT]<20)
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ABU 1");lcd_putstr(lcd);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowCounter_Left(12);

		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"HITAM 1");lcd_putstr(lcd);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ABU 2");lcd_putstr(lcd);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"HITAM 2");lcd_putstr(lcd);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ABU 3");lcd_putstr(lcd);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"HITAM 3");lcd_putstr(lcd);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		Nav_TurnAround(TURN_RIGHT);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Left();
	}

//	DEFAULT ROUTE
	else if(R4ATO3_SP_ROUTE==R4ATO3_SP_INACTIVE)
	{
		while(Ping[PING_FRONT]>20)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}

		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		if(CAT_FLAG_A==CAT_NOT_DETECTED || CAT_FLAG_B==CAT_NOT_DETECTED || CAT_FLAG_C==CAT_NOT_DETECTED)
		{
		GetCMPS11_Angle8Bit();
		if(CMPS11_Angle<R4A_THRESHOLD_MIDDLE && CMPS11_Angle>R4AB_THRESHOLD_UPPER-10)
		{
			while(CMPS11_Angle<(R4A_THRESHOLD_MIDDLE) && CMPS11_Angle>(R4AB_THRESHOLD_UPPER-10))
			{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION ");lcd_putstr(lcd);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			GetCMPS11_Angle8Bit();
			}
		}
		}

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);


		if (CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	// COBA
//			Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

	/*		//USED NOW
	 * 		Dynamx_MovBwd(12,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
	 */

			while(Ping[PING_RIGHT]<20)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

			//NEXT ROOM = ROOM3
			if( (ROOM[1]==ROOM_1A) || (ROOM[1]==ROOM_2B) || (ROOM[1]==ROOM_2A) || (ROOM[1]==ROOM_1B) || (ROOM[1]==ROOM_1C))
			{

				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SPECIAL");lcd_putstr(lcd);
				lcd_gotoxy(8,2);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R3");lcd_putstr(lcd);
				delay_ms(100);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowCounter_Left(13);

				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				Nav_TurnAround(TURN_RIGHT);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left();
			}
			else
			{
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
				lcd_gotoxy(8,2);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
				delay_ms(100);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;


//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"1");lcd_putstr(lcd);
//				delay_ms(50);
//
//				BW_Buzz(1);
//				BW_PID_Init();
//				BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);
//
//
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"2");lcd_putstr(lcd);
//				delay_ms(50);
//
//				BW_Buzz(1);
//				BW_PID_Init();
//				BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
//
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"3");lcd_putstr(lcd);
//				delay_ms(50);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left();

				ROOM4A_FLAG=ROOM4AFLAG_ACTIVE;
				ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

				//ACTIVATING SPECIAL ROUTE
				R2TO4A_SP_ROUTE=R2TO4A_SP_ACTIVE;

				FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

			}
		}

		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;

//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			if(Ping[PING_FRONT]>12)
//				{
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				}
//			lcd_display_clear();
//			lcd_gotoxy(2,0);sprintf(lcd,"1");lcd_putstr(lcd);
//			//delay_ms(50);

//			BW_Buzz(1);
//			BW_PID_Init();
//			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);
//
//
//			lcd_display_clear();
//			lcd_gotoxy(2,0);sprintf(lcd,"2");lcd_putstr(lcd);
//			//delay_ms(50);
//
//			BW_Buzz(1);
//			BW_PID_Init();
//			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);
//
////			if((Ping[PING_RIGHT]>8)||(Ping[PING_REAR_RIGHT]>10))
////			{
////				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
////			}
//
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right();

			REVERSE_FLAG=REVERSEFLAG_INACTIVE;
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
		}
	}

}

/* func      : void Nav_4A_To_1A(void)
 * brief     : Navigate from Room 4A to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY:  Ver2 : Hafidin (Friday, Feb 24th 2017)
 * 				Ver.3 : Ryan (Saturday, April 22nd, 2017)
 * 				Added special route to R1BC when cat has been determined in config B/C
 * programmer's Note:
 */
void Nav_4A_To_1A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	/*
	 *  SPECIAL ROUTE WHEN NAVIGATION= R1B/R1C -> R2 -> R3 - R4A
	 *  CAT LOCATION= EXCEPT A (THUS POSSIBLE CAT LOCATIONS ARE B AND C)
	 *  BW WILL NAVIGATE THROUGH THE SAFEST ROUTE,
	 */

	while(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
	{
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	}
	if(R4ATO1_SP_ROUTE==SP_ROUTE_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R1BC");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"SPECIAL ROUTE");lcd_putstr(lcd);
		delay_ms(100);

		BW_Buzz(1);
		while(Ping[PING_FRONT]>18)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

		while(Ping[PING_FRONT]<25)
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		Nav_TurnAround(TURN_RIGHT);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Left();

	}

	/*
	 * BW DEFAULT ROUTE, THROUGH THE POSSIBLE CAT LOCATION B
	 */
	else
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"DEFAULT ROUTE");lcd_putstr(lcd);
		delay_ms(100);

		BW_Buzz(1);
		while(Ping[PING_FRONT]>18)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}

		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

		while(Ping[PING_FRONT]<25)
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Left();

		//CAT DETECTED
		if (CAT_FLAG==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			Dynamx_MovBwd(12,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			while(Ping[PING_LEFT]<25)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

			while(Ping[PING_FRONT]<25)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right();
		}
	}


}

/* func      : void Nav_4A_To_1A_VER2(void)
 * brief     : Navigate from Room 4A to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Toni (Friday, March 26th 2018)
 * Revised BY:
 * programmer's Note:
 */
void Nav_4A_To_1A_VER2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	while(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
	{
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	}

	BW_Buzz(1);
	while(Ping[PING_FRONT]>18)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
	}

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

	if(CAT_FLAG_A==CAT_NOT_DETECTED && CAT_FLAG_B==CAT_NOT_DETECTED && CAT_FLAG_C==CAT_NOT_DETECTED)
	{
	GetCMPS11_Angle8Bit();
	if(CMPS11_Angle<R4A_THRESHOLD_MIDDLE && CMPS11_Angle>R4AB_THRESHOLD_UPPER-10)
	{
		while(CMPS11_Angle<(R4A_THRESHOLD_MIDDLE) && CMPS11_Angle>(R4AB_THRESHOLD_UPPER-10))
		{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION ");lcd_putstr(lcd);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		GetCMPS11_Angle8Bit();
		}
	}
	}
//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//
//	BW_Buzz(1);
//	BW_PID_Init_FAR();
//	BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

	if(CAT_FLAG_B==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	}
	else
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	}
	BW_Buzz(1);
	BW_PID_Init_FAR();
	BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

	//CAT DETECTED
	if (CAT_FLAG==CAT_DETECTED)
	{
		CAT_DETECTOR=CAT_DIACTIVATED;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		CAT_FLAG_A = CAT_DETECTED;

		Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

		Nav_TurnAround(TURN_RIGHT);

//		while(Ping[PING_RIGHT]<20)
//		{
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		}
//
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//
//		while(Ping[PING_FRONT]<20)
//		{
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		}

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Left();

		ROOM4A_FLAG=ROOM4AFLAG_ACTIVE;
		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

		//ACTIVATING SPECIAL ROUTE
		R2TO4A_SP_ROUTE=R2TO4A_SP_ACTIVE;
	}
	else
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		CAT_FLAG=CAT_NOT_DETECTED;
		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		if(CAT_FLAG_B==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		}

		BW_PID_Init();
		BW_FollowCounter_Left(2);

		if(Ping[PING_ASKEW_LEFT]>(Ping[PING_REAR_LEFT]))
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if(Ping[PING_ASKEW_LEFT]>(Ping[PING_REAR_LEFT]))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}

		}

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BW_FollowTracer_Right();

		if (CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			CAT_FLAG_C = CAT_DETECTED;

			Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			Nav_TurnAround(TURN_LEFT);

			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();

		}
		else
		{
			CAT_FLAG_B=CAT_DETECTED;
		}
	}
	FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;
	ROOM4A_FLAG=ROOM4AFLAG_ACTIVE;
	ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;
}

/* func      : void Nav_4A_To_2(void)
 * brief     : Navigate from Room 4A to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2  : Hafidin (Friday, Feb 24th 2017)
 * 			   Ver 3.: Ryan (Friday, April 21th, 2017)
 * 			   			ADDED SPECIAL ROUTE WHEN CAT ALREADY SPOTTED IN EARLIER NAVIGATION
 * programmer's Note:
 */
void Nav_4A_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	/*
	 * SPECIAL ROUTE WHEN CAT ALREADY SPOTTED IN EARLIER NAVIGATION
	 */

	while(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
	{
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
	}

	if(R4ATO2_SP_ROUTE==SP_ROUTE_ACTIVE)
	{
		BW_Buzz(1);
		while(Ping[PING_FRONT]>18)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}

		while(Ping[PING_FRONT]<20)
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 1");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 2");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
//		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);
		BW_FollowCounter_Left(13);

//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);


		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 3");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 4");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 5");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);


		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);


		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 6");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 7");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);


		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);


		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 8");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();

	}

	else if((CAT_FLAG_B==CAT_DETECTED)||(CAT_FLAG_C==CAT_DETECTED))
	{
		while(Ping[PING_FRONT]>18)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}
		while(Ping[PING_FRONT]<18)
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

		Nav_TurnAround(TURN_LEFT);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();
	}
//	Default route (CHECKING CAT CONFIG A FIRST
	else
	{
		while(Ping[PING_FRONT]>18)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}
		while(Ping[PING_FRONT]<18)
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			Nav_TurnAround(TURN_LEFT);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right();
		}

		if(CAT_FLAG==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			Dynamx_MovBwd(12,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			while(Ping[PING_RIGHT]<20)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowCounter_Left(10);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right();
		}
	}


}


/* func      : void Nav_4B_To_HallwaySC(void)
 * brief     : Navigate from Room 4B to Hallway SC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, 10th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4B_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO SC");lcd_putstr(lcd);
	delay_ms(100);

//	while(Ping[PING_FRONT]<=30)
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}

//	mov_fwd_5cm(15,FAST_LEVEL_3);
	mov_fwd_5cm(15,FAST_LEVEL_3);

	BW_Buzz(2);
	BW_PID_Init();
	follow_right_counter(5);

	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowHome_Left();
}



/* func      : void Nav_4B_To_1(void)
 * brief     : Navigate from Room 4B to Room 1
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4B_To_1A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	if(CAT_FLAG_A == CAT_DETECTED || CAT_FLAG_B== CAT_DETECTED)
	{
		while(Ping[PING_FRONT]>=15)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}

		while(Ping[PING_FRONT]<18)
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		}

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();
		FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

	}
	else
	{
	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	while(Ping[PING_FRONT]>=15)
//	{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	}

//	while(Ping[PING_FRONT]<18)
//	{
	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//	}

	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init_FAR();
	BW_FollowCounter_Right(6);

	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

	BW_Buzz(1);
	BW_PID_Init_FAR();
	BW_FollowCounter_Left(8);

	if(Ping[PING_ASKEW_LEFT]<(Ping[PING_REAR_LEFT]-5))
	{
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	}

	while(Ping[PING_FRONT]>15)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
	}

	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

	if(CAT_FLAG==CAT_DETECTED)
	{
		CAT_DETECTOR=CAT_DIACTIVATED;
		R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;
		CAT_FLAG_A=CAT_DETECTED;

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		//Activate special route
		R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
		R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

		Dynamx_MovBwd(8,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		while(Ping[PING_RIGHT]>25)
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		Dynamx_MovFwd4cm(20,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		if(Ping[PING_LEFT]>18)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			if(Ping[PING_LEFT]>18)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}
		}

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right();
		FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

	}
	else
	{
		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		BW_Buzz(1);
		BW_PID_Init_Room();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init_Room();
		BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

		if(Ping[PING_ASKEW_LEFT]<(Ping[PING_REAR_LEFT]-5))
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
		while(Ping[PING_FRONT]>15)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		}

		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

		if(CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			CAT_FLAG_B=CAT_DETECTED;

			Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

	//		Nav_TurnAround(TURN_LEFT);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right();

			FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();

			FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

		}

	}
	}
}

/* func      : void Nav_4B_To_1(void)
 * brief     : Navigate from Room 4B to Room 1
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Thursday, Feb 23th 2017)
 * Revised BY: N/A
 * programmer's Note:
 */

void Nav_4B_To_1BC(void)
{
	int g;
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	while(Ping[PING_FRONT]>=15)
//	{
//		Dynamx_MovFwd3cm(3,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//	}
	for(g=0;g<=3;g++)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		if(Ping[PING_FRONT]<=15)break;
	}

	while(Ping[PING_FRONT]<18)
	{
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	}

//	BW_Buzz(1);
//	BW_PID_Init();
//	BW_FollowTracer_Left();

	//============== ;p ;p ;p
	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

	if(Ping[PING_LEFT]>=15)
	{
		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		if(Ping[PING_LEFT]>=15)
//		{
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		}
	}

//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

	if(Ping[PING_ASKEW_LEFT]>=30)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		if(Ping[PING_ASKEW_LEFT]>=30)
		{
			SP_FIRE_1B=SP_FIRE_ACTIVE;
		}
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	}
	else
	{
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		SP_FIRE_1C=SP_FIRE_ACTIVE;
	}

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left();

}
/* func      : void Nav_4B_To_1BC_EXC(void)
 * brief     : Navigate from Room 4B to Room 1 Exclusive route
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Toni (Wednesday, November 22th 2017)
 * Revised BY: N/A
 * programmer's Note:
 */

void Nav_4B_To_1BC_EXC(void)
{
	int g;
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R1BC EXC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	while(Ping[PING_FRONT]>=15)
//	{
//		Dynamx_MovFwd3cm(3,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//	}
	for(g=0;g<=3;g++)
	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		if(Ping[PING_FRONT]<=15)break;
	}

	while(Ping[PING_FRONT]<18)
	{
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	}

//	BW_Buzz(1);
//	BW_PID_Init();
//	BW_FollowTracer_Left();

	//============== ;p ;p ;p
	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

//	if(Ping[PING_LEFT]>=15)
//	{
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////		if(Ping[PING_LEFT]>=15)
////		{
////			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////		}
//	}

//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

	Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
	if(Ping[PING_LEFT]>=30 || Ping[PING_ASKEW_LEFT]>=30)
	{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//		if(Ping[PING_LEFT]>=50 && Ping[PING_ASKEW_LEFT]>=30)
//		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"1B DOOR");lcd_putstr(lcd);
			SP_FIRE_1B=SP_FIRE_ACTIVE;
//		}
	}
	else
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"1B DOOR");lcd_putstr(lcd);
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		SP_FIRE_1C=SP_FIRE_ACTIVE;
	}

}

/* func      : void Nav_4B_To_2(void)
 * brief     : Navigate from Room 4B to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Thursday, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_4B_To_2(void)
{
//	int counter;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	while(Ping[PING_FRONT]>=18)
//	{
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	}

//	while(Ping[PING_FRONT]<18)
//	{
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//	}



	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

//	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Right();
}

/* func      : void Nav_4B_To_3(void)
 * brief     : Navigate from Room 4B to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Thursday, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_4B_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	while(Ping[PING_FRONT]>=15)// && ((SHARP[SHARP_FRONT_L]>11) || (SHARP[SHARP_FRONT_R]>11)))
//	{
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//	}
//
//	while(Ping[PING_FRONT]<18)
//	{
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//	}

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left(COLOUR_BLACK,INVERSE);

	Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

	Nav_TurnAround(TURN_RIGHT);

//	if( (Ping[PING_FRONT]<=20) || (SHARP[SHARP_FRONT_R]<20) )
//	{
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
////		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	}


	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left();
}

/* func      : void TCSlave_Check(void)
 * brief     : Detecting white lines with Photodiode Tracer and TCS3200 Processor
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 30th 2016)
 * Revised BY: Ver. 2 -> Ryan (Thursday, April 21st 2016
 * 					Configured for the new Hybrid TCS3200+Tracer Processor
 * 			   Ver. 3 -> Ryan  (Monday, April 4th 2017
 * 			        Optimization for Photodiode Tracer Readings
 * programmer's Note:
 */
void TCSlave_Check(void)
{
	HomeCircle_Detector();
//	HomeCircle_Detector();

//	if((HOME_CIRCLE_FLAG==HOME_CIRCLE_DETECTED) && (FOLLOWHOME_FLAG==FOLLOWHOME_INACTIVE))
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"ESCAPING");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"HOME CIRCLE");lcd_putstr(lcd);
//		delay_ms(100);
//
//		BW_PID_Init();
//		follow_right_counter(5);
////		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
////		while ( (TCS3200_SLV_DATA[1]==TRACER_WHITE) || (TCS3200_SLV_DATA[0]==COLOUR_WHITE) )
////		{
////			follow_right_counter(2);
////			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
////		}
//
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"HOME CIRCLE");lcd_putstr(lcd);
//		lcd_gotoxy(0,0);sprintf(lcd,"ESCAPED!");lcd_putstr(lcd);
//		delay_ms(100);
//		HOME_CIRCLE_FLAG==HOME_CIRCLE_NOT_DETECTED;
//
//	}

//VERSION 1
//	if( (HOME_CIRCLE_FLAG == HOME_CIRCLE_NOT_DETECTED) && (FOLLOWHOME_FLAG==FOLLOWHOME_INACTIVE))
//	{
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
////		if(
////			(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
////		  )
////		{
////			TRACER_STAT= TRACER_WHITE;
////		}
//		if(
//			(TCS3200_SLV_DATA[1]==TRACER_WHITE)
//		  )
//		{
//			TRACER_STAT= TRACER_WHITE;
//		}
//
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
////		if(
////			(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
////		  )
////		{
////			TRACER_STAT= TRACER_WHITE;
////		}
//		if(
//			(TCS3200_SLV_DATA[1]==TRACER_WHITE)
//		  )
//		{
//			TRACER_STAT= TRACER_WHITE;
//		}
//
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
////		if(
////			(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
////		  )
////		{
////			TRACER_STAT= TRACER_WHITE;
////		}
//		if(
//			(TCS3200_SLV_DATA[1]==TRACER_WHITE)
//		  )
//		{
//			TRACER_STAT= TRACER_WHITE;
//		}
//
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
////		if(
////			(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
////		  )
////		{
////			TRACER_STAT= TRACER_WHITE;
////		}
//		if(
//			(TCS3200_SLV_DATA[1]==TRACER_WHITE)
//		  )
//		{
//			TRACER_STAT= TRACER_WHITE;
//		}
//	}

//VERSION 3
	if( (HOME_CIRCLE_FLAG == HOME_CIRCLE_NOT_DETECTED) && (FOLLOWHOME_FLAG==FOLLOWHOME_INACTIVE))
	{
		if(FOLLOWMODE_FLAG==FOLLOW_TRACER_WHITE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(
				(TCS3200_SLV_DATA[1]==TRACER_WHITE)
			  )
			{
				TRACER_STAT= TRACER_WHITE;
			}
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(
				(TCS3200_SLV_DATA[1]==TRACER_WHITE)
			  )
			{
				TRACER_STAT= TRACER_WHITE;
			}
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(
				(TCS3200_SLV_DATA[1]==TRACER_WHITE)
			  )
			{
				TRACER_STAT= TRACER_WHITE;
			}
		}


		else if(FOLLOWMODE_FLAG==FOLLOW_CARPET_ACTIVE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TCS3200);
			if(
				(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
			  )
			{
						TRACER_STAT= TRACER_WHITE;
			}
		}
	}

}

void Tracer_Check(void)
{
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	FRONT=TCS3200_SLV_DATA[0];
	MIDDLE=TCS3200_SLV_DATA[1];
	REAR=TCS3200_SLV_DATA[2];

//	if(cnt==3)
//	{
//		BACA[0]=FRONT;
//	}
//	else
//	{
//		BACA[1]=FRONT;
//		cnt=2;
//	}
//	cnt++;

	BACA[0]=FRONT;
	BACA[1]=MIDDLE;
	BACA[3]=REAR;

//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"lama %d",BACA[0]);lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"baru %d",BACA[1]);lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd,"%d",cnt);lcd_putstr(lcd);
//	delay_ms(50);

//	BACA[0]=FRONT;
//	BACA[1]=BACA[0];

//	VALUE=BACA[0]-BACA[1];

	if((BACA[0]>100) || (BACA[1]>100) || (BACA[2]>100))
	{
		TRACER_STAT=TRACER_WHITE;
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"WHITE DETECTED");lcd_putstr(lcd);
//		delay_ms(50);
	}
	else
	{
		TRACER_STAT=TRACER_BLACK;
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"BLACK DETECTED");lcd_putstr(lcd);
//		delay_ms(50);
	}

//	if(TRACER_STAT==TRACER_WHITE)
//	{
////		while(1)
////		{
////			lcd_display_clear();
////			lcd_gotoxy(0,0);sprintf(lcd,"WHITE DETECTED");lcd_putstr(lcd);
////			delay_ms(50);
////		}
//	}
//	else
//	{
////		lcd_display_clear();
////		lcd_gotoxy(0,0);sprintf(lcd,"BLACK DETECTED");lcd_putstr(lcd);
////		delay_ms(50);
//	}
}

/* func      : void HomeCircle_Detector(void)
 * brief     : Detecting HomeCircle's presence
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 30th 2016)
 * Revised BY: Ver. 2 -> Ryan (Thursday, April 21st 2016
 * 					Configured for the new Hybrid TCS3200+Tracer Processor
 * programmer's Note:
 */
void HomeCircle_Detector(void)
{
	HOME_CIRCLE_FLAG = HOME_CIRCLE_NOT_DETECTED;

	if(HOME_CIRCLE_FLAG == HOME_CIRCLE_NOT_DETECTED)
	{
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//		if( (TCS3200_SLV_DATA[0]==COLOUR_WHITE) && (TCS3200_SLV_DATA[1]==TRACER_WHITE) )
//		{
//			HOME_CIRCLE_FLAG = HOME_CIRCLE_DETECTED;
//
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"HOME CIRCLE");lcd_putstr(lcd);
//			lcd_gotoxy(8,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
//			delay_ms(100);
//		}
//		else
//		{
//			HOME_CIRCLE_FLAG = HOME_CIRCLE_NOT_DETECTED;
//		}
	}

}


/* func      : void Exit_No_Fire(void)
 * brief     : BW Escape ROOM when fire is not present
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (*MISSING NOTES*, Legacy codes from BW 2015)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void Exit_No_Fire(void)
{
//	int counter;
	Sendto_PC(USART1,"BW EXIT NO FIRE \r");

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(1,1);sprintf(lcd,"FIRE NOT FOUND");lcd_putstr(lcd);
	lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
	lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
	delay_ms(100);
//	Get_IR();

	if( (ROOM1_FLAG==ROOM1FLAG_ACTIVE) )
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(2,1);sprintf(lcd,"ROOM 1 FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(100);

		if (ROOM[2]==ROOM_1C)
		{
			lcd_gotoxy(0,1);sprintf(lcd,"RETURN PARAM");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"ROOM1C MODE");lcd_putstr(lcd);

			Nav_TurnAround(TURN_RIGHT);

			BW_PID_Init();
			//BW_PID_Init_Room();
			BW_FollowTracer_Left();
		}
		else if(ROOM[2]==ROOM_1B)
		{
			lcd_gotoxy(0,1);sprintf(lcd,"RETURN PARAM");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"ROOM1B MODE");lcd_putstr(lcd);

			Nav_TurnAround(TURN_LEFT);

			BW_PID_Init();
			//BW_PID_Init_Room();
			BW_FollowTracer_Right();
		}
		else if( (Ping[PING_LEFT]<30) && (Ping[PING_ASKEW_LEFT]<30) && (Ping[PING_REAR_LEFT]<30)  )
		{
			lcd_gotoxy(0,3);sprintf(lcd,"ROOM1B MODE");lcd_putstr(lcd);
			Nav_TurnAround(TURN_LEFT);
//			while(Ping[PING_LEFT]<25)
//			{
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			}
//
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
////			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//	//		Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//
//			if(Ping[PING_FRONT]>18)
//			{
//				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			}
//
//			while(Ping[PING_FRONT]<25)
//			{
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			}

			BW_PID_Init();
			//BW_PID_Init_Room();
			BW_FollowTracer_Right();
		}
				else if( (Ping[PING_RIGHT]<30) && (Ping[PING_ASKEW_RIGHT]<30) && (Ping[PING_REAR_RIGHT]<30)  )
						{
							lcd_gotoxy(0,3);sprintf(lcd,"ROOM1C MODE");lcd_putstr(lcd);
							Nav_TurnAround(TURN_RIGHT);
				//			while(Ping[PING_RIGHT]<25)
				//			{
				//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				//			}
				//
				//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				////			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				//	//		Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
				//
				//			if(Ping[PING_FRONT]>18)
				//			{
				//				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
				//			}
				//
				//			while(Ping[PING_FRONT]<25)
				//			{
				//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				//			}

							BW_PID_Init();
							//BW_PID_Init_Room();
							BW_FollowTracer_Left();
						}

		else
		{
			lcd_gotoxy(0,3);sprintf(lcd,"DEFAULT MODE");lcd_putstr(lcd);
			while(Ping[PING_LEFT]<25)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	//		Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);

			if(Ping[PING_FRONT]>18)
			{
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			while(Ping[PING_FRONT]<25)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

//			for(l=0;l<=1;l++)
//			{
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				if(Ping[PING_RIGHT]<=12)break;
//			}

			BW_PID_Init();
			//BW_PID_Init_Room();
			BW_FollowTracer_Right();
		}
		ROOM1_FLAG=ROOM1FLAG_INACTIVE;
	}

	//ENTER FROM R1A, EXIT FROM RIBC
	else if(SP_FIRE_R3==SP_FIRE_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"EXIT NO FIRE");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"ROOM 3 DEFAULT");lcd_putstr(lcd);
		delay_ms(100);

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_TurnAround(TURN_LEFT);

		BW_PID_Init();
		BW_FollowTracer_Right();

	}
	else if(UV_R2FLAG==UV_R2FLAG_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"EXIT NO FIRE");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"ROOM 2 DEFAULT");lcd_putstr(lcd);
		delay_ms(100);

		Nav_TurnAround(TURN_LEFT);

		BW_PID_Init();
		BW_FollowTracer_Right();

	}
	//ENTER FROM R1A, EXIT FROM RIBC
	else if(ROOM1A_SP_EXIT_FLAG==ROOM1A_SP_EXIT_FLAG_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"R 4A TO 1A FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(100);

		UV_R2FLAG=UV_R2FLAG_ACTIVE;
		FOLLOW_FLAG=KIRI;

		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW COUNTER 1A");lcd_putstr(lcd);

		if(Ping[PING_LEFT]>15)
		{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			if(Ping[PING_LEFT]>15)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
		}

		BW_Buzz(1);
		BW_PID_Init_Furniture();
		BW_FollowCounter_Left(20);

		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"RE-CHECK FIRE 1A");lcd_putstr(lcd);
		TRACER_STAT=TRACER_BLACK;
		TCSlave_Check();
		int i;
		for(i=0;i<10;i++)
//		while(TRACER_STAT==TRACER_BLACK && TCS3200_SLV_DATA[1]!=TRACER_WHITE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,1);sprintf(lcd,"RE-CHECK FIRE TRACER BLACK");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"CNT = %d",i);lcd_putstr(lcd);
			Get_UV();
			if((UV_state==UVSTATE_ACTIVE) && ((FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==6)))
			{
				ROOM[2]=ROOM_1C;
				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
			else if((UV_state==UVSTATE_ACTIVE) && ((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3)))
			{
//				ROOM[2]==ROOM_1B;
//				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
			TCSlave_Check();
			if (TRACER_STAT==TRACER_WHITE)break;
			BW_FollowCounter_Left(1);
			if(UV_Lock==UVLOCK_ACTIVE)break;
			if(FIRE==FIRE_ON)break;
			if (TRACER_STAT==TRACER_WHITE)break;
		}
		if(FIRE==FIRE_ON)
		{
			lcd_display_clear();
			lcd_gotoxy(0,1);sprintf(lcd,"API DETECT 1A");lcd_putstr(lcd);

			FIREROOM_R1A_FLAG=ROOM1A_SP_MIDDLE_FLAG;
			FIRESCAN_DIRECTION=SCAN_RIGHT;

			BW_FireFight();

			FIRE_LED_BLINK_OFF;
			FIRE_LED_OFF;
			FIRE=FIRE_SUCCESS;

	//		/*
	//		 * FIRE == OFF
	//		 */


			//old ALGORITHM
	//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
	//===============================================================
	//		Start of changes
	//		Ryan (April 20th,2017)

			Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

			if ((ROOM[2]==ROOM_4A) || (ROOM[2]==ROOM_4B) || (ROOM[2]==ROOM_3))// || (ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
			{
				FOLLOW_FLAG=KANAN;
				Nav_TurnAround(TURN_LEFT);
				BW_PID_Init();
	//			BW_PID_Init_Room();
				BW_FollowTracer_Right();
			}
			else if ((ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
			{
				Nav_TurnAround(TURN_LEFT);
				BW_PID_Init();
				if(Ping[PING_RIGHT]>30)BW_FollowTracer_Left();
				else BW_FollowTracer_Right();
			}
			else if (ROOM[2]==ROOM_1C)
			{
				FOLLOW_FLAG=KANAN;
				while(Ping[PING_FRONT]>14)
				{
					Furniture_Avoider();
					Bumper_Follow();
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
	//				if((Ping[PING_ASKEW_RIGHT]<15)||(Ping[PING_ASKEW_LEFT]<15))break;
				}
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				BW_PID_Init();
	//			BW_PID_Init_Room();
				BW_FollowTracer_Right();
			}
			else if (ROOM[2]==ROOM_1B)
			{
				FOLLOW_FLAG=KIRI;
	//			Nav_TurnAround(TURN_RIGHT);
				while(Ping[PING_FRONT]>14)
				{
					Furniture_Avoider();
					Bumper_Follow();
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	//				if((Ping[PING_ASKEW_RIGHT]<15)||(Ping[PING_ASKEW_LEFT]<15))break;//Nav_TurnAround(TURN_RIGHT);break;
				}
				BW_PID_Init();
	//			BW_PID_Init_Room();
				BW_FollowTracer_Left();
			}
			else if (ROOM[2]==ROOM_1A)
			{
				FOLLOW_FLAG=KANAN;
	//			Nav_TurnAround(TURN_RIGHT);
				while(Ping[PING_FRONT]>14)
				{
					Furniture_Avoider();
					Bumper_Follow();
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

	//				if((Ping[PING_ASKEW_RIGHT]<15)||(Ping[PING_ASKEW_LEFT]<15))break;//Nav_TurnAround(TURN_RIGHT);break;
				}
				BW_PID_Init();
	//			BW_PID_Init_Room();
				BW_FollowTracer_Right();
			}

			else if(
					(Ping[PING_LEFT]+Ping[PING_ASKEW_LEFT]+Ping[PING_REAR_LEFT])
					<
					(Ping[PING_RIGHT]+Ping[PING_ASKEW_RIGHT]+Ping[PING_REAR_RIGHT])
				)
			{
				FOLLOW_FLAG=KANAN;
				Nav_TurnAround(TURN_LEFT);
				BW_PID_Init();
	//			BW_PID_Init_Room();
				BW_FollowTracer_Right();

			}
			else
			{
				FOLLOW_FLAG=KIRI;
				Nav_TurnAround(TURN_RIGHT);
				BW_PID_Init();
	//			BW_PID_Init_Room();
				BW_FollowTracer_Left();
			}
	//		End of changes
	//		Some codes was omitted in this changes
	//===============================================================
			FOLLOW_FLAG=KOSONG;
			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
			UV_R2FLAG=UV_R2FLAG_INACTIVE;
		}
		else
		{
			lcd_display_clear();
			lcd_gotoxy(0,1);sprintf(lcd,"API KOSONG R 1A");lcd_putstr(lcd);

			BW_FollowTracer_Left();
			FOLLOW_FLAG=KOSONG;
			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
			UV_R2FLAG=UV_R2FLAG_INACTIVE;
		}
	}

	else if (ROOM4B_EXIT_FLAG==ROOM4BFLAG_EXIT_ACTIVE)
	{
		lcd_gotoxy(0,3);sprintf(lcd,"ROOM4B EXIT");lcd_putstr(lcd);
//		int l;
//		for(l=0;l<=5;l++)
//		{
//			Dynamx_Slide_Left(5,HEXSPD_MEDFAST);
//		}
		if((Ping[PING_ASKEW_LEFT]<25) && (Ping[PING_LEFT]<25))
		{
			while(Ping[PING_LEFT]<25)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//			Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);

			while(Ping[PING_FRONT]>18)
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			while(Ping[PING_FRONT]<25)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			BW_PID_Init();
			//BW_PID_Init_Room();
			BW_FollowTracer_Right();
		}
		else if((Ping[PING_ASKEW_RIGHT]<25) && (Ping[PING_RIGHT]<25))
		{
			while(Ping[PING_RIGHT]<25)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	//		Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);

			while(Ping[PING_FRONT]>18)
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			while(Ping[PING_FRONT]<25)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

//			Dynamx_Slide_Left(5,HEXSPD_MEDFAST);
//			Dynamx_Slide_Left(5,HEXSPD_MEDFAST);

			//BW_PID_Init();
			BW_PID_Init_Room();
			BW_FollowTracer_Left();
		}
		else
		{
			while(Ping[PING_LEFT]<25)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	//		Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);

			while(Ping[PING_FRONT]>18)
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			while(Ping[PING_FRONT]<25)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

			BW_PID_Init();
			//BW_PID_Init_Room();
			BW_FollowTracer_Right();
		}
		ROOM4B_EXIT_FLAG=ROOM4BFLAG_EXIT_INACTIVE;
	}

	//DEFAULT EXIT NO FIRE ROUTINES
	else
	{
			lcd_gotoxy(0,3);sprintf(lcd,"DEFAULT EXIT");lcd_putstr(lcd);
			Nav_TurnAround(TURN_LEFT);

			BW_PID_Init();
			//BW_PID_Init_Room();
			BW_FollowTracer_Right();
	}
}

/* func      : void Stabilize_After_Exit(void)
 * brief     : Approach nearest wall in front of door, except in front of ROOM
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 30th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Stabilize_After_Exit(void)
{
	int counter;
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BW STABILIZE");lcd_putstr(lcd);
	delay_ms(100);

	if(Ping[PING_FRONT]<=75)
	{
		Evade_Wall();

		for(counter=1;counter<=3;counter++)
		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
			mov_fwd_5cm(5,FAST_LEVEL_3);
			if(Ping[PING_FRONT]<=17)break;
		}
//		while(Ping[PING_FRONT]>=14)
//		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//			Evade_Wall();
//		}
	}

}

/* func      : void BW_Room(void)
 * brief     : BW in Room routines
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 30th 2016)
 * Revised BY: N/A
 * programmer's Note: 	1. Detecting ROOM_TYPE (NORMAL_ROOM or GRAY_ROOM)
 * 						2. Checking fire presence
 * 							if fire didn't exist, then Exit_No_Fire() routines initiated
 * 							if fire exist, then FireFighting algorithm initiated
 */
void BW_Room(void)
{
	int EXIT_STAT=0;
	BW_Buzz(2);

	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	Fwd_FlameSide(9, FAST_LEVEL_3);

	mov_static();
	delay_ms(500);

	BW_Buzz(1);
	RoomTypeDetector();

	if(ROOM_TYPE==GRAY_ROOM)
	{
		mov_fwd_5cm(5,FAST_LEVEL_3);
		RoomTypeDetector();
	}


//	Evade_Wall();

	//===FUNGSI BARU 7/10/16===//
	Get_UV();
	if(UV_state==UVSTATE_ACTIVE)
	{
		FIRE=FIRE_ON;
		UV_Lock=UVLOCK_ACTIVE;
	}

		if(UV_Lock==UVLOCK_INACTIVE)
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
			}
		}

		if(UV_Lock==UVLOCK_INACTIVE)
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
			}
		}

	//===COMMENT BARU 7/10/16===//
//	BW_FlameCheck();

	//===COMMENT BARU 7/10/16===//
//	if(UV_Lock==UVLOCK_INACTIVE)
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		BW_FlameCheck();
//	}

//	if(FlameSense[0]!=0)
	if(FIRE==FIRE_ON)
	{
		UV_Lock=UVLOCK_ACTIVE;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"FIREFIGHT");lcd_putstr(lcd);
		delay_ms(100);


//		BW_FireFight();
//		BW_FireFight_Ver2();
//		BW_FireFight_Ver4();
		BW_FireFight();

		/*
		 * FIRE == OFF
		 */

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);

			if(Ping[PING_FRONT]<=35)
			{
				if(Ping[PING_FRONT]<=15)
				{
					mov_bwd_3cm(18,FAST_LEVEL_3);
				}


				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
				Get_IR();
				while(
						(Ping[PING_FRONT]<=25) ||
						(INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||
						(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
					 )
				{
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					Get_IR();
				}
				FIRE_LED_BLINK_OFF;
				FIRE_LED_OFF;
				FIRE=FIRE_SUCCESS;
				BW_PID_Init();
				FollowTracer_Right();
			}

			else if(Ping[PING_FRONT]>35)
			{
				if(Ping[PING_LEFT]<Ping[PING_RIGHT])
				{
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);

					TRACER_STAT=TRACER_BLACK;
					while(Ping[PING_FRONT]>=20)
					{
						TCSlave_Check();
						if (TRACER_STAT==TRACER_WHITE){EXIT_STAT=1;break;}
						Get_IR();
						if	((INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED))break;
//						mov_fwd_5cm(5,FAST_LEVEL_3);
						mov_fwd_5cm(5,FAST_LEVEL_3);

					}

					if(EXIT_STAT==0)
					{
						mov_rot_left(FAST_LEVEL_3,CLOSE);
						mov_rot_left(FAST_LEVEL_3,CLOSE);
						mov_rot_left(FAST_LEVEL_3,CLOSE);
						mov_rot_left(FAST_LEVEL_3,CLOSE);
						while(Ping[PING_FRONT]<15)
						{
							mov_rot_left(FAST_LEVEL_3,CLOSE);
							mov_rot_left(FAST_LEVEL_3,CLOSE);
							mov_rot_left(FAST_LEVEL_3,CLOSE);
						}

						FIRE_LED_BLINK_OFF;
						FIRE_LED_OFF;
						FIRE=FIRE_SUCCESS;
						BW_PID_Init();
						FollowTracer_Right();
					}


				}
				else
				{
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);

					TRACER_STAT=TRACER_BLACK;
					while(Ping[PING_FRONT]>=20)
					{
						TCSlave_Check();
						if (TRACER_STAT==TRACER_WHITE){EXIT_STAT=1;break;}
						Get_IR();
						if	((INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED))break;
						mov_fwd_5cm(5, FAST_LEVEL_3);
					}

					if(EXIT_STAT==0)
					{
						mov_rot_right(FAST_LEVEL_3,CLOSE);
						mov_rot_right(FAST_LEVEL_3,CLOSE);
						mov_rot_right(FAST_LEVEL_3,CLOSE);
						mov_rot_right(FAST_LEVEL_3,CLOSE);
						while(Ping[PING_FRONT]<15)
						{
							mov_rot_right(FAST_LEVEL_3,CLOSE);
							mov_rot_right(FAST_LEVEL_3,CLOSE);
							mov_rot_right(FAST_LEVEL_3,CLOSE);
						}

						FIRE_LED_BLINK_OFF;
						FIRE_LED_OFF;
						FIRE=FIRE_SUCCESS;
						BW_PID_Init();
						FollowTracer_Left();
					}
				}

			}

			else
			{
				while(Ping[PING_FRONT]>=15)
				{
					Get_IR();
					if	((INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED))break;
//					mov_fwd_5cm(5,FAST_LEVEL_3);
					mov_fwd_5cm(5,FAST_LEVEL_3);
				}

				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
				while(Ping[PING_FRONT]<15)
				{
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
				}

				FIRE_LED_BLINK_OFF;
				FIRE_LED_OFF;
				FIRE=FIRE_SUCCESS;
				BW_PID_Init();
				FollowTracer_Right();

			}



	}

	else
	{
		FIRE=FIRE_OFF;
		Exit_No_Fire();
	}

}

/* func      : void BW_Strategy(void)
 * brief     : BW Trial Routines (after escape home)
 * 				Behavior Based System

 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Wednesday, March 30th 2016)
 * Revised BY: N/A
 * programmer's Note:
 * 						BW'S location stored in ROOM[1] ~ ROOM[4] variable
 * 						Program sequences from escape home to return trip
 * 						Decision making for navigation path planning
 */
void BW_Strategy(void)
{
	int Error_Code;

	//LOCATION: CORRIDOR
	BW_Buzz(1);
//	if((SHARP[SHARP_RIGHT]<10)||(Ping[PING_RIGHT]<10))
	if(Ping[PING_RIGHT]<14)
	{
//		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
	}
//	if((SHARP[SHARP_RIGHT]<10)||(Ping[PING_RIGHT]<10))
	if(Ping[PING_RIGHT]<14)
	{
//		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
	}

//	mov_fwd_5cm(15,FAST_LEVEL_3);
	mov_fwd_5cm(10, FAST_LEVEL_3);

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);

	//BW STABILIZE
	BW_Buzz(1);
//	Stabilize_After_Exit();

	//ROOM DETECTOR FOR FIRST ROOM
	RoomDetector(ROOM_COUNTER);


//	if(ROOM[ROOM_COUNTER]== ROOM_1A)
//	{
////		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		RoomDetector(ROOM_COUNTER);
//	}




	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	while(EXTINGUISHED_FIRE==0)
	{
		//SPECIAL CASE (HOME ROOM ROOM_1B, ROOM_1C, ROOM_4B, ROOM4AFLAG ACTIVE
		if ( (ROOM[1]==ROOM_1B) || (ROOM[1]==ROOM_1C) || (ROOM[1]==ROOM_4B) || (ROOM4A_FLAG==ROOM4AFLAG_ACTIVE) )
		{
//			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"REVERSE");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
			delay_ms(200);

			if (ROOM[ROOM_COUNTER]== ROOM_1A)
			{
				BW_Navi(ROOM_1A,ROOM_2A);
			}

			if (ROOM[ROOM_COUNTER]== ROOM_1B)
			{
				BW_Navi(ROOM_1B,ROOM_2A);
			}

			if (ROOM[ROOM_COUNTER]== ROOM_1C)
			{
				BW_Navi(ROOM_1C,ROOM_2A);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_2A)
			{
//				BW_Navi(ROOM_2A,ROOM_3);
				BW_Navi(ROOM_2A,ROOM_1C);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_2B)
			{
//				BW_Navi(ROOM_2B,ROOM_3);
				BW_Navi(ROOM_2B,ROOM_1B);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_3)
			{
//				BW_Navi(ROOM_3,ROOM_4A);
				BW_Navi(ROOM_3,ROOM_2A);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_4A)
			{
				BW_Navi(ROOM_4A,ROOM_1A);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_4B)
			{
//				BW_Navi(ROOM_4B,ROOM_1C);
				BW_Navi(ROOM_4B,ROOM_3);
			}
		}

		else
		{
//			BW_Buzz(3);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DEFAULT");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
			delay_ms(100);

			if(ROOM[ROOM_COUNTER]== ROOM_3)
			{
				BW_Navi(ROOM_3,ROOM_2A);
			}
			else if(ROOM[ROOM_COUNTER]== ROOM_2A)
			{
				ROOM1_FLAG=ROOM1FLAG_ACTIVE;
				BW_Navi(ROOM_2A,ROOM_1B);
			}

			else if (ROOM[ROOM_COUNTER]==ROOM_2B)
			{
				ROOM1_FLAG=ROOM1FLAG_ACTIVE;
				BW_Navi(ROOM_2B,ROOM_1B);
			}

			else if(ROOM[ROOM_COUNTER]==ROOM_1A)
			{
				BW_Navi(ROOM_1A,ROOM_4A);
			}
			else if(ROOM[ROOM_COUNTER]==ROOM_1B)
			{
				BW_Navi(ROOM_1C,ROOM_4A);

			}
			else if(ROOM[ROOM_COUNTER]==ROOM_1C)
			{
				BW_Navi(ROOM_1C,ROOM_4A);
			}
			else if(ROOM[ROOM_COUNTER]==ROOM_4A)
			{
				BW_Navi(ROOM_4A,ROOM_3);
			}
			else if(ROOM[ROOM_COUNTER]==ROOM_4B)
			{
				BW_Navi(ROOM_4B,ROOM_3);
			}
		}

		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		BW_Room();



		//BW IN CORRIDOR
		BW_Buzz(1);
//		if((SHARP[SHARP_RIGHT]<10)||(Ping[PING_RIGHT]<10))
		if (Ping[PING_RIGHT]<14)
		{
			mov_deflect_left(FAST,CLOSE);
		}
//		if((SHARP[SHARP_RIGHT]<10)||(Ping[PING_RIGHT]<10))
		if (Ping[PING_RIGHT]<14)
		{
			mov_deflect_left(FAST,CLOSE);
		}

//		mov_fwd_5cm(15,FAST_LEVEL_3);
		mov_fwd_5cm(10, FAST_LEVEL_3);

		//BW IN CORRIDOR
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);

		//BW STABILIZE
		BW_Buzz(1);
//		Stabilize_After_Exit();

		//BW MAP UPDATE
		BW_Buzz(1);
		ROOM_COUNTER++;
		RoomDetector(ROOM_COUNTER);


//		if(ROOM[ROOM_COUNTER]== ROOM_4A)
//		{
//			mov_deflect_left(FAST,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			RoomDetector(ROOM_COUNTER);
//		}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);

//		if(ROOM[ROOM_COUNTER]== ROOM_1A)
//		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			RoomDetector(ROOM_COUNTER);
//		}

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;
	}

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Error_Code= BW_ReturnTrip();

	Evade_Wall();
	if(ROOM[1]!=HALLWAY_SC)
	{
		BW_Buzz(2);

		Evade_Wall();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

		Evade_Wall();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

		Evade_Wall();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

		Evade_Wall();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

	}

//	while(1)
//	{
//		mov_celebrate();
//	}
//	mov_fwd_5cm(15,FAST_LEVEL_3);
//	FollowHome_Left();

	if(Error_Code==0)
	{
		BW_Buzz(5);

		while(1)
		{
			mov_celebrate();
		}

	}
	else
	{
		BW_Buzz(1);
		mov_static();
	}


//	//NON ARBITRARY START
//	if(HOME == HALLWAY_SC)
//	{
//		BW_Navi(HALLWAY_SC,ROOM_3);
//	}
//
//	//ARBITRARY START
//	else
//	{
//
//	}
}


/* func      : int BW_ReturnTrip(void)
 * brief     : BW Return Trip Routines
 * param     : N/A
 * retval    : int error codes
 * 				0 	-> SUCCESS
 * 				-1 	-> ERROR, EXTINGUISHED_FIRE==0 / !=1
 * Ver       : 1
 * written By: Ryan (Thursday, March 31th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int BW_ReturnTrip(void)
{
	//BW RETURN TRIP
	if(EXTINGUISHED_FIRE==1)
	{

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"RETURN TRIP");lcd_putstr(lcd);
//		lcd_gotoxy(8,1);sprintf(lcd,"TRIP");lcd_putstr(lcd);
		delay_ms(100);

		if( (ROOM[2]== ROOM_1A) )
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,HALLWAY_SC);
			}

			else if( (ROOM[1] == ROOM_2A) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_2A);
			}

			else if( (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R2B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_2B);
			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_3);
			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_4A);
			}

			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_4B);
			}
		}

		else if( (ROOM[2]== ROOM_1B) || (ROOM[2]== ROOM_1C) )
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,HALLWAY_SC);
			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,ROOM_3);
			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				if(ROOM[2]== ROOM_1B)
				{
					lcd_gotoxy(0,1);sprintf(lcd,"R1B TO R2A");lcd_putstr(lcd);
					delay_ms(100);
					BW_Navi(ROOM_1B,ROOM_2A);
				}

				else if(ROOM[2]== ROOM_1C)
				{
					lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R2A");lcd_putstr(lcd);
					delay_ms(100);
					BW_Navi(ROOM_1C,ROOM_2A);
				}

			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,ROOM_4A);
			}
			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,ROOM_4B);
			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_2AB
		else if ( (ROOM[2]== ROOM_2A) || (ROOM[2]== ROOM_2B) )
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,HALLWAY_SC);
			}

			else if( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2AB TO R1BC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2B,ROOM_1B);

			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,ROOM_3);

			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,ROOM_4A);
			}
			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,ROOM_4B);
			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_3
		else if (ROOM[2]== ROOM_3)
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,HALLWAY_SC);
			}

			else if ( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R1B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_1B);

			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_2A);

			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_4A);

			}

			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_4B);

			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_4A
		else if (ROOM[2]== ROOM_4A)
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,HALLWAY_SC);
			}

			else if ( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,ROOM_1A);

			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,ROOM_2A);

			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,ROOM_3);

			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_4B
		else if (ROOM[2]== ROOM_4B)
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,HALLWAY_SC);
			}

			else if ( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO R1A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,ROOM_1B);

			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,ROOM_2A);

			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,ROOM_3);

			}
		}

		// Everything's Alright~ *I hope
		return 0;
	}

	//Return Error Code
	else
	{
		BW_Buzz(2);
		lcd_gotoxy(0,1);sprintf(lcd,"ROUTE ERROR");lcd_putstr(lcd);
		delay_ms(100);

		while(1)
		{
			BW_Buzz(1);
//			mov_static();
			Dynamx_Mov_Static(HEXSPD_ULTRAFAST,IKCALC_ENABLE);
		}
//		BW_Navi(ROOM_4B,ROOM_3);

		//BW MAP UPDATE

		RoomDetector(ROOM_COUNTER);
		BW_ReturnTrip();

		return -1;
	}
}


/* func      : void RoomType_Init(void)
 * brief     : Initialize ROOM_TYPE variables manually (for debugging purposes)
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 31th 2016)
 * Revised BY: N/A
 * programmer's Note: 	1. Setting by clicking BUTTON_A and BUTTON_B
 * 						2. Finalize decision by pressing BW_BUTTON (START BUTTON)
 */
void RoomType_Init(void)
{
	int MENU_VAR=1;

	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			BW_Buzz(2);
			while(BUTTON_A_CLICKED){};
			MENU_VAR++;
		}
		if(BUTTON_B_CLICKED)
		{
			BW_Buzz(1);
			while(BUTTON_B_CLICKED){};
			MENU_VAR--;
		}

		if(MENU_VAR>2) MENU_VAR=1;
		else if (MENU_VAR<1) MENU_VAR=2;

		switch(MENU_VAR)
		{
			case 1:
					{
						ROOM_TYPE=NORMAL_ROOM;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"NORMAL ROOM");lcd_putstr(lcd);
						delay_ms(100);
					}break;
			case 2:
					{
						ROOM_TYPE=GRAY_ROOM;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"GRAY ROOM");lcd_putstr(lcd);
						delay_ms(100);
					}break;
		}
	}
}


void BW_FlameCheck(void)
{

	static int right=90,left=90;

	generate_movement_data(0,0,9);
	delay_ms(50);


	Get_UV();
	if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//	if(FlameSense[0]!=0){FIRE=1; }

		while(right>=10&&left<=170)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//			Send_FlameSense();
//			if(FlameSense[0]!=0){FIRE=1;}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}

		while(right<=90&&left>=90)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//			Send_FlameSense();
//			if(FlameSense[0]!=0){FIRE=1;}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}

		while(right<=170&&left>=10)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//			Send_FlameSense();
//			if(FlameSense[0]!=0){FIRE=1;}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
		while(right>=90&&left<=90)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//			Send_FlameSense();
//			if(FlameSense[0]!=0){FIRE=1;}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(1,1);sprintf(lcd,"FLAME  MONITOR");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"UV_state: %d",UV_state);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"FlameSense[0]: %d",FlameSense[0]);lcd_putstr(lcd);
		delay_ms(100);
}


void BW_CandleScan(void)
{
	static int right=90,left=90;
	int OVERRIDE=0;
	generate_movement_data(0,0,9);
	delay_ms(50);

	while(OVERRIDE==0)
	{
		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED) &&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		while(right>=10&&left<=170 &&(OVERRIDE==0))
		{
			Get_IR();
			if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
				(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
				(FlameSense[0]==3)
			  )
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);

		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


		while(right<=90&&left>=90&&(OVERRIDE==0))
		{
			Get_IR();
			if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
				(INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)&&
				(FlameSense[0]==3)
			  )
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


		while(right<=170&&left>=10&&(OVERRIDE==0))
		{
			if(
				(
						((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
						((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
				)&&
				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
				(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
				(FlameSense[0]==3)
			  )
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


		while(right>=90&&left<=90&&(OVERRIDE==0))
		{
			Get_IR();
//			if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//				(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//			  )
			if(
				(
						((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
						((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
				)&&
				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
				(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
				(FlameSense[0]==3)
			  )
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);
		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


		OVERRIDE=1;
	}


//	while(1)
//	{
//		BW_Buzz(3);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"CANDLE FOUND");lcd_putstr(lcd);
//		delay_ms(100);
//	}

}


void FollowCandle (void)
{
	int counter=0;
	FlameSense_PID_Init();

	UV_Lock=UVLOCK_ACTIVE;

	FlameTracking_New();

	for(counter=1;counter<=3;counter++)
	{
		FlameApproach();
		Get_IR();
		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
		  )
		{
//			if(FlameSense[0]!=3)
//			{
//				FollowCandle();
//			}
//			else
//			{
//				{BW_Buzz(2);CANDLE_STAT=1;break;}
//			}
			if(FlameSense[0]==3)
			{
				{BW_Buzz(2);CANDLE_STAT=1;break;}
			}
		}

	}

	BW_CandleScan();

//	if(CANDLE_STAT==1)
//	{
//		while(1)
//		{
//			BW_Buzz(3);
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"CANDLE FOUND");lcd_putstr(lcd);
//			delay_ms(100);
//		}
//
//	}
}

void CandleScan2(void)
{
	int OVERRIDE=0;
	generate_movement_data(0,0,10);
	delay_ms(50);
	while(OVERRIDE==0)
	{
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		Get_IR();
		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
		  )
		{BW_Buzz(2);OVERRIDE=1;break;}
	}

	while(1)
	{
		BW_Buzz(3);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"CANDLE FOUND");lcd_putstr(lcd);
		delay_ms(100);
	}
}


void BW_FlameDemo(void)
{
	UV_Lock=1;
	while(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(2);
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();

		BW_Buzz(2);
		FollowCandle();

		BW_Buzz(2);
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();

		BW_Buzz(2);
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FLAME SCANNING");lcd_putstr(lcd);
		delay_ms(100);

		BW_FlameScanning();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		BW_FlameScanning();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		BW_FlameScanning();
	}

	mov_celebrate();

}

/* func      : int FireFight_FrontDetector(void)
 * brief     : Detect Wall or furniture in BW_FireFight Algorithm
 * param     : N/A
 * retval    : integer
 * 				1 -> Wall Detected
 * 				0 -> Wall not Detected
 * Ver       : 1
 * written By: Ryan (Saturday, April 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int FireFight_FrontDetector(void)
{
	Get_IR();
//	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* func      : int FireFight_FlameDetector(int MODE)
 * brief     : Detect Wall or furniture in BW_FireFight Algorithm
 * param     : int MODE
 * 					1 -> Candle Absence Detector
 * 					2 -> Candle Presence Detector
 *
 * retval    : integer
 * 				1 -> ACTIVE
 * 				0 -> INACTIVE
 * Ver       : 1
 * written By: Ryan (Saturday, April 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int FireFight_FlameDetector(int MODE)
{

	switch(MODE)
	{
		case 1:
				{
//					if((FlameSense[0]==2) || (FlameSense[0]==3) || (FlameSense[0]==4))
//					if((FlameSense[0]==3) || (FlameSense[0]==4))
					if((FlameSense[0]==3))
//					if( (FlameSense[0]==3) )
					{
						return 1; break;
					}
					else
					{
						return 0; break;
					}
				}break;

		case 2:
				{
//					if((FlameSense[0]!=2) && (FlameSense[0]!=3) && (FlameSense[0]!=4))
//					if((FlameSense[0]!=3) && (FlameSense[0]!=4))
					if((FlameSense[0]!=3))
//					if( (FlameSense[0]!=3) )
					{
						return 1;break;
					}
					else
					{
						return 0; break;
					}
				}break;
	}
return 0;

}

void FireFight_CandleStickDetector(void)
{
	int CANDLE=0;

//	FlameApproach();
	Get_IR();
	GetFlame();

	if(FLAME_SENSOR[FLM_ANALOG]>=200)
	{
		CANDLE=1;
	}

	if (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		CANDLE=1;
	}


	if( (CANDLE==1)	&&
		(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
		(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
	  )
	{
		CANDLE_STICK=1;
	}
}

void FireFight_CandleFireDetector(void)
{

	if(CANDLE_STICK==1)
	{
//		if ( (FlameSense[0]==2) || (FlameSense[0]==3) || (FlameSense[0]==4) ) CANDLE_FIRE=1;
		if ( (FlameSense[0]==3)  )
		{
//			GetFlame();
//			if(FLAME_SENSOR[FLM_ANALOG]<=200)
//			{
//				mov_fwd_5cm(5,FAST_LEVEL_3);
//			}
//			else
//			{
				CANDLE_FIRE=1;
//			}

		}
	}
}



void BW_CandleScanExecute(void)
{
		static int right=90,left=90;
		int OVERRIDE=0;
		generate_movement_data(0,0,10);
		delay_ms(50);


		while(OVERRIDE==0)
		{
			Get_IR();
			GetFlame();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

			while(right>=10&&left<=170 &&(OVERRIDE==0))
			{
				Get_IR();
				if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//				if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
				{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

				inv_kine(front_left,left,7,leg);
				inv_kine(front_right,right,7,leg);
				inv_kine(middle_left,left,7,leg);
				inv_kine(middle_right,right,7,leg);
				inv_kine(rear_left,left,7,leg);
				inv_kine(rear_right,right,7,leg);
				delay_ms(13);
				right-=2;
				left+=2;
			}
			delay_ms(50);

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}


			while(right<=90&&left>=90&&(OVERRIDE==0))
			{
				Get_IR();
				if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//				if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
				{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

				inv_kine(front_left,left,7,leg);
				inv_kine(front_right,right,7,leg);
				inv_kine(middle_left,left,7,leg);
				inv_kine(middle_right,right,7,leg);
				inv_kine(rear_left,left,7,leg);
				inv_kine(rear_right,right,7,leg);
				delay_ms(13);
				right+=2;
				left-=2;
			}
			delay_ms(50);

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}


			while(right<=170&&left>=10&&(OVERRIDE==0))
			{
				Get_IR();
				if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//				if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
				{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

				inv_kine(front_left,left,7,leg);
				inv_kine(front_right,right,7,leg);
				inv_kine(middle_left,left,7,leg);
				inv_kine(middle_right,right,7,leg);
				inv_kine(rear_left,left,7,leg);
				inv_kine(rear_right,right,7,leg);
				delay_ms(13);
				right+=2;
				left-=2;
			}
			delay_ms(50);

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

			while(right>=90&&left<=90&&(OVERRIDE==0))
			{
				Get_IR();
				if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//				if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
				{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

				inv_kine(front_left,left,7,leg);
				inv_kine(front_right,right,7,leg);
				inv_kine(middle_left,left,7,leg);
				inv_kine(middle_right,right,7,leg);
				inv_kine(rear_left,left,7,leg);
				inv_kine(rear_right,right,7,leg);
				delay_ms(13);
				right-=2;
				left+=2;
			}
			delay_ms(50);

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

			OVERRIDE=1;
		}
}


void BW_FlameFollowDemo(void)
{
	int counter;
//	int PINPOINT_COUNTER;

//	FlameSense_PID_Init();
	FlameSenseDigi_PID_Init();

	int WALL_STAT;
	int FLAME_PRESENCE;
	int FLAME_ABSENCE;

	Get_UV();

	while(UV_state==UVSTATE_INACTIVE)
	{
		Get_UV();
//		mov_static();
		Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_ENABLE);
	}
		CANDLE_STICK=0;
		CANDLE_FIRE=0;
		FIRE_LED_BLINK_ON;

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_Ver3();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
		}





		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				//FLAME APPROACH
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
				delay_ms(1000);

				GetFlame();
				if( (Ping[PING_FRONT]<=15) && ((FlameSense[0]==3)) )
				{
					CANDLE_FIRE=1;
				}

				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);


				while(
						( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
						(CANDLE_FIRE==0)
					 )
				{
					for(counter=1;counter<=2;counter++)
					{
						GetFlame();
						if( (Ping[PING_FRONT]<=15) && ((FlameSense[0]==3)) )
						{
							CANDLE_FIRE=1;
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
						delay_ms(100);
						FlameApproach();

						GetFlame();
						if(FLAME_SENSOR[FLM_ANALOG]>=180)
						{
							CANDLE_FIRE=1;
							break;
						}

						//ITERATION BREAKER
						WALL_STAT= FireFight_FrontDetector();
						FLAME_PRESENCE= FireFight_FlameDetector(1);
						if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
						{
							break; //EXIT FROM ITERATION
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();
						if(CANDLE_FIRE==1)
						{
							break;
						}

						GetFlame();
						if( (Ping[PING_FRONT]<=13) && ((FLAME_SENSOR[FLM_ANALOG]>=180) && (FlameSense[0]==3)) )
						{
							CANDLE_FIRE=0;
							break;
						}

					}

					GetFlame();
					if( (Ping[PING_FRONT]<=13) && ((FLAME_SENSOR[FLM_ANALOG]>=100) && (FlameSense[0]==3)) )
					{
						CANDLE_FIRE=0;
						break;
					}

					GetFlame();
					if(FLAME_SENSOR[FLM_ANALOG]>=100)
					{
						CANDLE_FIRE=1;
						break;
					}



					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
					delay_ms(100);
//-------
					FlameTracking_New();

					BW_CandleScan();

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"CANDLE DETECTED!");lcd_putstr(lcd);
						delay_ms(500);
						break;
					}

					//CONTROL VARIABLE UPDATES
					WALL_STAT= FireFight_FrontDetector();
					FLAME_ABSENCE= FireFight_FlameDetector(2);
				}
			}



		}


	if(CANDLE_FIRE==1)
	{

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
		delay_ms(100);
		BW_BLDC_Fight();
		BW_BLDC_Extinguish();


		UVLock_Refresh();
		while(UV_Lock==UVLOCK_ACTIVE)
		{
			GetFlame();
			if( (FLAME_SENSOR[FLM_ANALOG]<=180) && (Ping[PING_FRONT]>=15))
			{
//				mov_fwd_5cm(5,FAST_LEVEL_3);
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

			if(Ping[PING_FRONT]<=12)
			{
//				mov_bwd(5,FAST_LEVEL_3);
				mov_bwd_3cm(3,FAST_LEVEL_3);
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();


			//RE-CHECKING
			BW_CandleScan();
			FireFight_CandleStickDetector();
			FireFight_CandleFireDetector();
			if(CANDLE_FIRE==0)
			{
				//FLAME APPROACH
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
				delay_ms(1000);

				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);


				while(
						( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
						(CANDLE_FIRE==0)
					 )
				{
					for(counter=1;counter<=2;counter++)
					{
						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
						delay_ms(100);
						FlameApproach();

						GetFlame();
						if(FLAME_SENSOR[FLM_ANALOG]>=100)
						{
							CANDLE_FIRE=1;
							break;
						}

						//ITERATION BREAKER
						WALL_STAT= FireFight_FrontDetector();
						FLAME_PRESENCE= FireFight_FlameDetector(1);
						if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
						{
							break; //EXIT FROM ITERATION
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}
					}

					GetFlame();
					if(FLAME_SENSOR[FLM_ANALOG]>=100)
					{
						CANDLE_FIRE=1;
						break;
					}

					BW_CandleScan();

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"CANDLE DETECTED!");lcd_putstr(lcd);
						delay_ms(2000);
						break;
					}


					//CONTROL VARIABLE UPDATES
					WALL_STAT= FireFight_FrontDetector();
					FLAME_ABSENCE= FireFight_FlameDetector(2);
				}
			}

			if((Ping[PING_LEFT]<=7)|| (Ping[PING_RIGHT]<=7) )
			{
				BW_Buzz(1);

				Evade_Wall();

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				delay_ms(100);
				FlameTracking_New();
			}

/////////////////////////////////////////////////////////////////////////////////
			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

//			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=20))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) ) && (Ping[PING_LEFT]>=20))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//			if(Ping[PING_FRONT]<=20)
//			{
//				while(Ping[PING_FRONT]<=20)
//				{
//					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
//				}
//			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();
/////////////////////////////////////////////////////////////////////////////////


			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

//			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);

			BW_Buzz(1);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;


//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;


		}
	}

	else if (CANDLE_FIRE==0)
	{
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"CORNER CANDLE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DETECTED!");lcd_putstr(lcd);
			delay_ms(100);

			/*
			 *  MANDATORY SEQUENCES
			 */

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();


			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(3,0);sprintf(lcd,"CREATE SPACES");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);

/////////////////////////////////////////////////////////////////////////////////
			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

//			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=20))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )&& (Ping[PING_LEFT]>=20))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//
//			if(Ping[PING_FRONT]<=20)
//			{
//				while(Ping[PING_FRONT]<=20)
//				{
//					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
//				}
//			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();
/////////////////////////////////////////////////////////////////////////////////

		}




	//	while(FlameSense[0]!=0)
		while(UV_Lock==UVLOCK_ACTIVE)
		{

			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=25))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )&& (Ping[PING_LEFT]>=25))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//----------------------
//			if(( (Ping[PING_LEFT]<=15) || (SHARP[SHARP_LEFT]<=5) )&& (Ping[PING_RIGHT]>=25))
			if( (Ping[PING_LEFT]<=15) && (Ping[PING_RIGHT]>=25))
			{
//				while( (Ping[PING_LEFT]<=15) || (SHARP[SHARP_LEFT]<=5) )
				while (Ping[PING_LEFT]<=15)
				{
//					mov_deflect_right(FAST,CLOSE);
					mov_deflect_right(FAST,CLOSE);
				}
			}

//			else if(( (Ping[PING_RIGHT]<=15) || (SHARP[SHARP_RIGHT]<=5) )&& (Ping[PING_LEFT]>=25))
			else if(( (Ping[PING_RIGHT]<=15) )&& (Ping[PING_LEFT]>=25))
			{
//				while( (Ping[PING_RIGHT]<=15) || (SHARP[SHARP_RIGHT]<=5) )
				while (Ping[PING_RIGHT]<=15)
				{
//					mov_deflect_left(FAST,CLOSE);
					mov_deflect_left(FAST,CLOSE);
				}
			}

			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			FlameTracking_New();

			//CREATING SPACES BETWEEN ROBOT AND CANDLES
			if(Ping[PING_FRONT]>15)
			{
				while(Ping[PING_FRONT]>15)
				{
//					mov_fwd_5cm(5,FAST_LEVEL_3);
					mov_fwd_5cm(5,FAST_LEVEL_3);
				}

			}
			else if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

//------------
			//FLAME APPROACH
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAMETRACKING");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			FlameTracking_New();

			BW_Buzz(5);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
			delay_ms(1000);

			WALL_STAT= FireFight_FrontDetector();
			FLAME_ABSENCE= FireFight_FlameDetector(2);


			while(
					( WALL_STAT==0) ||
					( FLAME_ABSENCE==1)
				 )
			{
				for(counter=1;counter<=2;counter++)
				{
					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						break;
					}

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
					delay_ms(100);
					FlameApproach();

					//ITERATION BREAKER
					WALL_STAT= FireFight_FrontDetector();
					FLAME_PRESENCE= FireFight_FlameDetector(1);
					if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
					{
						break; //EXIT FROM ITERATION
					}

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						break;
					}


				}


				BW_CandleScan();

				FireFight_CandleStickDetector();
				FireFight_CandleFireDetector();

				if(CANDLE_FIRE==1)
				{
					break;
				}


				//CONTROL VARIABLE UPDATES
				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);
			}


		}

	}


	EXTINGUISHER_OFF;
	EXTINGUISHED_FIRE=1;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
	delay_ms(100);

//		BW_Buzz(1);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
//		delay_ms(100);
//		FlameTracking_New();
//
//		//FLAME APPROACH
//		BW_Buzz(1);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
//		delay_ms(1000);
//
//		WALL_STAT= FireFight_FrontDetector();
//		FLAME_ABSENCE= FireFight_FlameDetector(2);
//
//
//		while(
//				( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
//				(CANDLE_FIRE==0)
//			 )
//		{
//				FireFight_CandleStickDetector();
//				FireFight_CandleFireDetector();
//
//				if(CANDLE_FIRE==1)
//				{
//					break;
//				}
//
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
//				delay_ms(100);
//				FlameApproach();
//
//				GetFlame();
//				if(FLAME_SENSOR[FLM_ANALOG]>=200)
//				{
//					CANDLE_FIRE=1;
//					break;
//				}
//
//				//ITERATION BREAKER
//				WALL_STAT= FireFight_FrontDetector();
//				FLAME_PRESENCE= FireFight_FlameDetector(1);
//				if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
//				{
//					break; //EXIT FROM ITERATION
//				}
//
//				FireFight_CandleStickDetector();
//				FireFight_CandleFireDetector();
//				if(CANDLE_FIRE==1)
//				{
//					break;
//				}
//
//				GetFlame();
//				if( (Ping[PING_FRONT]<=18) && ((FLAME_SENSOR[FLM_ANALOG]>=200) && (FlameSense[0]==3)) )
//				{
//					CANDLE_FIRE=0;
//					break;
//				}
//		}
//
//		BW_Buzz(1);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"CANDLE SCAN");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH");lcd_putstr(lcd);
//		delay_ms(100);
//		BW_CandleScanExecute();
//
//		UVLock_Refresh();
//		while(UV_Lock==UVLOCK_ACTIVE)
//		{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
//				delay_ms(100);
//				FlameTracking_New();
//
//				BW_Buzz(2);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SCANNING");lcd_putstr(lcd);
//				delay_ms(100);
//
//				BW_FlameScanning();
//
//				UVLock_Refresh();
//				if(UV_Lock==UVLOCK_INACTIVE) break;
//
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
//				delay_ms(100);
//				FlameTracking_New();
//
//				BW_FlameScanning();
//
//				UVLock_Refresh();
//				if(UV_Lock==UVLOCK_INACTIVE) break;
//
//				BW_FlameScanning();
//
//				UVLock_Refresh();
//				if(UV_Lock==UVLOCK_INACTIVE) break;
//
//		}
//
//
//
//
//
//	EXTINGUISHER_OFF;
//	EXTINGUISHED_FIRE=1;
//
//	lcd_display_clear();
//	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
//	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
//	delay_ms(100);

	mov_celebrate();

}

void BW_FlameFollowDemo_Dynamixel(void)
{
//	int counter;
//	int PINPOINT_COUNTER;

//	FlameSense_PID_Init();
	FlameSenseDigi_PID_Init();

//	int WALL_STAT;
//	int FLAME_PRESENCE;
//	int FLAME_ABSENCE;

	Get_UV();

	while(UV_state==UVSTATE_INACTIVE)
	{
		Get_UV();
//		mov_static();
		//Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	}

	CANDLE_STICK=0;
	CANDLE_FIRE=0;
	FIRE_LED_BLINK_ON;

	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
	delay_ms(100);

	FlameTracking_Ver3();

	//CHECKING WALL/FURNITURE
//		if((Ping[PING_FRONT]>30) || ((SHARP[SHARP_FRONT_R]>30) || (SHARP[SHARP_FRONT_L]>30)))
//		{
//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//			//RE-CHECKING
//			if((Ping[PING_FRONT]>30) || ((SHARP[SHARP_FRONT_R]>30) || (SHARP[SHARP_FRONT_L]>30)))
//			{
//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			}
//		}

	//FURNITURE CHECK
//		Furniture_Check();
//		if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
//		{
//			ROOM4AB_FLAG=ROOM4AB_INACTIVE;

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW FIREFIGHT");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"TRACKING");lcd_putstr(lcd);
		delay_ms(100);

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

				Get_UV();
				if(UV_state==1)break;

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

	if(((SHARP[SHARP_FRONT_R]<15)) || (SHARP[SHARP_FRONT_L]<15))
	{
		Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
	}

//		FlameTracking_Center();
//		Dynamx_Mov_Tracking(HEXSPD_MED);

	UV_R2FLAG=UV_R2FLAG_INACTIVE;

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH 1.0");lcd_putstr(lcd);
		delay_ms(100);
//		FlameTracking_Ver3();

//		FlameTracking_Center();

		Dynamx_Mov_Static(HEXSPD_MED,IKCALC_DISABLE);
//		BW_HydroPump();
//		BW_HydroPump_2();
	}

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 2.0");lcd_putstr(lcd);
		delay_ms(100);

		BW_HydroPump_2();
	}

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		Dynamx_Mov_Tracking(HEXSPD_SLOW);
		lcd_gotoxy(0,0);sprintf(lcd,"TRACKING AGAIN ");lcd_putstr(lcd);
		delay_ms(100);
		while(((SHARP[SHARP_FRONT_R]>30) && (SHARP[SHARP_FRONT_L]>30)) || (Ping[PING_FRONT]>40))
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FIRE MOVE FORWARD ");lcd_putstr(lcd);
			delay_ms(100);

			Furniture_Avoider();
			Bumper_Follow();

		//if(FlameFrontDigi[0]!=4)break;
		}
	}


	UVLock_Refresh();
	delay_ms(1000);
	UVLock_Refresh();


	if(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH 1.1");lcd_putstr(lcd);
		delay_ms(100);
//			FlameTracking_Ver3();

//			BW_HydroPump();
		BW_HydroPump_2();
	}

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 2.1");lcd_putstr(lcd);
		delay_ms(100);

		BW_HydroPump_2();
	}

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		Dynamx_Mov_Tracking(HEXSPD_SLOW);
		lcd_gotoxy(0,0);sprintf(lcd,"TRACKING AGAIN ");lcd_putstr(lcd);
		delay_ms(100);

		while((SHARP[SHARP_FRONT_R]>30) /*&& (SHARP[SHARP_FRONT_L]>30))*/ || (Ping[PING_FRONT]>40))
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FIRE MOVE FORWARD ");lcd_putstr(lcd);
			delay_ms(100);


			Furniture_Avoider();
			Bumper_Follow();

		//if(FlameFrontDigi[0]!=4)break;
		}
	}
	UVLock_Refresh();
	while(UV_Lock==UVLOCK_ACTIVE)
	{

		BW_TurnAround=INACTIVE;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				delay_ms(100);
				FlameTracking_Center();
//					Dynamx_Mov_Tracking(HEXSPD_SLOW);
			}

/////////////////////////////////////////////////////////////////////////////////

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 3");lcd_putstr(lcd);
				delay_ms(100);
//					BW_BLDC_Fight();
//					BW_HydroPump();
				BW_HydroPump_2();
			}

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 4");lcd_putstr(lcd);
				delay_ms(100);
//					BW_BLDC_Extinguish();
				BW_HydroPump_2();
			}

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				Dynamx_Mov_Tracking(HEXSPD_SLOW);

				lcd_gotoxy(0,0);sprintf(lcd,"TRACKING AGAIN ");lcd_putstr(lcd);
				delay_ms(100);

				while((SHARP[SHARP_FRONT_R]>30) /*&& (SHARP[SHARP_FRONT_L]>30))*/ || (Ping[PING_FRONT]>40))
				{
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FIRE MOVE FORWARD ");lcd_putstr(lcd);
					delay_ms(100);


					Furniture_Avoider();
					Bumper_Follow();

				//if(FlameFrontDigi[0]!=4)break;
				}
			}
			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
//					mov_rot_right(FAST_LEVEL_3,CLOSE);
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				delay_ms(100);
//					FlameTracking_Center();

				Dynamx_Mov_Tracking(HEXSPD_SLOW);

				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 5");lcd_putstr(lcd);
				delay_ms(100);
//					BW_BLDC_Fight();
				BW_HydroPump();

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 6");lcd_putstr(lcd);
					delay_ms(100);
//						BW_BLDC_Extinguish();
					BW_HydroPump_2();
				}
			}
		}
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;
	}

EXTINGUISHER_OFF;
EXTINGUISHED_FIRE=1;

BW_Buzz(2);
lcd_display_clear();
lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
delay_ms(200);
while(UV_state==UVSTATE_INACTIVE)
	{
		Get_UV();
//		mov_static();
		Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
	}
}

/*
 *  Param: TURN_LEFT, TURN_RIGHT
 */
void Nav_TurnAround(int ORIENTATION)
{
//	int i;
	switch(ORIENTATION)
	{
		case 1:
				{
					//TURN AROUND
					BW_Buzz(1);

					if((Ping[PING_LEFT]>15))// && (Ping[PING_ASKEW_LEFT]>15))
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						if((Ping[PING_LEFT]>15))// && (Ping[PING_ASKEW_LEFT]>15))
						{
							Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
							if((Ping[PING_LEFT]>15))// && (Ping[PING_ASKEW_LEFT]>15))
							{
								Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
							}
						}

					}

					if(EXTINGUISHED_FIRE==1)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
					}
					else
					{
						while((Ping[PING_LEFT]<20) || (Ping[PING_FRONT]>25))
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
					}
					if(Ping[PING_FRONT]>18)
					{
						Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
					}

					while(Ping[PING_FRONT]<20)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

//					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					if(Ping[PING_RIGHT]>18)
					{
						Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
					}
//					Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
				}break;

		case 2:
				{
					//TURN AROUND
					BW_Buzz(1);

					if((Ping[PING_RIGHT]>15))// && (Ping[PING_ASKEW_RIGHT]>15))
					{
						Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
						if((Ping[PING_RIGHT]>15))// && (Ping[PING_ASKEW_RIGHT]>15))
						{
							Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
							if((Ping[PING_RIGHT]>15))// && (Ping[PING_ASKEW_RIGHT]>15))
							{
								Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
							}
						}
					}
					if(EXTINGUISHED_FIRE==1)
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
					}
					else
					{
						while((Ping[PING_RIGHT]<20) || (Ping[PING_FRONT]>25))
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
					}
					if(Ping[PING_FRONT]>18)
					{
						Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
					}
					while(Ping[PING_FRONT]<20)
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					if(Ping[PING_LEFT]>18)
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					}
//					Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
				}break;
	}
}



void BW_BLDC_Extinguish(void)
{
//	Sendto_PC(USART1,"BW Hexapod Search Fire Sequences \r");

	BW_Buzz(4);

	static int right=90,left=90;

	BW_Buzz(4);
	BW_BLDC_ON;
	delay_ms(2000);

	generate_movement_data(0,0,9);
	delay_ms(50);

	Get_UV();

	while(right>=50&&left<=130&&UV_state==0)
	{
		inv_kine(front_left,left,7,leg);
		inv_kine(front_right,right,7,leg);
		inv_kine(middle_left,left,7,leg);
		inv_kine(middle_right,right,7,leg);
		inv_kine(rear_left,left,7,leg);
		inv_kine(rear_right,right,7,leg);
		delay_ms(20);
		right-=5;
		left+=5;
		if(UV_state==1) break;
	}
	delay_ms(100);

	Get_UV();

	while(right<=90&&left>=90&&UV_state==0)
	{
	    inv_kine(front_left,left,7,leg);
	    inv_kine(front_right,right,7,leg);
	    inv_kine(middle_left,left,7,leg);
	    inv_kine(middle_right,right,7,leg);
	    inv_kine(rear_left,left,7,leg);
	    inv_kine(rear_right,right,7,leg);
	    delay_ms(20);
	    right+=5;
	    left-=5;
	    if(UV_state==1) break;
	}
	delay_ms(100);

	Get_UV();
	while(right<=130&&left>=50&&UV_state==0)
	{
		inv_kine(front_left,left,7,leg);
		inv_kine(front_right,right,7,leg);
		inv_kine(middle_left,left,7,leg);
		inv_kine(middle_right,right,7,leg);
		inv_kine(rear_left,left,7,leg);
		inv_kine(rear_right,right,7,leg);
		delay_ms(20);
		right+=5;
		left-=5;
		if(UV_state==1) break;
	}
	delay_ms(100);

	Get_UV();
	while(right>=90&&left<=90&&UV_state==0)
	{
		inv_kine(front_left,left,7,leg);
		inv_kine(front_right,right,7,leg);
		inv_kine(middle_left,left,7,leg);
		inv_kine(middle_right,right,7,leg);
		inv_kine(rear_left,left,7,leg);
		inv_kine(rear_right,right,7,leg);
		delay_ms(20);
		right-=5;
		left+=5;
		if(UV_state==1) break;
	}
	delay_ms(100);

	BW_BLDC_OFF;

}



void FlameSenseDigi_PID_Init(void)
{
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_FLAME.P[0]=0;
	PID_FLAME.P[1]=0;
	PID_FLAME.P[2]=0;
	PID_FLAME.I[0]=0;
	PID_FLAME.I[1]=0;
	PID_FLAME.I[2]=0;
	PID_FLAME.D[0]=0;
	PID_FLAME.D[1]=0;
	PID_FLAME.D[2]=0;

	PID_FLAME.Kp=2;
	PID_FLAME.Ki=0;
	PID_FLAME.Kd=0;

	PID_FLAME.Ts=1;

	PID_FLAME.set_point=4;

	PID_FLAME.error[0]=0;
	PID_FLAME.error[1]=0;
	PID_FLAME.error[2]=0;
	PID_FLAME.pid_value[0]=0;
	PID_FLAME.pid_value[1]=0;
	PID_FLAME.pid_value[2]=0;
}

/*
 * func      : void PID_Calc(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void FlameSense_PID_Calc_Ver3(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_FLAME.pid_value[2]=PID_FLAME.pid_value[1];
	PID_FLAME.pid_value[1]=PID_FLAME.pid_value[0];

	PID_FLAME.error[2]=PID_FLAME.error[1];
	PID_FLAME.error[1]=PID_FLAME.error[0];

//	if (FlameSenseDigi[0]==8) {FlameSenseDigi[0]==4;}
	if (FlameSenseDigi[0]==PID_FLAME.set_point) {PID_FLAME.error[0]=0;}

	else if ( FlameSenseDigi[0] > PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = FlameSenseDigi[0] - PID_FLAME.set_point;
		}

	else if (FlameSenseDigi[0] < PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = PID_FLAME.set_point - FlameSenseDigi[0];
		}

	/*
	 * PID FORMULA
	 */
	PID_FLAME.P[2]= PID_FLAME.error[0]-PID_FLAME.error[2];
	PID_FLAME.P[1]= PID_FLAME.Kp;
	PID_FLAME.P[0]= PID_FLAME.P[1]*PID_FLAME.P[2]; //Proportional Controller

	PID_FLAME.I[2]= PID_FLAME.Ki*PID_FLAME.Ts/2;
	PID_FLAME.I[1]= PID_FLAME.error[0]+(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.I[0]= PID_FLAME.I[2]*PID_FLAME.I[1]; //Integral Controller

	PID_FLAME.D[2]= 2*PID_FLAME.Kd/PID_FLAME.Ts;
	PID_FLAME.D[1]= PID_FLAME.error[0]-(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.D[0]= PID_FLAME.D[2]*PID_FLAME.D[1]; //Derivative Controller

	PID_FLAME.pid_value[0]= PID_FLAME.pid_value[2] + PID_FLAME.P[0] + PID_FLAME.I[0] + PID_FLAME.D[0];
}


int FlameTracking_Ver3(void)
{
	int flametrack_cnt=0;

	while( (FlameSenseDigi[0]!=4) && (UV_Lock==UVLOCK_ACTIVE) )
	{

		PID_FlameTracking_Ver3();
		lcd_display_clear();

		flametrack_cnt++;
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"flametrack: %d",flametrack_cnt);lcd_putstr(lcd);
		if(flametrack_cnt>=35)
		{
			flametrack_cnt=0;
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"FLAMETRACKING");lcd_putstr(lcd);
			lcd_gotoxy(4,0);sprintf(lcd,"OVERFLOW");lcd_putstr(lcd);
			delay_ms(100);
			UVLock_Refresh();
		}
		if (FlameFrontDigi[0]==4)break;

//		if(FlameSenseDigi[0]==4)break;
	}
//	BW_BLDC_OFF;
	EXTINGUISHER_OFF;
	return 0;
}

/* func      : 	void FlameTracking_Center(void)
 * brief     : 	Dynamixel Hexapod Flame Tracking Center
 * param     :
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Wed, March 1 2017)
 * Revised By:
 *
 */

int FlameTracking_Center(void)
{
//	Get_TPA81();
	int CNT=0;
	int CNT_LONG=0;
//	int g;
	while(FlameFrontDigi[0]!=4)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME CENTER");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"FLAME SENSE= %d",FlameFrontDigi[0]);lcd_putstr(lcd);

		Get_TPA81();
		if(FIRE==1)break;
		if(FlameFrontDigi[0]==4)break;
//		while((FlameSenseDigi[0]!=3) || (FlameSenseDigi[0]!=2) || (FlameSenseDigi[0]!=1))
		while((FlameSenseDigi[0]!=5) || (FlameSenseDigi[0]!=6))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameFrontDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"CENTERING");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"CNT= %d",CNT);lcd_putstr(lcd);

//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE); // flame dibalik

			CNT++;
			if(CNT>20)
			{
				Get_UV();
				if(UV_state==1){CNT=0;CNT_LONG=1;break;}
			}

			Get_TPA81();
			if(FIRE==1)break;
			if(FlameFrontDigi[0]==4)break;
			if((FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6))break;
		}
		Get_TPA81();
		if(FIRE==1)break;
		if(FlameFrontDigi[0]==4)break;
		if(CNT_LONG==1)break;
		else CNT=0;
//		while((FlameSenseDigi[0]!=5) || (FlameSenseDigi[0]!=6) || (FlameSenseDigi[0]!=7))
		while((FlameSenseDigi[0]!=3) || (FlameSenseDigi[0]!=2))
		{
			//UVLock_Refresh();
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameFrontDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"CENTERING");lcd_putstr(lcd);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			CNT++;
			if(CNT>20)
				{
					Get_UV();
					if(UV_state==1){CNT=0;CNT_LONG=1;break;}
//					else if(ROOM[2]==ROOM_2A)
//					{
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"CMPS DIRECTION",FlameFrontDigi[0]);lcd_putstr(lcd);
//						lcd_gotoxy(0,3);sprintf(lcd,"CMPS= %d",CMPS11_Angle);lcd_putstr(lcd);
//
//						delay_ms(100);
//						GetCMPS11_Angle8Bit();
//						if (CMPS11_Angle>R4A_THRESHOLD_MIDDLE || CMPS11_Angle<R4A_THRESHOLD_MIDDLE)
//						{
//							lcd_display_clear();
//							lcd_gotoxy(0,0);sprintf(lcd,"CMPS DIRECTION",FlameFrontDigi[0]);lcd_putstr(lcd);
//							lcd_gotoxy(0,3);sprintf(lcd,"CMPS= %d",CMPS11_Angle);lcd_putstr(lcd);
//
//							delay_ms(100);
//
//							GetCMPS11_Angle8Bit();
//							while((CMPS11_Angle>R4A_THRESHOLD_MIDDLE) || (CMPS11_Angle<R4B_THRESHOLD_MIDDLE))
//							{
//								lcd_display_clear();
//								lcd_gotoxy(0,0);sprintf(lcd,"CMPS DIRECTION",FlameFrontDigi[0]);lcd_putstr(lcd);
//								lcd_gotoxy(0,3);sprintf(lcd,"CMPS= %d",CMPS11_Angle);lcd_putstr(lcd);
//
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								GetCMPS11_Angle8Bit();
//							}
//						}
//						else
//						{
//
//
//							lcd_display_clear();
//							lcd_gotoxy(0,0);sprintf(lcd,"CMPS DIRECTION",FlameFrontDigi[0]);lcd_putstr(lcd);
//							lcd_gotoxy(0,3);sprintf(lcd,"CMPS= %d",CMPS11_Angle);lcd_putstr(lcd);
//
//							delay_ms(100);
//
//							GetCMPS11_Angle8Bit();
//							while((CMPS11_Angle<R4A_THRESHOLD_MIDDLE) && (CMPS11_Angle>R4B_THRESHOLD_MIDDLE))
//							{
//								lcd_display_clear();
//								lcd_gotoxy(0,0);sprintf(lcd,"CMPS DIRECTION",FlameFrontDigi[0]);lcd_putstr(lcd);
//								lcd_gotoxy(0,3);sprintf(lcd,"CMPS= %d",CMPS11_Angle);lcd_putstr(lcd);
//
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								GetCMPS11_Angle8Bit();
//							}
//						}
//
//						while(FlameFrontDigi[0]!=4)
//						{
//							TRACER_STAT=TRACER_BLACK;
//							BW_FollowCounter_Left(1);
//
////							if(g>1)
////							{
//								TCSlave_Check();
//								if (TRACER_STAT==TRACER_WHITE)
//								{
//									lcd_display_clear();
//									lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
//									lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
//									delay_ms(50);
//									Dynamx_MovBwd(8,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//									Nav_TurnAround(TURN_RIGHT);
//									Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
////									break;
//								}
//								TCSlave_Check();
//
//								if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5))CNT=0;break;
//								if(FlameFrontDigi[0]==4)CNT=0;break;
////							}
//						}
//					}
				}

			Get_TPA81();
			if(FIRE==1)break;
			if(FlameFrontDigi[0]==4)break;
			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==2))break;
		}

		if(CNT_LONG==1)break;
		else CNT=0;
		Get_TPA81();
		if(FIRE==1)break;
		if(FlameFrontDigi[0]==4)break;
		UVLock_Refresh();
		if(UV_state==1)break;
		if(UV_Lock==UVLOCK_INACTIVE)break;
	}
	return 0;
}

/* func      : 	void FlameTracking_Center(void)
 * brief     : 	Dynamixel Hexapod Flame Tracking Center
 * param     :
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Wed, March 1 2017)
 * Revised By:
 *
 */

int FlameTracking_Center_FAR(void)
{
	while(FlameFrontDigi[0]!=4)//(suhu_pixel[3]<60 || suhu_pixel[2]<60))
	{
		if(FlameFrontDigi[0]==4)break;//(suhu_pixel[3]>60 || suhu_pixel[2]>60))break;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME CENTER FAR");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"FLAME SENSE= %d",FlameFrontDigi[0]);lcd_putstr(lcd);

//		while((FlameSenseDigi[0]!=3) || (FlameSenseDigi[0]!=2) || (FlameSenseDigi[0]!=1))
		while((FlameSenseDigi[0]!=5) || (FlameSenseDigi[0]!=6))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameFrontDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(1,0);sprintf(lcd,"CENTERING");lcd_putstr(lcd);

//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE); // flame dibalik

//			if(SHARP[SHARP_FRONT_R]<20)//((SHARP[SHARP_FRONT_R]<18) || (SHARP[SHARP_FRONT_L]<18))
//			{
//				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//			}

//			if(CNT1>=30)
//			{
//				if(FIRESCAN_DIRECTION==SCAN_RIGHT)
//				{
//					while(FlameSenseDigi[0]==0)
//					{
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"LONG CENTERING !!");lcd_putstr(lcd);
//						BW_FollowCounter_Left(1);
//					}
//
//				}
//				else if(FIRESCAN_DIRECTION==SCAN_LEFT)
//				{
//					while(FlameSenseDigi[0]==0)
//					{
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"LONG CENTERING !!");lcd_putstr(lcd);
//						BW_FollowCounter_Right(1);
//					}
//				}
//				Get_UV();
//				if(UV_state==1)break;
//			}
//			CNT1++;
			if(FlameFrontDigi[0]==4)break;//(suhu_pixel[3]>60 || suhu_pixel[2]>60))break;
//			if(FlameFrontDigi[0]==4)break;
			if((FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6))break;
		}
		if(FlameFrontDigi[0]==4)break;//(suhu_pixel[3]>60 || suhu_pixel[2]>60))break;
//		if(FlameFrontDigi[0]==4)break;

//		while((FlameSenseDigi[0]!=5) || (FlameSenseDigi[0]!=6) || (FlameSenseDigi[0]!=7))
		while((FlameSenseDigi[0]!=3) || (FlameSenseDigi[0]!=2))
		{
			//UVLock_Refresh();
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameFrontDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,0);sprintf(lcd,"CENTERING");lcd_putstr(lcd);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

//			if(SHARP[SHARP_FRONT_R]<20)//((SHARP[SHARP_FRONT_R]<18) || (SHARP[SHARP_FRONT_L]<18))
//			{
//				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//			}

//			if(CNT1>=30)
//			{
//				if(FIRESCAN_DIRECTION==SCAN_RIGHT)
//				{
//					while(FlameSenseDigi[0]==0)
//					{
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"LONG CENTERING !!");lcd_putstr(lcd);
//						BW_FollowCounter_Left(1);
//					}
//
//				}
//				if(FIRESCAN_DIRECTION==SCAN_LEFT)
//				{
//					while(FlameSenseDigi[0]==0)
//					{
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"LONG CENTERING !!");lcd_putstr(lcd);
//						BW_FollowCounter_Right(1);
//					}
//
//				}
//				Get_UV();
//				if(UV_state==1)break;
//			}
//			CNT1++;
			if(FlameFrontDigi[0]==4)break;//(suhu_pixel[3]>60 || suhu_pixel[2]>60))break;
//			if(FlameFrontDigi[0]==4)break;
			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==2))break;
		}
		if(FlameFrontDigi[0]==4)break;//(suhu_pixel[3]>60 || suhu_pixel[2]>60))break;
//		if(FlameFrontDigi[0]==4)break;
		UVLock_Refresh();
		if(UV_state==1)break;
		if(UV_Lock==UVLOCK_INACTIVE)break;
	}
	return 0;
}

int PID_FlameTracking_Ver3(void)
{
//	float DUMMY_PIDVALUE=1;

	//OVERCOMING BLIND SPOTS
	if(FlameSenseDigi[0]==0) FlameSenseDigi[0]=10;

	FlameSense_PID_Calc_Ver3();

	//KONDISI ROBOT SESUAI
	if ( FlameSenseDigi[0]==PID_FLAME.set_point)
	{
		FlameTrack_Flag=FLAG_ACTIVE;
	}

	else if(FlameSenseDigi[0]==10)
	{
		if ( (FlameSenseDigi[1]==10) || (FlameSenseDigi[1]==0) )
		{
//			Rot_Right_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
			Dynamx_Rot_Right_PID(HEXSPD_FAST,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
//			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}
		else if( (FlameSenseDigi[1]==1) )
		{
			UVLock_Refresh();
//			Rot_Left_PID(FAST, CLOSE, &DUMMY_PIDVALUE);
			Dynamx_Rot_Left_PID(HEXSPD_FAST,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
//			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSenseDigi[1]==7) )
		{
			UVLock_Refresh();
//			Rot_Right_PID(FAST, CLOSE, &DUMMY_PIDVALUE);
			Dynamx_Rot_Right_PID(HEXSPD_FAST,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
//			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] > PID_FLAME.set_point )
		{
//			Rot_Right_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
			Dynamx_Rot_Right_PID(HEXSPD_FAST,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
//			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] < PID_FLAME.set_point )
		{
//			Rot_Left_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
			Dynamx_Rot_Left_PID(HEXSPD_FAST,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
//			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}
	}

	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSenseDigi[0] > PID_FLAME.set_point )
	{
//		Rot_Right_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
		Dynamx_Rot_Right_PID(HEXSPD_FAST,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
		FlameSenseDigi[1]=7;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSenseDigi[0] < PID_FLAME.set_point )
	{
		FlameSenseDigi[1]=1;
//		Rot_Left_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
		Dynamx_Rot_Left_PID(HEXSPD_FAST,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);

	}
	return 0;

}


/* func      : int FlameApproach(void)
 * brief     : BW Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
int FlameApproach_Ver2(void)
{
	Get_UV();
	Evade_Wall_Room();
	PID_FlameApproach_Ver2();




	return 0;
}


/* func      : int PID_FlameApproach(void)
 * brief     : Calculating and actuating kinematics for Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called FlameApproach() function
 *
 */
int PID_FlameApproach_Ver2(void)
{
	float DUMMY_PIDVALUE=5;

	//OVERCOMING BLIND SPOTS
	if(FlameSenseDigi[0]==0) FlameSenseDigi[0]=7;

	FlameSense_PID_Calc_Ver3();

	//KONDISI ROBOT SESUAI
	if ( FlameSenseDigi[0]==PID_FLAME.set_point)
	{
		mov_fwd_5cm(10,FAST_LEVEL_3);
		BW_BLDC_ON;
		delay_ms(4000);
		BW_BLDC_OFF;
	}

	else if(FlameSenseDigi[0]==7)
	{

		if ( (FlameSenseDigi[1]==0) || (FlameSenseDigi[1]==7) )
		{
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if( (FlameSenseDigi[1]==1) )
		{
//			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSenseDigi[1]==7) )
		{
//			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] > PID_FLAME.set_point )
		{
			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] < PID_FLAME.set_point )
		{
			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}



	}
	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSenseDigi[0] > PID_FLAME.set_point )
	{
		if (PID_FLAME.pid_value[0]>10) PID_FLAME.pid_value[0]=10; //WINDUP

		CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSenseDigi[1]=7;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSenseDigi[0] < PID_FLAME.set_point )
	{
		if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP


		CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSenseDigi[1]=1;

	}
	return 0;
}

/* func      : int FireFight_FrontDetector(void)
 * brief     : Detect Wall or furniture in BW_FireFight Algorithm
 * param     : N/A
 * retval    : integer
 * 				1 -> Wall Detected
 * 				0 -> Wall not Detected
 * Ver       : 1
 * written By: Ryan (Saturday, April 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int FireFight_FrontDetector_Ver2(void)
{
	Get_IR();
	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* func      : int FireFight_FlameDetector(int MODE)
 * brief     : Detect Wall or furniture in BW_FireFight Algorithm
 * param     : int MODE
 * 					1 -> Candle Absence Detector
 * 					2 -> Candle Presence Detector
 *
 * retval    : integer
 * 				1 -> ACTIVE
 * 				0 -> INACTIVE
 * Ver       : 1
 * written By: Ryan (Saturday, April 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int FireFight_FlameDetector_Ver2(int MODE)
{
	switch(MODE)
	{
		case 1:
				{
					if((FlameSenseDigi[0]==4))
					{
						return 1; break;
					}
					else
					{
						return 0; break;
					}
				}break;

		case 2:
				{
					if((FlameSenseDigi[0]!=4))
					{
						return 1;break;
					}
					else
					{
						return 0; break;
					}
				}break;
	}
	return 0;
}

void FireFight_CandleStickDetector_Ver2(void)
{
	int CANDLE=0;

	Get_IR();
	GetFlame();

	if(FlameFrontDigi[0]>=200)
	{
		CANDLE=1;
	}

	if (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (CANDLE==1)	&&
		(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
		(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
	  )
	{
		CANDLE_STICK=1;
	}
}

void FireFight_CandleFireDetector_Ver2(void)
{
	if(CANDLE_STICK==1)
	{
		if ( (FlameSenseDigi[0]==4)  )
		{
				CANDLE_FIRE=1;
		}
	}
}


/* func      : void H_2017_Algorithm(void)
 * brief     : BW 2017 Level 1 Trial Algorithm
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Hafidin (MISSING NOTES)
 * Revised BY: Ver.2.Toni(Friday,1 Dec 2016)
 * 			   Ver.3 Hafidin(Monday, 6 march 2017)
 * 			   Ver.4 Hafidin (Tue, May 2nd 2017)
 * programmer's Note:
 */
void H_2017_Algorithm(void)
{
	int Error_Code=1;
//	int d;
	EXTINGUISHER_OFF;

	//REVERSE FLAG
	REVERSE_FLAG=REVERSEFLAG_INACTIVE;
	SP_FIRE_1B=SP_FIRE_INACTIVE;

	BW_LOCATION[0]= LOCATION_ROOM;
	ROOM_COUNTER = 1;


//		Escape_Home_2017();
//		SND_ACT_LED_OFF;

		RoomTypeDetector();

		BW_Home_Detection_2017_3();

			if(ROOM_TYPE==GRAY_ROOM)
			{
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
				RoomTypeDetector();
			}

			if(FOLLOW_FLAG==KIRI)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW TRACER :");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"LEFT");lcd_putstr(lcd);
				delay_ms(50);

//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				BW_PID_Init_Room();
				BW_FollowTracer_Left();
			}
			else
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW TRACER :");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"RIGHT");lcd_putstr(lcd);
				delay_ms(50);

//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//				if((ROOM_TYPE==GRAY_ROOM)&&(HOME_POS==POJOK))
//				{
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				}
//				BW_PID_Init();
				BW_PID_Init_Room();
				BW_FollowTracer_Right();

			}

//===========HOME CHECK============//
//			Dynamx_MovFwd4cm(20,HEXSPD_MEDFAST,IKCALC_DISABLE);
			if(ROOM_TYPE==GRAY_ROOM)
			{
				if(Ping[PING_RIGHT]<10)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					if(Ping[PING_RIGHT]<10)
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					}
				}
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
			else
			{
//				if(ROOM1A_SP_EXIT_FLAG==FLAG_ACTIVE)
//				{
//					if((Ping[PING_LEFT])>(Ping[PING_REAR_LEFT]))
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_LEFT])>(Ping[PING_REAR_LEFT]))
//						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT]))
//							{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							}
//						}
//					}
//					else
//					{
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_LEFT])<(Ping[PING_REAR_LEFT]))
//						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
////							if((Ping[PING_LEFT])<(Ping[PING_REAR_LEFT]))
////							{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
////							}
//						}
//					}
//				}
//				else
//				{
//					if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT]))
//					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT]))
//						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
////						if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT]))
////						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
////						}
//						}
//					}
					if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
//							{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							}
						}
					}
//				}
//				if(Ping[PING_RIGHT]<10)
//				{
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					if(Ping[PING_RIGHT]<10)
//					{
//						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					}
//				}

				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
//				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
//				TCSlave_Check();
//
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE)
//			{
////				BW_PID_Init_Room();
//				if(FOLLOW_FLAG==KIRI)
//				{
//					lcd_display_clear();
//					lcd_gotoxy(0,0);sprintf(lcd,"HoMe");lcd_putstr(lcd);
//					lcd_gotoxy(0,1);sprintf(lcd,"DeTeCtEd");lcd_putstr(lcd);
//					delay_ms(50);
//
//					BW_PID_Init_Furniture();
//					BW_FollowCounter_Left(10);
//
//					lcd_display_clear();
//					lcd_gotoxy(0,0);sprintf(lcd,"I'M FREE");lcd_putstr(lcd);
//					delay_ms(50);
//
//					BW_PID_Init();
//					BW_FollowTracer_Left();
////					FOLLOW_FLAG=KIRI;
//				}
//				else
//				{
//					lcd_display_clear();
//					lcd_gotoxy(0,0);sprintf(lcd,"HoMe");lcd_putstr(lcd);
//					lcd_gotoxy(0,1);sprintf(lcd,"DeTeCtEd");lcd_putstr(lcd);
//					delay_ms(50);
//
//					BW_PID_Init_Furniture();
//					BW_FollowCounter_Right(10);
//
//					lcd_display_clear();
//					lcd_gotoxy(0,0);sprintf(lcd,"I'M FREE");lcd_putstr(lcd);
//					delay_ms(50);
//
//					BW_PID_Init();
//					BW_FollowTracer_Right();
////					FOLLOW_FLAG=KANAN;
//				}
//			}
//
//			Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);

//================================================================//
//
//			int jarak;
//			if(Ping[PING_LEFT]<Ping[PING_RIGHT])
//			{
//				jarak=Ping[PING_RIGHT]-Ping[PING_LEFT];
//			}
//			else
//			{
//				jarak=Ping[PING_LEFT]-Ping[PING_RIGHT];
//			}
//
//			if(jarak<30)
//			{
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"HOME");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
//				delay_ms(100);
//
//				TCSlave_Check();
//				BW_PID_Init_Room();
//
//				while( (TCS3200_SLV_DATA[0]==COLOUR_WHITE) || (TCS3200_SLV_DATA[1]==TRACER_WHITE) )
//				{
//					BW_FollowCounter_Right(3);
//				}
//
//				BW_PID_Init_Room();
//				BW_FollowTracer_Right();
//
//				Dynamx_MovFwd4cm(20,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			}

//=======================//

		if(FOLLOW_FLAG==KIRI)
		{
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			if(Ping[PING_ASKEW_LEFT]>25)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
		}
		else if (FOLLOW_FLAG==KANAN)
		{
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			if(Ping[PING_LEFT]<20)
//			{
//				while(Ping[PING_LEFT]<20)
//				{
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				}
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			}
//			if((Ping[PING_REAR_LEFT]>20) && (Ping[PING_ASKEW_LEFT]<20))
//			{
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			}
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		}

		FOLLOW_FLAG=KOSONG;
// JIKA KELUAR MIRING DI RUANG 4
		if(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
		//H_Correction_ExitRoom();

	BW_LOCATION[1]=BW_LOCATION[0];
	BW_LOCATION[0]=LOCATION_CORRIDOR;

		RoomDetector(ROOM_COUNTER);

	int CNT = 0;

	while(EXTINGUISHED_FIRE==0)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"CNT= %d",CNT);lcd_putstr(lcd);
//			delay_ms(50);

//			switch(ROOM[ROOM_COUNTER])
//			{
//				case ROOM_1A :	{	H_ROOM_1A();	}break;
//
//				case ROOM_1B :	{	H_ROOM_1BC();	}break;
//
//				case ROOM_1C :	{	H_ROOM_1BC();	}break;
//
//				case ROOM_2A :	{	H_ROOM_2();		}break;
//
//				case ROOM_2B :	{	H_ROOM_2(); 	}break;
//
//				case ROOM_3  :	{	H_ROOM_3();		}break;
//
//				case ROOM_4A :	{	H_ROOM_4A();	}break;
//
//				case ROOM_4B :	{	H_ROOM_4B();	}break;
//			}
				if(ROOM[ROOM_COUNTER]==ROOM_1A)
				{
					H_ROOM_1A();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_1B)
				{
					H_ROOM_1BC_NEW2();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_1C)
				{
					H_ROOM_1BC_NEW2();
				}
				else if(ROOM[ROOM_COUNTER]== ROOM_2A)
				{
					H_ROOM_2_NEW_VER2();
				}
				else if (ROOM[ROOM_COUNTER]==ROOM_2B)
				{
					H_ROOM_2_NEW_VER2();
				}
				else if(ROOM[ROOM_COUNTER]== ROOM_3)
				{
					H_ROOM_3_VER2();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_4A)
				{
					H_ROOM_4A_VER2();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_4B)
				{
					H_ROOM_4B_VER2();
				}
				else if(cnt>10)
				{
					RoomDetector(ROOM_COUNTER);
				}
				cnt++;
//				if(EXTINGUISHED_FIRE==1)break;
		}

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

//		if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT]))
//		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT]))
//			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
////						if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT]))
////						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
////						}
//			}
//		}
		if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_RIGHT])<(Ping[PING_REAR_RIGHT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_RIGHT])<(Ping[PING_REAR_RIGHT]))
//						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						}
			}
		}

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
		//LOCATION: CORRIDOR
		if(FOLLOW_FLAG==KIRI)
		{
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			/*
			if(Ping[PING_ASKEW_LEFT]>25)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
			*/
		}
		else if (FOLLOW_FLAG==KANAN)
		{
//			if(Ping[PING_RIGHT]>30)
//			{
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
////				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);x
//			}
		}

		FOLLOW_FLAG=KOSONG;

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

//			H_Correction_ExitRoom();

		
		//BW MAP UPDATE
		BW_Buzz(1);

//		ROOM_COUNTER++;
//			RoomDetector(ROOM_COUNTER);

		if((ROOM[2]==ROOM_1A) || (ROOM[2]==ROOM_1B) || (ROOM[2]==ROOM_1C))
		{
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			if(Ping[PING_FRONT]>40)
			{
				GetCMPS11_Angle8Bit();
				if((Ping[PING_RIGHT])<(Ping[PING_LEFT]) || ((CMPS11_Angle>(R4A_THRESHOLD_UPPER))&&(CMPS11_Angle<R4A_THRESHOLD_LOWER)))//+Ping[PING_ASKEW_LEFT]+Ping[PING_REAR_LEFT]))
				{
					ROOM[2]=ROOM_1A;
				}
				else
				{
					ROOM[2]=ROOM_1C;
				}
			}
			else
			{
				ROOM[2]=ROOM_1B;

			}
		}

			Error_Code= BW_ReturnTrip();

		if(ROOM[1]!=HALLWAY_SC)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			BW_PID_Init();
			BW_FollowCounter_Left(8);

			SND_ACT_LED_OFF;	//turn off sound led indicator
		}

		if(Error_Code==0)
		{
			BW_Buzz(5);
			int j=15;

			Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);
			delay_ms(1000);
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(j,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(j,1);sprintf(lcd,"MISSION");lcd_putstr(lcd);
				lcd_gotoxy(j,2);sprintf(lcd,"ACCOMPLISHED!");lcd_putstr(lcd);
				delay_ms(50);
				j--;
				if(j==0)j=15;

				Dynamx_Mov_Static(HEXSPD_SLOW,IKCALC_DISABLE);
//				Dynamx_Mov_Static_Low(HEXSPD_ULTRASLOW);
			}
		}
		else
		{
			int j=15;

			Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_ENABLE);
			delay_ms(1000);
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(j,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(j,1);sprintf(lcd,"MISSION");lcd_putstr(lcd);
				lcd_gotoxy(j,2);sprintf(lcd,"FAILED");lcd_putstr(lcd);
				delay_ms(50);
				j--;
				if(j==0)j=15;
				BW_Buzz(1);
				Dynamx_Mov_Static(HEXSPD_SLOW,IKCALC_ENABLE);
//				Dynamx_Mov_Static_Low(HEXSPD_ULTRASLOW);
			}
		}
}

/* func      : void H_2017_Room (void)
 * brief     : BW 2017 Room Algorithm
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * 				Ver.2. - Toni (Thursday, December 1st 2016)
 * 				Ver.3. - Ryan (Friday, December 2nd 2016)
 * 				Ver.4. - Ryan (Thursday, April 20th 2017)
 * 				Ver.5. - Toni (Tuesday, September 12nd 2017) ==> FLAME DIBALIK
 * programmer's Note:
 */
void H_2017_Room (void)
{
//	int EXIT_STAT=0;
	int m,l;
	BW_Buzz(1);

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"ROOM");lcd_putstr(lcd);

	if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
	{
		lcd_gotoxy(0,3);sprintf(lcd,"R4AB ACTIVE");lcd_putstr(lcd);
	}

	if(SP_FIRE_1B==SP_FIRE_ACTIVE)
	{
		//		lcd_display_clear();
		//		lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
		//		delay_ms(50);
				SP_FIRE_1B=SP_FIRE_INACTIVE;

		//		for(l=0;l<=2;l++)
		//		{
		//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				}

				for(l=0;l<=1;l++)
				{
					Get_UV();
					if(UV_state==UVSTATE_ACTIVE)//|| (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
					{
						FIRE=FIRE_ON;
						UV_Lock=UVLOCK_ACTIVE;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
						lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					}
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST, IKCALC_DISABLE);
				}
		SP_FIRE_1B=SP_FIRE_ACTIVE;
	}
	else
	{
//		for(l=0;l<=2;l++)
//		{
//			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
		if(Ping[PING_ASKEW_RIGHT]<13)
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
//					lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				}
//		}
		for(l=0;l<=1;l++)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST, IKCALC_DISABLE);
			if(Ping[PING_FRONT]<=25)break;
		}

//		for(l=0;l<=5;l++)
//		{
//			Dynamx_Slide_Left(4,HEXSPD_SLOW);
//			if(Ping[PING_LEFT]<12)break;
//		}
	}

//		if((Ping[PING_LEFT]<25) && (Ping[PING_ASKEW_LEFT]<25))
//		{
//			BW_PID_Init();
//			for(l=0;l<=3;l++)
//			{
//				BW_FollowCounter_Left(1);
//				Get_UV();
//				if(UV_state==UVSTATE_ACTIVE)
//				{
//					FIRE=FIRE_ON;
//					UV_Lock=UVLOCK_ACTIVE;
//				}
//				if(Ping[PING_FRONT]<17)break;
//			}
//		}
//		else if ((Ping[PING_RIGHT]<25) && (Ping[PING_ASKEW_RIGHT]<25))
//		{
//			BW_PID_Init();
//			for(l=0;l<=3;l++)
//			{
//				BW_FollowCounter_Right(1);
//				Get_UV();
//				if(UV_state==UVSTATE_ACTIVE)
//				{
//					FIRE=FIRE_ON;
//					UV_Lock=UVLOCK_ACTIVE;
//				}
//				if(Ping[PING_FRONT]<17)break;
//			}
//		}
//		else
//		{
//			for(l=0;l<=2;l++)
//			{
//				Get_UV();
//				if(UV_state==UVSTATE_ACTIVE)
//				{
//					FIRE=FIRE_ON;
//					UV_Lock=UVLOCK_ACTIVE;
//				}
//				Dynamx_MovFwd3cm(3,HEXSPD_ULTRAFAST, IKCALC_ENABLE);
//			}
//
//		}


//	Get_UV();
//	if(UV_state==UVSTATE_ACTIVE)
//	{
//		FIRE=FIRE_ON;
//		UV_Lock=UVLOCK_ACTIVE;
//	}

		if(UV_Lock==UVLOCK_INACTIVE)
		{
//			if(SP_FIRE_1B==SP_FIRE_ACTIVE)
//			{
//
//			}
			if(SP_FIRE_1B==SP_FIRE_ACTIVE)
			{
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					delay_ms(50);
				}
//				for(m=0;m<=1;m++)
//				{
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					Get_UV();
					if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
					{
						FIRE=FIRE_ON;
						UV_Lock=UVLOCK_ACTIVE;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
						lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
						delay_ms(50);
					}
					//if(Ping[PING_FRONT]<16)break;
				//}

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	//			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_DISABLE);

				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					delay_ms(50);
				}
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	//			Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_DISABLE);
				SP_FIRE_1B=SP_FIRE_ACTIVE;

//				if(UV_state==UVSTATE_ACTIVE)
//				{
//					for(m=0;m<=3;m++)
//					{
//						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//						if(Ping[PING_FRONT]<16)break;
//					}
//				}
			}
			else if(UV_R2FLAG==UV_R2FLAG_ACTIVE)
			{
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					delay_ms(50);
				}
				for(m=0;m<=1;m++)
				{
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					Get_UV();
					if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
					{
						FIRE=FIRE_ON;
						UV_Lock=UVLOCK_ACTIVE;
						lcd_display_clear();
						lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
						delay_ms(50);
					}
					if(Ping[PING_FRONT]<20)break;
				}

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				//Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	//			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_DISABLE);

				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					delay_ms(50);
				}
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				//Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	//			Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
			else
			{
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					delay_ms(50);
				}
				for(m=0;m<=1;m++)
				{
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					Get_UV();
					if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
					{
						FIRE=FIRE_ON;
						UV_Lock=UVLOCK_ACTIVE;
						lcd_display_clear();
						lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
						delay_ms(50);
					}
					if(Ping[PING_FRONT]<20)break;
				}

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	//			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_DISABLE);

				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)// || (FlameSenseDigi[0]!=0) || (FlameFrontDigi[0]!=0))
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					delay_ms(50);
				}
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	//			Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_DISABLE);
			}

		}

	if(FIRE==FIRE_ON)
	{
		EXTINGUISHER_OFF;
		UV_Lock=UVLOCK_ACTIVE;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"FIREFIGHT");lcd_putstr(lcd);
		delay_ms(100);

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1B");lcd_putstr(lcd);

			if((FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==6))
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				FIRESCAN_DIRECTION=SCAN_LEFT;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
				delay_ms(100);
			}
			else
			{
				FIRESCAN_DIRECTION=SCAN_LEFT;


				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
				delay_ms(100);

				if(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				}
				else
				{
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
	//				Dynamx_MovFwd4cm(20,HEXSPD_MEDFAST,IKCALC_DISABLE);

					for(l=0;l<=3;l++)
					{
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
						Furniture_Avoider();
						Bumper_Follow();
						if(Ping[PING_FRONT]<20)break;
					}

//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				FIRESCAN_DIRECTION=SCAN_LEFT;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
				delay_ms(100);
			}
				SP_FIRE_1B=SP_FIRE_ACTIVE;

/*		=== TEST NEW ALGORITM ===
			int cnt;
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1B");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

//			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5))
//			{
//				if((Ping[PING_FRONT]<30) || (Ping[PING_RIGHT]>20))
//				{
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				}
//			}

			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

//			if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==1) || (FlameFrontDigi[0]==4))
//			if((FlameSenseDigi[0]!=2) || (FlameSenseDigi[0]!=1))
//			{
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if((FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==1))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

					FIRESCAN_DIRECTION=SCAN_LEFT;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1B");lcd_putstr(lcd);
					delay_ms(50);

				}
				else if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4))
				{
					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					FIRESCAN_DIRECTION=SCAN_LEFT;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
				}
				else if((FlameSenseDigi[0]!=2) || (FlameSenseDigi[0]!=1))
				{
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

					if(Ping[PING_LEFT]>15)
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						if(Ping[PING_LEFT]>15)
						{
							Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
							if(Ping[PING_LEFT]>15)
							{
								Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
							}
						}
					}


					if((Ping[PING_ASKEW_LEFT]) > (Ping[PING_REAR_LEFT]))
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_ASKEW_LEFT]) > (Ping[PING_REAR_LEFT]))
							{
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
								if((Ping[PING_ASKEW_LEFT]) > (Ping[PING_REAR_LEFT]))
									{
										Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
							}
					}

					while((FlameSenseDigi[0]!=1) || (FlameSenseDigi[0]!=2) || (FlameSenseDigi[0]!=4))
						{
							Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
							if(cnt>1)
							{
								if((Ping[PING_LEFT]<15) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==4))
								{
									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
									break;
								}
							}
							cnt++;

						}
					FIRESCAN_DIRECTION=SCAN_RIGHT;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
					delay_ms(100);

//				}
			}
			SP_FIRE_1B=SP_FIRE_ACTIVE;
			*/
		}
		else if(SP_FIRE_1C==SP_FIRE_ACTIVE)
		{
			FIRESCAN_DIRECTION=SCAN_LEFT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==2) || (FlameFrontDigi[0]==4))
			{
				if((Ping[PING_FRONT]<30) || (Ping[PING_RIGHT]>20))
				{
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				}
			}
			else
			{

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

//			if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==1) || (FlameFrontDigi[0]==4))
			if((FlameSenseDigi[0]!=2) || (FlameSenseDigi[0]!=1))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if((FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==1))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					FIRESCAN_DIRECTION=SCAN_RIGHT;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
					delay_ms(50);

				}
				else
				{

					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

					if((Ping[PING_FRONT]<30) || (Ping[PING_RIGHT]>20))
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					}
				}
			}
			}

			SP_FIRE_1C=SP_FIRE_ACTIVE;
		}
		else if(FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE)
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1A");lcd_putstr(lcd);
//			delay_ms(100);

			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5))
			{
				if((Ping[PING_FRONT]<30) || (Ping[PING_RIGHT]>20))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				}
			}
			else
			{

			//Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			if(FlameSenseDigi[0]!=4)
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			}

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			if((FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==6))
			{
				if((FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==6))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					FIRESCAN_DIRECTION=SCAN_LEFT;
				}

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1A");lcd_putstr(lcd);
				delay_ms(50);
			}
			else
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				if(FlameSenseDigi[0]!=4)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					if(Ping[PING_LEFT]>15)
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						if(Ping[PING_LEFT]>15)
						{
							Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						}
					}
				}
				if(FlameSenseDigi[0]!=4)
				{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				}


//				if((Ping[PING_FRONT]<30) || (Ping[PING_RIGHT]>20))
//				{
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				}
			}
		}
			FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;
		}
		else if(SP_FIRE_R3==SP_FIRE_ACTIVE)
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE R3");lcd_putstr(lcd);
			delay_ms(100);

//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			int CNT_R3=0;
			BW_PID_Init_Furniture();
			while((FlameSenseDigi[0]!=3) && (CNT_R3 < 10))// || (FlameSenseDigi[0]==4))
			{
				if(Ping[PING_FRONT]>15 && (CNT_R3 < 5))
				{
					if((FlameSenseDigi[0]==6)||(FlameSenseDigi[0]==7))Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);break;
					BW_FollowCounter_Left(1);
				}
				else
				{
					BW_FollowCounter_Left(1);
					if((CNT_R3>= 5) && (FlameSenseDigi[0]!=0))break;// || FlameSenseDigi[0]==5 || FlameSenseDigi[0]==3))break;
				}
				CNT_R3++;
			}

/* OLD ALGORITM */
//			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4))
//			{
//				if(Ping[PING_FRONT]<30)
//				{
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				}
//			}
//			else
//			{
//				if(Ping[PING_FRONT]>15)
//				{
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				}
//				if((Ping[PING_ASKEW_LEFT])<(Ping[PING_REAR_LEFT]))
//				{
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					if((Ping[PING_ASKEW_LEFT])<(Ping[PING_REAR_LEFT]))
//					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					}
//				}
//				else {
//					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					if((Ping[PING_ASKEW_LEFT])>(Ping[PING_REAR_LEFT]))
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					}
//				}
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//
//				int i=0;
//				while(Ping[PING_RIGHT]>10 && i<5)
//				{
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//					i++;
//				}
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//					FIRESCAN_DIRECTION=SCAN_LEFT;
//					lcd_display_clear();
//					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
//					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE R3");lcd_putstr(lcd);
//					delay_ms(50);
//				}

//			SP_FIRE_R3=SP_FIRE_INACTIVE;
		}
		else
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

//			if(Ping[PING_FRONT]<=15)
//			{
//				lcd_display_clear();
////				lcd_gotoxy(0,0);sprintf(lcd,"WA",FlameSenseDigi[0]);lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
//				delay_ms(100);
//
//				Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//			}
		}

		//============================//
		//		EXTINGUISH ROUTINE	  //
		//============================//

		BW_FireFight();


		//============================//

//=======APRIL, 27th 2017======//
//		RoomTypeDetector();

		FIRE_LED_BLINK_OFF;
		FIRE_LED_OFF;
		FIRE=FIRE_SUCCESS;

//		/*
//		 * FIRE == OFF
//		 */


		//old ALGORITHM
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//===============================================================
//		Start of changes
//		Ryan (April 20th,2017)

		Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

		if ((ROOM[2]==ROOM_4A) || (ROOM[2]==ROOM_4B) || (ROOM[2]==ROOM_3))// || (ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
		{
			FOLLOW_FLAG=KANAN;
			Nav_TurnAround(TURN_LEFT);
			BW_PID_Init();
//			BW_PID_Init_Room();
			BW_FollowTracer_Right();
		}
		else if ((ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
		{

			Nav_TurnAround(TURN_LEFT);
			BW_PID_Init();
			if(Ping[PING_RIGHT]>30){FOLLOW_FLAG=KIRI;BW_FollowTracer_Left();}
			else {FOLLOW_FLAG=KANAN;BW_FollowTracer_Right();}
		}
		else if (ROOM[2]==ROOM_1C)
		{
			FOLLOW_FLAG=KANAN;
			while(Ping[PING_FRONT]>14)
			{
				Furniture_Avoider();
				Bumper_Follow();
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				if((Ping[PING_ASKEW_RIGHT]<15)||(Ping[PING_ASKEW_LEFT]<15))break;
			}
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			BW_PID_Init();
//			BW_PID_Init_Room();
			BW_FollowTracer_Right();
		}
		else if (ROOM[2]==ROOM_1B)
		{
			FOLLOW_FLAG=KIRI;
//			Nav_TurnAround(TURN_RIGHT);
			while(Ping[PING_FRONT]>14)
			{
				Furniture_Avoider();
				Bumper_Follow();
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

//				if((Ping[PING_ASKEW_RIGHT]<15)||(Ping[PING_ASKEW_LEFT]<15))break;//Nav_TurnAround(TURN_RIGHT);break;
			}
			BW_PID_Init_FAR();
//			BW_PID_Init_Room();
			BW_FollowTracer_Left();
		}
		else if (ROOM[2]==ROOM_1A)
		{
//			int cnt=0;
			FOLLOW_FLAG=KANAN;
			Nav_TurnAround(TURN_LEFT);

			if	(
					(Ping[PING_LEFT]+Ping[PING_ASKEW_LEFT]+Ping[PING_REAR_LEFT])
					<
					(Ping[PING_RIGHT]+Ping[PING_ASKEW_RIGHT]+Ping[PING_REAR_RIGHT])
				)
			{
				BW_PID_Init_FAR();
//				BW_PID_Init_Room();
				BW_FollowTracer_Left();
			}
			else
			{
				BW_PID_Init_FAR();
//				BW_PID_Init_Room();
				BW_FollowTracer_Right();
			}
//			while(Ping[PING_FRONT]>10 && cnt < 10)
//			{
//				Furniture_Avoider();
//				Bumper_Follow();
//				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//				if(Ping[PING_ASKEW_LEFT]<7)Nav_TurnAround(TURN_LEFT);break;
//				cnt++;
//			}
//			BW_PID_Init_FAR();
////			BW_PID_Init_Room();
//			BW_FollowTracer_Right();
		}

		else if(
				(Ping[PING_LEFT]+Ping[PING_ASKEW_LEFT]+Ping[PING_REAR_LEFT])
				<
				(Ping[PING_RIGHT]+Ping[PING_ASKEW_RIGHT]+Ping[PING_REAR_RIGHT])
			)
		{
			FOLLOW_FLAG=KANAN;
			Nav_TurnAround(TURN_LEFT);
			BW_PID_Init();
//			BW_PID_Init_Room();
			BW_FollowTracer_Right();

		}
		else
		{
			FOLLOW_FLAG=KIRI;
			Nav_TurnAround(TURN_RIGHT);
			BW_PID_Init();
//			BW_PID_Init_Room();
			BW_FollowTracer_Left();
		}
//		End of changes
//		Some codes was omitted in this changes
//===============================================================
	}
	else
	{
		FIRE=FIRE_OFF;
		Exit_No_Fire();
		if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
		{
			ROOM4AB_FLAG=ROOM4AB_INACTIVE;
		}
	}



}

/* func      : void H_ROOM_1A (void)
 * brief     : BW 2017 Navigation Routine. Home== R1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Hafidin (MISSING NOTES)
 * Revised BY: Hafidin (April, 27th 2017)
 * programmer's Note:
 */
void H_ROOM_1A (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 1 KE ROOM 4=======//
		/*
		 * 	ACTIVATE ROOM4AB_FLAG
		 */
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Nav_1A_To_4A();

		if(Ping[PING_RIGHT]>10)
		{
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
		}
//		Nav_1A_To_3();

				//=======ROOM 4=======//
//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;

				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

//			if(ROOM4B_FLAG == ROOM4BFLAG_ACTIVE)
//			{
//				if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
//				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
//					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
//						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//					}
//				}
//			}
							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
							{
								ROOM[2]=ROOM_4A;

//								Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

								if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT])+4)
								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
									if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT]+4))
									{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
										if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT]+4))
										{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
									}
								}

							}
							else
							{
								ROOM[2]=ROOM_4B;

//								Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

								if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
								{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
									if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
									{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
										if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
										{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
									}
								}

							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				ROOM4B_FLAG = ROOM4BFLAG_INACTIVE;
				ROOM4A_FLAG = ROOM4AFLAG_INACTIVE;
				ROOM4AB_FLAG=ROOM4AB_INACTIVE;
		//=======ROOM 4 KE ROOM 3=======//
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		if(ROOM[2]==ROOM_4B)
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_4B_To_2();

			UV_R2FLAG=UV_R2FLAG_ACTIVE;
			//=======ROOM 2=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

						//RETURN TRIP NEEDED
						if(Ping[PING_REAR]<40)
						{
							ROOM[2]=ROOM_2B;
						}
						else
						{
							ROOM[2]=ROOM_2A;
						}

					//BW IN ROOM
					BW_Buzz(1);
					H_2017_Room();
					if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;
			UV_R2FLAG=UV_R2FLAG_INACTIVE;

			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_2_To_3();

			SP_FIRE_R3=SP_FIRE_ACTIVE;
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}

					//=======ROOM 3=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_3;

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			SP_FIRE_R3=SP_FIRE_INACTIVE;

			//==========================//
			//		RE-CHECK ROUTINE	//
			//==== RE CHECK  ROOM 3 ====//

			Nav_TurnAround(TURN_RIGHT);

			SP_FIRE_R3=SP_FIRE_ACTIVE;

	//		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
	//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
	//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
	//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
	//				}
	//			}
					//=======ROOM 3=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_3;

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			SP_FIRE_R3=SP_FIRE_INACTIVE;

			//=======ROOM 3 KE ROOM 2=======//
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_3_To_2();

			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
			}

			if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
			}
			else
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT]+4))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
			}

	//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
								{
									ROOM[2]=ROOM_2B;
								}
								else
								{
									ROOM[2]=ROOM_2A;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					Nav_2_To_4A_NEW_VER2();

					ROOM4AB_FLAG=ROOM4AB_ACTIVE;
						//=======ROOM 4=======//
						//UPDATE BW LOCATION
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_ROOM;

									//RETURN TRIP NEEDED
									GetCMPS11_Angle8Bit();
		//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
		//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
		/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
									{
										ROOM[2]=ROOM_4A;
									}
									else
									{
										ROOM[2]=ROOM_4B;
									//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
									}

								//BW IN ROOM
								BW_Buzz(1);
								H_2017_Room();
								if(EXTINGUISHED_FIRE==1)break;

						//BW IN CORRIDOR
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_CORRIDOR;

						ROOM4AB_FLAG=ROOM4AB_INACTIVE;

		}
		else
		{
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_4A_To_3();

			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
			SP_FIRE_R3=SP_FIRE_ACTIVE;

	//		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
	//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
	//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
	//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
	//				}
	//			}
					//=======ROOM 3=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_3;

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			SP_FIRE_R3=SP_FIRE_INACTIVE;
			//=======ROOM 3 KE ROOM 2=======//
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_3_To_2();

			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
			}

			if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
			}
			else
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT]+4))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
			}

	//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
								{
									ROOM[2]=ROOM_2B;
								}
								else
								{
									ROOM[2]=ROOM_2A;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//==========================//
			//		RE-CHECK ROUTINE	//
			//==== RE CHECK  ROOM 2 ====//

			Nav_TurnAround(TURN_RIGHT);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;


			//=======ROOM 2 KE ROOM 3=======//
			if((Ping[PING_RIGHT])<=10)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}
	//		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	//		{
	//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
	//			}
	//		}
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_2_To_3();

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 3 KE ROOM 4=======//
				if((Ping[PING_RIGHT])<=10)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					if((Ping[PING_RIGHT])<=10)
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					}
				}
				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
					}
				}
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_3_To_4A();

					//=======ROOM 4=======//
	//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;

					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								GetCMPS11_Angle8Bit();
	//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
	/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
								{
									ROOM[2]=ROOM_4A;
								}
								else
								{
									ROOM[2]=ROOM_4B;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

		}

	}
}

/* func      : void H_ROOM_1BC (void)
 * brief     : BW 2017 Navigation Routine. Home== R1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_1BC (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 1 KE ROOM 2=======//
		if(Ping[PING_FRONT]<40)
		{
			Nav_1B_To_2();
		}
		else
		{
			Nav_1C_To_2();
		}

//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 2 KE ROOM 3=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

//		Nav_2_To_3();
		Nav_2_To_4A();

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 3 KE ROOM 4=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

//		Nav_3_To_4A();
		if(ROOM[2]==ROOM_4B)
		{
			Nav_4B_To_3();
		}
		else
		{
			Nav_4A_To_3();
		}


				//=======ROOM 4=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}

void H_ROOM_1BC_NEW2(void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 1 KE ROOM 2=======//
		Nav_1C_To_3();

		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
		}
		SP_FIRE_R3=SP_FIRE_ACTIVE;

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

				//RETURN TRIP NEEDED
				ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;
		SP_FIRE_R3=SP_FIRE_INACTIVE;
				//=======ROOM 3 KE ROOM 2=======//
		if((Ping[PING_RIGHT])<=10)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}
//		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//			{
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				}
//			}
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
		UV_R2FLAG=UV_R2FLAG_ACTIVE;
		Nav_3_To_2();

		if(Ping[PING_LEFT]>10)
		{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
		}

		if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
		}
		else
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
		}
		//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		//=======ROOM 2=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

				//RETURN TRIP NEEDED
//				if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
//				{
//					ROOM[2]=ROOM_2B;
//				}
//				else
//				{
					ROOM[2]=ROOM_2A;
//				}

				//BW IN ROOM
				BW_Buzz(1);
				H_2017_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;
		//=======ROOM 2 KE ROOM 4=======//
		/*
		 * 	ACTIVATE ROOM4AB_FLAG
		 */
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

		if((Ping[PING_RIGHT])< 10)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		}
//		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//		{
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//			}
//		}
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_2_To_4A_NEW();

				//=======ROOM 4=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

				//RETURN TRIP NEEDED
				GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							}

				//BW IN ROOM
				BW_Buzz(1);
				H_2017_Room();
				if(EXTINGUISHED_FIRE==1)break;
		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;
		ROOM4AB_FLAG=ROOM4AB_INACTIVE;

	}
}

/* func      : void H_ROOM_1BC_NEW (void)
 * brief     : BW 2017 Navigation Routine. Home== R1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_1BC_NEW (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 1 KE ROOM 4=======//
		/*
		 * 	ACTIVATE ROOM4AB_FLAG
		 */
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Nav_1C_To_4A();

		SP_FIRE_1B=SP_FIRE_INACTIVE;
		SP_FIRE_1C=SP_FIRE_INACTIVE;

				//=======ROOM 4=======//
//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
							if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 4 KE ROOM 3=======//
		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if(ROOM[2]==ROOM_4B)
		{
			Nav_4B_To_3();
		}
		else
		{
			Nav_4A_To_3();
		}

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 3 KE ROOM 2=======//
		UV_R2FLAG=UV_R2FLAG_ACTIVE;
		Nav_3_To_2();

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;

		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 2 ====//

		Nav_TurnAround(TURN_RIGHT);

			//=======ROOM 2=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

						//RETURN TRIP NEEDED
						if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
						{
							ROOM[2]=ROOM_2B;
						}
						else
						{
							ROOM[2]=ROOM_2A;
						}

					//BW IN ROOM
					BW_Buzz(1);
					H_2017_Room();
					if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;


		//=======ROOM 2 KE ROOM 3=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_2_To_3();

			//=======ROOM 3=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

						//RETURN TRIP NEEDED
						ROOM[2]=ROOM_3;

					//BW IN ROOM
					BW_Buzz(1);
					H_2017_Room();
					if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 3 KE ROOM 4=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_3_To_4A();

				//=======ROOM 4=======//
//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;

				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) && (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}

/* func      : void H_ROOM_1BC_SP (void)
 * brief     : BW 2017 Navigation Routine. Home==4, cat==A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_1BC_SP (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
//		Get_UV();
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//					Get_UV();
//					if(UV_state==UVSTATE_ACTIVE)
//					{
//						FIRE=FIRE_ON;
//						UV_Lock=UVLOCK_ACTIVE;
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
//						lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
//					}
//					else
//					{
//						Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
////						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//						Dynamx_MovBwd(30,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//						BW_PID_Init();
//						BW_FollowTracer_Left();
//					}
		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_1A;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 2=======//
		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
		FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if(Ping[PING_FRONT]<40)
		{
			Nav_1B_To_2();
		}
		else
		{
			Nav_1C_To_2();
		}

//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 2 KE ROOM 3=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

		Nav_2_To_3();

//		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);	}
//			}
//		}

		SP_FIRE_R3=SP_FIRE_ACTIVE;

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 3 ====//


		Nav_TurnAround(TURN_RIGHT);

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

			SP_FIRE_R3=SP_FIRE_INACTIVE;
		//=======ROOM 3 KE ROOM 2=======//
				if((Ping[PING_RIGHT])<=10)
							{
								Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
							}
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
							{
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
								if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

								}
							}
		UV_R2FLAG=UV_R2FLAG_ACTIVE;
		Nav_3_To_2();

//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;
		//=======ROOM 2 KE ROOM 1=======//

		if((Ping[PING_RIGHT])<=10)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		}
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
							{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
								if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
									{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
							}
						}
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		ROOM1_FLAG=ROOM1FLAG_ACTIVE;

		if(Ping[PING_FRONT]<40)
		{
			Nav_2B_To_1BC();
			SP_FIRE_1B=SP_FIRE_ACTIVE;

		}
		else
		{
			SP_FIRE_1C=SP_FIRE_ACTIVE;

			Nav_2A_To_1BC();
		}

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)
		{
			if(Ping[PING_LEFT]>30)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>30)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
				}
			}
		}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}

/* func      : void H_ROOM_1BC_SP_NEW (void)
 * brief     : BW 2017 Navigation Routine. Home==4, cat==A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_1BC_SP_NEW (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
//		Get_UV();
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//					Get_UV();
//					if(UV_state==UVSTATE_ACTIVE)
//					{
//						FIRE=FIRE_ON;
//						UV_Lock=UVLOCK_ACTIVE;
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
//						lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
//					}
//					else
//					{
//						Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
////						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//						Dynamx_MovBwd(30,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//						BW_PID_Init();
//						BW_FollowTracer_Left();
//					}
		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_1A;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 2=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		// BACK UP UNTUK JTS RUANG 1A

		Nav_1A_To_2();

/*
		if(Ping[PING_FRONT]<40)
		{
			Nav_1B_To_2();
		}
		else
		{
			Nav_1C_To_2();
		}
*/
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 2 KE ROOM 3=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_2_To_3();

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 3 ====//

		Nav_TurnAround(TURN_RIGHT);

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;


		//=======ROOM 3 KE ROOM 2=======//
		UV_R2FLAG=UV_R2FLAG_ACTIVE;
		Nav_3_To_2();

//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;
		//=======ROOM 2 KE ROOM 1=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		ROOM1_FLAG=ROOM1FLAG_ACTIVE;

		if(Ping[PING_FRONT]<40)
		{
			Nav_2B_To_1BC();

//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			SP_FIRE_1B=SP_FIRE_ACTIVE;
//				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
//				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);

		}
		else
		{
			SP_FIRE_1C=SP_FIRE_ACTIVE;

			Nav_2A_To_1BC();
		}

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)
		{
			if(Ping[PING_LEFT]>30)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>30)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
				}
			}
		}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

	}
}

/* func      : void H_ROOM_2 (void)
 * brief     : BW 2017 Navigation Routine. Home== R2
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_2 (void)
{
//	int k;
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 2 KE ROOM 1=======//
		ROOM1_FLAG=ROOM1FLAG_ACTIVE;	//12/04/17

		if(Ping[PING_FRONT]<40)
		{
			Nav_2B_To_1BC();

			SP_FIRE_1B=SP_FIRE_ACTIVE;

		}
		else
		{
			SP_FIRE_1C=SP_FIRE_ACTIVE;

			Nav_2A_To_1BC();
		}

			if(SP_FIRE_1B==SP_FIRE_ACTIVE)
			{
				if(Ping[PING_LEFT]>30)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					if(Ping[PING_LEFT]>30)
					{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
				}
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
					}
				}
			}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;

								if(Ping[PING_LEFT]>18)
								{
									Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
								}
								if(Ping[PING_LEFT]>18)
								{
									Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
								}
							}
							else
							{
								ROOM[2]=ROOM_1C;

								if(Ping[PING_RIGHT]>18)
								{
									Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
								}
								if(Ping[PING_RIGHT]>18)
								{
									Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
								}
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 4=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

//		Nav_1A_To_4A();		//12/04/17
		Nav_1C_To_4A();
//		Nav_1C_To_3();

		SP_FIRE_1B=SP_FIRE_INACTIVE;
		SP_FIRE_1C=SP_FIRE_INACTIVE;

				//=======ROOM 4=======//
//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) && (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 4 KE ROOM 3=======//
		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if(ROOM[2]==ROOM_4B)
		{
			Nav_4B_To_3();
		}
		else
		{
			Nav_4A_To_3();
		}

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}

/* func      : void H_ROOM_2_NEW (void)
 * brief     : BW 2017 Navigation Routine. Home== R2
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_2_NEW (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 2 KE ROOM 4=======//
		/*
		 * 	ACTIVATE ROOM4AB_FLAG
		 */
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

//		if(Ping[PING_FRONT]>40)
//		{
//			SP_FIRE_1C=SP_FIRE_ACTIVE;
//		}
//		else
//		{
//			SP_FIRE_1B=SP_FIRE_ACTIVE;
//		}


		Nav_2_To_4A_NEW();

				//=======ROOM 4=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
/*GOR*/						if((CMPS11_Angle>R4AB_THRESHOLD_UPPER) && (CMPS11_Angle<R4AB_THRESHOLD_LOWER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 4 KE ROOM 3=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

	//		Nav_3_To_4A();
		if(ROOM[2]==ROOM_4B)
		{
			Nav_4B_To_3();
		}
		else
		{
			Nav_4A_To_3();
		}

		if((Ping[PING_LEFT])>10)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		}
		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);	}
					}
				}
		SP_FIRE_R3=SP_FIRE_ACTIVE;
				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				SP_FIRE_R3=SP_FIRE_INACTIVE;
		//=======ROOM 3 KE ROOM 1=======//
		ROOM1_FLAG=ROOM1FLAG_ACTIVE;
//		if((Ping[PING_RIGHT])<=10)
//					{
//						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					}
//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//					{
//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//						}
//					}
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_3_To_1BC();

			if(SP_FIRE_1B==SP_FIRE_ACTIVE)		//eksekusi persyaratan ada di nav 4b to 1bc
			{
				SP_FIRE_1B=SP_FIRE_ACTIVE;
			}
			else
			{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
							{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
						}
				}
				SP_FIRE_1C=SP_FIRE_ACTIVE;
			}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;


		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 1 ====//

		if(ROOM[2]==ROOM_1C)
		{
			Nav_TurnAround(TURN_LEFT);
		}
		else
		{
			while(Ping[PING_FRONT]<40)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			while((Ping[PING_RIGHT]<40) || (Ping[PING_ASKEW_RIGHT]<40))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				SP_FIRE_1B=SP_FIRE_INACTIVE;
				SP_FIRE_1C=SP_FIRE_INACTIVE;

			//=======ROOM 1 KE ROOM 4=======//
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_1C_To_4A();

			SP_FIRE_1B=SP_FIRE_INACTIVE;
			SP_FIRE_1C=SP_FIRE_INACTIVE;

					//=======ROOM 4=======//
	//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								GetCMPS11_Angle8Bit();
	//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
								if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) && (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
								{
									ROOM[2]=ROOM_4A;
								}
								else
								{
									ROOM[2]=ROOM_4B;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 4 KE ROOM 3=======//
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			if(ROOM[2]==ROOM_4B)
			{
				Nav_4B_To_3();
			}
			else
			{
				Nav_4A_To_3();
			}

			SP_FIRE_R3=SP_FIRE_ACTIVE;
					//=======ROOM 3=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_3;

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;
			SP_FIRE_R3=SP_FIRE_INACTIVE;

	}
}

/* func      : void H_ROOM_2_NEW_VER2 (void)
 * brief     : BW 2017 Navigation Routine. Home== R2
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Toni
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_2_NEW_VER2(void)
{
	while(EXTINGUISHED_FIRE==0)
	{
//		//=======ROOM 2 KE ROOM 4=======//
//		/*
//		 * 	ACTIVATE ROOM4AB_FLAG
//		 */
//		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

		Nav_2_To_4A_NEW_VER2();

		if(FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE)
		{
				if(Ping[PING_LEFT]>15)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				}
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
					}
				}
				else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
					}
				}

			//=======ROOM 1=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

						//RETURN TRIP NEEDED
						ROOM[2]=ROOM_1A;

					//BW IN ROOM
					BW_Buzz(1);
					H_2017_Room();
					if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

			//=======ROOM 1 KE ROOM 4=======//
			/*
			 * 	ACTIVATE ROOM4AB_FLAG
			 */
			ROOM4AB_FLAG=ROOM4AB_ACTIVE;
			CAT_FLAG_C=CAT_DETECTED;
			CAT_FLAG_B=CAT_NOT_DETECTED;
			CAT_FLAG_A=CAT_NOT_DETECTED;

			Nav_1A_To_4A();

			if(Ping[PING_RIGHT]>10)
			{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			}
	//		Nav_1A_To_3();

					//=======ROOM 4=======//
	//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;

					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

//				if(ROOM4B_FLAG == ROOM4BFLAG_ACTIVE)
//				{
//					if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
//					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
//						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
//							{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//						}
//					}
//				}
								//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
								{
									ROOM[2]=ROOM_4A;

//									Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

									if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT])+4)
									{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
										if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT]+4))
										{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
											if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT]+4))
											{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
										}
									}

								}
								else
								{
									ROOM[2]=ROOM_4B;

//									Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

									if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
									{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
										if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
										{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
											if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
											{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
										}
									}

								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

					ROOM4B_FLAG = ROOM4BFLAG_INACTIVE;
					ROOM4A_FLAG = ROOM4AFLAG_INACTIVE;
					ROOM4AB_FLAG=ROOM4AB_INACTIVE;
					//=======ROOM 4 KE ROOM 3=======//
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

					if((Ping[PING_REAR_RIGHT])>(Ping[PING_RIGHT])+4)
							{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
								if((Ping[PING_REAR_RIGHT])>(Ping[PING_RIGHT]+4))
								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
									if((Ping[PING_REAR_RIGHT])>(Ping[PING_RIGHT]+4))
									{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
								}
							}

					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					if(ROOM[2]==ROOM_4B)
					{
			//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
						Nav_4B_To_3();
					}
					else
					{
						Nav_4A_To_3();
					}

					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
					SP_FIRE_R3=SP_FIRE_ACTIVE;

			//		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			//				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			//					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
			//				}
			//			}
							//=======ROOM 3=======//
							//UPDATE BW LOCATION
							BW_LOCATION[1]= BW_LOCATION[0];
							BW_LOCATION[0]= LOCATION_ROOM;

										//RETURN TRIP NEEDED
										ROOM[2]=ROOM_3;

									//BW IN ROOM
									BW_Buzz(1);
									H_2017_Room();
									if(EXTINGUISHED_FIRE==1)break;

							//BW IN CORRIDOR
							BW_LOCATION[1]= BW_LOCATION[0];
							BW_LOCATION[0]= LOCATION_CORRIDOR;

					SP_FIRE_R3=SP_FIRE_INACTIVE;

//					//=======ROOM 3 KE ROOM 1=======//
//					ROOM1_FLAG=ROOM1FLAG_ACTIVE;
//			//		if((Ping[PING_RIGHT])<=10)
//			//					{
//			//						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			//					}
//			//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//			//					{
//			//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			//						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//			//						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			//							if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//			//								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//			//						}
//			//					}
//					Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//					Nav_3_To_1BC();
//
//						if(SP_FIRE_1B==SP_FIRE_ACTIVE)		//eksekusi persyaratan ada di nav 4b to 1bc
//						{
//							SP_FIRE_1B=SP_FIRE_ACTIVE;
//						}
//						else
//						{
//							Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//							if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//							{
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//								if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//									{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//										if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//										{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//									}
//							}
//							SP_FIRE_1C=SP_FIRE_ACTIVE;
//						}
//
//							//=======ROOM 1=======//
//							//UPDATE BW LOCATION
//							BW_LOCATION[1]= BW_LOCATION[0];
//							BW_LOCATION[0]= LOCATION_ROOM;
//
//										//RETURN TRIP NEEDED
//										if(SP_FIRE_1B==SP_FIRE_ACTIVE)
//										{
//											ROOM[2]=ROOM_1B;
//										}
//										else
//										{
//											ROOM[2]=ROOM_1C;
//										}
//
//									//BW IN ROOM
//									BW_Buzz(1);
//									H_2017_Room();
//									if(EXTINGUISHED_FIRE==1)break;
//
//							//BW IN CORRIDOR
//							BW_LOCATION[1]= BW_LOCATION[0];
//							BW_LOCATION[0]= LOCATION_CORRIDOR;

		}
		else {

			ROOM4AB_FLAG=ROOM4AB_ACTIVE;
				//=======ROOM 4=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				ROOM4AB_FLAG=ROOM4AB_INACTIVE;
		//=======ROOM 4 KE ROOM 3=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

	//		Nav_3_To_4A();
		if(ROOM[2]==ROOM_4B)
		{
			Nav_4B_To_3();
		}
		else
		{
			Nav_4A_To_3();
		}

		if((Ping[PING_LEFT])>10)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		}
		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);	}
					}
				}
		SP_FIRE_R3=SP_FIRE_ACTIVE;
				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				SP_FIRE_R3=SP_FIRE_INACTIVE;
		//=======ROOM 3 KE ROOM 1=======//
		ROOM1_FLAG=ROOM1FLAG_ACTIVE;
//		if((Ping[PING_RIGHT])<=10)
//					{
//						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					}
//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//					{
//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//							if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//						}
//					}
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_3_To_1BC();

			if(SP_FIRE_1B==SP_FIRE_ACTIVE)		//eksekusi persyaratan ada di nav 4b to 1bc
			{
				SP_FIRE_1B=SP_FIRE_ACTIVE;
			}
			else
			{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
							{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
						}
				}
				SP_FIRE_1C=SP_FIRE_ACTIVE;
			}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;


		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 1 ====//

		if(ROOM[2]==ROOM_1C)
		{
			Nav_TurnAround(TURN_LEFT);
		}
		else
		{
			while(Ping[PING_FRONT]<40)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			while((Ping[PING_RIGHT]<40) || (Ping[PING_ASKEW_RIGHT]<40))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				SP_FIRE_1B=SP_FIRE_INACTIVE;
				SP_FIRE_1C=SP_FIRE_INACTIVE;

			//=======ROOM 1 KE ROOM 4=======//
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_1C_To_4A();

			SP_FIRE_1B=SP_FIRE_INACTIVE;
			SP_FIRE_1C=SP_FIRE_INACTIVE;

					//=======ROOM 4=======//
	//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								GetCMPS11_Angle8Bit();
	//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
	/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
								{
									ROOM[2]=ROOM_4A;
								}
								else
								{
									ROOM[2]=ROOM_4B;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 4 KE ROOM 3=======//
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			if(ROOM[2]==ROOM_4B)
			{
				Nav_4B_To_3();
			}
			else
			{
				Nav_4A_To_3();
			}

			SP_FIRE_R3=SP_FIRE_ACTIVE;
					//=======ROOM 3=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_3;

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;
			SP_FIRE_R3=SP_FIRE_INACTIVE;
		}
	}
}

/* func      : void H_ROOM_3 (void)
 * brief     : BW 2017 Navigation Routine. Home== R3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_3 (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 3 KE ROOM 2=======//
		UV_R2FLAG=UV_R2FLAG_ACTIVE;
		Nav_3_To_2();

		if(Ping[PING_LEFT]>20)
		{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			if(Ping[PING_LEFT]>20)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
		}

		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);			}
		}
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							//if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							if(Ping[PING_REAR_LEFT]<70)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;
		//=======ROOM 2 KE ROOM 1=======//
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		ROOM1_FLAG=ROOM1FLAG_ACTIVE;

		if(Ping[PING_FRONT]<40)
		{
			Nav_2B_To_1BC();

//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			SP_FIRE_1B=SP_FIRE_ACTIVE;
//				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
//				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);

		}
		else
		{
			SP_FIRE_1C=SP_FIRE_ACTIVE;
			Nav_2A_To_1BC();
		}

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)
		{
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
			else
			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
		}
		if(SP_FIRE_1C==SP_FIRE_ACTIVE)
		{
			if(Ping[PING_RIGHT]<=10)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_RIGHT]<=10)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
			}
			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					}
				}

		}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 4=======//
		/*
		 * 	ACTIVATE ROOM4AB_FLAG
		 */
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

//		Nav_1A_To_4A();
		Nav_1C_To_4A_NEW();
		SP_FIRE_1B=SP_FIRE_INACTIVE;
		SP_FIRE_1C=SP_FIRE_INACTIVE;

				//=======ROOM 4=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
/*GOR*/						if((CMPS11_Angle>R4AB_THRESHOLD_UPPER) &&(CMPS11_Angle<R4AB_THRESHOLD_LOWER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 1 ====//

		//=======ROOM 4 KE ROOM 1=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if(ROOM[2]==ROOM_4B)
		{
			Nav_4B_To_1BC();
		}
		else
		{
			Nav_4A_To_1A();
		}
	}
}

/* func      : void H_ROOM_3_VER2 (void)
 * brief     : BW 2017 Navigation Routine. Home== R3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_3_VER2 (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 3 KE ROOM 2=======//
		Nav_3_To_1A();

		if(FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE)
		{
			if(Ping[PING_LEFT]>15)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
			else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}

			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_1A;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 2=======//
		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
		FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if(Ping[PING_FRONT]<40)
		{
			Nav_1B_To_2();
		}
		else
		{
			Nav_1C_To_2();
		}
		//=======ROOM 2=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
					{
						ROOM[2]=ROOM_2B;
					}
					else
					{
						ROOM[2]=ROOM_2A;
					}

				//BW IN ROOM
				BW_Buzz(1);
				H_2017_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 2 KE ROOM 4=======//
		/*
		 * 	ACTIVATE ROOM4AB_FLAG
		 */
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

//		if(Ping[PING_FRONT]>40)
//		{
//			SP_FIRE_1C=SP_FIRE_ACTIVE;
//		}
//		else
//		{
//			SP_FIRE_1B=SP_FIRE_ACTIVE;
//		}


		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_2_To_4A_NEW();

				//=======ROOM 4=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
///*GOR*/					if((CMPS11_Angle>R4AB_THRESHOLD_UPPER) && (CMPS11_Angle<R4AB_THRESHOLD_LOWER))
/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							//	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				ROOM4AB_FLAG=ROOM4AB_INACTIVE;
		}
		else
		{
			//=======ROOM 4 KE ROOM 1A=======//
			ROOM4AB_FLAG=ROOM4AB_ACTIVE;
					//=======ROOM 4=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								GetCMPS11_Angle8Bit();
	//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
	//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
	/*GOR*/						if((CMPS11_Angle<R4AB_THRESHOLD_UPPER) || (CMPS11_Angle>R4AB_THRESHOLD_LOWER))
								{
									ROOM[2]=ROOM_4A;
								}
								else
								{
									ROOM[2]=ROOM_4B;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

					ROOM4AB_FLAG=ROOM4AB_INACTIVE;
			//=======ROOM 4 KE ROOM 1=======//
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			if(ROOM[2]==ROOM_4A)
			{
				Nav_4A_To_1A_VER2();
			}
			else
			{
				Nav_4B_To_1A();
			}

			if(Ping[PING_LEFT]>15)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>15)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				}
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
			else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}

			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

					//=======ROOM 1=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_1A;

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 1 KE ROOM 2=======//
			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
			FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			if(Ping[PING_FRONT]<40)
			{
				Nav_1B_To_2();
			}
			else
			{
				Nav_1C_To_2();
			}


			UV_R2FLAG=UV_R2FLAG_ACTIVE;
	//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
								{
									ROOM[2]=ROOM_2B;
								}
								else
								{
									ROOM[2]=ROOM_2A;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;


					UV_R2FLAG=UV_R2FLAG_INACTIVE;
		}
	}
}


/* func      : void H_ROOM_4A (void)
 * brief     : BW 2017 Navigation Routine. Home== R4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_4A (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 4 KE ROOM 3=======//
		Nav_4A_To_3();

		if (ROOM1A_SP_EXIT_FLAG==ROOM1A_SP_EXIT_FLAG_ACTIVE)
		{
			H_ROOM_1BC_SP();

		}

		else
		{
//			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//				}
//			}
			SP_FIRE_R3=SP_FIRE_ACTIVE;
					//=======ROOM 3=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_3;

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

					SP_FIRE_R3=SP_FIRE_INACTIVE;
			//=======ROOM 3 KE ROOM 2=======//
//					if((Ping[PING_RIGHT])<=10)
//								{
//									Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//								}
//							if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//								{
//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//									if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//									{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//										if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//											{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//									}
//								}
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			UV_R2FLAG=UV_R2FLAG_ACTIVE;
			Nav_3_To_2();

			if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);						}
					}
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
					//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
								{
									ROOM[2]=ROOM_2B;
									SP_FIRE_1B=SP_FIRE_ACTIVE;
								}
								else
								{
									ROOM[2]=ROOM_2A;
									SP_FIRE_1C=SP_FIRE_ACTIVE;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			UV_R2FLAG=UV_R2FLAG_INACTIVE;
			//=======ROOM 2 KE ROOM 1=======//
			if((Ping[PING_RIGHT])<=10)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}
//			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//			{
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//				}
//			}
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			ROOM1_FLAG=ROOM1FLAG_ACTIVE;
			if(Ping[PING_FRONT]<40)
			{
				Nav_2B_To_1BC();
				SP_FIRE_1C=SP_FIRE_INACTIVE;
				SP_FIRE_1B=SP_FIRE_ACTIVE;
//					Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//					Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//					Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//					Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
//					Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);

			}
			else
			{
				SP_FIRE_1C=SP_FIRE_ACTIVE;
				SP_FIRE_1B=SP_FIRE_INACTIVE;
				Nav_2A_To_1BC();
			}

/* //==================
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

						Get_UV();
						if(UV_state==UVSTATE_ACTIVE)
						{
							FIRE=FIRE_ON;
							UV_Lock=UVLOCK_ACTIVE;
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
						}
						else
						{
							Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);

							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

							Dynamx_MovBwd(27,HEXSPD_MEDFAST,IKCALC_ENABLE);

							Dynamx_MovFwd4cm(20,HEXSPD_MEDFAST,IKCALC_DISABLE);
						}
*/ //==================

//						BW_PID_Init();
//						BW_FollowTracer_Right();

					//=======ROOM 1=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(SP_FIRE_1B==SP_FIRE_ACTIVE)
								{
									ROOM[2]=ROOM_1B;
								}
								else
								{
									ROOM[2]=ROOM_1C;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//==========================//
			//		RE-CHECK ROUTINE	//
			//==== RE CHECK  ROOM 2 ====//

			//=======ROOM 1 KE ROOM 2=======//
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			if(Ping[PING_FRONT]<40)
			{
				Nav_1B_To_2();
			}
			else
			{
				Nav_1C_To_2();
			}

	//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
								{
									ROOM[2]=ROOM_2B;
								}
								else
								{
									ROOM[2]=ROOM_2A;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 2 KE ROOM 1=======//
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			ROOM1_FLAG=ROOM1FLAG_ACTIVE;	//12/04/17

			if(Ping[PING_FRONT]<40)
			{
				Nav_2B_To_1BC();

				SP_FIRE_1B=SP_FIRE_ACTIVE;

			}
			else
			{
				SP_FIRE_1C=SP_FIRE_ACTIVE;

				Nav_2A_To_1BC();
			}

				if(SP_FIRE_1B==SP_FIRE_ACTIVE)
				{
					if(Ping[PING_LEFT]>30)
					{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						if(Ping[PING_LEFT]>30)
						{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
					}
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
							if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
							{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
						}
					}
				}

					//=======ROOM 1=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(SP_FIRE_1B==SP_FIRE_ACTIVE)
								{
									ROOM[2]=ROOM_1B;

									if(Ping[PING_LEFT]>18)
									{
										Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
									}
									if(Ping[PING_LEFT]>18)
									{
										Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
									}
								}
								else
								{
									ROOM[2]=ROOM_1C;

									if(Ping[PING_RIGHT]>18)
									{
										Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
									}
									if(Ping[PING_RIGHT]>18)
									{
										Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
									}
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 1 KE ROOM 3=======//
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Nav_1C_To_3();

			SP_FIRE_R3=SP_FIRE_ACTIVE;
				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;
			SP_FIRE_R3=SP_FIRE_INACTIVE;
		}
	}
}

/* func      : void H_ROOM_4A_VER2 (void)
 * brief     : BW 2017 Navigation Routine. Home== R4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Toni
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_4A_VER2 (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 4 KE ROOM 1A=======//
		Nav_4A_To_1A_VER2();

		if(Ping[PING_LEFT]>15)
		{
			Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
		}
		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
			}
		}
		else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
		{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
			}
		}

		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;
		FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

		//=======ROOM 1=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					ROOM[2]=ROOM_1A;

				//BW IN ROOM
				BW_Buzz(1);
				H_2017_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 2=======//
		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
		FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_1C_To_3();

		SP_FIRE_R3=SP_FIRE_ACTIVE;

		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
		}

		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					ROOM[2]=ROOM_3;

				//BW IN ROOM
				BW_Buzz(1);
				H_2017_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		SP_FIRE_R3=SP_FIRE_INACTIVE;

		//========ROOM 2=======//
		UV_R2FLAG=UV_R2FLAG_ACTIVE;

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_3_To_2();

		if(Ping[PING_LEFT]>20)
		{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			if(Ping[PING_LEFT]>20)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
		}

		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);			}
		}
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							//if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							if(Ping[PING_REAR_LEFT]<70)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;

//===============================================================================================//

		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 2 ====//

		UV_R2FLAG=UV_R2FLAG_ACTIVE;

		Nav_TurnAround(TURN_RIGHT);

		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

			//RETURN TRIP NEEDED
			ROOM[2]=ROOM_3;

				//BW IN ROOM
				BW_Buzz(1);
				H_2017_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;


		//=======ROOM 2 KE ROOM 3=======//

		SP_FIRE_R3=SP_FIRE_ACTIVE;

		Nav_2_To_3();

		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					ROOM[2]=ROOM_3;

				//BW IN ROOM
				BW_Buzz(1);
				H_2017_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

	SP_FIRE_R3=SP_FIRE_INACTIVE;

	//=======ROOM 3 KE ROOM 1=======//
	ROOM1_FLAG=ROOM1FLAG_ACTIVE;

	Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

	Nav_3_To_1BC();

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)		//eksekusi persyaratan ada di nav 4b to 1bc
		{
			SP_FIRE_1B=SP_FIRE_ACTIVE;
		}
		else
		{
			Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
					}
			}
			SP_FIRE_1C=SP_FIRE_ACTIVE;
		}

			//=======ROOM 1=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

						//RETURN TRIP NEEDED
						if(SP_FIRE_1B==SP_FIRE_ACTIVE)
						{
							ROOM[2]=ROOM_1B;
						}
						else
						{
							ROOM[2]=ROOM_1C;
						}

					//BW IN ROOM
					BW_Buzz(1);
					H_2017_Room();
					if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}



/* func      : void H_ROOM_4B (void)
 * brief     : BW 2017 Navigation Routine. Home== R4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_4B (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 4 KE ROOM 1=======//
		ROOM1_FLAG=ROOM1FLAG_ACTIVE;
		Nav_4B_To_1BC();

//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

						//BW IN ROOM
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
						lcd_gotoxy(0,2);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
						lcd_gotoxy(0,3);sprintf(lcd,"ROOM");lcd_putstr(lcd);

//						Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//						Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);

//						Dynamx_MovFwd3cm(3,HEXSPD_ULTRAFAST,IKCALC_ENABLE);

//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

//						if(Ping[PING_ASKEW_RIGHT]>35)
						if(SP_FIRE_1B==SP_FIRE_ACTIVE)		//eksekusi persyaratan ada di nav 4b to 1bc
						{
//							Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_ENABLE);
//							Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//							Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//							Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
//							Dynamx_MovFwd3cm(18,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//							ROOM4B_EXIT_FLAG=ROOM4BFLAG_EXIT_ACTIVE;
							SP_FIRE_1B=SP_FIRE_ACTIVE;
						}
						else
						{
							//Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//							Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//							Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

							SP_FIRE_1C=SP_FIRE_ACTIVE;
						}

//						Dynamx_MovBwd(3,HEXSPD_MEDFAST,IKCALC_DISABLE);

								//RETURN TRIP NEEDED
								if(SP_FIRE_1B==SP_FIRE_ACTIVE)
								{
									ROOM[2]=ROOM_1B;
								}
								else
								{
									ROOM[2]=ROOM_1C;
								}

						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 2=======//
		SP_FIRE_1B=SP_FIRE_INACTIVE;
		SP_FIRE_1C=SP_FIRE_INACTIVE;

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		if(Ping[PING_FRONT]<40)
		{
			Nav_1B_To_2();
		}
		else
		{
			Nav_1C_To_2();
		}

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 2 KE ROOM 3=======//
				if((Ping[PING_RIGHT])<=10)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				}
//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//				{
//					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//					}
//				}
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_2_To_3();

//		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
//			}
//		}
		SP_FIRE_R3=SP_FIRE_ACTIVE;
				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;


		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 3 ====//

		Nav_TurnAround(TURN_RIGHT);

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;
		SP_FIRE_R3=SP_FIRE_INACTIVE;
				//=======ROOM 3 KE ROOM 2=======//
				if((Ping[PING_RIGHT])<=10)
							{
								Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
								if((Ping[PING_RIGHT])<=10)
									{
										Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
									}
							}
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
							{
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
								if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
									if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
										{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
								}
							}
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

				UV_R2FLAG=UV_R2FLAG_ACTIVE;
				Nav_3_To_2();

//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;
		//=======ROOM 2 KE ROOM 1=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		ROOM1_FLAG=ROOM1FLAG_ACTIVE;

		if(Ping[PING_FRONT]<40)
		{
			Nav_2B_To_1BC();

//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			SP_FIRE_1B=SP_FIRE_ACTIVE;
//				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
//				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);

		}
		else
		{
			SP_FIRE_1C=SP_FIRE_ACTIVE;

			Nav_2A_To_1BC();
		}

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)
		{
			if(Ping[PING_LEFT]>30)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>30)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
				}
			}
		}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

	}
}

/* func      : void H_ROOM_4B (void)
 * brief     : BW 2017 Navigation Routine. Home== R4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY: Toni
 * programmer's Note:
 */
void H_ROOM_4B_NEW (void)
{
		while(EXTINGUISHED_FIRE==0)
		{
			//=======ROOM 4 KE ROOM 2=======//

				Nav_4B_To_2();

				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					if(Ping[PING_LEFT]>10)
						{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
				}

				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);			}
				}
				//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
								{
									ROOM[2]=ROOM_2B;
								}
								else
								{
									ROOM[2]=ROOM_2A;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			UV_R2FLAG=UV_R2FLAG_INACTIVE;

					//=======ROOM 2 KE ROOM 1=======//
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
					}
					Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

					ROOM1_FLAG=ROOM1FLAG_ACTIVE;

					if(Ping[PING_FRONT]<40)
					{
						Nav_2B_To_1BC();
						SP_FIRE_1B=SP_FIRE_ACTIVE;

					}
					else
					{
						SP_FIRE_1C=SP_FIRE_ACTIVE;
						Nav_2A_To_1BC();
					}

					if(SP_FIRE_1B==SP_FIRE_ACTIVE)
					{
						if(Ping[PING_LEFT]>10)
						{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
							if(Ping[PING_LEFT]>10)
							{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
						}
						if(Ping[PING_LEFT]>40)
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_LEFT]>40)
								{
									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
								}
						}
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
						if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
							{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}
					if(SP_FIRE_1C==SP_FIRE_ACTIVE)
					{
						if(Ping[PING_RIGHT]<=10)
						{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
							if(Ping[PING_RIGHT]<=10)
							{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
						}
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
							{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
								if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
								}
							}
					}

							//=======ROOM 1=======//
					Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
							//UPDATE BW LOCATION
							BW_LOCATION[1]= BW_LOCATION[0];
							BW_LOCATION[0]= LOCATION_ROOM;

										//RETURN TRIP NEEDED
										if(SP_FIRE_1B==SP_FIRE_ACTIVE)
										{
											ROOM[2]=ROOM_1B;
										}
										else
										{
											ROOM[2]=ROOM_1C;
										}

									//BW IN ROOM
									BW_Buzz(1);
									H_2017_Room();
									if(EXTINGUISHED_FIRE==1)break;

							//BW IN CORRIDOR
							BW_LOCATION[1]= BW_LOCATION[0];
							BW_LOCATION[0]= LOCATION_CORRIDOR;
					SP_FIRE_1B=SP_FIRE_INACTIVE;
					SP_FIRE_1C=SP_FIRE_INACTIVE;
							//=======ROOM 1 KE ROOM 3=======//
							Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

									Nav_1C_To_3();
									SP_FIRE_R3=SP_FIRE_ACTIVE;
									if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
									{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
										if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
										{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
											if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
											{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
										}
									}

									//=======ROOM 2=======//
											//UPDATE BW LOCATION
											BW_LOCATION[1]= BW_LOCATION[0];
											BW_LOCATION[0]= LOCATION_ROOM;

											//RETURN TRIP NEEDED
											ROOM[2]=ROOM_3;


													//BW IN ROOM
													BW_Buzz(1);
													H_2017_Room();
													if(EXTINGUISHED_FIRE==1)break;

											//BW IN CORRIDOR
											BW_LOCATION[1]= BW_LOCATION[0];
											BW_LOCATION[0]= LOCATION_CORRIDOR;
									SP_FIRE_R3=SP_FIRE_INACTIVE;



//	while(EXTINGUISHED_FIRE==0)
//	{
//		//=======ROOM 4 KE ROOM 3=======//
//
//			Nav_4B_To_3();
//
//			SP_FIRE_R3=SP_FIRE_ACTIVE;
//
//			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
//				}
//			}
//				//=======ROOM 3=======//
//				//UPDATE BW LOCATION
//				BW_LOCATION[1]= BW_LOCATION[0];
//				BW_LOCATION[0]= LOCATION_ROOM;
//
//							//RETURN TRIP NEEDED
//							ROOM[2]=ROOM_3;
//
//						//BW IN ROOM
//						BW_Buzz(1);
//						H_2017_Room();
//						if(EXTINGUISHED_FIRE==1)break;
//
//				//BW IN CORRIDOR
//				BW_LOCATION[1]= BW_LOCATION[0];
//				BW_LOCATION[0]= LOCATION_CORRIDOR;
//
//			SP_FIRE_R3=SP_FIRE_INACTIVE;
//		//=======ROOM 3 KE ROOM 2=======//
//		UV_R2FLAG=UV_R2FLAG_ACTIVE;
//
//		if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
//			{
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
//				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);			}
//			}
//		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//		Nav_3_To_2();
//
//		if(Ping[PING_LEFT]>10)
//		{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//			if(Ping[PING_LEFT]>10)
//				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
//		}
//
//		if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
//		{
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);			}
//		}
//
////		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//				//=======ROOM 2=======//
//				//UPDATE BW LOCATION
//				BW_LOCATION[1]= BW_LOCATION[0];
//				BW_LOCATION[0]= LOCATION_ROOM;
//
//							//RETURN TRIP NEEDED
//							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
//							{
//								ROOM[2]=ROOM_2B;
//							}
//							else
//							{
//								ROOM[2]=ROOM_2A;
//							}
//
//						//BW IN ROOM
//						BW_Buzz(1);
//						H_2017_Room();
//						if(EXTINGUISHED_FIRE==1)break;
//
//				//BW IN CORRIDOR
//				BW_LOCATION[1]= BW_LOCATION[0];
//				BW_LOCATION[0]= LOCATION_CORRIDOR;
//
//		UV_R2FLAG=UV_R2FLAG_INACTIVE;
//
//		//=======ROOM 2 KE ROOM 1=======//
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//		{
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
//		}
//		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//		ROOM1_FLAG=ROOM1FLAG_ACTIVE;
//
//		if(Ping[PING_FRONT]<40)
//		{
//			Nav_2B_To_1BC();
//
////			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//			SP_FIRE_1B=SP_FIRE_ACTIVE;
////				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
////				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
////				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
////				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
////				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//
//		}
//		else
//		{
//			SP_FIRE_1C=SP_FIRE_ACTIVE;
//
//			Nav_2A_To_1BC();
//		}
//
//		if(SP_FIRE_1B==SP_FIRE_ACTIVE)
//		{
//			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//			if(Ping[PING_LEFT]>30)
//			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				if(Ping[PING_LEFT]>30)
//				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
//			}
//			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//				}
//			}
//			else
//			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
//				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
//					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//				}
//			}
//		}
//		if(SP_FIRE_1C==SP_FIRE_ACTIVE)
//		{
//			if(Ping[PING_RIGHT]<=10)
//			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//				if(Ping[PING_RIGHT]<=10)
//				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
//			}
//			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//					}
//				}
//
//		}
//
//				//=======ROOM 1=======//
//				//UPDATE BW LOCATION
//				BW_LOCATION[1]= BW_LOCATION[0];
//				BW_LOCATION[0]= LOCATION_ROOM;
//
//							//RETURN TRIP NEEDED
//							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
//							{
//								ROOM[2]=ROOM_1B;
//							}
//							else
//							{
//								ROOM[2]=ROOM_1C;
//							}
//
//						//BW IN ROOM
//						BW_Buzz(1);
//						H_2017_Room();
//						if(EXTINGUISHED_FIRE==1)break;
//
//				//BW IN CORRIDOR
//				BW_LOCATION[1]= BW_LOCATION[0];
//				BW_LOCATION[0]= LOCATION_CORRIDOR;


	}
}

/* func      : void H_ROOM_4B_EXC (void)
 * brief     : BW 2017 Navigation Routine. Home== R4B Exclusive
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Toni ( Wednesday, November 22th 2017)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_4B_EXC (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 4 KE ROOM 1=======//
		ROOM1_FLAG=ROOM1FLAG_ACTIVE;
		Nav_4B_To_1BC_EXC();

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)		//UBAH RUTE nav 4b to 2 UNTUK PINTU 1B
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R2 EXC");lcd_putstr(lcd);
			delay_ms(100);

			SP_FIRE_1B=SP_FIRE_INACTIVE;

			UV_R2FLAG=UV_R2FLAG_ACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right();

			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>10)
					{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
			}

			if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);			}
				}
			}
			//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

						//RETURN TRIP NEEDED
						ROOM[2]=ROOM_2B;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;

				//=======ROOM 2 KE ROOM 1=======//
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
				}
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

				ROOM1_FLAG=ROOM1FLAG_ACTIVE;

				Nav_2B_To_1BC();
				SP_FIRE_1B=SP_FIRE_ACTIVE;

				if(SP_FIRE_1B==SP_FIRE_ACTIVE)
				{
					if(Ping[PING_LEFT]>10)
					{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						if(Ping[PING_LEFT]>10)
						{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
					}
					if(Ping[PING_LEFT]>40)
					{
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_LEFT]>40)
							{
								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
					}
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
						{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}

						//=======ROOM 1=======//
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
						//UPDATE BW LOCATION
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_ROOM;

									//RETURN TRIP NEEDED
									ROOM[2]=ROOM_1B;

								//BW IN ROOM
								BW_Buzz(1);
								H_2017_Room();
								if(EXTINGUISHED_FIRE==1)break;

						//BW IN CORRIDOR
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_CORRIDOR;
				SP_FIRE_1B=SP_FIRE_INACTIVE;
						//=======ROOM 1 KE ROOM 3=======//
						Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

								Nav_1C_To_3();
								SP_FIRE_R3=SP_FIRE_ACTIVE;
//								if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//									if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//									{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//										if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//										{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
//									}
//								}

								//=======ROOM 2=======//
										//UPDATE BW LOCATION
										BW_LOCATION[1]= BW_LOCATION[0];
										BW_LOCATION[0]= LOCATION_ROOM;

										//RETURN TRIP NEEDED
										ROOM[2]=ROOM_3;


												//BW IN ROOM
												BW_Buzz(1);
												H_2017_Room();
												if(EXTINGUISHED_FIRE==1)break;

										//BW IN CORRIDOR
										BW_LOCATION[1]= BW_LOCATION[0];
										BW_LOCATION[0]= LOCATION_CORRIDOR;
								SP_FIRE_R3=SP_FIRE_INACTIVE;


		}
		else	// ROUTE TETAP KE RUANG 1 DAHULU UNTUK PINTU 1C
		{
			SP_FIRE_1C=SP_FIRE_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R1C EXC");lcd_putstr(lcd);
			delay_ms(100);


			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left();
				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

						//BW IN ROOM
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
						lcd_gotoxy(0,2);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
						lcd_gotoxy(0,3);sprintf(lcd,"ROOM");lcd_putstr(lcd);


						//RETURN TRIP NEEDED
						ROOM[2]=ROOM_1C;

						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 2=======//
		SP_FIRE_1C=SP_FIRE_INACTIVE;

		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		UV_R2FLAG=UV_R2FLAG_ACTIVE;

		Nav_1C_To_2();

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

						ROOM[2]=ROOM_2A;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;

		//=======ROOM 2 KE ROOM 3=======//
				if((Ping[PING_RIGHT])<=10)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				}
				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
					}
				}
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		Nav_2_To_3();

		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
		{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
			}
		}
		SP_FIRE_R3=SP_FIRE_ACTIVE;
				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;


		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 3 ====//

		Nav_TurnAround(TURN_RIGHT);

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;
		SP_FIRE_R3=SP_FIRE_INACTIVE;
				//=======ROOM 3 KE ROOM 2=======//
				if((Ping[PING_RIGHT])<=10)
							{
								Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
								if((Ping[PING_RIGHT])<=10)
									{
										Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
									}
							}
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
							{
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
								if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
								{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
									if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
										{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
								}
							}
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

				UV_R2FLAG=UV_R2FLAG_ACTIVE;
				Nav_3_To_2();

//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;
		//=======ROOM 2 KE ROOM 1=======//
		Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

		ROOM1_FLAG=ROOM1FLAG_ACTIVE;

		if(Ping[PING_FRONT]<40)
		{
			Nav_2B_To_1BC();

//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			SP_FIRE_1B=SP_FIRE_ACTIVE;
//				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
//				Dynamx_MovFwd3cm(12,HEXSPD_ULTRAFAST,IKCALC_ENABLE);

		}
		else
		{
			SP_FIRE_1C=SP_FIRE_ACTIVE;

			Nav_2A_To_1BC();
		}

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)
		{
			if(Ping[PING_LEFT]>30)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>30)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);	}
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);	}
				}
			}
		}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;
		}
	}
}

/* func      : void H_ROOM_4B_VER2 (void)
 * brief     : BW 2017 Navigation Routine. Home== R4B Exclusive
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Toni ( Wednesday, November 22th 2017)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_4B_VER2 (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 4 KE ROOM 1=======//
//		ROOM1_FLAG=ROOM1FLAG_ACTIVE;
		Nav_4B_To_1A();

		if(CAT_FLAG_A==CAT_DETECTED || CAT_FLAG_B==CAT_DETECTED)
		{
			if(Ping[PING_LEFT]>15)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
			else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}

		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;
		FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_1A;

						//BW IN ROOM
						BW_Buzz(1);
						H_2017_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
			FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			//=======ROOM 1 KE ROOM 2=======//
			Nav_1C_To_3();

			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
			SP_FIRE_R3=SP_FIRE_ACTIVE;
	//		if(Ping[PING_FRONT]<40)
	//		{
	//			Nav_1B_To_2();
	//		}
	//		else
	//		{
	//			Nav_1C_To_2();
	//		}

	//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					ROOM[2]=ROOM_3;


							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;
			SP_FIRE_R3=SP_FIRE_INACTIVE;
					//=======ROOM 3 KE ROOM 2=======//
			if((Ping[PING_RIGHT])<=10)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				}
	//		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	//			{
	//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//				}
	//			}
			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);
			UV_R2FLAG=UV_R2FLAG_ACTIVE;
			Nav_3_To_2();

			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>10)
					{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
			}

			if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
			}
			else
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
			}
			//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			//=======ROOM 2=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
					{
						ROOM[2]=ROOM_2B;
					}
					else
					{
						ROOM[2]=ROOM_2A;
					}

					//BW IN ROOM
					BW_Buzz(1);
					H_2017_Room();
					if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			UV_R2FLAG=UV_R2FLAG_INACTIVE;
		}
		else
		{
			if(Ping[PING_LEFT]>15)
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				if(Ping[PING_LEFT]>15)
				{
					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
				}
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
			else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}

					//=======ROOM 1=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_1A;

							//BW IN ROOM
							BW_Buzz(1);
							H_2017_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

				ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;

				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

				//=======ROOM 1A KE ROOM 3=======//
				Nav_1A_To_3();

				SP_FIRE_R3=SP_FIRE_ACTIVE;
						//=======ROOM 3=======//
						//UPDATE BW LOCATION
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_ROOM;

									//RETURN TRIP NEEDED
									ROOM[2]=ROOM_3;

								//BW IN ROOM
								BW_Buzz(1);
								H_2017_Room();
								if(EXTINGUISHED_FIRE==1)break;

						//BW IN CORRIDOR
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_CORRIDOR;

				SP_FIRE_R3=SP_FIRE_INACTIVE;
				//=======ROOM 3 KE ROOM 2=======//
				Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

				Nav_3_To_2();

				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
					if(Ping[PING_LEFT]>10)
					{	Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);}
				}

				if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
				{
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
					{	Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
				}
				else
				{
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT]+4))
					{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
				}

		//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

						//=======ROOM 2=======//
						//UPDATE BW LOCATION
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_ROOM;

									//RETURN TRIP NEEDED
									if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
									{
										ROOM[2]=ROOM_2B;
									}
									else
									{
										ROOM[2]=ROOM_2A;
									}

								//BW IN ROOM
								BW_Buzz(1);
								H_2017_Room();
								if(EXTINGUISHED_FIRE==1)break;

						//BW IN CORRIDOR
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_CORRIDOR;

		}
	}
}

/* func      : void H_Correction_Left (void)
 * brief     : BW 2017 Position correction referencing left side rangefinder
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_Correction_Left (void)
{
	if(Ping[PING_LEFT]<14)
	{
		mov_deflect_right(FAST,CLOSE);
	}
	if(Ping[PING_LEFT]<14)
	{
		mov_deflect_right(FAST,CLOSE);
	}
}

/* func      : void H_Correction_Right (void)
 * brief     : BW 2017 Position correction referencing right side rangefinder
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_Correction_Right (void)
{
	if(Ping[PING_RIGHT]<14)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_RIGHT]<14)
	{
		mov_deflect_left(FAST,CLOSE);
	}
}

/* func      : void H_Correction_Right (void)
 * brief     : BW 2017 Position correction after exiting room
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_Correction_ExitRoom (void)
{
	if (Ping[PING_RIGHT]<75)
	{
		if(Ping[PING_ASKEW_RIGHT]>Ping[PING_RIGHT])
		{
//			while(Ping[PING_ASKEW_RIGHT]>Ping[PING_RIGHT])
//			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//			}
		}
		if(Ping[PING_ASKEW_RIGHT]>Ping[PING_RIGHT])
		{
//			while(Ping[PING_ASKEW_RIGHT]>Ping[PING_RIGHT])
//			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//			}
		}
		if(Ping[PING_ASKEW_RIGHT]<Ping[PING_RIGHT])
		{
//			while(Ping[PING_ASKEW_RIGHT]<Ping[PING_RIGHT])
//			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//			}
		}
		if(Ping[PING_ASKEW_RIGHT]<Ping[PING_RIGHT])
		{
//			while(Ping[PING_ASKEW_RIGHT]<Ping[PING_RIGHT])
//			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//			}
		}
	}
	else
	{
		if(Ping[PING_ASKEW_LEFT]>Ping[PING_LEFT])
		{
//			while(Ping[PING_ASKEW_LEFT]>Ping[PING_LEFT])
//			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//			}
		}
		if(Ping[PING_ASKEW_LEFT]>Ping[PING_LEFT])
		{
//			while(Ping[PING_ASKEW_LEFT]>Ping[PING_LEFT])
//			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//			}
		}
		if(Ping[PING_ASKEW_LEFT]<Ping[PING_LEFT])
		{
//			while(Ping[PING_ASKEW_LEFT]<Ping[PING_LEFT])
//			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//			}
		}
		if(Ping[PING_ASKEW_LEFT]<Ping[PING_LEFT])
		{
//			while(Ping[PING_ASKEW_LEFT]<Ping[PING_LEFT])
//			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//			}
		}
	}
}


/* func      : void Bumper_Action(void)
 * brief     : BW Evading obstacle detected by Limit Switch's Bumper
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Ryan (Friday, December 2nd 2016)
 * Revised BY: Ver.2 : Ryan (Saturday, April 22nd, 2017
 * 						Added Dynamixel hexapod locomotion
 * 			   Ver.3 : Hafidin (Tue, May 2nd, 2017)
 * 			   			Antisipate bumper stuck
 * 			   Ver.4 : Hafidin (Wed, May 3rd. 2017)
 * 			   			Antisipate Furniture
 * programmer's Note: This routine differ from usual Evade_Wall routine
 */
void Bumper_Action(void)
{
	if(BW_LOCATION[0]==LOCATION_ROOM)
	{
		if((FIRESCAN_DIRECTION==SCAN_RIGHT) || (FOLLOW_FLAG==KIRI))
		{
			GetBumper();
			if(BUMPER[LEFT]==ACTIVE)
			{
				Dynamx_MovBwd(3,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			GetBumper();
			if(BUMPER[RIGHT]==ACTIVE)
			{
				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			if((((Ping[PING_ASKEW_RIGHT]>2) && (Ping[PING_ASKEW_RIGHT]<8)) && (Ping[PING_RIGHT]>20)) && (Ping[PING_LEFT]<18))
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT]>2) && (Ping[PING_ASKEW_RIGHT]<8)) && (Ping[PING_RIGHT]>20))
				{
					Dynamx_MovBwd(3,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				}
				else
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FURNITURE FREE");lcd_putstr(lcd);
					delay_ms(50);
				}
			}
		}
		else if((FIRESCAN_DIRECTION==SCAN_LEFT) || (FOLLOW_FLAG==KANAN))
		{
			GetBumper();
			if(BUMPER[RIGHT]==ACTIVE)
			{
				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			GetBumper();
			if(BUMPER[LEFT]==ACTIVE)
			{
				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			if((((Ping[PING_ASKEW_LEFT]>2) && (Ping[PING_ASKEW_LEFT]<8)) && (Ping[PING_LEFT]>20)) && (Ping[PING_RIGHT]<18))
			{
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT]>2) && (Ping[PING_ASKEW_LEFT]<8)) && (Ping[PING_LEFT]>20))
				{
					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				}
				else
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FURNITURE FREE");lcd_putstr(lcd);
					delay_ms(50);
				}
			}
		}
	}
	else
	{
		GetBumper();
		while(BUMPER[LEFT]==ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BUMPER ACTIVATED");lcd_putstr(lcd);

			if(Ping[PING_RIGHT]<10)
			{
				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			else
			{
				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			GetBumper();
			if(BUMPER[LEFT]==INACTIVE)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"BUMPER INACTIVE");lcd_putstr(lcd);
				break;
			}
		}
		while(BUMPER[RIGHT]==ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BUMPER ACTIVATED");lcd_putstr(lcd);

			if(Ping[PING_LEFT]<10)
			{
				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}
			else
			{
				Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			}

			GetBumper();
			if(BUMPER[RIGHT]==INACTIVE)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"BUMPER INACTIVE");lcd_putstr(lcd);
				break;
			}
		}
	}

}

void Bumper_Action_Left(void)
{
	GetBumper();
	if(BUMPER[LEFT]==ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BUMPER ACTIVATED");lcd_putstr(lcd);

		Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		GetBumper();
		if(BUMPER[LEFT]==INACTIVE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BUMPER INACTIVE");lcd_putstr(lcd);
//			break;
		}
	}
}

void Bumper_Action_Right(void)
{
	GetBumper();
	if(BUMPER[RIGHT]==ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BUMPER ACTIVATED");lcd_putstr(lcd);
		Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

		GetBumper();
		if(BUMPER[RIGHT]==INACTIVE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BUMPER INACTIVE");lcd_putstr(lcd);
//			break;
		}
	}
}
/* func      : void Bumper_Follow(void)
 * brief     : BW Evading obstacle detected by Limit Switch's Bumper, by activating wall following
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, April 20th 2017)
 * Revised BY: Ver.2 > Hafidin (Friday, April 28th 2017)
 * programmer's Note: Should be able to pass the furniture blocking the view to candle location
 */
/* func      : void Furniture_Check(void)
 * brief     : BW Evading Furniture
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Saturday, April 29th 2017)
 * Revised BY:
 * programmer's Note: Should be able to pass the furniture blocking the view to candle location
 */
void Furniture_Check(void)
{
	int x;
	int furniture=0;
	if(FIRESCAN_DIRECTION==SCAN_RIGHT)
	{
		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"CHECK RIGHT");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FURNITURE X");lcd_putstr(lcd);
		delay_ms(50);

		for(x=0;x<=1;x++)
		{
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			if(Ping[PING_FRONT]<25){furniture=1;}
			if(Ping[PING_FRONT]<25)break;
		}

		if(furniture==1)
		{
			furniture=0;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FURNITURE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
			delay_ms(50);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

			BW_PID_Init();
			while(FlameSenseDigi[0]!=4)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);

				BW_FollowCounter_Left(1);
				cnt++;
				if(cnt>20)break;

//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5))break;
				if(FlameFrontDigi[0]==4)break;
			}
		}
		else
		{
			for(x=0;x<=1;x++)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
		}
	}
	else if(FIRESCAN_DIRECTION==SCAN_LEFT)
	{
		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"CHECK LEFT");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FURNITURE X");lcd_putstr(lcd);
		delay_ms(50);

		for(x=0;x<=1;x++)
		{
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			if(Ping[PING_FRONT]<25){furniture=1;}
			if(Ping[PING_FRONT]<25)break;
		}

		if(furniture==1)
		{
			furniture=0;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FURNITURE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
			delay_ms(50);

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);

			BW_PID_Init();
			while(FlameSenseDigi[0]!=4)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);

				BW_FollowCounter_Right(1);
				cnt++;
				if(cnt>20)break;

//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5))break;
				if(FlameFrontDigi[0]==4)break;
			}
		}
		else
		{
			for(x=0;x<=1;x++)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
		}
	}
	else
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW FIREFIGHT");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"ROOM4AB MODE");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FURNITURE X");lcd_putstr(lcd);
		delay_ms(100);
	}
}

/* func      : void Furniture_Avoider(void)
 * brief     : BW Evading Furniture
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Friday, June 9th 2017)
 * Revised BY:
 * programmer's Note: Should be able to pass the furniture blocking the view to candle location
 */
void Bumper_Follow(void)
{
	BW_PID_Init_Furniture();
	cnt=0;
	int g=0;
	if(FIRESCAN_DIRECTION==SCAN_RIGHT)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BUMPER FOLLOW");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);

		GetBumper();
		if(BUMPER[LEFT]==ACTIVE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BUMPER FOLLOW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"NO FOLLOW");lcd_putstr(lcd);

			Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			for(g=0;g<=5;g++)
			{
				TRACER_STAT=TRACER_BLACK;
				BW_FollowCounter_Left(1);

				if(g>1)
				{
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
//						break;
						TRACER_STAT=TRACER_BLACK;
					}
					TCSlave_Check();

					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5))break;
					if(g==3 && ((ROOM[2]==ROOM_3) ||(ROOM[2]==ROOM_2A)) && ((FlameSenseDigi[0]==2)||(FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5)))break;
//					if((FlameSenseDigi[0]==3))Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);break;
					if(FlameFrontDigi[0]==4)break;
				}
			}

//			BW_PID_Init();
//			BW_FollowCounter_Left(1);

//			GetBumper();
//			if(BUMPER[LEFT]==INACTIVE) break;
		}
		GetBumper();
		if(((BUMPER[RIGHT]==ACTIVE) || ((Ping[PING_ASKEW_RIGHT]<6) && (Ping[PING_RIGHT]>20))) && (Ping[PING_LEFT]<6))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BUMPER FOLLOW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FOLLOW");lcd_putstr(lcd);

			Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
			BW_PID_Init_Furniture();
			while(FlameSenseDigi[0]!=4)
			{
				TRACER_STAT=TRACER_BLACK;

//				mov_rot_right(FAST_LEVEL_2,FAR);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
//				delay_ms(100);

				BW_FollowCounter_Left(1);
				cnt++;
				if(cnt>15)break;

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
//					break;
					TRACER_STAT=TRACER_BLACK;
				}
				TCSlave_Check();

//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5))break;
				if(cnt==3 && ((ROOM[2]==ROOM_3) ||(ROOM[2]==ROOM_2A)||(ROOM[2]==ROOM_2B)) && ((FlameSenseDigi[0]==2)||(FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5)))break;
//				if((FlameSenseDigi[0]==3))Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);break;
				if(FlameFrontDigi[0]==4)break;
			}

//			GetBumper();
//			if(BUMPER[RIGHT]==INACTIVE) break;
		}
	}
	else if(FIRESCAN_DIRECTION==SCAN_LEFT)
	{
		TRACER_STAT=TRACER_BLACK;

		EXTINGUISHER_OFF;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BUMPER FOLLOW");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);

		GetBumper();
		if(BUMPER[RIGHT]==ACTIVE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BUMPER FOLLOW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);

			Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			for(g=0;g<=5;g++)
			{
				BW_FollowCounter_Right(1);

				if(g>2)
				{
					TCSlave_Check();
					if (TRACER_STAT==TRACER_WHITE)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
						delay_ms(50);
						Dynamx_MovBwd(8,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
						Nav_TurnAround(TURN_LEFT);
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
						TRACER_STAT=TRACER_BLACK;

//						break;
					}
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3))break;
					if(FlameFrontDigi[0]==4)break;
				}
			}

//			BW_PID_Init();
//			BW_FollowCounter_Right(1);

//			GetBumper();
//			if(BUMPER[RIGHT]==INACTIVE) break;
		}
		GetBumper();
		if(((BUMPER[LEFT]==ACTIVE) || ((Ping[PING_ASKEW_LEFT]<6) && (Ping[PING_LEFT]>20))) && (Ping[PING_RIGHT]<11))
		{
			TRACER_STAT=TRACER_BLACK;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BUMPER FOLLOW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);

			Dynamx_MovBwd(6,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

			BW_PID_Init_Room();

			while(FlameSenseDigi[0]!=4)
			{
//				mov_rot_right(FAST_LEVEL_2,FAR);
//				Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
//				delay_ms(100);
				BW_FollowCounter_Right(1);
				cnt++;
				if(cnt>15)break;

				TCSlave_Check();
				if (TRACER_STAT==TRACER_WHITE)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
					delay_ms(50);
					Dynamx_MovBwd(8,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					Nav_TurnAround(TURN_LEFT);
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					TRACER_STAT=TRACER_BLACK;

//						break;
				}
//				if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
				if((FlameSenseDigi[0]==4) /*|| (FlameSenseDigi[0]==3)*/ || (FlameSenseDigi[0]==3))break;
				if(FlameFrontDigi[0]==4)break;
			}

//			GetBumper();
//			if(BUMPER[LEFT]==INACTIVE) break;
		}
	}
}

void Furniture_Avoider(void)
{
	int g,CNT=0;
	if(BW_LOCATION[0]==LOCATION_ROOM)
	{
		if((FIRESCAN_DIRECTION==SCAN_RIGHT) || (FOLLOW_FLAG==KIRI))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FURNITURE AVOID");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);

			Get_IR();
			if(((INFRARED[IR_BUMPER_RIGHT]==IR_DETECTED) && (Ping[PING_FRONT]>25) && (Ping[PING_ASKEW_LEFT]<12)) && (Ping[PING_RIGHT]>20))
			{
				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				Get_IR();
				if(((INFRARED[IR_BUMPER_RIGHT]==IR_DETECTED) && (Ping[PING_FRONT]>25) && (Ping[PING_ASKEW_LEFT]<12)) && (Ping[PING_RIGHT]>20))
				{
					if(Ping[PING_ASKEW_RIGHT]<10)
					{
						Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					}
//							Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					while(Ping[PING_FRONT]>20)
					{
						Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
						CNT++;
						if(CNT>=4){CNT=0;break;}
					}
					while(Ping[PING_FRONT]<20)
					{
						Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
						CNT++;
						if(CNT>=4){CNT=0;break;}
					}
	//				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

//					for(g=0;g<=4;g++)
//					{
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//						if(Ping[PING_ASKEW_LEFT]<20)break;
//					}

					if(UV_Lock==UVLOCK_ACTIVE)
					{
						TRACER_STAT=TRACER_BLACK;
						BW_PID_Init_Furniture();
						for(g=0;g<=5;g++)
						{
							BW_FollowCounter_Left(1);

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
		//						break;
								TRACER_STAT=TRACER_BLACK;
							}
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
								TRACER_STAT=TRACER_BLACK;
		//						break;
							}
							if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5))break;
//							if((FlameSenseDigi[0]==3))Dynamx_MovFwd4cm(8,HEXSPD_MEDFAST,IKCALC_DISABLE);break;
							if(FlameFrontDigi[0]==4)break;
						}
					}

				}

			}

		}
		else if((FIRESCAN_DIRECTION==SCAN_LEFT) || (FOLLOW_FLAG==KANAN))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FURNITURE AVOID");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);

			Get_IR();
			if(((INFRARED[IR_BUMPER_LEFT]==IR_DETECTED) && (Ping[PING_FRONT]>25) && (Ping[PING_ASKEW_RIGHT]<12)) && (Ping[PING_LEFT]>20))
			{
				Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

				Get_IR();
				if(((INFRARED[IR_BUMPER_LEFT]==IR_DETECTED) && (Ping[PING_FRONT]>25) && (Ping[PING_ASKEW_RIGHT]<12)) && (Ping[PING_LEFT]>20))
				{
					if(Ping[PING_ASKEW_LEFT]<10)
					{
						Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					}

//					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					while(Ping[PING_FRONT]>20)
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						CNT++;
						if(CNT>=4){CNT=0;break;}
					}
					while(Ping[PING_FRONT]<20)
					{
						Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
						CNT++;
						if(CNT>=4){CNT=0;break;}
					}
	//				Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

//					for(g=0;g<=4;g++)
//					{
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

//						if(Ping[PING_ASKEW_RIGHT]<20)break;
//					}

					if(UV_Lock==UVLOCK_ACTIVE)
					{
						TRACER_STAT=TRACER_BLACK;
						BW_PID_Init_Furniture();
						for(g=0;g<=5;g++)
						{
							BW_FollowCounter_Right(1);

							TCSlave_Check();
							if (TRACER_STAT==TRACER_WHITE)
								{
									lcd_display_clear();
									lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
									lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
									delay_ms(50);

									Dynamx_MovBwd(8,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
									Nav_TurnAround(TURN_LEFT);
									Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
									TRACER_STAT=TRACER_BLACK;

//									break;
								}

							if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) /*|| (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7)*/)break;
							if(FlameFrontDigi[0]==4)break;
						}
					}
				}
			}

		}
	}
}

/* func      : void BW_FollowTracer_Right(void)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, February 9th 2017)
 * Revised BY: 	Ver.2 -> Hafidin (Wed, Feb 22th 2017)
 * 				Ver.3 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * 				Ver.4 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */
void BW_FollowTracer_Right(void)
{

	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;

	CAT_FLAG = CAT_NOT_DETECTED;
	TRACER_STAT=TRACER_BLACK;

	FOLLOW_CALC=KANAN;
//	FOLLOW_BREAK=KANAN;

	//ACTIVATE FOLLOWMODE TRACER
	FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
	TCSlave_Check();
//	Tracer_Check();

	while(
			(TCS3200_SLV_DATA[1]!=TRACER_WHITE) &&
			(TRACER_STAT==TRACER_BLACK) &&
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
//		Tracer_Check();
		Cat_Avoider();
		Furniture_Avoider();

		if (Ping[PING_FRONT]<=12)
		{
//			Tracer_Check();
			if (TRACER_STAT==TRACER_WHITE)break;

			if(BW_LOCATION[0]==LOCATION_ROOM)
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
			else
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}
		}
		else
		{
//			Tracer_Check();
			TCSlave_Check();
			if (TRACER_STAT==TRACER_WHITE)break;

			PID_BWFollowTracer_Right();

			if (TRACER_STAT==TRACER_WHITE)break;
		}

		Bumper_Action();
	}
	FOLLOW_CALC=KOSONG;
	//FOLLOW_BREAK=KOSONG;
}

/* func      : void PID_BWFollowTracer_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, February 9th 2017)
 * Revised BY: Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_BWFollowTracer_Right(void)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd," FOLLOW RIGHT ");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd," PID VALUES ");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd," pid_L: %d ",(int)PID_F_L.pid_value[0]);lcd_putstr(lcd);
//	lcd_gotoxy(0,3);sprintf(lcd," pid_R: %d ",(int)PID_F_R.pid_value[0]);lcd_putstr(lcd);

//	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
//	PID_Calc_RightRule();
//	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);

	while(OVERRIDE==0)
	{
//		Tracer_Check();
		if (TRACER_STAT==TRACER_WHITE)break;

		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=15)
					{
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						}
						else
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						if (TRACER_STAT==TRACER_WHITE)break;
//						while(Ping[PING_FRONT]<=15)
//						{
//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR, IKCALC_ENABLE);
//						}
//						if(Ping[PING_RIGHT]>=10)Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if(Ping[PING_RIGHT]>=10)Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if (TRACER_STAT==TRACER_WHITE)break;
					}

					if(OVERRIDE==1){break;}
					if (TRACER_STAT==TRACER_WHITE)break;
					if (OVERRIDE==0)
					{
						Cat_Avoider();

						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

//						Tracer_Check();
						if (TRACER_STAT==TRACER_WHITE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//						{
//							Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//						}
//						else
//						{
//							Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//						}
						Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
						if (TRACER_STAT==TRACER_WHITE)break;
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_FRONT]<=15)
					{
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						}
						else
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						if (TRACER_STAT==TRACER_WHITE)break;
//						while(Ping[PING_FRONT]<=15)
//						{
//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR, IKCALC_ENABLE);
//						}
//						if(Ping[PING_RIGHT]>=10)Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if(Ping[PING_RIGHT]>=10)Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if (TRACER_STAT==TRACER_WHITE)break;
					}

					if(OVERRIDE==1){break;}
					if (TRACER_STAT==TRACER_WHITE)break;
					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>15)
							{
								if (TRACER_STAT==TRACER_WHITE)break;
//								if(CAT_DETECTOR==CAT_ACTIVATED)
//								{
//									Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//								}
//								else
//								{
//									Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//								}
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
							}
							while(Ping[PING_RIGHT]>=16)
							{
//								Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
								if(BW_LOCATION[0]==LOCATION_ROOM)
								{
									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
								}
								else
								{
									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
								}
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							Cat_Avoider();
							Furniture_Avoider();
							Bumper_Action();

//							RIGHT_OVERFLOW_COUNTER=0;
//							LEFT_OVERFLOW_COUNTER=0;
//							Tracer_Check();
							if (TRACER_STAT==TRACER_WHITE)break;
//							LEFT_OVERFLOW_COUNTER=0;
//							lcd_display_clear();
//							lcd_gotoxy(0,0);sprintf(lcd," RIGHT OVERFLOW ");lcd_putstr(lcd);
//							lcd_gotoxy(0,1);sprintf(lcd," COUNT: %d ",RIGHT_OVERFLOW_COUNTER);lcd_putstr(lcd);
//
//							if(RIGHT_OVERFLOW_COUNTER>30)
//							{
//								RIGHT_OVERFLOW_COUNTER=0;
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							}
//							RIGHT_OVERFLOW_COUNTER++;
							Dynamx_CurveRight_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);

//							if(BUMPER[RIGHT]==ACTIVE)
//							{
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
//							}
							if (TRACER_STAT==TRACER_WHITE)break;

						}

						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
				{

					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_FRONT]<=15)
					{
						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						}
						else
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

						if (TRACER_STAT==TRACER_WHITE)break;
//						while(Ping[PING_FRONT]<=15)
//						{
//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR, IKCALC_ENABLE);
//						}
//						if(Ping[PING_RIGHT]>=10)Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if(Ping[PING_RIGHT]>=10)Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if (TRACER_STAT==TRACER_WHITE)break;
					}
					if (TRACER_STAT==TRACER_WHITE)break;
					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE) break;

						if(WINDUP_LEFT_COUNTER>=25)
							{
								BW_Buzz(5);
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
								delay_ms(100);

								while(Ping[PING_FRONT]>15)
								{
									if (TRACER_STAT==TRACER_WHITE)break;
//									if(CAT_DETECTOR==CAT_ACTIVATED)
//									{
//										Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//									}
//									else
//									{
//										Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//									}
									Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
								}
								while(Ping[PING_RIGHT]>=16)
								{
//									Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
									if(BW_LOCATION[0]==LOCATION_ROOM)
									{
										Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
									}
									else
									{
										Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
									}
//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
								}
								//RESET WINDUP RIGHT COUNTER
								WINDUP_LEFT_COUNTER=0;

								//REINIT PID
								BW_PID_Init();
							}
						else
						{
							Cat_Avoider();
							Furniture_Avoider();
							Bumper_Action();
//							RIGHT_OVERFLOW_COUNTER=0;
//							LEFT_OVERFLOW_COUNTER=0;
//							Tracer_Check();
							if (TRACER_STAT==TRACER_WHITE)break;
//							RIGHT_OVERFLOW_COUNTER=0;
//							lcd_display_clear();
//							lcd_gotoxy(0,0);sprintf(lcd," LEFT OVERFLOW ");lcd_putstr(lcd);
//							lcd_gotoxy(0,1);sprintf(lcd," COUNT: %d ",LEFT_OVERFLOW_COUNTER);lcd_putstr(lcd);
//
//							if(LEFT_OVERFLOW_COUNTER>30)
//							{
//								LEFT_OVERFLOW_COUNTER=0;
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							}
							Dynamx_CurveLeft_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
//							LEFT_OVERFLOW_COUNTER++;

//							Dynamx_CurveLeft_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
							if (TRACER_STAT==TRACER_WHITE)break;


						}

						OVERRIDE=1;
					}
				}
		}
	}

}

/* func      : void BW_FollowTracer_Left(void)
 * brief     : Hexapod Dynamixel Wall Following Left Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, February 10th 2017)
 * Revised BY: 	Rev.1. -> Hafidin (Wed, Feb 22th 2017)
 * 				Ver.3 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * 				Ver.4 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */
void BW_FollowTracer_Left(void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;
	CAT_FLAG=CAT_NOT_DETECTED;

	FOLLOW_CALC=KIRI;
//	FOLLOW_BREAK=KIRI;
	//ACTIVATE FOLLOWMODE TRACER
	FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
	TCSlave_Check();

	while(
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(TCS3200_SLV_DATA[1]!=TRACER_WHITE) &&
			(TRACER_STAT==TRACER_BLACK) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();
		Furniture_Avoider();

		if (Ping[PING_FRONT]<=15)
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");

//			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
			if(BW_LOCATION[0]==LOCATION_ROOM)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
			}
			else
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}

//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			if(CAT_DETECTOR==CAT_ACTIVATED)
//			{
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			}
//			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			while(Ping[PING_FRONT]<=15)
//			{
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			}
//			if(Ping[PING_LEFT]>=10)Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			if(Ping[PING_LEFT]>=10)Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			if (TRACER_STAT==TRACER_WHITE)break;
		}
		else
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			PID_BWFollowTracer_Left();
			if (TRACER_STAT==TRACER_WHITE)break;
		}
		if (TRACER_STAT==TRACER_WHITE)break;

		Bumper_Action();
	}
	FOLLOW_CALC=KOSONG;
	//FOLLOW_BREAK=KOSONG;
}

/* func      : void PID_BWFollowTracer_Left(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, February 10th 2017)
 * Revised BY: Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_BWFollowTracer_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd," FOLLOW LEFT ");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd," PID VALUES ");lcd_putstr(lcd);
//	lcd_gotoxy(0,3);sprintf(lcd," pid_L: %d ",(int)PID_F_L.pid_value[0]);lcd_putstr(lcd);
	//lcd_gotoxy(0,2);sprintf(lcd," pid_R: %d ",(int)PID_F_R.pid_value[0]);lcd_putstr(lcd);

//	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
				{
				if (TRACER_STAT==TRACER_WHITE)break;
					if (Ping[PING_FRONT]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						}
						else
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						}
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

						if (TRACER_STAT==TRACER_WHITE)break;

//						while(Ping[PING_FRONT]<=15)
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						}
//						if(Ping[PING_LEFT]>=10)Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if(Ping[PING_LEFT]>=10)Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if (TRACER_STAT==TRACER_WHITE)break;
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						Cat_Avoider();

						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_WHITE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//							}
//							else
//							{
//								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//							}
						Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
						if (TRACER_STAT==TRACER_WHITE)break;
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_L.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_FRONT]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						}
						else
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						}
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);

						if (TRACER_STAT==TRACER_WHITE)break;
//						while(Ping[PING_FRONT]<=15)
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						}
//						if(Ping[PING_LEFT]>=10)Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if(Ping[PING_LEFT]>=10)Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if (TRACER_STAT==TRACER_WHITE)break;
					}

					if(OVERRIDE==1){break;}
					if (TRACER_STAT==TRACER_WHITE)break;
					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>15)
							{
//								Dynamx_MovFwd3cm(3, HEXSPD_ULTRAFAST, IKCALC_DISABLE);
//								if(CAT_DETECTOR==CAT_ACTIVATED)
//									{
//										Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//									}
//									else
//									{
//										Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//									}
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
							}
							while(Ping[PING_LEFT]>=16)
							{
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
								if(BW_LOCATION[0]==LOCATION_ROOM)
								{
									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
								}
								else
								{
									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
								}
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							Cat_Avoider();
							Furniture_Avoider();
							Bumper_Action();

//							LEFT_OVERFLOW_COUNTER=0;

							if (TRACER_STAT==TRACER_WHITE)break;
//							if(RIGHT_OVERFLOW_COUNTER>30)
//							{
//								RIGHT_OVERFLOW_COUNTER=0;
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							}
							Dynamx_CurveRight_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0], IKCALC_DISABLE);
//							RIGHT_OVERFLOW_COUNTER++;
							if (TRACER_STAT==TRACER_WHITE)break;

						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_L.pid_value[0]=13;
//					}

					if (Ping[PING_FRONT]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
						}
						else
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						}
//						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						if (TRACER_STAT==TRACER_WHITE)break;
//						while(Ping[PING_FRONT]<=15)
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						}
//						if(Ping[PING_LEFT]>=10)Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if(Ping[PING_LEFT]>=10)Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
//						if (TRACER_STAT==TRACER_WHITE)break;

					}

					if(OVERRIDE==1){break;}
					if (TRACER_STAT==TRACER_WHITE)break;
					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>15)
							{
//								Dynamx_MovFwd3cm(3, HEXSPD_ULTRAFAST, IKCALC_DISABLE);
//								if(CAT_DETECTOR==CAT_ACTIVATED)
//									{
//										Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//									}
//									else
//									{
//										Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//									}
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
							}
							while(Ping[PING_LEFT]>=16)
							{
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
								if(BW_LOCATION[0]==LOCATION_ROOM)
								{
									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
								}
								else
								{
									Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
								}
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							Cat_Avoider();
							Furniture_Avoider();
							Bumper_Action();
//							RIGHT_OVERFLOW_COUNTER=0;
							if (TRACER_STAT==TRACER_WHITE)break;

//							if(LEFT_OVERFLOW_COUNTER>30)
//							{
//								LEFT_OVERFLOW_COUNTER=0;
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							}
							Dynamx_CurveLeft_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0], IKCALC_DISABLE);
//							LEFT_OVERFLOW_COUNTER++;
							if (TRACER_STAT==TRACER_WHITE)break;


						}
						OVERRIDE=1;
					}
				}
		}
	}

}


/* func      : void BWFollowCarpet_Right(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, February 10th 2017)
 * Revised By: Ver.2 -> Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.3 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * 			   Ver.4 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */
void BWFollowCarpet_Right(int CARPET_CODE, int FOLLOW_MODE)
{
//	int counter;
	//int limit=15;
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	FOLLOWMODE_FLAG=FOLLOW_CARPET_ACTIVE;
	TCSlave_Check();

	FOLLOW_CALC=KANAN;

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG=CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL: //BW FOLLOW WHILE CARPET == X
				{
					while( (TCS3200_SLV_DATA[1]==CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=15)
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
						}
						else
						{
							PID_BWFollowCarpet_Right();
						}

						Bumper_Action();

					}

				}break;


		case INVERSE: ////BW FOLLOW WHILE CARPET != X
				{
					while( (TCS3200_SLV_DATA[1]!=CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, CMD_GET_TRACER);
						//TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=15)
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
						}
						else
						{
							PID_BWFollowCarpet_Right();
						}

						Bumper_Action();
					}

				}break;
	}
	FOLLOW_CALC=KOSONG;
}


/* func      : void PID_BWFollowCarpet_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, February 10th 2017)
 * Revised BY: Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_BWFollowCarpet_Right(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
//	PID_Calc_RightRule();
//	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd," FOLLOW CARPET RIGHT ");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd," PID VALUES ");lcd_putstr(lcd);
////	lcd_gotoxy(0,1);sprintf(lcd," pid_L: %d ",(int)PID_F_L.pid_value[0]);lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd," pid_R: %d ",(int)PID_F_R.pid_value[0]);lcd_putstr(lcd);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=15)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						Cat_Avoider();

						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//							}
//							else
//							{
//								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//							}
						Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_FRONT]<=15)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
//								if(CAT_DETECTOR==CAT_ACTIVATED)
//									{
//										Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//									}
//									else
//									{
//										Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//									}
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
							}
							while(Ping[PING_RIGHT]>=16)
							{
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							Cat_Avoider();

//							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;
//							lcd_display_clear();
//							lcd_gotoxy(0,0);sprintf(lcd," righT OVERFLOW ");lcd_putstr(lcd);
//							lcd_gotoxy(0,1);sprintf(lcd," COUNT: %d ",RIGHT_OVERFLOW_COUNTER);lcd_putstr(lcd);
//
//							if(RIGHT_OVERFLOW_COUNTER>10)
//							{
//								RIGHT_OVERFLOW_COUNTER=0;
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							}
//							RIGHT_OVERFLOW_COUNTER++;
							Dynamx_CurveRight_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_FRONT]<=15)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
//								if(CAT_DETECTOR==CAT_ACTIVATED)
//									{
//										Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//									}
//									else
//									{
//										Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//									}
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
							}
							while(Ping[PING_RIGHT]>=16)
							{
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							Cat_Avoider();

//							RIGHT_OVERFLOW_COUNTER=0;
//							lcd_display_clear();
//							lcd_gotoxy(0,0);sprintf(lcd," LEFT OVERFLOW ");lcd_putstr(lcd);
//							lcd_gotoxy(0,1);sprintf(lcd," COUNT: %d ",LEFT_OVERFLOW_COUNTER);lcd_putstr(lcd);
//
//							if(LEFT_OVERFLOW_COUNTER>10)
//							{
//								LEFT_OVERFLOW_COUNTER=0;
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							}
							Dynamx_CurveLeft_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
//							LEFT_OVERFLOW_COUNTER++;
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void BWFollowCarpet_Left(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Hexapod Dynamixel Wall Following Left Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, February 10th 2017)
 * Revised By: Ver. 2 -> Hafidin (Wed, Feb 22th 2017)
 * 				Ver.3 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * 				Ver.4 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */
void BWFollowCarpet_Left(int CARPET_CODE, int FOLLOW_MODE)
{

//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	//ACTIVATE FOLLOWMODE CARPET
	FOLLOWMODE_FLAG=FOLLOW_CARPET_ACTIVE;
	TCSlave_Check();

	//ACTIVATE FOLLOW CALC
	FOLLOW_CALC=KIRI;

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG= CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL:
				{
					while(
							(TCS3200_SLV_DATA[1]==CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)
						 )
					{
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd," FOLLOW CARPET LEFT ");lcd_putstr(lcd);
						Cat_Avoider();
						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=15)
						{
							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							}

//							Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
						}
						else
						{
							PID_BWFollowCarpet_Left();
						}

						Bumper_Action();
					}
				}break;

		case INVERSE:
				{
					while(
							(TCS3200_SLV_DATA[1]!=CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)
						 )
					{
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd," FOLLOW CARPET LEFT ");lcd_putstr(lcd);
						Cat_Avoider();
						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=15)
						{
							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//							Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							}
						}
						else
						{
							PID_BWFollowCarpet_Left();
						}

						Bumper_Action();
					}
				}break;
	}
	FOLLOW_CALC=KOSONG;
}

/* func      : void PID_BWFollowCarpet_Left(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, February 10th 2017)
 * Revised BY: Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_BWFollowCarpet_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	PID_Calc_LeftRule();
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd," FOLLOW CARPET LEFT ");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd," PID VALUES ");lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd," pid_L: %d ",(int)PID_F_L.pid_value[0]);lcd_putstr(lcd);

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						Cat_Avoider();

						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//							}
//							else
//							{
//								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//							}
						Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_L.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_FRONT]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
//								if(CAT_DETECTOR==CAT_ACTIVATED)
//									{
//										Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//									}
//									else
//									{
//										Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//									}
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
							}
							while(Ping[PING_LEFT]>=16)
							{
								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							Cat_Avoider();

							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Dynamx_CurveRight_PID_SLOW(HEXSPD_MED, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
//							}
//							else
//							{
//								Dynamx_CurveRight_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
//							}
							Dynamx_CurveRight_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0], IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_L.pid_value[0]=13;
//					}

					if (Ping[PING_FRONT]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						if(CAT_DETECTOR==CAT_ACTIVATED)
//						{
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
//								if(CAT_DETECTOR==CAT_ACTIVATED)
//									{
//										Dynamx_MovFwd4cm_slow(4, HEXSPD_MED, IKCALC_DISABLE);
//									}
//									else
//									{
//										Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//									}
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
							}
							while(Ping[PING_LEFT]>=16)
							{
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							Cat_Avoider();

							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Dynamx_CurveLeft_PID_SLOW(HEXSPD_MED, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
//							}
//							else
//							{
//								Dynamx_CurveLeft_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
//							}
							Dynamx_CurveLeft_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0], IKCALC_DISABLE);

						}
						OVERRIDE=1;
					}

				}
		}
	}

}



/* func      : void BW_FollowCounter_Right(int limit)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until desired step
 * param     : int limit
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 13th 2017)
 * Revised By: Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */
void BW_FollowCounter_Right(int limit)
{
	int counter;
	FOLLOW_CALC=KANAN;
	CAT_FLAG = CAT_NOT_DETECTED;
	//int limit=15;
	for(counter=1;counter<=limit;counter++)
	{
		Cat_Avoider();
		Furniture_Avoider();
//		Evade_Wall();

		if (Ping[PING_FRONT]<=15)
		{
//			Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}
		else
		{
			PID_BW_FollowCounter_Right();
		}

		if(FIRE==FIRE_ON)
		{
			Bumper_Follow();
		}
		else
		{
			Bumper_Action_Right();
		}
	}
	FOLLOW_CALC=KOSONG;


}

/* func      : void ID_BW_FollowCounter_Right(void)
 * brief     : Wall following using PID controller right rule
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 13th 2017)
 * Revised BY: Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_BW_FollowCounter_Right(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	lcd_gotoxy(0,0);sprintf(lcd," FOLLOW COUNTER RIGHT ");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd," PID VALUES ");lcd_putstr(lcd);
//	//	lcd_gotoxy(0,1);sprintf(lcd," pid_L: %d ",(int)PID_F_L.pid_value[0]);lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd," pid_R: %d ",(int)PID_F_R.pid_value[0]);lcd_putstr(lcd);
//	BW_Buzz(3);
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"pid_value: %d \r",(int)PID_F_R.pid_value[0]);lcd_putstr(lcd);
//	delay_ms(100);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=15)
					{
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						Dynamx_MovFwd3cm(3, HEXSPD_ULTRAFAST, IKCALC_DISABLE);
						Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_FRONT]<=15)
					{
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
								Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
//								Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							Furniture_Avoider();

							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;
							Dynamx_CurveRight_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_FRONT]<=15)
					{
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
//								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							Furniture_Avoider();

							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveLeft_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}
				}
		}
	}
}


/* func      : void BW_FollowCounter_Left(int limit)
 * brief     : Hexapod Dynamixel Wall Following Left Rule using PID controller until desired step
 * param     : int limit
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 13th 2017)
 * Revised By: Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */
void BW_FollowCounter_Left(int limit)
{
	int counter;
	FOLLOW_CALC=KIRI;
	//int limit=15;
	for(counter=1;counter<=limit;counter++)
	{
//		Evade_Wall();
		Cat_Avoider();
		Furniture_Avoider();

		if (Ping[PING_FRONT]<=15)
		{
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
		}
		else
		{
			PID_BW_FollowCounter_Left();
		}

		if(FIRE==FIRE_ON)
		{
			Bumper_Follow();
		}
		else
		{
			Bumper_Action_Left();
		}

	}
	FOLLOW_CALC=KOSONG;
}

/* func      : void ID_BW_FollowCounter_Right(void)
 * brief     : Wall following using PID controller right rule
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 13th 2017)
 * Revised BY: Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_BW_FollowCounter_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd," FOLLOW COUNTER LEFT ");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd," PID VALUES ");lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd," pid_L: %d ",(int)PID_F_L.pid_value[0]);lcd_putstr(lcd);
//	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
						Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_L.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_FRONT]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init_Room();
						}

						else
						{
							Furniture_Avoider();

							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveRight_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0], IKCALC_DISABLE);

						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_L.pid_value[0]=13;
//					}

					if (Ping[PING_FRONT]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_DISABLE);
								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init_Room();
						}
						else
						{
							Furniture_Avoider();

							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveLeft_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0], IKCALC_DISABLE);
//							Dynamx_MovFwd1cm(1,HEXSPD_MEDFAST,IKCALC_ENABLE);
						}

						OVERRIDE=1;
					}

				}
		}
	}
}

/* func      : void BW_FollowTracer_Right_Reverse(void)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised BY: Ver.2 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * 			   Ver.3 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */
void BW_FollowTracer_Right_Reverse(void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;

	FOLLOW_CALC=KANAN_BELAKANG;

	CAT_FLAG = CAT_NOT_DETECTED;
//	TRACER_STAT=TRACER_BLACK;
//	TCSlave_Check();
	//ACTIVATE FOLLOWMODE TRACER
	FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
	TCSlave_Check();

	while(
			(TCS3200_SLV_DATA[1]!=TRACER_WHITE) &&
			(TRACER_STAT==TRACER_BLACK) &&
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_REAR]<=15)
		{
			if (TRACER_STAT==TRACER_WHITE)break;

			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
		}
		else
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			PID_BWFollowTracer_Right_Reverse();
		}
	}
	FOLLOW_CALC=KOSONG;
}

/* func      : void PID_BWFollowTracer_Right_Reverse(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised BY: Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_BWFollowTracer_Right_Reverse(void)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
//	PID_Calc_RightRule_Reverse();
//	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"pid: %d \r",(int)PID_F_L.pid_value[0]);lcd_putstr(lcd);
//	//delay_ms(100);

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_REAR_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_REAR]<=15)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_WHITE)break;
						Sendto_PC(USART1,"BW BACKWARD \r");
						Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_REAR_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_REAR]<=15)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								if (TRACER_STAT==TRACER_WHITE)break;
								Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
							}
							while(Ping[PING_LEFT]>=16)
							{
								Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init_Reverse();
						}

						else
						{
							//lcd_display_clear();
							lcd_gotoxy(4,2);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveRight_PID_Reverse(HEXSPD_FAST, HEXSTEP_FAR, &PID_F_L.pid_value[0],IKCALC_DISABLE);
						//	lcd_display_clear();
						}

						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_REAR_LEFT]<PID_F_L.set_point )
				{

					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_REAR]<=15)
					{
						Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE) break;

						if(WINDUP_LEFT_COUNTER>=25)
							{
								BW_Buzz(5);
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
								//delay_ms(100);

								while(Ping[PING_REAR]>=15)
								{
									if (TRACER_STAT==TRACER_WHITE)break;
									Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
								}
								while(Ping[PING_LEFT]>=16)
								{
									Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//									Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
								}
								//RESET WINDUP RIGHT COUNTER
								WINDUP_LEFT_COUNTER=0;

								//REINIT PID
								BW_PID_Init_Reverse();
							}

						else
						{
						//	lcd_display_clear();
							lcd_gotoxy(4,2);sprintf(lcd,"CURVE LEFT");lcd_putstr(lcd);
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveLeft_PID_Reverse(HEXSPD_FAST, HEXSTEP_FAR, &PID_F_L.pid_value[0],IKCALC_DISABLE);
						//	lcd_display_clear();
						}

						OVERRIDE=1;
					}
				}
		}
	}
}


/* func      : void BW_FollowTracer_Left_Reverse(void)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised BY: Ver.2 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * 			   Ver.3 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */
void BW_FollowTracer_Left_Reverse(void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_BLACK;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;
	CAT_FLAG=CAT_NOT_DETECTED;

	//ACTIVATE FOLLOW CALC
	FOLLOW_CALC=KIRI_BELAKANG;

	//ACTIVATE FOLLOWMODE TRACER
	FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
	TCSlave_Check();

	while(
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(TCS3200_SLV_DATA[1]!=TRACER_WHITE) &&
			(TRACER_STAT==TRACER_BLACK) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_REAR]<=15)
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");

			Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);

		}
		else
		{
			if (TRACER_STAT==TRACER_WHITE)break;
			PID_BWFollowTracer_Left_Reverse();
		}
		if (TRACER_STAT==TRACER_WHITE)break;

	}
	FOLLOW_CALC=KOSONG;
}


/* func      : void PID_BWFollowTracer_Left_Reverse(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised BY: Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_BWFollowTracer_Left_Reverse(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	PID_Calc_LeftRule_Reverse();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_REAR_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_REAR]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_WHITE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
						Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_REAR_RIGHT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_L.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_REAR]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=14)
							{
								Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
							}
							while(Ping[PING_RIGHT]>=16)
							{
								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveRight_PID_Reverse(HEXSPD_FAST, HEXSTEP_FAR, &PID_F_R.pid_value[0],IKCALC_DISABLE);
							lcd_display_clear();
						}


						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_REAR_RIGHT]>PID_F_R.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_L.pid_value[0]=13;
//					}

					if (Ping[PING_REAR]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_WHITE)break;

						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=14)
							{
								Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
							}
							while(Ping[PING_RIGHT]>=16)
							{
								Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CURVE LEFT");lcd_putstr(lcd);
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveLeft_PID_Reverse(HEXSPD_FAST, HEXSTEP_FAR, &PID_F_R.pid_value[0],IKCALC_DISABLE);
							lcd_display_clear();
						}
						OVERRIDE=1;
					}
				}
		}
	}
}


/* func      : void BWFollowCarpet_Right_Reverse(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised BY: Ver.2 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * programmer's Note:
 *
 */
void BWFollowCarpet_Right_Reverse(int CARPET_CODE, int FOLLOW_MODE)
{
//	int counter;
	//int limit=15;
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	//ACTIVATE FOLLOWMODE CARPET
	FOLLOWMODE_FLAG=FOLLOW_CARPET_ACTIVE;
	TCSlave_Check();

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG=CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL: //BW FOLLOW WHILE CARPET == X
				{
					while( (TCS3200_SLV_DATA[0]==CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_REAR]<=15)
						{
							Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//							Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
						}
						else
						{
							PID_BWFollowCarpet_Right_Reverse();
						}
					}
				}break;


		case INVERSE: ////BW FOLLOW WHILE CARPET != X
				{
					while( (TCS3200_SLV_DATA[0]!=CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_REAR]<=15)
						{
							Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//							Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
						}
						else
						{
							PID_BWFollowCarpet_Right_Reverse();
						}
					}
				}break;
	}
}

/* func      : void PID_BWFollowCarpet_Right_Reverse(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised By:
 * programmer's Note:
 *
 */
void PID_BWFollowCarpet_Right_Reverse(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
	PID_Calc_RightRule_Reverse();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_LEFT]<=PID_F_R.set_point_upper) && (Ping[PING_REAR_LEFT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_REAR]<=15)
					{
						Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
						Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_REAR_LEFT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_REAR]<=15)
					{
						Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
							}
							while(Ping[PING_LEFT]>=16)
							{
								Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//								Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveRight_PID_Reverse(HEXSPD_ULTRAFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0],IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_REAR_LEFT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_REAR]<=15)
					{
						Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
							}
							while(Ping[PING_LEFT]>=16)
							{
								Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//								Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveLeft_PID_Reverse(HEXSPD_ULTRAFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0],IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}


/* func      : void BWFollowCarpet_Left_Reverse(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised BY: Ver.2 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * programmer's Note:
 *
 */
void BWFollowCarpet_Left_Reverse(int CARPET_CODE, int FOLLOW_MODE)
{

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG= CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL:
				{
					while(
							(TCS3200_SLV_DATA[0]==CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)
						 )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_REAR]<=15)
						{
							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
							Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//							Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
						}
						else
						{
							PID_BWFollowCarpet_Left_Reverse();
						}
					}
				}break;

		case INVERSE:
				{
					while(
							(TCS3200_SLV_DATA[0]!=CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)
						 )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_REAR]<=15)
						{
							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
							Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//							Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
						}
						else
						{
							PID_BWFollowCarpet_Left_Reverse();
						}
					}
				}break;
	}
}


/* func      : void PID_BWFollowCarpet_Left_Reverse(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised By:
 * programmer's Note:
 *
 */
void PID_BWFollowCarpet_Left_Reverse(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule_Reverse();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_RIGHT]<=PID_F_L.set_point_upper) && (Ping[PING_REAR_RIGHT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_REAR]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
						Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_REAR_RIGHT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_L.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_REAR]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
							}
							while(Ping[PING_RIGHT]>=16)
							{
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
								Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveRight_PID_Reverse(HEXSPD_ULTRAFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0],IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_REAR_RIGHT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_L.pid_value[0]=13;
//					}

					if (Ping[PING_REAR]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
							}
							while(Ping[PING_RIGHT]>=16)
							{
								Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveLeft_PID_Reverse(HEXSPD_ULTRAFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0],IKCALC_DISABLE);

						}
						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void BW_FollowCounter_Right_Reverse(int limit)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until desired step
 * param     : int limit
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised By:
 * programmer's Note:
 *
 */
void BW_FollowCounter_Right_Reverse(int limit)
{
	int counter;
	CAT_FLAG = CAT_NOT_DETECTED;
	//int limit=15;
	for(counter=1;counter<=limit;counter++)
	{
		Cat_Avoider();
//		Evade_Wall();

		if (Ping[PING_REAR]<=15)
		{
			Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//			Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
		}
		else
		{
			PID_BW_FollowCounter_Right_Reverse();
		}
	}
}


/* func      : void PID_BW_FollowCounter_Right_Reverse(int limit)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until desired step
 * param     : int limit
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised By:
 * programmer's Note:
 *
 */
void PID_BW_FollowCounter_Right_Reverse(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
//	Sendto_PC(USART1,"SHARP ASKEW RIGHT: %d \t",(int)SHARP[SHARP_RIGHT]);
	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_RIGHT]);
	PID_Calc_RightRule_Reverse();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);

//	BW_Buzz(3);
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"pid_value: %d \r",(int)PID_F_R.pid_value[0]);lcd_putstr(lcd);
//	delay_ms(100);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_LEFT]<=PID_F_R.set_point_upper) && (Ping[PING_REAR_LEFT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_REAR]<=15)
					{
						Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
						Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST,IKCALC_DISABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_REAR_LEFT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_REAR]<=15)
					{
						Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								Dynamx_MovFwd3cm_Reverse(3,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
								Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//								Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;
							Dynamx_CurveRight_PID_Reverse(HEXSPD_ULTRAFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0],IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_REAR_LEFT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_R.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_R.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_REAR]<=15)
					{
						Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
								Dynamx_Rot_Left_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//								Dynamx_Rot_Left(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveLeft_PID_Reverse(HEXSPD_ULTRAFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0],IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}
				}
		}
	}
}


/* func      : void BW_FollowCounter_Left_Reverse(int limit)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until desired step
 * param     : int limit
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised By:
 * programmer's Note:
 *
 */
void BW_FollowCounter_Left_Reverse(int limit)
{
	int counter;
	//int limit=15;
	for(counter=1;counter<=limit;counter++)
	{
//		Evade_Wall();
		Cat_Avoider();

		if (Ping[PING_REAR]<=15)
		{
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");
			Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//			Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
		}
		else
		{
			PID_BW_FollowCounter_Left_Reverse();
		}
	}
}


/* func      : void PID_BW_FollowCounter_Left_Reverse(int limit)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until desired step
 * param     : int limit
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Saturday, March 4th 2017)
 * Revised By:
 * programmer's Note:
 *
 */
void PID_BW_FollowCounter_Left_Reverse(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule_Reverse();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_RIGHT]<=PID_F_L.set_point_upper) && (Ping[PING_REAR_RIGHT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_REAR]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
						Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_REAR_RIGHT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_RIGHT_COUNTER++;
//						PID_F_L.pid_value[0]=13; //WINDUP
//					}

					if (Ping[PING_REAR]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=15)
							{
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
								Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveRight_PID_Reverse(HEXSPD_ULTRAFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0],IKCALC_DISABLE);

						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_REAR_RIGHT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
//					if (PID_F_L.pid_value[0]>13)
//					{
//						WINDUP_LEFT_COUNTER++;
//						PID_F_L.pid_value[0]=13;
//					}

					if (Ping[PING_REAR]<=15)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
						Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//						Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								Dynamx_MovFwd3cm_Reverse(3, HEXSPD_ULTRAFAST, IKCALC_ENABLE);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=15)
							{
								Dynamx_Rot_Right_Reverse(HEXSPD_ULTRAFAST,HEXSTEP_FAR);
//								Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR, IKCALC_ENABLE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							Dynamx_CurveLeft_PID_Reverse(HEXSPD_ULTRAFAST, HEXSTEP_FAR, &PID_F_L.pid_value[0],IKCALC_DISABLE);
						}

						OVERRIDE=1;
					}

				}
		}
	}
}

/* func      : void BW_FollowTracer_Right(void)
 * brief     : Hexapod Dynamixel Flame Following using PID controller until Front Sharp close to fire
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Toni (Mon, November 23th 2017)
 * Revised BY:
 * programmer's Note:
 *
 */
void BW_FollowFlame(void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;

	FOLLOW_CALC=FLAME;

	//ACTIVATE FOLLOWMODE TRACER
	TCSlave_Check();

	while(
			(SHARP[SHARP_FRONT_R]>=20)//||(SHARP[SHARP_FRONT_L]>=20))
			&&
			(FlameFrontDigi[0]!=4)
		 )
	{
		TCSlave_Check();
		Furniture_Avoider();

		if ((Ping[PING_FRONT]<=20) && (FlameFrontDigi[0]!=4))
		{
			if (FIRESCAN_DIRECTION==SCAN_RIGHT)
			{
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			else
			{
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
			}
		}
		else
		{
			if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;

			PID_BWFollowFlame();

			if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
		}

		Bumper_Action();
	}
	FOLLOW_CALC=KOSONG;
}

/* func      : void PID_BWFollowFlame(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Toni (Thursday, November 23th 2017)
 * Revised BY:
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_BWFollowFlame(void)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
//	static int WINDUP_LEFT_COUNTER=0;
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd," FOLLOW FLAME ");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd," PID VALUES ");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd," PID: %d ",(int)PID_F_R.pid_value[0]);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd," Sense: %d ",(int)FlameSenseDigi[0]);lcd_putstr(lcd);

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			if (FlameSenseDigi[0]==0)
				{
					UV_Lock=UVLOCK_ACTIVE;
					FlameTracking_Ver3();
				}
			//KONDISI ROBOT SESUAI
			else if ( FlameSenseDigi[0]==PID_F_R.set_point)
				{
					if ((Ping[PING_FRONT]<=30) && (FlameFrontDigi[0]!=4))
					{
						if (FIRESCAN_DIRECTION==SCAN_RIGHT)
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
						else
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
					}
				if (OVERRIDE==1){break;}
				if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
				if (OVERRIDE==0)
					{
						if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
						Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);

						if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
						OVERRIDE=1;
					}
				}

			else if ( FlameSenseDigi[0]==7)
			{
				if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
				OVERRIDE=1;
			}

			else if ( FlameSenseDigi[0]==1)
			{
				if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
				OVERRIDE=1;
			}
			//KONDISI LILIN KIRI
			else if (( FlameSenseDigi[0]<PID_F_R.set_point ) && (FlameSenseDigi[0]>=2))
				{
				if ((Ping[PING_FRONT]<=30) && (FlameFrontDigi[0]!=4))
					{
						if (FIRESCAN_DIRECTION==SCAN_RIGHT)
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
						else
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
						}
					}
					if (OVERRIDE==1){break;}
					if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
					if (OVERRIDE==0)
					{
						if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while((Ping[PING_FRONT]<=30) && (FlameFrontDigi[0]!=4))
							{
								if ((SHARP[SHARP_FRONT_R]<=20)&& (FlameFrontDigi[0]==4))break;
//								Dynamx_MovFwd3cm(3, HEXSPD_ULTRAFAST, IKCALC_DISABLE);
								Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
								//Dynamx_MovFwd4cm(4, HEXSPD_MEDFAST, IKCALC_DISABLE);
							}
							//REINIT PID
							BW_PID_Flame_Init();
						}
						else
						{
							Furniture_Avoider();
							Bumper_Action();

							if ((SHARP[SHARP_FRONT_R]<=20) && (FlameFrontDigi[0]==4))break;
							Dynamx_CurveLeft_Flame_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
							lcd_gotoxy(0,3);sprintf(lcd," CURVE RIGHT");lcd_putstr(lcd);

							if ((SHARP[SHARP_FRONT_R]<=20) && (FlameFrontDigi[0]==4))break;

						}

						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( (FlameSenseDigi[0]>PID_F_R.set_point) && (FlameSenseDigi[0]<=6))
				{
					if ((Ping[PING_FRONT]<=20) && (FlameFrontDigi[0]!=4))
					{
						if (FIRESCAN_DIRECTION==SCAN_RIGHT)
						{
							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
						}
						else
						{
							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
						}
					}
					if ((SHARP[SHARP_FRONT_R]<=20) && (FlameFrontDigi[0]==4))break;
					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if ((SHARP[SHARP_FRONT_R]<=20) && (FlameFrontDigi[0]==4)) break;

						Furniture_Avoider();
						Bumper_Action();
//						Tracer_Check();
						if (TRACER_STAT==TRACER_WHITE)break;

						Dynamx_CurveRight_Flame_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
						lcd_gotoxy(0,3);sprintf(lcd," CURVE LEFT");lcd_putstr(lcd);

//						Dynamx_CurveLeft_PID(HEXSPD_MEDFAST, HEXSTEP_FAR, &PID_F_R.pid_value[0], IKCALC_DISABLE);
						if ((SHARP[SHARP_FRONT_R]<=20) && (FlameFrontDigi[0]==4))break;

					}

					OVERRIDE=1;
				}
			}
		}
	}

/* func      : Compass_Correction_ExitRoom(void)
 * brief     : Correction Robot posisition on exitroom
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Toni (Tuesday, March 6th 2018)
 * Revised BY:
 * programmer's Note: This function MUST be called in the corresponding wall following algorithm
 *
 */
void Compass_Correction_ExitRoom (void)
{
//	R3 Dan R4B
//	R1A DAN R4A
//	R2
//	R1C DAN R1B
	GetCMPS11_Angle8Bit();
	if((CMPS11_Angle<(R4B_THRESHOLD_LOWER-30)) || (CMPS11_Angle>(R4B_THRESHOLD_UPPER+20)))
	{
		ARENA_FLAG=CMPS_INACTIVE;
	}
	else
	{
		ARENA_FLAG=CMPS_ACTIVE;
	}
}
