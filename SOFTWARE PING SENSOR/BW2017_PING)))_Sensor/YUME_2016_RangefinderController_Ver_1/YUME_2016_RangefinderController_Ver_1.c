/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project  : YUME 2016 Rangefinder Controller  
Version  : Ver.1.0
Date     : Tuesday, February 24th 2016
Author   : Ryan  
Division : Intelligent Legged Fire Fighting Robot Division
Company  : University of Brawijaya Robotics Team
Comments: 


Chip type               : ATmega8
Program type            : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega8.h>
#include <delay.h>
#include <sleep.h>

// Standard Input/Output functions
#include <stdio.h>
#include <sleep.h>

//MACRO
#define  TIM1_OFF    TCCR1B=0x00
#define  TIM1_ON     TCCR1B=0x0B
#define  TIM1_RESET  TCNT1=0x0000
#define  UDRE 5

//OLD CONFIG WITHOUT SHARP INFRARED RANGER
//#define PING_LEFT        0
//#define PING_ASKEW_LEFT  1
//#define PING_FRONT       2
//#define PING_ASKEW_RIGHT 3
//#define PING_RIGHT       4
//#define PING_REAR        5
//#define PING_REAR_LEFT   6
//#define PING_REAR_RIGHT  7

#define PING_REAR_LEFT   0
//#define PING_REAR_RIGHT  1
#define PING_REAR_RIGHT  2
//#define PING_REAR        2
#define PING_LEFT        3
#define PING_ASKEW_LEFT  4
#define PING_FRONT       5
#define PING_ASKEW_RIGHT 6
#define PING_RIGHT       7

//SHARP IR
#define SHARP_FRONT_R     0
#define SHARP_FRONT_L     1
//#define SHARP_FRONT     0
//#define SHARP_LEFT      1
//#define SHARP_RIGHT     2

unsigned int COMMAND_FLAG_A = 0x3C;
unsigned int COMMAND_FLAG_B = 0x3E;
//const unsigned int COMMAND_COMPLETED = 0x7C;

//GLOBAL VARIABLE
char flag=0,schedule=0;
//int eksekusi;

unsigned int distance[8]={0,0,0,0,0,0,0,0};
//unsigned int TEST[8]={1,2,3,4,5,6,7,8};
//char x=0;
int baud_mode;

//UART SPEED CONFIG VARIABLES
const int DEBUG_MODE = 2;
//const int ROBOT_MODE = 1;


 

//Sharp IR Data
unsigned int ADC_Value;
float SHARP_Vo;
unsigned int SHARP_DIST[8]={0,0,0,0,0,0,0,0};

unsigned int SHARP_TEMP[5]={0,0,0,0,0};

//FUNCTION PROTOTYPE
void YUME_SystemInit(void);
void UART_Speed_Config(int mode);
void Ping_Scan(int CHANNEL);
void Send_UART(unsigned char DATA);
void SHARP_SCAN (unsigned int CHANNEL);

// Timer1 output compare A interrupt service routine
interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{
    // Place your code here
    schedule=1;
}

// Timer1 output compare B interrupt service routine
interrupt [TIM1_COMPB] void timer1_compb_isr(void)
{
    // Place your code here    
    flag=1;

}


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


