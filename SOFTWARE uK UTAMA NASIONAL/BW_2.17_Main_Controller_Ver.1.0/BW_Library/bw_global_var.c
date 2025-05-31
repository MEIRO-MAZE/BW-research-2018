#include "bw_global_var.h"

/*
 * BW TCS3200 GLOBAL VARIABLES
 */

char tcs3200;

/*
 * LEGACY COLOUR CODE (used in bw_tcs3200 library)
 */
//unsigned int COLOUR_NONE  = 0;
//unsigned int COLOUR_BLACK = 1;
//unsigned int COLOUR_WHITE = 2;
//unsigned int COLOUR_RED   = 3;
//unsigned int COLOUR_BLUE  = 4;
//unsigned int COLOUR_GRAY  = 5;

/*
 * BW Ver 2.0 Colour Code (used in bw_tcs3200_receiver library)
 */
//unsigned int COLUR_NONE		= 0;
//unsigned int COLOUR_BLACK	= 1;
//unsigned int COLOUR_GRAY	= 2;
//unsigned int COLOUR_WHITE	= 3;
//unsigned int COLOUR_RED	    = 4;
//unsigned int COLOUR_BLUE    = 5;

//unsigned int COLUR_NONE		= 0;
unsigned int COLOUR_BLACK	= 0;
unsigned int COLOUR_GRAY	= 2;
unsigned int COLOUR_WHITE	= 1;
unsigned int COLOUR_RED	    = 4;
unsigned int COLOUR_BLUE    = 5;

unsigned int F_DETECTED_COLOUR=0;
unsigned int M_DETECTED_COLOUR=0;

float F_sum_red=0, F_sum_blue=0, F_sum_white=0,F_sum_green, F_THRESHOLD=0, F_TOTAL_SUM=0;
float M_sum_red=0, M_sum_blue=0, M_sum_white=0,M_sum_green, M_THRESHOLD=0, M_TOTAL_SUM=0;

//TCS3200 MODE
unsigned int FRONT_TCS3200 = 1;
unsigned int MID_TCS3200   = 2;

//TRACER FLAG
//unsigned int TRACER_STAT=0;
unsigned int COLOUR_STAT;
unsigned int CANDLE_CIRCLE_FLAG = 0;
unsigned int CANDLE_CIRCLE_DETECTED =1;

int F_TRACER,M_TRACER,TRACER_FLAG;

/*
 * BW FOLLOW CARPET MACROS
 */
//unsigned int NORMAL  = 1;
//unsigned int INVERSE = 2;

/*
 *  BW HOME AND ZONE FLAG
 */


unsigned int INITIAL_ZONE=0;
unsigned int ZONE=0;

unsigned int ZONE_BLACK = 1;
unsigned int ZONE_RED   = 2;
unsigned int ZONE_BLUE  = 3;
unsigned int TRACER     = 4;

unsigned int BW_CROSS_MODE = 0;

//BW START MODE
unsigned int START_MODE=0;
enum BW_START_MODE {NON_ARBITRARY_START = 1, ARBITRARY_START = 2};


/*
 * BW ROOM AND CORRIDOR VARIABLES
 */
unsigned int BW_LOCATION[2]={1,0};
unsigned int LOCATION_CORRIDOR=0;
unsigned int LOCATION_ROOM=1;

unsigned int TANDA_FOLLOW[3]={0,0,0};
unsigned int FOLLOW_KIRI=1;
unsigned int FOLLOW_KANAN=2;

/*
 * BW FIRE FIGHTING VARIABLES
 */
unsigned int EXTINGUISHED_FIRE= 0;
unsigned int FIRE_PUTOFF=0;



/*
 * BW ROTARY SWITCH GLOBAL VARIABLES
 */
uint16_t rot_switch_mode;

/*
 * BW CAT OBSTACLE VARIABLES
 */
unsigned int CAT_FOUND[2]={0,0};
unsigned int CAT_SHIFT_FOLLOW=0;
unsigned int SHIFT_FOLLOW=1;
unsigned int NO_SHIFT=0;


unsigned int CAT_FLAG			= 0;
unsigned int CAT_FLAG_A			= 0;
unsigned int CAT_FLAG_B			= 0;
unsigned int CAT_FLAG_C			= 0;
unsigned int CAT_DETECTED 		= 1;
unsigned int CAT_NOT_DETECTED 	= 0;

unsigned int CAT_DETECTOR = 0;
unsigned int CAT_ACTIVATED = 1;
unsigned int CAT_DIACTIVATED =0;
/*
 * BW INFRARED PROXIMITY SENSOR
 */

int INFRARED[9];

/*
 * BW SOUND ACTIVATION VARIABLES
 */
uint16_t BW_Sound_Activate=0;

/*
 * BW REGULAR ACTIVATION VARIABLES
 */
uint16_t BW_START=0;
/*
 * BW HAMAMATSU UV-TRON GLOBAL VARIABLES
 */
unsigned int UV_state;

unsigned int UV_Lock=0;

unsigned int UV_R2FLAG=0;
unsigned int UV_R2FLAG_ACTIVE=1;
unsigned int UV_R2FLAG_INACTIVE=0;

/*
 * BW ROTARY SWITCH
 */
unsigned int ADCResult;

/*
 * BW LED BLINK INTERRUPT
 */
uint16_t led_counter=1;
uint16_t led_off_counter=0;
uint16_t led_snd_off_counter=0;

//--------Variable TPA n Servo---------//
int DATA;
int sudut_servo=0;
int PWM_FIRE;


//--------Variable UV tpa---------//
unsigned char sensor_UV_front=1,sensor_UV_back=1;
unsigned char sensor_UV_lock=0;
unsigned char fight=0;
unsigned char hitung=0;
unsigned int panas=0;
int regs;
int i=0, temp=0;
unsigned char suhu_ruang=0, suhu_pixel[7], pixel[10];



unsigned int FIRE=0;


//USART COMM VARIABLES
char received_string[MAX_STRLEN],buf[16],data1_lcd[16],data2_lcd[16],tampil_adc[16];
unsigned int Ping[9],USART_Count=0;
unsigned int USARTFlame_Counter=0;
unsigned int USARTFlameDigi_Counter=0;
unsigned int USART_Bluetooth_Count=0;
unsigned int COMMAND_FLAG_A = 0x3C;
unsigned int COMMAND_FLAG_B = 0x3E;
unsigned int COMMAND_COMPLETED = 0x7C;
unsigned int COMMAND_NOT_RECEIVED = 0x3F;
char command_code[5];

//SHARP IR RANGEFINDER
unsigned int SHARP[3];


//TCS3200 RAW VALUE FLAG
unsigned int RAW_VAL_FLAG = 0x52;

/*
 * BW DYNAMIXEL HEXAPOD MOVING VARIABLES
 */
//NEW VAR
unsigned int GERAK=0;

				  	 //COXA,FEMUR,TIBIA
int SUDUT_STATIC[18]={  90 ,  18 , 105 ,	//FR
					    90 ,  18 , 105 ,	//ML
					    90 ,  20 , 105 ,	//RR

					    90 ,  18 , 105 ,	//FL
					    90 ,  18 , 105 ,	//MR
					    90 ,  20 , 105 };	//RL

//int SUDUT_STATIC_BWD[18]={  90 ,  20 , 105 ,	//FR
//					    90 ,  18 , 108 ,	//ML
//					    90 ,  18 , 110 ,	//RR
//
//					    90 ,  18 , 108 ,	//FL
//					    90 ,  18 , 108 ,	//MR
//					    90 ,  20 , 108 };	//RL


	 //COXA,FEMUR,TIBIA
int SUDUT_STATIC_BWD[18]={  90 ,  15 , 105 ,	//FR
							90 ,  15 , 105 ,	//ML
							90 ,  15 , 105 ,	//RR

							90 ,  15 , 105 ,	//FL
							90 ,  15 , 105 ,	//MR
							90 ,  15 , 105 };	//RL

int SUDUT_ANGKAT=15;
//IK COXA AND TIBIA LEG 1 ,2 ,3 for Z+ from EXCEL
//// MOV FWD ZCOXA = 35 and Z TIBIA = 25
//int IKFWD_COXA_R[3]={7,17,12};
//int IKFWD_TIBIA_R[3]={12,3,18};
//int IKFWD_COXA_L[3]={7,17,12};
//int IKFWD_TIBIA_L[3]={12,3,18};

//// MOV FWD ZCOXA = 30 and Z TIBIA = 20
//int IKFWD_COXA_R[3]={12,35,42};
//int IKFWD_TIBIA_R[3]={12,3,18};
//int IKFWD_COXA_L[3]={12,35,42};
//int IKFWD_TIBIA_L[3]={12,3,18};

//// MOV FWD ZCOXA = 35 and Z TIBIA = 25
//int IKFWD_COXA_R[3]={12,35,42};
//int IKFWD_TIBIA_R[3]={17,7,36};
//int IKFWD_COXA_L[3]={12,35,42};
//int IKFWD_TIBIA_L[3]={17,7,36};

// MOV FWD ZCOXA = 30 and Z TIBIA = 30
int IKFWD_COXA_R[3]={11,31,32};
int IKFWD_TIBIA_R[3]={18,18,48};
int IKFWD_COXA_L[3]={11,31,32};
int IKFWD_TIBIA_L[3]={18,18,48};

//// MOV FWD ZCOXA = 20 and Z TIBIA = 20
//int IKFWD_COXA_R[3]={8,22,17};
//int IKFWD_TIBIA_R[3]={15,5,26};
//int IKFWD_COXA_L[3]={8,22,17};
//int IKFWD_TIBIA_L[3]={15,5,26};

//// MOV FWD ZCOXA = 10 and Z TIBIA = 10
//int IKFWD_COXA_R2[3]={5,11,7};
//int IKFWD_TIBIA_R2[3]={9,1,11};
//int IKFWD_COXA_L2[3]={5,11,7};
//int IKFWD_TIBIA_L2[3]={9,1,11};

//		Sementara
// MOV FWD ZCOXA = 20 and Z TIBIA = 20
int IKFWD_COXA_R1[3]={8,22,17};
int IKFWD_TIBIA_R1[3]={15,15,26};
int IKFWD_COXA_L1[3]={8,22,17};
int IKFWD_TIBIA_L1[3]={15,15,26};

//// MOV FWD ZCOXA = 15 and Z TIBIA = 15
//int IKFWD_COXA_R1[3]={7,17,12};
//int IKFWD_TIBIA_R1[3]={12,3,18};
//int IKFWD_COXA_L1[3]={7,17,12};
//int IKFWD_TIBIA_L1[3]={12,3,18};

// MOV FWD ZCOXA = 10 and Z TIBIA = 10
int IKFWD_COXA_R2[3]={5,11,7};
int IKFWD_TIBIA_R2[3]={9,1,11};
int IKFWD_COXA_L2[3]={5,11,7};
int IKFWD_TIBIA_L2[3]={9,1,11};

// MOV FWD ZCOXA = 5 and Z TIBIA = 5
int IKFWD_COXA_R3[3]={3,6,3};
int IKFWD_TIBIA_R3[3]={5,0,5};
int IKFWD_COXA_L3[3]={3,6,3};
int IKFWD_TIBIA_L3[3]={5,0,5};

