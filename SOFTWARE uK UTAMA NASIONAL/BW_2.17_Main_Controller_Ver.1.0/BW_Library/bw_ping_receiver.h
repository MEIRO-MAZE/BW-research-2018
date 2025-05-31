/*==============================================================================================
								  PROJECT BW Ver.1.0
							BW PING))) RANGEFINDER RECEIVER
==============================================================================================*/

#ifndef BW_PING_RECEIVER_H
#define BW_PING_RECEIVER_H

#include "main.h"


//USART COMM MACRO
#define ON_Ping 0x01
#define OFF_Ping 0x02
#define TO 0x04
#define USART_ACTIVE_MODE 1
#define MAX_STRLEN 10000

//USART COMM VARIABLES
extern char received_string[MAX_STRLEN];
extern char buf[16];
extern char data1_lcd[16];
extern char data2_lcd[16];
extern char tampil_adc[16];
extern unsigned int Ping[9];
extern unsigned int USART_Count;

extern unsigned int Ping[9],USART_Count;
extern unsigned int COMMAND_FLAG_A;
extern unsigned int COMMAND_FLAG_B;
extern unsigned int COMMAND_COMPLETED;
extern unsigned int COMMAND_NOT_RECEIVED;

#define PING_LEFT 0
#define PING_RIGHT 1
#define PING_FRONT 2
//#define PING_REAR 3
#define PING_ASKEW_LEFT 3
#define PING_ASKEW_RIGHT 4
#define PING_REAR 8
#define PING_REAR_LEFT 6
//#define PING_REAR_LEFT 5
#define PING_REAR_RIGHT 7

//SHARP IR RANGEFINDER
extern unsigned int SHARP[];
#define SHARP_FRONT_R 0
#define SHARP_FRONT_L 1


//USART COMM FUNCTION PROTOTYPE
void USART3_Init(uint32_t baudrate);

void usart_puts(char *data);

/*
 * USART PING
 */
void Display_Ping_Status (void);
void Send_Ping_Status (void);
void Display_Sharp_Status (void);

void USART3_Init(uint32_t baudrate); //TO RANGEFINDER uCU;

#endif


