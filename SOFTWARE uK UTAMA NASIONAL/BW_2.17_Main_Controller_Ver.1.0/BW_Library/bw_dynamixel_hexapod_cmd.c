/*==============================================================================================
							PROJECT BHATARA WIJAYA 3.17 Ver.1.0
					BW DYNAMIXEL AX-12A SMART SERVO HEXAPOD LOCOMOTION LIBRARY
==============================================================================================*/

#include "bw_dynamixel_hexapod_cmd.h"

// DYNAMIXEL ID
const unsigned int FRONT_LEFT_DX_COXA =	1;
const unsigned int FRONT_LEFT_DX_FEMUR=	2;
const unsigned int FRONT_LEFT_DX_TIBIA=	3;

const unsigned int MIDDLE_LEFT_DX_COXA =	4;
const unsigned int MIDDLE_LEFT_DX_FEMUR=	5;
const unsigned int MIDDLE_LEFT_DX_TIBIA=	6;

const unsigned int REAR_LEFT_DX_COXA 	=7;
const unsigned int REAR_LEFT_DX_FEMUR	=8;
const unsigned int REAR_LEFT_DX_TIBIA	=9;

const unsigned int FRONT_RIGHT_DX_COXA =	10;
const unsigned int FRONT_RIGHT_DX_FEMUR=	11;
const unsigned int FRONT_RIGHT_DX_TIBIA=	12;

const unsigned int MIDDLE_RIGHT_DX_COXA =	13;
const unsigned int MIDDLE_RIGHT_DX_FEMUR=	14;
const unsigned int MIDDLE_RIGHT_DX_TIBIA=	15;

const unsigned int REAR_RIGHT_DX_COXA 	=16;
const unsigned int REAR_RIGHT_DX_FEMUR	=17;
const unsigned int REAR_RIGHT_DX_TIBIA	=18;

void IK_Test(unsigned int clc)
{
	int count;
	for(count=1;count<=15;count++)
	{

		Dynamx_LegIK(2,clc,count);
//		delay_ms(1000);
		if(JointAngle.ThetaCoxa>0)
		{
			Sendto_PC(USART1,"============================ Clearance: %d \r",clc);
			Sendto_PC(USART1,"============================  Width: %d \r",count);
//			while(1);
//			if(JointAngle.ThetaFemur>=(-20)) while(1);
//			if(JointAngle.ThetaTibia==98) while(1);
		}

	}
}

int clc=6;
void HexDemo(void)
{
	while(1)
	{
	//		//DEPAN MENAPAK
			Dyna_Actuate(FRONT_RIGHT_DX_COXA,175,500,2600);
			Dyna_Actuate(FRONT_RIGHT_DX_FEMUR,175,500,2600);
			Dyna_Actuate(FRONT_RIGHT_DX_TIBIA,60,500,2600);
	//
	//		Dyna_Actuate(FRONT_LEFT_COXA,175,500);
	//		Dyna_Actuate(FRONT_LEFT_FEMUR,140,500);
	//
	//		//BELAKANG MENAPAK
			Dyna_Actuate(FRONT_RIGHT_DX_COXA,125,500,2600);
			Dyna_Actuate(FRONT_RIGHT_DX_FEMUR,125,500,2600);
			Dyna_Actuate(FRONT_RIGHT_DX_TIBIA,60,500,2600);
	}
//
//	Dyna_Actuate(FRONT_RIGHT_DX_COXA,150,500,2600);
//	Dyna_Actuate(FRONT_RIGHT_DX_FEMUR,150,500,2600);
//	Dyna_Actuate(FRONT_RIGHT_DX_TIBIA,150,500,2600);
//
//	Dyna_Actuate(FRONT_LEFT_DX_COXA,150,500,2600);
//	Dyna_Actuate(FRONT_LEFT_DX_FEMUR,150,500,2600);
//	Dyna_Actuate(FRONT_LEFT_DX_TIBIA,150,500,2600);
//
//	Dyna_Actuate(MIDDLE_RIGHT_DX_COXA,150,500,2600);
//	Dyna_Actuate(MIDDLE_RIGHT_DX_FEMUR,150,500,2600);
//	Dyna_Actuate(MIDDLE_RIGHT_DX_TIBIA,150,500,2600);
//
//	Dyna_Actuate(MIDDLE_LEFT_DX_COXA,150,500,2600);
//	Dyna_Actuate(MIDDLE_LEFT_DX_FEMUR,150,500,2600);
//	Dyna_Actuate(MIDDLE_LEFT_DX_TIBIA,150,500,2600);
//
//	Dyna_Actuate(REAR_RIGHT_DX_COXA,150,500,2600);
//	Dyna_Actuate(REAR_RIGHT_DX_FEMUR,150,500,2600);
//	Dyna_Actuate(REAR_RIGHT_DX_TIBIA,150,500,2600);
//
//	Dyna_Actuate(REAR_LEFT_DX_COXA,150,500,2600);
//	Dyna_Actuate(REAR_LEFT_DX_FEMUR,150,500,2600);
//	Dyna_Actuate(REAR_LEFT_DX_TIBIA,150,500,2600);
//	Dynamx_MovFwd3cm(30,HEXSPD_ULTRAFAST,IKCALC_ENABLE);
//
//	Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_CLOSE,IKCALC_ENABLE);
//	Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_CLOSE,IKCALC_ENABLE);
//
//	Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
//	Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_MED,IKCALC_ENABLE);
//
//	Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//	Dynamx_Rot_Right(HEXSPD_ULTRAFAST,HEXSTEP_FAR,IKCALC_ENABLE);
//
//	Dynamx_Mov_Static(HEXSPD_FAST,IKCALC_ENABLE);
//	HexJoint_Actuate(MIDDLE_LEFT_DX_COXA,150,500);
//	HexJoint_Actuate(MIDDLE_LEFT_DX_FEMUR,150,500); //ditambah makin keatas
//	HexJoint_Actuate(MIDDLE_LEFT_DX_TIBIA,150,500); //ditambah makin ke dalam

//	//STATIC LEG DOWN
//	Dynamx_LegIK(0,10,3);
//	delay_ms(100);

	//STATIC IDEAL

//	Dynamx_LegIK(0,4,6);
//	Dynamx_LegIK(0,5,6);
//	Dynamx_LegIK(0,6,6);
////	Dynamx_LegIK(0,7,9);
//	Dynamx_LegIK(0,6,6);
//	Dynamx_LegIK(0,5,6);
//	Dynamx_LegIK(0,4,6);

	//angkat maksimal
//	Dynamx_LegIK(0,3,5);

//	Dynamx_Mov_Static(HEX_ULTRAFAST, IKCALC_ENABLE);
//	HexJoint_Actuate(MIDDLE_LEFT_DX_COXA, 150, HEX_FAST);
//	HexJoint_Actuate(MIDDLE_LEFT_DX_FEMUR, 150, HEX_FAST);
//	HexJoint_Actuate(MIDDLE_LEFT_DX_TIBIA, 150, HEX_FAST);

//	delay_ms(500);

//	HexJoint_Actuate(MIDDLE_LEFT_DX_TIBIA, 42, HEX_MED);
//	delay_ms(500);
//	Dynamx_MovFwd3cm (20, HEX_FAST, IKCALC_ENABLE);
//	int count;
//	Dynamx_Mov_Static(HEX_ULTRAFAST, IKCALC_DISABLE);
//	delay_ms(2000);

//	Dynamx_MovFwd3cm (40, HEX_ULTRAFAST, IKCALC_DISABLE);

//	for(count=0;count<=6;count++)
//	{
//		Dynamx_Rot_Right(90,HEX_ULTRAFAST,IKCALC_DISABLE);
//	}

//	Dynamx_MovBwd(30,HEX_ULTRAFAST,IKCALC_ENABLE);

//	for(count=0;count<=6;count++)
//	{
//		Dynamx_Rot_Left(90,HEX_ULTRAFAST,IKCALC_DISABLE);
//	}

//	for(count=0;count<=10;count++)
//	{
////		Dynamx_Deflect_Right(1,HEX_ULTRAFAST);
//		Dynamx_Deflect_Left(1,HEXSPD_ULTRAFAST);
//	}
//
//	for(count=0;count<=10;count++)
//	{
//		Dynamx_Deflect_Right(1,HEXSPD_ULTRAFAST);
////		Dynamx_Deflect_Left(1,HEX_ULTRAFAST);
//	}


//	Dynamx_MovFwd3cm (15, HEX_MED, IKCALC_DISABLE);
//
//	Dynamx_MovFwd3cm (15, HEX_FAST, IKCALC_DISABLE);

//	Dynamx_MovFwd3cm (15, HEX_ULTRAFAST, IKCALC_DISABLE);


//	int count;

//	while(1)
//	{
//		Dynamx_Rot_Right();



////		delay_ms(4000);
////		Dynamx_MovFwd3cm(3,50);
////		Dynamx_MovFwd3cm (15, MED, IKCALC_ENABLE);
//		Dynamx_MovFwd3cm (15, MED, IKCALC_DISABLE);
//
////		Dynamx_Rot_Left();
////		Dynamx_MovBwd();
//
//
////		while(1);
//


//
////
//		for(count=0;count<=5;count++)
//		{
//			Dynamx_Rot_Left(90,MED,IKCALC_DISABLE);
//		}
//		Read_HexCMD();




//		HexJoint_Actuate(FRONT_RIGHT_DX_COXA,150,500);
//		HexJoint_Actuate(FRONT_RIGHT_DX_FEMUR,150,500); //ditambah makin keatas
//		HexJoint_Actuate(FRONT_RIGHT_DX_TIBIA,150,500); //ditambah makin ke dalam
//
//		HexJoint_Actuate(MIDDLE_RIGHT_DX_COXA,150,500);
//		HexJoint_Actuate(MIDDLE_RIGHT_DX_FEMUR,150,500); //ditambah makin keatas
//		HexJoint_Actuate(MIDDLE_RIGHT_DX_TIBIA,150,500); //ditambah makin ke dalam

//		Dynamx_LegIK(5,6,7);
//		delay_ms(3000);

//		Dynamx_LegIK(0,4,5);
//		delay_ms(3000);

//		IK_Test(9);
//		Dynamx_LegIK(1,7,8);

//		IK_Left(0,4,5);
//		IK_Right(3,6,7);
//
//
//		IK_Left(3,4,5);
//		IK_Right(-3,6,7);
//
//		IK_Left(3,6,7);
//		IK_Right(0,4,5);
//
//		IK_Left(-3,6,7);
//		IK_Right(3,4,5);

//			//ANGKAT IDEAL
//			Dynamx_LegIK(0,4,5);
//		//	delay_ms(100);
//
//			Dynamx_LegIK(5,4,5);
//		//	delay_ms(100);
//
//			//depan menapak
//			Dynamx_LegIK(5,6,7);
//		//	delay_ms(100);
//
//
//
//			//belakang menapak
//			Dynamx_LegIK(-5,6,7);
//		//	delay_ms(100);



//	}



//	IK_Test(clc);
//	clc++;
//
//	if(clc==8){Sendto_PC(USART1,"IK TEST FAILED \r");while(1);}


//	Dynamx_LegIK(0,6,7);


//	//ANGKAT IDEAL
//	Dynamx_LegIK(0,4,5);
////	delay_ms(100);
//
//	Dynamx_LegIK(5,4,5);
////	delay_ms(100);
//
//	//depan menapak
//	Dynamx_LegIK(5,6,7);
////	delay_ms(100);
//
//
//
//	//belakang menapak
//	Dynamx_LegIK(-5,6,7);
////	delay_ms(100);






//	//STATIC LEG DOWN

//	IK_Test(1);
//	IK_Test(2);
//	IK_Test(3);
//	IK_Test(4);
//	IK_Test(5);
//	IK_Test(6);
//	IK_Test(7);
//	IK_Test(8);
//	IK_Test(9);
//	IK_Test(10);



//	//STATIC LEG DOWN
//	Dynamx_LegIK(10,4);
//	delay_ms(100);

//	//STATIC LEG DOWN
//	Dynamx_LegIK(10,1);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,2);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,3);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,4);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,5);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,6);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,7);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,8);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,9);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,10);
//	delay_ms(100);





//	Dynamx_LegIK(1,11);
//	delay_ms(100);
//
//	Dynamx_LegIK(1,10);
//	delay_ms(100);
//
//	Dynamx_LegIK(1,9);
//	delay_ms(100);
//
//	Dynamx_LegIK(1,8);
//	delay_ms(100);

//	//STATIC LEG DOWN
//	Dynamx_LegIK(3,7);
//	delay_ms(100);

//	Dynamx_LegIK(1,6);
//	delay_ms(100);
//
//	Dynamx_LegIK(1,5);
//	delay_ms(100);
//
//	Dynamx_LegIK(1,4);
//	delay_ms(100);
//
//	Dynamx_LegIK(1,3);
//	delay_ms(100);

//	Dynamx_LegIK(2,11);
//	delay_ms(100);
//	Dynamx_LegIK(3,11);
//	delay_ms(100);
//	Dynamx_LegIK(4,11);
//	delay_ms(100);
//	Dynamx_LegIK(5,11);
//	delay_ms(100);
//
//	Dynamx_LegIK(6,11);
//	delay_ms(100);
//
//	Dynamx_LegIK(7,11);
//	delay_ms(100);
//
//	Dynamx_LegIK(8,11);
//	delay_ms(100);
//
//	Dynamx_LegIK(9,11);
//	delay_ms(100);
//
//	Dynamx_LegIK(10,11);
//	delay_ms(100);

//	HexJoint_Actuate(REAR_LEFT_DX_COXA,150,500);
//	HexJoint_Actuate(REAR_LEFT_DX_FEMUR,150,500);
//	HexJoint_Actuate(REAR_LEFT_DX_TIBIA,150,500);
}


void HexJoint_Actuate(unsigned char DYNA_ID, int INV_VALUE, int SPEED)
{
//	lcd_gotoxy(0,2);sprintf(lcd,"BW HXJNT ACT");lcd_putstr(lcd);

	unsigned int TX_DELAY_TIME;
	switch(SPEED)
	{									//jika berhenti/patah2 => terlalu besar
		case HEXSPD_ULTRASLOW:
		{
//			TX_DELAY_TIME=11200; //AX-12
			TX_DELAY_TIME=4000; //AX-18
//			TX_DELAY_TIME=4000;
		}break;

		case HEXSPD_SLOW:
		{
//			TX_DELAY_TIME=5600; //AX-12
			TX_DELAY_TIME=2000; //AX-12
//			TX_DELAY_TIME=3900;
		}break;

		case HEXSPD_MED:
		{
//			TX_DELAY_TIME=5000; //AX-12
			TX_DELAY_TIME=500; //AX-18
		}break;

		case HEXSPD_MEDFAST:
		{
//			TX_DELAY_TIME=5000; //AX-12
			TX_DELAY_TIME=350; //AX-18 asli
//			TX_DELAY_TIME=2900; //AX-18 modif

		}break;

		case HEXSPD_FAST:
		{
//			TX_DELAY_TIME=3750;
//			TX_DELAY_TIME=4500; //AX-12
			TX_DELAY_TIME=1200; //AX-18

		}break;

		case HEXSPD_ULTRAFAST:
		{
//			TX_DELAY_TIME=3850; //sepatu hitam
//			TX_DELAY_TIME=4350; //AX-12
			TX_DELAY_TIME=700; //AX-18
//			TX_DELAY_TIME=4200; //sepatu putih
//			TX_DELAY_TIME=4;
		}break;
	}

	int CorrectedAngle= INV_VALUE + DynamxCorrection[DYNA_ID-1];
	Dyna_Actuate(DYNA_ID, CorrectedAngle, SPEED, TX_DELAY_TIME);

	Sendto_PC(USART1,"Dyna ID: %d \r",DYNA_ID);
	Sendto_PC(USART1,"DynamxCorrection[%d]: %d \r",DYNA_ID,DynamxCorrection[DYNA_ID-1]);
	Sendto_PC(USART1,"INV_VALUE: %d \r",INV_VALUE);
	Sendto_PC(USART1,"CorrectedAngle: %d \r",CorrectedAngle);
	Sendto_PC(USART1,"SPEED: %d \r",SPEED);
	Sendto_PC(USART1,"TX_DELAY_TIME: %d \r\r\r",TX_DELAY_TIME);
}

int FloatToInt(float input)
{
  //Rounding a number avoiding truncation:
//  return (int)(input + 0.5);

	 int temp = (int)input; // floor-rounded input
	 float dif = input - (float)temp; //
	 if (dif < 0.5) return temp;
	 else return temp+1;
}

int RadToMicro(float rad) {
  //600 - 180 degree
  //2400 - 0 degree

  //y = ax + b
  //x = 0: y = a*0 + b = 2400, so b = 2400
  //x = pi (180'): y = a*pi + 2400 = 600, so a = -1800/pi
  //therefore y = 2400 - 1800/pi*x

  //Make sure rad isn't negative:
  if(rad < 0) {
    rad = -rad;
  }

  while(rad > PI) {
    rad -= PI;
  }

  return 2400 - FloatToInt(572.958 * rad);
}

//The functions for sin and cos use lookup table to determine the sin or cos value of the input angle.
//Input for these functions are scaled up 10 times. e.g. -450 = -45.0 deg
//  - Both functions return a value between -1 and 1. (e.g. input: -450, output -> -0.7071)
float SpeedTrig_sin(int deg)
{
  deg *= 10;
  float result = 0;
  int sign = 1;

  if (deg < 0) {
    deg = -deg;
    sign = -1;
  }

  while(deg >= 3600) {
    deg =- 3600;
  }

  if((deg >= 0) && (deg <= 900)) {
    //0 and 90 degrees.
    result = SIN_TABLE[deg / 5];

  } else if((deg > 900) && (deg <= 1800)) {
    //90 and 180 degrees.
    result = SIN_TABLE[(1800 - deg) / 5];

  } else if((deg > 1800) && (deg <= 2700)) {
    //180 and 270 degrees.
    result = -SIN_TABLE[(deg - 1800) / 5];

  } else if((deg > 2700) && (deg <= 3600)) {
    //270 and 360 degrees.
    result = -SIN_TABLE[(3600 - deg) / 5];

  }
  return sign * result;
}

//The acos function uses a lookup table for corresponding output.
//Output data are stored as byte values (0 - 255), they are scaled down to float number (0.0 - 1.0) for output.
float SpeedTrig_acos(float num)
{
  float rads = 0;
  int TRUE = 1;
  int FALSE= 0;
  int negative = FALSE;

  //Get sign of input
  if(num < 0) {
    negative = TRUE;
    num = -num;
  }

  if((num >= 0) && (num < 0.9)) {
    //num between 0 and 0.9.
    rads = (float)ACOS_TABLE[FloatToInt(num * DEC4 / 79)] * 0.00616;

  } else if ((num >= 0.9) && (num < 0.99)) {
    //num between 0.9 and 0.99.
    rads = (float)ACOS_TABLE[FloatToInt((num * DEC4 - 9000) / 8) + 114] * 0.00616;

  } else if ((num >= 0.99) && (num <= 1)) {
    //num between 0.99 and 1.0.
    rads = (float)ACOS_TABLE[FloatToInt((num * DEC4 - 9900) / 2) + 227] * 0.00616;
  }

  //Account for the negative sign if required.
  if(negative) {
    rads = PI - rads;
  }

  return rads;
}

float SpeedTrig_atan2(float opp, float adj) {
  float hypt = sqrt(adj * adj + opp * opp);
  float rad = SpeedTrig_acos(adj / hypt);

  if(opp < 0) {
    rad = -rad;
  }

  return rad;
}




void Dynamx_LegIK(int distance, unsigned int clearance, unsigned int width)
{
	float x, theta1,theta2,/*theta3,*/theta4;
	float temp_var1,temp_var2,temp_var3,temp_var4;//temp_var5,temp_var6,temp_var7;
	double add_var1,add_var2,add_var3;


	//Step 1
	temp_var1= pow(clearance,2) + pow(width,2);
	x= sqrt(temp_var1);
	Sendto_PC(USART1,"temp_var1: %d \r",(int)temp_var1);
	Sendto_PC(USART1,"x: %d \r",(int)x);

	//Step 2
	temp_var2= pow(Dynamx_LinkFemur,2) + pow(x,2) - pow(Dynamx_LinkTibia,2);
	Sendto_PC(USART1,"temp_var2: %d \r",(int)temp_var2);

	temp_var3= 2*Dynamx_LinkFemur*x;
	Sendto_PC(USART1,"temp_var3: %d \r",(int)temp_var3);

	add_var1=temp_var2/temp_var3;
	Sendto_PC(USART1,"add_var1: %d \r",(int)add_var1);

	theta1= SpeedTrig_acos(add_var1)*RAD2DEG;
	Sendto_PC(USART1,"theta1: %d \r",(int)theta1);
//	theta1= RadToMicro(theta1);
//	Sendto_PC(USART1,"theta1: %d \r",(int)theta1);


	//Step3
//	temp_var4= SpeedTrig_sin(theta1)*x/Dynamx_LinkTibia;
	temp_var4= SpeedTrig_sin(theta1);
	Sendto_PC(USART1,"temp_var4: %d \r",(int)temp_var4);

	temp_var4= temp_var4*x;
	Sendto_PC(USART1,"temp_var4: %d \r",(int)temp_var4);

	temp_var4= temp_var4/Dynamx_LinkTibia;
	Sendto_PC(USART1,"temp_var4: %d \r",(int)temp_var4);


	theta2= asin(temp_var4)*RAD2DEG;
	Sendto_PC(USART1,"theta2: %d \r",(int)theta2);

	JointAngle.ThetaTibia= 180 - theta2;
//	JointAngle.ThetaTibia= theta2;

	add_var2= width/clearance;
	Sendto_PC(USART1,"add_var2: %d \r",(int)add_var2);
	theta4= atan(add_var2)*RAD2DEG;
	Sendto_PC(USART1,"theta4: %d \r",(int)theta4);
	JointAngle.ThetaFemur= theta4+theta1 - 90;


	//Calculating Coxa
	if(distance<=0)
	{
		distance= -distance;
		add_var3= width/distance;
		JointAngle.ThetaCoxa= -atan(add_var3)*RAD2DEG;
	}
	else
	{
		add_var3= width/distance;
		JointAngle.ThetaCoxa= atan(add_var3)*RAD2DEG;
	}


	Sendto_PC(USART1,"JointAngle.ThetaCoxa: %d \r",(int)JointAngle.ThetaCoxa);
	Sendto_PC(USART1,"JointAngle.ThetaFemur: %d \r",(int)JointAngle.ThetaFemur);
	Sendto_PC(USART1,"JointAngle.ThetaTibia: %d \r",(int)JointAngle.ThetaTibia);

	int IK_AngleCoxa = 150+ (int)JointAngle.ThetaCoxa;
	int IK_AngleFemur= 150+ (int)JointAngle.ThetaFemur;
	int IK_AngleTibia= 150+ (int)JointAngle.ThetaTibia;

	Sendto_PC(USART1,"IK_AngleCoxa: %d \r",(int)IK_AngleCoxa);
	Sendto_PC(USART1,"IK_AngleFemur: %d \r",(int)IK_AngleFemur);
	Sendto_PC(USART1,"IK_AngleTibia: %d \r\r\r",(int)IK_AngleTibia);

//
//	HexJoint_Actuate(FRONT_LEFT_DX_TIBIA,IK_AngleTibia,700); //ditambah makin ke dalam
//	HexJoint_Actuate(FRONT_LEFT_DX_FEMUR,IK_AngleFemur,700); //ditambah makin keatas
//	HexJoint_Actuate(FRONT_LEFT_DX_COXA,IK_AngleCoxa,700);


	HexJoint_Actuate(MIDDLE_LEFT_DX_TIBIA,IK_AngleTibia,700); //ditambah makin ke dalam
	HexJoint_Actuate(MIDDLE_LEFT_DX_FEMUR,IK_AngleFemur,700); //ditambah makin keatas
	HexJoint_Actuate(MIDDLE_LEFT_DX_COXA,IK_AngleCoxa,700);


//	HexJoint_Actuate(REAR_LEFT_DX_TIBIA,IK_AngleTibia,700); //ditambah makin ke dalam
//	HexJoint_Actuate(REAR_LEFT_DX_FEMUR,IK_AngleFemur,700); //ditambah makin keatas
//	HexJoint_Actuate(REAR_LEFT_DX_COXA,IK_AngleCoxa,700);
//
//
//	IK_AngleCoxa = 150- (int)JointAngle.ThetaCoxa;
//	IK_AngleFemur= 150- (int)JointAngle.ThetaFemur;
//	IK_AngleTibia= 150- (int)JointAngle.ThetaTibia;
//
//	Sendto_PC(USART1,"IK_AngleCoxa: %d \r",(int)IK_AngleCoxa);
//	Sendto_PC(USART1,"IK_AngleFemur: %d \r",(int)IK_AngleFemur);
//	Sendto_PC(USART1,"IK_AngleTibia: %d \r\r\r",(int)IK_AngleTibia);
//
//
//	HexJoint_Actuate(FRONT_RIGHT_DX_TIBIA,IK_AngleTibia,700); //ditambah makin ke dalam
//	HexJoint_Actuate(FRONT_RIGHT_DX_FEMUR,IK_AngleFemur,700); //ditambah makin keatas
//	HexJoint_Actuate(FRONT_RIGHT_DX_COXA,IK_AngleCoxa,700);
//
//
//	HexJoint_Actuate(MIDDLE_RIGHT_DX_TIBIA,IK_AngleTibia,700); //ditambah makin ke dalam
//	HexJoint_Actuate(MIDDLE_RIGHT_DX_FEMUR,IK_AngleFemur,700); //ditambah makin keatas
//	HexJoint_Actuate(MIDDLE_RIGHT_DX_COXA,IK_AngleCoxa,700);
//
//
//	HexJoint_Actuate(REAR_RIGHT_DX_TIBIA,IK_AngleTibia,700); //ditambah makin ke dalam
//	HexJoint_Actuate(REAR_RIGHT_DX_FEMUR,IK_AngleFemur,700); //ditambah makin keatas
//	HexJoint_Actuate(REAR_RIGHT_DX_COXA,IK_AngleCoxa,700);

}

