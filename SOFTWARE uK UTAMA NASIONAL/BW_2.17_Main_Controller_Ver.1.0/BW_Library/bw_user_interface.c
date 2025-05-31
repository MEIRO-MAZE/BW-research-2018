/*==============================================================================================
								 	 PROJECT BW Ver.1.0
								  	 USER INTERFACE LIBRARY
==============================================================================================*/

#include "bw_user_interface.h"

//BW START BUTTON
void Button_Init(void)
{
	StartButton_Init();
	UserButton_Init();
}

/* func      : void StartButton_Init(void)
 * brief     : StartButon GPIO Init
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, February 22nd 2015)
 * Revised BY: N/A
 */
void StartButton_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_BUTTON, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = BUTTON_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(BUTTON_PORT, &GPIO_InitStructure);
}

/* func      : void UserButton_Init(void)
 * brief     : UserButton GPIO Init
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, February 22nd 2015)
 * Revised BY: N/A
 */
void UserButton_Init(void)
{
	/*
	 * USERBUTTON A
	 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_USERBUTTON_A, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = USERBUTTON_A_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(USERBUTTON_A_PORT, &GPIO_InitStructure);

	/*
	 * USERBUTTON B
	 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_USERBUTTON_B, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = USERBUTTON_B_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(USERBUTTON_B_PORT, &GPIO_InitStructure);
}

/* func      : void Buzzer_Init(void)
 * brief     : Buzzer GPIO Init
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Missing Note)
 * Revised BY: Ryan (Sunday, February 22nd 2015)
 * Programmer's Note: COnfigured for the YUMRyan (Sunday, February 22nd 2015)
 */
void Buzzer_Init(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_BUZZER, ENABLE);
	GPIO_InitStructure.GPIO_Pin = BUZZER_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 	// pin tidak diberikan pull up
	GPIO_Init(BUZZER_PORT, &GPIO_InitStructure); 		// inisialisasi periperal GPIO sesuai parameter typdef diatas
}

/* func      : void BW_Buzz(int counter)
 * brief     : Buzzing for *counter times
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Missing Note)
 * Programmer's Note:
 */
void BW_Buzz(int counter)
{
//	int LONG_BUZZ;
//    int buzz_count;
//    while(counter!=0)
//    {
//        if(counter<=3) //buzz 1-3
//        {
//            for(buzz_count=0;buzz_count<counter;buzz_count++)
//            {
//                delay_ms(50);
//                BUZZ_ON;
//                delay_ms(50);
//                BUZZ_OFF;
//            }
//            counter=0;
//        }
//        else
//        {
//        	LONG_BUZZ= counter-3;
//        	counter-=LONG_BUZZ;
//        	for(buzz_count=0;buzz_count<LONG_BUZZ;buzz_count++)
//        	{
//        		delay_ms(50);
//                BUZZ_ON;
//                delay_ms(200);
//                BUZZ_OFF;
//        	}
//
//        	LONG_BUZZ=0;
//        }
//    }
}

void BW_Buzz_New(int counter)
{
	int LONG_BUZZ;
    int buzz_count;
    while(counter!=0)
    {
        if(counter<=3) //buzz 1-3
        {
            for(buzz_count=0;buzz_count<counter;buzz_count++)
            {
                delay_ms(50);
                BUZZ_ON;
                delay_ms(50);
                BUZZ_OFF;
            }
            counter=0;
        }
        else
        {
        	LONG_BUZZ= counter-3;
        	counter-=LONG_BUZZ;
        	for(buzz_count=0;buzz_count<LONG_BUZZ;buzz_count++)
        	{
        		delay_ms(50);
                BUZZ_ON;
                delay_ms(200);
                BUZZ_OFF;
        	}

        	LONG_BUZZ=0;
        }
    }
}


/* func      : void LED_Init(void)
 * brief     : FIRE LED Indicator GPIO Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Missing Note)
 * Programmer's Note:
 */
void LED_Init(void)
{
	//-----------------LED INDICATOR-----------------------
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_LED, ENABLE);
	GPIO_InitStructure.GPIO_Pin = LED_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(LED_PORT, &GPIO_InitStructure); 		// inisialisasi periperal GPIO sesuai parameter typdef diatas
}

