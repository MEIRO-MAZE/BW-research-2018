
;CodeVisionAVR C Compiler V3.12 Advanced
;(C) Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
;http://www.hpinfotech.com

;Build configuration    : Debug
;Chip type              : ATmega8
;Program type           : Application
;Clock frequency        : 16.000000 MHz
;Memory model           : Small
;Optimize for           : Size
;(s)printf features     : int, width
;(s)scanf features      : int, width
;External RAM size      : 0
;Data Stack size        : 256 byte(s)
;Heap size              : 0 byte(s)
;Promote 'char' to 'int': Yes
;'char' is unsigned     : Yes
;8 bit enums            : Yes
;Global 'const' stored in FLASH: Yes
;Enhanced function parameter passing: Yes
;Enhanced core instructions: On
;Automatic register allocation for global variables: On
;Smart register allocation: On

	#define _MODEL_SMALL_

	#pragma AVRPART ADMIN PART_NAME ATmega8
	#pragma AVRPART MEMORY PROG_FLASH 8192
	#pragma AVRPART MEMORY EEPROM 512
	#pragma AVRPART MEMORY INT_SRAM SIZE 1024
	#pragma AVRPART MEMORY INT_SRAM START_ADDR 0x60

	.LISTMAC
	.EQU UDRE=0x5
	.EQU RXC=0x7
	.EQU USR=0xB
	.EQU UDR=0xC
	.EQU SPSR=0xE
	.EQU SPDR=0xF
	.EQU EERE=0x0
	.EQU EEWE=0x1
	.EQU EEMWE=0x2
	.EQU EECR=0x1C
	.EQU EEDR=0x1D
	.EQU EEARL=0x1E
	.EQU EEARH=0x1F
	.EQU WDTCR=0x21
	.EQU MCUCR=0x35
	.EQU GICR=0x3B
	.EQU SPL=0x3D
	.EQU SPH=0x3E
	.EQU SREG=0x3F

	.DEF R0X0=R0
	.DEF R0X1=R1
	.DEF R0X2=R2
	.DEF R0X3=R3
	.DEF R0X4=R4
	.DEF R0X5=R5
	.DEF R0X6=R6
	.DEF R0X7=R7
	.DEF R0X8=R8
	.DEF R0X9=R9
	.DEF R0XA=R10
	.DEF R0XB=R11
	.DEF R0XC=R12
	.DEF R0XD=R13
	.DEF R0XE=R14
	.DEF R0XF=R15
	.DEF R0X10=R16
	.DEF R0X11=R17
	.DEF R0X12=R18
	.DEF R0X13=R19
	.DEF R0X14=R20
	.DEF R0X15=R21
	.DEF R0X16=R22
	.DEF R0X17=R23
	.DEF R0X18=R24
	.DEF R0X19=R25
	.DEF R0X1A=R26
	.DEF R0X1B=R27
	.DEF R0X1C=R28
	.DEF R0X1D=R29
	.DEF R0X1E=R30
	.DEF R0X1F=R31

	.EQU __SRAM_START=0x0060
	.EQU __SRAM_END=0x045F
	.EQU __DSTACK_SIZE=0x0100
	.EQU __HEAP_SIZE=0x0000
	.EQU __CLEAR_SRAM_SIZE=__SRAM_END-__SRAM_START+1

	.MACRO __CPD1N
	CPI  R30,LOW(@0)
	LDI  R26,HIGH(@0)
	CPC  R31,R26
	LDI  R26,BYTE3(@0)
	CPC  R22,R26
	LDI  R26,BYTE4(@0)
	CPC  R23,R26
	.ENDM

	.MACRO __CPD2N
	CPI  R26,LOW(@0)
	LDI  R30,HIGH(@0)
	CPC  R27,R30
	LDI  R30,BYTE3(@0)
	CPC  R24,R30
	LDI  R30,BYTE4(@0)
	CPC  R25,R30
	.ENDM

	.MACRO __CPWRR
	CP   R@0,R@2
	CPC  R@1,R@3
	.ENDM

	.MACRO __CPWRN
	CPI  R@0,LOW(@2)
	LDI  R30,HIGH(@2)
	CPC  R@1,R30
	.ENDM

	.MACRO __ADDB1MN
	SUBI R30,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDB2MN
	SUBI R26,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDW1MN
	SUBI R30,LOW(-@0-(@1))
	SBCI R31,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW2MN
	SUBI R26,LOW(-@0-(@1))
	SBCI R27,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	SBCI R22,BYTE3(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1N
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	SBCI R22,BYTE3(-@0)
	SBCI R23,BYTE4(-@0)
	.ENDM

	.MACRO __ADDD2N
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	SBCI R24,BYTE3(-@0)
	SBCI R25,BYTE4(-@0)
	.ENDM

	.MACRO __SUBD1N
	SUBI R30,LOW(@0)
	SBCI R31,HIGH(@0)
	SBCI R22,BYTE3(@0)
	SBCI R23,BYTE4(@0)
	.ENDM

	.MACRO __SUBD2N
	SUBI R26,LOW(@0)
	SBCI R27,HIGH(@0)
	SBCI R24,BYTE3(@0)
	SBCI R25,BYTE4(@0)
	.ENDM

	.MACRO __ANDBMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ANDWMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ANDI R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ANDD1N
	ANDI R30,LOW(@0)
	ANDI R31,HIGH(@0)
	ANDI R22,BYTE3(@0)
	ANDI R23,BYTE4(@0)
	.ENDM

	.MACRO __ANDD2N
	ANDI R26,LOW(@0)
	ANDI R27,HIGH(@0)
	ANDI R24,BYTE3(@0)
	ANDI R25,BYTE4(@0)
	.ENDM

	.MACRO __ORBMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ORWMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ORI  R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ORD1N
	ORI  R30,LOW(@0)
	ORI  R31,HIGH(@0)
	ORI  R22,BYTE3(@0)
	ORI  R23,BYTE4(@0)
	.ENDM

	.MACRO __ORD2N
	ORI  R26,LOW(@0)
	ORI  R27,HIGH(@0)
	ORI  R24,BYTE3(@0)
	ORI  R25,BYTE4(@0)
	.ENDM

	.MACRO __DELAY_USB
	LDI  R24,LOW(@0)
__DELAY_USB_LOOP:
	DEC  R24
	BRNE __DELAY_USB_LOOP
	.ENDM

	.MACRO __DELAY_USW
	LDI  R24,LOW(@0)
	LDI  R25,HIGH(@0)
__DELAY_USW_LOOP:
	SBIW R24,1
	BRNE __DELAY_USW_LOOP
	.ENDM

	.MACRO __GETD1S
	LDD  R30,Y+@0
	LDD  R31,Y+@0+1
	LDD  R22,Y+@0+2
	LDD  R23,Y+@0+3
	.ENDM

	.MACRO __GETD2S
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	LDD  R24,Y+@0+2
	LDD  R25,Y+@0+3
	.ENDM

	.MACRO __PUTD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R31
	STD  Y+@0+2,R22
	STD  Y+@0+3,R23
	.ENDM

	.MACRO __PUTD2S
	STD  Y+@0,R26
	STD  Y+@0+1,R27
	STD  Y+@0+2,R24
	STD  Y+@0+3,R25
	.ENDM

	.MACRO __PUTDZ2
	STD  Z+@0,R26
	STD  Z+@0+1,R27
	STD  Z+@0+2,R24
	STD  Z+@0+3,R25
	.ENDM

	.MACRO __CLRD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R30
	STD  Y+@0+2,R30
	STD  Y+@0+3,R30
	.ENDM

	.MACRO __POINTB1MN
	LDI  R30,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW1MN
	LDI  R30,LOW(@0+(@1))
	LDI  R31,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTD1M
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __POINTW1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	LDI  R22,BYTE3(2*@0+(@1))
	LDI  R23,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTB2MN
	LDI  R26,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW2MN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTW2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	LDI  R24,BYTE3(2*@0+(@1))
	LDI  R25,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTBRM
	LDI  R@0,LOW(@1)
	.ENDM

	.MACRO __POINTWRM
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __POINTBRMN
	LDI  R@0,LOW(@1+(@2))
	.ENDM

	.MACRO __POINTWRMN
	LDI  R@0,LOW(@2+(@3))
	LDI  R@1,HIGH(@2+(@3))
	.ENDM

	.MACRO __POINTWRFN
	LDI  R@0,LOW(@2*2+(@3))
	LDI  R@1,HIGH(@2*2+(@3))
	.ENDM

	.MACRO __GETD1N
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __GETD2N
	LDI  R26,LOW(@0)
	LDI  R27,HIGH(@0)
	LDI  R24,BYTE3(@0)
	LDI  R25,BYTE4(@0)
	.ENDM

	.MACRO __GETB1MN
	LDS  R30,@0+(@1)
	.ENDM

	.MACRO __GETB1HMN
	LDS  R31,@0+(@1)
	.ENDM

	.MACRO __GETW1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	.ENDM

	.MACRO __GETD1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	LDS  R22,@0+(@1)+2
	LDS  R23,@0+(@1)+3
	.ENDM

	.MACRO __GETBRMN
	LDS  R@0,@1+(@2)
	.ENDM

	.MACRO __GETWRMN
	LDS  R@0,@2+(@3)
	LDS  R@1,@2+(@3)+1
	.ENDM

	.MACRO __GETWRZ
	LDD  R@0,Z+@2
	LDD  R@1,Z+@2+1
	.ENDM

	.MACRO __GETD2Z
	LDD  R26,Z+@0
	LDD  R27,Z+@0+1
	LDD  R24,Z+@0+2
	LDD  R25,Z+@0+3
	.ENDM

	.MACRO __GETB2MN
	LDS  R26,@0+(@1)
	.ENDM

	.MACRO __GETW2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	.ENDM

	.MACRO __GETD2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	LDS  R24,@0+(@1)+2
	LDS  R25,@0+(@1)+3
	.ENDM

	.MACRO __PUTB1MN
	STS  @0+(@1),R30
	.ENDM

	.MACRO __PUTW1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	.ENDM

	.MACRO __PUTD1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	STS  @0+(@1)+2,R22
	STS  @0+(@1)+3,R23
	.ENDM

	.MACRO __PUTB1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMWRB
	.ENDM

	.MACRO __PUTW1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMWRW
	.ENDM

	.MACRO __PUTD1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMWRD
	.ENDM

	.MACRO __PUTBR0MN
	STS  @0+(@1),R0
	.ENDM

	.MACRO __PUTBMRN
	STS  @0+(@1),R@2
	.ENDM

	.MACRO __PUTWMRN
	STS  @0+(@1),R@2
	STS  @0+(@1)+1,R@3
	.ENDM

	.MACRO __PUTBZR
	STD  Z+@1,R@0
	.ENDM

	.MACRO __PUTWZR
	STD  Z+@2,R@0
	STD  Z+@2+1,R@1
	.ENDM

	.MACRO __GETW1R
	MOV  R30,R@0
	MOV  R31,R@1
	.ENDM

	.MACRO __GETW2R
	MOV  R26,R@0
	MOV  R27,R@1
	.ENDM

	.MACRO __GETWRN
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __PUTW1R
	MOV  R@0,R30
	MOV  R@1,R31
	.ENDM

	.MACRO __PUTW2R
	MOV  R@0,R26
	MOV  R@1,R27
	.ENDM

	.MACRO __ADDWRN
	SUBI R@0,LOW(-@2)
	SBCI R@1,HIGH(-@2)
	.ENDM

	.MACRO __ADDWRR
	ADD  R@0,R@2
	ADC  R@1,R@3
	.ENDM

	.MACRO __SUBWRN
	SUBI R@0,LOW(@2)
	SBCI R@1,HIGH(@2)
	.ENDM

	.MACRO __SUBWRR
	SUB  R@0,R@2
	SBC  R@1,R@3
	.ENDM

	.MACRO __ANDWRN
	ANDI R@0,LOW(@2)
	ANDI R@1,HIGH(@2)
	.ENDM

	.MACRO __ANDWRR
	AND  R@0,R@2
	AND  R@1,R@3
	.ENDM

	.MACRO __ORWRN
	ORI  R@0,LOW(@2)
	ORI  R@1,HIGH(@2)
	.ENDM

	.MACRO __ORWRR
	OR   R@0,R@2
	OR   R@1,R@3
	.ENDM

	.MACRO __EORWRR
	EOR  R@0,R@2
	EOR  R@1,R@3
	.ENDM

	.MACRO __GETWRS
	LDD  R@0,Y+@2
	LDD  R@1,Y+@2+1
	.ENDM

	.MACRO __PUTBSR
	STD  Y+@1,R@0
	.ENDM

	.MACRO __PUTWSR
	STD  Y+@2,R@0
	STD  Y+@2+1,R@1
	.ENDM

	.MACRO __MOVEWRR
	MOV  R@0,R@2
	MOV  R@1,R@3
	.ENDM

	.MACRO __INWR
	IN   R@0,@2
	IN   R@1,@2+1
	.ENDM

	.MACRO __OUTWR
	OUT  @2+1,R@1
	OUT  @2,R@0
	.ENDM

	.MACRO __CALL1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	ICALL
	.ENDM

	.MACRO __CALL1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	RCALL __GETW1PF
	ICALL
	.ENDM

	.MACRO __CALL2EN
	PUSH R26
	PUSH R27
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMRDW
	POP  R27
	POP  R26
	ICALL
	.ENDM

	.MACRO __CALL2EX
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	RCALL __EEPROMRDD
	ICALL
	.ENDM

	.MACRO __GETW1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R31,Z
	MOV  R30,R0
	.ENDM

	.MACRO __GETD1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R1,Z+
	LD   R22,Z
	MOVW R30,R0
	.ENDM

	.MACRO __NBST
	BST  R@0,@1
	IN   R30,SREG
	LDI  R31,0x40
	EOR  R30,R31
	OUT  SREG,R30
	.ENDM


	.MACRO __PUTB1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RNS
	MOVW R26,R@0
	ADIW R26,@1
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	RCALL __PUTDP1
	.ENDM


	.MACRO __GETB1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R30,Z
	.ENDM

	.MACRO __GETB1HSX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	.ENDM

	.MACRO __GETW1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R0,Z+
	LD   R31,Z
	MOV  R30,R0
	.ENDM

	.MACRO __GETD1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R0,Z+
	LD   R1,Z+
	LD   R22,Z+
	LD   R23,Z
	MOVW R30,R0
	.ENDM

	.MACRO __GETB2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R26,X
	.ENDM

	.MACRO __GETW2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	.ENDM

	.MACRO __GETD2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R1,X+
	LD   R24,X+
	LD   R25,X
	MOVW R26,R0
	.ENDM

	.MACRO __GETBRSX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	LD   R@0,Z
	.ENDM

	.MACRO __GETWRSX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	LD   R@0,Z+
	LD   R@1,Z
	.ENDM

	.MACRO __GETBRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	LD   R@0,X
	.ENDM

	.MACRO __GETWRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	LD   R@0,X+
	LD   R@1,X
	.ENDM

	.MACRO __LSLW8SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	CLR  R30
	.ENDM

	.MACRO __PUTB1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __CLRW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __CLRD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R30
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __PUTB2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z,R26
	.ENDM

	.MACRO __PUTW2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z,R27
	.ENDM

	.MACRO __PUTD2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z+,R27
	ST   Z+,R24
	ST   Z,R25
	.ENDM

	.MACRO __PUTBSRX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	ST   Z,R@0
	.ENDM

	.MACRO __PUTWSRX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	ST   Z+,R@0
	ST   Z,R@1
	.ENDM

	.MACRO __PUTB1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __MULBRR
	MULS R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRRU
	MUL  R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRR0
	MULS R@0,R@1
	.ENDM

	.MACRO __MULBRRU0
	MUL  R@0,R@1
	.ENDM

	.MACRO __MULBNWRU
	LDI  R26,@2
	MUL  R26,R@0
	MOVW R30,R0
	MUL  R26,R@1
	ADD  R31,R0
	.ENDM

;NAME DEFINITIONS FOR GLOBAL VARIABLES ALLOCATED TO REGISTERS
	.DEF _baud_mode=R4
	.DEF _baud_mode_msb=R5
	.DEF _rx_wr_index=R7
	.DEF _rx_rd_index=R6
	.DEF _rx_counter=R9
	.DEF _FRONT_ANALOG=R10
	.DEF _FRONT_ANALOG_msb=R11
	.DEF _FLAME_SENSOR=R12
	.DEF _FLAME_SENSOR_msb=R13

	.CSEG
	.ORG 0x00

;START OF CODE MARKER
__START_OF_CODE:

;INTERRUPT VECTORS
	RJMP __RESET
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP _usart_rx_isr
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00

_tbl10_G100:
	.DB  0x10,0x27,0xE8,0x3,0x64,0x0,0xA,0x0
	.DB  0x1,0x0
_tbl16_G100:
	.DB  0x0,0x10,0x0,0x1,0x10,0x0,0x1,0x0

;REGISTER BIT VARIABLES INITIALIZATION
__REG_BIT_VARS:
	.DW  0x0000

;GLOBAL REGISTER VARIABLES INITIALIZATION
__REG_VARS:
	.DB  0x0,0x0

_0xD:
	.DB  0x3C
_0xE:
	.DB  0x3E
_0xF:
	.DB  0x1
_0x10:
	.DB  0x2
_0x11:
	.DB  0x3
_0x12:
	.DB  0x4
_0x13:
	.DB  0x5
_0x14:
	.DB  0x6
_0x15:
	.DB  0x7
_0x16:
	.DB  0x8
_0x2020060:
	.DB  0x1
_0x2020000:
	.DB  0x2D,0x4E,0x41,0x4E,0x0,0x49,0x4E,0x46
	.DB  0x0

__GLOBAL_INI_TBL:
	.DW  0x01
	.DW  0x02
	.DW  __REG_BIT_VARS*2

	.DW  0x02
	.DW  0x0C
	.DW  __REG_VARS*2

	.DW  0x01
	.DW  _COMMAND_FLAG_A
	.DW  _0xD*2

	.DW  0x01
	.DW  _COMMAND_FLAG_B
	.DW  _0xE*2

	.DW  0x01
	.DW  _FLAME_REAR_LEFT
	.DW  _0xF*2

	.DW  0x01
	.DW  _FLAME_LEFT
	.DW  _0x10*2

	.DW  0x01
	.DW  _FLAME_ASKEW_LEFT
	.DW  _0x11*2

	.DW  0x01
	.DW  _FLAME_FRONT
	.DW  _0x12*2

	.DW  0x01
	.DW  _FLAME_ASKEW_RIGHT
	.DW  _0x13*2

	.DW  0x01
	.DW  _FLAME_RIGHT
	.DW  _0x14*2

	.DW  0x01
	.DW  _FLAME_REAR_RIGHT
	.DW  _0x15*2

	.DW  0x01
	.DW  _FLAME_CENTER
	.DW  _0x16*2

	.DW  0x01
	.DW  __seed_G101
	.DW  _0x2020060*2

_0xFFFFFFFF:
	.DW  0

#define __GLOBAL_INI_TBL_PRESENT 1

__RESET:
	CLI
	CLR  R30
	OUT  EECR,R30

;INTERRUPT VECTORS ARE PLACED
;AT THE START OF FLASH
	LDI  R31,1
	OUT  GICR,R31
	OUT  GICR,R30
	OUT  MCUCR,R30

;CLEAR R2-R14
	LDI  R24,(14-2)+1
	LDI  R26,2
	CLR  R27
__CLEAR_REG:
	ST   X+,R30
	DEC  R24
	BRNE __CLEAR_REG

;CLEAR SRAM
	LDI  R24,LOW(__CLEAR_SRAM_SIZE)
	LDI  R25,HIGH(__CLEAR_SRAM_SIZE)
	LDI  R26,__SRAM_START
__CLEAR_SRAM:
	ST   X+,R30
	SBIW R24,1
	BRNE __CLEAR_SRAM

;GLOBAL VARIABLES INITIALIZATION
	LDI  R30,LOW(__GLOBAL_INI_TBL*2)
	LDI  R31,HIGH(__GLOBAL_INI_TBL*2)
__GLOBAL_INI_NEXT:
	LPM  R24,Z+
	LPM  R25,Z+
	SBIW R24,0
	BREQ __GLOBAL_INI_END
	LPM  R26,Z+
	LPM  R27,Z+
	LPM  R0,Z+
	LPM  R1,Z+
	MOVW R22,R30
	MOVW R30,R0
__GLOBAL_INI_LOOP:
	LPM  R0,Z+
	ST   X+,R0
	SBIW R24,1
	BRNE __GLOBAL_INI_LOOP
	MOVW R30,R22
	RJMP __GLOBAL_INI_NEXT
__GLOBAL_INI_END:

;HARDWARE STACK POINTER INITIALIZATION
	LDI  R30,LOW(__SRAM_END-__HEAP_SIZE)
	OUT  SPL,R30
	LDI  R30,HIGH(__SRAM_END-__HEAP_SIZE)
	OUT  SPH,R30

;DATA STACK POINTER INITIALIZATION
	LDI  R28,LOW(__SRAM_START+__DSTACK_SIZE)
	LDI  R29,HIGH(__SRAM_START+__DSTACK_SIZE)

	RJMP _main

	.ESEG
	.ORG 0

	.DSEG
	.ORG 0x160

	.CSEG
;/*******************************************************
;This program was created by the
;CodeWizardAVR V3.12 Advanced
;Automatic Program Generator
;© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
;http://www.hpinfotech.com
;
;Project : BW Digital Flame Sensor Ver 1
;Version : Ver 1
;Date    : 2/1/2017
;Author  : Intelligent Fire Fighting Robot Division
;Company : University of Brawijaya
;Comments:
;
;
;Chip type               : ATmega8
;Program type            : Application
;AVR Core Clock frequency: 16.000000 MHz
;Memory model            : Small
;External RAM size       : 0
;Data Stack size         : 256
;*******************************************************/
;
;#include <mega8.h>
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif
;#include <stdio.h>
;#include <stdlib.h>
;#include <delay.h>
;#include <math.h>
;#include <sleep.h>
;
;//char x=0;
;int baud_mode;
;
;//UART SPEED CONFIG VARIABLES
;const int DEBUG_MODE = 2;
;const int ROBOT_MODE = 1;
;void UART_Speed_Config(int mode);
;
;
;void BW_Initialization(void);
;void Send_UART(unsigned char data);
;
;#ifndef RXB8
;#define RXB8 1
;#endif
;
;#ifndef TXB8
;#define TXB8 0
;#endif
;
;#ifndef UPE
;#define UPE 2
;#endif
;
;#ifndef DOR
;#define DOR 3
;#endif
;
;#ifndef FE
;#define FE 4
;#endif
;
;#ifndef UDRE
;#define UDRE 5
;#endif
;
;#ifndef RXC
;#define RXC 7
;#endif
;
;#define FRAMING_ERROR (1<<FE)
;#define PARITY_ERROR (1<<UPE)
;#define DATA_OVERRUN (1<<DOR)
;#define DATA_REGISTER_EMPTY (1<<UDRE)
;#define RX_COMPLETE (1<<RXC)
;
;// USART Receiver buffer
;#define RX_BUFFER_SIZE 8
;char rx_buffer[RX_BUFFER_SIZE];
;
;#if RX_BUFFER_SIZE <= 256
;unsigned char rx_wr_index,rx_rd_index,rx_counter;
;#else
;unsigned int rx_wr_index,rx_rd_index,rx_counter;
;#endif
;
;// This flag is set on USART Receiver buffer overflow
;bit rx_buffer_overflow;
;
;// USART Receiver interrupt service routine
;interrupt [USART_RXC] void usart_rx_isr(void)
; 0000 005C {

	.CSEG
_usart_rx_isr:
; .FSTART _usart_rx_isr
	ST   -Y,R30
	ST   -Y,R31
	IN   R30,SREG
	ST   -Y,R30
; 0000 005D char status,data;
; 0000 005E status=UCSRA;
	RCALL __SAVELOCR2
;	status -> R17
;	data -> R16
	IN   R17,11
; 0000 005F data=UDR;
	IN   R16,12
; 0000 0060 if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
	MOV  R30,R17
	ANDI R30,LOW(0x1C)
	BRNE _0x3
; 0000 0061    {
; 0000 0062    rx_buffer[rx_wr_index++]=data;
	MOV  R30,R7
	INC  R7
	LDI  R31,0
	SUBI R30,LOW(-_rx_buffer)
	SBCI R31,HIGH(-_rx_buffer)
	ST   Z,R16
; 0000 0063 #if RX_BUFFER_SIZE == 256
; 0000 0064    // special case for receiver buffer size=256
; 0000 0065    if (++rx_counter == 0)
; 0000 0066       {
; 0000 0067 #else
; 0000 0068    if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
	LDI  R30,LOW(8)
	CP   R30,R7
	BRNE _0x4
	CLR  R7
; 0000 0069    if (++rx_counter == RX_BUFFER_SIZE)
_0x4:
	INC  R9
	LDI  R30,LOW(8)
	CP   R30,R9
	BRNE _0x5
; 0000 006A       {
; 0000 006B       rx_counter=0;
	CLR  R9
; 0000 006C #endif
; 0000 006D       rx_buffer_overflow=1;
	SET
	BLD  R2,0
; 0000 006E       }
; 0000 006F    }
_0x5:
; 0000 0070 }
_0x3:
	LD   R16,Y+
	LD   R17,Y+
	LD   R30,Y+
	OUT  SREG,R30
	LD   R31,Y+
	LD   R30,Y+
	RETI
; .FEND
;
;#ifndef _DEBUG_TERMINAL_IO_
;// Get a character from the USART Receiver buffer
;#define _ALTERNATE_GETCHAR_
;#pragma used+
;char getchar(void)
; 0000 0077 {
; 0000 0078 char data;
; 0000 0079 while (rx_counter==0);
;	data -> R17
; 0000 007A data=rx_buffer[rx_rd_index++];
; 0000 007B #if RX_BUFFER_SIZE != 256
; 0000 007C if (rx_rd_index == RX_BUFFER_SIZE) rx_rd_index=0;
; 0000 007D #endif
; 0000 007E #asm("cli")
; 0000 007F --rx_counter;
; 0000 0080 #asm("sei")
; 0000 0081 return data;
; 0000 0082 }
;#pragma used-
;#endif
;
;// Standard Input/Output functions
;#include <stdio.h>
;
;#define ADC_VREF_TYPE 0x60
;
;// Read the 8 most significant bits
;// of the AD conversion result
;unsigned char read_adc(unsigned char adc_input)
; 0000 008E {
_read_adc:
; .FSTART _read_adc
; 0000 008F ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
	ST   -Y,R26
;	adc_input -> Y+0
	LD   R30,Y
	ORI  R30,LOW(0x60)
	OUT  0x7,R30
; 0000 0090 // Delay needed for the stabilization of the ADC input voltage
; 0000 0091 delay_us(10);
	__DELAY_USB 53
; 0000 0092 // Start the AD conversion
; 0000 0093 ADCSRA|=0x40;
	SBI  0x6,6
; 0000 0094 // Wait for the AD conversion to complete
; 0000 0095 while ((ADCSRA & 0x10)==0);
_0xA:
	SBIS 0x6,4
	RJMP _0xA
; 0000 0096 ADCSRA|=0x10;
	SBI  0x6,4
; 0000 0097 return ADCH;
	IN   R30,0x5
	RJMP _0x20C0001
; 0000 0098 }
; .FEND
;
;// Declare your global variables here
;unsigned int FLAME_ANALOG[9]={0,0,0,0,0,0,0,0,0};
;//unsigned int FLAME_LOGIC[8]={0,0,0,0,0,0,0,0};
;unsigned int FRONT_ANALOG;
;
;
;int FLAME_SENSOR=0;
;
;//FLAG VARIABLES
;unsigned int COMMAND_FLAG_A = 0x3C;

	.DSEG
;unsigned int COMMAND_FLAG_B = 0x3E;
;const unsigned int COMMAND_COMPLETED = 0x7C;
;
;unsigned int MAX_VAL;
;//MACRO
;int NO_FLAME            = 0;
;
;int FLAME_REAR_LEFT     = 1;
;int FLAME_LEFT          = 2;
;int FLAME_ASKEW_LEFT    = 3;
;int FLAME_FRONT         = 4;
;int FLAME_ASKEW_RIGHT   = 5;
;int FLAME_RIGHT         = 6;
;int FLAME_REAR_RIGHT    = 7;
;int FLAME_CENTER        = 8;
;
;//           ADC4
;//           ADC3
;//     ADC2       ADC5
;//  ADC1              ADC6
;//   ADC0           ADC7
;
;void main(void)
; 0000 00BB {

	.CSEG
_main:
; .FSTART _main
; 0000 00BC     // Declare your local variables here
; 0000 00BD     BW_Initialization();
	RCALL _BW_Initialization
; 0000 00BE     UART_Speed_Config(DEBUG_MODE);
	LDI  R26,LOW(2)
	LDI  R27,HIGH(2)
	RCALL _UART_Speed_Config
; 0000 00BF 
; 0000 00C0 
; 0000 00C1     while (1)
_0x17:
; 0000 00C2       {
; 0000 00C3             FLAME_ANALOG[0]=read_adc(0);
	LDI  R26,LOW(0)
	RCALL _read_adc
	LDI  R31,0
	STS  _FLAME_ANALOG,R30
	STS  _FLAME_ANALOG+1,R31
; 0000 00C4             FLAME_ANALOG[1]=read_adc(1);
	LDI  R26,LOW(1)
	RCALL _read_adc
	__POINTW2MN _FLAME_ANALOG,2
	RCALL SUBOPT_0x0
; 0000 00C5             FLAME_ANALOG[2]=read_adc(2);
	LDI  R26,LOW(2)
	RCALL _read_adc
	__POINTW2MN _FLAME_ANALOG,4
	RCALL SUBOPT_0x0
; 0000 00C6             FLAME_ANALOG[3]=read_adc(3);
	LDI  R26,LOW(3)
	RCALL _read_adc
	__POINTW2MN _FLAME_ANALOG,6
	RCALL SUBOPT_0x0
; 0000 00C7             FLAME_ANALOG[4]=read_adc(4);
	LDI  R26,LOW(4)
	RCALL _read_adc
	__POINTW2MN _FLAME_ANALOG,8
	RCALL SUBOPT_0x0
; 0000 00C8             FLAME_ANALOG[5]=read_adc(5);
	LDI  R26,LOW(5)
	RCALL _read_adc
	__POINTW2MN _FLAME_ANALOG,10
	RCALL SUBOPT_0x0
; 0000 00C9             FLAME_ANALOG[6]=read_adc(6);
	LDI  R26,LOW(6)
	RCALL _read_adc
	__POINTW2MN _FLAME_ANALOG,12
	RCALL SUBOPT_0x0
; 0000 00CA             FLAME_ANALOG[7]=read_adc(7);
	LDI  R26,LOW(7)
	RCALL _read_adc
	__POINTW2MN _FLAME_ANALOG,14
	RCALL SUBOPT_0x0
; 0000 00CB 
; 0000 00CC             FRONT_ANALOG=FLAME_ANALOG[4];
	__GETWRMN 10,11,_FLAME_ANALOG,8
; 0000 00CD 
; 0000 00CE             MAX_VAL= max(FLAME_ANALOG[0],FLAME_ANALOG[1]);
	RCALL SUBOPT_0x1
	RCALL SUBOPT_0x2
	__GETW2MN _FLAME_ANALOG,2
	RCALL SUBOPT_0x3
; 0000 00CF             MAX_VAL= max(MAX_VAL,FLAME_ANALOG[2]);
	__GETW2MN _FLAME_ANALOG,4
	RCALL SUBOPT_0x3
; 0000 00D0             MAX_VAL= max(MAX_VAL,FLAME_ANALOG[3]);
	__GETW2MN _FLAME_ANALOG,6
	RCALL SUBOPT_0x3
; 0000 00D1             MAX_VAL= max(MAX_VAL,FLAME_ANALOG[4]);
	__GETW2MN _FLAME_ANALOG,8
	RCALL SUBOPT_0x3
; 0000 00D2             MAX_VAL= max(MAX_VAL,FLAME_ANALOG[5]);
	__GETW2MN _FLAME_ANALOG,10
	RCALL SUBOPT_0x3
; 0000 00D3             MAX_VAL= max(MAX_VAL,FLAME_ANALOG[6]);
	__GETW2MN _FLAME_ANALOG,12
	RCALL SUBOPT_0x3
; 0000 00D4             MAX_VAL= max(MAX_VAL,FLAME_ANALOG[7]);
	__GETW2MN _FLAME_ANALOG,14
	RCALL _max
	STS  _MAX_VAL,R30
	STS  _MAX_VAL+1,R31
; 0000 00D5 
; 0000 00D6             if(MAX_VAL>=100)
	RCALL SUBOPT_0x4
	CPI  R26,LOW(0x64)
	LDI  R30,HIGH(0x64)
	CPC  R27,R30
	BRSH PC+2
	RJMP _0x1A
; 0000 00D7             {
; 0000 00D8                 if(MAX_VAL==FLAME_ANALOG[4])
	__GETW1MN _FLAME_ANALOG,8
	RCALL SUBOPT_0x5
	BRNE _0x1B
; 0000 00D9                 {
; 0000 00DA                     FLAME_SENSOR=FLAME_CENTER;
	__GETWRMN 12,13,0,_FLAME_CENTER
; 0000 00DB                 }
; 0000 00DC                 else if(MAX_VAL==FLAME_ANALOG[3])
	RJMP _0x1C
_0x1B:
	__GETW1MN _FLAME_ANALOG,6
	RCALL SUBOPT_0x5
	BRNE _0x1D
; 0000 00DD                 {
; 0000 00DE                     FLAME_SENSOR=FLAME_FRONT;
	__GETWRMN 12,13,0,_FLAME_FRONT
; 0000 00DF                 }
; 0000 00E0                 else if(MAX_VAL==FLAME_ANALOG[2])
	RJMP _0x1E
_0x1D:
	__GETW1MN _FLAME_ANALOG,4
	RCALL SUBOPT_0x5
	BRNE _0x1F
; 0000 00E1                 {
; 0000 00E2                     FLAME_SENSOR=FLAME_ASKEW_LEFT;
	__GETWRMN 12,13,0,_FLAME_ASKEW_LEFT
; 0000 00E3                 }
; 0000 00E4                 else if(MAX_VAL==FLAME_ANALOG[5])
	RJMP _0x20
_0x1F:
	__GETW1MN _FLAME_ANALOG,10
	RCALL SUBOPT_0x5
	BRNE _0x21
; 0000 00E5                 {
; 0000 00E6                     FLAME_SENSOR=FLAME_ASKEW_RIGHT;
	__GETWRMN 12,13,0,_FLAME_ASKEW_RIGHT
; 0000 00E7                 }
; 0000 00E8                 else if(MAX_VAL==FLAME_ANALOG[1])
	RJMP _0x22
_0x21:
	__GETW1MN _FLAME_ANALOG,2
	RCALL SUBOPT_0x5
	BRNE _0x23
; 0000 00E9                 {
; 0000 00EA                     FLAME_SENSOR=FLAME_LEFT;
	__GETWRMN 12,13,0,_FLAME_LEFT
; 0000 00EB                 }
; 0000 00EC                 else if(MAX_VAL==FLAME_ANALOG[6])
	RJMP _0x24
_0x23:
	__GETW1MN _FLAME_ANALOG,12
	RCALL SUBOPT_0x5
	BRNE _0x25
; 0000 00ED                 {
; 0000 00EE                     FLAME_SENSOR=FLAME_RIGHT;
	__GETWRMN 12,13,0,_FLAME_RIGHT
; 0000 00EF                 }
; 0000 00F0                 else if(MAX_VAL==FLAME_ANALOG[0])
	RJMP _0x26
_0x25:
	RCALL SUBOPT_0x1
	RCALL SUBOPT_0x5
	BRNE _0x27
; 0000 00F1                 {
; 0000 00F2                     FLAME_SENSOR=FLAME_REAR_LEFT;
	__GETWRMN 12,13,0,_FLAME_REAR_LEFT
; 0000 00F3                 }
; 0000 00F4                 else if(MAX_VAL==FLAME_ANALOG[7])
	RJMP _0x28
_0x27:
	__GETW1MN _FLAME_ANALOG,14
	RCALL SUBOPT_0x5
	BRNE _0x29
; 0000 00F5                 {
; 0000 00F6                     FLAME_SENSOR=FLAME_REAR_RIGHT;
	__GETWRMN 12,13,0,_FLAME_REAR_RIGHT
; 0000 00F7                 }
; 0000 00F8 
; 0000 00F9             }
_0x29:
_0x28:
_0x26:
_0x24:
_0x22:
_0x20:
_0x1E:
_0x1C:
; 0000 00FA             else
	RJMP _0x2A
_0x1A:
; 0000 00FB             {
; 0000 00FC                 FLAME_SENSOR=NO_FLAME;
	__GETWRMN 12,13,0,_NO_FLAME
; 0000 00FD             }
_0x2A:
; 0000 00FE 
; 0000 00FF             Send_UART(COMMAND_FLAG_A);
	LDS  R26,_COMMAND_FLAG_A
	RCALL _Send_UART
; 0000 0100             Send_UART(COMMAND_FLAG_B);
	LDS  R26,_COMMAND_FLAG_B
	RCALL _Send_UART
; 0000 0101             Send_UART(FLAME_SENSOR);
	MOV  R26,R12
	RCALL _Send_UART
; 0000 0102             Send_UART(FRONT_ANALOG);
	MOV  R26,R10
	RCALL _Send_UART
; 0000 0103 
; 0000 0104       }
	RJMP _0x17
; 0000 0105 }
_0x2B:
	RJMP _0x2B
; .FEND
;
;
;void BW_Initialization(void)
; 0000 0109 {
_BW_Initialization:
; .FSTART _BW_Initialization
; 0000 010A     // Input/Output Ports initialization
; 0000 010B     // Port B initialization
; 0000 010C     // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
; 0000 010D     // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
; 0000 010E     PORTB=0x00;
	LDI  R30,LOW(0)
	OUT  0x18,R30
; 0000 010F     DDRB=0x00;
	OUT  0x17,R30
; 0000 0110 
; 0000 0111     // Port C initialization
; 0000 0112     // Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
; 0000 0113     // State6=T State5=T State4=T State3=T State2=T State1=T State0=T
; 0000 0114     PORTC=0x00;
	OUT  0x15,R30
; 0000 0115     DDRC=0x00;
	OUT  0x14,R30
; 0000 0116 
; 0000 0117     // Port D initialization
; 0000 0118     // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
; 0000 0119     // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
; 0000 011A     PORTD=0x00;
	OUT  0x12,R30
; 0000 011B     DDRD=0x00;
	OUT  0x11,R30
; 0000 011C 
; 0000 011D     // Timer/Counter 0 initialization
; 0000 011E     // Clock source: System Clock
; 0000 011F     // Clock value: Timer 0 Stopped
; 0000 0120     TCCR0=0x00;
	OUT  0x33,R30
; 0000 0121     TCNT0=0x00;
	OUT  0x32,R30
; 0000 0122 
; 0000 0123     // Timer/Counter 1 initialization
; 0000 0124     // Clock source: System Clock
; 0000 0125     // Clock value: Timer1 Stopped
; 0000 0126     // Mode: Normal top=0xFFFF
; 0000 0127     // OC1A output: Discon.
; 0000 0128     // OC1B output: Discon.
; 0000 0129     // Noise Canceler: Off
; 0000 012A     // Input Capture on Falling Edge
; 0000 012B     // Timer1 Overflow Interrupt: Off
; 0000 012C     // Input Capture Interrupt: Off
; 0000 012D     // Compare A Match Interrupt: Off
; 0000 012E     // Compare B Match Interrupt: Off
; 0000 012F     TCCR1A=0x00;
	OUT  0x2F,R30
; 0000 0130     TCCR1B=0x00;
	OUT  0x2E,R30
; 0000 0131     TCNT1H=0x00;
	OUT  0x2D,R30
; 0000 0132     TCNT1L=0x00;
	OUT  0x2C,R30
; 0000 0133     ICR1H=0x00;
	OUT  0x27,R30
; 0000 0134     ICR1L=0x00;
	OUT  0x26,R30
; 0000 0135     OCR1AH=0x00;
	OUT  0x2B,R30
; 0000 0136     OCR1AL=0x00;
	OUT  0x2A,R30
; 0000 0137     OCR1BH=0x00;
	OUT  0x29,R30
; 0000 0138     OCR1BL=0x00;
	OUT  0x28,R30
; 0000 0139 
; 0000 013A     // Timer/Counter 2 initialization
; 0000 013B     // Clock source: System Clock
; 0000 013C     // Clock value: Timer2 Stopped
; 0000 013D     // Mode: Normal top=0xFF
; 0000 013E     // OC2 output: Disconnected
; 0000 013F     ASSR=0x00;
	OUT  0x22,R30
; 0000 0140     TCCR2=0x00;
	OUT  0x25,R30
; 0000 0141     TCNT2=0x00;
	OUT  0x24,R30
; 0000 0142     OCR2=0x00;
	OUT  0x23,R30
; 0000 0143 
; 0000 0144     // External Interrupt(s) initialization
; 0000 0145     // INT0: Off
; 0000 0146     // INT1: Off
; 0000 0147     MCUCR=0x00;
	OUT  0x35,R30
; 0000 0148 
; 0000 0149     // Timer(s)/Counter(s) Interrupt(s) initialization
; 0000 014A     TIMSK=0x00;
	OUT  0x39,R30
; 0000 014B 
; 0000 014C     // USART initialization
; 0000 014D     // Communication Parameters: 8 Data, 1 Stop, No Parity
; 0000 014E     // USART Receiver: On
; 0000 014F     // USART Transmitter: On
; 0000 0150     // USART Mode: Asynchronous
; 0000 0151     // USART Baud Rate: 9600
; 0000 0152     UCSRA=0x00;
	OUT  0xB,R30
; 0000 0153     UCSRB=0x98;
	LDI  R30,LOW(152)
	OUT  0xA,R30
; 0000 0154     UCSRC=0x86;
	LDI  R30,LOW(134)
	OUT  0x20,R30
; 0000 0155     UBRRH=0x00;
	LDI  R30,LOW(0)
	OUT  0x20,R30
; 0000 0156     UBRRL=0x67;
	LDI  R30,LOW(103)
	OUT  0x9,R30
; 0000 0157 
; 0000 0158     // Analog Comparator initialization
; 0000 0159     // Analog Comparator: Off
; 0000 015A     // Analog Comparator Input Capture by Timer/Counter 1: Off
; 0000 015B     ACSR=0x80;
	LDI  R30,LOW(128)
	OUT  0x8,R30
; 0000 015C     SFIOR=0x00;
	LDI  R30,LOW(0)
	OUT  0x30,R30
; 0000 015D 
; 0000 015E     // ADC initialization
; 0000 015F     // ADC Clock frequency: 1000.000 kHz
; 0000 0160     // ADC Voltage Reference: AVCC pin
; 0000 0161     // Only the 8 most significant bits of
; 0000 0162     // the AD conversion result are used
; 0000 0163     ADMUX=ADC_VREF_TYPE & 0xff;
	LDI  R30,LOW(96)
	OUT  0x7,R30
; 0000 0164     ADCSRA=0x84;
	LDI  R30,LOW(132)
	OUT  0x6,R30
; 0000 0165 
; 0000 0166     // SPI initialization
; 0000 0167     // SPI disabled
; 0000 0168     SPCR=0x00;
	LDI  R30,LOW(0)
	OUT  0xD,R30
; 0000 0169 
; 0000 016A     // TWI initialization
; 0000 016B     // TWI disabled
; 0000 016C     TWCR=0x00;
	OUT  0x36,R30
; 0000 016D 
; 0000 016E     // Global enable interrupts
; 0000 016F     #asm("sei")
	sei
; 0000 0170 
; 0000 0171 }
	RET
; .FEND
;
;void UART_Speed_Config(int mode)
; 0000 0174 {
_UART_Speed_Config:
; .FSTART _UART_Speed_Config
; 0000 0175     //BAUD RATE SELECT INITIALIZATION
; 0000 0176     if (PINB.3==0) baud_mode=1;
	ST   -Y,R27
	ST   -Y,R26
;	mode -> Y+0
	SBIC 0x16,3
	RJMP _0x2C
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	RJMP _0x37
; 0000 0177     else if (PINB.3==1) baud_mode=2;
_0x2C:
	SBIS 0x16,3
	RJMP _0x2E
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
_0x37:
	MOVW R4,R30
; 0000 0178 
; 0000 0179     switch(mode)
_0x2E:
	LD   R30,Y
	LDD  R31,Y+1
; 0000 017A     {
; 0000 017B         case 1:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0x32
; 0000 017C             {
; 0000 017D                 UBRRH=0x00;
	LDI  R30,LOW(0)
	OUT  0x20,R30
; 0000 017E                 UBRRL=0x00;
	RJMP _0x38
; 0000 017F             }break;
; 0000 0180         case 2:
_0x32:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0x31
; 0000 0181             {
; 0000 0182                 UBRRH=0x00;
	LDI  R30,LOW(0)
	OUT  0x20,R30
; 0000 0183                 UBRRL=0x67;
	LDI  R30,LOW(103)
_0x38:
	OUT  0x9,R30
; 0000 0184             }break;
; 0000 0185 
; 0000 0186     }
_0x31:
; 0000 0187 
; 0000 0188     #asm("cli")
	cli
; 0000 0189 
; 0000 018A     #asm("sei")
	sei
; 0000 018B }
	ADIW R28,2
	RET
; .FEND
;
;void Send_UART(unsigned char data)
; 0000 018E {
_Send_UART:
; .FSTART _Send_UART
; 0000 018F     while(!(UCSRA & (1<<UDRE))){};
	ST   -Y,R26
;	data -> Y+0
_0x34:
	SBIS 0xB,5
	RJMP _0x34
; 0000 0190     UDR=data;
	LD   R30,Y
	OUT  0xC,R30
; 0000 0191 }
_0x20C0001:
	ADIW R28,1
	RET
; .FEND
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif

	.CSEG

	.CSEG

	.DSEG

	.CSEG

	.CSEG
_max:
; .FSTART _max
	ST   -Y,R27
	ST   -Y,R26
    ld   r26,y+
    ld   r27,y+
    ld   r30,y+
    ld   r31,y+
    cp   r26,r30
    cpc  r27,r31
    brlt __max0
    movw r30,r26
__max0:
    ret
; .FEND
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif

	.CSEG

	.CSEG

	.CSEG

	.DSEG
_rx_buffer:
	.BYTE 0x8
_FLAME_ANALOG:
	.BYTE 0x12
_COMMAND_FLAG_A:
	.BYTE 0x2
_COMMAND_FLAG_B:
	.BYTE 0x2
_MAX_VAL:
	.BYTE 0x2
_NO_FLAME:
	.BYTE 0x2
_FLAME_REAR_LEFT:
	.BYTE 0x2
_FLAME_LEFT:
	.BYTE 0x2
_FLAME_ASKEW_LEFT:
	.BYTE 0x2
_FLAME_FRONT:
	.BYTE 0x2
_FLAME_ASKEW_RIGHT:
	.BYTE 0x2
_FLAME_RIGHT:
	.BYTE 0x2
_FLAME_REAR_RIGHT:
	.BYTE 0x2
_FLAME_CENTER:
	.BYTE 0x2
__seed_G101:
	.BYTE 0x4

	.CSEG
;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0x0:
	LDI  R31,0
	ST   X+,R30
	ST   X,R31
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x1:
	LDS  R30,_FLAME_ANALOG
	LDS  R31,_FLAME_ANALOG+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x2:
	ST   -Y,R31
	ST   -Y,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:43 WORDS
SUBOPT_0x3:
	RCALL _max
	STS  _MAX_VAL,R30
	STS  _MAX_VAL+1,R31
	RJMP SUBOPT_0x2

;OPTIMIZER ADDED SUBROUTINE, CALLED 9 TIMES, CODE SIZE REDUCTION:22 WORDS
SUBOPT_0x4:
	LDS  R26,_MAX_VAL
	LDS  R27,_MAX_VAL+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 8 TIMES, CODE SIZE REDUCTION:12 WORDS
SUBOPT_0x5:
	RCALL SUBOPT_0x4
	CP   R30,R26
	CPC  R31,R27
	RET


	.CSEG
__SAVELOCR2:
	ST   -Y,R17
	ST   -Y,R16
	RET

;END OF CODE MARKER
__END_OF_CODE:
