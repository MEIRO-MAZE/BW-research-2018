#ifndef _YUME2016_TCS3200TRACER_HYBRID_VER_1_INCLUDED_
#define _YUME2016_TCS3200TRACER_HYBRID_VER_1_INCLUDED_

#pragma used+

/* YUME TCS3200 CONTROLLER PIN MAPPING
 * 
 * UART COMMUNICATION
 * RX -> PD0
 * TX -> PD1
 * 
 * SPI COMMUNICATION (BANNED, USED IN IN SYSTEM PROGRAMMING)
 * PB5 -> SCK
 * PB4 -> MISO
 * PB3 -> MOSI    
 *
 * FRONT PHOTODIODE-BASED TRACER
 * 
 * FRONT TRACER  -> PC0
 * MIDDLE TRACER -> PC1
 * REAR TRACER   -> PC2
 *
 *
 * MIDDLE TCS3200 COLOUR SENSOR
 *
 * PC3 -> S3
 * PB2 -> S2
 * PD5 -> TCS3200 OUT
 * 5V  -> LED & VCC
 * 
 * GND -> GND
 * PC4 -> OE
 * PB1 -> S1
 * PB0 -> S0
 *
*/

//TCS3200 COLOUR SENSOR
#define TCS3200_S3      PORTC.3
#define TCS3200_S2      PORTB.2
#define TCS3200_S1      PORTB.1
#define TCS3200_S0      PORTB.0
#define TCS3200_OE      PORTC.4
#define TCS3200_OUT     PIND.5

//TIM1 CONTROL
#define TIM1_OFF             TCCR1B = 0x00
#define TIM1_ON              TCCR1B = 0x06
#define TIM1_RESET           TCNT1  = 0x0000

//TCS3200 COLOUR STATUS
int DETECTED_COLOUR=0;

#define COLOUR_NONE         0
#define COLOUR_BLACK        1
#define COLOUR_GRAY         2
#define COLOUR_WHITE        3
#define COLOUR_RED          4
#define COLOUR_BLUE         5
#define COLOUR_ERROR        6




#define TCS3200_RED   5
#define TCS3200_GREEN 6
#define TCS3200_BLUE  7
#define TCS3200_WHITE 8
#define TCS3200_SUM   9 




/*
 *
 * CALIBRATION PARAMETER
 *
 *
 */       
               
//TCS3200 COLOUR SENSOR
//PHOTODIODE TRACER

//eeprom int Threshold_BW, Threshold_BG;
//eeprom int Threshold_White, Threshold_Black,Threshold_Gray; 
//eeprom int TRACER_GRAYDATA, TRACER_WHITEDATA;
//eeprom int TRACER_THRESHOLD;

////KALIBRASI ROBOT BARU SIMULASI UJI COBA
//
int Threshold_White;
int Threshold_Black;
int Threshold_Gray;     
int TRACER_GRAYDATA;
int TRACER_WHITEDATA;
int TRACER_BLACKDATA;


////===TAMBAH BUSA===//
//int Threshold_BW=1654;
//int Threshold_BG=422;
//int TRACER_THRESHOLD=123;

//===LED MERAH===//
//int Threshold_BW=1830;
//int Threshold_BG=390;
//int TRACER_THRESHOLD=230;

//===KRI REG.IV UB 2017 - GOR (Led Merah)===//
//int Threshold_BW=1862;
//int Threshold_BG=440;  //533
//int TRACER_THRESHOLD=240;

//===KRI REG.IV UB 2017 - IKA ===//
//int Threshold_BW=1892;
//int Threshold_BG=453;
//int TRACER_THRESHOLD=185;

//===KRI REG.IV UB 2017 - Running Test I ; Lap. Utara ===//
//int Threshold_BW=1890;
//int Threshold_BG=450;
//int TRACER_THRESHOLD=195;

//===KRI REG.IV UB 2017 - Running Test III ; Lap. Selatan ===//
//int Threshold_BW=1869;
//int Threshold_BG=450;
//int TRACER_THRESHOLD=198;

//===KRI NASIONAL UPI 2017 - Persiapan ===//
//int Threshold_BW=1827;
//int Threshold_BG=407;
//int TRACER_THRESHOLD=169;

//===KRI NASIONAL UPI 2017 - Persiapan 2 ===//
//int Threshold_BW=1887;
//int Threshold_BG=468;
//int TRACER_THRESHOLD=186;

//===KRI NASIONAL UPI 2017 - Persiapan 3 ===//
int Threshold_BW=1857;
int Threshold_BG=436;
int TRACER_THRESHOLD_UP=144;
int TRACER_THRESHOLD_DOWN=54;
//===KRI NASIONAL UPI 2017 - Running Test 1 ===//
//int Threshold_BW=2110;
//int Threshold_BG=631;
//int TRACER_THRESHOLD=237;

//===KRI NASIONAL UPI 2017 - Running Test 3 Data 1===//
//int Threshold_BW=2094;
//int Threshold_BG=636;
//int TRACER_THRESHOLD=237;

//===KRI NASIONAL UPI 2017 - Running Test 3 Data 2===//
//int Threshold_BW=2114;
//int Threshold_BG=640;
//int TRACER_THRESHOLD=238;
 
////int TRACER_THRESHOLD=208;  //Original Data

/*
 *
 * COMMAND FLAG
 *
 */

//COMMAND FLAG TO MAIN CONTROLLER
unsigned int COMMAND_FLAG_A = 0x3C;
unsigned int COMMAND_FLAG_B = 0x3E;
const unsigned int COMMAND_COMPLETED = 0x7C;

