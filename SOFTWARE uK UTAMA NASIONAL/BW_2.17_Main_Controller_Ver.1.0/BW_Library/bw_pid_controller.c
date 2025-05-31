/*==============================================================================================
								  	 PROJECT BW Ver.1.0
								  	 BW PID CONTROLLER
==============================================================================================*/

#include "bw_pid_controller.h"
// PID FOLLOW VARIABLES


int count=1;
/*
 * Note: PID Calc setiap 50 ms, program langsung stuck di inisialisasi
 */
//void BW_PID_Interrupt_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
//
//	TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
//
//	TIM_TimeBaseStructure.TIM_Prescaler = 33593;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_Period = 5000; //0.004*5000=50Hz jadi sampling adc setiap 20ms
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
//
//	TIM_Cmd(TIM2, ENABLE); //default di off dulu
//
//	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
//
//    NVIC_InitTypeDef NVIC_InitStructure;
//    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//
//}
//
//void TIM4_IRQHandler(void)
//{
//    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
//    	{
//    		count++;
//
//    		if (count==1) GPIO_SetBits(GPIOC, GPIO_Pin_0);
//    		//if (count==2) {GPIO_ResetBits(GPIOC, GPIO_Pin_0);count=1;}
//    		//PID_Calc_Interrupt_Init();
//    		//BW_RGB_Tracer_Encoder();
//    		//PID_Calc();
//    		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
//    	}
//}

//ADC INTERRUPT INIT
//void BW_PID_Interrupt_Init(void)
//{
////	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
//
//	TIM_TimeBaseStructure.TIM_Prescaler = 335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_Period = 5000; //0.004*5000=50ms jadi sampling adc setiap 20ms
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
//
//	TIM_Cmd(TIM5, ENABLE); //default di off dulu
//
//	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
//
//    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//}
//
//void TIM5_IRQHandler(void)
//{
//    if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
//    	{
//    		PID_Calc();
//    		//PID_follow_right();
//    		TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
//    	}
//}


/*
 * WALL FOLLOWING FUNCTIONS
 */


/*
 * func : void BW_PID_Init(void)
 * brief: initialize PID variables
 * param: N/A
 * Programmer's Note: This function only required to be called once in the early initialization
 * 					  Call this function in the BW_Initialization function
 */
void BW_PID_Init(void)
{
	CAT_DETECTOR=CAT_DIACTIVATED;
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//DEFAULT FOLLOW MAJU
//	PID_F_R.Kp=20; untuk mov fwd tx delay 700
	PID_F_R.Kp=15;
	PID_F_R.Ki=0;
	PID_F_R.Kd=0;

//	PID_F_R.Kp=3;
//	PID_F_R.Ki=6;
//	PID_F_R.Kd=0.675;

//	PID_F_R.Kp=2;
//	PID_F_R.Ki=2;
//	PID_F_R.Kd=1;

	PID_F_R.Ts=1;

	//NEW METHOD
//	PID_F_R.Kp=6;
//	PID_F_R.Ki=1;
//	PID_F_R.Kd=1;
//	PID_F_R.Ts=1;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=17;
	PID_F_R.set_point_lower=16;
	PID_F_R.set_point=16;

//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;
	//==================//
//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;

	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

	//DEFAULT FOLLOW MAJU
//	PID_F_L.Kp=20; untuk mov fwd tx delay 700
	PID_F_L.Kp=15;
	PID_F_L.Ki=0;
	PID_F_L.Kd=0;
	PID_F_L.Ts=1;

	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point=16;
	PID_F_L.set_point_upper=17;
	PID_F_L.set_point_lower=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}

/*
 * func : void BW_PID_Init_Revers(void)
 * brief: initialize PID variables
 * param: N/A
 * Programmer's Note: This function only required to be called once in the early initialization
 * 					  Call this function in the BW_Initialization function
 */
