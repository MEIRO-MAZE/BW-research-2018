/*==============================================================================================
								  PROJECT BW Ver.1.0
							BW HEXAPOD COMMAND LIBRARY
==============================================================================================*/

#ifndef BW_HEXAPOD_CMD_H
#define BW_HEXAPOD_CMD_H

#include "main.h"

//#define la  5            // besar La
//#define lb  6.6            // besar Lb
//#define lj  2             // besar L_junction

#define la  5            // besar La
#define lb  8            // besar Lb
#define lj  3.5             // besar L_junction
#define rad2deg  57.29
#define angle_correction    45      //koreksi sudut 0 di teta3, karena sudut 0 sbenarnya adalah sejajar teta2 shg jangkauan servo kurang

#define front_left      1
#define front_right     2
#define middle_left     3
#define middle_right    4
#define rear_left       5
#define rear_right      6


/*
 *  NEW BW 2016 SERVO PIN MAPPING
 */
//FRONT LEFT
#define ch_0 	GPIOD,GPIO_Pin_0 //COXA
#define ch_1 	GPIOD,GPIO_Pin_1 //FEMUR
#define ch_2 	GPIOD,GPIO_Pin_3 //TIBIA

//MIDDLE LEFT
#define ch_3 	GPIOD,GPIO_Pin_7 //COXA
#define ch_4 	GPIOB,GPIO_Pin_5 //FEMUR
#define ch_5 	GPIOB,GPIO_Pin_4 //TIBIA

//REAR LEFT
#define ch_6 	GPIOE,GPIO_Pin_5 //COXA
#define ch_7 	GPIOE,GPIO_Pin_4 //FEMUR
#define ch_8 	GPIOE,GPIO_Pin_6 //TIBIA

//FRONT RIGHT
#define ch_9 	GPIOB,GPIO_Pin_14 //COXA
#define ch_10 	GPIOB,GPIO_Pin_13 //FEMUR
#define ch_11 	GPIOB,GPIO_Pin_12 //TIBIA

//MIDDLE RIGHT
#define ch_12 	GPIOE,GPIO_Pin_9 //COXA
#define ch_13 	GPIOE,GPIO_Pin_8 //FEMUR
#define ch_14 	GPIOE,GPIO_Pin_7 //TIBIA

//REAR RIGHT
#define ch_15 	GPIOB,GPIO_Pin_2 //COXA
#define ch_16 	GPIOB,GPIO_Pin_1 //FEMUR
#define ch_17 	GPIOB,GPIO_Pin_0 //TIBIA

//SERVO ORIENTATION
// right ccw ccw cw
// left cw cw ccw


//SPEED PARAMETER
enum SPEED {ULTRA_SLOW=300, SLOW=250, MED_SLOW=200, MED=150, FAST=130, FAST_LEVEL_2=100, FAST_LEVEL_3=80, ULTRA_FAST=50};
enum STEP {CLOSE=2, HALF=3, FAR=5};


extern uint32_t CCR1_Val;
extern uint32_t CCR2_Val;
extern uint32_t CCR3_Val;

extern uint32_t CCR1_Val2;
extern uint32_t CCR2_Val2;
extern uint32_t CCR3_Val2;

extern uint32_t Count;
extern uint32_t nCount;

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

struct {
        float teta1;
        float teta2;
        float teta3;
       }temp_angle;

extern float c1;
extern float c2;
extern float Lsem;
extern float c3;
extern float c4;
extern int i;
extern float temp_var;
extern float temp_var2;

/*
 * GLOBAL VARIABLES RECENTLY ADDED BY RYAN
 */
//Control loop for gait_mode(SEARCH_FIRE);
//float right=90,left=90;

//GAIT COMMAND
#define STAT_STATIC      			0x41
#define STAT_SEARCH_FIRE 			0x42
#define STAT_FWD         			0x43
#define STAT_BWD         			0x44
#define STAT_ROT_RIGHT   			0x45
#define STAT_ROT_LEFT    			0x46
#define STAT_CURVE_RIGHT 			0x47
#define STAT_CURVE_LEFT  			0x48
#define STAT_ASKEW_RIGHT_TRANSITION 0x49
#define STAT_ASKEW_RIGHT            0x4A
#define STAT_ASKEW_LEFT_TRANSITION 	0x4B
#define STAT_ASKEW_LEFT 			0x4C
#define STAT_DEFLECT_RIGHT          0x4D
#define STAT_DEFLECT_LEFT           0x4E
#define STAT_CELEBRATE   			0x4F

#define STAT_SPEED_SLOW             0x31
#define STAT_SPEED_MED              0x32
#define STAT_SPEED_FAST             0x33

#define STAT_STEP_NARROW            0x31
#define STAT_STEP_FAR               0x32

/*
 * BW COMMAND CALIBRATION MACRO
 */