// MOV ROT ZCOXA_L = 15
int IKROT_COXA[2]={0,0};

// MOV ROT ZCOXA_L = 10
int IKROT_COXA1[2]={0,0};

// MOV ROT ZCOXA_L = 5
int IKROT_COXA2[2]={0,0};

/*//SLOW
// MOV FWD SLOW ZCOXA = 20 and Z TIBIA = 20
int IKFWD_COXA_R2[3]={8,22,17};
int IKFWD_TIBIA_R2[3]={15,5,26};
int IKFWD_COXA_L2[3]={8,22,17};
int IKFWD_TIBIA_L2[3]={15,5,26};
*/
// MOV CURVE RIGHT SLOW ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKCRVR_COXA_R2[3]={3,6,3};
int IKCRVR_TIBIA_R2[3]={5,0,5};
int IKCRVR_COXA_L2[3]={8,22,17};
int IKCRVR_TIBIA_L2[3]={15,5,26};

// MOV PID CURVE RIGHT SLOW ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKRPID_COXA_R2[3]={5,16,14};
int IKRPID_TIBIA_R2[3]={10,5,21};


// MOV CURVE RIGHT ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKCRVR_COXA_R[3]={3,6,3};
int IKCRVR_TIBIA_R[3]={5,0,5};
int IKCRVR_COXA_L[3]={12,35,42};
int IKCRVR_TIBIA_L[3]={17,7,36};

// MOV PID CURVE RIGHT ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKRPID_COXA_R[3]={9,29,39};
int IKRPID_TIBIA_R[3]={12,7,31};

// MOV SLIDE RIGHT X = 20
int IKSLR_COXA[3]={16,0,23};
int IKSLR_TIBIA[4]={7,18,30,17};

// MOV SLIDE RIGHT X = 15
int IKSLR_COXA1[3]={13,0,17};
int IKSLR_TIBIA1[4]={6,14,21,12};

// MOV SLIDE RIGHT X = 10
int IKSLR_COXA2[3]={9,0,11};
int IKSLR_TIBIA2[4]={5,10,13,7};

// MIRING, SPEED ULTRAFAST
//// MOV SLIDE RIGHT X = 15
//int IKSLR_COXA[3]={13,0,17};
//int IKSLR_TIBIA[4]={6,14,21,12};
//
//// MOV SLIDE RIGHT X = 10
//int IKSLR_COXA1[3]={9,0,11};
//int IKSLR_TIBIA1[4]={5,10,13,7};
//
//// MOV SLIDE RIGHT X = 5
//int IKSLR_COXA2[3]={5,0,5};
//int IKSLR_TIBIA2[4]={2,5,6,3};


// MOV CURVE LEFT ZCOXA_R = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 35
int IKCRVL_COXA_R[3]={12,35,42};
int IKCRVL_TIBIA_R[3]={17,7,36};
int IKCRVL_COXA_L[3]={3,6,3};
int IKCRVL_TIBIA_L[3]={5,0,5};

// MOV PID CURVE LEFT ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKLPID_COXA_L[3]={9,29,39};
int IKLPID_TIBIA_L[3]={12,7,31};

//SLOW
// MOV CURVE LEFT SLOW ZCOXA_R = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 35
int IKCRVL_COXA_R2[3]={8,22,17};
int IKCRVL_TIBIA_R2[3]={15,5,26};
int IKCRVL_COXA_L2[3]={3,6,3};
int IKCRVL_TIBIA_L2[3]={5,0,5};

// MOV PID CURVE LEFT SLOW ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKLPID_COXA_L2[3]={5,16,14};
int IKLPID_TIBIA_L2[3]={10,5,21};

// MOV SLIDE LEFT X = 20
int IKSLL_COXA[3]={16,0,23};
int IKSLL_TIBIA[4]={7,18,30,17};

// MOV SLIDE LEFT X = 15
int IKSLL_COXA1[3]={13,0,17};
int IKSLL_TIBIA1[4]={6,14,21,12};

// MOV SLIDE LEFT X = 10
int IKSLL_COXA2[3]={9,0,11};
int IKSLL_TIBIA2[4]={5,10,13,7};

//// MIRING SPEED ULTRAFAST
//// MOV SLIDE LEFT X = 15
//int IKSLL_COXA[3]={13,0,17};
//int IKSLL_TIBIA[4]={6,14,21,12};
//
//// MOV SLIDE LEFT X = 10
//int IKSLL_COXA1[3]={9,0,11};
//int IKSLL_TIBIA1[4]={5,10,13,7};
//
//// MOV SLIDE LEFT X = 5
//int IKSLL_COXA2[3]={5,0,5};
//int IKSLL_TIBIA2[4]={2,5,6,3};


//// MOV BWD ZCOXA = 35 and Z TIBIA = 25
//int IKBWD_COXA_R[3]={12,35,42};
//int IKBWD_TIBIA_R[3]={17,7,36};
//int IKBWD_COXA_L[3]={12,35,42};
//int IKBWD_TIBIA_L[3]={17,7,36};

// MOV BWD ZCOXA = 15 and Z TIBIA = 15
int IKBWD_COXA_R[3]={7,17,12};
int IKBWD_TIBIA_R[3]={12,3,18};
int IKBWD_COXA_L[3]={7,17,12};
int IKBWD_TIBIA_L[3]={12,3,18};

//// MOV CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
//int IKCRVRR_COXA_L[3]={3,6,3};
//int IKCRVRR_TIBIA_L[3]={5,0,5};
//int IKCRVRR_COXA_R[3]={12,35,42};
//int IKCRVRR_TIBIA_R[3]={17,7,36};
//
//// MOV PID CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
//int IKPIDR_COXA_L[3]={9,29,39};
//int IKPIDR_TIBIA_L[3]={12,7,31};
//
//// MOV CURVE LEFT REVERSE ZCOXA_R = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
//int IKCRVLR_COXA_L[3]={12,35,42};
//int IKCRVLR_TIBIA_L[3]={17,7,36};
//int IKCRVLR_COXA_R[3]={3,6,3};
//int IKCRVLR_TIBIA_R[3]={5,0,5};
//
//// MOV PID CURVE LEFT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
//int IKPIDR_COXA_R[3]={9,29,39};
//int IKPIDR_TIBIA_R[3]={12,7,31};

// MOV CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKCRVRR_COXA_L[3]={3,6,3};
int IKCRVRR_TIBIA_L[3]={5,0,5};
int IKCRVRR_COXA_R[3]={7,17,12};
int IKCRVRR_TIBIA_R[3]={12,3,18};

// MOV PID CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKPIDR_COXA_L[3]={4,11,9};
int IKPIDR_TIBIA_L[3]={7,3,13};

// MOV CURVE LEFT REVERSE ZCOXA_R = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKCRVLR_COXA_L[3]={7,17,12};
int IKCRVLR_TIBIA_L[3]={12,3,18};
int IKCRVLR_COXA_R[3]={3,6,3};
int IKCRVLR_TIBIA_R[3]={5,0,5};

// MOV PID CURVE LEFT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKPIDR_COXA_R[3]={4,11,9};
int IKPIDR_TIBIA_R[3]={7,3,13};

/*
 * BW HEXAPOD VARIABLES
 */

//uint32_t CCR1_Val, CCR2_Val, CCR3_Val;
uint32_t Count;
uint32_t nCount;

int sudut_target[18],sudut_awal[18],x=0,z_A[18],pembagi,y_A[18],sudut_tahap1[18],sudut_tahap2[18];

//float gamma[6];
int leg;
int ww[6];
float beta[6];
float leg_next[6];
float A_body;			// translasi pusat badan
float A_leg[6];			// translasi setiap pangkal kaki
float P_body;			// jarak titik pusat robot ke titik imajiner putar
int epsilon_body;		// besar sudut vektor hadap thdp vektor poros-imajiner
float phi[6];
float lambpsi[6];		//lambda / psi temporal
float P_leg[6];			// jarak titik pusat kaki ke titik imajiner putar
float epsilon[6];		// epsilon tiap N

unsigned int sudut[18]= {4915,4915,4915,4915,4915,4915,    	//3615 == 1 ms   4915 == 1,5 ms
						 4915,4915,4915,4915,4915,4915,			//6550 == 2 ms
						 4915,4915,4915,4915,4915,4915};

unsigned char y,a,b,c,d,v,index_bantu,index_servo3,index_servo2;
uint32_t PrescalerValue;

    const float A_const[18] ={26.68,26.68,26.68,26.68,26.68,26.68,
    		 	 	 	 	  26.68,26.68,26.68,26.68,26.68,26.68,
    		 	 	 	 	  26.68,26.68,26.68,26.68,26.68,26.68
    						  /*13.33,50,13.33,13.33,50,13.33,
                              18.18,18.18,18.18,18.18,18.18,18.18,
                              18.18,18.18,18.18,18.18,18.18,18.18*/ };

    const int B_const[18]   ={2681,2681,2681,2681,2681,2681,
    		2681,2681,2681,2681,2681,2681,
    		2681,2681,2681,2681,2681,2681
			  	  	  	  	  /*1800,-1500,1800
							  ,1800,-1500,1800,
                              1364,1364,1364,1364,1364,1364,
                              1364,1364,1364,1364,1364,1364*/};

    //LAST REVISED BY RYAN: MON, APRIL 2nd, 2015
     float correct[18]        ={/*0,0,0,0,0,0,					0,0,0,0,0,0
			  	  	  	  	  0,0,0,0,0,0,						100,35,93,43,105,37
			  	  	  	  	  0,0,0,0,0,0						121,41,103,37,102,30*/
    							/*
//JANGAN ADA NILAI (-)			* LEFT SECTION
    		    				* Coxa,Femur,Tibia
    		    				* Coxa ditambah makin ke belakang
    		    				* Femur ditambah makin turun
    		    				* Tibia ditambah makin masuk ke dalam
    		    				*
    		    				*/
//    		 	 	 	 	 	10,40,40,	//FRONT LEFT LEG
//    		 	 	 	 	 	19,40,40,	//FRONT LEFT LEG
    		 	 	 	 	 	24,100,13,	//FRONT LEFT LEG

//    		 	 	 	 	 	10,42,31,	//MIDDLE LEFT LEG
//    		 	 	 	 	 	16,42,31,	//MIDDLE LEFT LEG
    		 	 	 	 	 	22,124,22,	//MIDDLE LEFT LEG

//    		 	 	 	 	 	10,25,24,	//REAR LEFT LEG
//    		 	 	 	 	 	44,25,24,	//REAR LEFT LEG
    		 	 	 	 	 	0,98,6,	//REAR LEFT LEG

    		    		 	 	 /* RIGHT SECTION
    		    		 	 	 * Coxa,Femur,Tibia
    		    		 	 	 * Coxa ditambah makin ke belakang
    		    		 	 	 * Femur ditambah makin turun
    		    		 	 	 * Tibia ditambah makin masuk ke dalam
    		    		 	 	 */

//    		 	 	 	 	 	 10,40,22,	//FRONT RIGHT LEG
//    		 	 	 	 	 	 37,40,22,	//FRONT RIGHT LEG
    		 	 	 	 	 	 35,53,14,	//FRONT RIGHT LEG

//    		 	 	 	 	 	 10,20,105,	//MIDDLE RIGHT LEG
//    		 	 	 	 	 	 28,20,105,	//MIDDLE RIGHT LEG
    		 	 	 	 	 	 30,115,13,	//MIDDLE RIGHT LEG

//    		 	 	 	 	 	 10,55,19,	//REAR RIGHT LEG
//    		 	 	 	 	 	 65,55,19,	//REAR RIGHT LEG
    		 	 	 	 	 	 38,94,6,	//REAR RIGHT LEG
    						  };