void BW_PID_Init_Reverse(void)
{
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

//	//DEFAULT FOLLOW MAJU
//	PID_F_R.Kp=20;
//	PID_F_R.Ki=0;
//	PID_F_R.Kd=0;
	//DEFAULT
	PID_F_R.Kp=1;
	PID_F_R.Ki=0;
	PID_F_R.Kd=0;

//	PID_F_R.Kp=3;
//	PID_F_R.Ki=6;
//	PID_F_R.Kd=0.675;

//	PID_F_R.Kp=2;
//	PID_F_R.Ki=2;
//	PID_F_R.Kd=1;

	PID_F_R.Ts=1;

	//NEW METHOD
//	PID_F_R.Kp=6;
//	PID_F_R.Ki=1;
//	PID_F_R.Kd=1;
//	PID_F_R.Ts=1;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=13;
	PID_F_R.set_point_lower=12;
	PID_F_R.set_point=12;

//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;
	//==================//
//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;

	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

//	//DEFAULT FOLLOW MAJU
//	PID_F_L.Kp=20;
//	PID_F_L.Ki=0;
//	PID_F_L.Kd=0;

	PID_F_L.Kp=1;
	PID_F_L.Ki=0;
	PID_F_L.Kd=0;
	PID_F_L.Ts=1;

	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point=12;
	PID_F_L.set_point_upper=13;
	PID_F_L.set_point_lower=12;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}


/*
 * func : void BW_PID_Init(void)
 * brief: initialize PID variables
 * param: N/A
 * Programmer's Note: This function only required to be called once in the early initialization
 * 					  Call this function in the BW_Initialization function
 */
void BW_PID_Init_FAR(void)
{
	CAT_DETECTOR=CAT_ACTIVATED;
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

//	//DEFAULT
//	PID_F_R.Kp=45;
//	PID_F_R.Ki=1;
//	PID_F_R.Kd=2;
	//DEFAULT
//	PID_F_R.Kp=20; untuk mov fwd tx delay 700
	PID_F_R.Kp=17;
	PID_F_R.Ki=0;
	PID_F_R.Kd=0;

//	PID_F_R.Kp=3;
//	PID_F_R.Ki=6;
//	PID_F_R.Kd=0.675;

//	PID_F_R.Kp=2;
//	PID_F_R.Ki=2;
//	PID_F_R.Kd=1;

	PID_F_R.Ts=1;

	//NEW METHOD
//	PID_F_R.Kp=6;
//	PID_F_R.Ki=1;
//	PID_F_R.Kd=1;
//	PID_F_R.Ts=1;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=18;
	PID_F_R.set_point_lower=17;
	PID_F_R.set_point=17;

//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;
	//==================//
//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;

	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

//	PID_F_L.Kp=20; untuk mov fwd tx delay 700
	PID_F_L.Kp=17;
	PID_F_L.Ki=0;
	PID_F_L.Kd=0;
	PID_F_L.Ts=1;

//	PID_F_L.Kp=30;
//	PID_F_L.Ki=2;
//	PID_F_L.Kd=0;
//	PID_F_L.Ts=1;

	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point=17;
	PID_F_L.set_point_upper=18;
	PID_F_L.set_point_lower=17;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}

void BW_PID_Init_Room(void)
{
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//DEFAULT
	PID_F_R.Kp=20;
	PID_F_R.Ki=0;
	PID_F_R.Kd=0;

//	PID_F_R.Kp=2;
//	PID_F_R.Ki=2;
//	PID_F_R.Kd=1;

	PID_F_R.Ts=1;

	//NEW METHOD
//	PID_F_R.Kp=6;
//	PID_F_R.Ki=1;
//	PID_F_R.Kd=1;
//	PID_F_R.Ts=1;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=14;
	PID_F_R.set_point_lower=13;
	PID_F_R.set_point=13;

//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;
	//==================//
//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;

	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

	PID_F_L.Kp=20;
	PID_F_L.Ki=0;
	PID_F_L.Kd=0;
	PID_F_L.Ts=1;

	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point=13;
	PID_F_L.set_point_upper=14;
	PID_F_L.set_point_lower=13;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}