void main(void)
{
    YUME_SystemInit();
    TIM1_OFF;
    TIM1_RESET;
    PORTD.6=1;
    PORTD.7=0;                 
    UART_Speed_Config(DEBUG_MODE);
    delay_ms(200);           
    
    // Global enable interrupts
    #asm("sei") //meaning -> asm= assembler | sei= set enable interrupt 

while (1)
      {  
//            SHARP_DIST[0]=read_adc(0);  
//            
//            SHARP_Vo= (float)SHARP_DIST[0]/51; 
////            printf("SHARP: %d \r",(int) Vo);  
//            
//            SHARP_DIST[1]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
//
//            printf("SHARP: %d \r",(int) SHARP_DIST[1]); 
//            
//            SHARP_SCAN(SHARP_FRONT);
//            printf("SHARP: %d \r",SHARP_DIST[SHARP_FRONT]);
            
            
//            //Place your code here
            Send_UART(COMMAND_FLAG_A); 
            Send_UART(COMMAND_FLAG_B);   
            
            Ping_Scan(PING_FRONT);Send_UART(distance[PING_FRONT]);      
            Ping_Scan(PING_LEFT); Send_UART(distance[PING_LEFT]);
            Ping_Scan(PING_RIGHT);Send_UART(distance[PING_RIGHT]);  
//            Ping_Scan(PING_FRONT);Send_UART(distance[PING_FRONT]);
            
            //Ping_Scan(PING_REAR);Send_UART(distance[PING_REAR]);    
            SHARP_SCAN(SHARP_FRONT_R); Send_UART(SHARP_DIST[SHARP_FRONT_R]);
            
            Ping_Scan(PING_ASKEW_LEFT);Send_UART(distance[PING_ASKEW_LEFT]);
            Ping_Scan(PING_ASKEW_RIGHT);Send_UART(distance[PING_ASKEW_RIGHT]);         
                                                                  
            
            Ping_Scan(PING_REAR_LEFT);Send_UART(distance[PING_REAR_LEFT]);
//            Ping_Scan(PING_REAR);Send_UART(distance[PING_REAR]);
            Ping_Scan(PING_REAR_RIGHT);Send_UART(distance[PING_REAR_RIGHT]);

            SHARP_SCAN(SHARP_FRONT_L); Send_UART(SHARP_DIST[SHARP_FRONT_L]);              
//            SHARP_SCAN(SHARP_FRONT); Send_UART(SHARP_DIST[SHARP_FRONT]); 
//            SHARP_SCAN(SHARP_REAR); Send_UART(SHARP_DIST[SHARP_REAR]);
             
                   
              
//            Ping_Scan(PING_REAR_LEFT);Send_UART(distance[PING_REAR_LEFT]);
//            Ping_Scan(PING_REAR_RIGHT);Send_UART(distance[PING_REAR_RIGHT]); 

      }
}