/*
    const float leg_1[6]	=	{8.2802,4.5,8.2802,8.2802,4.5,8.2802};	//L1
    const float leg_norm[6]	=	{9.5,9.5,9.5,9.5,9.5,9.5};				//L2
    const float alpha[6]	=	{30,90,150,30,90,150};					//alpha
*/
     const float leg_1[6]	=	{7.27,5.06,7.27,7.27,5.06,7.27};	//L1
//     const float leg_norm[6]=	{11,11,11,11,11,11};				//L2
     const float leg_norm[6]=	{8,8,8,8,8,8};				//L2
     const float alpha[6]	=	{30,90,150,30,90,150};					//alpha


float c1,c2;
float Lsem,c3,c4;
int i;
float temp_var,temp_var2;


/*
 * MPU6050 GYRO ACCELEROMETER VARIABLES
 */

unsigned int MPU6050_PWR_MGMT_1  = 0x6B;
unsigned int MPU6050_GYRO_CONFIG = 0x1B;
unsigned int MPU6050_ACCEL_CONFIG = 0x1C;
float Gyro_Mult;
//GYROSCOPE SENSITIVITY
unsigned int Gyro_Sensitivity_250s = 0x00;  /*!< Range is +- 250 degrees/s */
unsigned int Gyro_Sensitivity_500s = 0x01;  /*!< Range is +- 500 degrees/s */
const unsigned int Gyro_Sensitivity_1000s = 0x02; /*!< Range is +- 1000 degrees/s */
const unsigned int Gyro_Sensitivity_2000s = 0x03;  /*!< Range is +- 2000 degrees/s */

//ACCELEROMETER RANGE
unsigned int Accelerometer_Range = 0x00;
float Acce_Mult;

float ACCEL_DEG;
float GYRO_DEG;

//MPU6050 RECEIVER VARIABLEs
unsigned int IMU_SLAVE_DATA[4] = {0,0,0,0};
int YAW_IMU;
int PITCH_IMU;
int ROLL_IMU;
/*
 * CALCULATING DISTANCE
 */
double PI = 3.1415926535897932384626433832795;
double GRAVITY = 9806.65;

float dummy_correct[18];
unsigned int TEST = 0x5A;

/*
 * BW RUNTIME CALIBRATION VARIABLES
 */
int CALIBRATION_STAT=1;

/*
 *  BW ROOM COUNTER
 */

unsigned int ROOM_COUNTER=0;

/*
 * BW WARZONE FLAG
 */
unsigned int WARZONE_FLAG=0;
unsigned int SPECIAL_ZONE_FLAG=0;

/*
 * BW HOME CIRCLE
 */
unsigned int HOME_CIRCLE_FLAG 			= 0;
unsigned int HOME_CIRCLE_DETECTED 		= 1;
unsigned int HOME_CIRCLE_NOT_DETECTED 	= 0;

/*
 * FOLLOW HOME FLAG
 */
unsigned int FOLLOWHOME_FLAG			= 0;
unsigned int FOLLOWHOME_INACTIVE		= 0;
unsigned int FOLLOWHOME_ACTIVE			= 1;


/*
 * BW FIRE TRACKER COUNTER
 */
unsigned int firetrack_counter=0;


/*
 * BW FOUND FIRE OVERRIDE
 */
unsigned int BW_FOUND_FIRE_OVERRIDE=0;

/*
 * BW EXTINGUISHER FLAG
 */
unsigned int EXTINGUISHER_FLAG=0;

/*
 * BW ROOM 1 FLAG
 */
unsigned int ROOM1_FLAG=0;

/*
 * BW ROOM 1BC FLAG
 */
unsigned int ROOM1BC_FLAG=0;

/*
 * BW ROOM 2B FLAG
 */
unsigned int ROOM2B_FLAG=0;

/*
 * BW WARZONE COUNTER
 */
unsigned int WARZONE_COUNTER=0;

/*
 * BW GLOBAL COUNTER
 */
unsigned int global_counter=0;

/*
 * BW CROSS_ZONE VARIABLES
 */
unsigned int BW_CROSSING_AUTHORITY=0;
unsigned int CROSS_DISABLED=0;
unsigned int CROSS_ENABLED=1;
unsigned int BW_CROSSING_STATUS=0;
unsigned int NO_CROSSING=0;
unsigned int CROSSING_SUCCESS=1;
unsigned int CROSSING_FAILED=2;

/*
 *  BW STEAL ENEMY FIRE VARIABLES
 */
unsigned int STEAL_FIRE_STAT=0;
unsigned int STEAL_FIRE_COUNTER=0;
unsigned int STEALFIRE_SUCCESS=1;
unsigned int STEALFIRE_FAILED=2;
unsigned int ENEMY_ZONE_STAT=0;
unsigned int ENEMY_ZONE=1;
unsigned int COMFORT_ZONE=0;

/*
 * BW SPECIAL_CONDITION_FLAG
 */
unsigned int SPECIAL_CONDITION_FLAG=0;
unsigned int SPECIAL_CONDITION_ENABLED=1;
unsigned int SPECIAL_CONDITION_DISABLED=0;
unsigned int SPECIAL_CONDITION_COUNTER=0;
/*
 * BW ROOM FLAG
 */
//DEFAULT: PREVIOUS & PRESENT: OTHER ROOM
unsigned int ROOM_FLAG[2]={1,1};
unsigned int PRESENT_ROOM=0;
unsigned int PREVIOUS_ROOM=1;
unsigned int OTHER_ROOM=1;
unsigned int ROOM_ONE=2;
unsigned int WARZONE=3;

/*
 * BW VARIABLE DOOR
 */
unsigned int VARIABLE_DOOR=0;
unsigned int VAR_DOOR_NOT_DETECTED=0;
unsigned int VAR_DOOR_DETECTED=1;
unsigned int VAR_DOOR_SCAN=2;

/*
 * FIRST CAT ENCOUNTER
 */
unsigned int FIRST_CAT_ENCOUNTER=0;


/*
 * RETURN COUNTER
 */
unsigned int RETURN_COUNTER=0;

/*
 * FOLLOW CARPET FLAG
 */
unsigned int FOLLOW_CARPET_FLAG=0;
unsigned int FOLLOW_CARPET_ENABLED=1;
unsigned int FOLLOW_CARPET_DISABLED=0;
unsigned int FOLLOW_CARPET_ESCAPE_TRAP=2;

/*
 * RETURN
 */
//unsigned int RETURN_FLAG;
//unsigned int RETURN_ENABLED;
//unsigned int RETURN_DISABLED;


/*
 * BW ARTICULATED MANIPULATOR VARIABLES
 */

int Arm_Angle[3]={0,0,0};
int Arm_Correction[3]= {0,0,0};

uint32_t ARM_CCR1_Val, ARM_CCR2_Val, ARM_CCR3_Val;

/*
 * I2C MULTIBYTE READ
 */
uint8_t    I2C1_DATA[10];
uint8_t    I2C2_DATA[10];
uint8_t	   I2C3_DATA[10];
/*
 * CMPS11 VARIABLES
 */
/*
 *  CMPS-11 SERIAL COMMANDS
 */

unsigned int GET_VERSION 			= 0x11;
unsigned int GET_ANGLE_8_BIT 		= 0x12;
unsigned int GET_ANGLE_16_BIT		= 0x13;
unsigned int GET_PITCH 				= 0x14;
unsigned int GET_ROLL 				= 0x15;
unsigned int GET_PITCH_NO_KF 		= 0x16;
unsigned int GET_ROLL_NO_KF 		= 0x17;
unsigned int GET_MAG_RAW 			= 0x19;
unsigned int GET_ACCEL_RAW 			= 0x20;
unsigned int GET_GYRO_RAW 			= 0x21;
unsigned int GET_TEMP     		   	= 0x22;
unsigned int GET_ALL      		   	= 0x23;
unsigned int CALIBRATE_BYTE_1 	   	= 0xF0;
unsigned int CALIBRATE_BYTE_2 	   	= 0xF5;
unsigned int CALIBRATE_BYTE_3_FULL 	= 0xF6;
unsigned int CALIBRATE_BYTE_3_FLAT 	= 0xF7;
unsigned int CALIBRATE_EXIT       	= 0xF8;
unsigned int RESTORE_1             	= 0x6A;
unsigned int RESTORE_2             	= 0x7C;
unsigned int RESTORE_3             	= 0x81;
unsigned int BAUD_19200            	= 0xA0;
unsigned int BAUD_38400            	= 0xA1;

unsigned int USART2_DATA[6]={0,0,0,0,0,0};
unsigned int CMPS11_COMPASS_ANGLE =0;

int CMPS11_Angle;

/*
 * RETURN TRIP FLAG
 */
unsigned int RETURN_TRIP_FLAG=0;

/*
 * FLAME SENSOR VARIABLES
 */
unsigned int FlameSense[2]={0,0};
unsigned int FollowFlame_Flag=0,FlameTrack_Flag=0,FlameScan_Flag=0,FlameExtinguish_Flag=0,FlameApproach_Flag=0;

unsigned int FlameSenseDigi[2]={0,0};
unsigned int FlameFrontDigi[2]={0,0};

/*
 * 	BW CONTACT BUMPER
 */
unsigned int BUMPER[2]={0,0};


/*
 * BW TCS3200 SLAVE VARIABLES
 */

unsigned int TCS3200_SLV_CNT=0;
unsigned int TCS3200_SLV_STAT[4]={0,0,0,0};
unsigned int FRONT_PRESENT        = 0;
unsigned int FRONT_PREVIOUS       = 1;
unsigned int MIDDLE_PRESENT       = 2;
unsigned int MIDDLE_PREVIOUS      = 3;
unsigned int TCS3200_SLV_DATA[11]={0,0,0,0,0,0,0,0,0,0,0};
unsigned int DUMMY_DATA_A= 0x41;
unsigned int DUMMY_DATA_G= 0x47;

unsigned int TCS3200_CMD_CODE[5]={0,0,0,0,0};

const int TCS_CALIBRATE_WHITE           = 0x46;
const int TCS_CALIBRATE_BLACK           = 0x47;
const int TCS_CALIBRATE_GRAY            = 0x48;
const int TCS_CALIBRATE_GETRULE         = 0x49;

const int TCS_FRONT_SHOW_THRESHOLD      = 0x4A;
const int TCS_MIDDLE_SHOW_THRESHOLD     = 0x4B;

