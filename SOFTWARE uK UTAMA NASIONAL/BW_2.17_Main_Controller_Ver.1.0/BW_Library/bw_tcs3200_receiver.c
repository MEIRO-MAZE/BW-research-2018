/*==============================================================================================
								PROJECT BW 2016 Ver.1.0
							  BW TCS3200 RECEIVER LIBRARY
==============================================================================================*/

#include "bw_tcs3200_receiver.h"


void Display_TCS3200(void)
{
	Get_IR();
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd," F_PRESENT: %d",TCS3200_SLV_STAT[FRONT_PRESENT]);lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd," F_PREVIOUS: %d",TCS3200_SLV_STAT[FRONT_PREVIOUS]);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd," TRC_STAT: %d",TCS3200_SLV_STAT[MIDDLE_PRESENT]);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd," CLR_STAT: %d",TCS3200_SLV_STAT[MIDDLE_PREVIOUS]);lcd_putstr(lcd);


}

void Display_TCS3200_Data(void)
{
	int red_val;
	int green_val;
	int blue_val;
	int white_val;
	int sum_val;

	red_val= (TCS3200_SLV_DATA[1]*255) + TCS3200_SLV_DATA[2];
	green_val= (TCS3200_SLV_DATA[3]*255) + TCS3200_SLV_DATA[4];
	blue_val= (TCS3200_SLV_DATA[5]*255) + TCS3200_SLV_DATA[6];
	white_val= (TCS3200_SLV_DATA[7]*255) + TCS3200_SLV_DATA[8];
	sum_val= (TCS3200_SLV_DATA[9]*255) + TCS3200_SLV_DATA[10];

	lcd_display_clear();

	lcd_gotoxy(0,0);sprintf(lcd,"TCS3200  RAW VAL");lcd_putstr(lcd);

	lcd_gotoxy(0,1);sprintf(lcd,"R:%d",red_val);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"G:%d",green_val);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"B:%d",blue_val);lcd_putstr(lcd);
	lcd_gotoxy(7,1);sprintf(lcd,"W:%d",white_val);lcd_putstr(lcd);
	lcd_gotoxy(7,2);sprintf(lcd,"T:%d",sum_val);lcd_putstr(lcd);
	delay_ms(100);
}


void Display_Tracer_Data(void)
{
	int FRONT,MIDDLE,REAR,FRONT_2,MIDDLE_2,REAR_2;//TRC_STAT,TRC_THOLD_UP,TRC_THOLD_DOWN;

	FRONT		= TCS3200_SLV_DATA[1];
	MIDDLE		= TCS3200_SLV_DATA[2];
	REAR		= TCS3200_SLV_DATA[3];
	FRONT_2		= TCS3200_SLV_DATA[4];
	MIDDLE_2	= TCS3200_SLV_DATA[5];
	REAR_2		= TCS3200_SLV_DATA[6];
	TRACER_STAT	= TCS3200_SLV_DATA[7];
//	TRC_THOLD_UP 	= TCS3200_SLV_DATA[8];
//	TRC_THOLD_DOWN 	= TCS3200_SLV_DATA[9];

	lcd_display_clear();

	lcd_gotoxy(1,0);sprintf(lcd,"TRACER RAW VAL");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"F:%d",FRONT);lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"M:%d",MIDDLE);lcd_putstr(lcd);
	lcd_gotoxy(10,1);sprintf(lcd,"R:%d",REAR);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"F:%d",FRONT_2);lcd_putstr(lcd);
	lcd_gotoxy(5,2);sprintf(lcd,"M:%d",MIDDLE_2);lcd_putstr(lcd);
	lcd_gotoxy(10,2);sprintf(lcd,"R:%d",REAR_2);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"T_STAT:%d",TRACER_STAT);lcd_putstr(lcd);
//	lcd_gotoxy(6,2);sprintf(lcd,"TH_UP:%d",TRC_THOLD_UP);lcd_putstr(lcd);
//	lcd_gotoxy(6,3);sprintf(lcd,"TH_DW:%d",TRC_THOLD_DOWN);lcd_putstr(lcd);
	delay_ms(100);
}