void BW_PID_Init_Furniture(void)
{
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//DEFAULT
	PID_F_R.Kp=15;
	PID_F_R.Ki=0;
	PID_F_R.Kd=0;

//	PID_F_R.Kp=2;
//	PID_F_R.Ki=2;
//	PID_F_R.Kd=1;

	PID_F_R.Ts=1;

	//NEW METHOD
//	PID_F_R.Kp=6;
//	PID_F_R.Ki=1;
//	PID_F_R.Kd=1;
//	PID_F_R.Ts=1;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=11;
	PID_F_R.set_point_lower=10;
	PID_F_R.set_point=10;

//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;
	//==================//
//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;

	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

	PID_F_L.Kp=15;
	PID_F_L.Ki=0;
	PID_F_L.Kd=0;
	PID_F_L.Ts=1;

	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point_upper=11;
	PID_F_L.set_point=10;
	PID_F_L.set_point_lower=10;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}

/*
 * func : void BW_PID_Init(void)
 * brief: initialize PID variables
 * param: N/A
 * Programmer's Note: This function only required to be called once in the early initialization
 * 					  Call this function in the BW_Initialization function
 */
void BW_PID_Flame_Init(void)
{
	CAT_DETECTOR=CAT_DIACTIVATED;
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//DEFAULT FOLLOW MAJU
	PID_F_R.Kp=30;
	PID_F_R.Ki=0;
	PID_F_R.Kd=0;

//	PID_F_R.Kp=3;
//	PID_F_R.Ki=6;
//	PID_F_R.Kd=0.675;

//	PID_F_R.Kp=2;
//	PID_F_R.Ki=2;
//	PID_F_R.Kd=1;

	PID_F_R.Ts=1;

	//NEW METHOD
//	PID_F_R.Kp=6;
//	PID_F_R.Ki=1;
//	PID_F_R.Kd=1;
//	PID_F_R.Ts=1;

	//===FIX 11/10/16===//
	PID_F_R.set_point=4;

//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;
	//==================//
//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;

	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

	//DEFAULT FOLLOW MAJU
	PID_F_L.Kp=30;
	PID_F_L.Ki=0;
	PID_F_L.Kd=0;
	PID_F_L.Ts=1;

	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point=4;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}

/*	============= PID FOLLOW BIASA ===============
 * func      : void PID_Calc(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_RightRule(void)
{

	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_F_R.pid_value[2]=PID_F_R.pid_value[1];
	PID_F_R.pid_value[1]=PID_F_R.pid_value[0];

	PID_F_R.error[2]=PID_F_R.error[1];
	PID_F_R.error[1]=PID_F_R.error[0];

	if (Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point) {PID_F_R.error[0]=0;}
	else if (Ping[PING_ASKEW_RIGHT] > PID_F_R.set_point)
		{
			PID_F_R.error[0] = Ping[PING_ASKEW_RIGHT] - PID_F_R.set_point;
		}

	else if (Ping[PING_ASKEW_RIGHT] < PID_F_R.set_point)
		{
			PID_F_R.error[0] = PID_F_R.set_point - Ping[PING_ASKEW_RIGHT];
		}
//	if (SHARP[SHARP_RIGHT]==PID_F_R.set_point) {PID_F_R.error[0]=0;}
//	else if (SHARP[SHARP_RIGHT] > PID_F_R.set_point)
//		{
//			PID_F_R.error[0] = SHARP[SHARP_RIGHT] - PID_F_R.set_point;
//		}
//
//	else if (SHARP[SHARP_RIGHT] < PID_F_R.set_point)
//		{
//			PID_F_R.error[0] = PID_F_R.set_point - SHARP[SHARP_RIGHT];
//		}

	/*
	 * PID FORMULA
	 */
	PID_F_R.P[2]= PID_F_R.error[0]-PID_F_R.error[2];
	PID_F_R.P[1]= PID_F_R.Kp;
	PID_F_R.P[0]= PID_F_R.P[1]*PID_F_R.P[2]; //Proportional Controller

	PID_F_R.I[2]= PID_F_R.Ki*PID_F_R.Ts/2;
	PID_F_R.I[1]= PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.I[0]= PID_F_R.I[2]*PID_F_R.I[1]; //Integral Controller


	PID_F_R.D[2]= 2*PID_F_R.Kd/PID_F_R.Ts;
	PID_F_R.D[1]= PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.D[0]= PID_F_R.D[2]*PID_F_R.D[1]; //Derivative Controller

