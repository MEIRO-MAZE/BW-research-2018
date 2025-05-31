/*==============================================================================================
								 	 PROJECT BW Ver.1.0
							  BW CONTACT BUMPER SENSOR LIBRARY
==============================================================================================*/

#include "bw_bumper.h"
void Bumper_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_BUMPER_LEFT, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2; //FRONT RIGHT
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(BUMPER_PORT_LEFT, &GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_BUMPER_RIGHT, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7; //FRONT RIGHT
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(BUMPER_PORT_RIGHT, &GPIO_InitStructure);

}

void GetBumper(void)
{
	BUMPER[0]= GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2);
	BUMPER[1]= GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7);
}

void Display_Bumper_Stat(void)
{
	GetBumper();
	if( (BUMPER[LEFT]||BUMPER[RIGHT])==ACTIVE)
	{
		BW_Buzz(1);
	}
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(1,1);sprintf(lcd,"BUMPER MONITOR");lcd_putstr(lcd);
	lcd_gotoxy(4,2);sprintf(lcd,"BMP_L: %d",BUMPER[LEFT]);lcd_putstr(lcd);
	lcd_gotoxy(4,3);sprintf(lcd,"BMP_R: %d",BUMPER[RIGHT]);lcd_putstr(lcd);
	delay_ms(100);
}



