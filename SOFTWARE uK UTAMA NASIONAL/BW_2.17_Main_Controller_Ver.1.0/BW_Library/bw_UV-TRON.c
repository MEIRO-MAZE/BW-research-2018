/*==============================================================================================
								  	  PROJECT BW Ver.1.0
								  HAMAMATSU UV-TRON SENSOR LIBRARY
==============================================================================================*/

#include <bw_UV-TRON.h>


/*
 *  BW HAMAMATSU UV-TRON GLOBAL VARIABLE
 */

//unsigned char sensor_UV=1;
//unsigned char sensor_UV_lock=0;
//unsigned char fight=0;
//unsigned char hitung=0;


void BW_UV_TRON_Init(void)
{
	UV_GPIO_Init_Right();
	UV_GPIO_Init_Left();
}

void BW_Display_UV_Stat(void)
{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"UV_State: %d",UV_state);lcd_putstr(lcd);
}

void UV_GPIO_Init_Right(void)
{
	//------------------------Pin UV------------------------
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_UV_Right, ENABLE);
	GPIO_InitStructure.GPIO_Pin = UV_PIN_Right;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;            // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			 // Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 		 // kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 		 // pin tidak diberikan pull up
	GPIO_Init(UV_PORT_Right, &GPIO_InitStructure); 					 // inisialisasi periperal GPIO sesuai parameter typdef diatas
}

void UV_GPIO_Init_Left(void)
{
	//------------------------Pin UV------------------------
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_UV_Left, ENABLE);
	GPIO_InitStructure.GPIO_Pin = UV_PIN_Left;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;            // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			 // Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 		 // kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 		 // pin tidak diberikan pull up
	GPIO_Init(UV_PORT_Left, &GPIO_InitStructure); 					 // inisialisasi periperal GPIO sesuai parameter typdef diatas
}
//void UV_TIM_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
//
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//
//	TIM_TimeBaseStructure.TIM_Prescaler = 335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_Period = 125000; //0.004*125000=500ms jadi sampling adc setiap 500ms
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
//	TIM_Cmd(TIM5, ENABLE); //default di off dulu
//	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
//
//    NVIC_InitTypeDef NVIC_InitStructure;
//    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//}



void Get_UV(void)
{
	if(UV_R2FLAG==UV_R2FLAG_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"UV R2 FLAG");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"ROOM");lcd_putstr(lcd);

		if(UV_READ_Right==0)
		{
			UV_state=0; //FLAME DETECTED
			UV_Lock=1;
		}
		else UV_state=1; //FLAME NOT DETECTED
	}
	else
	{
		if((UV_READ_Right==0) || (UV_READ_Left==0))
		{
			UV_state=0; //FLAME DETECTED
			UV_Lock=1;
		}
		else UV_state=1; //FLAME NOT DETECTED
	}
}

//void TIM5_IRQHandler(void)
//{
//    if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
//    {
//    	get_UV();
//    	if(UV_state==0)
//    	{
//    		GPIO_ToggleBits(GPIOC, GPIO_Pin_1);
//    	}
//    	/*
//    	if(fight==1)
//    	{
//    		if(hitung<10)
//    		{GPIO_ToggleBits(GPIOC, GPIO_Pin_1); hitung++;}
//    	}
//    	*/
//
//    	TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
//    }
//}

/*
//==============
//UV
void get_UV()
{
    int d=0;
    sensor_UV=1;
  //  sensor_UV_lock=1;

    while(d<500 && sensor_UV==1)    //1000ms
    //while(d<200 && sensor_UV==1)    //200ms
    {
		 if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==Bit_RESET)
		 {
		     //PORTE.3=1;
		//	 GPIO_SetBits(GPIOC, GPIO_Pin_1);	//led
//			 GPIO_SetBits(GPIOC, GPIO_Pin_8); //kipas
		     sensor_UV=0;break;
		 }
		 else{GPIO_ResetBits(GPIOC, GPIO_Pin_8);GPIO_ResetBits(GPIOC, GPIO_Pin_1);}

        d++;
        delay_ms(2);
    };

//    if(sensor_UV==1)
//    {sensor_UV_lock=0; PORTE.3=0;}
}
*/