void IK_Right(int distance, unsigned int clearance, unsigned int width)
{
	float x, theta1,theta2,/*theta3,*/theta4;
	float temp_var1,temp_var2,temp_var3,temp_var4;//temp_var5,temp_var6,temp_var7;
	double add_var1,add_var2,add_var3;


	//Step 1
	temp_var1= pow(clearance,2) + pow(width,2);
	x= sqrt(temp_var1);
	Sendto_PC(USART1,"temp_var1: %d \r",(int)temp_var1);
	Sendto_PC(USART1,"x: %d \r",(int)x);

	//Step 2
	temp_var2= pow(Dynamx_LinkFemur,2) + pow(x,2) - pow(Dynamx_LinkTibia,2);
	Sendto_PC(USART1,"temp_var2: %d \r",(int)temp_var2);

	temp_var3= 2*Dynamx_LinkFemur*x;
	Sendto_PC(USART1,"temp_var3: %d \r",(int)temp_var3);

	add_var1=temp_var2/temp_var3;
	Sendto_PC(USART1,"add_var1: %d \r",(int)add_var1);

	theta1= SpeedTrig_acos(add_var1)*RAD2DEG;
	Sendto_PC(USART1,"theta1: %d \r",(int)theta1);
//	theta1= RadToMicro(theta1);
//	Sendto_PC(USART1,"theta1: %d \r",(int)theta1);


	//Step3
//	temp_var4= SpeedTrig_sin(theta1)*x/Dynamx_LinkTibia;
	temp_var4= SpeedTrig_sin(theta1);
	Sendto_PC(USART1,"temp_var4: %d \r",(int)temp_var4);

	temp_var4= temp_var4*x;
	Sendto_PC(USART1,"temp_var4: %d \r",(int)temp_var4);

	temp_var4= temp_var4/Dynamx_LinkTibia;
	Sendto_PC(USART1,"temp_var4: %d \r",(int)temp_var4);


	theta2= asin(temp_var4)*RAD2DEG;
	Sendto_PC(USART1,"theta2: %d \r",(int)theta2);

	JointAngle.ThetaTibia= 180 - theta2;
//	JointAngle.ThetaTibia= theta2;

	add_var2= width/clearance;
	Sendto_PC(USART1,"add_var2: %d \r",(int)add_var2);
	theta4= atan(add_var2)*RAD2DEG;
	Sendto_PC(USART1,"theta4: %d \r",(int)theta4);
	JointAngle.ThetaFemur= theta4+theta1 - 90;


	//Calculating Coxa
	if(distance<=0)
	{
		distance= -distance;
		add_var3= width/distance;
		JointAngle.ThetaCoxa= -atan(add_var3)*RAD2DEG;
	}
	else
	{
		add_var3= width/distance;
		JointAngle.ThetaCoxa= atan(add_var3)*RAD2DEG;
	}


	Sendto_PC(USART1,"JointAngle.ThetaCoxa: %d \r",(int)JointAngle.ThetaCoxa);
	Sendto_PC(USART1,"JointAngle.ThetaFemur: %d \r",(int)JointAngle.ThetaFemur);
	Sendto_PC(USART1,"JointAngle.ThetaTibia: %d \r",(int)JointAngle.ThetaTibia);

	int IK_AngleCoxa = 150+ (int)JointAngle.ThetaCoxa;
	int IK_AngleFemur= 150+ (int)JointAngle.ThetaFemur;
	int IK_AngleTibia= 150+ (int)JointAngle.ThetaTibia;

	Sendto_PC(USART1,"IK_AngleCoxa: %d \r",(int)IK_AngleCoxa);
	Sendto_PC(USART1,"IK_AngleFemur: %d \r",(int)IK_AngleFemur);
	Sendto_PC(USART1,"IK_AngleTibia: %d \r\r\r",(int)IK_AngleTibia);

	HexJoint_Actuate(MIDDLE_LEFT_DX_TIBIA,IK_AngleTibia,700); //ditambah makin ke dalam
	HexJoint_Actuate(MIDDLE_LEFT_DX_FEMUR,IK_AngleFemur,700); //ditambah makin keatas
	HexJoint_Actuate(MIDDLE_LEFT_DX_COXA,IK_AngleCoxa,700);


	IK_AngleCoxa = 150- (int)JointAngle.ThetaCoxa;
	IK_AngleFemur= 150- (int)JointAngle.ThetaFemur;
	IK_AngleTibia= 150- (int)JointAngle.ThetaTibia;

	Sendto_PC(USART1,"IK_AngleCoxa: %d \r",(int)IK_AngleCoxa);
	Sendto_PC(USART1,"IK_AngleFemur: %d \r",(int)IK_AngleFemur);
	Sendto_PC(USART1,"IK_AngleTibia: %d \r\r\r",(int)IK_AngleTibia);


	HexJoint_Actuate(FRONT_RIGHT_DX_TIBIA,IK_AngleTibia,700); //ditambah makin ke dalam
	HexJoint_Actuate(FRONT_RIGHT_DX_FEMUR,IK_AngleFemur,700); //ditambah makin keatas
	HexJoint_Actuate(FRONT_RIGHT_DX_COXA,IK_AngleCoxa,700);


	HexJoint_Actuate(REAR_RIGHT_DX_TIBIA,IK_AngleTibia,700); //ditambah makin ke dalam
	HexJoint_Actuate(REAR_RIGHT_DX_FEMUR,IK_AngleFemur,700); //ditambah makin keatas
	HexJoint_Actuate(REAR_RIGHT_DX_COXA,IK_AngleCoxa,700);
}

void IK_Left(int distance, unsigned int clearance, unsigned int width)
{
	float x, theta1,theta2,/*theta3,*/theta4;
	float temp_var1,temp_var2,temp_var3,temp_var4;//temp_var5,temp_var6,temp_var7;
	double add_var1,add_var2,add_var3;


	//Step 1
	temp_var1= pow(clearance,2) + pow(width,2);
	x= sqrt(temp_var1);
	Sendto_PC(USART1,"temp_var1: %d \r",(int)temp_var1);
	Sendto_PC(USART1,"x: %d \r",(int)x);

	//Step 2
	temp_var2= pow(Dynamx_LinkFemur,2) + pow(x,2) - pow(Dynamx_LinkTibia,2);
	Sendto_PC(USART1,"temp_var2: %d \r",(int)temp_var2);

	temp_var3= 2*Dynamx_LinkFemur*x;
	Sendto_PC(USART1,"temp_var3: %d \r",(int)temp_var3);

	add_var1=temp_var2/temp_var3;
	Sendto_PC(USART1,"add_var1: %d \r",(int)add_var1);

	theta1= SpeedTrig_acos(add_var1)*RAD2DEG;
	Sendto_PC(USART1,"theta1: %d \r",(int)theta1);
//	theta1= RadToMicro(theta1);
//	Sendto_PC(USART1,"theta1: %d \r",(int)theta1);


	//Step3
//	temp_var4= SpeedTrig_sin(theta1)*x/Dynamx_LinkTibia;
	temp_var4= SpeedTrig_sin(theta1);
	Sendto_PC(USART1,"temp_var4: %d \r",(int)temp_var4);

	temp_var4= temp_var4*x;
	Sendto_PC(USART1,"temp_var4: %d \r",(int)temp_var4);

	temp_var4= temp_var4/Dynamx_LinkTibia;
	Sendto_PC(USART1,"temp_var4: %d \r",(int)temp_var4);


	theta2= asin(temp_var4)*RAD2DEG;
	Sendto_PC(USART1,"theta2: %d \r",(int)theta2);

	JointAngle.ThetaTibia= 180 - theta2;
//	JointAngle.ThetaTibia= theta2;

	add_var2= width/clearance;
	Sendto_PC(USART1,"add_var2: %d \r",(int)add_var2);
	theta4= atan(add_var2)*RAD2DEG;
	Sendto_PC(USART1,"theta4: %d \r",(int)theta4);
	JointAngle.ThetaFemur= theta4+theta1 - 90;


	//Calculating Coxa
	if(distance<=0)
	{
		distance= -distance;
		add_var3= width/distance;
		JointAngle.ThetaCoxa= -atan(add_var3)*RAD2DEG;
	}
	else
	{
		add_var3= width/distance;
		JointAngle.ThetaCoxa= atan(add_var3)*RAD2DEG;
	}


	Sendto_PC(USART1,"JointAngle.ThetaCoxa: %d \r",(int)JointAngle.ThetaCoxa);
	Sendto_PC(USART1,"JointAngle.ThetaFemur: %d \r",(int)JointAngle.ThetaFemur);
	Sendto_PC(USART1,"JointAngle.ThetaTibia: %d \r",(int)JointAngle.ThetaTibia);

	int IK_AngleCoxa = 150+ (int)JointAngle.ThetaCoxa;
	int IK_AngleFemur= 150+ (int)JointAngle.ThetaFemur;
	int IK_AngleTibia= 150+ (int)JointAngle.ThetaTibia;

	Sendto_PC(USART1,"IK_AngleCoxa: %d \r",(int)IK_AngleCoxa);
	Sendto_PC(USART1,"IK_AngleFemur: %d \r",(int)IK_AngleFemur);
	Sendto_PC(USART1,"IK_AngleTibia: %d \r\r\r",(int)IK_AngleTibia);


	HexJoint_Actuate(FRONT_LEFT_DX_TIBIA,IK_AngleTibia,500); //ditambah makin ke dalam
	HexJoint_Actuate(FRONT_LEFT_DX_FEMUR,IK_AngleFemur,500); //ditambah makin keatas
	HexJoint_Actuate(FRONT_LEFT_DX_COXA,IK_AngleCoxa,500);


	HexJoint_Actuate(REAR_LEFT_DX_TIBIA,IK_AngleTibia,500); //ditambah makin ke dalam
	HexJoint_Actuate(REAR_LEFT_DX_FEMUR,IK_AngleFemur,500); //ditambah makin keatas
	HexJoint_Actuate(REAR_LEFT_DX_COXA,IK_AngleCoxa,500);


	IK_AngleCoxa = 150- (int)JointAngle.ThetaCoxa;
	IK_AngleFemur= 150- (int)JointAngle.ThetaFemur;
	IK_AngleTibia= 150- (int)JointAngle.ThetaTibia;

	Sendto_PC(USART1,"IK_AngleCoxa: %d \r",(int)IK_AngleCoxa);
	Sendto_PC(USART1,"IK_AngleFemur: %d \r",(int)IK_AngleFemur);
	Sendto_PC(USART1,"IK_AngleTibia: %d \r\r\r",(int)IK_AngleTibia);


	HexJoint_Actuate(MIDDLE_RIGHT_DX_TIBIA,IK_AngleTibia,500); //ditambah makin ke dalam
	HexJoint_Actuate(MIDDLE_RIGHT_DX_FEMUR,IK_AngleFemur,500); //ditambah makin keatas
	HexJoint_Actuate(MIDDLE_RIGHT_DX_COXA,IK_AngleCoxa,500);

}


/*
 *  CONVERSION FROM OLD ALGORITHM
 */
void Dynamx_GenerateIK(int deflection_angle, int translation, float clearance)
{
	leg=clearance;
//	translation -=1;
    A_body = (float) translation;
    for(i=0;i<6;i++)
	{
	  ww[i] = (int)(alpha[i] - deflection_angle);			//hitung gamma = alpha - psi
	  //printf("%d \n",param->gamma);
	  // hitung beta tiap kaki
	  temp_var  = (float) (A_body * cos(ww[i] / rad2deg));	//temp_var = Ab*cos(gamma)
	  temp_var  = (float) (leg_norm[i] - temp_var);				//temp_var = L2 - temp_var
	  temp_var2 = (float) (A_body * sin(ww[i] / rad2deg));	//temp_var2 = Ab*sin(gamma)
	  temp_var  = (float) (temp_var2 / temp_var);				//var = temp_var2 / temp_var
	  temp_var  = (float) atan(temp_var);						//temp_var = arctan (temp_var)
	  beta[i] = (temp_var*rad2deg);							//beta[i] = temp_var
	  // hitung panjang kaki (L2')
	  temp_var  = (float) sin(ww[i] / rad2deg);				//temp_var = sin(gamma);
	  temp_var  = (float) (A_body * temp_var);					//temp_var = Ab * temp_var;
	  temp_var2 = (float) sin(beta[i] / rad2deg);				//temp_var2 = sin(alpha);
	  temp_var  = (float) (temp_var / temp_var2);				//temp_var  = temp_var/temp_var2
//	  leg_next[i] = temp_var-7;									// leg_next[i] = temp_var
	  leg_next[i] = temp_var;
//	  leg_next[i] = temp_var-7;
	}


    leg_next[0]+=2; //5
    leg_next[3]+=2; //5
    leg_next[1]-=3; //10

    leg_next[4]-=3; //10
    leg_next[2]-=7; //14
    leg_next[5]-=7; //14

}


void Dynamx_IK(char leg_pos,int *SPEED, float x, float w, float z)
{
	temp_angle.teta1  = x;

	Lsem = w;//(cos(temp_angle.teta1));
	Lsem -= lj;
	c1 = (la*la) + (lb*lb);
	c2 = 2*la*lb;
	temp_angle.teta3 = acos(((((Lsem*Lsem)+(z*z))-c1)/c2));

	c3=la+(lb*cos(temp_angle.teta3));
	c4=lb*sin(temp_angle.teta3);
	temp_angle.teta2 = atan((((z*c3)-(Lsem*c4))/((Lsem*c3)+(z*c4))));

	temp_angle.teta3 *= rad2deg;
	temp_angle.teta2 *= rad2deg;


	switch(leg_pos)
	{
		case FRONT_LEFT_DX      :   Sendto_PC(USART1,"===== FRONT LEFT LEG IK ===== \r");
								 HexJoint_Actuate(FRONT_LEFT_DX_COXA, 150-90+temp_angle.teta1, *SPEED);
								 HexJoint_Actuate(FRONT_LEFT_DX_FEMUR, 150+temp_angle.teta2, *SPEED);
								 HexJoint_Actuate(FRONT_LEFT_DX_TIBIA, 150+temp_angle.teta3, *SPEED);

                            	 break;

		case FRONT_RIGHT_DX     :   Sendto_PC(USART1,"===== FRONT RIGHT LEG IK ===== \r");
								 HexJoint_Actuate(FRONT_RIGHT_DX_COXA, 150+90-temp_angle.teta1, *SPEED);
		 	 	 	 	 	 	 HexJoint_Actuate(FRONT_RIGHT_DX_FEMUR, 150-temp_angle.teta2, *SPEED);
		 	 	 	 	 	 	 HexJoint_Actuate(FRONT_RIGHT_DX_TIBIA, 150-temp_angle.teta3, *SPEED);
                            	 break;

		case MIDDLE_LEFT_DX     :   Sendto_PC(USART1,"===== MIDDLE LEFT LEG IK ===== \r");
								 HexJoint_Actuate(MIDDLE_LEFT_DX_COXA, 150-90+temp_angle.teta1,*SPEED);
		 	 	 	 	 	 	 HexJoint_Actuate(MIDDLE_LEFT_DX_FEMUR, 150+temp_angle.teta2, *SPEED);
		 	 	 	 	 	 	 HexJoint_Actuate(MIDDLE_LEFT_DX_TIBIA, 150+temp_angle.teta3, *SPEED);
//		 	 	 	 	 	 	 HexJoint_Actuate(MIDDLE_LEFT_DX_FEMUR, 148+temp_angle.teta2, *SPEED);
//		 	 	 	 	 	 	 HexJoint_Actuate(MIDDLE_LEFT_DX_TIBIA, 152+temp_angle.teta3, *SPEED);
                            	 break;

		case MIDDLE_RIGHT_DX    :   Sendto_PC(USART1,"===== MIDDLE RIGHT LEG IK ===== \r");
								 HexJoint_Actuate(MIDDLE_RIGHT_DX_COXA, 150+90-temp_angle.teta1, *SPEED);
	 	 	 	 	 	 	 	 HexJoint_Actuate(MIDDLE_RIGHT_DX_FEMUR, 150-temp_angle.teta2, *SPEED);
	 	 	 	 	 	 	 	 HexJoint_Actuate(MIDDLE_RIGHT_DX_TIBIA, 150-temp_angle.teta3, *SPEED);
								 break;

		case REAR_LEFT_DX       :   Sendto_PC(USART1,"===== REAR LEFT LEG IK ===== \r");
								 HexJoint_Actuate(REAR_LEFT_DX_COXA, 150-90+temp_angle.teta1, *SPEED);
	 	 	 	 	 	 	 	 HexJoint_Actuate(REAR_LEFT_DX_FEMUR, 150+temp_angle.teta2, *SPEED);
	 	 	 	 	 	 	 	 HexJoint_Actuate(REAR_LEFT_DX_TIBIA, 150+temp_angle.teta3, *SPEED);
                            	 break;

		case REAR_RIGHT_DX      :   Sendto_PC(USART1,"===== REAR RIGHT LEG IK ===== \r");
								 HexJoint_Actuate(REAR_RIGHT_DX_COXA, 150+90-temp_angle.teta1, *SPEED);
	 	 	 	 	 	 	 	 HexJoint_Actuate(REAR_RIGHT_DX_FEMUR, 150-temp_angle.teta2, *SPEED);
	 	 	 	 	 	 	 	 HexJoint_Actuate(REAR_RIGHT_DX_TIBIA, 150-temp_angle.teta3, *SPEED);
                            	 break;
	}


		Sendto_PC(USART1,"JointAngle.ThetaCoxa: %d \r",(int)temp_angle.teta1);
		Sendto_PC(USART1,"JointAngle.ThetaFemur: %d \r",(int)temp_angle.teta2);
		Sendto_PC(USART1,"JointAngle.ThetaTibia: %d \r\r",(int)temp_angle.teta3);
}



