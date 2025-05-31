/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : BW Digital Flame Sensor Ver 1
Version : Ver 1
Date    : 2/1/2017
Author  : Intelligent Fire Fighting Robot Division
Company : University of Brawijaya
Comments: 


Chip type               : ATmega8
Program type            : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega8.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h> 
#include <math.h>
#include <sleep.h>

//char x=0;
int baud_mode;

//UART SPEED CONFIG VARIABLES
const int DEBUG_MODE = 2;
const int ROBOT_MODE = 1;
void UART_Speed_Config(int mode);


void BW_Initialization(void);
void Send_UART(unsigned char data);

#ifndef RXB8
#define RXB8 1
#endif

#ifndef TXB8
#define TXB8 0
#endif

#ifndef UPE
#define UPE 2
#endif

#ifndef DOR
#define DOR 3
#endif

#ifndef FE
#define FE 4
#endif

#ifndef UDRE
#define UDRE 5
#endif

#ifndef RXC
#define RXC 7
#endif

#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)

// USART Receiver buffer
#define RX_BUFFER_SIZE 8
char rx_buffer[RX_BUFFER_SIZE];

#if RX_BUFFER_SIZE <= 256
unsigned char rx_wr_index,rx_rd_index,rx_counter;
#else
unsigned int rx_wr_index,rx_rd_index,rx_counter;
#endif

// This flag is set on USART Receiver buffer overflow
bit rx_buffer_overflow;

// USART Receiver interrupt service routine
interrupt [USART_RXC] void usart_rx_isr(void)
{
char status,data;
status=UCSRA;
data=UDR;
if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
   {
   rx_buffer[rx_wr_index++]=data;
#if RX_BUFFER_SIZE == 256
   // special case for receiver buffer size=256
   if (++rx_counter == 0)
      {
#else
   if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
   if (++rx_counter == RX_BUFFER_SIZE)
      {
      rx_counter=0;
#endif
      rx_buffer_overflow=1;
      }
   }
}

#ifndef _DEBUG_TERMINAL_IO_
// Get a character from the USART Receiver buffer
#define _ALTERNATE_GETCHAR_
#pragma used+
char getchar(void)
{
char data;
while (rx_counter==0);
data=rx_buffer[rx_rd_index++];
#if RX_BUFFER_SIZE != 256
if (rx_rd_index == RX_BUFFER_SIZE) rx_rd_index=0;
#endif
#asm("cli")
--rx_counter;
#asm("sei")
return data;
}
#pragma used-
#endif

// Standard Input/Output functions
#include <stdio.h>

#define ADC_VREF_TYPE 0x60

// Read the 8 most significant bits
// of the AD conversion result
unsigned char read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCH;
}

// Declare your global variables here
unsigned int FLAME_ANALOG[9]={0,0,0,0,0,0,0,0,0};
//unsigned int FLAME_LOGIC[8]={0,0,0,0,0,0,0,0};
unsigned int FRONT_ANALOG;


int FLAME_SENSOR=0;

//FLAG VARIABLES
unsigned int COMMAND_FLAG_A = 0x3C;
unsigned int COMMAND_FLAG_B = 0x3E;
const unsigned int COMMAND_COMPLETED = 0x7C;

unsigned int MAX_VAL;
//MACRO
int NO_FLAME            = 0;

int FLAME_REAR_LEFT     = 1;
int FLAME_LEFT          = 2;
int FLAME_ASKEW_LEFT    = 3;
int FLAME_FRONT         = 4;
int FLAME_ASKEW_RIGHT   = 5;
int FLAME_RIGHT         = 6;
int FLAME_REAR_RIGHT    = 7;
int FLAME_CENTER        = 8;

//           ADC4
//           ADC3
//     ADC2       ADC5
//  ADC1              ADC6
//   ADC0           ADC7