//	PID_F_R.I= ( (PID_F_R.Ki*PID_F_R.Ts/2)*(PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2]) );
//	PID_F_R.D= ( (2*PID_F_R.Kd/PID_F_R.Ts)*(PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2]));

	PID_F_R.pid_value[0]= PID_F_R.pid_value[2] + PID_F_R.P[0] + PID_F_R.I[0] + PID_F_R.D[0];
}



/*
 * func      : void PID_Calc_Reverse(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Hafidin
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_RightRule_Reverse(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */

	PID_F_L.pid_value[2]=PID_F_L.pid_value[1];
	PID_F_L.pid_value[1]=PID_F_L.pid_value[0];

	PID_F_L.error[2]=PID_F_L.error[1];
	PID_F_L.error[1]=PID_F_L.error[0];

	if (Ping[PING_REAR_LEFT]==PID_F_L.set_point) {PID_F_L.error[0]=0;}

	else if (Ping[PING_REAR_LEFT] > PID_F_L.set_point)
		{
			PID_F_L.error[0] = Ping[PING_REAR_LEFT] - PID_F_L.set_point;
		}

	else if (Ping[PING_REAR_LEFT] < PID_F_L.set_point)
		{
			PID_F_L.error[0] = PID_F_L.set_point - Ping[PING_REAR_LEFT];
		}

	/*
	 * PID FORMULA
	 */
	PID_F_L.P[2]= PID_F_L.error[0]-PID_F_L.error[2];
	PID_F_L.P[1]= PID_F_L.Kp;
	PID_F_L.P[0]= PID_F_L.P[1]*PID_F_L.P[2]; //Proportional Controller

	PID_F_L.I[2]= PID_F_L.Ki*PID_F_L.Ts/2;
	PID_F_L.I[1]= PID_F_L.error[0]+(2*PID_F_L.error[1])+PID_F_L.error[2];
	PID_F_L.I[0]= PID_F_L.I[2]*PID_F_L.I[1]; //Integral Controller

	PID_F_L.D[2]= 2*PID_F_L.Kd/PID_F_L.Ts;
	PID_F_L.D[1]= PID_F_L.error[0]-(2*PID_F_L.error[1])+PID_F_L.error[2];
	PID_F_L.D[0]= PID_F_L.D[2]*PID_F_L.D[1]; //Derivative Controller

//	PID_F_L.I= ( (PID_F_L.Ki*PID_F_L.Ts/2)*(PID_F_L.error[0]+(2*PID_F_L.error[1])+PID_F_L.error[2]) );
//	PID_F_L.D= ( (2*PID_F_L.Kd/PID_F_L.Ts)*(PID_F_L.error[0]-(2*PID_F_L.error[1])+PID_F_L.error[2]));

	PID_F_L.pid_value[0]= PID_F_L.pid_value[2] + PID_F_L.P[0] + PID_F_L.I[0] + PID_F_L.D[0];
}

/*
 * PID FOLLOW LEFT RULE
 */

/*
 * func      : void PID_Calc_LeftRule(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_LeftRule(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */

	PID_F_L.pid_value[2]=PID_F_L.pid_value[1];
	PID_F_L.pid_value[1]=PID_F_L.pid_value[0];

	PID_F_L.error[2]=PID_F_L.error[1];
	PID_F_L.error[1]=PID_F_L.error[0];

	if (Ping[PING_ASKEW_LEFT]==PID_F_L.set_point) {PID_F_L.error[0]=0;}

	else if (Ping[PING_ASKEW_LEFT] > PID_F_L.set_point)
		{
			PID_F_L.error[0] = Ping[PING_ASKEW_LEFT] - PID_F_L.set_point;
		}

	else if (Ping[PING_ASKEW_LEFT] < PID_F_L.set_point)
		{
			PID_F_L.error[0] = PID_F_L.set_point - Ping[PING_ASKEW_LEFT];
		}

