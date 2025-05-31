/*==============================================================================================
								 	 PROJECT BW Ver.2.0
								  	 BW UTILITIES LIBRARY
==============================================================================================*/

#include "bw_utilities.h"

void BW_Initial_Setup(int BW_MODE)
{
//	int LIMITER;


//	if(BW_MODE>3)
//	{
//		BW_Buzz(3);
//		LIMITER= BW_MODE - 3;
//		delay_ms(500);
//		BW_Buzz(LIMITER);
//	}
//	else
//	{
//		delay_ms(500);
//		BW_Buzz(BW_MODE);
//	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
	delay_ms(100);
//
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Mode %d", BW_MODE);lcd_putstr(lcd);delay_ms(200);
}