void main(void)
{
    // Declare your local variables here
    BW_Initialization();     
//    UART_Speed_Config(DEBUG_MODE);


    while (1)
      {
            FLAME_ANALOG[0]=read_adc(0);
            FLAME_ANALOG[1]=read_adc(1);
            FLAME_ANALOG[2]=read_adc(2); //DI KALI 1.15 BIAR NILAI NYA BISA MAKS, KARENA GK TAU KENAPA NILAI ADC NYA GK MAU MAKS..
            FLAME_ANALOG[3]=read_adc(3);        
            FLAME_ANALOG[4]=read_adc(4);
            FLAME_ANALOG[5]=read_adc(5);
            FLAME_ANALOG[6]=read_adc(6);
            FLAME_ANALOG[7]=read_adc(7); 
            
            FRONT_ANALOG=FLAME_ANALOG[4];
                
            MAX_VAL= max(FLAME_ANALOG[0],FLAME_ANALOG[1]);
            MAX_VAL= max(MAX_VAL,FLAME_ANALOG[2]);
            MAX_VAL= max(MAX_VAL,FLAME_ANALOG[3]);
            MAX_VAL= max(MAX_VAL,FLAME_ANALOG[4]);
            MAX_VAL= max(MAX_VAL,FLAME_ANALOG[5]);
            MAX_VAL= max(MAX_VAL,FLAME_ANALOG[6]);
            MAX_VAL= max(MAX_VAL,FLAME_ANALOG[7]);

            if(MAX_VAL>=100)
            {
                if(MAX_VAL==FLAME_ANALOG[4])
                {
                    FLAME_SENSOR=FLAME_CENTER;
                }
                else if(MAX_VAL==FLAME_ANALOG[3])
                {
                    FLAME_SENSOR=FLAME_FRONT;
                }
                else if(MAX_VAL==FLAME_ANALOG[2])
                {
                    FLAME_SENSOR=FLAME_ASKEW_LEFT;
                }
                else if(MAX_VAL==FLAME_ANALOG[5])
                {
                    FLAME_SENSOR=FLAME_ASKEW_RIGHT;
                }
                else if(MAX_VAL==FLAME_ANALOG[1])
                { 
                    FLAME_SENSOR=FLAME_LEFT;
                }
                else if(MAX_VAL==FLAME_ANALOG[6])
                {
                    FLAME_SENSOR=FLAME_RIGHT;
                }   
                else if(MAX_VAL==FLAME_ANALOG[0])
                {
                    FLAME_SENSOR=FLAME_REAR_LEFT;
                }
                else if(MAX_VAL==FLAME_ANALOG[7])
                {
                    FLAME_SENSOR=FLAME_REAR_RIGHT;
                }
                
            }   
            else
            {
                FLAME_SENSOR=NO_FLAME;
            }
            
            Send_UART(COMMAND_FLAG_A); 
            Send_UART(COMMAND_FLAG_B); 
            Send_UART(FLAME_SENSOR);
            Send_UART(FRONT_ANALOG);
            
//            printf("FLAME = %d \t",FLAME_SENSOR);
//            printf("FA = %d \r",FRONT_ANALOG);  
//            delay_ms(100);
//           
                 
      }
}


void BW_Initialization(void)
{
    // Input/Output Ports initialization
    // Port B initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
    // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
    PORTB=0x00;
    DDRB=0x00;

    // Port C initialization
    // Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
    // State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
    PORTC=0x00;
    DDRC=0x00;

    // Port D initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
    // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
    PORTD=0x00;
    DDRD=0x00;

    // Timer/Counter 0 initialization
    // Clock source: System Clock
    // Clock value: Timer 0 Stopped
    TCCR0=0x00;
    TCNT0=0x00;

    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: Timer1 Stopped
    // Mode: Normal top=0xFFFF
    // OC1A output: Discon.
    // OC1B output: Discon.
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer1 Overflow Interrupt: Off
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: Off
    // Compare B Match Interrupt: Off
    TCCR1A=0x00;
    TCCR1B=0x00;
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x00;
    OCR1AL=0x00;
    OCR1BH=0x00;
    OCR1BL=0x00;

    // Timer/Counter 2 initialization
    // Clock source: System Clock
    // Clock value: Timer2 Stopped
    // Mode: Normal top=0xFF
    // OC2 output: Disconnected
    ASSR=0x00;
    TCCR2=0x00;
    TCNT2=0x00;
    OCR2=0x00;

    // External Interrupt(s) initialization
    // INT0: Off
    // INT1: Off
    MCUCR=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=0x00;

    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=0x00;
    UCSRB=0x98;
    UCSRC=0x86;
    UBRRH=0x00;
    UBRRL=0x67;

    // Analog Comparator initialization
    // Analog Comparator: Off
    // Analog Comparator Input Capture by Timer/Counter 1: Off
    ACSR=0x80;
    SFIOR=0x00;

    // ADC initialization
    // ADC Clock frequency: 1000.000 kHz
    // ADC Voltage Reference: AVCC pin
    // Only the 8 most significant bits of
    // the AD conversion result are used
    ADMUX=ADC_VREF_TYPE & 0xff;
    ADCSRA=0x84;

    // SPI initialization
    // SPI disabled
    SPCR=0x00;

    // TWI initialization
    // TWI disabled
    TWCR=0x00;

    // Global enable interrupts
    #asm("sei")
    
}

void UART_Speed_Config(int mode)
{
    //BAUD RATE SELECT INITIALIZATION
    if (PINB.3==0) baud_mode=1;
    else if (PINB.3==1) baud_mode=2;
    
    switch(mode)
    {
        case 1: 
            {
                UBRRH=0x00;
                UBRRL=0x00;
            }break; 
        case 2: 
            {
                UBRRH=0x00;
                UBRRL=0x67;
            }break;
            
    }
    
    #asm("cli")

    #asm("sei")        
}

void Send_UART(unsigned char data)
{
    while(!(UCSRA & (1<<UDRE))){};
    UDR=data;
}