/* func      : void FIRE_LED_Init(void)
 * brief     : FIRE LED Indicator GPIO Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Wednesday, February 24th 2016
 * Programmer's Note:
 */
void FIRE_LED_Init(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_FIRE_LED, ENABLE);
	GPIO_InitStructure.GPIO_Pin 	= FIRE_LED_PIN;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;       // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType 	= GPIO_OType_PP; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(FIRE_LED_PORT, &GPIO_InitStructure); 		// inisialisasi periperal GPIO sesuai parameter typdef diatas
}

/* func      : void SND_ACT_LED_Init(void)
 * brief     : Sound Activation LED Indicator GPIO Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Wednesday, February 24th 2016
 * Programmer's Note:
 */
void SND_ACT_LED_Init(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_SND_ACT_LED, ENABLE);
	GPIO_InitStructure.GPIO_Pin 	= SND_ACT_LED_PIN ;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;       	// Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType 	= GPIO_OType_PP; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(SND_ACT_LED_PORT, &GPIO_InitStructure); 		// inisialisasi periperal GPIO sesuai parameter typdef diatas
}

/* func      : void COMVISION_LED_Init(void)
 * brief     : Computer Vision LED Indicator GPIO Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Wednesday, February 24th 2016
 * Programmer's Note:
 */
void COMVISION_LED_Init(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_COMVISION_LED, ENABLE);
	GPIO_InitStructure.GPIO_Pin 	= COMVISION_LED_PIN ;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;       	// Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType 	= GPIO_OType_PP; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(COMVISION_LED_PORT, &GPIO_InitStructure); 	// inisialisasi periperal GPIO sesuai parameter typdef diatas
}

/* func      : void BW_LED_Interrupt_Init(void)
 * brief     : FIRE LED Indicator Timer Interrupt Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (MISSING NOTE)
 * Programmer's Note: LED Blinking effect Initialization using timer 5
 */
void BW_LED_Interrupt_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 8399; //f per count= 84.000.000/(8399+1)=10.000Hz = 0,1ms (0,001 s)
	//335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 1000;// 0,1 ms x 1000 = 100 ms -> 1 s -> 1 Hz
//	TIM_TimeBaseStructure.TIM_Period = 500;// 0,1 ms x 500 = 50 ms -> 0,5 s -> 2 Hz
			//200; //0,1 X 200 = 20 ms -> 0,2 s -> 5 Hz
	//10000; //0,1ms x 10000 = 1 s
	//0.004*125000=500ms jadi sampling adc setiap 500ms //MAX 65535
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM5, ENABLE); //default di off dulu
//	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/* func      : void TIM5_IRQHandler(void)
 * brief     : FIRE LED Indicator Timer Handler
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (MISSING NOTE)
 * Programmer's Note: LED Blinking effect Handler
 */
void TIM5_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
    {
//    	led_snd_off_counter++;
//    	if(led_snd_off_counter>=4000)
//    	{
////    		led_snd_off_counter=0;
//    		SND_ACT_LED_OFF;
//    		BW_LED_BLINK_OFF
//    	}

    	if ( (UV_Lock==0) )
    	{

    		if(led_off_counter==0)
    		{
    			FIRE_LED_OFF;
    		}

    		else if(led_off_counter>=1)
    		{
            	if(led_counter==1)
                {
            		FIRE_LED_ON;
                	led_counter=2;
                }

                else if(led_counter==2)
                {
                	FIRE_LED_OFF;
                	led_counter=1;
                }

            	led_off_counter++;

        		if(led_off_counter>=4000)
        		{
        			FIRE_LED_OFF;
        			led_off_counter=0;
        			BW_LED_BLINK_OFF;
        		}

    		}


    	}

    	else if (UV_Lock==1)
    	{
    		led_off_counter=0;

        	if(led_counter==1)
            {
        		FIRE_LED_ON;
            	led_counter=2;
            }

            else if(led_counter==2)
            {
            	FIRE_LED_OFF;
            	led_counter=1;
            }
    	}

    	TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
    }
}