void YUME_SystemInit(void)
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
    // Clock value: 250.000 kHz
    // Mode: CTC top=OCR1A
    // OC1A output: Discon.
    // OC1B output: Discon.
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer1 Overflow Interrupt: Off
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: On
    // Compare B Match Interrupt: On
    TCCR1A=0x00;
    TCCR1B=0x0B;
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x09;
    OCR1AL=0xC4;
    OCR1BH=0x07;
    OCR1BL=0xD0;

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
    TIMSK=0x18;

    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: Off
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=0x00;
    UCSRB=0x08;
    UCSRC=0x86;
    UBRRH=0x00;
    UBRRL=0x67;

    // Analog Comparator initialization
    // Analog Comparator: Off
    // Analog Comparator Input Capture by Timer/Counter 1: Off
    ACSR=0x80;
    SFIOR=0x00;

    // ADC initialization
    // ADC Clock frequency: 500.000 kHz
    // ADC Voltage Reference: AVCC pin
    // Only the 8 most significant bits of
    // the AD conversion result are used
    ADMUX=ADC_VREF_TYPE & 0xff;
    ADCSRA=0x85;

    // SPI initialization
    // SPI disabled
    SPCR=0x00;

    // TWI initialization
    // TWI disabled
    TWCR=0x00;
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
    //if(PIND.3==0)    operational 1Mbps
     //   {
     //       UBRRH=0x00;
      //      UBRRL=0x00;
      //  }
    //else   //9600bps for debug purpose
        //{
            //UBRRH=0x00;
            //UBRRL=0x67;
        //}
    #asm("sei")        
}
void Ping_Scan(int CHANNEL)
{
    PORTD.6 = ~PORTD.6;
    PORTD.7 = ~PORTD.7;
            
    TIM1_OFF;
    flag=0;
    schedule=0;
    TIM1_RESET;    
        
    PORTB&=0x00;
    DDRB&=0x00;
    PORTC&=0x00;
    DDRC&=0x00; 
          
    TIM1_ON;   
    
    switch(CHANNEL)
    {
        case 0: 
                {
                    DDRC.0=1;PORTC.0=1;delay_us(5);PORTC.0=0;
                    DDRC.0=0;delay_us(4);               
        
                    while(PINC.0==1 && flag==0){};
                    while(PINC.0==0 && flag==0){}; TIM1_ON; TIM1_RESET;
                    while(PINC.0==1 && flag==0){}; TIM1_OFF;  
                    
                }break;  
//                 
//        case 1: 
//                {
//                    DDRC.1=1;PORTC.1=1;delay_us(5);PORTC.1=0;
//                    DDRC.1=0;delay_us(4);               
//        
//                    while(PINC.1==1 && flag==0){};
//                    while(PINC.1==0 && flag==0){}; TIM1_ON; TIM1_RESET;
//                    while(PINC.1==1 && flag==0){}; TIM1_OFF;  
//                    
//                }break;  
        case 2: 
                {
 
//                    DDRC.2=1;PORTC.2=1;delay_us(5);PORTC.2=0;
//                    DDRC.2=0;delay_us(4);               
//        
//                    while(PINC.2==1 && flag==0){};
//                    while(PINC.2==0 && flag==0){}; TIM1_ON; TIM1_RESET;
//                    while(PINC.2==1 && flag==0){}; TIM1_OFF;  
                    DDRC.1=1;PORTC.1=1;delay_us(5);PORTC.1=0;
                    DDRC.1=0;delay_us(4);               
        
                    while(PINC.1==1 && flag==0){};
                    while(PINC.1==0 && flag==0){}; TIM1_ON; TIM1_RESET;
                    while(PINC.1==1 && flag==0){}; TIM1_OFF;                    
                }break; 
        case 3: 
                {
                    DDRC.3=1;PORTC.3=1;delay_us(5);PORTC.3=0;
                    DDRC.3=0;delay_us(4);               
        
                    while(PINC.3==1 && flag==0){};
                    while(PINC.3==0 && flag==0){}; TIM1_ON; TIM1_RESET;
                    while(PINC.3==1 && flag==0){}; TIM1_OFF;  
                    
                }break;  
        case 4: 
                {
//                    DDRC.4=1;PORTC.4=1;delay_us(5);PORTC.4=0;
//                    DDRC.4=0;delay_us(4);               
//        
//                    while(PINC.4==1 && flag==0){};
//                    while(PINC.4==0 && flag==0){}; TIM1_ON; TIM1_RESET;
//                    while(PINC.4==1 && flag==0){}; TIM1_OFF;
                    DDRB.0=1;PORTB.0=1;delay_us(5);PORTB.0=0;
                    DDRB.0=0;delay_us(4);               
        
                    while(PINB.0==1 && flag==0){};
                    while(PINB.0==0 && flag==0){}; TIM1_ON; TIM1_RESET;
                    while(PINB.0==1 && flag==0){}; TIM1_OFF;   
                    
                }break;   
        case 5: 
                {
                    DDRC.5=1;PORTC.5=1;delay_us(5);PORTC.5=0;
                    DDRC.5=0;delay_us(4);               
        
                    while(PINC.5==1 && flag==0){};
                    while(PINC.5==0 && flag==0){}; TIM1_ON; TIM1_RESET;
                    while(PINC.5==1 && flag==0){}; TIM1_OFF;  
                    
                }break;  
        case 6: 
                {
//                    DDRB.0=1;PORTB.0=1;delay_us(5);PORTB.0=0;
//                    DDRB.0=0;delay_us(4);               
//        
//                    while(PINB.0==1 && flag==0){};
//                    while(PINB.0==0 && flag==0){}; TIM1_ON; TIM1_RESET;
//                    while(PINB.0==1 && flag==0){}; TIM1_OFF;  
                    DDRC.4=1;PORTC.4=1;delay_us(5);PORTC.4=0;
                    DDRC.4=0;delay_us(4);               
        
                    while(PINC.4==1 && flag==0){};
                    while(PINC.4==0 && flag==0){}; TIM1_ON; TIM1_RESET;
                    while(PINC.4==1 && flag==0){}; TIM1_OFF;                     
                }break;  
        case 7: 
                {
                    DDRB.1=1;PORTB.1=1;delay_us(5);PORTB.1=0;
                    DDRB.1=0;delay_us(4);               
        
                    while(PINB.1==1 && flag==0){};
                    while(PINB.1==0 && flag==0){}; TIM1_ON; TIM1_RESET;
                    while(PINB.1==1 && flag==0){}; TIM1_OFF;  
                    
                }break;              
    }    
    
    distance[CHANNEL]=(unsigned int)((344*0.5*100*TCNT1*64)/16000000);  


    
    //printf("TCNT1 Value: %d ",TCNT1);
    //Send_UART(distance[CHANNEL]);
    //printf("Ping[%d]: %d   ",CHANNEL, distance[CHANNEL]);    // \r -> return (go back to column 1 of current output line)   
    TIM1_ON;
    //if(schedule==0){idle();}
    TIM1_OFF;  
}


