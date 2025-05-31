/*===========================================================================================================================*
*===========================================================================================================================*
										PROJECT BHATARA WIJAYA 3.17 Ver.1.0
								BW DYNAMIXEL AX-12A SMART SERVO HEXAPOD LOCOMOTION LIBRARY
@Author  : Ryan (Batch 2013)
@Company : Brawijaya University Robotics Team
@Division: Intelligent Fire-Fighting Robot Division
@Team    : Project YUME (Legged Robot Sub-Division)
@E-mail	 : achnaf13@gmail.com
@Version : ALPHA RELEASE (ON PROGRESS)
@IDE	 : CooCox IDE 1.7.8

<================= UPDATE LOGS

<=== Version 1.0
@Date:


<=== Version 2.0
@Date:

<================= LIBRARY DEPENDENCIES
	bw_dynamixel_ax_12a.c
	bw_dynamixel_ax_12a.h


*===========================================================================================================================*
============================================================================================================================*/

#include "main.h"



#ifndef BW_DYNAMIXEL_HEXAPOD_CMD_H
#define BW_DYNAMIXEL_HEXAPOD_CMD_H

//// DYNAMIXEL ID
//#define FRONT_LEFT_COXA 	0x01
//#define FRONT_LEFT_FEMUR 	0x02
//#define FRONT_LEFT_TIBIA 	0x03
//
//#define MIDDLE_LEFT_COXA 	0x04
//#define MIDDLE_LEFT_FEMUR 	0x05
//#define MIDDLE_LEFT_TIBIA 	0x06
//
//#define REAR_LEFT_COXA 		0x07
//#define REAR_LEFT_FEMUR 	0x08
//#define REAR_LEFT_TIBIA 	0x09


//#define FRONT_LEFT_DX_COXA		1
//#define FRONT_LEFT_DX_FEMUR		2
//#define FRONT_LEFT_DX_TIBIA		3
//
//#define MIDDLE_LEFT_DX_COXA		4
//#define MIDDLE_LEFT_DX_FEMUR	5
//#define MIDDLE_LEFT_DX_TIBIA	6
//
//#define REAR_LEFT_DX_COXA		7
//#define REAR_LEFT_DX_FEMUR		8
//#define REAR_LEFT_DX_TIBIA		9
//
//#define FRONT_RIGHT_DX_COXA		10
//#define FRONT_RIGHT_DX_FEMUR	11
//#define FRONT_RIGHT_DX_TIBIA	12
//
//#define MIDDLE_RIGHT_DX_COXA	13
//#define MIDDLE_RIGHT_DX_FEMUR	14
//#define MIDDLE_RIGHT_DX_TIBIA	15
//
//#define REAR_RIGHT_DX_COXA		16
//#define REAR_RIGHT_DX_FEMUR		17
//#define REAR_RIGHT_DX_TIBIA		18




extern int DynamxCorrection[];

#define link_A  			5       // besar La
#define link_B  			8       // besar Lb
#define L_junction  		3.5     // besar L_junction
#define RAD2DEG  			57.29
#define ANGLE_CORRECTION    45      //koreksi sudut 0 di teta3, karena sudut 0 sbenarnya adalah sejajar teta2 shg jangkauan servo kurang

struct {
        int ThetaCoxa;
        int ThetaFemur;
        int ThetaTibia;
       }JointAngle;

extern float Dynamx_LinkFemur;
extern float Dynamx_LinkTibia;

/*
 * SPEED TRIGONOMETRY
 */

extern double PI;
//extern float PIby2;
#define MAX_UINT  65535
#define MIN_INT -32768
#define MAX_INT  32767

#define DEC1 10
#define DEC2 100
#define DEC3 1000
#define DEC4 10000

extern const float SIN_TABLE[];
extern const int ACOS_TABLE[];

/*
 * BW DYNAMIXEL HEXAPOD VARIABLES
 */
extern int SUDUT_STATIC[];
extern int SUDUT_STATIC_BWD[];
extern int SUDUT_ANGKAT;
// MOV FWD ZCOXA = 35 and Z TIBIA = 25
extern int IKFWD_COXA_R[];
extern int IKFWD_TIBIA_R[];
extern int IKFWD_COXA_L[];
extern int IKFWD_TIBIA_L[];

// MOV FWD ZCOXA = 15 and Z TIBIA = 15
extern int IKFWD_COXA_R1[];
extern int IKFWD_TIBIA_R1[];
extern int IKFWD_COXA_L1[];
extern int IKFWD_TIBIA_L1[];

// MOV FWD ZCOXA = 10 and Z TIBIA = 10
extern int IKFWD_COXA_R2[];
extern int IKFWD_TIBIA_R2[];
extern int IKFWD_COXA_L2[];
extern int IKFWD_TIBIA_L2[];