void Display_TCS3200_Rule(void)
{
	lcd_display_clear();
	lcd_gotoxy(1,0);sprintf(lcd,"TCS3200  SLAVE");lcd_putstr(lcd);
	lcd_gotoxy(1,1);sprintf(lcd,"PROCESSED DATA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"TCS3200 :%d",TCS3200_SLV_DATA[0]);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"TRACER  :%d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
//	lcd_gotoxy(0,3);sprintf(lcd,"TRC:%d",TCS3200_SLV_DATA[BLUE]);lcd_putstr(lcd);
//	lcd_gotoxy(8,3);sprintf(lcd,"CLR:%d",TCS3200_SLV_DATA[WHITE]);lcd_putstr(lcd);
	delay_ms(100);

}

void Display_TCS3200_CMD_CODE(void)
{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"C[0]:%d",TCS3200_SLV_DATA[0]);lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"C[1]:%d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"C[2]:%d",TCS3200_SLV_DATA[2]);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"C[3]:%d",TCS3200_SLV_DATA[3]);lcd_putstr(lcd);
	lcd_gotoxy(8,0);sprintf(lcd,"C[4]:%d",TCS3200_SLV_DATA[4]);lcd_putstr(lcd);
//	lcd_gotoxy(8,1);sprintf(lcd," CMD[4]: %d",TCS3200_SLV_DATA[3]);lcd_putstr(lcd);
//	lcd_gotoxy(8,2);sprintf(lcd," CMD[4]: %d",TCS3200_SLV_DATA[3]);lcd_putstr(lcd);

//	lcd_gotoxy(0,3);sprintf(lcd," S: %d",TCS3200_SLV_DATA[SUM]);lcd_putstr(lcd);
//	delay_ms(100);

}

void Get_TCS3200_Rule(void)
{
	TCS3200_SLV_DATA[SUM]= TCS3200_SLV_DATA[RED]+TCS3200_SLV_DATA[GREEN]+TCS3200_SLV_DATA[BLUE]+TCS3200_SLV_DATA[WHITE];
	lcd_gotoxy(8,1);sprintf(lcd," S: %d",TCS3200_SLV_DATA[SUM]);lcd_putstr(lcd);

	if(TCS3200_SLV_DATA[WHITE]>=100)
	{
		lcd_gotoxy(8,2);sprintf(lcd," WHITE");lcd_putstr(lcd);
	}
	else if (TCS3200_SLV_DATA[WHITE]<100)
	{
		if(TCS3200_SLV_DATA[SUM]>=250)
		{
			lcd_gotoxy(8,2);sprintf(lcd," GRAY");lcd_putstr(lcd);
		}
		else if (TCS3200_SLV_DATA[SUM]<250)
		{
			lcd_gotoxy(8,2);sprintf(lcd," BLACK");lcd_putstr(lcd);
		}
	}

}

/*
 * BUTTON COMMAND METHOD 1
 */
void Button_CMD(void)
{
//	int BUTTON_A = BUTTON_A_INPUT;

	if(BW_BUTTON_CLICKED)
	{
		BW_Buzz(1);
		TCS3200_Transmit(UART5, START_BUTTON_CMD);

		if(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, CMD_COMPLETED);
		}
	}

	else if(BUTTON_A_CLICKED)
	{
		BW_Buzz(2);
		TCS3200_Transmit(UART5, BUTTON_A);

		if(BUTTON_A_UNCLICKED)
		{
			TCS3200_Transmit(UART5, CMD_COMPLETED);
		}
	}

	else if(BUTTON_B_CLICKED)
	{
		BW_Buzz(2);
		BW_Buzz(2);
		TCS3200_Transmit(UART5, BUTTON_B);

		if(BUTTON_B_UNCLICKED)
		{
			TCS3200_Transmit(UART5, CMD_COMPLETED);
		}
	}
	else
	{
		TCS3200_Transmit(UART5, CMD_IDLE);
	}

}

void TCS3200_MainMenu(void)
{
	 //START SEQUENCES

	Button_CMD();
	while(TCS3200_SLV_DATA[0]==CMD_IDLE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"TCS3200");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"MAIN MENU");lcd_putstr(lcd);
		delay_ms(100);
		Button_CMD();
	}