//	if (SHARP[SHARP_LEFT]==PID_F_L.set_point) {PID_F_L.error[0]=0;}
//
//	else if (SHARP[SHARP_LEFT] > PID_F_L.set_point)
//		{
//			PID_F_L.error[0] = SHARP[SHARP_LEFT] - PID_F_L.set_point;
//		}
//
//	else if (SHARP[SHARP_LEFT] < PID_F_L.set_point)
//		{
//			PID_F_L.error[0] = PID_F_L.set_point - SHARP[SHARP_LEFT];
//		}

	/*
	 * PID FORMULA
	 */
	PID_F_L.P[2]= PID_F_L.error[0]-PID_F_L.error[2];
	PID_F_L.P[1]= PID_F_L.Kp;
	PID_F_L.P[0]= PID_F_L.P[1]*PID_F_L.P[2]; //Proportional Controller

	PID_F_L.I[2]= PID_F_L.Ki*PID_F_L.Ts/2;
	PID_F_L.I[1]= PID_F_L.error[0]+(2*PID_F_L.error[1])+PID_F_L.error[2];
	PID_F_L.I[0]= PID_F_L.I[2]*PID_F_L.I[1]; //Integral Controller

	PID_F_L.D[2]= 2*PID_F_L.Kd/PID_F_L.Ts;
	PID_F_L.D[1]= PID_F_L.error[0]-(2*PID_F_L.error[1])+PID_F_L.error[2];
	PID_F_L.D[0]= PID_F_L.D[2]*PID_F_L.D[1]; //Derivative Controller

//	PID_F_L.I= ( (PID_F_L.Ki*PID_F_L.Ts/2)*(PID_F_L.error[0]+(2*PID_F_L.error[1])+PID_F_L.error[2]) );
//	PID_F_L.D= ( (2*PID_F_L.Kd/PID_F_L.Ts)*(PID_F_L.error[0]-(2*PID_F_L.error[1])+PID_F_L.error[2]));

	PID_F_L.pid_value[0]= PID_F_L.pid_value[2] + PID_F_L.P[0] + PID_F_L.I[0] + PID_F_L.D[0];
}


/*
 * func      : void PID_Calc_Reverse(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Hafidin
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_LeftRule_Reverse(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_F_R.pid_value[2]=PID_F_R.pid_value[1];
	PID_F_R.pid_value[1]=PID_F_R.pid_value[0];

	PID_F_R.error[2]=PID_F_R.error[1];
	PID_F_R.error[1]=PID_F_R.error[0];

	if (Ping[PING_REAR_RIGHT]==PID_F_R.set_point) {PID_F_R.error[0]=0;}
	else if (Ping[PING_REAR_RIGHT] > PID_F_R.set_point)
		{
			PID_F_R.error[0] = Ping[PING_REAR_RIGHT] - PID_F_R.set_point;
		}

	else if (Ping[PING_REAR_RIGHT] < PID_F_R.set_point)
		{
			PID_F_R.error[0] = PID_F_R.set_point - Ping[PING_REAR_RIGHT];
		}

	/*
	 * PID FORMULA
	 */
	PID_F_R.P[2]= PID_F_R.error[0]-PID_F_R.error[2];
	PID_F_R.P[1]= PID_F_R.Kp;
	PID_F_R.P[0]= PID_F_R.P[1]*PID_F_R.P[2]; //Proportional Controller

	PID_F_R.I[2]= PID_F_R.Ki*PID_F_R.Ts/2;
	PID_F_R.I[1]= PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.I[0]= PID_F_R.I[2]*PID_F_R.I[1]; //Integral Controller


	PID_F_R.D[2]= 2*PID_F_R.Kd/PID_F_R.Ts;
	PID_F_R.D[1]= PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.D[0]= PID_F_R.D[2]*PID_F_R.D[1]; //Derivative Controller