/* func      : 	void Dynamx_MoveLeg(unsigned int leg_position, unsigned int *SPEED, unsigned int ThetaCoxa, unsigned int ThetaFemur, unsigned int ThetaTibia)
 * brief     : 	Control Hexapod Leg angle
 * param     :	unsigned int leg_position -> (FRONT_LEFT_DX_COXA,FRONT_LEFT_DX_FEMUR,FRONT_LEFT_DX_TIBIA)
 * 										  -> (FRONT_RIGHT_DX_COXA,FRONT_RIGHT_DX_FEMUR,FRONT_RIGHT_DX_TIBIA)
 * 			    unsigned int *SPEED		  -> 0~1023
 * 			    unsigned int ThetaCoxa	  -> 0-300 degrees
 * 			    unsigned int ThetaFemur   -> 0-300 degrees
 * 			    unsigned int ThetaTibia	  -> 0-300 degrees
 * retval    : 	N/A
 * Ver       : 2
 * written By: Ryan (Thursday, February 2nd 2017)
 * Revised By: Ver. 2 - Ryan (Monday, February 6th 2017)
 * 					- Speed parameter added
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_MoveLeg(unsigned int leg_position, int *SPEED, unsigned int ThetaCoxa, int ThetaFemur, unsigned int ThetaTibia)
{
//	lcd_gotoxy(0,3);sprintf(lcd,"Moveleg");lcd_putstr(lcd);

	switch(leg_position)
	{
		case FRONT_LEFT_DX      :   //Sendto_PC(USART1,"===== FRONT LEFT LEG IK ===== \r");
							 	 HexJoint_Actuate(FRONT_LEFT_DX_COXA, 150-90+ThetaCoxa, *SPEED);
							 	 HexJoint_Actuate(FRONT_LEFT_DX_FEMUR, 150+ThetaFemur, *SPEED);
							 	 HexJoint_Actuate(FRONT_LEFT_DX_TIBIA, 150+ThetaTibia, *SPEED);
//		 	 	 	 	 	 	 HexJoint_Actuate(FRONT_LEFT_DX_COXA, 153-90+ThetaCoxa, *SPEED);
//							 	 HexJoint_Actuate(FRONT_LEFT_DX_FEMUR, 148+ThetaFemur, *SPEED);
//							 	 HexJoint_Actuate(FRONT_LEFT_DX_TIBIA, 152+ThetaTibia, *SPEED);
							 	 break;

		case FRONT_RIGHT_DX     :   //Sendto_PC(USART1,"===== FRONT RIGHT LEG IK	 ===== \r");
							 	 HexJoint_Actuate(FRONT_RIGHT_DX_COXA, 150+90-ThetaCoxa, *SPEED);
							 	 HexJoint_Actuate(FRONT_RIGHT_DX_FEMUR, 150-ThetaFemur, *SPEED);
							 	 HexJoint_Actuate(FRONT_RIGHT_DX_TIBIA, 150-ThetaTibia, *SPEED);
//							 	 HexJoint_Actuate(FRONT_RIGHT_DX_COXA, 148+90-ThetaCoxa, *SPEED);
//							 	 HexJoint_Actuate(FRONT_RIGHT_DX_FEMUR, 150-ThetaFemur, *SPEED);
//							 	 HexJoint_Actuate(FRONT_RIGHT_DX_TIBIA, 150-ThetaTibia, *SPEED);
							 	 break;

		case MIDDLE_LEFT_DX     :   //Sendto_PC(USART1,"===== MIDDLE LEFT LEG IK ===== \r");
							 	 HexJoint_Actuate(MIDDLE_LEFT_DX_COXA, 150-90+ThetaCoxa, *SPEED);
							 	 HexJoint_Actuate(MIDDLE_LEFT_DX_FEMUR, 150+ThetaFemur, *SPEED);
							 	 HexJoint_Actuate(MIDDLE_LEFT_DX_TIBIA, 150+ThetaTibia, *SPEED);
//								 HexJoint_Actuate(MIDDLE_LEFT_DX_COXA, 153-90+ThetaCoxa, *SPEED);
//							 	 HexJoint_Actuate(MIDDLE_LEFT_DX_FEMUR, 147+ThetaFemur, *SPEED);
//							 	 HexJoint_Actuate(MIDDLE_LEFT_DX_TIBIA, 153+ThetaTibia, *SPEED);
							 	 break;

		case MIDDLE_RIGHT_DX    :   //Sendto_PC(USART1,"===== MIDDLE RIGHT LEG IK ===== \r");
							 	 HexJoint_Actuate(MIDDLE_RIGHT_DX_COXA, 150+90-ThetaCoxa, *SPEED);
							 	 HexJoint_Actuate(MIDDLE_RIGHT_DX_FEMUR, 150-ThetaFemur, *SPEED);
							 	 HexJoint_Actuate(MIDDLE_RIGHT_DX_TIBIA, 150-ThetaTibia, *SPEED);
//								 HexJoint_Actuate(MIDDLE_RIGHT_DX_COXA, 148+90-ThetaCoxa, *SPEED);
//								 HexJoint_Actuate(MIDDLE_RIGHT_DX_FEMUR, 150-ThetaFemur, *SPEED);
//								 HexJoint_Actuate(MIDDLE_RIGHT_DX_TIBIA, 150-ThetaTibia, *SPEED);
							 	 break;

		case REAR_LEFT_DX       :   //Sendto_PC(USART1,"===== REAR LEFT LEG IK ===== \r");
							 	 HexJoint_Actuate(REAR_LEFT_DX_COXA, 150-90+ThetaCoxa, *SPEED);
							 	 HexJoint_Actuate(REAR_LEFT_DX_FEMUR, 150+ThetaFemur, *SPEED);
							 	 HexJoint_Actuate(REAR_LEFT_DX_TIBIA, 150+ThetaTibia, *SPEED);
//								 HexJoint_Actuate(REAR_LEFT_DX_COXA, 153-90+ThetaCoxa, *SPEED);
//							 	 HexJoint_Actuate(REAR_LEFT_DX_FEMUR, 148+ThetaFemur, *SPEED);
//							 	 HexJoint_Actuate(REAR_LEFT_DX_TIBIA, 152+ThetaTibia, *SPEED);
							 	 break;

		case REAR_RIGHT_DX      :   //Sendto_PC(USART1,"===== REAR RIGHT LEG IK ===== \r");
							 	 HexJoint_Actuate(REAR_RIGHT_DX_COXA, 150+90-ThetaCoxa, *SPEED);
							 	 HexJoint_Actuate(REAR_RIGHT_DX_FEMUR, 150-ThetaFemur, *SPEED);
							 	 HexJoint_Actuate(REAR_RIGHT_DX_TIBIA, 150-ThetaTibia, *SPEED);
//								 HexJoint_Actuate(REAR_RIGHT_DX_COXA, 148+90-ThetaCoxa, *SPEED);
//								 HexJoint_Actuate(REAR_RIGHT_DX_FEMUR, 150-ThetaFemur, *SPEED);
//								 HexJoint_Actuate(REAR_RIGHT_DX_TIBIA, 150-ThetaTibia, *SPEED);
							 	 break;
	}

}

/* func      : 	void Dynamx_Mov_Static(unsigned int SPEED, unsigned int IK_STAT)
 * brief     : 	Dynamixel Hexapod Static gait
 * param     :	unsigned int IK_STAT
 * 					 IKCALC_ENABLE	1  -> Calculate all joint angle with Inverse Kinematics
 * 					 IKCALC_DISABLE	0  -> Bypass the Inverse Kinematics calculation,
 * 					 						move servo with predetermined value
 * retval    : 	N/A
 * Ver       : 2
 * written By: Ryan (Thursday, February 2nd 2017)
 * Revised By: Ver. 2 - Ryan (Monday, February 6th 2017)
 * 					- Speed parameter added
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_Mov_Static(int SPEED, unsigned int IK_STAT)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW MOV STATIC");lcd_putstr(lcd);

	switch(IK_STAT)
	{
		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,0,8);
		    delay_ms(50);

//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,7,leg+0.4);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,7,leg+0.4);
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,7,leg+0.4);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,7,leg+0.4);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,7,leg+0.4);
//			Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,7,leg+0.4);

//			delay_ms(2000);

			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,12,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,12,leg-2);
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,12,leg-2);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,12,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,12,leg-2);
			Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,12,leg-2);

//			delay_ms(2000);

//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,3,leg);
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,3,leg); //TENGAH MENAPAK
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,3,leg);
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,3,leg);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,3,leg);
//		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,3,leg);

//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,150,4,leg-1);
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,150,4,leg-1); //TENGAH MENAPAK
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,150,4,leg-1);
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,150,4,leg-1);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,150,4,leg-1);
//		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,150,4,leg-1);

//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,90,3,leg-2);
//		    Dynamx_IK(MIDDLE_LEFT_DX,90,3,leg-2); //TENGAH MENAPAK
//		    Dynamx_IK(REAR_RIGHT_DX,90,3,leg-2);
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,90,3,leg-2);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,90,3,leg-2);
//		    Dynamx_IK(REAR_LEFT_DX,90,2,leg-2);

		}break;

		case IKCALC_DISABLE:
		{
			//===FIX=== body agak turun ====
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);

//			//2
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);


		}break;
	}

}

void Dynamx_Mov_Static_Low(int SPEED)
{
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,34,128);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,34,128);
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,34,128);

	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,34,128);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,34,128);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,34,128);
}

/* func      : 	void Dynamx_MovFwd3cm (int distance, int SPEED, int IKCALC_STAT)
 * brief     : 	Dynamixel Hexapod Forward locomotion using tripod gait
 * param     :	unsigned int distance  	-> Travel distance multiplication of 3
 * 				unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int IKCALC_STAT
 * 					 IKCALC_ENABLE	1  	-> Calculate all joint angle with Inverse Kinematics
 * 					 IKCALC_DISABLE	0  	-> Bypass the Inverse Kinematics calculation,
 * 					 						move servo with predetermined value
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Thursday, February 2nd 2017)
 * Revised By: N/A
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_MovFwd3cm (unsigned int distance, int SPEED, int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Forward Movement 3 cm \r");
	int limit= distance/3;
	int loop;

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,3,9);
			delay_ms(50);
			for (loop=1;loop<=limit;loop++)
				{
					Sendto_PC(USART1,"================ START OF FORWARD TRIPOD GAIT SEQUENCES ================ \r");

//					Sendto_PC(USART1,"<======== STEP 1 \r");
//					//1
//				    //Tripod A
//				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1);
//				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); //DEPAN MENAPAK
//				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1);
//
//				    //Tripod B
//				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);
//				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
//				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
////				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 2 \r");
				    //2
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 3 \r");
				    //3
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); //BELAKANG MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
				    //4

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);

				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

//				    delay_ms(1000);

				    Sendto_PC(USART1,"<======== STEP 5 \r");
				    //5
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 6 \r");
				    //6
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //DEPAN ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

					Sendto_PC(USART1,"<======== STEP 1 \r");
					//1
					//Tripod A
					Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1);
					Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); //DEPAN MENAPAK
					Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1);

					//Tripod B
					Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);
					Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
					Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
//				    delay_ms(1000);

				    Sendto_PC(USART1,"================ END OF FORWARD TRIPOD GAIT SEQUENCES ================ \r\r");

				}
		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{
//					//1
//					//TRIPOD A
//					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105,14,108);
//					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,14,108);
//					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98,14,108);
//
//					//TRIPOD B
//					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74,32,114);
//					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69,32,114);
//					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81,32,114);

					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

					//2
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,14,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,14,108);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,14,108);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,30,114);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,31,114);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,32,114);

//					delay_ms(1500);

					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

					//3
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,77,14,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,74,14,108);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81,14,108);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,102,30,114);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,105,31,114);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98,32,114);

//					delay_ms(1500);

					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

					//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,102,14,108);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,105,14,108);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98,14,108);

					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,77,30,114);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,74,31,114);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81,32,114);

//					delay_ms(1500);

					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

					//5
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,30,114);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,31,114);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,32,114);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,14,108);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,14,108);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,14,108);

//					delay_ms(1500);

					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

					//6
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,102,30,114);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,105,31,114);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98,32,114);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,77,14,108);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,74,14,108);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81,14,108);

//					delay_ms(1500);

					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

					//1
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,102,14,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,105,14,108);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98,14,108);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,77,30,114);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,74,31,114);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81,32,114);

//					delay_ms(1500);
				}
		}break;
	}
}


void Dynamx_MovFwd4cm (unsigned int distance, int SPEED, int IKCALC_STAT)
{

//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Forward");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"Movement 4 cm");lcd_putstr(lcd);
//	Sendto_PC(USART1,"BW Forward Movement 4 cm \r");
	int limit= distance/4;
	int loop;

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,4,9);
			delay_ms(50);
			for (loop=1;loop<=limit;loop++)
				{
					Sendto_PC(USART1,"================ START OF FORWARD TRIPOD GAIT SEQUENCES ================ \r");

					Sendto_PC(USART1,"<======== STEP 1 \r");
					//1
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); //DEPAN MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 2 \r");
				    //2
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 3 \r");
				    //3
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); //BELAKANG MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90+beta[2],1,leg-2);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
				    //4

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);

				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

//				    delay_ms(1000);

				    Sendto_PC(USART1,"<======== STEP 5 \r");
				    //5
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,4,leg-1);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 6 \r");
				    //6
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //DEPAN ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"================ END OF FORWARD TRIPOD GAIT SEQUENCES ================ \r\r");

				}
		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//BW_Tracer_Check();
//				delay_ms(500);
				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//				delay_ms(500);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
//				delay_ms(500);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]-7,SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
//				delay_ms(500);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]-7,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]-10,SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]-10,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]-7,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]-7,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(500);

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(500);

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(500);

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(500);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//				delay_ms(500);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//				delay_ms(500);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
//				delay_ms(500);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]-7,SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
//				delay_ms(500);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]-7,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]-10,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]-7,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]-7,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(500);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(500);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(500);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(500);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				//BW_Tracer_Check();
				if (Ping[PING_FRONT]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				}
		}break;
	}

//	Bumper_Action();
}

void Dynamx_MovFwd4cm_slow(unsigned int distance, int SPEED, int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Forward Movement 4 cm \r");
	int limit= distance/4;
	int loop;

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,4,9);
			delay_ms(50);
			for (loop=1;loop<=limit;loop++)
				{
					Sendto_PC(USART1,"================ START OF FORWARD TRIPOD GAIT SEQUENCES ================ \r");


					Sendto_PC(USART1,"<======== STEP 1 \r");
					//1
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); //DEPAN MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90-beta[2],1,leg-2);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 2 \r");
				    //2
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 3 \r");
				    //3
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); //BELAKANG MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
				    //4

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);

				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

//				    delay_ms(1000);

				    Sendto_PC(USART1,"<======== STEP 5 \r");
				    //5
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"<======== STEP 6 \r");
				    //6
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //DEPAN ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
//				    delay_ms(1000);

					//BW_Tracer_Check();
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				    Sendto_PC(USART1,"================ END OF FORWARD TRIPOD GAIT SEQUENCES ================ \r\r");

				}
		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{

				if((SHARP[SHARP_FRONT_R]<25) || (SHARP[SHARP_FRONT_L]<25)){break;}//Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);break;}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//BW_Tracer_Check();
//				delay_ms(500);

				if((SHARP[SHARP_FRONT_R]<25) || (SHARP[SHARP_FRONT_L]<25)){break;}//Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);break;}

				if (Ping[PING_FRONT]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//				delay_ms(500);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
//				delay_ms(500);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]-7,SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
//				delay_ms(500);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]-7,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]-10,SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);

				if((SHARP[SHARP_FRONT_R]<25) || (SHARP[SHARP_FRONT_L]<25)){break;}//Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);break;}

				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]-10,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]-7,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]-7,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(500);

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(500);

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(500);

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(500);

				if((SHARP[SHARP_FRONT_R]<25) || (SHARP[SHARP_FRONT_L]<25)){break;}//Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);break;}

				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//				delay_ms(500);

				if((SHARP[SHARP_FRONT_R]<25) || (SHARP[SHARP_FRONT_L]<25)){break;}//Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);break;}

				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//				delay_ms(500);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
//				delay_ms(500);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]-7,SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
//				delay_ms(500);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]-7,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);

				if((SHARP[SHARP_FRONT_R]<25) || (SHARP[SHARP_FRONT_L]<25)){break;}//Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);break;}

				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]-10,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]-7,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]-7,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(500);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(500);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(500);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(500);

				if((SHARP[SHARP_FRONT_R]<25) || (SHARP[SHARP_FRONT_L]<25)){break;}//Dynamx_Mov_Static(HEXSPD_MEDFAST,IKCALC_DISABLE);break;}

				//BW_Tracer_Check();
				if (Ping[PING_FRONT]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				}
		}break;
	}

//	Bumper_Action();

}


void Dynamx_MovFwd1cm (unsigned int distance, int SPEED, int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Forward Movement 3 cm \r");
	int limit= distance/1;
	int loop;

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,1,9);
			delay_ms(50);
			for (loop=1;loop<=limit;loop++)
				{
					Sendto_PC(USART1,"================ START OF FORWARD TRIPOD GAIT SEQUENCES ================ \r");

					Sendto_PC(USART1,"<======== STEP 1 \r");
					//1
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); //DEPAN MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
//				    delay_ms(1000);


				    Sendto_PC(USART1,"<======== STEP 2 \r");
				    //2
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);
//				    delay_ms(1000);

				    Sendto_PC(USART1,"<======== STEP 3 \r");
				    //3
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); //BELAKANG MENAPAK
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
//				    delay_ms(1000);

				    Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
				    //4

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);

				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2);


//				    delay_ms(1000);

				    Sendto_PC(USART1,"<======== STEP 5 \r");
				    //5
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);
//				    delay_ms(1000);

				    Sendto_PC(USART1,"<======== STEP 6 \r");
				    //6
				    //Tripod A
				    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);
				    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //DEPAN ANGKAT
				    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);

				    //Tripod B
				    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);
				    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
				    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
//				    delay_ms(1000);

				    Sendto_PC(USART1,"================ END OF FORWARD TRIPOD GAIT SEQUENCES ================ \r\r");

				}
		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{
					//1
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105,14,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,14,108);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98,14,108);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74,32,114);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69,32,114);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81,32,114);

					//2
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,14,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,14,108);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,14,108);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,32,114);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,32,114);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,32,114);

					//3
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74,14,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69,14,108);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81,14,108);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105,32,114);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,32,114);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98,32,114);

					//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105,14,108);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,14,108);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98,14,108);

					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74,32,114);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69,32,114);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81,32,114);

					//5
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,32,114);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,32,114);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,32,114);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,14,108);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,14,108);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,14,108);

					//6
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105,32,114);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,32,114);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98,32,114);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74,14,108);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69,14,108);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81,14,108);
				}
		}break;
	}
}
/* func      : 	void Dynamx_MovBwd (int distance, int SPEED, int IKCALC_STAT)
 * brief     : 	Dynamixel Hexapod Backward locomotion using tripod gait
 * param     :	unsigned int distance  	-> Travel distance multiplication of 3
 * 				unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int IKCALC_STAT
 * 					 IKCALC_ENABLE	1  	-> Calculate all joint angle with Inverse Kinematics
 * 					 IKCALC_DISABLE	0  	-> Bypass the Inverse Kinematics calculation,
 * 					 						move servo with predetermined value
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Thursday, February 2nd 2017)
 * Revised By: N/A
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_MovBwd (int distance, int SPEED, int IKCALC_STAT)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Backward");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"Movement");lcd_putstr(lcd);
//	Sendto_PC(USART1,"BW Backward Movement cm \r");
	int limit= distance/3;
	int loop;

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{

			Dynamx_GenerateIK(0,3,8);
			delay_ms(50);
			for (loop=1;loop<=limit;loop++)
				{
					//DEFAULT
					Sendto_PC(USART1,"================ START OF BACKWARD TRIPOD GAIT SEQUENCES ================ \r");

//					Sendto_PC(USART1,"<======== STEP 1 \r");
//					//1
//					//Tripod A
//					Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);
//			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); //BELAKANG MENAPAK
//			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1);
//
//			    	//Tripod B
//			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);
//			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
//			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
//
//			    	Sendto_PC(USART1,"<======== STEP 2 \r");
//			    	//2
//			    	//Tripod A
//			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1);
//			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
//			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1);
//
//			    	//Tripod B
//			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
//			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
//			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);
//
//			    	Sendto_PC(USART1,"<======== STEP 3 \r");
//			    	//3
//			    	//Tripod A
//			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1);
//			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); //DEPAN MENAPAK
//			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1);
//
//			    	//Tripod B
//			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);
//			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
//			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
//
//
//			    	Sendto_PC(USART1,"<======== STEP 4 \r");
//
//			    	//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//			    	//Tripod B
//			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);
//			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
//			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
//
//			    	//Tripod A
//			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);
//			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //DEPAN ANGKAT
//			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);
//
//
//			    	Sendto_PC(USART1,"<======== STEP 5 \r");
//			    	//5
//			    	//Tripod A
//			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2);
//			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
//			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2);
//
//			    	//Tripod B
//			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
//			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
//			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);
//
//			    	Sendto_PC(USART1,"<======== STEP 6 \r");
//			    	//6
//			    	//Tripod A
//			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);
//			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
//			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2);
//
//			    	//Tripod B
//			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);
//			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
//			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);

					//VER 2
					Sendto_PC(USART1,"<======== STEP 1 \r");
					//1
					//Tripod A
					Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],7,leg+0.4);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],7,leg+0.4); //BELAKANG MENAPAK
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],7,leg+0.4);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],3,leg);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],3,leg);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],3,leg);

			    	Sendto_PC(USART1,"<======== STEP 2 \r");
			    	//2
			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,7,leg+0.4);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,7,leg+0.4); //TENGAH MENAPAK
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,7,leg+0.4);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,3,leg);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,3,leg);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,3,leg);

			    	Sendto_PC(USART1,"<======== STEP 3 \r");
			    	//3
			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],7,leg+0.4);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],7,leg+0.4); //DEPAN MENAPAK
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],7,leg+0.4);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],3,leg);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],3,leg);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],3,leg);


			    	Sendto_PC(USART1,"<======== STEP 4 \r");

			    	//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],7,leg+0.4);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],7,leg+0.4);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],7,leg+0.4);

			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],3,leg);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],3,leg); //DEPAN ANGKAT
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],3,leg);


			    	Sendto_PC(USART1,"<======== STEP 5 \r");
			    	//5
			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,3,leg);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,3,leg); //TENGAH ANGKAT
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,3,leg);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,7,leg+0.4);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,7,leg+0.4);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,7,leg+0.4);

			    	Sendto_PC(USART1,"<======== STEP 6 \r");
			    	//6
			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],3,leg);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],3,leg); //BELAKANG ANGKAT
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],3,leg);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],7,leg+0.4);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],7,leg+0.4);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],7,leg+0.4);

			    	Sendto_PC(USART1,"================ END OF BACKWARD TRIPOD GAIT SEQUENCES ================ \r\r");
				}

		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);
//				delay_ms(5000);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKFWD_COXA_L2[0],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKFWD_TIBIA_L2[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKFWD_COXA_R2[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKFWD_COXA_L2[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKFWD_TIBIA_L2[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKFWD_COXA_R2[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKFWD_TIBIA_R2[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKFWD_COXA_L2[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKFWD_TIBIA_L2[1]);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKFWD_COXA_R2[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKFWD_TIBIA_R2[2]);
//				delay_ms(5000);

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKFWD_COXA_L1[0],SUDUT_STATIC_BWD[10]-5,SUDUT_STATIC_BWD[11]-IKFWD_TIBIA_L1[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKFWD_COXA_R1[1],SUDUT_STATIC_BWD[13]-3,SUDUT_STATIC_BWD[14]-IKFWD_TIBIA_R1[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKFWD_COXA_L1[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKFWD_TIBIA_L1[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKFWD_COXA_R1[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKFWD_TIBIA_R1[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKFWD_COXA_L1[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKFWD_TIBIA_L1[1]);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKFWD_COXA_R1[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKFWD_TIBIA_R1[2]);
//				delay_ms(5000);

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKFWD_COXA_L[0],SUDUT_STATIC_BWD[10]-15,SUDUT_STATIC_BWD[11]-IKFWD_TIBIA_L[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKFWD_COXA_R[1],SUDUT_STATIC_BWD[13]-7,SUDUT_STATIC_BWD[14]-IKFWD_TIBIA_R[1]);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKFWD_COXA_L[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKFWD_TIBIA_L[0]);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKFWD_COXA_R[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKFWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKFWD_TIBIA_L[1]);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKFWD_COXA_R[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKFWD_TIBIA_R[2]);
//				delay_ms(5000);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKFWD_COXA_R[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKFWD_COXA_L[1],SUDUT_STATIC_BWD[4]-7,SUDUT_STATIC_BWD[5]-IKFWD_TIBIA_L[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKFWD_COXA_R[0],SUDUT_STATIC_BWD[7]-15,SUDUT_STATIC_BWD[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKFWD_COXA_L[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKFWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKFWD_COXA_L[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//				delay_ms(5000);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKFWD_COXA_R1[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKFWD_TIBIA_R1[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKFWD_COXA_L1[1],SUDUT_STATIC_BWD[4]-3,SUDUT_STATIC_BWD[5]-IKFWD_TIBIA_L1[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKFWD_COXA_R1[0],SUDUT_STATIC_BWD[7]-7,SUDUT_STATIC_BWD[8]-IKFWD_TIBIA_R1[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKFWD_COXA_L1[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKFWD_COXA_R1[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKFWD_COXA_L1[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//				delay_ms(5000);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKFWD_COXA_R2[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKFWD_TIBIA_R2[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKFWD_COXA_L2[1],SUDUT_STATIC_BWD[4]-1,SUDUT_STATIC_BWD[5]-IKFWD_TIBIA_L2[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKFWD_COXA_R2[0],SUDUT_STATIC_BWD[7]-3,SUDUT_STATIC_BWD[8]-IKFWD_TIBIA_R2[2]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKFWD_COXA_L2[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKFWD_COXA_R2[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKFWD_COXA_L2[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//				delay_ms(5000);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
				//BW_Tracer_Check();
//				delay_ms(5000);

				if (Ping[PING_REAR]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKFWD_COXA_R2[0],SUDUT_STATIC_BWD[1]-3,SUDUT_STATIC_BWD[2]-IKFWD_TIBIA_R2[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKFWD_COXA_L2[1],SUDUT_STATIC_BWD[4]-1,SUDUT_STATIC_BWD[5]-IKFWD_TIBIA_L2[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKFWD_COXA_R2[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKFWD_COXA_L2[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKFWD_TIBIA_L2[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKFWD_COXA_R2[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKFWD_TIBIA_R2[1]);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKFWD_COXA_L2[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKFWD_TIBIA_L2[2]);
//				delay_ms(5000);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKFWD_COXA_R1[0],SUDUT_STATIC_BWD[1]-7,SUDUT_STATIC_BWD[2]-IKFWD_TIBIA_R1[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKFWD_COXA_L1[1],SUDUT_STATIC_BWD[4]-3,SUDUT_STATIC_BWD[5]-IKFWD_TIBIA_L1[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKFWD_COXA_R1[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKFWD_COXA_L1[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKFWD_TIBIA_L1[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKFWD_COXA_R1[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKFWD_TIBIA_R1[1]);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKFWD_COXA_L1[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKFWD_TIBIA_L1[2]);
//				delay_ms(5000);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKFWD_COXA_R[0],SUDUT_STATIC_BWD[1]-15,SUDUT_STATIC_BWD[2]-IKFWD_TIBIA_R[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKFWD_COXA_L[1],SUDUT_STATIC_BWD[4]-7,SUDUT_STATIC_BWD[5]-IKFWD_TIBIA_L[1]);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKFWD_COXA_R[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKFWD_COXA_L[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKFWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKFWD_TIBIA_R[1]);	//belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKFWD_COXA_L[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(5000);

				if (Ping[PING_REAR]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKFWD_COXA_R[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKFWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKFWD_COXA_R[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKFWD_COXA_L[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKFWD_COXA_R[1],SUDUT_STATIC_BWD[13]-7,SUDUT_STATIC_BWD[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKFWD_COXA_L[0],SUDUT_STATIC_BWD[16]-15,SUDUT_STATIC_BWD[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(5000);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKFWD_COXA_R1[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKFWD_COXA_L1[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKFWD_COXA_R1[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKFWD_COXA_L1[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKFWD_TIBIA_L1[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKFWD_COXA_R1[1],SUDUT_STATIC_BWD[13]-3,SUDUT_STATIC_BWD[14]-IKFWD_TIBIA_R1[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKFWD_COXA_L1[0],SUDUT_STATIC_BWD[16]-7,SUDUT_STATIC_BWD[17]-IKFWD_TIBIA_L1[2]);
//				delay_ms(5000);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]-1,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]-3,SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
//				delay_ms(5000);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

/*	// MIRING KE KANAN BELAKANG
 * //				====== Z=35 TIBIA Z=25 ======
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);


				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;


				//4
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);		//depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]);
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]-5);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]-5);	//belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]+5);
				//					delay_ms(2000);

				//4
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);		//depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]);
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]-5);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]-5);	//belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]+5);
				//					delay_ms(2000);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]);	//belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]);	//belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

				if (Ping[PING_REAR]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]-5);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]-5);	//belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]+5);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]-5);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]-5);	//belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]+5);

				//BW_Tracer_Check();
				if (Ping[PING_REAR]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);	//belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);	//belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/

/*	MUNDUR DOUBLE STEP
 * //	zR = 15 ZL = 12
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				//5
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);


				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76,35,98); //belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
				//					delay_ms(2000);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99,24,117);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96,20,91);

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76,35,98); //belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
				//					delay_ms(2000);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99,24,117);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96,20,91);

				if (Ping[PING_REAR]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76,20,103); //belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96,35,122);

				//					delay_ms(2000);

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76,20,103); //belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96,35,122);
				if (Ping[PING_REAR]<=15)break;
				//					delay_ms(2000);
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//TRIPOD A kaki 5cm

				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104,20,103); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84,39,89);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81,35,122);
				//					delay_ms(2000);
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,20,102); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84,39,88);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81,35,120);
				//					delay_ms(2000);
				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104,35,120); //depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84,24,91);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81,20,115);
				//					delay_ms(2000);

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104,35,120); //depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84,24,91);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81,20,115);

				//					delay_ms(2000);
				if (Ping[PING_REAR]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/
/*
				//	zR = 15 ZL = 15
				//5
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);

				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,35,97); //belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
				//					delay_ms(2000);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,24,122);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,20,87);

				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,35,97); //belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
				//					delay_ms(2000);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,24,122);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,20,87);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,20,102); //belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,35,122);

				//					delay_ms(2000);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,20,102); //belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,35,122);

				//					delay_ms(2000);


				//TRIPOD A kaki 5cm

				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
				//BW_Tracer_Check();

				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,20,102); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,39,84);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,35,122);
				//					delay_ms(2000);
				//BW_Tracer_Check();

				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,20,102); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,39,84);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,35,122);
				//					delay_ms(2000);
				//BW_Tracer_Check();


				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,35,120); //depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,24,89);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,20,117);

				//					delay_ms(2000);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,35,120); //depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,24,89);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,20,117);

				//					delay_ms(2000);
*/
/*//			====== Z=35 TIBIA Z=25 =======
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,35,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,35,120); //tengah angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,38,126);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);

				//					delay_ms(2000);

				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,78,35,67);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,55,35,93); //belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,48,38,130);
				//					delay_ms(2000);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,132,24,122);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,125,20,103); //depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,102,20,71);


				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,78,23,72);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,55,20,98); //belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,48,20,125);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,132,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,125,35,128); //depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,102,35,122);

				//					delay_ms(2000);

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//TRIPOD A kaki 5cm

				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
				//BW_Tracer_Check();

				//delay_ms(2000);
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,132,20,125);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,125,20,98); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,102,23,72);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,48,39,64);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,55,35,98); //belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,35,129);
				//					delay_ms(2000);
				//BW_Tracer_Check();


				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,132,35,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,125,35,120); //depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,102,38,126);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,48,24,69);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,55,20,103); //belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,20,124);

				//					delay_ms(2000);


				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/
/*
				//2
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,5,95);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,5,100);
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,5,100);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,15,100);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,15,105);
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,15,105);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98,5,77);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,112,5,97); //depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,107,5,110);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,73,15,100);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,68,15,105); //belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,82,15,105);
				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,73,5,105);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,68,5,97);	// belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,82,5,82);

				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98,15,100);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,112,15,105); //depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,107,15,105);

				//5
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,15,100);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,15,105);	//tengah angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,15,105);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,5,95);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,5,100);	//tengah menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,5,100);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,73,15,100);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,68,15,105);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,82,15,105);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98,5,77);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,112,5,97);	//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,107,5,110);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,73,5,105);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,68,5,97);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,82,5,82);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98,15,100);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,112,15,105);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,107,15,105);
*/
//				//2
//				//TRIPOD A
//				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,5,95);
//				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,5,100);
//				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,5,100);
//
//				//TRIPOD B
//				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,15,100);
//				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,15,105);
//				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,15,105);
//
//				//3
//				//TRIPOD A
//				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,101,3,108);
//				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,5,98); //depan menapak
//				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,97,3,82);
//
//				//TRIPOD B
//				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,83,15,87);
//				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,15,98); //belakang angkat
//				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,79,15,103);
//				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//				//TRIPOD B
//				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,83,3,87);
//				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,5,98);	// belakang menapak
//				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,79,3,103);
//
//				//TRIPOD A
//				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,101,15,108);
//				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,15,98); //depan angkat
//				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,97,15,82);
//
//				//5
//				//TRIPOD A
//				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,15,100);
//				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,15,105);	//tengah angkat
//				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,15,105);
//
//				//TRIPOD B
//				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,5,95);
//				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,5,100);	//tengah menapak
//				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,5,100);
//
//				//6
//				//TRIPOD A
//				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,83,15,87);
//				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,15,98);	//belakang angkat
//				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,79,15,103);
//
//				//TRIPOD B
//				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,101,3,108);
//				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,107,5,98);	//depan menapak
//				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,97,3,82);
//
//				//1
//				//TRIPOD A
//				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,83,3,87);
//				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,5,98);	//belakang menapak
//				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,79,3,103);
//
//				//TRIPOD B
//				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,101,15,108);
//				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,107,15,98);	//depan angkat
//				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,97,15,82);

/*
  	  	  	  	//	USED NOW

				//2
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,5,95);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,5,100);
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,5,100);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,15,100);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,15,105);
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,15,105);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,5,82);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,5,98); //depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,5,109);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,15,100);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,15,105); //belakang angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,15,105);
				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,5,104);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,5,98);	// belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,5,87);

				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,15,100);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,15,105); //depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,15,105);

				//5
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,15,100);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,15,105);	//tengah angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,15,105);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,5,95);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,5,100);	//tengah menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,5,100);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,15,100);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,15,105);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,15,105);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,5,82);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,107,5,98);	//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,5,109);

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,5,104);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,5,98);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,5,87);

				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,15,100);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,107,15,105);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,15,105);

*/
				}

		}break;
	}
}