//	while(1)
//	{
		Button_CMD();

		if(TCS3200_SLV_DATA[0]==CMD_IDLE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"TCS3200");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"MAIN MENU");lcd_putstr(lcd);
			delay_ms(100);
			Button_CMD();
		}

		//TCS3200 CALIBRATION
		else if(TCS3200_SLV_DATA[0]==RCV_START)
		{
			Button_CMD();
			while(TCS3200_SLV_DATA[1]==RCV_IDLE)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"TCS3200");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"CALIBRATION");lcd_putstr(lcd);
				delay_ms(100);
				Button_CMD();
			}

			if(TCS3200_SLV_DATA[0]==RCV_BUTTON_A)
			{
				while(1)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"MIDDLE");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"TCS3200");lcd_putstr(lcd);
					delay_ms(100);
				}
			}
		}

		//FRONT TCS3200 MODE
		else if(TCS3200_SLV_DATA[0]==RCV_BUTTON_A)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FRONT");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"TCS3200");lcd_putstr(lcd);
			delay_ms(1000);

			while(TCS3200_SLV_DATA[0]!=RCV_START)
			{
				Display_TCS3200_Data();
				Button_CMD();
			}
			TCS3200_SLV_DATA[0]=CMD_IDLE;

		}

		//MIDDLE TCS3200 MODE
		else if(TCS3200_SLV_DATA[0]==RCV_BUTTON_B)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"MIDDLE");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"TCS3200");lcd_putstr(lcd);
				delay_ms(100);
			}
		}
//	}

}


void BW_MainMenu(void)
{
	int MENU_VAR=0;

	while(BUTTON_IDLE)
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"BW  2016");lcd_putstr(lcd);
		lcd_gotoxy(1,1);sprintf(lcd,"TCS3200  SLAVE");lcd_putstr(lcd);
		lcd_gotoxy(3,2);sprintf(lcd,"MAIN  MENU");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
		TCS3200_Transmit(UART5, CMD_IDLE);
		delay_ms(100);
	}

	if(BW_BUTTON_CLICKED)
	{

		BW_Buzz(2);
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

			if(MENU_VAR>7) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=7;

			switch(MENU_VAR)
			{
				case 0:
						{
							TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
							Display_TCS3200_Rule();
						}break;

				case 1:
						{

							TCS3200_Transmit(UART5, TCS_CMD_SEND_RAW);
							Display_TCS3200_Data();

							if(BW_BUTTON_CLICKED)
							{
								BW_Buzz(2);
								BW_Buzz(2);
								TCS3200_Transmit(UART5, TCS_CMD_SAVE_EEPROM);
							}
						}break;
				case 2:
						{
							TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
							Display_Tracer_Data();
						}break;

				case 3:
						{
							TCS3200_Transmit(UART5, TCS_FRONT_SHOW_THRESHOLD);
//							Display_TCS3200_Threshold(1);

						}break;

				case 4:
						{
							TCS3200_Transmit(UART5, TCS_MIDDLE_SHOW_THRESHOLD);
//							Display_TCS3200_Threshold(2);

						}break;


				case 5:
						{

							BW_Buzz(2);
							BW_Buzz(2);

								lcd_display_clear();
								TCS3200_Transmit(UART5, TCS_CMD_SHOW_EEPROM);
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"Th_B: %d",TCS3200_SLV_DATA[0]);lcd_putstr(lcd);
								lcd_gotoxy(0,1);sprintf(lcd,"Th_G: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
								lcd_gotoxy(0,2);sprintf(lcd,"Th_BW: %d",TCS3200_SLV_DATA[2]);lcd_putstr(lcd);
								lcd_gotoxy(0,3);sprintf(lcd,"Th_BG: %d",TCS3200_SLV_DATA[3]);lcd_putstr(lcd);
								delay_ms(100);

						}break;

				case 6:
						{
							TCS3200_Calibration();

						}break;
				case 7:
						{

							Tracer_Calibration();
						}break;

			}

		}

	}

	else if(BUTTON_A_CLICKED)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"MENU_A");lcd_putstr(lcd);
		delay_ms(100);
	}

	else if(BUTTON_B_CLICKED)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"MENU_B");lcd_putstr(lcd);
		delay_ms(100);
	}
	else
	{

	}

}