unsigned int TRIAL_MODE			= 0x41;
unsigned int CALIBRATION_MODE	= 0x42;

//unsigned int CALIBRATE_BLACK    = 0x43;
//unsigned int CALIBRATE_GRAY     = 0x44;
//unsigned int CALIBRATE_WHITE	= 0x45;

unsigned int START_BUTTON_CMD	= 0x53;
unsigned int BUTTON_A			= 0x41;
unsigned int BUTTON_B			= 0x42;
unsigned int CMD_COMPLETED		= 0x58;
unsigned int CMD_IDLE			= 0x5E;

//SENT COMMAND DATA
//unsigned int TCS_CMD_SEND_FRONT  	 = 0x41;
//unsigned int TCS_CMD_SEND_MIDDLE 	 = 0x42;
unsigned int TCS_CMD_SEND_RAW		 = 0x41;
unsigned int TRACER_CMD_SEND_RAW	 = 0x42;
const int IMU_CMD_SEND_RAW			 = '1';
const int SOUNDCHECK		 		 = '2';
unsigned int TCS_CMD_SEND_CONCLUSION = 0x43;
unsigned int TCS_CMD_SAVE_EEPROM     = 0x5A;
unsigned int BW_SOUND_ACTIVATED		 = 0x77;

unsigned int HYBRID_CMD_SEND_THRESHOLD= 0x58;


/*
 * TCS3200+TRACER NEW COMMAND FOR OPTMIZATION
 */
unsigned int CMD_GET_TCS3200		= 0x52;
unsigned int CMD_GET_TRACER		= 0x53;

/*
 * FOLLOWMODE FLAG
 */
unsigned int FOLLOWMODE_FLAG= 0;
const unsigned int FOLLOW_TRACER_WHITE= 1;
const unsigned int FOLLOW_CARPET_ACTIVE= 2;
const unsigned int FOLLOW_COLOUR_DISABLE= 0;

/*
 *  PHOTODIODE TRACER CALIBRATION COMMAND
 */

//BLACK/WHITE PHOTODIODE TRACER PROCESSOR COMMAND
const int TRACER_CALIBRATE_GRAY             = 0x4A;
const int TRACER_CALIBRATE_WHITE            = 0x4B;
const int TRACER_CALIBRATE_BLACK            = 0x4D;
const int TRACER_CALIBRATE_GETRULE          = 0x4C;

//RECEIVED DATA
unsigned int RCV_IDLE  		= 94;
unsigned int RCV_START 		= 53;
unsigned int RCV_BUTTON_A 	= 41;
unsigned int RCV_BUTTON_B	= 42;



/*
 * ROOM IDENTIFIER VARIABLES
 */

unsigned int HOME;

//ROOM[0] == DUMMY DATA / UNUSED
unsigned int ROOM[6]={99,13,13,13,13,13};

unsigned int HALLWAY_SC = 0;

unsigned int ROOM_1A 	= 1;
unsigned int ROOM_1B	= 2;
unsigned int ROOM_1C	= 3;

unsigned int ROOM_2A 	= 4;
unsigned int ROOM_2B	= 5;

unsigned int ROOM_3 	= 6;

unsigned int ROOM_4A 	= 7;
unsigned int ROOM_4B	= 8;





unsigned int ROOM_TYPE		= 0;
unsigned int NORMAL_ROOM	= 1;
unsigned int GRAY_ROOM 		= 2;

unsigned int HOME_POS	=0;
unsigned int TENGAH		=1;
unsigned int POJOK		=2;



/*
 * TRACER DETECTED IN BUMPER HANDLER ROUTINES
 */
unsigned int TRACER_IN_BUMPER;
unsigned int TRC_BMP_ACTIVE=1;
unsigned int TRC_BMP_INACTIVE=0;

/*	NASIPNAL
 * TRACER STATUS VARIABLES

unsigned int TRACER_STAT=0;
unsigned int TRACER_WHITE=1;					// diganti dengan TRACER_WHITE, GRAY dan BLACK untuk board yang pakai tracer aja
unsigned int TRACER_INACTIVE=0;
*/
/*
 * TRACER STATUS VARIABLES
 */
unsigned int TRACER_STAT=0;
unsigned int TRACER_WHITE=1;
unsigned int TRACER_BLACK=0;
unsigned int TRACER_GRAY=2;
unsigned int TRACER_BREAK=0;
/*
 * FOLLOW TRACER FLAG VARIABLES
 */
unsigned int FOLLOWTRACER_FLAG=0;
unsigned int FOLLOWTRACER_ENABLE=1;
unsigned int FOLLOWTRACER_DISABLE=0;

/*
 * FLAME SENSOR VARIABLES
 */

unsigned int FLAME_SENSOR[2];

/*
 * MOV FLAME SENSOR SIDE
 */
unsigned int FLAME_SIDE;

/*
 * CANDLE STATUS
 */
unsigned int CANDLE_STICK=0;
unsigned int CANDLE_FIRE=0;
unsigned int CANDLE_STAT=0;

unsigned int SP_FIRE_1B;
unsigned int SP_FIRE_1C;
unsigned int SP_FIRE_R3;
unsigned int SP_FIRE_ACTIVE=1;
unsigned int SP_FIRE_INACTIVE=0;

/*
 *  EXIT FLAG
 */
unsigned int EXIT_FLAG;
unsigned int EXIT_ACTIVE=1;
unsigned int EXIT_INACTIVE=0;

unsigned int FOLLOW_FLAG;
unsigned int FLAME=5;
unsigned int KANAN_BELAKANG=4;
unsigned int KIRI_BELAKANG=3;
unsigned int KANAN=2;
unsigned int KIRI=1;
unsigned int KOSONG=0;

unsigned int FOLLOW_BREAK;
unsigned int FOLLOW_CALC;


/*
 *  ROOM 2 FLAG
 */
unsigned int ROOM1_FLAG;
unsigned int ROOM1FLAG_ACTIVE=1;
unsigned int ROOM1FLAG_INACTIVE=0;

/*
 *  ROOM 1BC FLAG
 */
unsigned int ROOM1BC_FLAG;
unsigned int ROOM1BCFLAG_ACTIVE=1;
unsigned int ROOM1BCFLAG_INACTIVE=0;

/*
 * ROOM 2B FLAG
 */
unsigned int ROOM2B_FLAG;
unsigned int ROOM2BFLAG_ACTIVE=1;
unsigned int ROOM2BFLAG_INACTIVE=0;

/*
 * ROOM 4 FLAG
 */
unsigned int ROOM4_FLAG;
unsigned int ROOM4FLAG_ACTIVE=1;
unsigned int ROOM4FLAG_INACTIVE=0;

/*
 * ROOM 4A FLAG
 */
unsigned int ROOM4A_FLAG;
unsigned int ROOM4AFLAG_ACTIVE=1;
unsigned int ROOM4AFLAG_INACTIVE=0;

/*
 * ROOM 4B FLAG
 */
unsigned int ROOM4B_FLAG;
unsigned int ROOM4BFLAG_ACTIVE=1;
unsigned int ROOM4BFLAG_INACTIVE=0;

/*
 * ROOM 4B_EXIT FLAG
 */
unsigned int ROOM4B_EXIT_FLAG;
unsigned int ROOM4BFLAG_EXIT_ACTIVE=1;
unsigned int ROOM4BFLAG_EXIT_INACTIVE=0;

/*
 * ROOM1A SPECIAL EXIT FLAG
 */
unsigned int ROOM1A_SP_EXIT_FLAG;
unsigned int ROOM1A_SP_EXIT_FLAG_ACTIVE=1;
unsigned int ROOM1A_SP_EXIT_FLAG_INACTIVE=0;

/*
 * ROOM4A CAT AVOIDER
 */
unsigned int ROOM4A_CAT_AVOIDER;
unsigned int ROOM4A_CAT_AVOIDER_ACTIVE = 1;
unsigned int ROOM4A_CAT_AVOIDER_INACTIVE = 0;


/*
 * SPECIAL ROUTE FOR RETURN TRIP R2 TO R4A
 * HOME: R4A
 * FIRE ROOM: R2
 * CAT CONFIG: A
 */
unsigned int R2TO4A_SP_ROUTE=0;
unsigned int R2TO4A_SP_ACTIVE=1;
unsigned int R2TO4A_SP_INACTIVE=0;

unsigned int R4ATO3_SP_ROUTE=0;
unsigned int R4ATO3_SP_ACTIVE=1;
unsigned int R4ATO3_SP_INACTIVE=0;


unsigned int SP_ROUTE_ACTIVE=1;
unsigned int SP_ROUTE_INACTIVE=0;

/*
 *  SPECIAL ROUTE FOR RETURN TRIP R4A TO R2
 *  HOME: R2
 *  FIRE ROOM: R4A
 *  CAT CONFIG: A
 */
unsigned int R4ATO2_SP_ROUTE=0;

/*
 *  SPECIAL ROUTE FOR RETURN TRIP R4A TO R1
 *  HOME: R1
 *  FIRE ROOM: R4A
 *  CAT CONFIG: B
 */
unsigned int R4ATO1_SP_ROUTE=0;


/*
 * CAT SHIFT ALGORITHM FLAG
 */
unsigned int SHIFT_ALGORITHM_FLAG;
unsigned int SHIFT_ALGORITHM_ACTIVE=1;
unsigned int SHIFT_ALGORITHM_INACTIVE=0;


/*
 *  DEFLECT WALL OVERFLOW COUNTER
 */

int RIGHT_OVERFLOW_COUNTER=0;
int LEFT_OVERFLOW_COUNTER=0;


/*
 *  BW TURNAROUND NAVIGATION
 */
unsigned int TURN_LEFT  = 1;
unsigned int TURN_RIGHT = 2;


/*
 * BW FIRE SCAN DIRECTION FLAG
 */
unsigned int FIRESCAN_DIRECTION=0;
#define SCAN_LEFT 1
#define SCAN_RIGHT  2
#define NO_WALL_PARAM 3

/*
 * BW FIREFIGHT SUCCESS TURN AROUND
 */
unsigned int BW_TurnAround=0;
#define INACTIVE 0
#define ACTIVE   1

/*
 * BW FOWARD REVERSE FLAG
 */
unsigned int REVERSE_FLAG;
unsigned int REVERSEFLAG_ACTIVE=1;
unsigned int REVERSEFLAG_INACTIVE=0;

int cnt=0;
int FRONT, MIDDLE, REAR;
int BACA[3]={0,0,0};
int KONSTANTA[2]={0,0};
int VALUE;

//=============================================================================================//
//					CAUTION! THESE VARIABLES NEEDS TO BE CALIBRATED CORRECTLY                  //
//=============================================================================================//
/*
 *  COMPASS ARENA FLAG
 */
unsigned int CMPS_ACTIVE	=1;
unsigned int CMPS_INACTIVE	=0;
unsigned int ARENA_FLAG		=0;
unsigned int TRESH_UPPER	=1;
unsigned int TRESH_LOWER	=2;
unsigned int TRESH_FLAG		=0;