/* func      : 	void Dynamx_Rot_Right(int degree, int SPEED, int IKCALC_STAT)
 * brief     : 	Dynamixel Hexapod Rotate Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEXSTEP_CLOSE, HEXSTEP_MED, HEXSTEP_FAR
 * 				unsigned int IKCALC_STAT
 * 					 IKCALC_ENABLE	1  	-> Calculate all joint angle with Inverse Kinematics
 * 					 IKCALC_DISABLE	0  	-> Bypass the Inverse Kinematics calculation,
 * 					 						move servo with predetermined value
 * retval    : 	N/A
 * Ver       : 2
 * written By: Ryan (Thursday, February 2nd 2017)
 * Revised By:
 * 				Ver 2. Ryan (Thursday, February 9th 2017)
 * 					Step parameter added
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_Rot_Right(int SPEED,  int STEP, int IKCALC_STAT)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Rotate Right");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"Movement");lcd_putstr(lcd);
//	Sendto_PC(USART1,"BW Rotate Right Movement \r");
//	int limit= degree/3;
//	int loop;

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{

			Dynamx_GenerateIK(0,STEP,8);
//			delay_ms(50);
		    Sendto_PC(USART1,"<======== STEP 2 \r");
		    //2
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,3,leg); //TENGAH MENAPAK
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,3,leg); 						//TENGAH MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,3,leg); //TENGAH MENAPAK

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,1,leg-1);

//		    delay_ms(1000);

		    Sendto_PC(USART1,"<======== STEP 3 \r");
		    //3
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],3,leg); //DEPAN MENAPAK
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],3,leg); 				//BELAKANG MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],3,leg); //DEPAN MENAPAK

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],1,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90+beta[2],1,leg-1);

		    Sendto_PC(USART1,"<======== STEP 4 \r");

		    //4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],3,leg);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],3,leg);
		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90+beta[2],3,leg);
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],1,leg-1); //DEPAN ANGKAT
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-1); 				//BELAKANG ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],1,leg-1); //DEPAN ANGKAT

		    Sendto_PC(USART1,"<======== STEP 5 \r");
		    //5
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-1); //TENGAH ANGKAT
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-1); 						//TENGAH ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-1); //TENGAH ANGKAT

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,3,leg);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,3,leg);
		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,3,leg);

//		    delay_ms(1000);

		    Sendto_PC(USART1,"<======== STEP 6 \r");
		    //6
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],1,leg-1); //BELAKANG ANGKAT
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-1); 				//BELAKANG ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],1,leg-1);  //BELAKANG ANGKAT

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],3,leg);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],3,leg);
		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90-beta[2],3,leg);

//		    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 1 \r");
			//1
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],3,leg); //BELAKANG MENAPAK
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],3,leg); 				//DEPAN MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],3,leg);  //BELAKANG MENAPAK

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90-beta[2],1,leg-1);
		}break;

		case IKCALC_DISABLE:
		{
			if(STEP==HEXSTEP_FAR)
			{
				IKROT_COXA[0]=31;IKROT_COXA[1]=29;// MOV ROT ZCOXA_L = 15
				IKROT_COXA1[0]=21;IKROT_COXA1[1]=19;// MOV ROT ZCOXA_L = 10
				IKROT_COXA2[0]=11;IKROT_COXA2[1]=10;// MOV ROT ZCOXA_L = 5
			}
			else if(STEP==HEXSTEP_MED)
			{
				IKROT_COXA[0]=21;IKROT_COXA[1]=19;// MOV ROT ZCOXA_L = 10
				IKROT_COXA1[0]=13;IKROT_COXA1[1]=12;// MOV ROT ZCOXA_L = 6
				IKROT_COXA2[0]=7;IKROT_COXA2[1]=6;// MOV ROT ZCOXA_L = 3
			}
			else if(STEP==HEXSTEP_CLOSE)
			{
				IKROT_COXA[0]=11;IKROT_COXA[1]=10;// MOV ROT ZCOXA_L = 5
				IKROT_COXA1[0]=7;IKROT_COXA1[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1

			}
			else
			{
				IKROT_COXA[0]=7;IKROT_COXA[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA1[0]=4;IKROT_COXA1[1]=4;// MOV ROT ZCOXA_L = 2
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1
			}

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

/*
			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,26,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,90,28,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,32,114);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105,26,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,69,28,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98,32,114);

			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,69,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98,14,108);

			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105,26,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69,28,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98,32,114);

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,26,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,28,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,32,114);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,90,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,14,108);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74,26,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,28,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81,32,114);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,110,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81,14,108);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74,26,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,110,28,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81,32,108);
*/
		}break;
	}


}


/* func      : 	void Dynamx_Rot_Left(int SPEED, int STEP, int IKCALC_STAT)
 * brief     : 	Dynamixel Hexapod Rotate Left locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEXSTEP_CLOSE, HEXSTEP_MED, HEXSTEP_FAR
 * 				unsigned int IKCALC_STAT
 * 					 IKCALC_ENABLE	1  	-> Calculate all joint angle with Inverse Kinematics
 * 					 IKCALC_DISABLE	0  	-> Bypass the Inverse Kinematics calculation,
 * 					 						move servo with predetermined value
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, February 2nd 2017)
 * Revised By:
 * 				Ver 2. Ryan (Thursday, February 9th 2017)
 * 					Step parameter added
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_Rot_Left(int SPEED,  int STEP, int IKCALC_STAT)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Rotate Left");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"Movement");lcd_putstr(lcd);
//	Sendto_PC(USART1,"BW Rotate Left Movement \r");
//	int limit= degree/3;
//	int loop;

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,STEP,8);
//			delay_ms(50);

			Sendto_PC(USART1,"================ START OF ROTATE LEFT TRIPOD GAIT SEQUENCES ================ \r");

//			Sendto_PC(USART1,"<======== STEP 1 \r");
//			//1
//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1); //DEPAN MENAPAK
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); //BELAKANG MENAPAK
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1);  //DEPAN MENAPAK
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
//		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);

		    Sendto_PC(USART1,"<======== STEP 2 \r");
		    //2
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,3,leg); //TENGAH MENAPAK
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,3,leg); //TENGAH MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,3,leg);  //TENGAH MENAPAK

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,1,leg-1);

		    Sendto_PC(USART1,"<======== STEP 3 \r");
		    //3
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],3,leg); //BELAKANG MENAPAK
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],3,leg); //DEPAN MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],3,leg);  //BELAKANG MENAPAK

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],1,leg-1);

		    Sendto_PC(USART1,"<======== STEP 4 \r");
		    //4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],3,leg);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],3,leg);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],3,leg);

		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],1,leg-1); //BELAKANG ANGKAT
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-1); //DEPAN ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],1,leg-1);  //BELAKANG ANGKAT



		    Sendto_PC(USART1,"<======== STEP 5 \r");
		    //5
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-1); //TENGAH ANGKAT
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-1); //TENGAH ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-1);  //TENGAH ANGKAT

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,3,leg);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,3,leg);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,3,leg);

		    Sendto_PC(USART1,"<======== STEP 6 \r");
		    //6
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],1,leg-1); //DEPAN ANGKAT
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-1); //BELAKANG ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],1,leg-1);  //DEPAN ANGKAT

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],3,leg);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],3,leg);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],3,leg);

			Sendto_PC(USART1,"<======== STEP 1 \r");
			//1
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],3,leg); //DEPAN MENAPAK
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],3,leg); //BELAKANG MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],3,leg);  //DEPAN MENAPAK

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],1,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],1,leg-1);

		    Sendto_PC(USART1,"================ END OF ROTATE LEFT TRIPOD GAIT SEQUENCES ================ \r\r");

		}break;

		case IKCALC_DISABLE:
		{
			if(STEP==HEXSTEP_FAR)
			{
				IKROT_COXA[0]=31;IKROT_COXA[1]=29;// MOV ROT ZCOXA_L = 15
				IKROT_COXA1[0]=21;IKROT_COXA1[1]=19;// MOV ROT ZCOXA_L = 10
				IKROT_COXA2[0]=11;IKROT_COXA2[1]=10;// MOV ROT ZCOXA_L = 5
			}
			else if(STEP==HEXSTEP_MED)
			{
				IKROT_COXA[0]=21;IKROT_COXA[1]=19;// MOV ROT ZCOXA_L = 10
				IKROT_COXA1[0]=13;IKROT_COXA1[1]=12;// MOV ROT ZCOXA_L = 6
				IKROT_COXA2[0]=7;IKROT_COXA2[1]=6;// MOV ROT ZCOXA_L = 3
			}
			else if(STEP==HEXSTEP_CLOSE)
			{
				IKROT_COXA[0]=11;IKROT_COXA[1]=10;// MOV ROT ZCOXA_L = 5
				IKROT_COXA1[0]=7;IKROT_COXA1[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1

			}
			else
			{
				IKROT_COXA[0]=7;IKROT_COXA[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA1[0]=4;IKROT_COXA1[1]=4;// MOV ROT ZCOXA_L = 2
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1
			}


			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

/*
			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,26,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,28,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,32,114);


			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74,26,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,28,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81,32,114);


			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81,14,108);

			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74,26,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,28,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81,32,114);

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,26,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,28,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,32,114);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,14,108);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105,26,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69,28,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98,32,114);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98,14,108);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105,26,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69,28,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98,32,114);
*/
		}break;
	}

}

/* func      : 	void Dynamx_Rot_Right_PID(int degree, int SPEED, float PID)
 * brief     : 	Dynamixel Hexapod Rotate Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEXSTEP_CLOSE, HEXSTEP_MED, HEXSTEP_FAR
 * 				unsigned float PID		-> PID Value
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Monday, Feb 27th 2017)
 * Revised By:
 * Programmer's Note:
 *
 */
void Dynamx_Rot_Right_PID(int SPEED,  int STEP, float *COMMAND_LOOP, int IKCALC_STAT)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Rotate Right");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"PID Movement");lcd_putstr(lcd);
//
//	Sendto_PC(USART1,"BW Rotate Right Movement \r");

		float DELTA= (2 * *COMMAND_LOOP);
//		float DELTA= 12;

		if (DELTA>=12)DELTA=12;

//		lcd_gotoxy(0,0);sprintf(lcd,"com loop: %f",*COMMAND_LOOP);lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"signal: %f",signal);lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"DELTA: %f",DELTA);lcd_putstr(lcd);
//		lcd_gotoxy(7,2);sprintf(lcd,"FR: %f",DELTA_FR);lcd_putstr(lcd);
//		lcd_gotoxy(3,3);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{

			Dynamx_GenerateIK(0,STEP,8);
			delay_ms(50);

			Sendto_PC(USART1,"================ START OF ROTATE RIGHT TRIPOD GAIT SEQUENCES ================ \r");

//			Sendto_PC(USART1,"<======== STEP 1 \r");
//			//1
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA,4,leg-1); //BELAKANG MENAPAK
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA,4,leg-1); 				//DEPAN MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA,4,leg-1);  //BELAKANG MENAPAK
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]-DELTA,1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA,1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]-DELTA,1,leg-2);
//
//	//		delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 2 \r");
			//2
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,3,leg); //TENGAH MENAPAK
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,3,leg); 						//TENGAH MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,3,leg); //TENGAH MENAPAK

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-1);
			Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,1,leg-1);

	//		delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 3 \r");
			//3
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA,3,leg); //DEPAN MENAPAK
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA,3,leg); 				//BELAKANG MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA,3,leg); //DEPAN MENAPAK

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA,1,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA,1,leg-1);
			Dynamx_IK(REAR_LEFT_DX,		&SPEED,90+beta[2]+DELTA,1,leg-1);

	//		delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 4 \r");
			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA,3,leg);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA,3,leg);
			Dynamx_IK(REAR_LEFT_DX,		&SPEED,90+beta[2]+DELTA,3,leg);
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA,1,leg-1); //DEPAN ANGKAT
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA,1,leg-1); 				//BELAKANG ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA,1,leg-1); //DEPAN ANGKAT

	//		delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 5 \r");
			//5
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-1); //TENGAH ANGKAT
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-1); 						//TENGAH ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-1); //TENGAH ANGKAT

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,3,leg);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,3,leg);
			Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,3,leg);

	//		delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 6 \r");
			//6
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA,1,leg-1); //BELAKANG ANGKAT
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA,1,leg-1); 				//BELAKANG ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA,1,leg-1);  //BELAKANG ANGKAT

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]-DELTA,3,leg);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA,3,leg);
			Dynamx_IK(REAR_LEFT_DX,		&SPEED,90-beta[2]-DELTA,3,leg);

	//		delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 1 \r");
			//1
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA,3,leg); //BELAKANG MENAPAK
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA,3,leg); 				//DEPAN MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA,3,leg);  //BELAKANG MENAPAK

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]-DELTA,1,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA,1,leg-1);
			Dynamx_IK(REAR_LEFT_DX,		&SPEED,90-beta[2]-DELTA,1,leg-1);

	//		delay_ms(1000);






				Sendto_PC(USART1,"================ END OF ROTATE RIGHT TRIPOD GAIT SEQUENCES ================ \r\r");
		}break;

		case IKCALC_DISABLE:
		{
			if(STEP==HEXSTEP_FAR)
			{
				IKROT_COXA[0]=31;IKROT_COXA[1]=29;// MOV ROT ZCOXA_L = 15
				IKROT_COXA1[0]=21;IKROT_COXA1[1]=19;// MOV ROT ZCOXA_L = 10
				IKROT_COXA2[0]=11;IKROT_COXA2[1]=10;// MOV ROT ZCOXA_L = 5
			}
			else if(STEP==HEXSTEP_MED)
			{
				IKROT_COXA[0]=21;IKROT_COXA[1]=19;// MOV ROT ZCOXA_L = 10
				IKROT_COXA1[0]=13;IKROT_COXA1[1]=12;// MOV ROT ZCOXA_L = 6
				IKROT_COXA2[0]=7;IKROT_COXA2[1]=6;// MOV ROT ZCOXA_L = 3
			}
			else if(STEP==HEXSTEP_CLOSE)
			{
				IKROT_COXA[0]=11;IKROT_COXA[1]=10;// MOV ROT ZCOXA_L = 5
				IKROT_COXA1[0]=7;IKROT_COXA1[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1
			}
			else
			{
				IKROT_COXA[0]=7;IKROT_COXA[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA1[0]=4;IKROT_COXA1[1]=4;// MOV ROT ZCOXA_L = 2
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1
			}

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();
			//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
				//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
				//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
				//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
				//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//			delay_ms(5000);
//			//2
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,32,114);
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105+DELTA,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69-DELTA,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98+DELTA,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105+DELTA,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69-DELTA,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98+DELTA,32,114);
//
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105+DELTA,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69-DELTA,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98+DELTA,14,108);
//
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105+DELTA,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69-DELTA,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98+DELTA,32,114);
//
//			//5
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,32,114);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,14,108);
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74-DELTA,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110+DELTA,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81-DELTA,32,114);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74-DELTA,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110+DELTA,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81-DELTA,14,108);
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74-DELTA,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110+DELTA,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81-DELTA,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74-DELTA,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110+DELTA,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81-DELTA,32,108);
//
//
//			Sendto_PC(USART1,"<======== STEP 2 \r");
//			//2
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); 						//TENGAH MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);
//
//	//		delay_ms(1000);
//
//			Sendto_PC(USART1,"<======== STEP 3 \r");
//			//3
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA,4,leg-1); //DEPAN MENAPAK
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA,4,leg-1); 				//BELAKANG MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA,4,leg-1); //DEPAN MENAPAK
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA,1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA,1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]+DELTA,1,leg-2);
//
//	//		delay_ms(1000);
//
//			Sendto_PC(USART1,"<======== STEP 4 \r");
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA,4,leg-1);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA,4,leg-1);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]+DELTA,4,leg-1);
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA,1,leg-2); //DEPAN ANGKAT
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA,1,leg-2); 				//BELAKANG ANGKAT
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA,1,leg-2); //DEPAN ANGKAT
//
//	//		delay_ms(1000);
//
//			Sendto_PC(USART1,"<======== STEP 5 \r");
//			//5
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); 						//TENGAH ANGKAT
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);
//
//	//		delay_ms(1000);
//
//			Sendto_PC(USART1,"<======== STEP 6 \r");
//			//6
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA,1,leg-2); //BELAKANG ANGKAT
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA,1,leg-2); 				//BELAKANG ANGKAT
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA,1,leg-2);  //BELAKANG ANGKAT
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]-DELTA,4,leg-1);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA,4,leg-1);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]-DELTA,4,leg-1);
//
//	//		delay_ms(1000);
//
//			Sendto_PC(USART1,"<======== STEP 1 \r");
//			//1
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA,4,leg-1); //BELAKANG MENAPAK
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA,4,leg-1); 				//DEPAN MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA,4,leg-1);  //BELAKANG MENAPAK
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]-DELTA,1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA,1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]-DELTA,1,leg-2);
//
//	//		delay_ms(1000);

		}break;
	}
}

/* func      : 	void Dynamx_Rot_Left_PID(int SPEED, int STEP, float PID)
 * brief     : 	Dynamixel Hexapod Rotate Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEXSTEP_CLOSE, HEXSTEP_MED, HEXSTEP_FAR
 * 				unsigned float PID		-> PID Value
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Monday, Feb 27th 2017)
 * Revised By:
 * Programmer's Note:
 *
 */
void Dynamx_Rot_Left_PID(int SPEED,  int STEP, float *COMMAND_LOOP, int IKCALC_STAT)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Rotate Left");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"PID Movement");lcd_putstr(lcd);
//	Sendto_PC(USART1,"BW Rotate Right Movement \r");
//
			float DELTA= (2 * *COMMAND_LOOP);

			if (DELTA>=12)DELTA=12;
//			int DELTA=12;

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,STEP,8);
//			delay_ms(50);

			Sendto_PC(USART1,"================ START OF ROTATE LEFT TRIPOD GAIT SEQUENCES ================ \r");

//			Sendto_PC(USART1,"<======== STEP 1 \r");
//			//1
//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA,4,leg-1); //DEPAN MENAPAK
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA,4,leg-1); //BELAKANG MENAPAK
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA,4,leg-1);  //DEPAN MENAPAK
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA,1,leg-2);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA,1,leg-2);
//		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]+DELTA,1,leg-2);
//
////		    delay_ms(1000);

		    Sendto_PC(USART1,"<======== STEP 2 \r");
		    //2
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,3,leg); //TENGAH MENAPAK
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,3,leg); //TENGAH MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,3,leg);  //TENGAH MENAPAK

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-1);

//		    delay_ms(1000);

		    Sendto_PC(USART1,"<======== STEP 3 \r");
		    //3
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA,3,leg); //BELAKANG MENAPAK
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA,3,leg); //DEPAN MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA,3,leg);  //BELAKANG MENAPAK

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]-DELTA,1,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA,1,leg);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]-DELTA,1,leg-1);

//		    delay_ms(1000);

		    Sendto_PC(USART1,"<======== STEP 4 \r");
		    //4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]-DELTA,3,leg);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA,3,leg);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]-DELTA,3,leg);

		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA,1,leg-1); //BELAKANG ANGKAT
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA,1,leg-1); //DEPAN ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA,1,leg-1);  //BELAKANG ANGKAT

//		    delay_ms(1000);

		    Sendto_PC(USART1,"<======== STEP 5 \r");
		    //5
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-1); //TENGAH ANGKAT
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-1); //TENGAH ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-1);  //TENGAH ANGKAT

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,3,leg);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,3,leg);
		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,3,leg);

//		    delay_ms(1000);

		    Sendto_PC(USART1,"<======== STEP 6 \r");
		    //6
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA,1,leg-1); //DEPAN ANGKAT
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA,1,leg-1); //BELAKANG ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA,1,leg-1);  //DEPAN ANGKAT

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA,3,leg);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA,3,leg);
		    Dynamx_IK(REAR_LEFT_DX,		&SPEED,90+beta[2]+DELTA,3,leg);

//		    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 1 \r");
			//1
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA,3,leg); //DEPAN MENAPAK
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA,3,leg); //BELAKANG MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA,3,leg);  //DEPAN MENAPAK

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA,1,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA,1,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]+DELTA,1,leg-1);

//		    delay_ms(1000);

		    Sendto_PC(USART1,"================ END OF ROTATE LEFT TRIPOD GAIT SEQUENCES ================ \r\r");
		}break;

		case IKCALC_DISABLE:
		{
			if(STEP==HEXSTEP_FAR)
			{
				IKROT_COXA[0]=31;IKROT_COXA[1]=29;// MOV ROT ZCOXA_L = 15
				IKROT_COXA1[0]=21;IKROT_COXA1[1]=19;// MOV ROT ZCOXA_L = 10
				IKROT_COXA2[0]=11;IKROT_COXA2[1]=10;// MOV ROT ZCOXA_L = 5
			}
			else if(STEP==HEXSTEP_MED)
			{
				IKROT_COXA[0]=21;IKROT_COXA[1]=19;// MOV ROT ZCOXA_L = 10
				IKROT_COXA1[0]=13;IKROT_COXA1[1]=12;// MOV ROT ZCOXA_L = 6
				IKROT_COXA2[0]=7;IKROT_COXA2[1]=6;// MOV ROT ZCOXA_L = 3
			}
			else if(STEP==HEXSTEP_CLOSE)
			{
				IKROT_COXA[0]=11;IKROT_COXA[1]=10;// MOV ROT ZCOXA_L = 5
				IKROT_COXA1[0]=7;IKROT_COXA1[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1

			}
			else
			{
				IKROT_COXA[0]=7;IKROT_COXA[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA1[0]=4;IKROT_COXA1[1]=4;// MOV ROT ZCOXA_L = 2
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1
			}


			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//			delay_ms(5000);

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105+DELTA,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69-DELTA,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98+DELTA,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105+DELTA,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69-DELTA,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98+DELTA,32,114);

//
//			//2
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,32,114);
//
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74-DELTA,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110+DELTA,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81-DELTA,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74-DELTA,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110+DELTA,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81-DELTA,32,114);
//
//
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,74-DELTA,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110+DELTA,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,81-DELTA,14,108);
//
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,74-DELTA,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110+DELTA,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,81-DELTA,32,114);
//
//			//5
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,32,114);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,14,108);
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105+DELTA,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69-DELTA,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98+DELTA,32,114);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105+DELTA,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69-DELTA,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98+DELTA,14,108);
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,105+DELTA,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69-DELTA,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,98+DELTA,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,105+DELTA,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69-DELTA,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,98+DELTA,32,114);
		}break;
	}
}