//	PID_F_R.I= ( (PID_F_R.Ki*PID_F_R.Ts/2)*(PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2]) );
//	PID_F_R.D= ( (2*PID_F_R.Kd/PID_F_R.Ts)*(PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2]));

	PID_F_R.pid_value[0]= PID_F_R.pid_value[2] + PID_F_R.P[0] + PID_F_R.I[0] + PID_F_R.D[0];
}

/*	============= PID FOLLOW FLAME ===============
 * func      : void PID_Calc_FlameRule(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Toni
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_FlameRule(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_F_R.pid_value[2]=PID_F_R.pid_value[1];
	PID_F_R.pid_value[1]=PID_F_R.pid_value[0];

	PID_F_R.error[2]=PID_F_R.error[1];
	PID_F_R.error[1]=PID_F_R.error[0];

	if (FlameSenseDigi[0]==PID_F_R.set_point) {PID_F_R.error[0]=0;}
	else if (FlameSenseDigi[0] > PID_F_R.set_point)
		{
			PID_F_R.error[0] = FlameSenseDigi[0] - PID_F_R.set_point;
		}

	else if (FlameSenseDigi[0] < PID_F_R.set_point)
		{
			PID_F_R.error[0] = PID_F_R.set_point - FlameSenseDigi[0];
		}

	/*
	 * PID FORMULA
	 */
	PID_F_R.P[2]= PID_F_R.error[0]-PID_F_R.error[2];
	PID_F_R.P[1]= PID_F_R.Kp;
	PID_F_R.P[0]= PID_F_R.P[1]*PID_F_R.P[2]; //Proportional Controller

	PID_F_R.I[2]= PID_F_R.Ki*PID_F_R.Ts/2;
	PID_F_R.I[1]= PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.I[0]= PID_F_R.I[2]*PID_F_R.I[1]; //Integral Controller


	PID_F_R.D[2]= 2*PID_F_R.Kd/PID_F_R.Ts;
	PID_F_R.D[1]= PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.D[0]= PID_F_R.D[2]*PID_F_R.D[1]; //Derivative Controller

//	PID_F_R.I= ( (PID_F_R.Ki*PID_F_R.Ts/2)*(PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2]) );
//	PID_F_R.D= ( (2*PID_F_R.Kd/PID_F_R.Ts)*(PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2]));

	PID_F_R.pid_value[0]= PID_F_R.pid_value[2] + PID_F_R.P[0] + PID_F_R.I[0] + PID_F_R.D[0];
}


/* func      : void PID_Calculate_RightRule_Interrupt_Init(void)
 * brief     : PID Calculate RightRule Timer Interrupt Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Toni
 * Programmer's Note: PID Calculate RightRule Initialization using timer 5
 */
void PID_Calculate_Rule_Interrupt_Init(void)
{

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 839; //f per count= 84.000.000/(839+1)=100000Hz = 10us (0,00001 s)
	//335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 50;// 0,00001 s x 50 = 0.0005 s -> 1 Hz
//	TIM_TimeBaseStructure.TIM_Period = 500;// 0,1 ms x 500 = 50 ms -> 0,5 s -> 2 Hz
			//200; //0,1 X 200 = 20 ms -> 0,2 s -> 5 Hz
	//10000; //0,1ms x 10000 = 1 s
	//0.004*125000=500ms jadi sampling adc setiap 500ms //MAX 65535
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM3, ENABLE); //default di off dulu
//	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/* func      : void TIM3_IRQHandler(void)
 * brief     : PID_Calculate_RightRule Timer Handler
 * retval    : N/A
 * Ver       : 1
 * written By: Toni
 * Programmer's Note: PID_Calculate_RightRule Handler
 */
void TIM3_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
    	if(FOLLOW_CALC==KANAN)
    	{
    		PID_Calc_RightRule();
    	}
    	else if(FOLLOW_CALC==KANAN_BELAKANG)
    	{
    		PID_Calc_RightRule_Reverse();
    	}
    	else if(FOLLOW_CALC==KIRI)
    	{
    		PID_Calc_LeftRule();
    	}
    	else if(FOLLOW_CALC==KIRI_BELAKANG)
    	{
    		PID_Calc_LeftRule_Reverse();
    	}
    	else if(FOLLOW_CALC==FLAME)
    	{
    		PID_Calc_FlameRule();
    	}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    }
}