unsigned int NORTH_THRESHOLD_UPPER=178;
unsigned int NORTH_THRESHOLD_LOWER=152;
unsigned int NORTH_THRESHOLD_MIDDLE=(178+152)/2;
unsigned int WEST_THRESHOLD_UPPER=248;
unsigned int WEST_THRESHOLD_LOWER=222;
unsigned int WEST_THRESHOLD_MIDDLE=(248+222)/2;
unsigned int SOUTH_THRESHOLD_UPPER=358;
unsigned int SOUTH_THRESHOLD_LOWER=328;
unsigned int SOUTH_THRESHOLD_MIDDLE=(358+332)/2;
unsigned int EAST_THRESHOLD_UPPER=113;
unsigned int EAST_THRESHOLD_LOWER=87;
unsigned int EAST_THRESHOLD_MIDDLE= (113+87)/2;

/*								 */
// CMPS DATA TEST ALL 8 DIRECTION//
/*								 */
/* 1 */
////DI GOR	RUANG 1 di kanan
//unsigned int R4AB_THRESHOLD_UPPER=64;
//unsigned int R4AB_THRESHOLD_LOWER=180;
//unsigned int R4AB_THRESHOLD_MIDDLE=(125+241)/2;
//
//unsigned int R4A_THRESHOLD_UPPER=100;	//kiri 4A
//unsigned int R4A_THRESHOLD_LOWER=141;	//kanan 4A
//unsigned int R4B_THRESHOLD_LOWER=221;	//kiri 4B
//unsigned int R4B_THRESHOLD_UPPER=33;	//kanan 4B
////unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
//unsigned int R4A_THRESHOLD_MIDDLE=124;
//unsigned int R4B_THRESHOLD_MIDDLE=314;
//unsigned int START_MIDDLE=318;
//unsigned int R1BC_THRESHOLD_MIDDLE=56;

/* 2 */
//DI GOR	RUANG 1 di kanan selatan
unsigned int R4AB_THRESHOLD_UPPER=101;
unsigned int R4AB_THRESHOLD_LOWER=258;
unsigned int R4AB_THRESHOLD_MIDDLE=(125+241)/2;

unsigned int R4A_THRESHOLD_UPPER=128;	//kiri 4A
unsigned int R4A_THRESHOLD_LOWER=194;	//kanan 4A
unsigned int R4B_THRESHOLD_LOWER=310;	//kiri 4B
unsigned int R4B_THRESHOLD_UPPER=67;	//kanan 4B
//unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
unsigned int R4A_THRESHOLD_MIDDLE=153;
unsigned int R4B_THRESHOLD_MIDDLE=15;
unsigned int START_MIDDLE=17;
unsigned int R1BC_THRESHOLD_MIDDLE=97;

///* 3 */
////DI GOR	RUANG 1 di selatan
//unsigned int R4AB_THRESHOLD_UPPER=122;
//unsigned int R4AB_THRESHOLD_LOWER=340;
//unsigned int R4AB_THRESHOLD_MIDDLE=(125+241)/2;
//
//unsigned int R4A_THRESHOLD_UPPER=146;	//kiri 4A
//unsigned int R4A_THRESHOLD_LOWER=249;	//kanan 4A
//unsigned int R4B_THRESHOLD_LOWER=5;	//kiri 4B
//unsigned int R4B_THRESHOLD_UPPER=83;	//kanan 4B
////unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
//unsigned int R4A_THRESHOLD_MIDDLE=184;
//unsigned int R4B_THRESHOLD_MIDDLE=50;
//unsigned int START_MIDDLE=56;
//unsigned int R1BC_THRESHOLD_MIDDLE=120;

///* 4 */
////DI GOR	RUANG 1 di kiri selatan
//unsigned int R4AB_THRESHOLD_UPPER=155;
//unsigned int R4AB_THRESHOLD_LOWER=18;
//unsigned int R4AB_THRESHOLD_MIDDLE=(125+241)/2;
//
//unsigned int R4A_THRESHOLD_UPPER=190;	//kiri 4A
//unsigned int R4A_THRESHOLD_LOWER=332;	//kanan 4A
//unsigned int R4B_THRESHOLD_LOWER=50;	//kiri 4B
//unsigned int R4B_THRESHOLD_UPPER=118;	//kanan 4B
////unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
//unsigned int R4A_THRESHOLD_MIDDLE=253;
//unsigned int R4B_THRESHOLD_MIDDLE=91;
//unsigned int START_MIDDLE=97;
//unsigned int R1BC_THRESHOLD_MIDDLE=150;

///* 5 */
////DI GOR	RUANG 1 di kiri
//unsigned int R4AB_THRESHOLD_UPPER=190;
//unsigned int R4AB_THRESHOLD_LOWER=62;
//unsigned int R4AB_THRESHOLD_MIDDLE=(125+241)/2;
//
//unsigned int R4A_THRESHOLD_UPPER=240;	//kiri 4A
//unsigned int R4A_THRESHOLD_LOWER=30;	//kanan 4A
//unsigned int R4B_THRESHOLD_LOWER=81;	//kiri 4B
//unsigned int R4B_THRESHOLD_UPPER=150;	//kanan 4B
////unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
//unsigned int R4A_THRESHOLD_MIDDLE=330;
//unsigned int R4B_THRESHOLD_MIDDLE=125;
//unsigned int START_MIDDLE=124;
//unsigned int R1BC_THRESHOLD_MIDDLE=191;

///* 6 */
////DI GOR	RUANG 1 di kiri utara
//unsigned int R4AB_THRESHOLD_UPPER=261;
//unsigned int R4AB_THRESHOLD_LOWER=95;
//unsigned int R4AB_THRESHOLD_MIDDLE=(125+241)/2;
//
//unsigned int R4A_THRESHOLD_UPPER=327;	//kiri 4A
//unsigned int R4A_THRESHOLD_LOWER=66;	//kanan 4A
//unsigned int R4B_THRESHOLD_LOWER=118;	//kiri 4B
//unsigned int R4B_THRESHOLD_UPPER=179;	//kanan 4B
////unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
//unsigned int R4A_THRESHOLD_MIDDLE=28;
//unsigned int R4B_THRESHOLD_MIDDLE=152;
//unsigned int START_MIDDLE=152;
//unsigned int R1BC_THRESHOLD_MIDDLE=255;

///* TRIAL POLINEMA */
////DI GOR RUANG 1 di kanan selatan
//unsigned int R4AB_THRESHOLD_UPPER=128;
//unsigned int R4AB_THRESHOLD_LOWER=347;
//unsigned int R4AB_THRESHOLD_MIDDLE=(125+241)/2;
//
//unsigned int R4A_THRESHOLD_UPPER=155;	//kiri 4A
//unsigned int R4A_THRESHOLD_LOWER=262;	//kanan 4A
//unsigned int R4B_THRESHOLD_LOWER=21;	//kiri 4B
//unsigned int R4B_THRESHOLD_UPPER=95;	//kanan 4B
////unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
//unsigned int R4A_THRESHOLD_MIDDLE=187;
//unsigned int R4B_THRESHOLD_MIDDLE=63;
//unsigned int START_MIDDLE=62;
//unsigned int R1BC_THRESHOLD_MIDDLE=120;

///* DEMO ROBOT LAP BASKET */
////DI LAP BASKET	RUANG 1 di kiri utara (DEMO)
//unsigned int R4AB_THRESHOLD_UPPER=262;
//unsigned int R4AB_THRESHOLD_LOWER=95;
//unsigned int R4AB_THRESHOLD_MIDDLE=(125+241)/2;
//
//unsigned int R4A_THRESHOLD_UPPER=330;	//kiri 4A
//unsigned int R4A_THRESHOLD_LOWER=77;	//kanan 4A
//unsigned int R4B_THRESHOLD_LOWER=125;	//kiri 4B
//unsigned int R4B_THRESHOLD_UPPER=204;	//kanan 4B
////unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
//unsigned int R4A_THRESHOLD_MIDDLE=35;
//unsigned int R4B_THRESHOLD_MIDDLE=162;
//unsigned int START_MIDDLE=160;
//unsigned int R1BC_THRESHOLD_MIDDLE=275;

//==OLD DATA==//
//unsigned int NORTH_THRESHOLD_UPPER=175;
//unsigned int NORTH_THRESHOLD_LOWER=145;
//unsigned int NORTH_THRESHOLD_MIDDLE=(175+145)/2;
//unsigned int WEST_THRESHOLD_UPPER=245;
//unsigned int WEST_THRESHOLD_LOWER=215;
//unsigned int WEST_THRESHOLD_MIDDLE=(245+215)/2;
//unsigned int SOUTH_THRESHOLD_UPPER=340;
//unsigned int SOUTH_THRESHOLD_LOWER=310;
//unsigned int SOUTH_THRESHOLD_MIDDLE=(340+310)/2;
//unsigned int EAST_THRESHOLD_UPPER=120;
//unsigned int EAST_THRESHOLD_LOWER=90;
//unsigned int EAST_THRESHOLD_MIDDLE= (120+90)/2;

//EXIT ROOM CORRECTION

unsigned int R1B_THRESHOLD=175;
unsigned int R1C_THRESHOLD=175;
unsigned int R1A_R4A_THRESHOLD_MIDDLE=193;
unsigned int R1A_THRESHOLD=175;
unsigned int R2_THRESHOLD=175;
unsigned int R3_R4B_THRESHOLD_MIDDLE=320;
unsigned int R4A_THRESHOLD=175;
unsigned int R4B_THRESHOLD=175;


//=============================================================================================//

/*
 * 	FIREFIGHT FLAG FOR ROOM4AB
 */
unsigned int ROOM4AB_FLAG=0;
unsigned int ROOM4AB_ACTIVE=1;
unsigned int ROOM4AB_INACTIVE=0;

unsigned int FIREROOM_R4AB_FLAG=0;
unsigned int FIREROOM_R4AB_ACTIVE=1;
unsigned int FIREROOM_R4AB_INACTIVE=0;

unsigned int FIREROOM_R1A_FLAG=0;
unsigned int FIREROOM_R1A_ACTIVE=1;
unsigned int FIREROOM_R1A_INACTIVE=0;
unsigned int ROOM1A_SP_MIDDLE_FLAG=2; // CEK ulang R1A ditengah ruang
/*
 *  BW DYNAMIXEL INVERSE KINEMATICS
 */
//const unsigned int FRONT_LEFT_DX_COXA =	1;
//const unsigned int FRONT_LEFT_DX_FEMUR=	2;
//const unsigned int FRONT_LEFT_DX_TIBIA=	3;
//
//const unsigned int MIDDLE_LEFT_DX_COXA =	4;
//const unsigned int MIDDLE_LEFT_DX_FEMUR=	5;
//const unsigned int MIDDLE_LEFT_DX_TIBIA=	6;
//
//const unsigned int REAR_LEFT_DX_COXA 	=7;
//const unsigned int REAR_LEFT_DX_FEMUR	=8;
//const unsigned int REAR_LEFT_DX_TIBIA	=9;
//
//const unsigned int FRONT_RIGHT_DX_COXA =	10;
//const unsigned int FRONT_RIGHT_DX_FEMUR=	11;
//const unsigned int FRONT_RIGHT_DX_TIBIA=	12;
//
//const unsigned int MIDDLE_RIGHT_DX_COXA =	13;
//const unsigned int MIDDLE_RIGHT_DX_FEMUR=	14;
//const unsigned int MIDDLE_RIGHT_DX_TIBIA=	15;
//
//const unsigned int REAR_RIGHT_DX_COXA 	=16;
//const unsigned int REAR_RIGHT_DX_FEMUR	=17;
//const unsigned int REAR_RIGHT_DX_TIBIA	=18;