/* func      : 	void Dynamx_Deflect_Right(int STEP, int SPEED)
 * brief     : 	Dynamixel Hexapod Deflect Right locomotion using tripod gait
 * param     :	unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * retval    : 	N/A
 * Ver       : 2
 * written By: Ryan (Wednesday, February 8th 2017)
 *
 * Revised By: Toni
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_Slide_Left(int STEP, int SPEED)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Slide Left Movement");lcd_putstr(lcd);

	//2
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

	//3
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLL_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLL_TIBIA2[3]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			    ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLL_TIBIA2[1]);	//kanan menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLL_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLL_TIBIA2[3]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLL_COXA2[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKSLL_TIBIA2[3]-5);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				 ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+IKSLL_TIBIA2[1]+5);	//kiri angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLL_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]-IKSLL_TIBIA2[3]-5);

	//3
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLL_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLL_TIBIA1[3]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			    ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLL_TIBIA1[1]);	//kanan menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLL_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLL_TIBIA1[3]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLL_COXA1[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKSLL_TIBIA1[3]-5);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				 ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+IKSLL_TIBIA1[1]+5);	//kiri angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLL_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]-IKSLL_TIBIA1[3]-5);

	//3
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLL_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLL_TIBIA[3]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLL_TIBIA[1]);	//kanan menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLL_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLL_TIBIA[3]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLL_COXA[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKSLL_TIBIA[3]-5);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+IKSLL_TIBIA[1]+5);	//kiri angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLL_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]-IKSLL_TIBIA[3]-5);

	//4
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLL_COXA[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLL_TIBIA[3]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLL_TIBIA[1]);		//kiri menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLL_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLL_TIBIA[3]);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLL_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kanan angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLL_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

	//4
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLL_COXA1[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLL_TIBIA1[3]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLL_TIBIA1[1]);		//kiri menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLL_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLL_TIBIA1[3]);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLL_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kanan angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLL_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

	//4
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLL_COXA2[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLL_TIBIA2[3]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLL_TIBIA2[1]);		//kiri menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLL_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLL_TIBIA2[3]);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLL_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kanan angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLL_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

	//5
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);

	//6
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLL_COXA2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+IKSLL_TIBIA2[0]+5);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKSLL_TIBIA2[2]-5);	//kiri angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLL_COXA2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKSLL_TIBIA2[0]+5);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLL_COXA2[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLL_TIBIA2[0]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLL_TIBIA2[2]);	//kanan menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLL_COXA2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLL_TIBIA2[0]);

	//6
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLL_COXA1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+IKSLL_TIBIA1[0]+5);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKSLL_TIBIA1[2]-5);	//kiri angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLL_COXA1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKSLL_TIBIA1[0]+5);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLL_COXA1[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLL_TIBIA1[0]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLL_TIBIA1[2]);	//kanan menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLL_COXA1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLL_TIBIA1[0]);

	//6
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLL_COXA[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+IKSLL_TIBIA[0]+5);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKSLL_TIBIA[2]-5);	//kiri angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLL_COXA[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKSLL_TIBIA[0]+5);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLL_COXA[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLL_TIBIA[0]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLL_TIBIA[2]);	//kanan menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLL_COXA[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLL_TIBIA[0]);

	//1
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLL_COXA[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLL_TIBIA[0]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLL_TIBIA[2]);	//keluar menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLL_COXA[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLL_TIBIA[0]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLL_COXA[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//keluar angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLL_COXA[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

	//1
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLL_COXA1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLL_TIBIA1[0]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLL_TIBIA1[2]);	//keluar menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLL_COXA1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLL_TIBIA1[0]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLL_COXA1[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//keluar angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLL_COXA1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

	//1
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLL_COXA2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLL_TIBIA2[0]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLL_TIBIA2[2]);	//keluar menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLL_COXA2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLL_TIBIA2[0]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLL_COXA2[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//keluar angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLL_COXA2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

	/*
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//2
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//3
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKSLL_COXA[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKSLL_TIBIA[3]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]				 ,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]+IKSLL_TIBIA[1]);	//kanan menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKSLL_COXA[0],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKSLL_TIBIA[3]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKSLL_COXA[0] ,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]-IKSLL_TIBIA[3]-5);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]				  ,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+IKSLL_TIBIA[1]+5);	//kiri angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKSLL_COXA[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKSLL_TIBIA[3]-5);

	//BW_Tracer_Check();
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//4
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKSLL_COXA[0] ,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKSLL_TIBIA[3]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]				  ,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]+IKSLL_TIBIA[1]);		//kiri menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKSLL_COXA[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKSLL_TIBIA[3]);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKSLL_COXA[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]				 ,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//kanan angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKSLL_COXA[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);

	//BW_Tracer_Check();
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//5
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);

	//BW_Tracer_Check();
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//6
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKSLL_COXA[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKSLL_TIBIA[0]+5);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]			   ,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKSLL_TIBIA[2]-5);	//kiri angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKSLL_COXA[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+IKSLL_TIBIA[0]+5);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKSLL_COXA[2] ,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKSLL_TIBIA[0]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]				,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKSLL_TIBIA[2]);	//kanan menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKSLL_COXA[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKSLL_TIBIA[0]);

	//				delay_ms(2000);

	//BW_Tracer_Check();
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//1
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKSLL_COXA[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKSLL_TIBIA[0]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]			   ,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKSLL_TIBIA[2]);	//keluar menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKSLL_COXA[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKSLL_TIBIA[0]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKSLL_COXA[2] ,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]			    ,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//keluar angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKSLL_COXA[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);

	//BW_Tracer_Check();

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/
}

/* func      : 	void Dynamx_Slide_Right(int STEP, int SPEED)
 * brief     : 	Dynamixel Hexapod Deflect Left locomotion using tripod gait
 * param     :	unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * retval    : 	N/A
 * Ver       : 2
 * written By: Ryan (Wednesday, February 8th 2017)
 * Revised By: Toni
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_Slide_Right(int STEP, int SPEED)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Slide Right Movement");lcd_putstr(lcd);
//	Sendto_PC(USART1,"BW Deflect Left Movement \r");

	//2
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

	//3
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA2[0]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA2[2]);	//kiri menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA2[0]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA2[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+IKSLR_TIBIA2[0]+5);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKSLR_TIBIA2[2]-5);	//kanan angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKSLR_TIBIA2[0]+5);

	//3
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA1[0]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA1[2]);	//kiri menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA1[0]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA1[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+IKSLR_TIBIA1[0]+5);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKSLR_TIBIA1[2]-5);	//kanan angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKSLR_TIBIA1[0]+5);

	//3
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA[2]);	//kiri menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA[0]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+IKSLR_TIBIA[0]+5);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKSLR_TIBIA[2]-5);	//kanan angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKSLR_TIBIA[0]+5);

	//4
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA[2]); //kanan menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA[0]);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

	//4
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA1[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA1[0]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA1[2]); //kanan menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA1[0]);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

	//4
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA2[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA2[0]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA2[2]); //kanan menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA2[0]);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

	//5
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);

	//6
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKSLR_TIBIA2[3]-5);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+IKSLR_TIBIA2[1]+5);	//kanan angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]-IKSLR_TIBIA2[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA2[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLR_TIBIA2[3]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLR_TIBIA2[1]);	//kiri menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLR_TIBIA2[3]);

	//6
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKSLR_TIBIA1[3]-5);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+IKSLR_TIBIA1[1]+5);	//kanan angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]-IKSLR_TIBIA1[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA1[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLR_TIBIA1[3]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLR_TIBIA1[1]);	//kiri menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLR_TIBIA1[3]);

	//6
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKSLR_TIBIA[3]-5);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+IKSLR_TIBIA[1]+5);	//kanan angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]-IKSLR_TIBIA[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLR_TIBIA[1]);	//kiri menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLR_TIBIA[3]);
	//				delay_ms(2000);

	//1
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA[1]);	//kanan menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA[3]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
		//				delay_ms(2000);

	//1
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA1[3]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA1[1]);	//kanan menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA1[3]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA1[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

	//1
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA2[3]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA2[1]);	//kanan menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA2[3]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA2[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

/*
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//2
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//3
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKSLR_COXA[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]			   ,SUDUT_STATIC_BWD[4]-10,SUDUT_STATIC_BWD[5]-IKSLR_TIBIA[2]);	//kiri menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKSLR_COXA[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKSLR_TIBIA[0]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKSLR_COXA[2] ,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKSLR_TIBIA[0]+5);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]				,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKSLR_TIBIA[2]-5);	//kanan angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKSLR_COXA[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+IKSLR_TIBIA[0]+5);

	//BW_Tracer_Check();
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//					delay_ms(2000);
	//4
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKSLR_COXA[2] ,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]				,SUDUT_STATIC_BWD[13]-12,SUDUT_STATIC_BWD[14]-IKSLR_TIBIA[2]); //kanan menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKSLR_COXA[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKSLR_TIBIA[0]);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKSLR_COXA[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]			   ,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKSLR_COXA[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);

	//BW_Tracer_Check();
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//					delay_ms(2000);

	//5
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);

//				delay_ms(2000);
	//BW_Tracer_Check();
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//6
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKSLR_COXA[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]-IKSLR_TIBIA[3]-5);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]			   ,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT+5,SUDUT_STATIC_BWD[5]+IKSLR_TIBIA[1]+5);	//kanan angkat
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKSLR_COXA[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKSLR_TIBIA[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKSLR_COXA[0] ,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]				,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]+IKSLR_TIBIA[1]);	//kiri menapak
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKSLR_COXA[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKSLR_TIBIA[3]);

//				delay_ms(2000);

	//				delay_ms(2000);
	//BW_Tracer_Check();
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

	//1
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKSLR_COXA[0],SUDUT_STATIC_BWD[1]-5,SUDUT_STATIC_BWD[2]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]			   ,SUDUT_STATIC_BWD[4]-5,SUDUT_STATIC_BWD[5]+IKSLR_TIBIA[1]);	//kanan menapak
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKSLR_COXA[0],SUDUT_STATIC_BWD[7]-5,SUDUT_STATIC_BWD[8]-IKSLR_TIBIA[3]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKSLR_COXA[0] ,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]			    ,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKSLR_COXA[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//				delay_ms(2000);

	//BW_Tracer_Check();

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/
}


/* func      : 	void Dynamx_CurveRight_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL)
 * brief     : 	Dynamixel Hexapod Curve Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				float *ACTUATE_SIGNAL	-> PID Value from PID calculations
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Thursday, February 9th 2017)
 * Revised By: Hafidin (Monday, February 20th 2017)
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_CurveRight_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL, int IKCALC_STAT)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Curve Right");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"PID");lcd_putstr(lcd);
//	Sendto_PC(USART1,"BW Curve Right PID \r");

	float signal=*ACTUATE_SIGNAL/5;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;

//	if (signal>=23){error_L=23;}
//	if (signal>=9){error_R=9;}
	if (signal>=IKFWD_TIBIA_R2[2]){error_R=IKFWD_TIBIA_R2[2];}
	else {error_R=signal;error_L=signal;}

//	if(error_R>=4) {femur_R=1;} else {femur_R=0;}
//	if(error_L>=2) {femur_L=2;} else {femur_L=0;}

//	float DELTA_L=0 + (1 * error_L);
	float DELTA_R=0 + (1 * error_R);

	int DELTA3[3];
	int DELTA2[3];
	int DELTA1[3];
	int DELTA[3];

	DELTA3[2] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R3[2];
	DELTA3[1] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R3[1];
	DELTA3[0] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R3[0];

	DELTA2[2] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R2[2];
	DELTA2[1] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R2[1];
	DELTA2[0] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R2[0];

	DELTA1[2] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R1[2];
	DELTA1[1] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R1[1];
	DELTA1[0] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R1[0];

	DELTA[2] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R[2];
	DELTA[1] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R[1];
	DELTA[0] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R[0];

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
		}break;

		case IKCALC_DISABLE:
		{

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();
//			delay_ms(5000);
			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2]+DELTA3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0]+DELTA3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1]-DELTA3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2]+DELTA2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0]+DELTA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1]-DELTA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2]+DELTA1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0]+DELTA1[0],SUDUT_STATIC[7]-6,SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1]-DELTA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]-5,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA[0],SUDUT_STATIC[7]-10,SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]-4,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1]-DELTA1[1],SUDUT_STATIC[13]-2,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2]+DELTA1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0]+DELTA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1]-DELTA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2]+DELTA2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0]+DELTA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0]-DELTA3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2]-DELTA3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1]+DELTA3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0]-DELTA3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2]-DELTA3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1]+DELTA3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0]-DELTA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2]-DELTA2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1]+DELTA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0]-DELTA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2]-DELTA1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1]+DELTA1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]-6,SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA[0],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0]-DELTA1[0],SUDUT_STATIC[1]-4,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]-2,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2]-DELTA1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1]+DELTA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0]-DELTA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2]-DELTA2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1]+DELTA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0]-DELTA3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2]-DELTA3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1]+DELTA3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			//BW_Tracer_Check();
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

/*			//====== Z=35 TIBIA Z=25 SPEED = 1700 FIX CUKUP BAGUS ======
			//BW_Tracer_Check();

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]-DELTA_R3);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);									//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]+DELTA_R5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]+DELTA_R4-5);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]+5);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]+DELTA_R4);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);									//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]+DELTA_R5-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]-5);										//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]-DELTA_R3+5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]+DELTA_R4);				//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]+DELTA_R5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);										//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]-DELTA_R3);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);			//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			//BW_Tracer_Check();
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/

		}break;
	}
}

/* func      : 	void Dynamx_CurveRight_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL)
 * brief     : 	Dynamixel Hexapod Curve Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				float *ACTUATE_SIGNAL	-> PID Value from PID calculations
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Thursday, February 9th 2017)
 * Revised By: Hafidin (Monday, February 20th 2017)
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 */
void Dynamx_CurveRight_PID_SLOW(int SPEED, int STEP, float *ACTUATE_SIGNAL, int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Right PID SLOW \r");

	float signal=*ACTUATE_SIGNAL/5;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;

//	if (signal>=23){error_L=23;}
//	if (signal>=9){error_R=9;}
	if (signal>=IKRPID_TIBIA_R2[2]){error_R=IKRPID_TIBIA_R2[2];}
	else {error_R=signal;error_L=signal;}

//	if(error_R>=4) {femur_R=1;} else {femur_R=0;}
//	if(error_L>=2) {femur_L=2;} else {femur_L=0;}

//	float DELTA_L=0 + (1 * error_L);
	float DELTA_R=0 + (1 * error_R);

	int DELTA_R0 = (DELTA_R/IKRPID_TIBIA_R2[2])*IKRPID_COXA_R2[0];
	int DELTA_R1 = (DELTA_R/IKRPID_TIBIA_R2[2])*IKRPID_COXA_R2[1];
	int DELTA_R2 = (DELTA_R/IKRPID_TIBIA_R2[2])*IKRPID_COXA_R2[2];
	int DELTA_R3 = (DELTA_R/IKRPID_TIBIA_R2[2])*IKRPID_TIBIA_R2[0];
	int DELTA_R4 = (DELTA_R/IKRPID_TIBIA_R2[2])*IKRPID_TIBIA_R2[1];
	int DELTA_R5 = (DELTA_R/IKRPID_TIBIA_R2[2])*IKRPID_TIBIA_R2[2];

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
		}break;

		case IKCALC_DISABLE:
		{
			//====== Z=35 TIBIA Z=25 SPEED = 1700 FIX CUKUP BAGUS ======
			//BW_Tracer_Check();

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2]+DELTA_R2,SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]-DELTA_R3);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);									//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0]+DELTA_R0,SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]+DELTA_R5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1]-DELTA_R1,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]+DELTA_R4-5);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]+5);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1]-DELTA_R1,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]+DELTA_R4);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2]+DELTA_R2,SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);									//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0]+DELTA_R0,SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0]-DELTA_R0,SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]+DELTA_R5-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]-5);										//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2]-DELTA_R2,SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]-DELTA_R3+5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1]+DELTA_R1,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]+DELTA_R4);				//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0]-DELTA_R0,SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]+DELTA_R5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);										//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2]-DELTA_R2,SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]-DELTA_R3);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1]+DELTA_R1,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);			//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			//BW_Tracer_Check();
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

		}break;
	}
}



/* func      : 	void Dynamx_CurveRight(int SPEED, int STEP)
 * brief     : 	Dynamixel Hexapod Curve Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 *
 * retval    : 	N/A
 * Ver       : 2
 * written By: Hafidin (Monday, February 20th 2017)
 * Revised By: Hafidin (Friday, March 24th 2017)
 * Programmer's Note:
 *
 *
 */
void Dynamx_CurveRight(int SPEED, int STEP, int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Right \r");

	unsigned int DELTA_FL=0;
	unsigned int DELTA_FR=5;
	unsigned int DELTA_ML=0;
	unsigned int DELTA_MR=5;
	unsigned int DELTA_RL=0;
	unsigned int DELTA_RR=5;

//	lcd_gotoxy(0,2);sprintf(lcd,"FL: %d",DELTA_FL);lcd_putstr(lcd);
//	lcd_gotoxy(7,2);sprintf(lcd,"FR: %d",DELTA_FR);lcd_putstr(lcd);
//	lcd_gotoxy(3,3);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);
	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,STEP,9);
			delay_ms(50);

			Sendto_PC(USART1,"================ START OF CURVE RIGHT TRIPOD GAIT SEQUENCES ================ \r");

			Sendto_PC(USART1,"<======== STEP 1 \r");
			//1
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]-DELTA_FR,4,leg-1);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA_ML,4,leg-1); //DEPAN MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]-DELTA_RR,4,leg-1);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 2 \r");
			//2
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,4,leg-1);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,4,leg-1); //TENGAH MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+DELTA_RR,4,leg-1);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+DELTA_FL,1,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-DELTA_MR,1,leg-2);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+DELTA_RL,1,leg-2);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 3 \r");
			//3
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]+DELTA_FR,4,leg-1);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA_ML,4,leg-1); //BELAKANG MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]+DELTA_RR,4,leg-1);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA_FL,1,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]-DELTA_MR,1,leg-2);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]+DELTA_RL,1,leg-2);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
			//4
			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA_FL,4,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]-DELTA_MR,4,leg-1);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]+DELTA_RL,4,leg-1);

			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 5 \r");
			//5
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,1,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,1,leg-2); //TENGAH ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-DELTA_RR,1,leg-2);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-DELTA_FL,4,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+DELTA_MR,4,leg-1);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-DELTA_RL,4,leg-1);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 6 \r");
			//6
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]-DELTA_FR,1,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA_ML,1,leg-2); //DEPAN ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]-DELTA_RR,1,leg-2);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]-DELTA_FL,4,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]+DELTA_MR,4,leg-1);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]-DELTA_RL,4,leg-1);

		//    delay_ms(1000);

			Sendto_PC(USART1,"================ END OF CURVE RIGHT TRIPOD GAIT SEQUENCES ================ \r\r");
		}break;

		case IKCALC_DISABLE:
		{
			//				====== Z=35 TIBIA Z=25 SPEED = 1700 FIX CUKUP BAGUS ======
							//BW_Tracer_Check();

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//2
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
							//BW_Tracer_Check();
			//				delay_ms(5000);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//3
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
			//				delay_ms(5000);

							//3
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]-6,SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
			//				delay_ms(5000);

							//3
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]-5,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]-10,SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
			//				delay_ms(5000);

							//BW_Tracer_Check();
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//4
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//									delay_ms(5000);

							//4
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]-4,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]-2,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);		//depan menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//									delay_ms(5000);

							//4
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//									delay_ms(5000);

							//BW_Tracer_Check();
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//5
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//				delay_ms(5000);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//6
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
			//				delay_ms(5000);

							//6
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]-6,SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
			//				delay_ms(5000);

							//6
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
			//				delay_ms(5000);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//1
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//				delay_ms(5000);

							//1
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]-4,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]-2,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//				delay_ms(5000);

							//1
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//				delay_ms(5000);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;


/*
//		====== ZL = 35 && ZR = 5, TIBIA ZL=25 ZR=5 SPEED = 1650 FIX CUKUP BAGUS ======
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKCRVR_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKCRVR_TIBIA_R[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKCRVR_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKCRVR_TIBIA_L[1]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKCRVR_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKCRVR_TIBIA_R[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKCRVR_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKCRVR_TIBIA_L[2]-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKCRVR_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKCRVR_TIBIA_R[1]-5);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKCRVR_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKCRVR_TIBIA_L[0]+5);

			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKCRVR_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKCRVR_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKCRVR_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKCRVR_TIBIA_R[1]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKCRVR_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKCRVR_TIBIA_L[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKCRVR_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKCRVR_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKCRVR_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKCRVR_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKCRVR_TIBIA_R[2]-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKCRVR_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKCRVR_TIBIA_L[1]-5);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKCRVR_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKCRVR_TIBIA_R[0]+5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKCRVR_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKCRVR_TIBIA_L[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKCRVR_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKCRVR_TIBIA_R[1]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKCRVR_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKCRVR_TIBIA_L[2]);
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKCRVR_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKCRVR_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKCRVR_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKCRVR_TIBIA_L[1]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKCRVR_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKCRVR_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKCRVR_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKCRVR_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKCRVR_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/
		}break;
	}
}

/* func      : 	void Dynamx_CurveLeft_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL)
 * brief     : 	Dynamixel Hexapod Curve Left locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				float *ACTUATE_SIGNAL	-> PID Value from PID calculations
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Thursday, February 9th 2017)
 * Revised By: Hafidin (Monday, February 20th 2017)
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_CurveLeft_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL,int IKCALC_STAT)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Curve Left");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"PID");lcd_putstr(lcd);
//	Sendto_PC(USART1,"BW Curve Left PID \r");

	float signal=*ACTUATE_SIGNAL/5;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;

	if (signal>=IKFWD_TIBIA_L[2]){error_L=IKFWD_TIBIA_L[2];}
	//if (signal>=17){error_R=17;}
	else {error_R=signal;error_L=signal;}

//	if(error_R>=4) {femur_R=1;} else {femur_R=0;}
//	if(error_L>=2) {femur_L=2;} else {femur_L=0;}

	float DELTA_L=0 + (1 * error_L);
	//float DELTA_R=0 + (1 * error_R);

//
//	int DELTA_L0 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[0];
//	int DELTA_L1 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[1];
//	int DELTA_L2 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[2];
//	int DELTA_L3 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[0];
//	int DELTA_L4 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[1];
//	int DELTA_L5 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[2];

	int DELTA3[3];
	int DELTA2[3];
	int DELTA1[3];
	int DELTA[3];

	DELTA3[2] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L3[2];
	DELTA3[1] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L3[1];
	DELTA3[0] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L3[0];

	DELTA2[2] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L2[2];
	DELTA2[1] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L2[1];
	DELTA2[0] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L2[0];

	DELTA1[2] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L1[2];
	DELTA1[1] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L1[1];
	DELTA1[0] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L1[0];

	DELTA[2] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L[2];
	DELTA[1] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L[1];
	DELTA[0] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L[0];

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
		}break;

		case IKCALC_DISABLE:
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();
			//			delay_ms(5000);
			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1]+DELTA3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0]-DELTA3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2]-DELTA3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//				delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1]+DELTA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0]-DELTA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2]-DELTA2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
				//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1]+DELTA1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]-6,SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0]-DELTA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2]-DELTA1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
				//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA[1],SUDUT_STATIC[4]-5,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]-10,SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
				//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA[0],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0]-DELTA1[0],SUDUT_STATIC[10]-4,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]-2,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2]-DELTA1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1]+DELTA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0]-DELTA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1]+DELTA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0]-DELTA3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2]-DELTA3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1]+DELTA3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
				//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1]-DELTA3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2]+DELTA3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0]+DELTA3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1]-DELTA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2]+DELTA2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0]+DELTA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
				//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1]-DELTA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2]+DELTA1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0]+DELTA1[0],SUDUT_STATIC[16]-6,SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
				//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
				//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]-4,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1]-DELTA1[1],SUDUT_STATIC[4]-2,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2]+DELTA1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0]+DELTA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1]-DELTA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2]+DELTA2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0]+DELTA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1]-DELTA3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2]+DELTA3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0]+DELTA3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			//BW_Tracer_Check();
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
/*			//====== Z=35 TIBIA Z=25 SPEED = 1700 FIX CUKUP BAGUS ======
			//BW_Tracer_Check();

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]+DELTA_L4);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]+DELTA_L5-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]-5);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]-DELTA_L3+5);
			//					delay_ms(2000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]+DELTA_L5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]-DELTA_L3);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//					delay_ms(2000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);

			//					delay_ms(2000);
			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]+DELTA_L4-5);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]+5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]-DELTA_L3);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]+DELTA_L5);

			//					delay_ms(2000);
			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]+DELTA_L4);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

			//BW_Tracer_Check();

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/
		}break;
	}

	Bumper_Action();
}

/* func      : 	void Dynamx_CurveLeft_PID_SLOW(int SPEED, int STEP, float *ACTUATE_SIGNAL)
 * brief     : 	Dynamixel Hexapod Curve Left locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				float *ACTUATE_SIGNAL	-> PID Value from PID calculations
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Thursday, February 9th 2017)
 * Revised By: Hafidin (Monday, February 20th 2017)
 * Programmer's Note: 	ENABLE Inverse Kinematics Calculation burdens the processor,
 * 						speed significantly increase if IK Calc disabled
 *
 *
 */
void Dynamx_CurveLeft_PID_SLOW(int SPEED, int STEP, float *ACTUATE_SIGNAL,int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Left PID \r");

	float signal=*ACTUATE_SIGNAL/5;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;

	if (signal>=IKLPID_TIBIA_L2[2]){error_L=IKLPID_TIBIA_L2[2];}
	//if (signal>=17){error_R=17;}
	else {error_R=signal;error_L=signal;}

//	if(error_R>=4) {femur_R=1;} else {femur_R=0;}
//	if(error_L>=2) {femur_L=2;} else {femur_L=0;}

	float DELTA_L=0 + (1 * error_L);
	//float DELTA_R=0 + (1 * error_R);


	int DELTA_L0 = (DELTA_L/IKLPID_TIBIA_L2[2])*IKLPID_COXA_L2[0];
	int DELTA_L1 = (DELTA_L/IKLPID_TIBIA_L2[2])*IKLPID_COXA_L2[1];
	int DELTA_L2 = (DELTA_L/IKLPID_TIBIA_L2[2])*IKLPID_COXA_L2[2];
	int DELTA_L3 = (DELTA_L/IKLPID_TIBIA_L2[2])*IKLPID_TIBIA_L2[0];
	int DELTA_L4 = (DELTA_L/IKLPID_TIBIA_L2[2])*IKLPID_TIBIA_L2[1];
	int DELTA_L5 = (DELTA_L/IKLPID_TIBIA_L2[2])*IKLPID_TIBIA_L2[2];


	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
		}break;

		case IKCALC_DISABLE:
		{
			//====== Z=35 TIBIA Z=25 SPEED = 1700 FIX CUKUP BAGUS ======
			//BW_Tracer_Check();

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1]+DELTA_L1,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]+DELTA_L4);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0]-DELTA_L0,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]+DELTA_L5-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]-5);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2]-DELTA_L2,SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]-DELTA_L3+5);
			//					delay_ms(2000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0]-DELTA_L0,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]+DELTA_L5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2]-DELTA_L2,SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]-DELTA_L3);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1]+DELTA_L1,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//					delay_ms(2000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);

			//					delay_ms(2000);
			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1]-DELTA_L1,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]+DELTA_L4-5);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]+5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2]+DELTA_L2,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]-DELTA_L3);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0]+DELTA_L0,SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]+DELTA_L5);

			//					delay_ms(2000);
			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1]-DELTA_L1,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]+DELTA_L4);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2]+DELTA_L2,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0]+DELTA_L0,SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

			//BW_Tracer_Check();

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

		}break;
	}

	Bumper_Action();
}

/* func      : 	void Dynamx_CurveLeft(int SPEED, int STEP)
 * brief     : 	Dynamixel Hexapod Curve Left locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 *
 * retval    : 	N/A
 * Ver       : 2
 * written By: Hafidin (Monday, February 20th 2017)
 * Revised By: Hafidin (Friday, March 24th 2017)
 * Programmer's Note:
 *
 */
void Dynamx_CurveLeft(int SPEED, int STEP, int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Left \r");

	unsigned int DELTA_FL=5;
	unsigned int DELTA_FR=0;
	unsigned int DELTA_ML=5;
	unsigned int DELTA_MR=0;
	unsigned int DELTA_RL=5;
	unsigned int DELTA_RR=0;

//	lcd_gotoxy(0,2);sprintf(lcd,"FL: %d",DELTA_FL);lcd_putstr(lcd);
//	lcd_gotoxy(7,2);sprintf(lcd,"FR: %d",DELTA_FR);lcd_putstr(lcd);
//	lcd_gotoxy(3,3);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);
	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,STEP,9);
			delay_ms(50);
			Sendto_PC(USART1,"================ START OF CURVE LEFT TRIPOD GAIT SEQUENCES ================ \r");

			Sendto_PC(USART1,"<======== STEP 1 \r");
			//1
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA_FR,4,leg-1);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]-DELTA_ML,4,leg-1);
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA_RR,4,leg-1);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]+DELTA_FL,1,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA_MR,1,leg-2);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]+DELTA_RL,1,leg-2);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 2 \r");
			//2
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 3 \r");
			//3
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA_FR,4,leg-1);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]+DELTA_ML,4,leg-1); //BELAKANG MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA_RR,4,leg-1);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]-DELTA_FL,1,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA_MR,1,leg-2);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]-DELTA_RL,1,leg-2);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
			//4
			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]-DELTA_FL,4,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA_MR,4,leg-1);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]-DELTA_RL,4,leg-1);

			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA_FR,1,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]+DELTA_ML,1,leg-2); //BELAKANG ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA_RR,1,leg-2);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 5 \r");
			//5
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);

		//    delay_ms(1000);

			Sendto_PC(USART1,"<======== STEP 6 \r");
			//6
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA_FR,1,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]-DELTA_ML,1,leg-2); //DEPAN ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA_RR,1,leg-2);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]+DELTA_FL,4,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA_MR,4,leg-1);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]+DELTA_RL,4,leg-1);

		//    delay_ms(1000);

			Sendto_PC(USART1,"================ END OF CURVE LEFT TRIPOD GAIT SEQUENCES ================ \r\r");
		}break;

		case IKCALC_DISABLE:
		{
			//				====== Z=35 TIBIA Z=25 SPEED = 1700 FIX CUKUP BAGUS ======
							//BW_Tracer_Check();
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//2
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
							//BW_Tracer_Check();
			//				delay_ms(5000);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//3
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
			//				delay_ms(5000);

							//3
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]-6,SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
			//				delay_ms(5000);

							//3
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]-5,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]-10,SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
			//				delay_ms(5000);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//4
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//									delay_ms(5000);

							//4
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]-4,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]-2,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);		//depan menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//									delay_ms(5000);

							//4
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//									delay_ms(5000);

							//BW_Tracer_Check();
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//5
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//				delay_ms(5000);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//6
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
			//				delay_ms(5000);

							//6
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]-6,SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
			//				delay_ms(5000);

							//6
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan angkat
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
			//				delay_ms(5000);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//1
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//				delay_ms(5000);

							//1
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]-4,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]-2,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//				delay_ms(5000);

							//1
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan menapak
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//				delay_ms(5000);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

/*			//				====== ZR=35 ZL=5 TIBIA ZR=25 ZL=5  SPEED = 1650 FIX CUKUP BAGUS ======
							//BW_Tracer_Check();

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//2
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);


							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//3
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKCRVL_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKCRVL_TIBIA_R[0]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKCRVL_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKCRVL_TIBIA_L[1]);
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKCRVL_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKCRVL_TIBIA_R[2]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKCRVL_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKCRVL_TIBIA_L[2]-5);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKCRVL_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKCRVL_TIBIA_R[1]-5);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKCRVL_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKCRVL_TIBIA_R[0]+5);

							//BW_Tracer_Check();
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//4
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKCRVL_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKCRVL_TIBIA_L[2]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKCRVL_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKCRVL_TIBIA_R[1]);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKCRVL_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKCRVL_TIBIA_L[0]);
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKCRVL_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKCRVL_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKCRVL_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

							//BW_Tracer_Check();
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//5
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
							//BW_Tracer_Check();

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//6
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKCRVL_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKCRVL_TIBIA_R[2]-5);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKCRVL_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKCRVL_TIBIA_L[1]-5);
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKCRVL_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKCRVL_TIBIA_R[0]+5);
							//BW_Tracer_Check();
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKCRVL_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKCRVL_TIBIA_L[0]);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKCRVL_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKCRVL_TIBIA_R[1]);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKCRVL_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKCRVL_TIBIA_L[2]);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

							//1
							//TRIPOD A
							Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKCRVL_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKCRVL_TIBIA_R[2]);
							Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKCRVL_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKCRVL_TIBIA_L[1]);
							Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKCRVL_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKCRVL_TIBIA_R[0]);
							//TRIPOD B
							Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKCRVL_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKCRVL_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
							Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKCRVL_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/

		}break;
	}

	Bumper_Action();
}

/* func      : 	void Dynamx_MovFwd3cm_Reverse (int distance, int SPEED)
 * brief     : 	Dynamixel Hexapod Forward locomotion using tripod gait
 * param     :	unsigned int distance  	-> Travel distance multiplication of 3
 * 				unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 *
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By: N/A
 * Programmer's Note:
 *
 */