//PID TS SAMPLING COUNT
//stop counter
//pid calculate
//ts = counter
//reset counter
//start counter
//Sinyal kontrol ke actuator

///*
// * func      : void PID_Calc(void)
// * brief     : PID Controller Calculations
// * param     : N/A
// * Written By: Ryan
// * Ver       : 1
// * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
// * 					  This function should be called everytime PID function executed
// */
//void Centerize_PID_Calc(void)
//{
//	/*
//	 * Update Nilai Variable PID & Set-Point Error
//	 */
//
//	PID_DFL_R.pid_value[2]=PID_DFL_R.pid_value[1];
//	PID_DFL_R.pid_value[1]=PID_DFL_R.pid_value[0];
//
//	PID_DFL_R.error[2]=PID_DFL_R.error[1];
//	PID_DFL_R.error[1]=PID_DFL_R.error[0];
//
//	if (Ping[PING_RIGHT]==PID_DFL_R.set_point) {PID_DFL_R.error[0]=0;}
//	else if (Ping[PING_RIGHT] > PID_DFL_R.set_point)
//		{
//			PID_DFL_R.error[0] = Ping[PING_RIGHT] - PID_DFL_R.set_point;
//		}
//
//	else if (Ping[PING_RIGHT] < PID_DFL_R.set_point)
//		{
//			PID_DFL_R.error[0] = PID_DFL_R.set_point - Ping[PING_RIGHT];
//		}
//
//	/*
//	 * PID FORMULA
//	 */
//	PID_DFL_R.P[2]= PID_DFL_R.error[0]-PID_DFL_R.error[2];
//	PID_DFL_R.P[1]= PID_DFL_R.Kp;
//	PID_DFL_R.P[0]= PID_DFL_R.P[1]*PID_DFL_R.P[2]; //Proportional Controller
//
//	PID_DFL_R.I[2]= PID_DFL_R.Ki*PID_DFL_R.Ts/2;
//	PID_DFL_R.I[1]= PID_DFL_R.error[0]+(2*PID_DFL_R.error[1])+PID_DFL_R.error[2];
//	PID_DFL_R.I[0]= PID_DFL_R.I[2]*PID_DFL_R.I[1]; //Integral Controller
//
//	PID_DFL_R.D[2]= 2*PID_DFL_R.Kd/PID_DFL_R.Ts;
//	PID_DFL_R.D[1]= PID_DFL_R.error[0]-(2*PID_DFL_R.error[1])+PID_DFL_R.error[2];
//	PID_DFL_R.D[0]= PID_DFL_R.D[2]*PID_DFL_R.D[1]; //Derivative Controller
//
//	//PID_F_R.I= ( (PID_F_R.Ki*PID_F_R.Ts/2)*(PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2]) );
//	//PID_F_R.D= ( (2*PID_F_R.Kd/PID_F_R.Ts)*(PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2]));
//
//	PID_DFL_R.pid_value[0]= PID_DFL_R.pid_value[2] + PID_DFL_R.P[0] + PID_DFL_R.I[0] + PID_DFL_R.D[0];
//}