/* func      : int TCS3200_CMD(int TCS_CMD)
 * brief     : Send TCS3200 Command through UART Communications
 * param     : int  TCS_CMD
 * 				IDLE 			(0)	->	Send IDLE Command
 * 				SEND_CONCLUSION (1) ->  Request TCS3200 Conclusion
 * 				SEND_FRONT		(2) ->  Request Front TCS3200 RGBW Data
 * 				SEND_MIDDLE		(3) ->	Request Middle TCS3200 RGBW Data
 * 				SAVE_EEPROM		(4) ->  Send Command to save threshold rule data to EEPROM
 * 				SHOW_EEPROM		(5) ->	Request saved threshold data on EEPROM
 * retval    : int
 * Ver       : 1
 * written By: Ryan (Tuesday, March 15th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
int TCS3200_Command(int TCS_CMD)
{
	switch(TCS_CMD)
	{
		case 0:
				{
					TCS3200_Transmit(UART5, CMD_IDLE);
				}break;

		case 1:
				{
					TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
				}break;

		case 2:
				{
					TCS3200_Transmit(UART5, TCS_CMD_SEND_FRONT);
				}break;

		case 3:
				{
					TCS3200_Transmit(UART5, TCS_CMD_SEND_MIDDLE);
				}break;
		case 4:
				{
					TCS3200_Transmit(UART5, TCS_CMD_SAVE_EEPROM);
				}break;
		case 5:
				{
					TCS3200_Transmit(UART5, TCS_CMD_SHOW_EEPROM);
				}break;

	}

	return 0;

}

/* func      : void TCS3200_Calibration(void)
 * brief     : BW tcs3200 Colour Sensor Calibration Routine
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (MISSING NOTES)
 * Revised BY: Ver. 2 -> Ryan (Thursday, April 25th 2016
 * 					Tracer_Calibration New Routines
 * 			   Ver. 3 -> Ryan (Monday, April 25th 2016
 * 					Showing TCS3200 Raw Data while Calibrating
 * programmer's Note:
 */
void TCS3200_Calibration(void)
{
	lcd_display_clear();
	lcd_gotoxy(1,0);sprintf(lcd,"TCS3200");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"CALIBRATION");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"PRESS START");lcd_putstr(lcd);
	lcd_gotoxy(5,3);sprintf(lcd,"TO INITIATE");lcd_putstr(lcd);
	delay_ms(100);

	if(BW_BUTTON_CLICKED)
	{
		BW_Buzz(1);
		delay_ms(1000);

		while(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, TCS_CMD_SEND_RAW);
			TCS3200_Cal_DisplayStat(1);

		}
		if(BW_BUTTON_CLICKED)
		{
			BW_Buzz(2);
			TCS3200_Transmit(UART5, TCS_CALIBRATE_BLACK);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLACK DATA");lcd_putstr(lcd);
			lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
			delay_ms(100);
		}
		delay_ms(1000);


		while(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, TCS_CMD_SEND_RAW);
			TCS3200_Cal_DisplayStat(2);
		}
		if(BW_BUTTON_CLICKED)
		{
			BW_Buzz(2);
			TCS3200_Transmit(UART5, TCS_CALIBRATE_GRAY);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"GRAY DATA");lcd_putstr(lcd);
			lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
			delay_ms(100);
		}
		delay_ms(1000);


		while(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, TCS_CMD_SEND_RAW);
			TCS3200_Cal_DisplayStat(3);
		}
		if(BW_BUTTON_CLICKED)
		{
			BW_Buzz(2);
			TCS3200_Transmit(UART5, TCS_CALIBRATE_WHITE);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"WHITE DATA");lcd_putstr(lcd);
			lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
			delay_ms(100);

		}
		delay_ms(1000);


		BW_Buzz(2);
		BW_Buzz(2);
		TCS3200_Transmit(UART5, TCS_CALIBRATE_GETRULE);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"TCS3200 RULE");lcd_putstr(lcd);
		lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
		delay_ms(100);

		delay_ms(1000);

	}
	else
	{

	}

}

/*
 *  param -> int MODE
 *  1 -> Calibrate Black
 *  2 -> Calibrate Gray
 *  3 -> Calibrate White
 */