void Dynamx_MovFwd3cm_Reverse (int distance, int SPEED, int IKCALC_STAT)
{
	int limit= distance/3;
	int loop;

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,3,9);
			delay_ms(50);
			for (loop=1;loop<=limit;loop++)
				{
					//DEFAULT
					Sendto_PC(USART1,"================ START OF BACKWARD TRIPOD GAIT SEQUENCES ================ \r");

					//VER 2
					Sendto_PC(USART1,"<======== STEP 1 \r");
					//1
					//Tripod A
					Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); //BELAKANG MENAPAK
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);

			    	Sendto_PC(USART1,"<======== STEP 2 \r");
			    	//2
			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);

			    	Sendto_PC(USART1,"<======== STEP 3 \r");
			    	//3
			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); //DEPAN MENAPAK
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);


			    	Sendto_PC(USART1,"<======== STEP 4 \r");

			    	//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);

			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //DEPAN ANGKAT
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);


			    	Sendto_PC(USART1,"<======== STEP 5 \r");
			    	//5
			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);

			    	Sendto_PC(USART1,"<======== STEP 6 \r");
			    	//6
			    	//Tripod A
			    	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2);
			    	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
			    	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);

			    	//Tripod B
			    	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);
			    	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
			    	Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);

			    	Sendto_PC(USART1,"================ END OF BACKWARD TRIPOD GAIT SEQUENCES ================ \r\r");
				}

		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{
					//1
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81,14,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69,14,108);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74,14,108);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98,32,114);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,32,114);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105,32,114);

					//2
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,14,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,14,108);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,14,108);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,32,114);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,32,114);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,32,114);

					//3
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98,14,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,14,108);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105,14,108);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81,32,114);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69,32,114);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74,32,114);

					//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81,14,108);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69,14,108);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74,14,108);

					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98,32,114);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,32,114);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105,32,114);

					//5
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,32,114);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,32,114);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,32,114);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90,14,108);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,14,108);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90,14,108);

					//6
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81,32,114);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69,32,114);
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74,32,114);

					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98,14,108);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,14,108);
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105,14,108);
				}

		}break;
	}
}


/* func      : 	void Dynamx_Rot_Right_Reverse(int degree, int SPEED)
 * brief     : 	Dynamixel Hexapod Rotate Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEXSTEP_CLOSE, HEXSTEP_MED, HEXSTEP_FAR
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By:
 *
 * Programmer's Note:
 *
 */

void Dynamx_Rot_Right_Reverse(int SPEED,  int STEP)
{
	Dynamx_GenerateIK(0,STEP,9);
	delay_ms(50);

	Sendto_PC(USART1,"================ START OF ROTATE RIGHT TRIPOD GAIT SEQUENCES ================ \r");

	Sendto_PC(USART1,"<======== STEP 1 \r");
	//1
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1); //BELAKANG MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); 				//DEPAN MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);  //BELAKANG MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);

//		    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 2 \r");
    //2
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); 						//TENGAH MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);

//		    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 3 \r");
    //3
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1); //DEPAN MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); 				//BELAKANG MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1); //DEPAN MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);

//		    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 4 \r");
    //4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2); //DEPAN ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); 				//BELAKANG ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2); //DEPAN ANGKAT

//		    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 5 \r");
    //5
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); 						//TENGAH ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);

//		    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 6 \r");
    //6
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2); //BELAKANG ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); 				//BELAKANG ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);  //BELAKANG ANGKAT

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);

//		    delay_ms(1000);

    Sendto_PC(USART1,"================ END OF ROTATE RIGHT TRIPOD GAIT SEQUENCES ================ \r\r");
}

/* func      : 	void Dynamx_Rot_Left_Reverse(int degree, int SPEED)
 * brief     : 	Dynamixel Hexapod Rotate Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEXSTEP_CLOSE, HEXSTEP_MED, HEXSTEP_FAR
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By:
 *
 * Programmer's Note:
 *
 */
void Dynamx_Rot_Left_Reverse(int SPEED,  int STEP)
{
	Dynamx_GenerateIK(0,STEP,9);
	delay_ms(50);

	Sendto_PC(USART1,"================ START OF ROTATE LEFT TRIPOD GAIT SEQUENCES ================ \r");

	Sendto_PC(USART1,"<======== STEP 1 \r");
	//1
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1); //DEPAN MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); //BELAKANG MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1);  //DEPAN MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);

    Sendto_PC(USART1,"<======== STEP 2 \r");
    //2
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1);  //TENGAH MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);

    Sendto_PC(USART1,"<======== STEP 3 \r");
    //3
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1); //BELAKANG MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); //DEPAN MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);  //BELAKANG MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);

    Sendto_PC(USART1,"<======== STEP 4 \r");
    //4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);

    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2); //BELAKANG ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //DEPAN ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);  //BELAKANG ANGKAT



    Sendto_PC(USART1,"<======== STEP 5 \r");
    //5
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2);  //TENGAH ANGKAT

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);

    Sendto_PC(USART1,"<======== STEP 6 \r");
    //6
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2); //DEPAN ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);  //DEPAN ANGKAT

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);

    Sendto_PC(USART1,"================ END OF ROTATE LEFT TRIPOD GAIT SEQUENCES ================ \r\r");
}


/* func      : 	void Dynamx_CurveRight_PID_Reverse(int SPEED, int STEP, float *ACTUATE_SIGNAL)
 * brief     : 	Dynamixel Hexapod Curve Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				float *ACTUATE_SIGNAL	-> PID Value from PID calculations
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By: Toni (Monday, October 30 2017)
 * Programmer's Note:
 *
 */
void Dynamx_CurveRight_PID_Reverse(int SPEED, int STEP, float *ACTUATE_SIGNAL, int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Right PID \r");

	float signal=*ACTUATE_SIGNAL/5;
	float error_L,error;
	if (signal>=IKPIDR_TIBIA_L[2]){error_L=IKPIDR_TIBIA_L[2];}
	else {error_L=signal;}

	float DELTA_L=0 + (1 * error_L);

	int DELTA_L0 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_COXA_L[0];
	int DELTA_L1 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_COXA_L[1];
	int DELTA_L2 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_COXA_L[2];
	int DELTA_L3 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_TIBIA_L[0];
	int DELTA_L4 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_TIBIA_L[1];
	int DELTA_L5 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_TIBIA_L[2];

	float DELTA_FL=5 + (1 * error);
	float DELTA_FR=0 + (1 * error);
	float DELTA_ML=5 + (1 * error);
	float DELTA_MR=0 + (1 * error);
	float DELTA_RL=5 + (1 * error);
	float DELTA_RR=0 + (1 * error);

//	lcd_gotoxy(0,0);sprintf(lcd,"act signal: %f",*ACTUATE_SIGNAL);lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"signal: %f",signal);lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd,"FL: %f",DELTA_FL);lcd_putstr(lcd);
//	lcd_gotoxy(7,2);sprintf(lcd,"FR: %f",DELTA_FR);lcd_putstr(lcd);
//	lcd_gotoxy(3,3);sprintf(lcd,"CURVE LEFT");lcd_putstr(lcd);

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,STEP,9);
			delay_ms(50);

			Sendto_PC(USART1,"================ START OF CURVE LEFT TRIPOD GAIT SEQUENCES ================ \r");

			Sendto_PC(USART1,"<======== STEP 1 \r");
			//1
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]-DELTA_FR,4,leg-1);
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]+DELTA_ML,4,leg-1);
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]-DELTA_RR,4,leg-1);

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

		    Sendto_PC(USART1,"<======== STEP 2 \r");
		    //2
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,4,leg-1);
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,4,leg-1); //TENGAH MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+DELTA_RR,4,leg-1);

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+DELTA_FL,1,leg-2);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-DELTA_MR,1,leg-2);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+DELTA_RL,1,leg-2);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

		    Sendto_PC(USART1,"<======== STEP 3 \r");
		    //3
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5]+DELTA_FR,4,leg-1);
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]-DELTA_ML,4,leg-1); //BELAKANG MENAPAK
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3]+DELTA_RR,4,leg-1);

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]+DELTA_FL,1,leg-2);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA_MR,1,leg-2);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]+DELTA_RL,1,leg-2);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

		    Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
		    //4
		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]+DELTA_FL,4,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA_MR,4,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]+DELTA_RL,4,leg-1);

		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //BELAKANG ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

		    Sendto_PC(USART1,"<======== STEP 5 \r");
		    //5
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,1,leg-2);
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,1,leg-2); //TENGAH ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-DELTA_RR,1,leg-2);

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-DELTA_FL,4,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+DELTA_MR,4,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-DELTA_RL,4,leg-1);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

		    Sendto_PC(USART1,"<======== STEP 6 \r");
		    //6
		    //Tripod A
		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]-DELTA_FR,1,leg-2);
		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]+DELTA_ML,1,leg-2); //DEPAN ANGKAT
		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]-DELTA_RR,1,leg-2);

		    //Tripod B
		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2]-DELTA_FL,4,leg-1);
		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA_MR,4,leg-1);
		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0]-DELTA_RL,4,leg-1);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

		    Sendto_PC(USART1,"================ END OF CURVE LEFT TRIPOD GAIT SEQUENCES ================ \r\r");
		}break;

		case IKCALC_DISABLE:
		{

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);


			if (Ping[PING_REAR]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;


			//4
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]-DELTA_L3);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);		//depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]+DELTA_L5);
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4-5);	//belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]+5);
			//					delay_ms(2000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]-DELTA_L3);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);		//depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]+DELTA_L5);
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4-5);	//belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]+5);
			//					delay_ms(2000);

			if (Ping[PING_REAR]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4);	//belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4);	//belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

			if (Ping[PING_REAR]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

			if (Ping[PING_REAR]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]+DELTA_L5-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]-5);	//belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]-DELTA_L3+5);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]+DELTA_L5-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]-5);	//belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]-DELTA_L3+5);
			//BW_Tracer_Check();

			if (Ping[PING_REAR]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]+DELTA_L5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);	//belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]-DELTA_L3);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]+DELTA_L5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);	//belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]-DELTA_L3);

			if (Ping[PING_REAR]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

/*
			//	zR = 15 ZL = 12
			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);

			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76+DELTA_L118,35,98+DELTA_L117); //belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
			//					delay_ms(2000);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99-DELTA_L116,24,117-DELTA_L115);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96-DELTA_L113,20,91+DELTA_L119);
			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76+DELTA_L118,35,98+DELTA_L117); //belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
			//					delay_ms(2000);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99-DELTA_L116,24,117-DELTA_L115);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96-DELTA_L113,20,91+DELTA_L119);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76+DELTA_L118,20,103+DELTA_L112); //belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99-DELTA_L116,39,120);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96-DELTA_L113,35,122);

			//					delay_ms(2000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76+DELTA_L118,20,103+DELTA_L112); //belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99-DELTA_L116,39,120);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96-DELTA_L113,35,122);

			//					delay_ms(2000);


			//TRIPOD A kaki 5cm

			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
			//BW_Tracer_Check();

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104-DELTA_L118,20,103+DELTA_L112); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84+DELTA_L113,39,89+DELTA_L);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_L116,35,122-DELTA_L1110);
			//					delay_ms(2000);
			//BW_Tracer_Check();

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104-DELTA_L118,20,103+DELTA_L112); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84+DELTA_L113,39,89+DELTA_L);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_L116,35,122-DELTA_L1110);
			//					delay_ms(2000);
			//BW_Tracer_Check();


			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104-DELTA_L118,35,120); //depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84+DELTA_L113,24,91+DELTA_L119);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_L116,20,115-DELTA_L113);
			//					delay_ms(2000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104-DELTA_L118,35,120); //depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84+DELTA_L113,24,91+DELTA_L119);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_L116,20,115-DELTA_L113);

			//					delay_ms(2000);
*/
//===========================================================================================///
/*			//	zR = 15 ZL = 5
						//5
						//TRIPOD A
						Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
						Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
						//TRIPOD B
						Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
						Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);

						//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

						//TRIPOD A
						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,35,105); //belakang angkat
						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
						//					delay_ms(2000);

						//TRIPOD B
						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,24,112);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,20,100);

						//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

						//TRIPOD A
						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,35,105); //belakang angkat
						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
						//					delay_ms(2000);

						//TRIPOD B
						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,24,112);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,20,100);

						//3
						//TRIPOD A
						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,20,105); //belakang menapak
						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

						//TRIPOD B
						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,39,120);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,35,122);

						//					delay_ms(2000);

						//3
						//TRIPOD A
						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,20,105); //belakang menapak
						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

						//TRIPOD B
						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,39,120);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,35,122);

						//					delay_ms(2000);


						//TRIPOD A kaki 5cm

						Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
						Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);

						//TRIPOD B
						Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
						Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
						//BW_Tracer_Check();

						//1
						//TRIPOD A
						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,20,105); //depan menapak
						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

						//TRIPOD B
						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,39,100);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,35,112);
						//					delay_ms(2000);
						//BW_Tracer_Check();

						//1
						//TRIPOD A
						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,20,105); //depan menapak
						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

						//TRIPOD B
						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,39,95);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,35,117);
						//					delay_ms(2000);
						//BW_Tracer_Check();

						//6
						//TRIPOD A
						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,35,120); //depan angkat
						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

						//TRIPOD B
						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,24,100);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,20,112);

						//					delay_ms(2000);

						//6
						//TRIPOD A
						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,35,120); //depan angkat
						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

						//TRIPOD B
						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,24,100);
						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,20,112);

						//					delay_ms(2000);
*/
	///===========================================================================================//

/*			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81-DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69+DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74-DELTA_FR,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98,32,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,32,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105,32,114);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90+DELTA_FR,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90+DELTA_FR,32,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90-DELTA_ML,32,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90+DELTA_FR,32,114);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98+DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110-DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105+DELTA_FR,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_FR,32,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69-DELTA_ML,32,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74+DELTA_FR,32,114);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69-DELTA_MR,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74+DELTA_FR,14,108);

			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98,32,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,32,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105,32,114);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90-DELTA_MR,32,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,32,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90-DELTA_MR,32,114);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90-DELTA_MR,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90+DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90-DELTA_MR,14,108);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81-DELTA_FR,32,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69+DELTA_ML,32,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74-DELTA_FR,32,114);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98-DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110+DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105-DELTA_FR,14,108);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/
		}break;
	}

}


/* func      : 	void Dynamx_CurveRight_Reverse(int SPEED, int STEP)
 * brief     : 	Dynamixel Hexapod Curve Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By: Toni (Monday, October 30 2017)
 * Programmer's Note:
 *
 */
void Dynamx_CurveRight_Reverse(int SPEED, int STEP , int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Right PID \r");

	unsigned int DELTA_FL=5;
	unsigned int DELTA_FR=0;
	unsigned int DELTA_ML=5;
	unsigned int DELTA_MR=0;
	unsigned int DELTA_RL=5;
	unsigned int DELTA_RR=0;

//	lcd_gotoxy(0,0);sprintf(lcd,"act signal: %f",*ACTUATE_SIGNAL);lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"signal: %f",signal);lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd,"FL: %f",DELTA_FL);lcd_putstr(lcd);
//	lcd_gotoxy(7,2);sprintf(lcd,"FR: %f",DELTA_FR);lcd_putstr(lcd);
//	lcd_gotoxy(3,3);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);
	switch(IKCALC_STAT)
		{
			case IKCALC_ENABLE:
			{
				Dynamx_GenerateIK(0,STEP,9);
				delay_ms(50);

				Sendto_PC(USART1,"================ START OF CURVE RIGHT TRIPOD GAIT SEQUENCES ================ \r");

				Sendto_PC(USART1,"<======== STEP 1 \r");
				//1
				//Tripod A
				Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]+DELTA_FR,4,leg-1);
				Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA_ML,4,leg-1); //DEPAN MENAPAK
				Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]+DELTA_RR,4,leg-1);

				//Tripod B
				Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
				Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
				Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);

				//    delay_ms(1000);

				Sendto_PC(USART1,"<======== STEP 2 \r");
				//2
				//Tripod A
				Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,4,leg-1);
				Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,4,leg-1); //TENGAH MENAPAK
				Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-DELTA_RR,4,leg-1);

				//Tripod B
				Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-DELTA_FL,1,leg-2);
				Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+DELTA_MR,1,leg-2);
				Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-DELTA_RL,1,leg-2);

				//    delay_ms(1000);

				Sendto_PC(USART1,"<======== STEP 3 \r");
				//3
				//Tripod A
				Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5]-DELTA_FR,4,leg-1);
				Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA_ML,4,leg-1); //BELAKANG MENAPAK
				Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3]-DELTA_RR,4,leg-1);

				//Tripod B
				Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]-DELTA_FL,1,leg-2);
				Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]+DELTA_MR,1,leg-2);
				Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]-DELTA_RL,1,leg-2);

				//    delay_ms(1000);

				Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
				//4
				//Tripod B
				Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]-DELTA_FL,4,leg-1);
				Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]+DELTA_MR,4,leg-1);
				Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]-DELTA_RL,4,leg-1);

				//Tripod A
				Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);
				Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //BELAKANG ANGKAT
				Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);

					//    delay_ms(1000);

				Sendto_PC(USART1,"<======== STEP 5 \r");
				//5
				//Tripod A
				Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,1,leg-2);
				Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,1,leg-2); //TENGAH ANGKAT
				Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+DELTA_RR,1,leg-2);

				//Tripod B
				Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+DELTA_FL,4,leg-1);
				Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-DELTA_MR,4,leg-1);
				Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+DELTA_RL,4,leg-1);

				//    delay_ms(1000);

				Sendto_PC(USART1,"<======== STEP 6 \r");
				//6
				//Tripod A
				Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]+DELTA_FR,1,leg-2);
				Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA_ML,1,leg-2); //DEPAN ANGKAT
				Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]+DELTA_RR,1,leg-2);

				//Tripod B
				Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2]+DELTA_FL,4,leg-1);
				Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]-DELTA_MR,4,leg-1);
				Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0]+DELTA_RL,4,leg-1);

				//    delay_ms(1000);

    Sendto_PC(USART1,"================ END OF CURVE RIGHT TRIPOD GAIT SEQUENCES ================ \r\r");
			}break;

		case IKCALC_DISABLE:
			{
				//				====== ZR=35 & ZL=5 TIBIA ZR=25 ZL=5 ======
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKCRVRR_COXA_L[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKCRVRR_TIBIA_L[0]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKCRVRR_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKCRVRR_TIBIA_R[1]);		//depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKCRVRR_COXA_L[0],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKCRVRR_TIBIA_L[2]);
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKCRVRR_COXA_R[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKCRVRR_TIBIA_R[2]-5);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKCRVRR_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKCRVRR_TIBIA_L[1]-5);	//belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKCRVRR_COXA_R[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKCRVRR_TIBIA_R[0]+5);
				//					delay_ms(2000);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKCRVRR_COXA_R[0],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKCRVRR_TIBIA_R[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKCRVRR_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKCRVRR_TIBIA_L[1]);	//belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKCRVRR_COXA_R[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKCRVRR_TIBIA_R[0]);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKCRVRR_COXA_L[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKCRVRR_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKCRVRR_COXA_L[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

				if (Ping[PING_REAR]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKCRVRR_COXA_R[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKCRVRR_TIBIA_R[0]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKCRVRR_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKCRVRR_TIBIA_L[1]); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKCRVRR_COXA_R[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKCRVRR_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKCRVRR_COXA_L[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKCRVRR_TIBIA_L[2]-5);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKCRVRR_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKCRVRR_TIBIA_R[1]-5);	//belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKCRVRR_COXA_L[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKCRVRR_TIBIA_L[0]+5);

				//BW_Tracer_Check();
				if (Ping[PING_REAR]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKCRVRR_COXA_R[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+IKCRVRR_TIBIA_R[0]+5);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKCRVRR_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKCRVRR_TIBIA_L[1]-5);	//depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKCRVRR_COXA_R[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]-IKCRVRR_TIBIA_R[2]-5);
				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKCRVRR_COXA_L[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKCRVRR_TIBIA_L[2]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKCRVRR_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKCRVRR_TIBIA_R[1]);	//belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKCRVRR_COXA_L[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKCRVRR_TIBIA_L[0]);

				if (Ping[PING_REAR]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

/*
 *				//double step
 				//	zR = 15 ZL = 5
				//5
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);

				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,35,105); //belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
				//					delay_ms(2000);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,24,112);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,20,100);

				//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,35,105); //belakang angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
				//					delay_ms(2000);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,24,112);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,20,100);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,20,105); //belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,35,122);

				//					delay_ms(2000);

				//3
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,20,105); //belakang menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,35,122);

				//					delay_ms(2000);


				//TRIPOD A kaki 5cm

				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
				//BW_Tracer_Check();

				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,20,105); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,39,100);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,35,112);
				//					delay_ms(2000);
				//BW_Tracer_Check();

				//1
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,20,105); //depan menapak
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,39,95);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,35,117);
				//					delay_ms(2000);
				//BW_Tracer_Check();

				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,35,120); //depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,24,100);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,20,112);

				//					delay_ms(2000);

				//6
				//TRIPOD A
				Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,35,120); //depan angkat
				Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);

				//TRIPOD B
				Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,24,100);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
				Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,20,112);

				//					delay_ms(2000);
*/
			}break;
		}

}


/* func      : 	void Dynamx_CurveLeft_PID_Reverse(int SPEED, int STEP, float *ACTUATE_SIGNAL)
 * brief     : 	Dynamixel Hexapod Curve Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				float *ACTUATE_SIGNAL	-> PID Value from PID calculations
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By: Toni (Monday, October 30 2017)
 * Programmer's Note:
 *
 */
void Dynamx_CurveLeft_PID_Reverse(int SPEED, int STEP, float *ACTUATE_SIGNAL, int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Left PID \r");

	float signal=*ACTUATE_SIGNAL/5;
	float error_L,error_R,error;
//	if (signal>=18){error_R=18;}
//	if (signal>=5){error_L=5;}
	if (signal>=IKPIDR_TIBIA_R[2]){error_R=IKPIDR_TIBIA_R[2];}
	//if (signal>=7){error_L=7;}
	else {error_R=signal;}

	float DELTA_R=0 + (1 * error_R);

	int DELTA_R0 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_COXA_R[0];
	int DELTA_R1 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_COXA_R[1];
	int DELTA_R2 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_COXA_R[2];
	int DELTA_R3 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_TIBIA_R[0];
	int DELTA_R4 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_TIBIA_R[1];
	int DELTA_R5 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_TIBIA_R[2];

	float DELTA_FL=0 + (1 * error);
	float DELTA_FR=5 + (1 * error);
	float DELTA_ML=0 + (1 * error);
	float DELTA_MR=5 + (1 * error);
	float DELTA_RL=0 + (1 * error);
	float DELTA_RR=5 + (1 * error);

//	lcd_gotoxy(0,0);sprintf(lcd,"act signal: %f",*ACTUATE_SIGNAL);lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"signal: %f",signal);lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd,"FL: %f",DELTA_FL);lcd_putstr(lcd);
//	lcd_gotoxy(7,2);sprintf(lcd,"FR: %f",DELTA_FR);lcd_putstr(lcd);
//	lcd_gotoxy(3,3);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
			Dynamx_GenerateIK(0,STEP,9);
			delay_ms(50);

			Sendto_PC(USART1,"================ START OF CURVE RIGHT TRIPOD GAIT SEQUENCES ================ \r");

			Sendto_PC(USART1,"<======== STEP 1 \r");
			//1
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]+DELTA_FR,4,leg-1);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA_ML,4,leg-1); //DEPAN MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]+DELTA_RR,4,leg-1);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			Tracer_Check();

			Sendto_PC(USART1,"<======== STEP 2 \r");
			//2
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,4,leg-1);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,4,leg-1); //TENGAH MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-DELTA_RR,4,leg-1);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-DELTA_FL,1,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+DELTA_MR,1,leg-2);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-DELTA_RL,1,leg-2);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			Tracer_Check();

			Sendto_PC(USART1,"<======== STEP 3 \r");
			//3
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5]-DELTA_FR,4,leg-1);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA_ML,4,leg-1); //BELAKANG MENAPAK
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3]-DELTA_RR,4,leg-1);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]-DELTA_FL,1,leg-2);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]+DELTA_MR,1,leg-2);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]-DELTA_RL,1,leg-2);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			Tracer_Check();

			Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
			//4
			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]-DELTA_FL,4,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]+DELTA_MR,4,leg-1);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]-DELTA_RL,4,leg-1);

			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //BELAKANG ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			Tracer_Check();

			Sendto_PC(USART1,"<======== STEP 5 \r");
			//5
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,1,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,1,leg-2); //TENGAH ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+DELTA_RR,1,leg-2);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+DELTA_FL,4,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-DELTA_MR,4,leg-1);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+DELTA_RL,4,leg-1);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			Tracer_Check();

			Sendto_PC(USART1,"<======== STEP 6 \r");
			//6
			//Tripod A
			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]+DELTA_FR,1,leg-2);
			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA_ML,1,leg-2); //DEPAN ANGKAT
			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]+DELTA_RR,1,leg-2);

			//Tripod B
			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2]+DELTA_FL,4,leg-1);
			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]-DELTA_MR,4,leg-1);
			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0]+DELTA_RL,4,leg-1);

		//    delay_ms(1000);
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			Tracer_Check();

			Sendto_PC(USART1,"================ END OF CURVE RIGHT TRIPOD GAIT SEQUENCES ================ \r\r");
		}break;

		case IKCALC_DISABLE:
		{

			//				====== Z=35 TIBIA Z=25 ======
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);


			if (Ping[PING_REAR]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4);		//depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]);
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]+DELTA_R5-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]-5);	//belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]-DELTA_R3+5);
			//					delay_ms(2000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4);		//depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]);
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]+DELTA_R5-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]-5);	//belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]-DELTA_R3+5);
			//					delay_ms(2000);

			if (Ping[PING_REAR]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]+DELTA_R5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]);	//belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]-DELTA_R3);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]+DELTA_R5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]);	//belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]-DELTA_R3);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

			if (Ping[PING_REAR]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

			if (Ping[PING_REAR]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]-DELTA_R3);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]+DELTA_R5);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4-5);	//belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]+5);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]-DELTA_R3);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]+DELTA_R5);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4-5);	//belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]+5);
			//BW_Tracer_Check();

			if (Ping[PING_REAR]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4);	//belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4);	//belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]);

			if (Ping[PING_REAR]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
/*
			//	zR = 15 ZL = 12
			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);

			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83+DELTA_R184,35,85+DELTA_R);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76-DELTA_L53,35,98-DELTA_L51); //belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78+DELTA_R189,38,125-DELTA_R1812);
			//					delay_ms(2000);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99+DELTA_L53,24,117+DELTA_L52);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107-DELTA_R1811,20,103+DELTA_R182); //depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96+DELTA_L51,20,91-DELTA_L54);

			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83+DELTA_R184,35,85+error_R);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76-DELTA_L53,35,98-DELTA_L51); //belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78+DELTA_R189,38,125-DELTA_R1812);
			//					delay_ms(2000);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99+DELTA_L53,24,117+DELTA_L52);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107-DELTA_R1811,20,103+DELTA_R182); //depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96+DELTA_L51,20,91-DELTA_L54);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83+DELTA_R184,20,90+DELTA_R1813);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76-DELTA_L53,20,103-DELTA_L51); //belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78+DELTA_R1811,23,120-DELTA_R187);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99+DELTA_L53,39,120);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107-DELTA_R1811,35,128); //depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96+DELTA_L51,35,122);

			//					delay_ms(2000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83+DELTA_R184,20,90+DELTA_R1813);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76-DELTA_L53,20,103-DELTA_L51); //belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78+DELTA_R1811,23,120-DELTA_R187);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99+DELTA_L53,39,120);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107-DELTA_R1811,35,128); //depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96+DELTA_L51,35,122);

			//					delay_ms(2000);

			//TRIPOD A kaki 5cm

			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
			//BW_Tracer_Check();

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102-DELTA_R189,20,120-DELTA_R187);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104+DELTA_L53,20,103); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97-DELTA_R184,23,90+DELTA_R1813);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84-DELTA_L51,39,89-DELTA_L);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73+DELTA_R1811,35,102); //belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_L53,35,122-DELTA_L);
			//					delay_ms(2000);
			//BW_Tracer_Check();

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102-DELTA_R189,20,120-DELTA_R187);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104+DELTA_L53,20,103); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97-DELTA_R184,23,90+DELTA_R1813);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84-DELTA_L51,39,89-DELTA_L);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73+DELTA_R1811,35,102); //belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_L53,35,122-DELTA_L);
			//					delay_ms(2000);
			//BW_Tracer_Check();


			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102-DELTA_R189,35,126);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104+DELTA_L53,35,120); //depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97-DELTA_R184,38,126);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84-DELTA_L51,24,91-DELTA_L52);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73+DELTA_R1811,20,107); //belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_L53,20,115+DELTA_L52);

			//					delay_ms(2000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102-DELTA_R189,35,126);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104+DELTA_L53,35,120); //depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97-DELTA_R184,38,126);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84-DELTA_L51,24,91-DELTA_L52);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73+DELTA_R1811,20,107); //belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_L53,20,115+DELTA_L52);

			//					delay_ms(2000);
*/
//==================================================================================//
/*			//	zR = 5 ZL = 15
			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);

			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,35,103);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,35,97); //belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,38,113);
			//					delay_ms(2000);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,24,119);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,20,105); //depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,20,87);

			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,35,103);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,35,102); //belakang angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,38,113);
			//					delay_ms(2000);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,24,119);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,20,105); //depan menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,20,87);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,20,103);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,20,102); //belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,23,113);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,39,120);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,35,128); //depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,35,122);

			//					delay_ms(2000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,20,103);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,20,102); //belakang menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,23,113);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,39,120);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,35,128); //depan angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,35,122);

			//					delay_ms(2000);


			//TRIPOD A kaki 5cm

			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
			//BW_Tracer_Check();

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,20,113);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,20,102); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,23,90);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,39,84);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,35,105); //belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,35,122);
			//					delay_ms(2000);
			//BW_Tracer_Check();

			//1
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,20,113);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,20,102); //depan menapak
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,23,103);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,39,84);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,35,105); //belakang angkat
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,35,122);
			//					delay_ms(2000);
			//BW_Tracer_Check();

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,35,126);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,35,120); //depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,38,126);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,24,89);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,20,105); //belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,20,117);

			//					delay_ms(2000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,35,126);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,35,120); //depan angkat
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,38,126);

			//TRIPOD B
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,24,89);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,20,105); //belakang menapak
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,20,117);

			//					delay_ms(2000);

*/
//============================================================================================//
/*			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81+DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69-DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74+DELTA_FR,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98,32,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,32,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105,32,114);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90-DELTA_FR,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90-DELTA_FR,32,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90+DELTA_ML,32,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90-DELTA_FR,32,114);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98-DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110+DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105-DELTA_FR,14,108);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_FR,32,114);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69+DELTA_ML,32,114);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74-DELTA_FR,32,114);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69+DELTA_MR,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74-DELTA_FR,14,108);

			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98,32,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,32,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105,32,114);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90+DELTA_MR,32,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,32,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90+DELTA_MR,32,114);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90+DELTA_MR,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90-DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90+DELTA_MR,14,108);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81+DELTA_FR,32,114);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69-DELTA_ML,32,114);
			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74+DELTA_FR,32,114);

			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98+DELTA_FR,14,108);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110-DELTA_ML,14,108);
			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105+DELTA_FR,14,108);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
*/
		}break;
	}
}