void Send_UART(unsigned char DATA)
{
    while(!(UCSRA & (1<<UDRE))){};
    UDR= DATA;    
}


//void SHARP_ADC_Read(void)
//{
//    ADC_Value= read_adc(0);
//    SHARP_Vo= ADC_Value/51;
//}

//void SHARP_Calc(unsigned int CHANNEL)
//{
//    //SHARP_DIST[CHANNEL]= (float) ((1/((0.04*SHARP_Vo)-0;
//}

//void SHARP_SCAN (unsigned int CHANNEL)
//{
//    int counter=0;
//    
//    ADC_Value=0;
//    SHARP_Vo=0;
//    SHARP_TEMP[0]=0;
//    SHARP_TEMP[1]=0;
//    SHARP_TEMP[2]=0;  
//    SHARP_TEMP[3]=0;
//    SHARP_TEMP[4]=0;
//    
//    switch (CHANNEL)
//    {
//        case 0:
//                {
//                     for(counter=0;counter<=4;counter++)
//                     {
//                        ADC_Value = read_adc(0);  
//                        
//                        SHARP_TEMP[counter]= 4800/(ADC_Value-20);
//                     }
//                     
//                     SHARP_DIST[SHARP_FRONT]= (SHARP_TEMP[0]+SHARP_TEMP[1]+SHARP_TEMP[2]+SHARP_TEMP[3]+SHARP_TEMP[4])/5;
//                     
//                        if(SHARP_DIST[SHARP_FRONT] > 80) SHARP_DIST[SHARP_FRONT]=81;
//			            else if(SHARP_DIST[SHARP_FRONT] < 10) SHARP_DIST[SHARP_FRONT]=9;
//			            else SHARP_DIST[SHARP_FRONT]=SHARP_DIST[SHARP_FRONT];   
//                }break;
//                
//        case 1:
//                {
//                     for(counter=0;counter<=4;counter++)
//                     {
//                        ADC_Value = read_adc(1);
//                        
//                        SHARP_TEMP[counter]= 4800/(ADC_Value-20);
//                     }
//                     
//                     SHARP_DIST[SHARP_LEFT]= (SHARP_TEMP[0]+SHARP_TEMP[1]+SHARP_TEMP[2]+SHARP_TEMP[3]+SHARP_TEMP[4])/5;
//                     
//                        if( SHARP_DIST[SHARP_LEFT] > 80)  SHARP_DIST[SHARP_LEFT]=81;
//			            else if( SHARP_DIST[SHARP_LEFT] < 10)  SHARP_DIST[SHARP_LEFT]=9;
//			            else  SHARP_DIST[SHARP_LEFT]=SHARP_DIST[SHARP_LEFT];  
//                }break;  
//                
//        case 2:
//                {
//                     for(counter=0;counter<=4;counter++)
//                     {
//                        ADC_Value = read_adc(2);
//  
//                        SHARP_TEMP[counter]= 4800/(ADC_Value-20); 
//                     }
//                     
//                     SHARP_DIST[SHARP_RIGHT]= (SHARP_TEMP[0]+SHARP_TEMP[1]+SHARP_TEMP[2]+SHARP_TEMP[3]+SHARP_TEMP[4])/5;
//                     
//                        if(SHARP_DIST[SHARP_RIGHT] > 80) SHARP_DIST[SHARP_RIGHT]=81;
//			            else if(SHARP_DIST[SHARP_RIGHT] < 10) SHARP_DIST[SHARP_RIGHT]=9;
//			            else SHARP_DIST[SHARP_RIGHT]=SHARP_DIST[SHARP_RIGHT];                      
//                }break;      
//    }
//            
//}