// MOV FWD ZCOXA = 5 and Z TIBIA = 5
extern int IKFWD_COXA_R3[];
extern int IKFWD_TIBIA_R3[];
extern int IKFWD_COXA_L3[];
extern int IKFWD_TIBIA_L3[];

//// MOV FWD ZCOXA = 15 and Z TIBIA = 15
//extern int IKFWD_COXA_R2[];
//extern int IKFWD_TIBIA_R2[];
//extern int IKFWD_COXA_L2[];
//extern int IKFWD_TIBIA_L2[];

// MOV ROT ZCOXA_L = 15
extern int IKROT_COXA[];

// MOV ROT ZCOXA_L = 10
extern int IKROT_COXA1[];

// MOV ROT ZCOXA_L = 5
extern int IKROT_COXA2[];

//SLOW
// MOV CURVE RIGHT SLOW ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
extern int IKCRVR_COXA_R2[];
extern int IKCRVR_TIBIA_R2[];
extern int IKCRVR_COXA_L2[];
extern int IKCRVR_TIBIA_L2[];

// MOV PID CURVE RIGHT SLOW ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
extern int IKRPID_COXA_R2[];
extern int IKRPID_TIBIA_R2[];

// MOV CURVE RIGHT ZCOXA_L = 35 ZCOXA_R = 5 and ZTIBIA_L = 25 ZTIBIA_R = 5
extern int IKCRVR_COXA_R[];
extern int IKCRVR_TIBIA_R[];
extern int IKCRVR_COXA_L[];
extern int IKCRVR_TIBIA_L[];

// MOV CURVE PID RIGHT ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
extern int IKRPID_COXA_R[];
extern int IKRPID_TIBIA_R[];

// MOV SLIDE RIGHT X = 20
extern int IKSLR_COXA[];
extern int IKSLR_TIBIA[];

// MOV SLIDE RIGHT X = 15
extern int IKSLR_COXA1[];
extern int IKSLR_TIBIA1[];

// MOV SLIDE RIGHT X = 10
extern int IKSLR_COXA2[];
extern int IKSLR_TIBIA2[];

// MOV CURVE LEFT ZCOXA_R = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 35
extern int IKCRVL_COXA_R[];
extern int IKCRVL_TIBIA_R[];
extern int IKCRVL_COXA_L[];
extern int IKCRVL_TIBIA_L[];

// MOV CURVE PID LEFT ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKLPID_COXA_L[];
extern int IKLPID_TIBIA_L[];

//SLOW
// MOV CURVE LEFT SLOW ZCOXA_R = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 35
extern int IKCRVL_COXA_R2[];
extern int IKCRVL_TIBIA_R2[];
extern int IKCRVL_COXA_L2[];
extern int IKCRVL_TIBIA_L2[];

// MOV PID CURVE LEFT SLOW ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKLPID_COXA_L2[];
extern int IKLPID_TIBIA_L2[];

// MOV SLIDE LEFT X = 20
extern int IKSLL_COXA[];
extern int IKSLL_TIBIA[];

// MOV SLIDE LEFT X = 15
extern int IKSLL_COXA1[];
extern int IKSLL_TIBIA1[];

// MOV SLIDE LEFT X = 10
extern int IKSLL_COXA2[];
extern int IKSLL_TIBIA2[];

// MOV BWD ZCOXA = 35 and Z TIBIA = 25
extern int IKBWD_COXA_R[];
extern int IKBWD_TIBIA_R[];
extern int IKBWD_COXA_L[];
extern int IKBWD_TIBIA_L[];

// MOV CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKCRVRR_COXA_L[];
extern int IKCRVRR_TIBIA_L[];
extern int IKCRVRR_COXA_R[];
extern int IKCRVRR_TIBIA_R[];

// MOV PID CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKPIDR_COXA_L[];
extern int IKPIDR_TIBIA_L[];

// MOV CURVE LEFT REVERSE ZCOXA_R = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
extern int IKCRVLR_COXA_L[];
extern int IKCRVLR_TIBIA_L[];
extern int IKCRVLR_COXA_R[];
extern int IKCRVLR_TIBIA_R[];

// MOV PID CURVE LEFT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKPIDR_COXA_R[];
extern int IKPIDR_TIBIA_R[];

/*
 *   CONVERSION FROM OLD ALGORITHM
 */
extern int sudut_target[];
extern int sudut_awal[];
extern int x;
extern int z_A[];
extern int pembagi;
extern int y_A[];
extern int sudut_tahap1[];
extern int sudut_tahap2[];

//float gamma[6];
extern int leg;
extern int ww[];
extern float beta[];
extern float leg_next[];
extern float A_body;			// translasi pusat badan
extern float A_leg[];			// translasi setiap pangkal kaki
extern float P_body;			// jarak titik pusat robot ke titik imajiner putar
extern int epsilon_body;		// besar sudut vektor hadap thdp vektor poros-imajiner
extern float phi[];
extern float lambpsi[];		//lambda / psi temporal
extern float P_leg[];			// jarak titik pusat kaki ke titik imajiner putar
extern float epsilon[];		// epsilon tiap N