void TCS3200_Cal_DisplayStat(int MODE)
{
	int red_val;
	int green_val;
	int blue_val;
	int white_val;
	int sum_val;

	red_val= (TCS3200_SLV_DATA[1]*255) + TCS3200_SLV_DATA[2];
	green_val= (TCS3200_SLV_DATA[3]*255) + TCS3200_SLV_DATA[4];
	blue_val= (TCS3200_SLV_DATA[5]*255) + TCS3200_SLV_DATA[6];
	white_val= (TCS3200_SLV_DATA[7]*255) + TCS3200_SLV_DATA[8];
	sum_val= (TCS3200_SLV_DATA[9]*255) + TCS3200_SLV_DATA[10];

	lcd_display_clear();

	switch(MODE)
	{
		case 1: {
					lcd_gotoxy(0,0);sprintf(lcd,"CALIBRATE BLACK");lcd_putstr(lcd);
				}break;
		case 2: {
					lcd_gotoxy(0,0);sprintf(lcd,"CALIBRATE GRAY");lcd_putstr(lcd);
				}break;
		case 3: {
					lcd_gotoxy(0,0);sprintf(lcd,"CALIBRATE WHITE");lcd_putstr(lcd);
				}break;
	}

	lcd_gotoxy(0,1);sprintf(lcd,"R:%d",red_val);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"G:%d",green_val);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"B:%d",blue_val);lcd_putstr(lcd);
	lcd_gotoxy(7,1);sprintf(lcd,"W:%d",white_val);lcd_putstr(lcd);
	lcd_gotoxy(7,2);sprintf(lcd,"T:%d",sum_val);lcd_putstr(lcd);
	delay_ms(100);
}

/* func      : void Tracer_Calibration(void)
 * brief     : BW Photodiode Tracer Calibration Routine
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (MISSING NOTES)
 * Revised BY: Ver. 2 -> Ryan (Thursday, April 25th 2016
 * 					Tracer_Calibration New Routines
 * programmer's Note:
 */
void Tracer_Calibration(void)
{
	lcd_display_clear();
	lcd_gotoxy(1,0);sprintf(lcd,"TRACER");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"CALIBRATION");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"PRESS START");lcd_putstr(lcd);
	lcd_gotoxy(5,3);sprintf(lcd,"TO INITIATE");lcd_putstr(lcd);
	delay_ms(100);

	if(BW_BUTTON_CLICKED)
	{
		BW_Buzz(1);
		delay_ms(1000);

		while(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
			Tracer_Cal_DisplayStat(1);
		}


		if(BW_BUTTON_CLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CALIBRATE_GRAY);
			BW_Buzz(2);
			delay_ms(500);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"GRAY DATA");lcd_putstr(lcd);
			lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
			delay_ms(100);

		}
		delay_ms(1000);

		while(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
			Tracer_Cal_DisplayStat(2);
		}


		if(BW_BUTTON_CLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CALIBRATE_WHITE);
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"WHITE DATA");lcd_putstr(lcd);
			lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
			delay_ms(100);

		}
		delay_ms(1000);

		while(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
			Tracer_Cal_DisplayStat(3);
		}


		if(BW_BUTTON_CLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CALIBRATE_BLACK);
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLACK DATA");lcd_putstr(lcd);
			lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
			delay_ms(100);

		}
		delay_ms(1000);


		BW_Buzz(2);
		BW_Buzz(2);
		TCS3200_Transmit(UART5, TRACER_CALIBRATE_GETRULE);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"TRACER RULE");lcd_putstr(lcd);
		lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
		delay_ms(100);

		delay_ms(1000);
	}
	else
	{

	}

}

/*
 * MODE:
 * 	1 -> CALIBRATE GRAY
 * 	2 -> CALIBRATE WHITE
 * 	3 -> CALIBRATE BLACK
 */
void Tracer_Cal_DisplayStat(int MODE)
{
	int FRONT,MIDDLE,REAR,TRC_THOLD_UP,TRC_THOLD_DOWN;

	FRONT		= TCS3200_SLV_DATA[1];
	MIDDLE		= TCS3200_SLV_DATA[2];
	REAR		= TCS3200_SLV_DATA[3];
	TRACER_STAT	= TCS3200_SLV_DATA[4];
	TRC_THOLD_UP 	= TCS3200_SLV_DATA[5];
	TRC_THOLD_DOWN 	= TCS3200_SLV_DATA[6];

	lcd_display_clear();
	switch(MODE)
	{
		case 1: {
					lcd_gotoxy(0,0);sprintf(lcd,"CALIBRATE GRAY");lcd_putstr(lcd);
				}break;
		case 2: {
					lcd_gotoxy(0,0);sprintf(lcd,"CALIBRATE WHITE");lcd_putstr(lcd);
				}break;
		case 3: {
					lcd_gotoxy(0,0);sprintf(lcd,"CALIBRATE BLACK");lcd_putstr(lcd);
				}break;
	}

	lcd_gotoxy(0,1);sprintf(lcd,"F:%d",FRONT);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"M:%d",MIDDLE);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"R:%d",REAR);lcd_putstr(lcd);
	lcd_gotoxy(6,1);sprintf(lcd,"T_STAT:%d",TRACER_STAT);lcd_putstr(lcd);
	lcd_gotoxy(6,2);sprintf(lcd,"TH_UP:%d",TRC_THOLD_UP);lcd_putstr(lcd);
	lcd_gotoxy(6,3);sprintf(lcd,"TH_DW:%d",TRC_THOLD_DOWN);lcd_putstr(lcd);
	delay_ms(100);
}