/*
 * CMD_ACTUATE MACRO
 */
#define CMD_ACTUATE_DRV_STATIC      0x31 //1
#define CMD_ACTUATE_DRV_FWD         0x32 //2
#define CMD_ACTUATE_DRV_BWD         0x33 //3

//command_code[0]
#define CMD_RUNTIME_CALIBRATION     0x5A //Z
#define CMD_SHOW_CALIBRATION        0x58 //X

#define CMD_NORMAL_CALIBRATION      0x41 //A
#define CMD_SIDE_CALIBRATION        0x42 //B
#define CMD_REAR_CALIBRATION        0x43 //C

#define CMD_DRIVETEST_STATIC        0x44 //D
#define CMD_DRIVETEST_FWD           0x45 //E
#define CMD_DRIVETEST_BWD           0x46 //F
#define CMD_DRIVETEST_ROT_RIGHT     0x47 //G
#define CMD_DRIVETEST_ROT_LEFT      0x48 //H
#define CMD_DRIVETEST_CURVE_RIGHT   0x49 //I
#define CMD_DRIVETEST_CURVE_LEFT    0x50 //J

//command_code[1]
#define FRONT_LEFT                  0x41 //A
#define MIDDLE_LEFT                 0x42 //B
#define REAR_LEFT                   0x43 //C

#define FRONT_RIGHT                 0x44 //D
#define MIDDLE_RIGHT                0x45 //E
#define REAR_RIGHT                  0x46 //F

//command_code[2]
#define COXA                        0x31 //1
#define FEMUR                       0x32 //2
#define TIBIA                       0X33 //3

//command_code[3]
#define CAL_INCREMENT               0x2B //+
#define CAL_DECREMENT               0x2D //-

//command_code[4]
#define ONE                         0x31 //1
#define TWO                         0x32 //2
#define THREE                       0X33 //3
#define FOUR                        0x34 //4
#define FIVE                        0x35 //5

#define CMD_RESET {command_code[0]=0x0; command_code[1]=0x0;command_code[2]=0x0;command_code[3]=0x0;command_code[4]=0x0;}

extern unsigned int TEST;
extern int CALIBRATION_STAT;


/*
 * BW SEARCH FIRE VARIABLES
 */
extern unsigned int panas;

void BW_Servo_Initialization(void);

//INVERSE KINEMATICS PROTOTYPE
void Servo_TIM_Init(void);
void Servo_TIM_Init2(void);
void Servo_Interrupt_Init(void);
void Servo_Interrupt_Init2(void);
void Servo_GPIO_Init(void);
void generate_movement_data(int deflection_angle, int translation, float clearance);
void inv_kine(char leg_pos,float x,float w,float z);
void servo_lin_func(int ch_num,float value);
void gait_mode(int menu, int SPEED);


//BW BASIC HEXAPOD GAIT
void mov_static(void);
void mov_search_fire(void);
void mov_fwd_5cm (int distance, int SPEED);
void mov_fwd_3cm (int distance, int SPEED); //NEW FUNCTION
void mov_fwd_2cm (int distance, int SPEED); //NEW FUNCTION 2
void mov_bwd(int distance, int SPEED);
//void mov_rot_right_90_dgr(int angle, int SPEED, int STEP);
//void mov_rot_left_90_dgr(int angle, int SPEED, int STEP);
void mov_rot_right(int SPEED, int STEP);
void mov_rot_left(int SPEED, int STEP);
void mov_curve_right(int SPEED, int STEP);
void mov_curve_left(int SPEED, int STEP);
void mov_askew_right(int SPEED, int STEP);
void mov_askew_right_transition(void);
void mov_askew_left(int SPEED, int STEP);
void mov_askew_left_transition(void);
void mov_celebrate(void);
void mov_fwd_ripple_gait(int SPEED);
void mov_bwd_ripple_gait(int SPEED);
void mov_fwd_wave_gait(int SPEED);
void mov_toggle_clearance(void);
void mov_deflect_right(int SPEED, int STEP);
void mov_deflect_left(int SPEED, int STEP);
void mov_bwd_5cm(int distance, int SPEED);
void mov_rot_right_reverse(int SPEED, int STEP);
void mov_bwd_3cm(int distance, int SPEED);
void mov_rot_left_reverse(int SPEED, int STEP);


//BW PID WALL FOLLOWING MOVEMENT
void PID_curve_right(int SPEED, int STEP, float *COMMAND_LOOP);
void PID_curve_left(int SPEED, int STEP, float *COMMAND_LOOP);

//BW FIRE FIGHTING ALGORITHM
void BW_FireFight(void);

//BW DEMO HEXAPOD DANCE MODE
void bw_demo(void);

void CMD_ACTUATE(void);
int BW_Calibration(void);
void BW_Extinguisher(void);

#endif