void SHARP_SCAN (unsigned int CHANNEL)
{
    int counter=0;
    
    ADC_Value=0;
    SHARP_Vo=0;
    SHARP_TEMP[0]=0;
    SHARP_TEMP[1]=0;
    SHARP_TEMP[2]=0;  
    SHARP_TEMP[3]=0;
    SHARP_TEMP[4]=0;
    
    switch (CHANNEL)
    {
//        case 0:
//                {
//                     for(counter=0;counter<=4;counter++)
//                     {
//                        ADC_Value = read_adc(0);
//                        SHARP_Vo  = (float)ADC_Value/51;  
//                        SHARP_TEMP[counter]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
//                        if(SHARP_TEMP[counter]>80)
//                        {
//                            SHARP_TEMP[counter]=81;
//                        } 
//                     }
//                     
//                     SHARP_DIST[SHARP_FRONT]= (SHARP_TEMP[0]+SHARP_TEMP[1]+SHARP_TEMP[2]+SHARP_TEMP[3]+SHARP_TEMP[4])/3;
//                     
////                     ADC_Value = read_adc(0);
////                     SHARP_Vo  = (float)ADC_Value/51;  
////                     SHARP_DIST[SHARP_FRONT]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));   
//                }break;
                
        case 0:
                {
                     for(counter=0;counter<=4;counter++)
                     {
                        ADC_Value = read_adc(2);
                        SHARP_Vo  = (float)ADC_Value/51;  
                        SHARP_TEMP[counter]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
                        if(SHARP_TEMP[counter]>80)
                        {
                            SHARP_TEMP[counter]=81;
                        } 
                     }
                     
                     SHARP_DIST[SHARP_FRONT_R]= (SHARP_TEMP[0]+SHARP_TEMP[1]+SHARP_TEMP[2]+SHARP_TEMP[3]+SHARP_TEMP[4])/4;
//                     ADC_Value = read_adc(1);
//                     SHARP_Vo  = (float)ADC_Value/51;   
//                     SHARP_DIST[SHARP_LEFT]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));  
                }break;  
                
        case 1:
                {
                     for(counter=0;counter<=4;counter++)
                     {
                        ADC_Value = read_adc(7);
                        SHARP_Vo  = (float)ADC_Value/51;  
                        SHARP_TEMP[counter]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
                        if(SHARP_TEMP[counter]>80)
                        {
                            SHARP_TEMP[counter]=81;
                        }                         
                     }
                     
                     SHARP_DIST[SHARP_FRONT_L]= (SHARP_TEMP[0]+SHARP_TEMP[1]+SHARP_TEMP[2]+SHARP_TEMP[3]+SHARP_TEMP[4])/4;
                     
//                     ADC_Value = read_adc(2);
//                     SHARP_Vo  = (float)ADC_Value/51;    
//                     SHARP_DIST[SHARP_RIGHT]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42)); 
                }break;      
    }
            
}