int DynamxCorrection[18]=
							{

									0,0,0, //Front Left Leg
									0,0,0, //Middle Left Leg
									0,0,0, //Rear Left Leg

									0,0,0, //Front Right Leg
									0,0,0, //Middle Right Leg
									0,0,0, //Rear Right Leg

////									0,0,-2, //Front Left Leg
//									0,0,-2, //Front Left Leg
//									0,0,0, //Middle Left Leg
////									0,-2,-1, //Rear Left Leg
//									0,0,0, //Rear Left Leg
//
//									0,0,5, //Front Right Leg
////									0,-6,-1, //Middle Right Leg
//									0,0,1, //Middle Right Leg
//									0,0,0, //Rear Right Leg

							};

//									0,0,-2, //Front Left Leg
//									0,0,0, //Middle Left Leg
//									0,-2,-1, //Rear Left Leg
//
//									0,0,6, //Front Right Leg
//									0,-6,-1, //Middle Right Leg
//									0,0,0, //Rear Right Leg

//float Dynamx_LinkFemur= 5.4;
//float Dynamx_LinkTibia= 7.4;
float Dynamx_LinkFemur= 4;
float Dynamx_LinkTibia= 8;

///*
// *  SPEED TRIGONOMETRY
// */
////float PIby2 = PI / 2;
//
////Sin Lookup table
//const float SIN_TABLE[181]={
//  0.000000, 0.008727, 0.017452, 0.026177, 0.034899, 0.043619, 0.052336, 0.061049, 0.069756, 0.078459, 0.087156, 0.095846, 0.104528,
//  0.113203, 0.121869, 0.130526, 0.139173, 0.147809, 0.156434, 0.165048, 0.173648, 0.182236, 0.190809, 0.199368, 0.207912, 0.216440,
//  0.224951, 0.233445, 0.241922, 0.250380, 0.258819, 0.267238, 0.275637, 0.284015, 0.292372, 0.300706, 0.309017, 0.317305, 0.325568,
//  0.333807, 0.342020, 0.350207, 0.358368, 0.366501, 0.374607, 0.382683, 0.390731, 0.398749, 0.406737, 0.414693, 0.422618, 0.430511,
//  0.438371, 0.446198, 0.453990, 0.461749, 0.469472, 0.477159, 0.484810, 0.492424, 0.500000, 0.507538, 0.515038, 0.522499, 0.529919,
//  0.537300, 0.544639, 0.551937, 0.559193, 0.566406, 0.573576, 0.580703, 0.587785, 0.594823, 0.601815, 0.608761, 0.615661, 0.622515,
//  0.629320, 0.636078, 0.642788, 0.649448, 0.656059, 0.662620, 0.669131, 0.675590, 0.681998, 0.688355, 0.694658, 0.700909, 0.707107,
//  0.713250, 0.719340, 0.725374, 0.731354, 0.737277, 0.743145, 0.748956, 0.754710, 0.760406, 0.766044, 0.771625, 0.777146, 0.782608,
//  0.788011, 0.793353, 0.798636, 0.803857, 0.809017, 0.814116, 0.819152, 0.824126, 0.829038, 0.833886, 0.838671, 0.843391, 0.848048,
//  0.852640, 0.857167, 0.861629, 0.866025, 0.870356, 0.874620, 0.878817, 0.882948, 0.887011, 0.891007, 0.894934, 0.898794, 0.902585,
//  0.906308, 0.909961, 0.913545, 0.917060, 0.920505, 0.923880, 0.927184, 0.930418, 0.933580, 0.936672, 0.939693, 0.942641, 0.945519,
//  0.948324, 0.951057, 0.953717, 0.956305, 0.958820, 0.961262, 0.963630, 0.965926, 0.968148, 0.970296, 0.972370, 0.974370, 0.976296,
//  0.978148, 0.979925, 0.981627, 0.983255, 0.984808, 0.986286, 0.987688, 0.989016, 0.990268, 0.991445, 0.992546, 0.993572, 0.994522,
//  0.995396, 0.996195, 0.996917, 0.997564, 0.998135, 0.998630, 0.999048, 0.999391, 0.999657, 0.999848, 0.999962, 1.000000
//};
//
///*
//  acos lookup table is split into three parts, which has a higher accuracy nearer acos(1).
//    - 0 to 0.9 is done in steps of 0.0079 rads. (1/127)
//    - 0.9 to 0.99 is done in steps of 0.0008 rads. (0.01/127)
//    - 0.99 to 1 is done in steps of 0.0002 rads. (0.01/64)
//*/
//const int ACOS_TABLE[278] = {
//  255, 254, 252, 251, 250, 249, 247, 246, 245, 243, 242, 241, 240, 238, 237, 236, 234, 233, 232, 231, 229, 228, 227, 225, 224, 223,
//  221, 220, 219, 217, 216, 215, 214, 212, 211, 210, 208, 207, 206, 204, 203, 201, 200, 199, 197, 196, 195, 193, 192, 190, 189, 188,
//  186, 185, 183, 182, 181, 179, 178, 176, 175, 173, 172, 170, 169, 167, 166, 164, 163, 161, 160, 158, 157, 155, 154, 152, 150, 149,
//  147, 146, 144, 142, 141, 139, 137, 135, 134, 132, 130, 128, 127, 125, 123, 121, 119, 117, 115, 113, 111, 109, 107, 105, 103, 101,
//  98, 96, 94, 92, 89, 87, 84, 81, 79, 76, 73, 73, 73, 72, 72, 72, 71, 71, 71, 70, 70, 70, 70, 69, 69, 69, 68, 68, 68, 67, 67, 67,
//  66, 66, 66, 65, 65, 65, 64, 64, 64, 63, 63, 63, 62, 62, 62, 61, 61, 61, 60, 60, 59, 59, 59, 58, 58, 58, 57, 57, 57, 56, 56, 55,
//  55, 55, 54, 54, 53, 53, 53, 52, 52, 51, 51, 51, 50, 50, 49, 49, 48, 48, 47, 47, 47, 46, 46, 45, 45, 44, 44, 43, 43, 42, 42, 41,
//  41, 40, 40, 39, 39, 38, 37, 37, 36, 36, 35, 34, 34, 33, 33, 32, 31, 31, 30, 29, 28, 28, 27, 26, 25, 24, 23, 23, 23, 23, 22, 22,
//  22, 22, 21, 21, 21, 21, 20, 20, 20, 19, 19, 19, 19, 18, 18, 18, 17, 17, 17, 17, 16, 16, 16, 15, 15, 15, 14, 14, 13, 13, 13, 12,
//  12, 11, 11, 10, 10, 9, 9, 8, 7, 6, 6, 5, 3, 0
//};
//
////const uint8_t Dynamixel_Pin[] = {
////  FRONT_LEFT_DX_COXA,	MIDDLE_LEFT_DX_COXA,	REAR_LEFT_DX_COXA,	FRONT_RIGHT_DX_COXA,	MIDDLE_RIGHT_DX_COXA,	REAR_RIGHT_DX_COXA,
////  FRONT_LEFT_DX_FEMUR,	MIDDLE_LEFT_DX_FEMUR,	REAR_LEFT_DX_FEMUR,	FRONT_RIGHT_DX_FEMUR,	MIDDLE_RIGHT_DX_FEMUR,	REAR_RIGHT_DX_FEMUR,
////  FRONT_LEFT_DX_TIBIA,	MIDDLE_LEFT_DX_TIBIA,	REAR_LEFT_DX_TIBIA,	FRONT_RIGHT_DX_TIBIA,	MIDDLE_RIGHT_DX_TIBIA,	REAR_RIGHT_DX_TIBIA
////};
//
////#define CNTLEGS 6
//
////static const short cFemurHornOffset1[];
////static const short cTibiaHornOffset1[];
////const short cCoxaMin1[];
////const short cCoxaMax1[];
////const short cFemurMin1[];
////const short cFemurMax1[];
////const short cTibiaMin1[];
////const short cTibiaMax1[];
////const bool cCoxaInv[];
////bool cFemurInv[];
////const bool cTibiaInv[];
////const uint8_t cCoxaLength[];
////const uint8_t cFemurLength[];
////const uint8_t cTibiaLength[];
////const short cOffsetX[];
////const short cOffsetZ[];
////const short cCoxaAngle1[];
////const short cCoxaInitAngle1[];
////
////const short cInitPosX[];
////const short cInitPosY[];
////const short cInitPosZ[];
//
//
///*
// *  BW_HEX_CFG
// *
// */
//
//
////const uint8_t g_abHexIntXZ[]= {cHexInitXZ, 144};
////const uint8_t g_abHexMaxBodyY[]= { 20, MAX_BODY_Y};
//
//const unsigned char g_abHexIntXZ[]= {cHexInitXZ, 144};
//const unsigned char g_abHexMaxBodyY[]= { 20, MAX_BODY_Y};
//
////==================================// END OF BW_HEX_CFG
//
//
//
///*
// * 	BW PHOENIX
// *
// */
////============BW PHOENIX============//
//
//////#define PROGMEM
////#define pgm_read_byte(x)        (*((char *)x))
//////  #define pgm_read_word(x)        (*((short *)(x & 0xfffffffe)))
////#define pgm_read_word(x)        ( ((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x)))
////#define pgm_read_byte_near(x)   (*((char *)x))
////#define pgm_read_byte_far(x)    (*((char *)x))
//////  #define pgm_read_word_near(x)   (*((short *)(x & 0xfffffffe))
//////  #define pgm_read_word_far(x)    (*((short *)(x & 0xfffffffe)))
////#define pgm_read_word_near(x)   ( ((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x)))
////#define pgm_read_word_far(x)    ( ((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x))))
////#define PSTR(x)  x
//
////=============================================================================
////[CONSTANTS]
////=============================================================================
////#define BUTTON_DOWN 0
////#define BUTTON_UP   1
//
////#define c1DEC       10
////#define c2DEC       100
////#define c4DEC       10000
////#define c6DEC       1000000
//
//float c1DEC=10;
//float c2DEC=100;
//float c4DEC=10000;
//float c6DEC=1000000;
//
////enum { cRR=0, cRM, cRF, cLR, cLM, cLF, CNTLEGS};
//
////#define WTIMERTICSPERMSMUL      64  // BAP28 is 16mhz need a multiplyer and divider to make the conversion with /8192
////#define WTIMERTICSPERMSDIV      125 //
////#define USEINT_TIMERAV
//
//
//// BUGBUG: to make Dynamic first pass simpl make it a variable.
////uint8_t    NUM_GAITS = 6;	//sizeof(APG)/sizeof(APG[0]);
////#define SmDiv        4  //"Smooth division" factor for the smooth control function, a value of 3 to 5 is most suitable
//
//
////-----------------------------------------------------------------------------
//// Define Global variables
////-----------------------------------------------------------------------------
//
////extern boolean          g_fDebugOutput;
////extern boolean          g_fEnableServos;      // Hack to allow me to turn servo processing off...
////extern boolean          g_fRobotUpsideDown;    // Is the robot upside down?
//
//extern uint16_t GetLegsXZLength(void);
//extern void AdjustLegPositions(uint16_t XZLength1);
//extern void AdjustLegPositionsToBodyHeight();
//extern void ResetLegInitAngles(void);
//extern void RotateLegInitAngles (int iDeltaAngle);
//extern long GetCmdLineNum(uint8_t **ppszCmdLine);
//
//// debug handler...
////extern boolean g_fDBGHandleError;
//
////#ifdef OPT_BACKGROUND_PROCESS
////#define DoBackgroundProcess()   g_ServoDriver.BackgroundProcess()
////#else
////#define DoBackgroundProcess()
////#endif
//
////#ifdef DEBUG_IOPINS
////#define DebugToggle(pin)  {digitalWrite(pin, !digitalRead(pin));}
////#define DebugWrite(pin, state) {digitalWrite(pin, state);}
////#else
////#define DebugToggle(pin)  {;}
////#define DebugWrite(pin, state) {;}
////#endif
//
//
//
//
//
////typedef struct COORD3D
////{
////    int x,y,z;
////}
////COORD3D;
//
////struct movement
////{
////	float x;
////	float y;
////	float z;
////}
////BodyPos,BodyRot1,BodyRotOffset,TravelLength;
//
////[Single Leg Control]
//uint8_t          SelectedLeg;
//uint8_t          PrevSelectedLeg;
//
////[gait]
//uint8_t          GaitType;            //Gait type
//uint8_t          GaitStep;            //Actual current step in gait
//
//short       LegLiftHeight;
//
////[TIMING]
//uint8_t          InputTimeDelay; //Delay that depends on the input to get the "sneaking" effect
//uint16_t          SpeedControl;   //Adjustible Delay
//uint8_t          ForceGaitStepCnt;          // new to allow us to force a step even when not moving
//
//uint16_t	BalanceMode;
//
//static short   g_BodyYOffset;
//static short   g_BodyYShift;
//static uint8_t    ControlMode;
//static uint8_t    HeightSpeedMode;
//
//////[CONSTANTS]
////enum {
////  WALKMODE=0, TRANSLATEMODE, ROTATEMODE,
////#ifdef OPT_SINGLELEG
////  SINGLELEGMODE,
////#endif
////#ifdef OPT_GPPLAYER
////  GPPLAYERMODE,
////#endif
////  MODECNT};
////enum {
////  NORM_NORM=0, NORM_LONG, HIGH_NORM, HIGH_LONG};
//
//uint8_t          SelectedLeg;
//uint8_t          PrevSelectedLeg;
////==============================================================================
//// class ControlState: This is the main structure of data that the Control
////      manipulates and is used by the main Phoenix Code to make it do what is
////      requested.
////==============================================================================
////typedef struct _InControlState {
//////  boolean       fRobotOn;            //Switch to turn on Phoenix
//////  boolean       fPrev_RobotOn;       //Previous loop state
////  //Body position
////  COORD3D       BodyPos;
////  COORD3D       BodyRotOffset;      // Body rotation offset;
////
////  //Body Inverse Kinematics
////  COORD3D       BodyRot1;            // X -Pitch, Y-Rotation, Z-Roll
////
////  //[gait]
////  uint8_t          GaitType;            //Gait type
////  uint8_t          GaitStep;            //Actual current step in gait
////  PHOENIXGAIT   gaitCur;             // Definition of the current gait
////
////  short       LegLiftHeight;       //Current Travel height
////  COORD3D       TravelLength;        // X-Z or Length, Y is rotation.
////
//////#ifdef cTurretRotPin
//////  // Turret information
//////  int           TurretRotAngle1;      // Rotation of turrent in 10ths of degree
//////  int           TurretTiltAngle1;    // the tile for the turret
//////#endif
////
////  //[Single Leg Control]
//////#ifdef OPT_SINGLELEG
////  uint8_t          SelectedLeg;
////  uint8_t          PrevSelectedLeg;
////  COORD3D       SLLeg;               //
//////  boolean       fSLHold;             //Single leg control mode
//////#endif
////
////  //[Balance]
//////  boolean       BalanceMode;
////
////  //[TIMING]
////  uint8_t          InputTimeDelay; //Delay that depends on the input to get the "sneaking" effect
////  uint16_t          SpeedControl;   //Adjustible Delay
////  uint8_t          ForceGaitStepCnt;          // new to allow us to force a step even when not moving
////
////#ifdef OPT_DYNAMIC_ADJUST_LEGS
////  short         aCoxaInitAngle1[CNTLEGS];
////#endif
////
////  //
////
////}
////INCONTROLSTATE;
//
//
////==============================================================================
////==============================================================================
//// Define the class(s) for Servo Drivers.
////==============================================================================
////==============================================================================
////class ServoDriver {
////public:
////  void Init(void);
////
////  uint16_t GetBatteryVoltage(void);
////
////#ifdef OPT_GPPLAYER
////  inline boolean  FIsGPEnabled(void) {
////    return _fGPEnabled;
////  };
////  boolean         FIsGPSeqDefined(uint8_t iSeq);
////  inline boolean  FIsGPSeqActive(void) {
////    return _fGPActive;
////  };
////  void            GPStartSeq(uint8_t iSeq);  // 0xff - says to abort...
////  void            GPPlayer(void);
////  uint8_t         GPNumSteps(void);          // How many steps does the current sequence have
////  uint8_t         GPCurStep(void);           // Return which step currently on...
////  void            GPSetSpeedMultiplyer(short sm) ;      // Set the Speed multiplier (100 is default)
////#endif
////  void            BeginServoUpdate(void);    // Start the update
////#ifdef c4DOF
////  void            OutputServoInfoForLeg(uint8_t LegIndex, short sCoxaAngle1, short sFemurAngle1, short sTibiaAngle1, short sTarsAngle1);
////#else
////  void            OutputServoInfoForLeg(uint8_t LegIndex, short sCoxaAngle1, short sFemurAngle1, short sTibiaAngle1);
////#endif
////#ifdef cTurretRotPin
////  void            OutputServoInfoForTurret(short sRotateAngle1, short sTiltAngle1);
////#endif
////  void            CommitServoDriver(uint16_t wMoveTime);
////  void            FreeServos(void);
////
////  void            IdleTime(void);        // called when the main loop when the robot is not on
////
////  // Allow for background process to happen...
////#ifdef OPT_BACKGROUND_PROCESS
////  void            BackgroundProcess(void);
////#endif
////
////#ifdef OPT_TERMINAL_MONITOR
////  void            ShowTerminalCommandList(void);
////  boolean         ProcessTerminalCommand(uint8_t *psz, uint8_t bLen);
////#endif
////
////private:
////
////#ifdef OPT_GPPLAYER
////  boolean _fGPEnabled;     // IS GP defined for this servo driver?
////  boolean _fGPActive;      // Is a sequence currently active - May change later when we integrate in sequence timing adjustment code
////  uint8_t    _iSeq;        // current sequence we are running
////  short    _sGPSM;        // Speed multiplier +-200
////#endif
////
////}
////;
//
////==============================================================================
////==============================================================================
//// Define global class objects
////==============================================================================
////==============================================================================
////extern ServoDriver      g_ServoDriver;           // our global servo driver class
////extern InputController  g_InputController;       // Our Input controller
////extern INCONTROLSTATE   g_InControlState;        // State information that controller changes
//
////==================================// END OF BW PHOENIX
//
//
///*
// * BW_PHOENIX_CODE
// *
// */
//
//const uint8_t GetACos[] = {
//  255,254,252,251,250,249,247,246,245,243,242,241,240,238,237,236,234,233,232,231,229,228,227,225,
//  224,223,221,220,219,217,216,215,214,212,211,210,208,207,206,204,203,201,200,199,197,196,195,193,
//  192,190,189,188,186,185,183,182,181,179,178,176,175,173,172,170,169,167,166,164,163,161,160,158,
//  157,155,154,152,150,149,147,146,144,142,141,139,137,135,134,132,130,128,127,125,123,121,119,117,
//  115,113,111,109,107,105,103,101,98,96,94,92,89,87,84,81,79,76,73,73,73,72,72,72,71,71,71,70,70,
//  70,70,69,69,69,68,68,68,67,67,67,66,66,66,65,65,65,64,64,64,63,63,63,62,62,62,61,61,61,60,60,59,
//  59,59,58,58,58,57,57,57,56,56,55,55,55,54,54,53,53,53,52,52,51,51,51,50,50,49,49,48,48,47,47,47,
//  46,46,45,45,44,44,43,43,42,42,41,41,40,40,39,39,38,37,37,36,36,35,34,34,33,33,32,31,31,30,29,28,
//  28,27,26,25,24,23,23,23,23,22,22,22,22,21,21,21,21,20,20,20,19,19,19,19,18,18,18,17,17,17,17,16,
//  16,16,15,15,15,14,14,13,13,13,12,12,11,11,10,10,9,9,8,7,6,6,5,3,0 };//
//
//const uint16_t GetSin[] = {
//  0, 87, 174, 261, 348, 436, 523, 610, 697, 784, 871, 958, 1045, 1132, 1218, 1305, 1391, 1478, 1564,
//  1650, 1736, 1822, 1908, 1993, 2079, 2164, 2249, 2334, 2419, 2503, 2588, 2672, 2756, 2840, 2923, 3007,
//  3090, 3173, 3255, 3338, 3420, 3502, 3583, 3665, 3746, 3826, 3907, 3987, 4067, 4146, 4226, 4305, 4383,
//  4461, 4539, 4617, 4694, 4771, 4848, 4924, 4999, 5075, 5150, 5224, 5299, 5372, 5446, 5519, 5591, 5664,
//  5735, 5807, 5877, 5948, 6018, 6087, 6156, 6225, 6293, 6360, 6427, 6494, 6560, 6626, 6691, 6755, 6819,
//  6883, 6946, 7009, 7071, 7132, 7193, 7253, 7313, 7372, 7431, 7489, 7547, 7604, 7660, 7716, 7771, 7826,
//  7880, 7933, 7986, 8038, 8090, 8141, 8191, 8241, 8290, 8338, 8386, 8433, 8480, 8526, 8571, 8616, 8660,
//  8703, 8746, 8788, 8829, 8870, 8910, 8949, 8987, 9025, 9063, 9099, 9135, 9170, 9205, 9238, 9271, 9304,
//  9335, 9366, 9396, 9426, 9455, 9483, 9510, 9537, 9563, 9588, 9612, 9636, 9659, 9681, 9702, 9723, 9743,
//  9762, 9781, 9799, 9816, 9832, 9848, 9862, 9876, 9890, 9902, 9914, 9925, 9935, 9945, 9953, 9961, 9969,
//  9975, 9981, 9986, 9990, 9993, 9996, 9998, 9999, 10000 };//
//
//const short cCoxaMin1[]  = {
//  cRRCoxaMin1,  cRMCoxaMin1,  cRFCoxaMin1,  cLRCoxaMin1,  cLMCoxaMin1,  cLFCoxaMin1};
//const short cCoxaMax1[]  = {
//  cRRCoxaMax1,  cRMCoxaMax1,  cRFCoxaMax1,  cLRCoxaMax1,  cLMCoxaMax1,  cLFCoxaMax1};
//const short cFemurMin1[]  ={
//  cRRFemurMin1, cRMFemurMin1, cRFFemurMin1, cLRFemurMin1, cLMFemurMin1, cLFFemurMin1};
//const short cFemurMax1[]  ={
//  cRRFemurMax1, cRMFemurMax1, cRFFemurMax1, cLRFemurMax1, cLMFemurMax1, cLFFemurMax1};
//const short cTibiaMin1[]  ={
//  cRRTibiaMin1, cRMTibiaMin1, cRFTibiaMin1, cLRTibiaMin1, cLMTibiaMin1, cLFTibiaMin1};
//const short cTibiaMax1[]  = {
//  cRRTibiaMax1, cRMTibiaMax1, cRFTibiaMax1, cLRTibiaMax1, cLMTibiaMax1, cLFTibiaMax1};
//
//
//// Servo inverse direction
//const bool cCoxaInv[] = {cRRCoxaInv, cRMCoxaInv, cRFCoxaInv, cLRCoxaInv, cLMCoxaInv, cLFCoxaInv};
//bool cFemurInv[] = {cRRFemurInv, cRMFemurInv, cRFFemurInv, cLRFemurInv, cLMFemurInv, cLFFemurInv};
//const bool cTibiaInv[] = {cRRTibiaInv, cRMTibiaInv, cRFTibiaInv, cLRTibiaInv, cLMTibiaInv, cLFTibiaInv};
//
////Leg Lengths
//const uint8_t cCoxaLength[]  = {
//  cRRCoxaLength,  cRMCoxaLength,  cRFCoxaLength,  cLRCoxaLength,  cLMCoxaLength,  cLFCoxaLength};
//const uint8_t cFemurLength[]  = {
//  cRRFemurLength, cRMFemurLength, cRFFemurLength, cLRFemurLength, cLMFemurLength, cLFFemurLength};
//const uint8_t cTibiaLength[]  = {
//  cRRTibiaLength, cRMTibiaLength, cRFTibiaLength, cLRTibiaLength, cLMTibiaLength, cLFTibiaLength};
//
////Body Offsets [distance between the center of the body and the center of the coxa]
//const short cOffsetX[]  = {
//  cRROffsetX, cRMOffsetX, cRFOffsetX, cLROffsetX, cLMOffsetX, cLFOffsetX};
//const short cOffsetZ[]  = {
//  cRROffsetZ, cRMOffsetZ, cRFOffsetZ, cLROffsetZ, cLMOffsetZ, cLFOffsetZ};
//
////Default leg angle
//const short cCoxaAngle1[]  = {
//  cRRCoxaAngle1, cRMCoxaAngle1, cRFCoxaAngle1, cLRCoxaAngle1, cLMCoxaAngle1, cLFCoxaAngle1};
//
//#ifdef cRRInitCoxaAngle1    // We can set different angles for the legs than just where they servo horns are set...
//const short cCoxaInitAngle1[]  = {
//  cRRInitCoxaAngle1, cRMInitCoxaAngle1, cRFInitCoxaAngle1, cLRInitCoxaAngle1, cLMInitCoxaAngle1, cLFInitCoxaAngle1};
//#endif
//
////Start positions for the leg
//const short cInitPosX[]  = {
//  cRRInitPosX, cRMInitPosX, cRFInitPosX, cLRInitPosX, cLMInitPosX, cLFInitPosX};
//const short cInitPosY[]  = {
//  cRRInitPosY, cRMInitPosY, cRFInitPosY, cLRInitPosY, cLMInitPosY, cLFInitPosY};
//const short cInitPosZ[]  = {
//  cRRInitPosZ, cRMInitPosZ, cRFInitPosZ, cLRInitPosZ, cLMInitPosZ, cLFInitPosZ};
//
////====================================================================
////[ANGLES]
//short           CoxaAngle1[6];	//[CNTLEGS];    //Actual Angle of the horizontal hip, decimals = 1
//short           FemurAngle1[6];	//[CNTLEGS];   //Actual Angle of the vertical hip, decimals = 1
//short           TibiaAngle1[6];	//[CNTLEGS];   //Actual Angle of the knee, decimals = 1
//
////--------------------------------------------------------------------
////[POSITIONS SINGLE LEG CONTROL]
//
//short           LegPosX[6];	//[CNTLEGS];    //Actual X Posion of the Leg
//short           LegPosY[6];	//[CNTLEGS];    //Actual Y Posion of the Leg
//short           LegPosZ[6];	//[CNTLEGS];    //Actual Z Posion of the Leg
//
////--------------------------------------------------------------------
////[VARIABLES]
////uint8_t            Index;                    //Index universal used
////uint8_t            LegIndex;                //Index used for leg Index Number
//uint8_t            Index;                    //Index universal used
//uint8_t            LegIndex;                //Index used for leg Index Number
//
////GetSinCos / ArcCos
//short           AngleDeg1;        //Input Angle in degrees, decimals = 1
//short           sin4;             //Output Sinus of the given Angle, decimals = 4
//short           cos4;            //Output Cosinus of the given Angle, decimals = 4
//short           AngleRad4;        //Output Angle in radials, decimals = 4
//
////GetAtan2
//short           AtanX;            //Input X
//short           AtanY;            //Input Y
//short           Atan4;            //ArcTan2 output
//long            XYhyp2;            //Output presenting Hypotenuse of X and Y
//
////Body Inverse Kinematics
//short           PosX;            //Input position of the feet X
//short           PosZ;            //Input position of the feet Z
//short           PosY;            //Input position of the feet Y
//long            BodyFKPosX;        //Output Position X of feet with Rotation
//long            BodyFKPosY;        //Output Position Y of feet with Rotation
//long            BodyFKPosZ;        //Output Position Z of feet with Rotation
//
//
////Leg Inverse Kinematics
//long            IKFeetPosX;        //Input position of the Feet X
//long            IKFeetPosY;        //Input position of the Feet Y
//long            IKFeetPosZ;        //Input Position of the Feet Z
//bool         IKSolution;        //Output true if the solution is possible
//bool         IKSolutionWarning;    //Output true if the solution is NEARLY possible
//bool         IKSolutionError;    //Output true if the solution is NOT possible
//
//
////--------------------------------------------------------------------
////[TIMING]
//unsigned long   lTimerStart;    //Start time of the calculation cycles
//unsigned long   lTimerEnd;        //End time of the calculation cycles
////uint8_t            CycleTime;        //Total Cycle time
//uint8_t            CycleTime;        //Total Cycle time
//
////uint16_t            ServoMoveTime;        //Time for servo updates
////uint16_t            PrevServoMoveTime;    //Previous time for the servo updates
//uint16_t            ServoMoveTime;        //Time for servo updates
//uint16_t            PrevServoMoveTime;    //Previous time for the servo updates
//
////--------------------------------------------------------------------
////[Balance]
//long            TotalTransX;
//long            TotalTransZ;
//long            TotalTransY;
//long            TotalYBal1;
//long            TotalXBal1;
//long            TotalZBal1;
//
//
////[Single Leg Control]
////boolean         AllDown;
//
////[gait - State]
//// Note: Information about the current gait is now part of the g_InControlState...
////boolean         TravelRequest;          //Temp to check if the gait is in motion
//
//long            GaitPosX[6];	//[CNTLEGS];         //Array containing Relative X position corresponding to the Gait
//long            GaitPosY[6];	//[CNTLEGS];         //Array containing Relative Y position corresponding to the Gait
//long            GaitPosZ[6];	//[CNTLEGS];         //Array containing Relative Z position corresponding to the Gait
//long            GaitRotY[6];	//[CNTLEGS];         //Array containing Relative Y rotation corresponding to the Gait
//
////boolean           GaitLegInAir[CNTLEGS];     // True if leg is in the air
////uint8_t          GaitNextLeg;                // The next leg which will be lifted
//
//bool        fWalking;            //  True if the robot are walking
//uint8_t            bExtraCycle;          // Forcing some extra timed cycles for avoiding "end of gait bug"
//
//
//short int LegStep;
//
////boolean        g_fRobotUpsideDown;    // Is the robot upside down?
////boolean        fRobotUpsideDownPrev;
//
//
//PHOENIXGAIT APG[] = {
//    {DEFAULT_SLOW_GAIT, 12, 3, 2, 2, 8, 3, {7, 11, 3, 1, 5, 9}},        // Ripple 12
//    {DEFAULT_SLOW_GAIT, 8, 3, 2, 2, 4, 3, {1, 5, 1, 5, 1, 5}},           //Tripod 8 steps
//    {DEFAULT_GAIT_SPEED, 12, 3, 2, 2, 8, 3, {5, 10, 3, 11, 4, 9}},      //Triple Tripod 12 step
//    {DEFAULT_GAIT_SPEED, 16, 5, 3, 4, 10, 1, {6, 13, 4, 14, 5, 12}},    // Triple Tripod 16 steps, use 5 lifted positions
//    {DEFAULT_SLOW_GAIT, 24, 3, 2, 2, 20, 3, {13, 17, 21, 1, 5, 9}},     //Wave 24 steps
//    {DEFAULT_GAIT_SPEED, 6, 2, 1, 2, 4, 1, {1, 4, 1, 4, 1, 4}}          //Tripod 6 steps
//};
//
////--------------------------------------------------------------------
////uint8_t NUM_GAITS = sizeof(APG)/sizeof(APG[0]);
//uint8_t NUM_GAITS = sizeof(APG)/sizeof(APG[0]);
//
//unsigned long lTimeWaitEnd;
//
//short GetATan2 (short AtanX, short AtanY);
//unsigned long isqrt32 (unsigned long n);
//
//
//
///*
// * BW_PHOENIX DRIVER AX 12
// *
// */
//uint16_t      g_awCurAXPos[NUMSERVOS];
//uint16_t      g_awGoalAXPos[NUMSERVOS];
//
////=============================================================================
//// Global - Local to this file only...
////=============================================================================
//const uint8_t cPinTable[] = {
////static const uint8_t cPinTable[] = {
//  cRRCoxaPin,  cRMCoxaPin,  cRFCoxaPin,  cLRCoxaPin,  cLMCoxaPin,  cLFCoxaPin,
//  cRRFemurPin, cRMFemurPin, cRFFemurPin, cLRFemurPin, cLMFemurPin, cLFFemurPin,
//  cRRTibiaPin, cRMTibiaPin, cRFTibiaPin, cLRTibiaPin, cLMTibiaPin, cLFTibiaPin
////#ifdef cTurretRotPin
////  , cTurretRotPin, cTurretTiltPin
////#endif
//};