extern unsigned int sudut[];

extern unsigned char y;
extern unsigned char a;
extern unsigned char b;
extern unsigned char c;
extern unsigned char d;
extern unsigned char v;
extern unsigned char index_bantu;
extern unsigned char index_servo2;
extern unsigned char index_servo3;
extern uint32_t PrescalerValue;

extern const float A_const[];

extern const int B_const[];

extern float correct[]; //EDITED

extern const float leg_1[];	//L1
extern const float leg_norm[]; //L2
extern const float alpha[];	//alpha

extern float c1;
extern float c2;
extern float Lsem;
extern float c3;
extern float c4;
extern int i;
extern float temp_var;
extern float temp_var2;

//LEG POSITION MACRO
#define FRONT_LEFT_DX      1
#define FRONT_RIGHT_DX     2
#define MIDDLE_LEFT_DX     3
#define MIDDLE_RIGHT_DX    4
#define REAR_LEFT_DX       5
#define REAR_RIGHT_DX      6

#define IKCALC_ENABLE	1
#define IKCALC_DISABLE	0

extern char command_code[];

enum DYNAMX_HEX_SPEED {HEXSPD_ULTRASLOW=80, HEXSPD_SLOW=300, HEXSPD_MED=500, HEXSPD_MEDFAST=650,  HEXSPD_FAST=800, HEXSPD_ULTRAFAST=1000};

enum DYNAMX_HEX_STEP	{HEXSTEP_VERYCLOSE=1, HEXSTEP_CLOSE= 2, HEXSTEP_MED=3, HEXSTEP_FAR=4};

void Dynamx_LegIK(int distance, unsigned int clearance, unsigned int width);
void Dynamx_Mov_Static(int SPEED, unsigned int IK_STAT);
void Dynamx_Mov_Static_Low(int SPEED);
void Dynamx_MovFwd3cm (unsigned int distance, int SPEED, int IKCALC_STAT);
void Dynamx_MovFwd4cm (unsigned int distance, int SPEED, int IKCALC_STAT);
void Dynamx_MovFwd4cm_slow(unsigned int distance, int SPEED, int IKCALC_STAT);
void Dynamx_MovFwd1cm (unsigned int distance, int SPEED, int IKCALC_STAT);
void Dynamx_MovBwd (int distance, int SPEED, int IKCALC_STAT);
void Dynamx_MovFwd3cm_Reverse (int distance, int SPEED, int IKCALC_STAT);
void Dynamx_Rot_Right(int SPEED,  int STEP, int IKCALC_STAT);
void Dynamx_Rot_Left(int SPEED,  int STEP, int IKCALC_STAT);
void Dynamx_Rot_Left_Reverse(int SPEED,  int STEP);
void Dynamx_Rot_Right_Reverse(int SPEED,  int STEP);
void Dynamx_Rot_Right_PID(int SPEED,  int STEP, float *COMMAND_LOOP, int IKCALC_STAT);
void Dynamx_Rot_Left_PID(int SPEED,  int STEP, float *COMMAND_LOOP, int IKCALC_STAT);
void Dynamx_Slide_Left(int STEP, int SPEED);
void Dynamx_Slide_Right(int STEP, int SPEED);
void Dynamx_CurveRight_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL, int IKCALC_STAT);
void Dynamx_CurveRight(int SPEED, int STEP, int IKCALC_STAT);
void Dynamx_CurveLeft_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL,int IKCALC_STAT);
void Dynamx_CurveLeft(int SPEED, int STEP, int IKCALC_STAT);
void Dynamx_CurveRight_PID_Reverse(int SPEED, int STEP, float *ACTUATE_SIGNAL, int IKCALC_STAT);
void Dynamx_CurveRight_Reverse(int SPEED, int STEP , int IKCALC_STAT);
void Dynamx_CurveLeft_PID_Reverse(int SPEED, int STEP, float *ACTUATE_SIGNAL, int IKCALC_STAT);
void Dynamx_CurveLeft_Reverse(int SPEED, int STEP , int IKCALC_STAT);
void Dynamx_Extinguish_High(int SPEED);
void Dynamx_Mov_Extinguish(int SPEED);
void Dynamx_Mov_Tracking(int SPEED);
void Dynamx_CurveRight_Flame_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL, int IKCALC_STAT);
void Dynamx_CurveLeft_Flame_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL,int IKCALC_STAT);
void Read_HexCMD(void);
void Dynamx_FollowRight_PID(int SPEED,int IKCALC_STAT);
void kinematik_invers(unsigned int leg_position,int *SPEED,float x,float y,float z);




//#define HEX_SLOW  		300
//#define HEX_MED	  		500
//#define HEX_FAST		800
//#define HEX_ULTRAFAST	1000

#endif