/* func      : 	void Dynamx_CurveLeft_Reverse(int SPEED, int STEP)
 * brief     : 	Dynamixel Hexapod Curve Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By: Toni (Monday, October 30 2017)
 * Programmer's Note:
 *
 */
void Dynamx_CurveLeft_Reverse(int SPEED, int STEP , int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Left PID \r");



	unsigned int DELTA_FL=0;
	unsigned int DELTA_FR=5;
	unsigned int DELTA_ML=0;
	unsigned int DELTA_MR=5;
	unsigned int DELTA_RL=0;
	unsigned int DELTA_RR=5;

//	lcd_gotoxy(0,0);sprintf(lcd,"act signal: %f",*ACTUATE_SIGNAL);lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"signal: %f",signal);lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd,"FL: %f",DELTA_FL);lcd_putstr(lcd);
//	lcd_gotoxy(7,2);sprintf(lcd,"FR: %f",DELTA_FR);lcd_putstr(lcd);
//	lcd_gotoxy(3,3);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);
	switch(IKCALC_STAT)
			{
				case IKCALC_ENABLE:
				{
					Dynamx_GenerateIK(0,STEP,9);
					delay_ms(50);

					Sendto_PC(USART1,"================ START OF CURVE LEFT TRIPOD GAIT SEQUENCES ================ \r");

	Sendto_PC(USART1,"<======== STEP 1 \r");
	//1
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA_FR,4,leg-1);
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]+DELTA_ML,4,leg-1); //DEPAN MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA_RR,4,leg-1);

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);

//    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 2 \r");
    //2
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,4,leg-1);
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,4,leg-1); //TENGAH MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-DELTA_RR,4,leg-1);

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-DELTA_FL,1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+DELTA_MR,1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-DELTA_RL,1,leg-2);

//    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 3 \r");
    //3
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]+DELTA_FR,4,leg-1);
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]-DELTA_ML,4,leg-1); //BELAKANG MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]+DELTA_RR,4,leg-1);

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]+DELTA_FL,1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA_MR,1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]+DELTA_RL,1,leg-2);

//    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
    //4
    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]+DELTA_FL,4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA_MR,4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]+DELTA_RL,4,leg-1);

    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //BELAKANG ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);

//    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 5 \r");
    //5
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,1,leg-2);
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,1,leg-2); //TENGAH ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+DELTA_RR,1,leg-2);

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+DELTA_FL,4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-DELTA_MR,4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+DELTA_RL,4,leg-1);

//    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 6 \r");
    //6
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]-DELTA_FR,1,leg-2);
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]+DELTA_ML,1,leg-2); //DEPAN ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]-DELTA_RR,1,leg-2);

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]-DELTA_FL,4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA_MR,4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]-DELTA_RL,4,leg-1);

//    delay_ms(1000);

    Sendto_PC(USART1,"================ END OF CURVE LEFT TRIPOD GAIT SEQUENCES ================ \r\r");
				}break;

			case IKCALC_DISABLE:
				{
					//				====== ZR=35 & ZL=5 TIBIA ZR=25 ZL=5 ======
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

									//5
									//TRIPOD A
									Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
									Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
									Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
									//TRIPOD B
									Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);
									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
									Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);


									if (Ping[PING_REAR]<=15)break;
									//BW_Tracer_Check();

									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;


									//4
									//TRIPOD B
									Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKCRVLR_COXA_L[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKCRVLR_TIBIA_L[0]);
									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKCRVLR_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKCRVLR_TIBIA_R[1]);		//depan menapak
									Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKCRVLR_COXA_L[0],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKCRVLR_TIBIA_L[2]);
									//TRIPOD A
									Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKCRVLR_COXA_R[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKCRVLR_TIBIA_R[2]-5);
									Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKCRVLR_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKCRVLR_TIBIA_L[1]-5);	//belakang angkat
									Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKCRVLR_COXA_R[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKCRVLR_TIBIA_R[0]+5);
									//					delay_ms(2000);

									if (Ping[PING_REAR]<=15)break;
									//BW_Tracer_Check();
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

									//3
									//TRIPOD A
									Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKCRVLR_COXA_R[0],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKCRVLR_TIBIA_R[2]);
									Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKCRVLR_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKCRVLR_TIBIA_L[1]);	//belakang menapak
									Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKCRVLR_COXA_R[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKCRVLR_TIBIA_R[0]);

									//TRIPOD B
									Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKCRVLR_COXA_L[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKCRVLR_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
									Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKCRVLR_COXA_L[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
									if (Ping[PING_REAR]<=15)break;
									//BW_Tracer_Check();
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

									//2
									//TRIPOD A
									Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
									Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
									Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);

									//TRIPOD B
									Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
									Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);

									if (Ping[PING_REAR]<=15)break;
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

									//1
									//TRIPOD A
									Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKCRVLR_COXA_R[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKCRVLR_TIBIA_R[0]);
									Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKCRVLR_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKCRVLR_TIBIA_L[1]); //depan menapak
									Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKCRVLR_COXA_R[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKCRVLR_TIBIA_R[2]);
									//TRIPOD B
									Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKCRVLR_COXA_L[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKCRVLR_TIBIA_L[2]-5);
									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKCRVLR_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKCRVLR_TIBIA_R[1]-5);	//belakang angkat
									Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKCRVLR_COXA_L[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKCRVLR_TIBIA_L[0]+5);

									//BW_Tracer_Check();
									if (Ping[PING_REAR]<=15)break;
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

									//6
									//TRIPOD A
									Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKCRVLR_COXA_R[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+IKCRVLR_TIBIA_R[0]+5);
									Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKCRVLR_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKCRVLR_TIBIA_L[1]-5);	//depan angkat
									Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKCRVLR_COXA_R[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]-IKCRVLR_TIBIA_R[2]-5);
									//TRIPOD B
									Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKCRVRR_COXA_L[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKCRVLR_TIBIA_L[2]);
									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKCRVRR_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKCRVLR_TIBIA_R[1]);	//belakang menapak
									Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKCRVRR_COXA_L[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKCRVLR_TIBIA_L[0]);

									if (Ping[PING_REAR]<=15)break;
									//BW_Tracer_Check();
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
									TCS3200_Transmit(UART5, CMD_GET_TRACER);
									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
/*
 * 					// DOUBLE STEP
 *					//	zR = 5 ZL = 15
					//5
					//TRIPOD A
					Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
					Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
					//TRIPOD B
					Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
					Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);

					//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

					//TRIPOD A
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,35,103);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,35,97); //belakang angkat
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,38,113);
					//					delay_ms(2000);

					//TRIPOD B
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,24,119);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,20,105); //depan menapak
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,20,87);

					//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

					//TRIPOD A
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,35,103);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,35,102); //belakang angkat
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,38,113);
					//					delay_ms(2000);

					//TRIPOD B
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,24,119);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,20,105); //depan menapak
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,20,87);

					//3
					//TRIPOD A
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,20,103);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,20,102); //belakang menapak
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,23,113);

					//TRIPOD B
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,39,120);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,35,128); //depan angkat
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,35,122);

					//					delay_ms(2000);

					//3
					//TRIPOD A
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,20,103);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,20,102); //belakang menapak
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,23,113);

					//TRIPOD B
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,39,120);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,35,128); //depan angkat
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,35,122);

					//					delay_ms(2000);


					//TRIPOD A kaki 5cm

					Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
					Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);

					//TRIPOD B
					Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
					Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
					//BW_Tracer_Check();

					//1
					//TRIPOD A
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,20,113);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,20,102); //depan menapak
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,23,90);

					//TRIPOD B
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,39,84);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,35,105); //belakang angkat
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,35,122);
					//					delay_ms(2000);
					//BW_Tracer_Check();

					//1
					//TRIPOD A
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,20,113);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,20,102); //depan menapak
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,23,103);

					//TRIPOD B
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,39,84);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,35,105); //belakang angkat
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,35,122);
					//					delay_ms(2000);
					//BW_Tracer_Check();

					//6
					//TRIPOD A
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,35,126);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,35,120); //depan angkat
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,38,126);

					//TRIPOD B
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,24,89);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,20,105); //belakang menapak
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,20,117);

					//					delay_ms(2000);

					//6
					//TRIPOD A
					Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,35,126);
					Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,35,120); //depan angkat
					Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,38,126);

					//TRIPOD B
					Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,24,89);
					Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,20,105); //belakang menapak
					Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,20,117);

					//					delay_ms(2000);
*/
				}break;
			}

}

void Dynamx_Extinguish_High(int SPEED)
{
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"BW Extinguish High");lcd_putstr(lcd);

//	Dynamx_GenerateIK(0,0,8);
//
//	//Tripod A
//	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,7,leg+0.4);
//	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,7,leg+0.4);
//	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,7,leg+0.4);
//
//	//Tripod B
//	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,7,leg+0.4);
//	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,7,leg+0.4);
//	Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,7,leg+0.4);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]-30,SUDUT_STATIC[2]-30);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]-30,SUDUT_STATIC[5]-30);
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]-30,SUDUT_STATIC[8]-30);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]-30,SUDUT_STATIC[11]-30);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]-30,SUDUT_STATIC[14]-30);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]-30,SUDUT_STATIC[17]-30);


	while(PWM_servo<PWM_FIRE+150)
	{
		PWM_servo+=10;
		delay_ms(25);
	}
	while(PWM_servo>PWM_FIRE-150)
	{
		PWM_servo-=10;
		delay_ms(25);
	}
	while(PWM_servo<PWM_FIRE+150)
	{
		PWM_servo+=10;
		delay_ms(25);
	}

//		delay_ms(250);
	//TRIPOD A
	Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
	Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
	Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
	//TRIPOD B
	Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
	Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
	Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);


	while(PWM_servo<PWM_FIRE+150)
	{
		PWM_servo+=10;
		delay_ms(25);
	}
	while(PWM_servo>PWM_FIRE-150)
	{
		PWM_servo-=10;
		delay_ms(25);
	}
	while(PWM_servo<PWM_FIRE+150)
	{
		PWM_servo+=10;
		delay_ms(25);
	}

//	//Tripod A
//	Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,12,leg-2);
//	Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,12,leg-2);
//	Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,12,leg-2);
//
//	//Tripod B
//	Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,12,leg-2);
//	Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,12,leg-2);
//	Dynamx_IK(REAR_LEFT_DX,		&SPEED,90,12,leg-2);

//	delay_ms(250);

}
void Dynamx_Mov_Extinguish(int SPEED)
{

	static int right=90,left=90;

//	Dynamx_GenerateIK(0,0,8);
////	delay_ms(50);

//	Get_UV();
//	Get_TPA81();
	while( right>=70 && left<=110)
	{
		//TRIPOD A
		Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,right,SUDUT_STATIC[1]-30,SUDUT_STATIC[2]-30);
		Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,left,SUDUT_STATIC[4]-30,SUDUT_STATIC[5]-30);
		Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,right,SUDUT_STATIC[7]-30,SUDUT_STATIC[8]-30);
		//TRIPOD B
		Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,left,SUDUT_STATIC[10]-30,SUDUT_STATIC[11]-30);
		Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,right,SUDUT_STATIC[13]-30,SUDUT_STATIC[14]-30);
		Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,left,SUDUT_STATIC[16]-30,SUDUT_STATIC[17]-30);

//		//Tripod A
//		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
//		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
//		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);
//
//		//Tripod B
//		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
//		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
//		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right-=5;
		left+=5;

		UVLock_Refresh();
		if(UV_state==1){EXTINGUISHER_OFF;break;}
		Get_TPA81();
		if(FIRE==1)break;
	}
	delay_ms(100);

//	Get_UV();
	Get_TPA81();
	while( right<=90 && left>=90 && FIRE == 0)
	{
		Get_TPA81();
		//Tripod A

		//TRIPOD A
		Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,right,SUDUT_STATIC[1]-30,SUDUT_STATIC[2]-30);
		Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,left,SUDUT_STATIC[4]-30,SUDUT_STATIC[5]-30);
		Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,right,SUDUT_STATIC[7]-30,SUDUT_STATIC[8]-30);
		//TRIPOD B
		Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,left,SUDUT_STATIC[10]-30,SUDUT_STATIC[11]-30);
		Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,right,SUDUT_STATIC[13]-30,SUDUT_STATIC[14]-30);
		Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,left,SUDUT_STATIC[16]-30,SUDUT_STATIC[17]-30);
//
//		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,12,leg-2);
//		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,12,leg-2);
//		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,12,leg-2);
//
//		//Tripod B
//		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,12,leg-2);
//		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,12,leg-2);
//		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,12,leg-2);

		delay_ms(20);
		right+=5;
		left-=5;

		UVLock_Refresh();
		if(UV_state==1){EXTINGUISHER_OFF;break;}
		Get_TPA81();
		if(FIRE==1)break;
	}
	delay_ms(100);

    //SEMENTARA
	Get_TPA81();
	Get_UV();
	while( right<=110 && left>=70 && UV_state==0 && FIRE == 0 )
	{
		//TRIPOD A
		Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,right,SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,left,SUDUT_STATIC[4],SUDUT_STATIC[5]);
		Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,right,SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,left,SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,right,SUDUT_STATIC[13],SUDUT_STATIC[14]);
		Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,left,SUDUT_STATIC[16],SUDUT_STATIC[17]);

//		//Tripod A
//		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,12,leg-2);
//		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,12,leg-2);
//		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,12,leg-2);
//
//		//Tripod B
//		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,12,leg-2);
//		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,12,leg-2);
//		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,12,leg-2);

		delay_ms(20);
		right+=5;
		left-=5;

		UVLock_Refresh();
		if(UV_state==1){EXTINGUISHER_OFF;break;}
		Get_TPA81();
		if(FIRE==1)break;
	}
	delay_ms(100);

	Get_UV();
	Get_TPA81();
	while(right>=90&&left<=90 && UV_state==0 && FIRE == 0)
	{
		//TRIPOD A
		Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,right,SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,left,SUDUT_STATIC[4],SUDUT_STATIC[5]);
		Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,right,SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,left,SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,right,SUDUT_STATIC[13],SUDUT_STATIC[14]);
		Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,left,SUDUT_STATIC[16],SUDUT_STATIC[17]);

//		//Tripod A
//		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
//		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
//		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);
//
//		//Tripod B
//		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
//		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
//		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right-=5;
		left+=5;

		UVLock_Refresh();
		if(UV_state==1){EXTINGUISHER_OFF;break;}
		Get_TPA81();
		if(FIRE==1)break;
	}
	delay_ms(100);


}

void Dynamx_Mov_Extinguish_High(int SPEED)
{
	static int right=90,left=90;

	Dynamx_GenerateIK(0,0,8);
	delay_ms(50);

	Get_UV();
	while( right>=70 && left<=110 )
	{
		//Tripod A
		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);

		//Tripod B
		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right-=5;
		left+=5;
		if(UV_state==1) break;
	}
	delay_ms(100);

	Get_UV();
	while( right<=90 && left>=90 )
	{
		//Tripod A
		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);

		//Tripod B
		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right+=5;
		left-=5;
		if(UV_state==1) break;
	}
	delay_ms(100);

	Get_UV();
	while( right<=110 && left>=70 )
	{
		//Tripod A
		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);

		//Tripod B
		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right+=5;
		left-=5;
		if(UV_state==1) break;
	}
	delay_ms(100);

	Get_UV();
	while(right>=90&&left<=90&&UV_state==0)
	{
		//Tripod A
		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);

		//Tripod B
		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right-=5;
		left+=5;
		if(UV_state==1) break;
	}
	delay_ms(100);
}
void Dynamx_Mov_Tracking(int SPEED)
{
	static int right=90,left=90;

	Dynamx_GenerateIK(0,0,8);
	delay_ms(50);

	Get_UV();
	while( right>=50 && left<=130 && FlameFrontDigi[0]!=4)
	{
		//Tripod A
		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);

		//Tripod B
		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right-=5;
		left+=5;
		if(UV_state==1) break;
		if(FlameFrontDigi[0]==4)break;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;
	}
	delay_ms(100);

	Get_UV();
	while( right<=90 && left>=90 && FlameFrontDigi[0]!=4)
	{
		//Tripod A
		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);

		//Tripod B
		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right+=5;
		left-=5;
		if(UV_state==1) break;
		if(FlameFrontDigi[0]==4)break;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;
	}
	delay_ms(100);

	Get_UV();
	while( right<=130 && left>=50 && FlameFrontDigi[0]!=4)
	{
		//Tripod A
		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);

		//Tripod B
		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right+=5;
		left-=5;
		if(UV_state==1) break;
		if(FlameFrontDigi[0]==4)break;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;
	}
	delay_ms(100);

	Get_UV();
	while( right>=90 && left<=90 && FlameFrontDigi[0]!=4)
	{
		//Tripod A
		Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(REAR_RIGHT_DX,	&SPEED,right,7,leg+0.4);

		//Tripod B
		Dynamx_IK(FRONT_LEFT_DX,	&SPEED,left,7,leg+0.4);
		Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,right,7,leg+0.4);
		Dynamx_IK(REAR_LEFT_DX,		&SPEED,left,7,leg+0.4);

		delay_ms(20);
		right-=5;
		left+=5;
		if(UV_state==1) break;
		if(FlameFrontDigi[0]==4)break;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;
	}
	delay_ms(100);
}

void Dynamx_CurveRight_Flame_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL, int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Right PID \r");

	float signal=*ACTUATE_SIGNAL;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;

	if (signal>=IKFWD_TIBIA_R2[2]){error_R=IKFWD_TIBIA_R2[2];}
	else {error_R=signal;error_L=signal;}

//	if(error_R>=4) {femur_R=1;} else {femur_R=0;}
//	if(error_L>=2) {femur_L=2;} else {femur_L=0;}

//	float DELTA_L=0 + (1 * error_L);
	float DELTA_R=0 + (1 * error_R);

	int DELTA3[3];
	int DELTA2[3];
	int DELTA1[3];
	int DELTA[3];

	DELTA3[2] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R3[2];
	DELTA3[1] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R3[1];
	DELTA3[0] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R3[0];

	DELTA2[2] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R2[2];
	DELTA2[1] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R2[1];
	DELTA2[0] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R2[0];

	DELTA1[2] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R1[2];
	DELTA1[1] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R1[1];
	DELTA1[0] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R1[0];

	DELTA[2] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R[2];
	DELTA[1] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R[1];
	DELTA[0] = (DELTA_R/IKFWD_TIBIA_R2[2])*IKFWD_COXA_R[0];

////	if (signal>=23){error_L=23;}
////	if (signal>=9){error_R=9;}
//	if (signal>=IKRPID_COXA_R[2]+3){error_R=IKRPID_COXA_R[2]+3;}
//	else {error_R=signal;error_L=signal;}
//
////	if(error_R>=4) {femur_R=1;} else {femur_R=0;}
////	if(error_L>=2) {femur_L=2;} else {femur_L=0;}
//
////	float DELTA_L=0 + (1 * error_L);
//	float DELTA_R=0 + (1 * error_R);
//
//	int DELTA_R0 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_COXA_R[0];
//	int DELTA_R1 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_COXA_R[1];
//	int DELTA_R2 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_COXA_R[2];
//	int DELTA_R3 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_TIBIA_R[0];
//	int DELTA_R4 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_TIBIA_R[1];
//	int DELTA_R5 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_TIBIA_R[2];


	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
		}break;

		case IKCALC_DISABLE:
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();
//			delay_ms(5000);
			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2]+DELTA3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0]+DELTA3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1]-DELTA3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2]+DELTA2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0]+DELTA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1]-DELTA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2]+DELTA1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0]+DELTA1[0],SUDUT_STATIC[7]-6,SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1]-DELTA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]-5,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA[0],SUDUT_STATIC[7]-10,SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]-4,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1]-DELTA1[1],SUDUT_STATIC[13]-2,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2]+DELTA1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0]+DELTA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1]-DELTA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2]+DELTA2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0]+DELTA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0]-DELTA3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2]-DELTA3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1]+DELTA3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0]-DELTA3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2]-DELTA3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1]+DELTA3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0]-DELTA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2]-DELTA2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1]+DELTA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0]-DELTA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2]-DELTA1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1]+DELTA1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]-6,SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA[0],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0]-DELTA1[0],SUDUT_STATIC[1]-4,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]-2,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2]-DELTA1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1]+DELTA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0]-DELTA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2]-DELTA2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1]+DELTA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0]-DELTA3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2]-DELTA3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1]+DELTA3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
						{
							Cat_Avoider();
							if(CAT_FLAG ==CAT_DETECTED)break;
						}
			//BW_Tracer_Check();
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

/*			//====== Z=35 TIBIA Z=25 SPEED = 1700 FIX CUKUP BAGUS ======

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]-DELTA_R3);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);									//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]+DELTA_R5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]+DELTA_R4-5);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]+5);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]+DELTA_R4);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);									//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]+DELTA_R5-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]-5);										//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]-DELTA_R3+5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]+DELTA_R4);				//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]+DELTA_R5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);										//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]-DELTA_R3);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);			//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
*/

		}break;
	}
}

void Dynamx_CurveLeft_Flame_PID(int SPEED, int STEP, float *ACTUATE_SIGNAL,int IKCALC_STAT)
{
	Sendto_PC(USART1,"BW Curve Left PID \r");

	float signal=*ACTUATE_SIGNAL;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;

	if (signal>=IKFWD_TIBIA_L[2]){error_L=IKFWD_TIBIA_L[2];}
	//if (signal>=17){error_R=17;}
	else {error_R=signal;error_L=signal;}

//	if(error_R>=4) {femur_R=1;} else {femur_R=0;}
//	if(error_L>=2) {femur_L=2;} else {femur_L=0;}

	float DELTA_L=0 + (1 * error_L);
	//float DELTA_R=0 + (1 * error_R);

//
//	int DELTA_L0 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[0];
//	int DELTA_L1 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[1];
//	int DELTA_L2 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[2];
//	int DELTA_L3 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[0];
//	int DELTA_L4 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[1];
//	int DELTA_L5 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[2];

	int DELTA3[3];
	int DELTA2[3];
	int DELTA1[3];
	int DELTA[3];

	DELTA3[2] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L3[2];
	DELTA3[1] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L3[1];
	DELTA3[0] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L3[0];

	DELTA2[2] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L2[2];
	DELTA2[1] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L2[1];
	DELTA2[0] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L2[0];

	DELTA1[2] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L1[2];
	DELTA1[1] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L1[1];
	DELTA1[0] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L1[0];

	DELTA[2] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L[2];
	DELTA[1] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L[1];
	DELTA[0] = (DELTA_L/IKFWD_TIBIA_L[2])*IKFWD_COXA_L[0];


//	if (signal>=IKLPID_COXA_L[2]-1){error_L=IKLPID_COXA_L[2]-1;}
//	//if (signal>=17){error_R=17;}
//	else {error_R=signal;error_L=signal;}
//
////	if(error_R>=4) {femur_R=1;} else {femur_R=0;}
////	if(error_L>=2) {femur_L=2;} else {femur_L=0;}
//
//	float DELTA_L=0 + (1 * error_L);
//	//float DELTA_R=0 + (1 * error_R);
//
//
//	int DELTA_L0 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[0];
//	int DELTA_L1 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[1];
//	int DELTA_L2 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[2];
//	int DELTA_L3 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[0];
//	int DELTA_L4 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[1];
//	int DELTA_L5 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[2];


	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
		}break;

		case IKCALC_DISABLE:
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
			//BW_Tracer_Check();
			//			delay_ms(5000);
			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1]+DELTA3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0]-DELTA3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2]-DELTA3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//				delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1]+DELTA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0]-DELTA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2]-DELTA2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
				//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1]+DELTA1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]-6,SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0]-DELTA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2]-DELTA1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
				//			delay_ms(5000);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA[1],SUDUT_STATIC[4]-5,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]-10,SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
				//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA[0],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0]-DELTA1[0],SUDUT_STATIC[10]-4,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]-2,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2]-DELTA1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1]+DELTA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0]-DELTA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1]+DELTA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0]-DELTA3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2]-DELTA3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1]+DELTA3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