void Hybrid_TCS3200Tracer_MainMenu(void)
{
	int MENU_VAR=0;

	while(BUTTON_IDLE)
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"BW  2016");lcd_putstr(lcd);
		lcd_gotoxy(1,1);sprintf(lcd,"TCS3200 TRACER");lcd_putstr(lcd);
		lcd_gotoxy(3,2);sprintf(lcd,"MAIN  MENU");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
		TCS3200_Transmit(UART5, CMD_IDLE);
		delay_ms(100);
	}

	if(BW_BUTTON_CLICKED)
	{

		BW_Buzz(2);
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

			if(MENU_VAR>6) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=6;

			switch(MENU_VAR)
			{
				case 0:
						{
							TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
							Display_TCS3200_Rule();
						}break;

				case 1:
						{

							TCS3200_Transmit(UART5, TCS_CMD_SEND_RAW);
							Display_TCS3200_Data();

							if(BW_BUTTON_CLICKED)
							{
								BW_Buzz(2);
								BW_Buzz(2);
								TCS3200_Transmit(UART5, TCS_CMD_SAVE_EEPROM);
							}
						}break;
				case 2:
						{
							TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
							Display_Tracer_Data();
						}break;
				case 3:
						{
							TCS3200_Transmit(UART5, HYBRID_CMD_SEND_THRESHOLD);
							Display_Threshold();
						}break;
				case 4:
						{
							TCS3200_Calibration();

						}break;
				case 5:
						{

							Tracer_Calibration();
						}break;
				case 6:
						{
							Display_New_Tracer();

						}break;

			}

		}

	}

	else if(BUTTON_A_CLICKED)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"MENU_A");lcd_putstr(lcd);
		delay_ms(100);
	}

	else if(BUTTON_B_CLICKED)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"MENU_B");lcd_putstr(lcd);
		delay_ms(100);
	}
	else
	{

	}

}

void Display_Threshold(void)
{

	int Threshold_BW, Threshold_BG, TRACER_THRESHOLD_UP, TRACER_THRESHOLD_DOWN;

	Threshold_BW     = (TCS3200_SLV_DATA[1]*255) + TCS3200_SLV_DATA[2];
	Threshold_BG	 = (TCS3200_SLV_DATA[3]*255) + TCS3200_SLV_DATA[4];
	TRACER_THRESHOLD_UP = (TCS3200_SLV_DATA[5]);
	TRACER_THRESHOLD_DOWN = (TCS3200_SLV_DATA[6]);

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"THRESHOLD");lcd_putstr(lcd);

	lcd_gotoxy(0,1);sprintf(lcd,"TRC_THld_U: %d",TRACER_THRESHOLD_UP);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"TRC_THld_D: %d",TRACER_THRESHOLD_DOWN);lcd_putstr(lcd);

	Sendto_PC(USART1,"============= TCS3200 TRACER THRESHOLD ============= \r");
	Sendto_PC(USART1,"Thold BW: %d \r",Threshold_BW);
	Sendto_PC(USART1,"Thold BG: %d \r",Threshold_BG);
	Sendto_PC(USART1,"TRACER_THRESHOLD_UP: %d \r",TRACER_THRESHOLD_UP);
	Sendto_PC(USART1,"TRACER_THRESHOLD_DOWN: %d \r",TRACER_THRESHOLD_DOWN);
	delay_ms(100);
}

void Display_New_Tracer(void)
{
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"TRACER VALUE");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"FRONT: %d",TCS3200_SLV_DATA[0]);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"REAR: %d",TCS3200_SLV_DATA[2]);lcd_putstr(lcd);
	delay_ms(50);
}