//DUMMY DATAs
int DUMMY_DATA_A= 41;
int DUMMY_DATA_B= 42;
int DUMMY_DATA_C= 43;
int DUMMY_DATA_D= 44;
int DUMMY_DATA_E= 45;
int DUMMY_DATA_F= 46;
int DUMMY_DATA_START= 53;
int DUMMY_DATA_IDLE = 94;

//RECEIVED DATA FROM MAIN CONTROLLER
int START_BUTTON    = 0x53;
int BUTTON_A        = 0x41;
int BUTTON_B        = 0x42;
int CMD_COMPLETED   = 0x58;
int CMD_IDLE        = 0x5E;


//MANDATORY COMMAND HYBRID TCS3200 TRACER PROCESSOR
const int TCS3200_CMD_SEND_RAW              = 0x41; //CHANGED
const int TRACER_CMD_SEND_RAW               = 0x42; //CHANGED
const int HYBRID_CMD_SEND_CONCLUSION        = 0x43;


const int TCS3200_CMD_SAVE_EEPROM           = 0x5A;

//SEND THRESHOLD
const int HYBRID_CMD_SEND_THRESHOLD         = 0x58;

const int TCS3200_CALIBRATE_WHITE           = 0x46;
const int TCS3200_CALIBRATE_BLACK           = 0x47;
const int TCS3200_CALIBRATE_GRAY            = 0x48;
const int TCS3200_CALIBRATE_GETRULE         = 0x49;

//BLACK/WHITE PHOTODIODE TRACER PROCESSOR COMMAND
const int TRACER_CALIBRATE_GRAY             = 0x4A;
const int TRACER_CALIBRATE_WHITE            = 0x4B;
const int TRACER_CALIBRATE_BLACK            = 0x4D;
const int TRACER_CALIBRATE_GETRULE          = 0x4C;

void Tracer_GetData_Black(void);
void Tracer_GetData_Gray(void);
void Tracer_GetData_White(void);
void Tracer_Calibrate_GetRule(void); 

//TCS3200+TRACER NEW COMMAND FOR OPTMIZATION
const unsigned int CMD_GET_TCS3200		= 0x52;
const unsigned int CMD_GET_TRACER		= 0x53;


int MOV_AVG[10]={0,0,0,0,0,0,0,0,0,0};

//CALIBRATION VARIABLES
unsigned int M_SUM_RED, M_SUM_GREEN, M_SUM_BLUE, M_SUM_WHITE;


//AUTO-CALIBRATION ARRAY
#define BLACK_FLOOR  0
#define GRAY_CARPET  1
#define WHITE_CARPET 2


#define PRESENT_VAL  0
#define PREVIOUS_VAL 1
#define TEMPORARY    2

int TCS3200_COUNTER=0;
int Diff=0;

int TCS3200_Pulse_R=0, TCS3200_Pulse_G=0, TCS3200_Pulse_B=0, TCS3200_Pulse_W=0,TCS3200_Pulse_Sum=0;
int TCS3200_THRESHOLD=0;
int TCS3200_TOTAL_SUM=0;


/*=============== MOVING AVERAGE SMOOTHING ALGORITHM =================
New average = old average * (n-1)/n + new value /n
=====================================================================*/

// Function Prototypes

long int Mov_AVG=0;
unsigned int NewVal=0;
unsigned int MovAVG_Counter=1;




int TCS3200_CMD[8]={0,0,0,0,0,0,0,0};

int TCS_CMD[8];




eeprom int EEPROM_A, EEPROM_B, EEPROM_C, EEPROM_D;

int Threshold_Diff;


/*
 *  THRESHOLD VARIABLES
 */

unsigned int M_Threshold_W      = 2000;
unsigned int M_Threshold_Sum    = 3135;

//MANDATORY INITIALIZATION FUNCTION
void YUME_Initialization(void);
void Send_UART(unsigned char data);

//SENSITIVITY SETTINGS
void TCS3200_Config(unsigned int mode);

//UART COMMAND RECEIVER
void Get_CMD(void);

//MIDDLE TCS3200 READING
void TCS3200Read(void);
int TCS3200Read_R(void);
int TCS3200Read_G(void);
int TCS3200Read_B(void);
int TCS3200Read_W(void);

//
//void TCS3200_Sampling(void);
//
//void TCS3200_GetRule(void);

void Send_TCS3200_Conclusion(void);


//void Display_Raw_Data(int TCS3200_MODE);
//
//void TCS3200_Autocalibration(void);

void Send_Threshold(void);

//RAW VALUE EXCLUSIVES
unsigned int RAW_VAL_FLAG = 0x52;
int MULTIPLY_COUNTER=0;
int MODULO=0;

//CALIBRATE COUNTER
int CALIBRATE_COUNTER=0;

char TRIGGER;


//TRACER

int TRACER[3]={0,0,0}; 
#define FRONT   0
#define MIDDLE  1
#define REAR    2

//NASIONAL
////PHOTODIODE-BASED TRACER
//int TRACER_STAT=0;
//#define TRACER_INACTIVE 0   // diganti TRACER_WHITE, GRAY dan BLACK
//#define TRACER_ACTIVE   1

//PHOTODIODE-BASED TRACER
int TRACER_STAT=0;
#define TRACER_BLACK 0   
#define TRACER_WHITE 1
#define TRACER_GRAY 2

int TRACER_SECTION[3]={0,0,0};

int Tracer_Sampling(int MODE);
void Tracer_GetRule(void);

#pragma used-

#endif