//				delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
				//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1]-DELTA3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2]+DELTA3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0]+DELTA3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1]-DELTA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2]+DELTA2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0]+DELTA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
				//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1]-DELTA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2]+DELTA1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0]+DELTA1[0],SUDUT_STATIC[16]-6,SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
				//			delay_ms(5000);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]-5,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
				//			delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			if (Ping[PING_FRONT]<=15)break;
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]-4,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1]-DELTA1[1],SUDUT_STATIC[4]-2,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2]+DELTA1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0]+DELTA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1]-DELTA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2]+DELTA2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0]+DELTA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
				//			delay_ms(5000);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1]-DELTA3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1]);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2]+DELTA3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0]+DELTA3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
//				delay_ms(5000);

			if(CAT_DETECTOR==CAT_ACTIVATED)
			{
				Cat_Avoider();
				if(CAT_FLAG ==CAT_DETECTED)break;
			}
			//BW_Tracer_Check();
			if (Ping[PING_FRONT]<=15)break;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
/*			//====== Z=35 TIBIA Z=25 SPEED = 1700 FIX CUKUP BAGUS ======
			//2
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

			//3
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]+DELTA_L4);	//belakang menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]+DELTA_L5-5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]-5);	//depan angkat
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]-DELTA_L3+5);

			//4
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]+DELTA_L5);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);		//depan menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]-DELTA_L3);
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

			//5
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);

			//6
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]-5);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]+DELTA_L4-5);	//depan angkat
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]+5);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]-DELTA_L3);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]+DELTA_L5);

			//1
			//TRIPOD A
			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]);
			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]+DELTA_L4);	//depan menapak
			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
			//TRIPOD B
			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//belakang menapak
			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
*/
		}break;
	}

	Bumper_Action();
}

void Read_HexCMD(void)
{
	int CMD_Lock;
	switch(command_code[0])
	{
		case 0x53:
		{
			Dynamx_Mov_Static(HEXSPD_MED, IKCALC_ENABLE);
			CMD_Lock=0;
		}break;
		case 0x57:
		{
			Dynamx_MovFwd3cm (15, HEXSPD_MED, IKCALC_ENABLE);
			CMD_Lock=1;
		}break;

		case 0x44:
		{
			Dynamx_Rot_Right(90,HEXSPD_MED,IKCALC_DISABLE);
			CMD_Lock=2;
		}break;

		case 0X41:
		{
			Dynamx_Rot_Left(90,HEXSPD_MED,IKCALC_DISABLE);
			CMD_Lock=3;
		}break;
	}

	switch(CMD_Lock)
	{
		case 0:
		{
			Dynamx_Mov_Static(HEXSPD_MED, IKCALC_ENABLE);
		}break;
		case 1:
		{
			Dynamx_MovFwd3cm (15, HEXSPD_MED, IKCALC_ENABLE);
		}break;

		case 2:
		{
			Dynamx_Rot_Right(90,HEXSPD_MED,IKCALC_DISABLE);
		}break;

		case 3:
		{
			Dynamx_Rot_Left(90,HEXSPD_MED,IKCALC_DISABLE);
		}break;
	}
}

void Dynamx_FollowRight_PID(int SPEED,int IKCALC_STAT)
{
	float signal=PID_F_R.pid_value[0];
	float error_L;
	float error_R;

	if (signal>=IKRPID_COXA_R[2]){error_R=IKRPID_COXA_R[2];error_L=0;}
	if (signal<=-(IKLPID_COXA_L[2]-1)){error_L=IKLPID_COXA_L[2]-1;error_R=0;}
	if (signal>0){error_R=signal;error_L=0;}
	else {error_L=-(signal);error_R=0;}

	float DELTA_R=0 + (1 * error_R);
	float DELTA_L=0 + (1 * error_L);

	int DELTA_R0 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_COXA_R[0];
	int DELTA_R1 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_COXA_R[1];
	int DELTA_R2 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_COXA_R[2];
	int DELTA_R3 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_TIBIA_R[0];
	int DELTA_R4 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_TIBIA_R[1];
	int DELTA_R5 = (DELTA_R/IKRPID_COXA_R[2])*IKRPID_TIBIA_R[2];

	int DELTA_L0 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[0];
	int DELTA_L1 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[1];
	int DELTA_L2 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_COXA_L[2];
	int DELTA_L3 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[0];
	int DELTA_L4 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[1];
	int DELTA_L5 = (DELTA_L/IKLPID_COXA_L[2])*IKLPID_TIBIA_L[2];


	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{
//			Dynamx_GenerateIK(0,STEP,9);
//			delay_ms(50);
//
//			Sendto_PC(USART1,"================ START OF CURVE RIGHT TRIPOD GAIT SEQUENCES ================ \r");
//
//			Sendto_PC(USART1,"<======== STEP 1 \r");
//			//1
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]-DELTA_FR,4,leg-1);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA_ML,4,leg-1); //DEPAN MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]-DELTA_RR,4,leg-1);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 2 \r");
//			//2
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,4,leg-1);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,4,leg-1); //TENGAH MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+DELTA_RR,4,leg-1);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+DELTA_FL,1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-DELTA_MR,1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+DELTA_RL,1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 3 \r");
//			//3
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3]+DELTA_FR,4,leg-1);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA_ML,4,leg-1); //BELAKANG MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5]+DELTA_RR,4,leg-1);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA_FL,1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]-DELTA_MR,1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]+DELTA_RL,1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
//			//4
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[0]+DELTA_FL,4,leg-1);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]-DELTA_MR,4,leg-1);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[2]+DELTA_RL,4,leg-1);
//
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 5 \r");
//			//5
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,1,leg-2);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,1,leg-2); //TENGAH ANGKAT
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-DELTA_RR,1,leg-2);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-DELTA_FL,4,leg-1);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+DELTA_MR,4,leg-1);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-DELTA_RL,4,leg-1);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 6 \r");
//			//6
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[3]-DELTA_FR,1,leg-2);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA_ML,1,leg-2); //DEPAN ANGKAT
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[5]-DELTA_RR,1,leg-2);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[0]-DELTA_FL,4,leg-1);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]+DELTA_MR,4,leg-1);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[2]-DELTA_RL,4,leg-1);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"================ END OF CURVE RIGHT TRIPOD GAIT SEQUENCES ================ \r\r");
		}break;

		case IKCALC_DISABLE:
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);

				if (Ping[PING_FRONT]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]-DELTA_R3);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]+DELTA_L4);	//belakang menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]+DELTA_R5);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]+DELTA_L5-5);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]+DELTA_R4-5);	//depan angkat
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]-DELTA_L3+5);

				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L[2]+DELTA_L5);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]+DELTA_R4);		//depan menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]-DELTA_L3);
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//belakang angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);

				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);

				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]+DELTA_R5-5);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]+DELTA_L4-5);	//depan angkat
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]-DELTA_R3+5);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]-DELTA_L3);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R[1]+DELTA_R4);				//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]+DELTA_L5);

				if (Ping[PING_FRONT]<=15)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R[2]+DELTA_R5);
				Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L[1]+DELTA_L4);	//depan menapak
				Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]-DELTA_R3);
				//TRIPOD B
				Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
				Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-SUDUT_ANGKAT);			//belakang menapak
				Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]-SUDUT_ANGKAT);

				//BW_Tracer_Check();
				if (Ping[PING_FRONT]<=15)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

///=====================================================================================
//			//		====== Z=35 TIBIA Z=25 SPEED = 1650 FIX CUKUP BAGUS ======
//						//BW_Tracer_Check();
//
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//						//TRIPOD A kaki 5cm
//						Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
//						Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
//						//TRIPOD B
//						Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
//						Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
//
//						//BW_Tracer_Check();
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//						//3
//						//TRIPOD A
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,48+DELTA_R,23,125-DELTA_R3);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,55+DELTA_L3929,20,98+DELTA_L397); //belakang menapak
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,78+DELTA_R399,20,72+DELTA_R3931);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,102-DELTA_L399,35,66+DELTA_L3931);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,125-DELTA_R3929,35,98+DELTA_R3); //depan angkat
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,132-DELTA_L,39,127-DELTA_L3);
//						//					delay_ms(2000);
//
//						//BW_Tracer_Check();
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//						//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//						//TRIPOD B
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,102-DELTA_L399,20,71+DELTA_L3931);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,125-DELTA_R3921,20,103+DELTA_R397); //depan menapak
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,132-DELTA_L,24,122-DELTA_L3);
//
//						//TRIPOD A
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,48+DELTA_R3935,38,126);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,55+DELTA_L3929,35,120); //belakang angkat
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,78+DELTA_R397,35,126);
//						//					delay_ms(2000);
//
//						//BW_Tracer_Check();
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//						//5
//						//TRIPOD A
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,38,126);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,35,120); //tengah angkat
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,35,126);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
//						Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);
//						//					delay_ms(2000);
//
//						//BW_Tracer_Check();
//
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//						//6
//						//TRIPOD A
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,102-DELTA_R399,38,67+DELTA_R3931);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,125-DELTA_L3929,35,93+DELTA_L3); //depan angkat
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,132-DELTA_R,35,130-DELTA_R3);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,48+DELTA_L,20,124-DELTA_L3);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,55+DELTA_R3929,20,103+DELTA_R397); //belakang menapak
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,78+DELTA_L399,24,69+DELTA_L3931);
//						//					delay_ms(2000);
//
//						//BW_Tracer_Check();
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//						//1
//						//TRIPOD A
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,102-DELTA_R399,23,72+DELTA_R3931);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,125-DELTA_L3929,20,98+DELTA_L397); //depan menapak
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,132-DELTA_R3937,20,125-DELTA_R3);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,48+DELTA_L3937,35,122);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,55+DELTA_R3929,35,128); //belakang angkat
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,78+DELTA_L399,39,120);
//						//					delay_ms(2000);
//						//BW_Tracer_Check();
//
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//						TCS3200_Transmit(UART5, CMD_GET_TRACER);
//						if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
////===========================================
///*						//		====== ZL = 35 && ZR = 5, TIBIA ZL=25 ZR=5 SPEED = 1650 FIX CUKUP BAGUS ======
//									//BW_Tracer_Check();
//
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//									//TRIPOD A kaki 5cm
//									Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);
//									Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
//									Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
//									//TRIPOD B
//									Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
//									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
//									Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
//
//									//BW_Tracer_Check();
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//									//3
//									//TRIPOD A
//									Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,23,113);
//									Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,55,20,103); //belakang menapak
//									Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,20,103);
//
//									//TRIPOD B
//									Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,102,35,66);
//									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,35,110); //depan angkat
//									Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,132,39,127);
//									//					delay_ms(2000);
//
//									//BW_Tracer_Check();
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//									//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//									//TRIPOD B
//									Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,102,20,71);
//									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,20,110); //depan menapak
//									Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,132,24,122);
//
//									//TRIPOD A
//									Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,83,38,126);
//									Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,55,35,120); //belakang angkat
//									Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,85,35,126);
//									//					delay_ms(2000);
//
//									//BW_Tracer_Check();
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//									//5
//									//TRIPOD A
//									Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90,38,126);
//									Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90,35,120); //tengah angkat
//									Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90,35,126);
//
//									//TRIPOD B
//									Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
//									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
//									Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);
//									//					delay_ms(2000);
//
//									//BW_Tracer_Check();
//
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//									//6
//									//TRIPOD A
//									Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,38,98);
//									Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,125,35,93); //depan angkat
//									Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,35,118);
//
//									//TRIPOD B
//									Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,48,20,124);
//									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,20,110); //belakang menapak
//									Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,78,24,69);
//									//					delay_ms(2000);
//
//									//BW_Tracer_Check();
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//									//1
//									//TRIPOD A
//									Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,23,103);
//									Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,125,20,107); //depan menapak
//									Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,20,113);
//
//									//TRIPOD B
//									Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,48,35,122);
//									Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,35,128); //belakang angkat
//									Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,78,39,120);
//									//					delay_ms(2000);
//									//BW_Tracer_Check();
//
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//									TCS3200_Transmit(UART5, CMD_GET_TRACER);
//									if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;



		}break;
	}
}


float           L1 = 4,	   //panjang lengan
                L2 = 5;
float           tetha_1,	//coxa //dalam radian
                tetha_2,	//femur
                tetha_3;	//tibia
int             degree_1, //dalam sudut
                degree_2,
                degree_3;
void kinematik_invers(unsigned int leg_position,int *SPEED,float x,float y,float z)
{

float A;
float B;
float C;
float D;
float buff_1,buff_2,buff_3;

        A= ((x*x)+(y*y)+(z*z)-(L1*L1)-(L2*L2))/(2*L1*L2);
        B=sqrt(1-(A*A));
        tetha_3= atan2(B,A);
        buff_1= (L2*cos(tetha_3))+L1;
        buff_2= sqrt((x*x)+(y*y));
        buff_3= L2*sin(tetha_3);
        C= (z*buff_1)-(buff_2*buff_3);
        D= (buff_1*buff_2)+(z*buff_3);
        tetha_2=atan2(C,D);
        tetha_1=atan2(x,y);

        degree_1= tetha_1*57.29577957855;
        degree_2= tetha_2*57.29577957855;
        degree_3= tetha_3*57.29577957855;

//		lcd_display_clear();yo
//		lcd_gotoxy(1,0);sprintf(lcd,"INVERS KIN");lcd_putstr(lcd);
//		lcd_gotoxy(1,1);sprintf(lcd,"degree1= %d ",degree_1);lcd_putstr(lcd);
//		lcd_gotoxy(1,2);sprintf(lcd,"degree2= %d ",degree_2);lcd_putstr(lcd);
//		lcd_gotoxy(1,3);sprintf(lcd,"degree3= %d ",degree_3);lcd_putstr(lcd);

//		Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,degree_1,(-degree_2),degree_3);
    	switch(leg_position)
    	{
    		case FRONT_LEFT_DX      :Dynamx_MoveLeg(FRONT_LEFT_DX, &SPEED,degree_1,(-degree_2),degree_3);
    							 	 break;

    		case FRONT_RIGHT_DX     :Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,degree_1,(-degree_2),degree_3);
		 	 	 	 	 	 	 	 break;

    		case MIDDLE_LEFT_DX     :Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,degree_1,(-degree_2),degree_3);
    							 	 break;

    		case MIDDLE_RIGHT_DX    :Dynamx_MoveLeg(MIDDLE_RIGHT_DX, &SPEED,degree_1,(-degree_2),degree_3);
		 	 	 	 	 	 	 	 break;

    		case REAR_LEFT_DX       :Dynamx_MoveLeg(REAR_LEFT_DX, &SPEED,degree_1,(-degree_2),degree_3);
    								 break;

    		case REAR_RIGHT_DX      :Dynamx_MoveLeg(REAR_RIGHT_DX, &SPEED,degree_1,(-degree_2),degree_3);
			 	 	 	 	 	 	 break;
    	}
}

void test_IK()
{
	int delay=1;
	int speed=HEXSPD_MEDFAST;
	float langkah;

	while(1)
	{

//		kinematik_invers(FRONT_LEFT_DX,speed,4.5,0.5,3.5);
//		kinematik_invers(MIDDLE_RIGHT_DX,speed,4,0,3.5);
//		kinematik_invers(REAR_LEFT_DX,speed,3,0,3.5);
//
//		kinematik_invers(FRONT_RIGHT_DX,speed,4.5,0.5,3.5);
//		kinematik_invers(MIDDLE_LEFT_DX,speed,4,0,3.5);	///belakang
//		kinematik_invers(REAR_RIGHT_DX,speed,3,0,3.5);

	//test
//	kinematik_invers(FRONT_LEFT_DX,HEXSPD_MED,6,-1,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,HEXSPD_MED,4,-1,3.5);	//MAU KE BELAKANG
//	kinematik_invers(REAR_LEFT_DX,HEXSPD_SLOW,2,-1,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,HEXSPD_MED,3,2,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,HEXSPD_MED,4,2,3.5);	///MAU KE DEPAN
//	kinematik_invers(REAR_RIGHT_DX,HEXSPD_MED,5,2,3.5);
//
//	delay_ms(50);
//
//	kinematik_invers(FRONT_LEFT_DX,HEXSPD_MED,5,0,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,HEXSPD_MED,4,0,3.5);
//	kinematik_invers(REAR_LEFT_DX,HEXSPD_SLOW,3,0,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,HEXSPD_MED,4,1,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,HEXSPD_MED,4,1,3.5);
//	kinematik_invers(REAR_RIGHT_DX,HEXSPD_MED,4,1,3.5);
//
//	delay_ms(50);
//
//	kinematik_invers(FRONT_LEFT_DX,HEXSPD_MED,4,1,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,HEXSPD_MED,4,1,3.5);
//	kinematik_invers(REAR_LEFT_DX,HEXSPD_SLOW,4,1,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,HEXSPD_MED,5,0,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,HEXSPD_MED,4,0,3.5);
//	kinematik_invers(REAR_RIGHT_DX,HEXSPD_MED,3,0,3.5);
//
//	delay_ms(50);
//
//	kinematik_invers(FRONT_LEFT_DX,HEXSPD_MED,3,2,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,HEXSPD_MED,4,2,3.5);
//	kinematik_invers(REAR_LEFT_DX,HEXSPD_SLOW,5,2,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,HEXSPD_MED,6,-1,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,HEXSPD_MED,4,-1,3.5);
//	kinematik_invers(REAR_RIGHT_DX,HEXSPD_MED,2,-1,3.5);
//
//	delay_ms(50);

	//1	mov_fwd
		for(langkah=0;langkah<=3;langkah+=0.25)
		{
			kinematik_invers(FRONT_LEFT_DX,speed,6-langkah,-1+langkah,3.5);
			kinematik_invers(MIDDLE_RIGHT_DX,speed,4,-1+langkah,3.5);
			kinematik_invers(REAR_LEFT_DX,speed,2+langkah,-1+langkah,3.5);

			kinematik_invers(FRONT_RIGHT_DX,speed,3+langkah,2-langkah,2.5);
			kinematik_invers(MIDDLE_LEFT_DX,speed,4,2-langkah,2.5);	///belakang
			kinematik_invers(REAR_RIGHT_DX,speed,5-langkah,2-langkah,2.5);

//			delay_ms(delay);

		}
		//===============================================

			kinematik_invers(FRONT_LEFT_DX,speed,3,2,3.5);
			kinematik_invers(MIDDLE_RIGHT_DX,speed,4,2,3.5);
			kinematik_invers(REAR_LEFT_DX,speed,5,2,3.5);

			kinematik_invers(FRONT_RIGHT_DX,speed,6,-1,3.5);
			kinematik_invers(MIDDLE_LEFT_DX,speed,4,-1,3.5);
			kinematik_invers(REAR_RIGHT_DX,speed,2,-1,3.5);

//			delay_ms(delay);

		//===============================================
		for(langkah=3;langkah>=0;langkah-=0.25)
		{
			kinematik_invers(FRONT_LEFT_DX,speed,6-langkah,-1+langkah,2.5);
			kinematik_invers(MIDDLE_RIGHT_DX,speed,4,-1+langkah,2.5);
			kinematik_invers(REAR_LEFT_DX,speed,2+langkah,-1+langkah,2.5);

			kinematik_invers(FRONT_RIGHT_DX,speed,3+langkah,2-langkah,3.5);
			kinematik_invers(MIDDLE_LEFT_DX,speed,4,2-langkah,3.5);	///belakang
			kinematik_invers(REAR_RIGHT_DX,speed,5-langkah,2-langkah,3.5);

//			delay_ms(delay);
		}
		//===============================================

		kinematik_invers(FRONT_LEFT_DX,speed,6,-1,3.5);
		kinematik_invers(MIDDLE_RIGHT_DX,speed,4,-1,3.5);	//depan
		kinematik_invers(REAR_LEFT_DX,speed,2,-1,3.5);

		kinematik_invers(FRONT_RIGHT_DX,speed,3,2,3.5);
		kinematik_invers(MIDDLE_LEFT_DX,speed,4,2,3.5);	///belakang
		kinematik_invers(REAR_RIGHT_DX,speed,5,2,3.5);
//		delay_ms(delay);

		//===============================================

/*		//1	mov_bwd
			for(langkah=0;langkah<=3;langkah+=0.5)
			{
				kinematik_invers(FRONT_LEFT_DX,speed,6-langkah,-1+langkah,2.5);
				kinematik_invers(MIDDLE_RIGHT_DX,speed,4,-1+langkah,2.5);
				kinematik_invers(REAR_LEFT_DX,speed,2+langkah,-1+langkah,2.5);

				kinematik_invers(FRONT_RIGHT_DX,speed,3+langkah,2-langkah,3.5);
				kinematik_invers(MIDDLE_LEFT_DX,speed,4,2-langkah,3.5);	///belakang
				kinematik_invers(REAR_RIGHT_DX,speed,5-langkah,2-langkah,3.5);

				delay_ms(delay);

			}
			//===============================================

				kinematik_invers(FRONT_LEFT_DX,speed,3,2,3.5);
				kinematik_invers(MIDDLE_RIGHT_DX,speed,4,2,3.5);
				kinematik_invers(REAR_LEFT_DX,speed,5,2,3.5);

				kinematik_invers(FRONT_RIGHT_DX,speed,6,-1,3.5);
				kinematik_invers(MIDDLE_LEFT_DX,speed,4,-1,3.5);
				kinematik_invers(REAR_RIGHT_DX,speed,2,-1,3.5);

				delay_ms(delay);

			//===============================================
			for(langkah=3;langkah>=0;langkah-=0.5)
			{
				kinematik_invers(FRONT_LEFT_DX,speed,6-langkah,-1+langkah,3.5);
				kinematik_invers(MIDDLE_RIGHT_DX,speed,4,-1+langkah,3.5);
				kinematik_invers(REAR_LEFT_DX,speed,2+langkah,-1+langkah,3.5);

				kinematik_invers(FRONT_RIGHT_DX,speed,3+langkah,2-langkah,2.5);
				kinematik_invers(MIDDLE_LEFT_DX,speed,4,2-langkah,2.5);	///belakang
				kinematik_invers(REAR_RIGHT_DX,speed,5-langkah,2-langkah,2.5);

				delay_ms(delay);
			}
			//===============================================

			kinematik_invers(FRONT_LEFT_DX,speed,6,-1,3.5);
			kinematik_invers(MIDDLE_RIGHT_DX,speed,4,-1,3.5);	//depan
			kinematik_invers(REAR_LEFT_DX,speed,2,-1,3.5);

			kinematik_invers(FRONT_RIGHT_DX,speed,3,2,3.5);
			kinematik_invers(MIDDLE_LEFT_DX,speed,4,2,3.5);	///belakang
			kinematik_invers(REAR_RIGHT_DX,speed,5,2,3.5);
			delay_ms(delay);

			//===============================================
*/

//	//1
//	kinematik_invers(FRONT_LEFT_DX,speed,6,-1,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,-1,3.5);	//depan
//	kinematik_invers(REAR_LEFT_DX,speed,2,-1,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,3,2,2);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,2,2);	///belakang
//	kinematik_invers(REAR_RIGHT_DX,speed,5,2,2);
//
//	delay_ms(delay);
//
//	kinematik_invers(FRONT_LEFT_DX,speed,5,0,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,0,3.5);
//	kinematik_invers(REAR_LEFT_DX,speed,3,0,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,4,1,2);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,1,2);
//	kinematik_invers(REAR_RIGHT_DX,speed,4,1,2);
//
//	delay_ms(delay);
//
//	kinematik_invers(FRONT_LEFT_DX,speed,4,1,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,1,3.5);
//	kinematik_invers(REAR_LEFT_DX,speed,4,1,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,5,0,2);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,0,2);
//	kinematik_invers(REAR_RIGHT_DX,speed,3,0,2);
//
//	delay_ms(delay);
//
//	kinematik_invers(FRONT_LEFT_DX,speed,3,2,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,2,3.5);
//	kinematik_invers(REAR_LEFT_DX,speed,5,2,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,6,-1,2);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,-1,2);
//	kinematik_invers(REAR_RIGHT_DX,speed,2,-1,2);
//
//	delay_ms(delay);
////===============================================
//
//	kinematik_invers(FRONT_LEFT_DX,speed,3,2,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,2,3.5);
//	kinematik_invers(REAR_LEFT_DX,speed,5,2,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,6,-1,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,-1,3.5);
//	kinematik_invers(REAR_RIGHT_DX,speed,2,-1,3.5);
//
//	delay_ms(delay);
//
////===============================================
//	//2
//	kinematik_invers(FRONT_LEFT_DX,speed,3,2,2);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,2,2);
//	kinematik_invers(REAR_LEFT_DX,speed,5,2,2);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,6,-1,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,-1,3.5);
//	kinematik_invers(REAR_RIGHT_DX,speed,2,-1,3.5);
//
//	delay_ms(delay);
//	kinematik_invers(FRONT_LEFT_DX,speed,4,1,2);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,1,2);
//	kinematik_invers(REAR_LEFT_DX,speed,4,1,2);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,5,0,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,0,3.5);
//	kinematik_invers(REAR_RIGHT_DX,speed,3,0,3.5);
//
//	delay_ms(delay);
//
//	kinematik_invers(FRONT_LEFT_DX,speed,5,0,2);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,0,2);
//	kinematik_invers(REAR_LEFT_DX,speed,3,0,2);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,4,1,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,1,3.5);
//	kinematik_invers(REAR_RIGHT_DX,speed,4,1,3.5);
//
//	delay_ms(delay);
//
//	kinematik_invers(FRONT_LEFT_DX,speed,6,-1,2);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,-1,2);	//MAU KE BELAKANG
//	kinematik_invers(REAR_LEFT_DX,speed,2,-1,2);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,3,2,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,2,3.5);	///MAU KE DEPAN
//	kinematik_invers(REAR_RIGHT_DX,speed,5,2,3.5);
//
//	delay_ms(delay);
//
//	//===============================================
//
//	kinematik_invers(FRONT_LEFT_DX,speed,6,-1,3.5);
//	kinematik_invers(MIDDLE_RIGHT_DX,speed,4,-1,3.5);	//depan
//	kinematik_invers(REAR_LEFT_DX,speed,2,-1,3.5);
//
//	kinematik_invers(FRONT_RIGHT_DX,speed,3,2,3.5);
//	kinematik_invers(MIDDLE_LEFT_DX,speed,4,2,3.5);	///belakang
//	kinematik_invers(REAR_RIGHT_DX,speed,5,2,3.5);
//	delay_ms(delay);
//
//	//===============================================

}

}
