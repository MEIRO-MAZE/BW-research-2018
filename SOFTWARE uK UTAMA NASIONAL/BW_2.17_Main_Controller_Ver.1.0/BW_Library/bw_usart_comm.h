/*==============================================================================================
								  PROJECT BW Ver.1.0
							THERMOPHILE ARRAY AND SERVO LIBRARY
==============================================================================================*/
#ifndef BW_USART_COMM_H
#define BW_USART_COMM_H

#include "main.h"

/*
 * BW USART VARIABLES
 */
extern char command_code[];
extern unsigned int USART_Bluetooth_Count;
extern unsigned int COMMAND_FLAG_A;
extern unsigned int COMMAND_FLAG_B;
extern unsigned int COMMAND_COMPLETED;
extern unsigned int COMMAND_NOT_RECEIVED;
/*
 *  TCS3200 RAW VALUE FLAG
 */
extern unsigned int RAW_VAL_FLAG;

//CALIBRATION COMMAND
extern const int TCS_CALIBRATE_WHITE;
extern const int TCS_CALIBRATE_BLACK;
extern const int TCS_CALIBRATE_GRAY;
extern const int TCS_CALIBRATE_GETRULE;

void USART1_Init(uint32_t baudrate);
void USART2_Init(uint32_t baudrate);
void Command_Gait(USART_TypeDef* USARTx, volatile char *s);
void TCS3200_CMD(USART_TypeDef* USARTx, volatile char *s);

void Sendto_PC(USART_TypeDef* USARTx, const char *pFormat, ... );

void Send_FlameSense(void);
void Display_FlameSense(void);

void TCS3200_Transmit(USART_TypeDef* USARTx, int DATA);

extern unsigned int USART2_DATA[];
extern unsigned int FlameSense[];
extern unsigned int USARTFlame_Counter;
extern unsigned int USARTFlameDigi_Counter;
extern unsigned int FlameSenseDigi[];

extern unsigned int FlameFrontDigi[];

extern unsigned int FLAME_SENSOR[];

/*
 *  TCS3200 SLAVE VARIABLES
 */
extern unsigned int TCS3200_SLV_CNT;
extern unsigned int TCS3200_SLV_STAT[];
extern unsigned int TCS3200_SLV_DATA[];
extern unsigned int FRONT_PRESENT;
extern unsigned int FRONT_PREVIOUS;
extern unsigned int MIDDLE_PRESENT;
extern unsigned int MIDDLE_PREVIOUS;

extern unsigned int TCS3200_CMD_CODE[];

//CARPET CODE
extern unsigned int COLOUR_NONE;
extern unsigned int COLOUR_BLACK;
extern unsigned int COLOUR_GRAY;
extern unsigned int COLOUR_WHITE;
extern unsigned int COLOUR_RED;
extern unsigned int COLOUR_BLUE;

/*
 * FOLLOW TRACER FLAG VARIABLES
 */
extern unsigned int FOLLOWTRACER_FLAG;
extern unsigned int FOLLOWTRACER_ENABLE;
extern unsigned int FOLLOWTRACER_DISABLE;

extern unsigned int UV_state;

extern unsigned int TRACER_VALUE[];

void UART4_Init(uint32_t baudrate);
void UART5_Init(uint32_t baudrate);
void USART6_Init(uint32_t baudrate);


#endif