//void Centerize_Right(void)
//{
//	if (Ping[PING_FRONT]<=25)
//	{
//		while (Ping[PING_ASKEW_RIGHT]<=15)
//		{
//			mov_rot_left(MED, FAR);
//		}
//
//		if (Ping[PING_ASKEW_RIGHT]>50)
//		{
//			mov_rot_right(MED, FAR);
//		}
//	}
//	else PID_Centerize_Right();
//}
//
//void PID_Centerize_Right(void)
//{
//	Centerize_PID_Calc();
//
//	//KONDISI ROBOT SESUAI
//	if ( Ping[PING_RIGHT]==PID_DFL_R.set_point )
//		{
//			mov_fwd_5cm(5, MED);
//		}
//
//	//KONDISI ROBOT JAUH DARI DINDING
//	else if ( Ping[PING_RIGHT]>PID_DFL_R.set_point )
//		{
//			//if (PID_DFL_R.pid_value[0]>=3) PID_DFL_R.pid_value[0]=3; //windup
//
//			if ((PID_DFL_R.pid_value[0]<1)&&(PID_DFL_R.pid_value[0]>=0))
//				{
//					mov_fwd_5cm(5, MED);
//				}
//			Centerize_deflect_right(MED, FAR, &PID_DFL_R.pid_value[0]);
//		}
//
//	//KONDISI ROBOT DEKAT DENGAN DINDING
//	else if ( Ping[PING_RIGHT]<PID_DFL_R.set_point )
//		{
//			//if (PID_DFL_R.pid_value[0]>=3) PID_DFL_R.pid_value[0]=3; //windup
//			if ((PID_DFL_R.pid_value[0]<1)&&(PID_DFL_R.pid_value[0]>=0))
//				{
//					mov_fwd_5cm(5, MED);
//				}
//			 Centerize_deflect_left(MED, FAR, &PID_DFL_R.pid_value[0]);
//		}
//}
//
//
//void Centerize_deflect_right(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	int counter;
//	//int limit= *COMMAND_LOOP;
//
//	for(counter=1;counter<=*COMMAND_LOOP;counter++)
//	{
//		mov_deflect_right(MED, FAR);
//	}
//
//}
//
//void Centerize_deflect_left(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	int counter;
//	//int limit= *COMMAND_LOOP;
//	mov_askew_left_transition();
//	for(counter=1;counter<=*COMMAND_LOOP;counter++)
//	{
//		mov_deflect_left(MED, FAR);
//	}
//
//}




/*
 *  BW PID CONTROLLER RUNTIME TUNING
 */
void PID_Runtime_Tuning(void)
{
	int MENU_VAR;

	while(BUTTON_IDLE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"PID CONTROLLER");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"RUNTIME");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"TUNING");lcd_putstr(lcd);
		delay_ms(100);
	}

	if(BW_BUTTON_CLICKED)
	{


		while(1)
		{
//			while(BUTTON_IDLE)
//			{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"PID TUNING");lcd_putstr(lcd);
//				lcd_gotoxy(0,2);sprintf(lcd,"INITIALIZING");lcd_putstr(lcd);
//				delay_ms(100);
//			}

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

			switch(MENU_VAR)
			{
				case 0:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW RIGHT");lcd_putstr(lcd);
							delay_ms(100);
							while(MENU_VAR==0)
							{
								follow_right_counter(1);

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
								//WALL FOLLOW START
							}


						}break;

				case 1:
						{
							mov_static();
							Kp_Tuning();

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
							//Kp Tuning

						}break;
				case 2:
						{
							mov_static();
							Ki_Tuning();

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
							//Ki Tuning
						}break;
				case 3:
						{
							mov_static();
							Kd_Tuning();

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
							//Kd Tuning
						}break;

			}
		}

	}

}

void Kp_Tuning(void)
{

	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			BW_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_R.Kp++;
		}
		if(BUTTON_B_CLICKED)
		{
			BW_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_R.Kp--;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Kp: %d",(int)PID_F_R.Kp);lcd_putstr(lcd);
		delay_ms(100);
	}

}

void Ki_Tuning(void)
{

	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			BW_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_R.Ki++;
		}
		if(BUTTON_B_CLICKED)
		{
			BW_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_R.Ki--;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Ki: %d",(int)PID_F_R.Ki);lcd_putstr(lcd);
		delay_ms(100);
	}
}

void Kd_Tuning(void)
{

	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			BW_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_R.Kd++;
		}
		if(BUTTON_B_CLICKED)
		{
			BW_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_R.Kd--;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Kd: %d",(int)PID_F_R.Kd);lcd_putstr(lcd);
		delay_ms(100);
	}

}
