
;CodeVisionAVR C Compiler V3.12 Advanced
;(C) Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
;http://www.hpinfotech.com

;Build configuration    : Release
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
;Global 'const' stored in FLASH: No
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
	.DEF _DETECTED_COLOUR=R4
	.DEF _DETECTED_COLOUR_msb=R5
	.DEF _Threshold_White=R6
	.DEF _Threshold_White_msb=R7
	.DEF _Threshold_Black=R8
	.DEF _Threshold_Black_msb=R9
	.DEF _Threshold_Gray=R10
	.DEF _Threshold_Gray_msb=R11
	.DEF _TRACER_GRAYDATA=R12
	.DEF _TRACER_GRAYDATA_msb=R13

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
	RJMP _timer1_ovf_isr
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

_0x3:
	.DB  0x4D,0x7
_0x4:
	.DB  0xC2,0x1
_0x5:
	.DB  0xC6
_0x6:
	.DB  0x3C
_0x7:
	.DB  0x3E
_0x8:
	.DB  0x7C
_0x9:
	.DB  0x29
_0xA:
	.DB  0x2A
_0xB:
	.DB  0x2B
_0xC:
	.DB  0x2C
_0xD:
	.DB  0x2D
_0xE:
	.DB  0x2E
_0xF:
	.DB  0x35
_0x10:
	.DB  0x5E
_0x11:
	.DB  0x53
_0x12:
	.DB  0x41
_0x13:
	.DB  0x42
_0x14:
	.DB  0x58
_0x15:
	.DB  0x5E
_0x16:
	.DB  0x41
_0x17:
	.DB  0x42
_0x18:
	.DB  0x43
_0x19:
	.DB  0x5A
_0x1A:
	.DB  0x58
_0x1B:
	.DB  0x46
_0x1C:
	.DB  0x47
_0x1D:
	.DB  0x48
_0x1E:
	.DB  0x49
_0x1F:
	.DB  0x4A
_0x20:
	.DB  0x4B
_0x21:
	.DB  0x4C
_0x22:
	.DB  0x52
_0x23:
	.DB  0x53
_0x24:
	.DB  0x1
_0x25:
	.DB  0xD0,0x7
_0x26:
	.DB  0x3F,0xC
_0x27:
	.DB  0x52
_0xCF:
	.DB  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
	.DB  0x0,0x0
_0x0:
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x20,0xD,0x0
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x46,0x52,0x4F,0x4E,0x54,0x20
	.DB  0x54,0x43,0x53,0x33,0x32,0x30,0x30,0x20
	.DB  0x4D,0x4F,0x4E,0x49,0x54,0x4F,0x52,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x20,0xD,0x0
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x4D,0x49,0x44,0x44,0x4C
	.DB  0x45,0x20,0x54,0x43,0x53,0x33,0x32,0x30
	.DB  0x30,0x20,0x4D,0x4F,0x4E,0x49,0x54,0x4F
	.DB  0x52,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D
	.DB  0x3D,0x3D,0x3D,0x3D,0x3D,0x20,0xD,0x0
	.DB  0x52,0x65,0x64,0x20,0x20,0x3A,0x20,0x25
	.DB  0x64,0x20,0x9,0x0,0x47,0x72,0x65,0x65
	.DB  0x6E,0x3A,0x20,0x25,0x64,0x20,0x9,0x0
	.DB  0x42,0x6C,0x75,0x65,0x3A,0x20,0x25,0x64
	.DB  0x20,0x9,0x0,0x57,0x68,0x69,0x74,0x65
	.DB  0x3A,0x20,0x25,0x64,0x20,0xD,0x0,0x54
	.DB  0x43,0x53,0x33,0x32,0x30,0x30,0x5F,0x54
	.DB  0x48,0x52,0x45,0x53,0x48,0x4F,0x4C,0x44
	.DB  0x20,0x3D,0x20,0x25,0x64,0x20,0x9,0x9
	.DB  0x20,0x54,0x43,0x53,0x33,0x32,0x30,0x30
	.DB  0x5F,0x54,0x4F,0x54,0x41,0x4C,0x5F,0x53
	.DB  0x55,0x4D,0x20,0x25,0x64,0x20,0xD,0x0
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
	.DW  0x04
	.DW  __REG_VARS*2

	.DW  0x02
	.DW  _Threshold_BW
	.DW  _0x3*2

	.DW  0x02
	.DW  _Threshold_BG
	.DW  _0x4*2

	.DW  0x01
	.DW  _TRACER_THRESHOLD
	.DW  _0x5*2

	.DW  0x01
	.DW  _COMMAND_FLAG_A
	.DW  _0x6*2

	.DW  0x01
	.DW  _COMMAND_FLAG_B
	.DW  _0x7*2

	.DW  0x01
	.DW  _START_BUTTON
	.DW  _0x11*2

	.DW  0x01
	.DW  _CMD_IDLE
	.DW  _0x15*2

	.DW  0x01
	.DW  _RAW_VAL_FLAG
	.DW  _0x27*2

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

;DISABLE WATCHDOG
	LDI  R31,0x18
	OUT  WDTCR,R31
	OUT  WDTCR,R30

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
;/*****************************************************
;This program was produced by the
;CodeWizardAVR V2.05.0 Professional
;Automatic Program Generator
;© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
;http://www.hpinfotech.com
;
;Project : YUME TCS3200 + Photodiode Tracer Processor
;Version : Ver.3.0
;Date    : April 21st 2016
;Author  : Ryan Batch 2013
;Company : Intelligent Fire Fighting Robot Division - Brawijaya University
;Comments:   Ver. 1 -> Basic function
;            Ver. 2 -> EEPROM autocalibration feature
;            Ver. 3 -> Optimization
;
;
;Chip type               : ATmega8
;Program type            : Application
;AVR Core Clock frequency: 16.000000 MHz
;Memory model            : Small
;External RAM size       : 0
;Data Stack size         : 256
;*****************************************************/
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
;#include <YUME2016_TCS3200TRACER_Hybrid_Processor_Ver_1.h>

	.DSEG
;
;// Standard Input/Output functions
;#include <stdio.h>
;
;
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
; 0000 0057 {

	.CSEG
_usart_rx_isr:
; .FSTART _usart_rx_isr
	ST   -Y,R26
	ST   -Y,R30
	ST   -Y,R31
	IN   R30,SREG
	ST   -Y,R30
; 0000 0058 char status,data;
; 0000 0059 status=UCSRA;
	RCALL __SAVELOCR2
;	status -> R17
;	data -> R16
	IN   R17,11
; 0000 005A data=UDR;
	IN   R16,12
; 0000 005B if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
	MOV  R30,R17
	ANDI R30,LOW(0x1C)
	BRNE _0x28
; 0000 005C    {
; 0000 005D    rx_buffer[rx_wr_index++]=data;
	LDS  R30,_rx_wr_index
	SUBI R30,-LOW(1)
	STS  _rx_wr_index,R30
	RCALL SUBOPT_0x0
	ST   Z,R16
; 0000 005E #if RX_BUFFER_SIZE == 256
; 0000 005F    // special case for receiver buffer size=256
; 0000 0060    if (++rx_counter == 0)
; 0000 0061       {
; 0000 0062 #else
; 0000 0063    if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
	LDS  R26,_rx_wr_index
	CPI  R26,LOW(0x8)
	BRNE _0x29
	LDI  R30,LOW(0)
	STS  _rx_wr_index,R30
; 0000 0064    if (++rx_counter == RX_BUFFER_SIZE)
_0x29:
	LDS  R26,_rx_counter
	SUBI R26,-LOW(1)
	STS  _rx_counter,R26
	CPI  R26,LOW(0x8)
	BRNE _0x2A
; 0000 0065       {
; 0000 0066       rx_counter=0;
	LDI  R30,LOW(0)
	STS  _rx_counter,R30
; 0000 0067 #endif
; 0000 0068       rx_buffer_overflow=1;
	SET
	BLD  R2,0
; 0000 0069       }
; 0000 006A    }
_0x2A:
; 0000 006B }
_0x28:
	LD   R16,Y+
	LD   R17,Y+
	LD   R30,Y+
	OUT  SREG,R30
	LD   R31,Y+
	LD   R30,Y+
	LD   R26,Y+
	RETI
; .FEND
;
;#ifndef _DEBUG_TERMINAL_IO_
;// Get a character from the USART Receiver buffer
;#define _ALTERNATE_GETCHAR_
;#pragma used+
;char getchar(void)
; 0000 0072 {
_getchar:
; .FSTART _getchar
; 0000 0073 char data;
; 0000 0074 while (rx_counter==0);
	ST   -Y,R17
;	data -> R17
_0x2B:
	LDS  R30,_rx_counter
	CPI  R30,0
	BREQ _0x2B
; 0000 0075 data=rx_buffer[rx_rd_index++];
	LDS  R30,_rx_rd_index
	SUBI R30,-LOW(1)
	STS  _rx_rd_index,R30
	RCALL SUBOPT_0x0
	LD   R17,Z
; 0000 0076 #if RX_BUFFER_SIZE != 256
; 0000 0077 if (rx_rd_index == RX_BUFFER_SIZE) rx_rd_index=0;
	LDS  R26,_rx_rd_index
	CPI  R26,LOW(0x8)
	BRNE _0x2E
	LDI  R30,LOW(0)
	STS  _rx_rd_index,R30
; 0000 0078 #endif
; 0000 0079 #asm("cli")
_0x2E:
	cli
; 0000 007A --rx_counter;
	LDS  R30,_rx_counter
	SUBI R30,LOW(1)
	STS  _rx_counter,R30
; 0000 007B #asm("sei")
	sei
; 0000 007C return data;
	MOV  R30,R17
	LD   R17,Y+
	RET
; 0000 007D }
; .FEND
;#pragma used-
;#endif
;
;// Standard Input/Output functions
;#include <stdio.h>
;
;// Timer1 overflow interrupt service routine
;interrupt [TIM1_OVF] void timer1_ovf_isr(void)
; 0000 0086 {
_timer1_ovf_isr:
; .FSTART _timer1_ovf_isr
	ST   -Y,R26
	ST   -Y,R27
	ST   -Y,R30
	ST   -Y,R31
	IN   R30,SREG
	ST   -Y,R30
; 0000 0087 // Place your code here
; 0000 0088     TCS3200_COUNTER++;
	LDI  R26,LOW(_TCS3200_COUNTER)
	LDI  R27,HIGH(_TCS3200_COUNTER)
	RCALL SUBOPT_0x1
; 0000 0089 
; 0000 008A }
	LD   R30,Y+
	OUT  SREG,R30
	LD   R31,Y+
	LD   R30,Y+
	LD   R27,Y+
	LD   R26,Y+
	RETI
; .FEND
;
;#define ADC_VREF_TYPE 0x60
;
;// Read the 8 most significant bits
;// of the AD conversion result
;unsigned char read_adc(unsigned char adc_input)
; 0000 0091 {
_read_adc:
; .FSTART _read_adc
; 0000 0092 ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
	ST   -Y,R26
;	adc_input -> Y+0
	LD   R30,Y
	ORI  R30,LOW(0x60)
	OUT  0x7,R30
; 0000 0093 // Delay needed for the stabilization of the ADC input voltage
; 0000 0094 delay_us(10);
	__DELAY_USB 53
; 0000 0095 // Start the AD conversion
; 0000 0096 ADCSRA|=0x40;
	SBI  0x6,6
; 0000 0097 // Wait for the AD conversion to complete
; 0000 0098 while ((ADCSRA & 0x10)==0);
_0x2F:
	SBIS 0x6,4
	RJMP _0x2F
; 0000 0099 ADCSRA|=0x10;
	SBI  0x6,4
; 0000 009A return ADCH;
	IN   R30,0x5
	RJMP _0x20A0004
; 0000 009B }
; .FEND
;
;// Declare your global variables here
;
;void main(void)
; 0000 00A0 {
_main:
; .FSTART _main
; 0000 00A1 
; 0000 00A2     YUME_Initialization();
	RCALL _YUME_Initialization
; 0000 00A3     TCS3200_Config(3);
	LDI  R26,LOW(3)
	LDI  R27,0
	RCALL _TCS3200_Config
; 0000 00A4 
; 0000 00A5     while (1)
_0x32:
; 0000 00A6     {
; 0000 00A7 //        TRIGGER= getchar();
; 0000 00A8 //        printf("\r\r");
; 0000 00A9 //        if(TRIGGER=='X')
; 0000 00AA //        {
; 0000 00AB ////            Tracer_Sampling(FRONT);
; 0000 00AC ////            Tracer_Sampling(MIDDLE);
; 0000 00AD ////            Tracer_Sampling(REAR);
; 0000 00AE //
; 0000 00AF //            Tracer_GetRule();
; 0000 00B0 //
; 0000 00B1 //            //TCS3200_Sampling();
; 0000 00B2 ////            TCS3200_GetRule();
; 0000 00B3 //            TRIGGER=0;
; 0000 00B4 //        }
; 0000 00B5 
; 0000 00B6         Get_CMD();
	RCALL _Get_CMD
; 0000 00B7 
; 0000 00B8     }
	RJMP _0x32
; 0000 00B9 }
_0x35:
	RJMP _0x35
; .FEND
;
;
;void YUME_Initialization(void)
; 0000 00BD {
_YUME_Initialization:
; .FSTART _YUME_Initialization
; 0000 00BE     // Declare your local variables here
; 0000 00BF 
; 0000 00C0     // Input/Output Ports initialization
; 0000 00C1     // Port B initialization
; 0000 00C2     // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=Out Func1=Out Func0=Out
; 0000 00C3     // State7=T State6=T State5=T State4=T State3=T State2=0 State1=0 State0=0
; 0000 00C4     PORTB=0x00;
	LDI  R30,LOW(0)
	OUT  0x18,R30
; 0000 00C5     DDRB=0x07;
	LDI  R30,LOW(7)
	OUT  0x17,R30
; 0000 00C6 
; 0000 00C7     // Port C initialization
; 0000 00C8     // Func6=In Func5=Out Func4=Out Func3=Out Func2=In Func1=In Func0=In
; 0000 00C9     // State6=T State5=0 State4=0 State3=0 State2=T State1=T State0=T
; 0000 00CA     PORTC=0x00;
	LDI  R30,LOW(0)
	OUT  0x15,R30
; 0000 00CB     DDRC=0x38;
	LDI  R30,LOW(56)
	OUT  0x14,R30
; 0000 00CC 
; 0000 00CD     // Port D initialization
; 0000 00CE     // Func7=In Func6=In Func5=In Func4=Out Func3=Out Func2=In Func1=In Func0=In
; 0000 00CF     // State7=T State6=T State5=T State4=0 State3=0 State2=T State1=T State0=T
; 0000 00D0     PORTD=0x00;
	LDI  R30,LOW(0)
	OUT  0x12,R30
; 0000 00D1     DDRD=0x18;
	LDI  R30,LOW(24)
	OUT  0x11,R30
; 0000 00D2 
; 0000 00D3     // Timer/Counter 0 initialization
; 0000 00D4     // Clock source: System Clock
; 0000 00D5     // Clock value: Timer 0 Stopped
; 0000 00D6     TCCR0=0x00;
	LDI  R30,LOW(0)
	OUT  0x33,R30
; 0000 00D7     TCNT0=0x00;
	OUT  0x32,R30
; 0000 00D8 
; 0000 00D9     // Timer/Counter 1 initialization
; 0000 00DA     // Clock source: System Clock
; 0000 00DB     // Clock value: Timer1 Stopped
; 0000 00DC     // Mode: Normal top=0xFFFF
; 0000 00DD     // OC1A output: Discon.
; 0000 00DE     // OC1B output: Discon.
; 0000 00DF     // Noise Canceler: Off
; 0000 00E0     // Input Capture on Falling Edge
; 0000 00E1     // Timer1 Overflow Interrupt: On
; 0000 00E2     // Input Capture Interrupt: Off
; 0000 00E3     // Compare A Match Interrupt: Off
; 0000 00E4     // Compare B Match Interrupt: Off
; 0000 00E5     TCCR1A=0x00;
	OUT  0x2F,R30
; 0000 00E6     TCCR1B=0x00;
	RCALL SUBOPT_0x2
; 0000 00E7     TCNT1H=0x00;
	LDI  R30,LOW(0)
	OUT  0x2D,R30
; 0000 00E8     TCNT1L=0x00;
	OUT  0x2C,R30
; 0000 00E9     ICR1H=0x00;
	OUT  0x27,R30
; 0000 00EA     ICR1L=0x00;
	OUT  0x26,R30
; 0000 00EB     OCR1AH=0x00;
	OUT  0x2B,R30
; 0000 00EC     OCR1AL=0x00;
	OUT  0x2A,R30
; 0000 00ED     OCR1BH=0x00;
	OUT  0x29,R30
; 0000 00EE     OCR1BL=0x00;
	OUT  0x28,R30
; 0000 00EF 
; 0000 00F0     // Timer/Counter 2 initialization
; 0000 00F1     // Clock source: System Clock
; 0000 00F2     // Clock value: Timer2 Stopped
; 0000 00F3     // Mode: Normal top=0xFF
; 0000 00F4     // OC2 output: Disconnected
; 0000 00F5     ASSR=0x00;
	OUT  0x22,R30
; 0000 00F6     TCCR2=0x00;
	OUT  0x25,R30
; 0000 00F7     TCNT2=0x00;
	OUT  0x24,R30
; 0000 00F8     OCR2=0x00;
	OUT  0x23,R30
; 0000 00F9 
; 0000 00FA     // External Interrupt(s) initialization
; 0000 00FB     // INT0: Off
; 0000 00FC     // INT1: Off
; 0000 00FD     MCUCR=0x00;
	OUT  0x35,R30
; 0000 00FE 
; 0000 00FF     // Timer(s)/Counter(s) Interrupt(s) initialization
; 0000 0100     TIMSK=0x04;
	LDI  R30,LOW(4)
	OUT  0x39,R30
; 0000 0101 
; 0000 0102     // USART initialization
; 0000 0103     // Communication Parameters: 8 Data, 1 Stop, No Parity
; 0000 0104     // USART Receiver: On
; 0000 0105     // USART Transmitter: On
; 0000 0106     // USART Mode: Asynchronous
; 0000 0107     // USART Baud Rate: 9600
; 0000 0108     UCSRA=0x00;
	LDI  R30,LOW(0)
	OUT  0xB,R30
; 0000 0109     UCSRB=0x98;
	LDI  R30,LOW(152)
	OUT  0xA,R30
; 0000 010A     UCSRC=0x86;
	LDI  R30,LOW(134)
	OUT  0x20,R30
; 0000 010B     UBRRH=0x00;
	LDI  R30,LOW(0)
	OUT  0x20,R30
; 0000 010C     UBRRL=0x67;
	LDI  R30,LOW(103)
	OUT  0x9,R30
; 0000 010D 
; 0000 010E     // Analog Comparator initialization
; 0000 010F     // Analog Comparator: Off
; 0000 0110     // Analog Comparator Input Capture by Timer/Counter 1: Off
; 0000 0111     ACSR=0x80;
	LDI  R30,LOW(128)
	OUT  0x8,R30
; 0000 0112     SFIOR=0x00;
	LDI  R30,LOW(0)
	OUT  0x30,R30
; 0000 0113 
; 0000 0114     // ADC initialization
; 0000 0115     // ADC Clock frequency: 500.000 kHz
; 0000 0116     // ADC Voltage Reference: AVCC pin
; 0000 0117     // Only the 8 most significant bits of
; 0000 0118     // the AD conversion result are used
; 0000 0119     ADMUX=ADC_VREF_TYPE & 0xff;
	LDI  R30,LOW(96)
	OUT  0x7,R30
; 0000 011A     ADCSRA=0x85;
	LDI  R30,LOW(133)
	OUT  0x6,R30
; 0000 011B 
; 0000 011C     // SPI initialization
; 0000 011D     // SPI disabled
; 0000 011E     SPCR=0x00;
	LDI  R30,LOW(0)
	OUT  0xD,R30
; 0000 011F 
; 0000 0120     // TWI initialization
; 0000 0121     // TWI disabled
; 0000 0122     TWCR=0x00;
	OUT  0x36,R30
; 0000 0123 
; 0000 0124     // Global enable interrupts
; 0000 0125     #asm("sei")
	sei
; 0000 0126 
; 0000 0127 }
	RET
; .FEND
;
;void Send_UART(unsigned char data)
; 0000 012A {
_Send_UART:
; .FSTART _Send_UART
; 0000 012B     while(!(UCSRA & (1<<UDRE))){};
	ST   -Y,R26
;	data -> Y+0
_0x36:
	SBIS 0xB,5
	RJMP _0x36
; 0000 012C     UDR=data;
	LD   R30,Y
	OUT  0xC,R30
; 0000 012D }
_0x20A0004:
	ADIW R28,1
	RET
; .FEND
;
;
;void TCS3200_Config(unsigned int mode)
; 0000 0131 {
_TCS3200_Config:
; .FSTART _TCS3200_Config
; 0000 0132     if(mode==0)         //output frequency scaling power down
	ST   -Y,R27
	ST   -Y,R26
;	mode -> Y+0
	LD   R30,Y
	LDD  R31,Y+1
	SBIW R30,0
	BRNE _0x39
; 0000 0133     {
; 0000 0134         TCS3200_S0=0;
	CBI  0x18,0
; 0000 0135         TCS3200_S1=0;
	CBI  0x18,1
; 0000 0136     }
; 0000 0137     if(mode==1)         //output frequency scaling 1:50
_0x39:
	LD   R26,Y
	LDD  R27,Y+1
	SBIW R26,1
	BRNE _0x3E
; 0000 0138     {
; 0000 0139         TCS3200_S0=0;
	CBI  0x18,0
; 0000 013A         TCS3200_S1=1;
	SBI  0x18,1
; 0000 013B     }
; 0000 013C     if(mode==2)         //output frequency scaling 1:5
_0x3E:
	LD   R26,Y
	LDD  R27,Y+1
	SBIW R26,2
	BRNE _0x43
; 0000 013D     {
; 0000 013E         TCS3200_S0=1;
	SBI  0x18,0
; 0000 013F         TCS3200_S1=0;
	CBI  0x18,1
; 0000 0140     }
; 0000 0141     if(mode==3)         //output frequency scaling 1:1
_0x43:
	LD   R26,Y
	LDD  R27,Y+1
	SBIW R26,3
	BRNE _0x48
; 0000 0142     {
; 0000 0143         TCS3200_S0=1;
	SBI  0x18,0
; 0000 0144         TCS3200_S1=1;
	SBI  0x18,1
; 0000 0145     }
; 0000 0146     return;
_0x48:
	ADIW R28,2
	RET
; 0000 0147 }
; .FEND
;
;
;void TCS3200Read(void)
; 0000 014B {
_TCS3200Read:
; .FSTART _TCS3200Read
; 0000 014C     TCS3200Read_R();
	RCALL SUBOPT_0x3
; 0000 014D     TCS3200Read_G();
; 0000 014E     TCS3200Read_B();
; 0000 014F     TCS3200Read_W();
; 0000 0150 
; 0000 0151 //    printf("Red  : %d \t",(int)TCS3200_Pulse_R);
; 0000 0152 //    printf("Green: %d \t",(int)TCS3200_Pulse_G);
; 0000 0153 //    printf("Blue: %d \t",(int)TCS3200_Pulse_B);
; 0000 0154 //    printf("White: %d \r",(int)TCS3200_Pulse_W);
; 0000 0155 }
	RET
; .FEND
;
;int TCS3200Read_R(void)
; 0000 0158 {
_TCS3200Read_R:
; .FSTART _TCS3200Read_R
; 0000 0159      TCS3200_S2=0;
	CBI  0x18,2
; 0000 015A      TCS3200_S3=0;
	RCALL SUBOPT_0x4
; 0000 015B      delay_ms(5);
; 0000 015C      TCCR1B=0x06;
; 0000 015D      delay_ms(5);
; 0000 015E      TCCR1B=0x00;
; 0000 015F      TCS3200_Pulse_R=((int)TCS3200_COUNTER*256)+(int)TCNT1;
	RCALL SUBOPT_0x5
	STS  _TCS3200_Pulse_R,R30
	STS  _TCS3200_Pulse_R+1,R31
; 0000 0160      TCNT1=0;
	RCALL SUBOPT_0x6
; 0000 0161      TCS3200_COUNTER=0;
; 0000 0162      delay_ms(10);
; 0000 0163      return TCS3200_Pulse_R;
	LDS  R30,_TCS3200_Pulse_R
	LDS  R31,_TCS3200_Pulse_R+1
	RET
; 0000 0164 
; 0000 0165 }
; .FEND
;
;int TCS3200Read_G(void)
; 0000 0168 {
_TCS3200Read_G:
; .FSTART _TCS3200Read_G
; 0000 0169      TCS3200_S2=1;
	SBI  0x18,2
; 0000 016A      TCS3200_S3=1;
	RCALL SUBOPT_0x7
; 0000 016B      delay_ms(5);
; 0000 016C      TCCR1B=0x06;
; 0000 016D      delay_ms(5);
; 0000 016E      TCCR1B=0x00;
; 0000 016F      TCS3200_Pulse_G=((int)TCS3200_COUNTER*256)+(int)TCNT1;
	RCALL SUBOPT_0x5
	STS  _TCS3200_Pulse_G,R30
	STS  _TCS3200_Pulse_G+1,R31
; 0000 0170 //    TCS3200_Pulse_G=((int)MIDDLE_COUNTER*65536)+(int)TCNT1;
; 0000 0171      TCNT1=0;
	RCALL SUBOPT_0x6
; 0000 0172      TCS3200_COUNTER=0;
; 0000 0173      delay_ms(10);
; 0000 0174      return TCS3200_Pulse_G;
	RCALL SUBOPT_0x8
	RET
; 0000 0175 
; 0000 0176 }
; .FEND
;
;int TCS3200Read_B(void)
; 0000 0179 {
_TCS3200Read_B:
; .FSTART _TCS3200Read_B
; 0000 017A      TCS3200_S2=0;
	CBI  0x18,2
; 0000 017B      TCS3200_S3=1;
	RCALL SUBOPT_0x7
; 0000 017C      delay_ms(5);
; 0000 017D      TCCR1B=0x06;
; 0000 017E      delay_ms(5);
; 0000 017F      TCCR1B=0x00;
; 0000 0180      TCS3200_Pulse_B=((int)TCS3200_COUNTER*256)+(int)TCNT1;
	RCALL SUBOPT_0x5
	STS  _TCS3200_Pulse_B,R30
	STS  _TCS3200_Pulse_B+1,R31
; 0000 0181 //     TCS3200_Pulse_B=((int)TCS3200_COUNTER*65536)+(int)TCNT1;
; 0000 0182      TCNT1=0;
	RCALL SUBOPT_0x6
; 0000 0183      TCS3200_COUNTER=0;
; 0000 0184      delay_ms(10);
; 0000 0185      return TCS3200_Pulse_B;
	RCALL SUBOPT_0x9
	RET
; 0000 0186 
; 0000 0187 }
; .FEND
;
;int TCS3200Read_W(void)
; 0000 018A {
_TCS3200Read_W:
; .FSTART _TCS3200Read_W
; 0000 018B      TCS3200_S2=1;
	SBI  0x18,2
; 0000 018C      TCS3200_S3=0;
	RCALL SUBOPT_0x4
; 0000 018D      delay_ms(5);
; 0000 018E      TCCR1B=0x06;
; 0000 018F      delay_ms(5);
; 0000 0190      TCCR1B=0x00;
; 0000 0191      TCS3200_Pulse_W=((int)TCS3200_COUNTER*256)+(int)TCNT1;
	RCALL SUBOPT_0x5
	STS  _TCS3200_Pulse_W,R30
	STS  _TCS3200_Pulse_W+1,R31
; 0000 0192 //    TCS3200_Pulse_W=((int)TCS3200_COUNTER*65536)+(int)TCNT1;
; 0000 0193      TCNT1=0;
	RCALL SUBOPT_0x6
; 0000 0194      TCS3200_COUNTER=0;
; 0000 0195      delay_ms(10);
; 0000 0196      return TCS3200_Pulse_W;
	RCALL SUBOPT_0xA
	RET
; 0000 0197 
; 0000 0198 }
; .FEND
;
;
;
;/*
; * DATA PACKET STRUCTURE
; * [COMMAND_FLAG_A] [COMMAND_FLAG_B] [F_DETECTED_COLOUR] [M_DETECTED_COLOUR] [TRACER_STAT] [COLOUR_STAT]
; *
;*/
;void Send_TCS3200_Conclusion(void)
; 0000 01A2 {
; 0000 01A3     Send_UART(COMMAND_FLAG_A);
; 0000 01A4     Send_UART(COMMAND_FLAG_B);
; 0000 01A5     Send_UART(DETECTED_COLOUR);
; 0000 01A6     Send_UART(TRACER_STAT);
; 0000 01A7 }
;
;void Get_CMD(void)
; 0000 01AA {
_Get_CMD:
; .FSTART _Get_CMD
; 0000 01AB     TCS3200_CMD[TEMPORARY] = getchar();;
	RCALL _getchar
	__POINTW2MN _TCS3200_CMD,4
	RCALL SUBOPT_0xB
; 0000 01AC 
; 0000 01AD     if(TCS3200_CMD[TEMPORARY]!=CMD_IDLE)
	__GETW2MN _TCS3200_CMD,4
	LDS  R30,_CMD_IDLE
	LDS  R31,_CMD_IDLE+1
	CP   R30,R26
	CPC  R31,R27
	BREQ _0x5D
; 0000 01AE     {
; 0000 01AF         TCS3200_CMD[1] = TCS3200_CMD[0];
	RCALL SUBOPT_0xC
	__PUTW1MN _TCS3200_CMD,2
; 0000 01B0         TCS3200_CMD[0] = TCS3200_CMD[TEMPORARY];
	__GETW1MN _TCS3200_CMD,4
	STS  _TCS3200_CMD,R30
	STS  _TCS3200_CMD+1,R31
; 0000 01B1     }
; 0000 01B2 
; 0000 01B3     //Switch-case version
; 0000 01B4     switch(TCS3200_CMD[0])
_0x5D:
	RCALL SUBOPT_0xC
; 0000 01B5     {
; 0000 01B6         case TCS3200_CMD_SEND_RAW:{
	CPI  R30,LOW(0x41)
	LDI  R26,HIGH(0x41)
	CPC  R31,R26
	BREQ PC+2
	RJMP _0x61
; 0000 01B7                                     TCS3200_Sampling();
	RCALL _TCS3200_Sampling
; 0000 01B8                                     Send_UART(COMMAND_FLAG_A);
	RCALL SUBOPT_0xD
; 0000 01B9                                     Send_UART(COMMAND_FLAG_B);
; 0000 01BA                                     Send_UART(RAW_VAL_FLAG);
; 0000 01BB 
; 0000 01BC                                     //RED FILTER RAW VALUE
; 0000 01BD                                     MULTIPLY_COUNTER=0;
	RCALL SUBOPT_0xE
; 0000 01BE                                     if(MOV_AVG[TCS3200_RED]>255)
	RCALL SUBOPT_0xF
	BRLT _0x62
; 0000 01BF                                     {
; 0000 01C0                                         while( MOV_AVG[TCS3200_RED] >255)
_0x63:
	RCALL SUBOPT_0xF
	BRLT _0x65
; 0000 01C1                                         {
; 0000 01C2                                            MOV_AVG[TCS3200_RED]-=255;
	RCALL SUBOPT_0x10
	RCALL SUBOPT_0x11
	RCALL SUBOPT_0x12
; 0000 01C3                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x13
; 0000 01C4                                         }
	RJMP _0x63
_0x65:
; 0000 01C5                                     }
; 0000 01C6                                     Send_UART(MULTIPLY_COUNTER);
_0x62:
	RCALL SUBOPT_0x14
; 0000 01C7                                     Send_UART(MOV_AVG[TCS3200_RED]);
	__GETB2MN _MOV_AVG,10
	RCALL SUBOPT_0x15
; 0000 01C8 
; 0000 01C9                                     //GREEN FILTER RAW VALUE
; 0000 01CA                                     MULTIPLY_COUNTER=0;
; 0000 01CB                                     if(MOV_AVG[TCS3200_GREEN]>255)
	RCALL SUBOPT_0x16
	BRLT _0x66
; 0000 01CC                                     {
; 0000 01CD                                         while( MOV_AVG[TCS3200_GREEN] >255)
_0x67:
	RCALL SUBOPT_0x16
	BRLT _0x69
; 0000 01CE                                         {
; 0000 01CF                                            MOV_AVG[TCS3200_GREEN]-=255;
	RCALL SUBOPT_0x17
	RCALL SUBOPT_0x11
	RCALL SUBOPT_0x18
; 0000 01D0                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x13
; 0000 01D1                                         }
	RJMP _0x67
_0x69:
; 0000 01D2                                     }
; 0000 01D3                                     Send_UART(MULTIPLY_COUNTER);
_0x66:
	RCALL SUBOPT_0x14
; 0000 01D4                                     Send_UART(MOV_AVG[TCS3200_GREEN]);
	__GETB2MN _MOV_AVG,12
	RCALL SUBOPT_0x15
; 0000 01D5 
; 0000 01D6                                     //BLUE FILTER RAW VALUE
; 0000 01D7                                     MULTIPLY_COUNTER=0;
; 0000 01D8                                     if(MOV_AVG[TCS3200_BLUE]>255)
	RCALL SUBOPT_0x19
	BRLT _0x6A
; 0000 01D9                                     {
; 0000 01DA                                         while( MOV_AVG[TCS3200_BLUE] >255)
_0x6B:
	RCALL SUBOPT_0x19
	BRLT _0x6D
; 0000 01DB                                         {
; 0000 01DC                                            MOV_AVG[TCS3200_BLUE]-=255;
	RCALL SUBOPT_0x1A
	RCALL SUBOPT_0x11
	RCALL SUBOPT_0x1B
; 0000 01DD                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x13
; 0000 01DE                                         }
	RJMP _0x6B
_0x6D:
; 0000 01DF                                     }
; 0000 01E0                                     Send_UART(MULTIPLY_COUNTER);
_0x6A:
	RCALL SUBOPT_0x14
; 0000 01E1                                     Send_UART(MOV_AVG[TCS3200_BLUE]);
	__GETB2MN _MOV_AVG,14
	RCALL SUBOPT_0x15
; 0000 01E2 
; 0000 01E3                                     //WHITE FILTER RAW VALUE
; 0000 01E4                                     MULTIPLY_COUNTER=0;
; 0000 01E5                                     if(MOV_AVG[TCS3200_WHITE]>255)
	RCALL SUBOPT_0x1C
	BRLT _0x6E
; 0000 01E6                                     {
; 0000 01E7                                         while( MOV_AVG[TCS3200_WHITE] >255)
_0x6F:
	RCALL SUBOPT_0x1C
	BRLT _0x71
; 0000 01E8                                         {
; 0000 01E9                                            MOV_AVG[TCS3200_WHITE]-=255;
	RCALL SUBOPT_0x1D
	RCALL SUBOPT_0x11
	RCALL SUBOPT_0x1E
; 0000 01EA                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x13
; 0000 01EB                                         }
	RJMP _0x6F
_0x71:
; 0000 01EC                                     }
; 0000 01ED                                     Send_UART(MULTIPLY_COUNTER);
_0x6E:
	RCALL SUBOPT_0x14
; 0000 01EE                                     Send_UART(MOV_AVG[TCS3200_WHITE]);
	__GETB2MN _MOV_AVG,16
	RCALL SUBOPT_0x15
; 0000 01EF 
; 0000 01F0                                     //SUM FILTER RAW VALUE
; 0000 01F1                                     MULTIPLY_COUNTER=0;
; 0000 01F2                                     if(TCS3200_TOTAL_SUM>255)
	RCALL SUBOPT_0x1F
	BRLT _0x72
; 0000 01F3                                     {
; 0000 01F4                                         while( TCS3200_TOTAL_SUM >255)
_0x73:
	RCALL SUBOPT_0x1F
	BRLT _0x75
; 0000 01F5                                         {
; 0000 01F6                                            TCS3200_TOTAL_SUM-=255;
	LDS  R30,_TCS3200_TOTAL_SUM
	LDS  R31,_TCS3200_TOTAL_SUM+1
	RCALL SUBOPT_0x11
	RCALL SUBOPT_0x20
; 0000 01F7                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x13
; 0000 01F8                                         }
	RJMP _0x73
_0x75:
; 0000 01F9                                     }
; 0000 01FA                                     Send_UART(MULTIPLY_COUNTER);
_0x72:
	RCALL SUBOPT_0x14
; 0000 01FB                                     Send_UART(TCS3200_TOTAL_SUM);
	LDS  R26,_TCS3200_TOTAL_SUM
	RCALL _Send_UART
; 0000 01FC 
; 0000 01FD                                 }break;
	RJMP _0x60
; 0000 01FE 
; 0000 01FF 
; 0000 0200         case TRACER_CMD_SEND_RAW:{
_0x61:
	CPI  R30,LOW(0x42)
	LDI  R26,HIGH(0x42)
	CPC  R31,R26
	BRNE _0x76
; 0000 0201                                         Tracer_GetRule();
	RCALL _Tracer_GetRule
; 0000 0202                                         Send_UART(COMMAND_FLAG_A);
	RCALL SUBOPT_0xD
; 0000 0203                                         Send_UART(COMMAND_FLAG_B);
; 0000 0204                                         Send_UART(RAW_VAL_FLAG);
; 0000 0205                                         Send_UART(TRACER[FRONT]);
	LDS  R26,_TRACER
	RCALL _Send_UART
; 0000 0206                                         Send_UART(TRACER[MIDDLE]);
	__GETB2MN _TRACER,2
	RCALL _Send_UART
; 0000 0207                                         Send_UART(TRACER[REAR]);
	__GETB2MN _TRACER,4
	RCALL SUBOPT_0x21
; 0000 0208                                         Send_UART(TRACER_STAT);
; 0000 0209                                         Send_UART(TRACER_THRESHOLD);
	LDS  R26,_TRACER_THRESHOLD
	RCALL _Send_UART
; 0000 020A 
; 0000 020B                                 }break;
	RJMP _0x60
; 0000 020C 
; 0000 020D         case HYBRID_CMD_SEND_CONCLUSION:
_0x76:
	CPI  R30,LOW(0x43)
	LDI  R26,HIGH(0x43)
	CPC  R31,R26
	BRNE _0x77
; 0000 020E                                     {
; 0000 020F                                         Tracer_GetRule();
	RCALL _Tracer_GetRule
; 0000 0210                                         TCS3200_GetRule();
	RCALL SUBOPT_0x22
; 0000 0211                                         Send_UART(COMMAND_FLAG_A);
; 0000 0212                                         Send_UART(COMMAND_FLAG_B);
; 0000 0213                                         Send_UART(DETECTED_COLOUR);
	RCALL SUBOPT_0x21
; 0000 0214                                         Send_UART(TRACER_STAT);
; 0000 0215 //                                        Send_UART(TRACER[FRONT]);
; 0000 0216 //                                        Send_UART(TRACER[MIDDLE]);
; 0000 0217 //                                        Send_UART(TRACER[REAR]);
; 0000 0218 
; 0000 0219                                     }break;
	RJMP _0x60
; 0000 021A         case CMD_GET_TCS3200            :
_0x77:
	CPI  R30,LOW(0x52)
	LDI  R26,HIGH(0x52)
	CPC  R31,R26
	BRNE _0x78
; 0000 021B                                     {
; 0000 021C                                         TCS3200_GetRule();
	RCALL SUBOPT_0x22
; 0000 021D                                         Send_UART(COMMAND_FLAG_A);
; 0000 021E                                         Send_UART(COMMAND_FLAG_B);
; 0000 021F                                         Send_UART(DETECTED_COLOUR);
	RCALL _Send_UART
; 0000 0220                                         Send_UART(0x00);
	LDI  R26,LOW(0)
	RCALL _Send_UART
; 0000 0221                                     }break;
	RJMP _0x60
; 0000 0222         case CMD_GET_TRACER            :
_0x78:
	CPI  R30,LOW(0x53)
	LDI  R26,HIGH(0x53)
	CPC  R31,R26
	BRNE _0x79
; 0000 0223                                     {
; 0000 0224                                         Tracer_GetRule();
	RCALL _Tracer_GetRule
; 0000 0225                                         Send_UART(COMMAND_FLAG_A);
	LDS  R26,_COMMAND_FLAG_A
	RCALL _Send_UART
; 0000 0226                                         Send_UART(COMMAND_FLAG_B);
	LDS  R26,_COMMAND_FLAG_B
	RCALL _Send_UART
; 0000 0227                                         Send_UART(0x00);
	LDI  R26,LOW(0)
	RCALL SUBOPT_0x21
; 0000 0228                                         Send_UART(TRACER_STAT);
; 0000 0229                                     }break;
	RJMP _0x60
; 0000 022A 
; 0000 022B         case TCS3200_CMD_SAVE_EEPROM:
_0x79:
	CPI  R30,LOW(0x5A)
	LDI  R26,HIGH(0x5A)
	CPC  R31,R26
	BRNE _0x7A
; 0000 022C                                     {
; 0000 022D                                         TCS3200Read();
	RCALL _TCS3200Read
; 0000 022E                                         EEPROM_A= TCS3200_Pulse_G;
	RCALL SUBOPT_0x8
	LDI  R26,LOW(_EEPROM_A)
	LDI  R27,HIGH(_EEPROM_A)
	RCALL __EEPROMWRW
; 0000 022F                                         EEPROM_B= TCS3200_Pulse_B;
	RCALL SUBOPT_0x9
	LDI  R26,LOW(_EEPROM_B)
	LDI  R27,HIGH(_EEPROM_B)
	RCALL __EEPROMWRW
; 0000 0230                                         EEPROM_C= TCS3200_Pulse_W;
	RCALL SUBOPT_0xA
	LDI  R26,LOW(_EEPROM_C)
	LDI  R27,HIGH(_EEPROM_C)
	RCALL __EEPROMWRW
; 0000 0231                                         EEPROM_D= TCS3200_Pulse_Sum;
	LDS  R30,_TCS3200_Pulse_Sum
	LDS  R31,_TCS3200_Pulse_Sum+1
	LDI  R26,LOW(_EEPROM_D)
	LDI  R27,HIGH(_EEPROM_D)
	RCALL __EEPROMWRW
; 0000 0232                                     }break;
	RJMP _0x60
; 0000 0233 
; 0000 0234         case HYBRID_CMD_SEND_THRESHOLD:
_0x7A:
	CPI  R30,LOW(0x58)
	LDI  R26,HIGH(0x58)
	CPC  R31,R26
	BRNE _0x7B
; 0000 0235                                     {
; 0000 0236                                         Send_Threshold();
	RCALL _Send_Threshold
; 0000 0237                                     }break;
	RJMP _0x60
; 0000 0238 
; 0000 0239         case TCS3200_CALIBRATE_WHITE:
_0x7B:
	CPI  R30,LOW(0x46)
	LDI  R26,HIGH(0x46)
	CPC  R31,R26
	BRNE _0x7C
; 0000 023A                                     {
; 0000 023B                                         TCS3200_Sampling();
	RCALL _TCS3200_Sampling
; 0000 023C                                         Threshold_White= TCS3200_TOTAL_SUM;
	__GETWRMN 6,7,0,_TCS3200_TOTAL_SUM
; 0000 023D                                     }break;
	RJMP _0x60
; 0000 023E         case TCS3200_CALIBRATE_BLACK:
_0x7C:
	CPI  R30,LOW(0x47)
	LDI  R26,HIGH(0x47)
	CPC  R31,R26
	BRNE _0x7D
; 0000 023F                                     {
; 0000 0240 
; 0000 0241                                         TCS3200_Sampling();
	RCALL _TCS3200_Sampling
; 0000 0242                                         Threshold_Black = TCS3200_TOTAL_SUM;
	__GETWRMN 8,9,0,_TCS3200_TOTAL_SUM
; 0000 0243                                     }break;
	RJMP _0x60
; 0000 0244         case TCS3200_CALIBRATE_GRAY:
_0x7D:
	CPI  R30,LOW(0x48)
	LDI  R26,HIGH(0x48)
	CPC  R31,R26
	BRNE _0x7E
; 0000 0245                                     {
; 0000 0246 
; 0000 0247                                         TCS3200_Sampling();
	RCALL _TCS3200_Sampling
; 0000 0248                                         Threshold_Gray = TCS3200_TOTAL_SUM;
	__GETWRMN 10,11,0,_TCS3200_TOTAL_SUM
; 0000 0249                                     }break;
	RJMP _0x60
; 0000 024A         case TCS3200_CALIBRATE_GETRULE:
_0x7E:
	CPI  R30,LOW(0x49)
	LDI  R26,HIGH(0x49)
	CPC  R31,R26
	BREQ PC+2
	RJMP _0x7F
; 0000 024B                                     {
; 0000 024C                                         Threshold_Diff = Threshold_White-Threshold_Gray;
	MOVW R30,R6
	SUB  R30,R10
	SBC  R31,R11
	RCALL SUBOPT_0x23
; 0000 024D 
; 0000 024E                                         if(Threshold_Diff>1400)
	CPI  R26,LOW(0x579)
	LDI  R30,HIGH(0x579)
	CPC  R27,R30
	BRLT _0x80
; 0000 024F                                         {
; 0000 0250                                             Threshold_BW = Threshold_Gray + 1390;
	MOVW R30,R10
	SUBI R30,LOW(-1390)
	SBCI R31,HIGH(-1390)
	RJMP _0x11C
; 0000 0251                                         }
; 0000 0252                                         else if(Threshold_Diff>1350)
_0x80:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x547)
	LDI  R30,HIGH(0x547)
	CPC  R27,R30
	BRLT _0x82
; 0000 0253                                         {
; 0000 0254                                             Threshold_BW = Threshold_Gray + 1340;
	MOVW R30,R10
	SUBI R30,LOW(-1340)
	SBCI R31,HIGH(-1340)
	RJMP _0x11C
; 0000 0255                                         }
; 0000 0256 
; 0000 0257                                         else if(Threshold_Diff>1300)
_0x82:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x515)
	LDI  R30,HIGH(0x515)
	CPC  R27,R30
	BRLT _0x84
; 0000 0258                                         {
; 0000 0259                                             Threshold_BW = Threshold_Gray + 1290;
	MOVW R30,R10
	SUBI R30,LOW(-1290)
	SBCI R31,HIGH(-1290)
	RJMP _0x11C
; 0000 025A                                         }
; 0000 025B                                         else if(Threshold_Diff>1250)
_0x84:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x4E3)
	LDI  R30,HIGH(0x4E3)
	CPC  R27,R30
	BRLT _0x86
; 0000 025C                                         {
; 0000 025D                                             Threshold_BW = Threshold_Gray + 1240;
	MOVW R30,R10
	SUBI R30,LOW(-1240)
	SBCI R31,HIGH(-1240)
	RJMP _0x11C
; 0000 025E                                         }
; 0000 025F 
; 0000 0260                                         else if(Threshold_Diff>1200)
_0x86:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x4B1)
	LDI  R30,HIGH(0x4B1)
	CPC  R27,R30
	BRLT _0x88
; 0000 0261                                         {
; 0000 0262                                             Threshold_BW = Threshold_Gray + 1190;
	MOVW R30,R10
	SUBI R30,LOW(-1190)
	SBCI R31,HIGH(-1190)
	RJMP _0x11C
; 0000 0263                                         }
; 0000 0264                                         else if(Threshold_Diff>1150)
_0x88:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x47F)
	LDI  R30,HIGH(0x47F)
	CPC  R27,R30
	BRLT _0x8A
; 0000 0265                                         {
; 0000 0266                                             Threshold_BW = Threshold_Gray + 1140;
	MOVW R30,R10
	SUBI R30,LOW(-1140)
	SBCI R31,HIGH(-1140)
	RJMP _0x11C
; 0000 0267                                         }
; 0000 0268 
; 0000 0269                                         else if(Threshold_Diff>1100)
_0x8A:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x44D)
	LDI  R30,HIGH(0x44D)
	CPC  R27,R30
	BRLT _0x8C
; 0000 026A                                         {
; 0000 026B                                             Threshold_BW = Threshold_Gray + 1190;
	MOVW R30,R10
	SUBI R30,LOW(-1190)
	SBCI R31,HIGH(-1190)
	RJMP _0x11C
; 0000 026C                                         }
; 0000 026D                                         else if(Threshold_Diff>1050)
_0x8C:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x41B)
	LDI  R30,HIGH(0x41B)
	CPC  R27,R30
	BRLT _0x8E
; 0000 026E                                         {
; 0000 026F                                             Threshold_BW = Threshold_Gray + 1040;
	MOVW R30,R10
	SUBI R30,LOW(-1040)
	SBCI R31,HIGH(-1040)
	RJMP _0x11C
; 0000 0270                                         }
; 0000 0271                                         else if(Threshold_Diff>1000)
_0x8E:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x3E9)
	LDI  R30,HIGH(0x3E9)
	CPC  R27,R30
	BRLT _0x90
; 0000 0272                                         {
; 0000 0273                                             Threshold_BW = Threshold_Gray + 990;
	MOVW R30,R10
	SUBI R30,LOW(-990)
	SBCI R31,HIGH(-990)
	RJMP _0x11C
; 0000 0274                                         }
; 0000 0275 
; 0000 0276                                         else if(Threshold_Diff>950)
_0x90:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x3B7)
	LDI  R30,HIGH(0x3B7)
	CPC  R27,R30
	BRLT _0x92
; 0000 0277                                         {
; 0000 0278                                             Threshold_BW = Threshold_Gray + 940;
	MOVW R30,R10
	SUBI R30,LOW(-940)
	SBCI R31,HIGH(-940)
	RJMP _0x11C
; 0000 0279                                         }
; 0000 027A 
; 0000 027B                                         else if(Threshold_Diff>900)
_0x92:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x385)
	LDI  R30,HIGH(0x385)
	CPC  R27,R30
	BRLT _0x94
; 0000 027C                                         {
; 0000 027D                                             Threshold_BW = Threshold_Gray + 890;
	MOVW R30,R10
	SUBI R30,LOW(-890)
	SBCI R31,HIGH(-890)
	RJMP _0x11C
; 0000 027E                                         }
; 0000 027F 
; 0000 0280                                         else if(Threshold_Diff>850)
_0x94:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x353)
	LDI  R30,HIGH(0x353)
	CPC  R27,R30
	BRLT _0x96
; 0000 0281                                         {
; 0000 0282                                             Threshold_BW = Threshold_Gray + 840;
	MOVW R30,R10
	SUBI R30,LOW(-840)
	SBCI R31,HIGH(-840)
	RJMP _0x11C
; 0000 0283                                         }
; 0000 0284 
; 0000 0285                                         else if(Threshold_Diff>800)
_0x96:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x321)
	LDI  R30,HIGH(0x321)
	CPC  R27,R30
	BRLT _0x98
; 0000 0286                                         {
; 0000 0287                                             Threshold_BW = Threshold_Gray + 790;
	MOVW R30,R10
	SUBI R30,LOW(-790)
	SBCI R31,HIGH(-790)
	RJMP _0x11C
; 0000 0288                                         }
; 0000 0289                                         else if(Threshold_Diff>700)
_0x98:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x2BD)
	LDI  R30,HIGH(0x2BD)
	CPC  R27,R30
	BRLT _0x9A
; 0000 028A                                         {
; 0000 028B                                             Threshold_BW = Threshold_Gray + 690;
	MOVW R30,R10
	SUBI R30,LOW(-690)
	SBCI R31,HIGH(-690)
	RJMP _0x11C
; 0000 028C                                         }
; 0000 028D                                         else if(Threshold_Diff>600)
_0x9A:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x259)
	LDI  R30,HIGH(0x259)
	CPC  R27,R30
	BRLT _0x9C
; 0000 028E                                         {
; 0000 028F                                             Threshold_BW = Threshold_Gray + 590;
	MOVW R30,R10
	SUBI R30,LOW(-590)
	SBCI R31,HIGH(-590)
	RJMP _0x11C
; 0000 0290                                         }
; 0000 0291                                         else if(Threshold_Diff>500)
_0x9C:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x1F5)
	LDI  R30,HIGH(0x1F5)
	CPC  R27,R30
	BRLT _0x9E
; 0000 0292                                         {
; 0000 0293                                             Threshold_BW = Threshold_Gray + 490;
	MOVW R30,R10
	SUBI R30,LOW(-490)
	SBCI R31,HIGH(-490)
	RJMP _0x11C
; 0000 0294                                         }
; 0000 0295                                         else if(Threshold_Diff>450)
_0x9E:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x1C3)
	LDI  R30,HIGH(0x1C3)
	CPC  R27,R30
	BRLT _0xA0
; 0000 0296                                         {
; 0000 0297                                             Threshold_BW = Threshold_Gray + 440;
	MOVW R30,R10
	SUBI R30,LOW(-440)
	SBCI R31,HIGH(-440)
	RJMP _0x11C
; 0000 0298                                         }
; 0000 0299                                         else if(Threshold_Diff>400)
_0xA0:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x191)
	LDI  R30,HIGH(0x191)
	CPC  R27,R30
	BRLT _0xA2
; 0000 029A                                         {
; 0000 029B                                             Threshold_BW = Threshold_Gray + 390;
	MOVW R30,R10
	SUBI R30,LOW(-390)
	SBCI R31,HIGH(-390)
	RJMP _0x11C
; 0000 029C                                         }
; 0000 029D                                         else if(Threshold_Diff>350)
_0xA2:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x15F)
	LDI  R30,HIGH(0x15F)
	CPC  R27,R30
	BRLT _0xA4
; 0000 029E                                         {
; 0000 029F                                             Threshold_BW = Threshold_Gray + 340;
	MOVW R30,R10
	SUBI R30,LOW(-340)
	SBCI R31,HIGH(-340)
	RJMP _0x11C
; 0000 02A0                                         }
; 0000 02A1                                         else if(Threshold_Diff>300)
_0xA4:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x12D)
	LDI  R30,HIGH(0x12D)
	CPC  R27,R30
	BRLT _0xA6
; 0000 02A2                                         {
; 0000 02A3                                             Threshold_BW = Threshold_Gray + 290;
	MOVW R30,R10
	SUBI R30,LOW(-290)
	SBCI R31,HIGH(-290)
	RJMP _0x11C
; 0000 02A4                                         }
; 0000 02A5                                         else if(Threshold_Diff>250)
_0xA6:
	RCALL SUBOPT_0x25
	BRLT _0xA8
; 0000 02A6                                         {
; 0000 02A7                                             Threshold_BW = Threshold_Gray + 240;
	MOVW R30,R10
	SUBI R30,LOW(-240)
	SBCI R31,HIGH(-240)
	RJMP _0x11C
; 0000 02A8                                         }
; 0000 02A9                                         else if(Threshold_Diff>200)
_0xA8:
	RCALL SUBOPT_0x26
	BRLT _0xAA
; 0000 02AA                                         {
; 0000 02AB                                             Threshold_BW = Threshold_Gray + 190;
	MOVW R30,R10
	SUBI R30,LOW(-190)
	SBCI R31,HIGH(-190)
	RJMP _0x11C
; 0000 02AC                                         }
; 0000 02AD                                         else if(Threshold_Diff>150)
_0xAA:
	RCALL SUBOPT_0x27
	BRLT _0xAC
; 0000 02AE                                         {
; 0000 02AF                                             Threshold_BW = Threshold_Gray + 140;
	MOVW R30,R10
	SUBI R30,LOW(-140)
	SBCI R31,HIGH(-140)
	RJMP _0x11C
; 0000 02B0                                         }
; 0000 02B1                                         else if(Threshold_Diff>100)
_0xAC:
	RCALL SUBOPT_0x28
	BRLT _0xAE
; 0000 02B2                                         {
; 0000 02B3                                             Threshold_BW = Threshold_Gray + 90;
	MOVW R30,R10
	SUBI R30,LOW(-90)
	SBCI R31,HIGH(-90)
	RJMP _0x11C
; 0000 02B4                                         }
; 0000 02B5                                         else if(Threshold_Diff>50)
_0xAE:
	RCALL SUBOPT_0x24
	SBIW R26,51
	BRLT _0xB0
; 0000 02B6                                         {
; 0000 02B7                                             Threshold_BW = Threshold_Gray + 40;
	MOVW R30,R10
	ADIW R30,40
	RJMP _0x11C
; 0000 02B8                                         }
; 0000 02B9                                         else
_0xB0:
; 0000 02BA                                         {
; 0000 02BB                                             Threshold_BW = Threshold_Gray + 30;
	MOVW R30,R10
	ADIW R30,30
_0x11C:
	STS  _Threshold_BW,R30
	STS  _Threshold_BW+1,R31
; 0000 02BC                                         }
; 0000 02BD 
; 0000 02BE 
; 0000 02BF                                         Threshold_Diff= Threshold_Gray - Threshold_Black;
	MOVW R30,R10
	SUB  R30,R8
	SBC  R31,R9
	RCALL SUBOPT_0x23
; 0000 02C0 
; 0000 02C1 //                                        if(Threshold_Diff>400)
; 0000 02C2 //                                        {
; 0000 02C3 //                                            Threshold_BG = Threshold_Black + 375;
; 0000 02C4 //                                        }
; 0000 02C5 //                                        if(Threshold_Diff>375)
; 0000 02C6 //                                        {
; 0000 02C7 //                                            Threshold_BG = Threshold_Black + 350;
; 0000 02C8 //                                        }
; 0000 02C9 //                                        else if(Threshold_Diff>350)
; 0000 02CA //                                        {
; 0000 02CB //                                            Threshold_BG = Threshold_Black + 325;
; 0000 02CC //                                        }
; 0000 02CD 
; 0000 02CE //======COMMENT 03-10-2016======//
; 0000 02CF /*
; 0000 02D0                                         if(Threshold_Diff>310)
; 0000 02D1                                         {
; 0000 02D2                                             Threshold_BG = Threshold_Black + 300;
; 0000 02D3                                         }
; 0000 02D4 
; 0000 02D5                                         else if(Threshold_Diff>300)
; 0000 02D6                                         {
; 0000 02D7                                             Threshold_BG = Threshold_Black + 290;
; 0000 02D8                                         }
; 0000 02D9 */
; 0000 02DA 
; 0000 02DB                                        // else
; 0000 02DC                                         if(Threshold_Diff>290)
	CPI  R26,LOW(0x123)
	LDI  R30,HIGH(0x123)
	CPC  R27,R30
	BRLT _0xB2
; 0000 02DD                                         {
; 0000 02DE                                             Threshold_BG = Threshold_Black + 280;
	MOVW R30,R8
	SUBI R30,LOW(-280)
	SBCI R31,HIGH(-280)
	RJMP _0x11D
; 0000 02DF                                         }
; 0000 02E0 
; 0000 02E1 
; 0000 02E2                                         else if(Threshold_Diff>280)
_0xB2:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x119)
	LDI  R30,HIGH(0x119)
	CPC  R27,R30
	BRLT _0xB4
; 0000 02E3                                         {
; 0000 02E4                                             Threshold_BG = Threshold_Black + 270;
	MOVW R30,R8
	SUBI R30,LOW(-270)
	SBCI R31,HIGH(-270)
	RJMP _0x11D
; 0000 02E5                                         }
; 0000 02E6 
; 0000 02E7                                         else if(Threshold_Diff>270)
_0xB4:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x10F)
	LDI  R30,HIGH(0x10F)
	CPC  R27,R30
	BRLT _0xB6
; 0000 02E8                                         {
; 0000 02E9                                             Threshold_BG = Threshold_Black + 260;
	MOVW R30,R8
	SUBI R30,LOW(-260)
	SBCI R31,HIGH(-260)
	RJMP _0x11D
; 0000 02EA                                         }
; 0000 02EB 
; 0000 02EC                                         else if(Threshold_Diff>260)
_0xB6:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x105)
	LDI  R30,HIGH(0x105)
	CPC  R27,R30
	BRLT _0xB8
; 0000 02ED                                         {
; 0000 02EE                                             Threshold_BG = Threshold_Black + 250;
	MOVW R30,R8
	SUBI R30,LOW(-250)
	SBCI R31,HIGH(-250)
	RJMP _0x11D
; 0000 02EF                                         }
; 0000 02F0 
; 0000 02F1                                         else if(Threshold_Diff>250)
_0xB8:
	RCALL SUBOPT_0x25
	BRLT _0xBA
; 0000 02F2                                         {
; 0000 02F3                                             Threshold_BG = Threshold_Black + 225;
	MOVW R30,R8
	SUBI R30,LOW(-225)
	SBCI R31,HIGH(-225)
	RJMP _0x11D
; 0000 02F4                                         }
; 0000 02F5                                         else if(Threshold_Diff>225)
_0xBA:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0xE2)
	LDI  R30,HIGH(0xE2)
	CPC  R27,R30
	BRLT _0xBC
; 0000 02F6                                         {
; 0000 02F7                                             Threshold_BG = Threshold_Black + 200;
	MOVW R30,R8
	SUBI R30,LOW(-200)
	SBCI R31,HIGH(-200)
	RJMP _0x11D
; 0000 02F8                                         }
; 0000 02F9 
; 0000 02FA                                         else if(Threshold_Diff>200)
_0xBC:
	RCALL SUBOPT_0x26
	BRLT _0xBE
; 0000 02FB                                         {
; 0000 02FC                                             Threshold_BG = Threshold_Black + 175;
	MOVW R30,R8
	SUBI R30,LOW(-175)
	SBCI R31,HIGH(-175)
	RJMP _0x11D
; 0000 02FD                                         }
; 0000 02FE                                         else if(Threshold_Diff>175)
_0xBE:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0xB0)
	LDI  R30,HIGH(0xB0)
	CPC  R27,R30
	BRLT _0xC0
; 0000 02FF                                         {
; 0000 0300                                             Threshold_BG = Threshold_Black + 150;
	MOVW R30,R8
	SUBI R30,LOW(-150)
	SBCI R31,HIGH(-150)
	RJMP _0x11D
; 0000 0301                                         }
; 0000 0302 
; 0000 0303                                         else if(Threshold_Diff>150)
_0xC0:
	RCALL SUBOPT_0x27
	BRLT _0xC2
; 0000 0304                                         {
; 0000 0305                                             Threshold_BG = Threshold_Black + 125;
	MOVW R30,R8
	SUBI R30,LOW(-125)
	SBCI R31,HIGH(-125)
	RJMP _0x11D
; 0000 0306                                         }
; 0000 0307                                         else if(Threshold_Diff>125)
_0xC2:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x7E)
	LDI  R30,HIGH(0x7E)
	CPC  R27,R30
	BRLT _0xC4
; 0000 0308                                         {
; 0000 0309                                             Threshold_BG = Threshold_Black + 100;
	MOVW R30,R8
	SUBI R30,LOW(-100)
	SBCI R31,HIGH(-100)
	RJMP _0x11D
; 0000 030A                                         }
; 0000 030B                                         else if(Threshold_Diff>100)
_0xC4:
	RCALL SUBOPT_0x28
	BRLT _0xC6
; 0000 030C                                         {
; 0000 030D                                             Threshold_BG = Threshold_Black + 75;
	MOVW R30,R8
	SUBI R30,LOW(-75)
	SBCI R31,HIGH(-75)
	RJMP _0x11D
; 0000 030E                                         }
; 0000 030F                                         else if(Threshold_Diff>75)
_0xC6:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x4C)
	LDI  R30,HIGH(0x4C)
	CPC  R27,R30
	BRLT _0xC8
; 0000 0310                                         {
; 0000 0311                                             Threshold_BG = Threshold_Black + 50;
	MOVW R30,R8
	ADIW R30,50
	RJMP _0x11D
; 0000 0312                                         }
; 0000 0313                                         else if(Threshold_Diff>50)
_0xC8:
	RCALL SUBOPT_0x24
	SBIW R26,51
; 0000 0314                                         {
; 0000 0315                                             Threshold_BG = Threshold_Black + 25;
; 0000 0316                                         }
; 0000 0317                                         else
; 0000 0318                                         {
; 0000 0319                                             Threshold_BG = Threshold_Black + 25;
_0x11E:
	MOVW R30,R8
	ADIW R30,25
_0x11D:
	STS  _Threshold_BG,R30
	STS  _Threshold_BG+1,R31
; 0000 031A                                         }
; 0000 031B                                     }break;
	RJMP _0x60
; 0000 031C 
; 0000 031D             case TRACER_CALIBRATE_GRAY:
_0x7F:
	CPI  R30,LOW(0x4A)
	LDI  R26,HIGH(0x4A)
	CPC  R31,R26
	BRNE _0xCC
; 0000 031E                                     {
; 0000 031F                                         Tracer_GetData_Gray();
	RCALL _Tracer_GetData_Gray
; 0000 0320                                     }break;
	RJMP _0x60
; 0000 0321 
; 0000 0322             case TRACER_CALIBRATE_WHITE:
_0xCC:
	CPI  R30,LOW(0x4B)
	LDI  R26,HIGH(0x4B)
	CPC  R31,R26
	BRNE _0xCD
; 0000 0323                                     {
; 0000 0324                                         Tracer_GetData_White();
	RCALL _Tracer_GetData_White
; 0000 0325                                     }break;
	RJMP _0x60
; 0000 0326 
; 0000 0327             case TRACER_CALIBRATE_GETRULE:
_0xCD:
	CPI  R30,LOW(0x4C)
	LDI  R26,HIGH(0x4C)
	CPC  R31,R26
	BRNE _0x60
; 0000 0328                                     {
; 0000 0329                                         Tracer_Calibrate_GetRule();
	RCALL _Tracer_Calibrate_GetRule
; 0000 032A                                     }break;
; 0000 032B     }
_0x60:
; 0000 032C 
; 0000 032D }
	RET
; .FEND
;
;int Tracer_Sampling(int MODE)
; 0000 0330 {
_Tracer_Sampling:
; .FSTART _Tracer_Sampling
; 0000 0331 
; 0000 0332     int counter=0;
; 0000 0333     int TRACER_TEMP[5]={0,0,0,0,0};
; 0000 0334     int TRACER_SUM=0;
; 0000 0335 
; 0000 0336 
; 0000 0337     switch(MODE)
	ST   -Y,R27
	ST   -Y,R26
	SBIW R28,10
	LDI  R24,10
	RCALL SUBOPT_0x29
	LDI  R30,LOW(_0xCF*2)
	LDI  R31,HIGH(_0xCF*2)
	RCALL __INITLOCB
	RCALL __SAVELOCR4
;	MODE -> Y+14
;	counter -> R16,R17
;	TRACER_TEMP -> Y+4
;	TRACER_SUM -> R18,R19
	RCALL SUBOPT_0x2A
	__GETWRN 18,19,0
	LDD  R30,Y+14
	LDD  R31,Y+14+1
; 0000 0338     {
; 0000 0339         case 0: {
	SBIW R30,0
	BRNE _0xD3
; 0000 033A                     for(counter=0;counter<=4;counter++)
	RCALL SUBOPT_0x2A
_0xD5:
	RCALL SUBOPT_0x2B
	BRGE _0xD6
; 0000 033B                     {
; 0000 033C                         TRACER_TEMP[counter]= read_adc(2);
	RCALL SUBOPT_0x2C
	PUSH R31
	PUSH R30
	LDI  R26,LOW(2)
	RCALL _read_adc
	POP  R26
	POP  R27
	RCALL SUBOPT_0xB
; 0000 033D                     }
	RCALL SUBOPT_0x2D
	RJMP _0xD5
_0xD6:
; 0000 033E 
; 0000 033F                     TRACER_SUM= TRACER_TEMP[0]+TRACER_TEMP[1]+TRACER_TEMP[2]+TRACER_TEMP[3]+TRACER_TEMP[4];
	RCALL SUBOPT_0x2E
; 0000 0340                     TRACER[FRONT]=TRACER_SUM/5;
	STS  _TRACER,R30
	STS  _TRACER+1,R31
; 0000 0341 
; 0000 0342                     if(TRACER[FRONT]>=TRACER_THRESHOLD)
	RCALL SUBOPT_0x2F
	LDS  R26,_TRACER
	LDS  R27,_TRACER+1
	RCALL SUBOPT_0x30
	BRLT _0xD7
; 0000 0343                     {
; 0000 0344 //                        printf("TRACER FRONT ACTIVE \r");
; 0000 0345                         TRACER_SECTION[FRONT]= TRACER_ACTIVE;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	STS  _TRACER_SECTION,R30
	STS  _TRACER_SECTION+1,R31
; 0000 0346                     }
; 0000 0347 
; 0000 0348                     else
	RJMP _0xD8
_0xD7:
; 0000 0349                     {
; 0000 034A //                        printf("TRACER FRONT INACTIVE \r");
; 0000 034B                         TRACER_SECTION[FRONT]= TRACER_INACTIVE;
	LDI  R30,LOW(0)
	STS  _TRACER_SECTION,R30
	STS  _TRACER_SECTION+1,R30
; 0000 034C                     }
_0xD8:
; 0000 034D                     return TRACER[FRONT];
	LDS  R30,_TRACER
	LDS  R31,_TRACER+1
	RJMP _0x20A0003
; 0000 034E                 }break;
; 0000 034F 
; 0000 0350         case 1: {
_0xD3:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0xD9
; 0000 0351 
; 0000 0352                     for(counter=0;counter<=4;counter++)
	RCALL SUBOPT_0x2A
_0xDB:
	RCALL SUBOPT_0x2B
	BRGE _0xDC
; 0000 0353                     {
; 0000 0354                         TRACER_TEMP[counter]= read_adc(1);
	RCALL SUBOPT_0x2C
	PUSH R31
	PUSH R30
	LDI  R26,LOW(1)
	RCALL _read_adc
	POP  R26
	POP  R27
	RCALL SUBOPT_0xB
; 0000 0355                     }
	RCALL SUBOPT_0x2D
	RJMP _0xDB
_0xDC:
; 0000 0356 
; 0000 0357                     TRACER_SUM= TRACER_TEMP[0]+TRACER_TEMP[1]+TRACER_TEMP[2]+TRACER_TEMP[3]+TRACER_TEMP[4];
	RCALL SUBOPT_0x2E
; 0000 0358                     TRACER[MIDDLE]=TRACER_SUM/5;
	__PUTW1MN _TRACER,2
; 0000 0359 
; 0000 035A                     if(TRACER[MIDDLE]>=TRACER_THRESHOLD)
	__GETW2MN _TRACER,2
	RCALL SUBOPT_0x2F
	RCALL SUBOPT_0x30
	BRLT _0xDD
; 0000 035B                     {
; 0000 035C //                        printf("TRACER MIDDLE ACTIVE \r");
; 0000 035D                         TRACER_SECTION[MIDDLE]= TRACER_ACTIVE;
	__POINTW1MN _TRACER_SECTION,2
	LDI  R26,LOW(1)
	LDI  R27,HIGH(1)
	RJMP _0x11F
; 0000 035E                     }
; 0000 035F 
; 0000 0360                     else
_0xDD:
; 0000 0361                     {
; 0000 0362 //                        printf("TRACER MIDDLE INACTIVE \r");
; 0000 0363                         TRACER_SECTION[MIDDLE]= TRACER_INACTIVE;
	__POINTW1MN _TRACER_SECTION,2
	RCALL SUBOPT_0x29
_0x11F:
	STD  Z+0,R26
	STD  Z+1,R27
; 0000 0364                     }
; 0000 0365                     return TRACER[MIDDLE];
	__GETW1MN _TRACER,2
	RJMP _0x20A0003
; 0000 0366                 }break;
; 0000 0367 
; 0000 0368         case 2: {
_0xD9:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0xD2
; 0000 0369                     for(counter=0;counter<=4;counter++)
	RCALL SUBOPT_0x2A
_0xE1:
	RCALL SUBOPT_0x2B
	BRGE _0xE2
; 0000 036A                     {
; 0000 036B                         TRACER_TEMP[counter]= read_adc(0);
	RCALL SUBOPT_0x2C
	PUSH R31
	PUSH R30
	LDI  R26,LOW(0)
	RCALL _read_adc
	POP  R26
	POP  R27
	RCALL SUBOPT_0xB
; 0000 036C                     }
	RCALL SUBOPT_0x2D
	RJMP _0xE1
_0xE2:
; 0000 036D 
; 0000 036E                     TRACER_SUM= TRACER_TEMP[0]+TRACER_TEMP[1]+TRACER_TEMP[2]+TRACER_TEMP[3]+TRACER_TEMP[4];
	RCALL SUBOPT_0x2E
; 0000 036F                     TRACER[REAR]=TRACER_SUM/5;
	__PUTW1MN _TRACER,4
; 0000 0370 
; 0000 0371                     if(TRACER[REAR]>=TRACER_THRESHOLD)
	__GETW2MN _TRACER,4
	RCALL SUBOPT_0x2F
	RCALL SUBOPT_0x30
	BRLT _0xE3
; 0000 0372                     {
; 0000 0373 //                        printf("TRACER REAR ACTIVE \r");
; 0000 0374                         TRACER_SECTION[REAR]= TRACER_ACTIVE;
	__POINTW1MN _TRACER_SECTION,4
	LDI  R26,LOW(1)
	LDI  R27,HIGH(1)
	RJMP _0x120
; 0000 0375                     }
; 0000 0376 
; 0000 0377                     else
_0xE3:
; 0000 0378                     {
; 0000 0379 //                        printf("TRACER REAR INACTIVE \r");
; 0000 037A                         TRACER_SECTION[REAR]= TRACER_INACTIVE;
	__POINTW1MN _TRACER_SECTION,4
	RCALL SUBOPT_0x29
_0x120:
	STD  Z+0,R26
	STD  Z+1,R27
; 0000 037B                     }
; 0000 037C                     return TRACER[REAR];
	__GETW1MN _TRACER,4
; 0000 037D                 }break;
; 0000 037E     }
_0xD2:
; 0000 037F }
_0x20A0003:
	RCALL __LOADLOCR4
	ADIW R28,16
	RET
; .FEND
;//
;//int Tracer_Sampling(int MODE)
;//{
;//
;//
;//    switch(MODE)
;//    {
;//        case 0: {
;//
;//                    TRACER[FRONT]= read_adc(2);
;//                    if(TRACER[FRONT]>=TRACER_THRESHOLD)
;//                    {
;//                        printf("TRACER FRONT ACTIVE \r");
;//                        TRACER_SECTION[FRONT]= TRACER_ACTIVE;
;//                    }
;//
;//                    else
;//                    {
;//                        printf("TRACER FRONT INACTIVE \r");
;//                        TRACER_SECTION[FRONT]= TRACER_INACTIVE;
;//                    }
;//                    return TRACER[FRONT];
;//                }break;
;//
;//        case 1: {
;//                    TRACER[MIDDLE]= read_adc(1);
;//                    if(TRACER[MIDDLE]>=TRACER_THRESHOLD)
;//                    {
;//                        printf("TRACER MIDDLE ACTIVE \r");
;//                        TRACER_SECTION[MIDDLE]= TRACER_ACTIVE;
;//                    }
;//
;//                    else
;//                    {
;//                        printf("TRACER MIDDLE INACTIVE \r");
;//                        TRACER_SECTION[MIDDLE]= TRACER_INACTIVE;
;//                    }
;//                    return TRACER[MIDDLE];
;//                }break;
;//
;//        case 2: {
;//                    TRACER[REAR]= read_adc(0);
;//                    if(TRACER[REAR]>=TRACER_THRESHOLD)
;//                    {
;//                        printf("TRACER REAR ACTIVE \r");
;//                        TRACER_SECTION[REAR]= TRACER_ACTIVE;
;//                    }
;//
;//                    else
;//                    {
;//                        printf("TRACER REAR INACTIVE \r");
;//                        TRACER_SECTION[REAR]= TRACER_INACTIVE;
;//                    }
;//                    return TRACER[REAR];
;//                }break;
;//    }
;//}
;
;
;void Tracer_GetRule(void)
; 0000 03BC {
_Tracer_GetRule:
; .FSTART _Tracer_GetRule
; 0000 03BD     Tracer_Sampling(FRONT);
	RCALL SUBOPT_0x31
; 0000 03BE     Tracer_Sampling(MIDDLE);
	RCALL SUBOPT_0x32
; 0000 03BF     Tracer_Sampling(REAR);
	RCALL SUBOPT_0x33
; 0000 03C0 
; 0000 03C1 //    printf("TRACER[FRONT]: %d \t TRACER[MIDDLE]: %d \t TRACER[REAR]: %d  \r",TRACER[FRONT],TRACER[MIDDLE],TRACER[REAR] ...
; 0000 03C2 
; 0000 03C3     if( (TRACER_SECTION[FRONT]==TRACER_ACTIVE) || (TRACER_SECTION[MIDDLE]==TRACER_ACTIVE) || (TRACER_SECTION[REAR]==TRAC ...
	LDS  R26,_TRACER_SECTION
	LDS  R27,_TRACER_SECTION+1
	SBIW R26,1
	BREQ _0xE6
	__GETW1MN _TRACER_SECTION,2
	SBIW R30,1
	BREQ _0xE6
	__GETW1MN _TRACER_SECTION,4
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0xE5
_0xE6:
; 0000 03C4     {
; 0000 03C5 //        printf("TRACER STAT ACTIVE \r");
; 0000 03C6         TRACER_STAT=TRACER_ACTIVE;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	STS  _TRACER_STAT,R30
	STS  _TRACER_STAT+1,R31
; 0000 03C7     }
; 0000 03C8     else
	RJMP _0xE8
_0xE5:
; 0000 03C9     {
; 0000 03CA //        printf("TRACER STAT INACTIVE \r");
; 0000 03CB         TRACER_STAT=TRACER_INACTIVE;
	LDI  R30,LOW(0)
	STS  _TRACER_STAT,R30
	STS  _TRACER_STAT+1,R30
; 0000 03CC     }
_0xE8:
; 0000 03CD 
; 0000 03CE }
	RET
; .FEND
;
;void Tracer_GetData_Gray(void)
; 0000 03D1 {
_Tracer_GetData_Gray:
; .FSTART _Tracer_GetData_Gray
; 0000 03D2      int TRC_FRONT,TRC_MIDDLE,TRC_REAR;
; 0000 03D3      int THold_Temp;
; 0000 03D4 
; 0000 03D5      TRC_FRONT  = Tracer_Sampling(FRONT);
	SBIW R28,2
	RCALL __SAVELOCR6
;	TRC_FRONT -> R16,R17
;	TRC_MIDDLE -> R18,R19
;	TRC_REAR -> R20,R21
;	THold_Temp -> Y+6
	RCALL SUBOPT_0x31
	MOVW R16,R30
; 0000 03D6      TRC_MIDDLE = Tracer_Sampling(MIDDLE);
	RCALL SUBOPT_0x32
	MOVW R18,R30
; 0000 03D7      TRC_REAR   = Tracer_Sampling(REAR);
	RCALL SUBOPT_0x33
	MOVW R20,R30
; 0000 03D8 
; 0000 03D9 //     THold_Temp = max(TRC_FRONT, TRC_MIDDLE);
; 0000 03DA //     THold_Temp = max(THold_Temp, TRC_REAR);
; 0000 03DB      if(TRC_FRONT >= TRC_MIDDLE) THold_Temp = TRC_FRONT;
	__CPWRR 16,17,18,19
	BRLT _0xE9
	__PUTWSR 16,17,6
; 0000 03DC      else THold_Temp= TRC_MIDDLE;
	RJMP _0xEA
_0xE9:
	__PUTWSR 18,19,6
; 0000 03DD 
; 0000 03DE      if(TRC_REAR >= THold_Temp) THold_Temp = TRC_REAR;
_0xEA:
	LDD  R30,Y+6
	LDD  R31,Y+6+1
	CP   R20,R30
	CPC  R21,R31
	BRLT _0xEB
	__PUTWSR 20,21,6
; 0000 03DF 
; 0000 03E0      TRACER_GRAYDATA= THold_Temp;
_0xEB:
	__GETWRS 12,13,6
; 0000 03E1 
; 0000 03E2 }
	RJMP _0x20A0002
; .FEND
;
;void Tracer_GetData_White(void)
; 0000 03E5 {
_Tracer_GetData_White:
; .FSTART _Tracer_GetData_White
; 0000 03E6      int TRC_FRONT,TRC_MIDDLE,TRC_REAR;
; 0000 03E7      int THold_Temp;
; 0000 03E8 
; 0000 03E9      TRC_FRONT  = Tracer_Sampling(FRONT);
	SBIW R28,2
	RCALL __SAVELOCR6
;	TRC_FRONT -> R16,R17
;	TRC_MIDDLE -> R18,R19
;	TRC_REAR -> R20,R21
;	THold_Temp -> Y+6
	RCALL SUBOPT_0x31
	MOVW R16,R30
; 0000 03EA      TRC_MIDDLE = Tracer_Sampling(MIDDLE);
	RCALL SUBOPT_0x32
	MOVW R18,R30
; 0000 03EB      TRC_REAR   = Tracer_Sampling(REAR);
	RCALL SUBOPT_0x33
	MOVW R20,R30
; 0000 03EC 
; 0000 03ED //     THold_Temp = min(TRC_FRONT, TRC_MIDDLE);
; 0000 03EE //     THold_Temp = min(THold_Temp, TRC_REAR);
; 0000 03EF 
; 0000 03F0      if(TRC_FRONT <= TRC_MIDDLE) THold_Temp = TRC_FRONT;
	__CPWRR 18,19,16,17
	BRLT _0xEC
	__PUTWSR 16,17,6
; 0000 03F1      else THold_Temp= TRC_MIDDLE;
	RJMP _0xED
_0xEC:
	__PUTWSR 18,19,6
; 0000 03F2 
; 0000 03F3      if(TRC_REAR <= THold_Temp) THold_Temp = TRC_REAR;
_0xED:
	LDD  R30,Y+6
	LDD  R31,Y+6+1
	CP   R30,R20
	CPC  R31,R21
	BRLT _0xEE
	__PUTWSR 20,21,6
; 0000 03F4 
; 0000 03F5      TRACER_WHITEDATA= THold_Temp;
_0xEE:
	LDD  R30,Y+6
	LDD  R31,Y+6+1
	STS  _TRACER_WHITEDATA,R30
	STS  _TRACER_WHITEDATA+1,R31
; 0000 03F6 }
_0x20A0002:
	RCALL __LOADLOCR6
	ADIW R28,8
	RET
; .FEND
;
;void Tracer_Calibrate_GetRule(void)
; 0000 03F9 {
_Tracer_Calibrate_GetRule:
; .FSTART _Tracer_Calibrate_GetRule
; 0000 03FA     int Tracer_Diff;
; 0000 03FB     int Tracer_White= TRACER_WHITEDATA;
; 0000 03FC     int Tracer_Gray= TRACER_GRAYDATA;
; 0000 03FD 
; 0000 03FE     //Tracer_Diff= TRACER_WHITEDATA-TRACER_GRAYDATA;
; 0000 03FF     Tracer_Diff= Tracer_White-Tracer_Gray;
	RCALL __SAVELOCR6
;	Tracer_Diff -> R16,R17
;	Tracer_White -> R18,R19
;	Tracer_Gray -> R20,R21
	__GETWRMN 18,19,0,_TRACER_WHITEDATA
	MOVW R20,R12
	MOVW R30,R18
	SUB  R30,R20
	SBC  R31,R21
	MOVW R16,R30
; 0000 0400 
; 0000 0401     if(Tracer_Diff>=80)      TRACER_THRESHOLD   = Tracer_Gray + 75;
	__CPWRN 16,17,80
	BRLT _0xEF
	MOVW R30,R20
	SUBI R30,LOW(-75)
	SBCI R31,HIGH(-75)
	RJMP _0x121
; 0000 0402     else if(Tracer_Diff>=75) TRACER_THRESHOLD   = Tracer_Gray + 70;
_0xEF:
	__CPWRN 16,17,75
	BRLT _0xF1
	MOVW R30,R20
	SUBI R30,LOW(-70)
	SBCI R31,HIGH(-70)
	RJMP _0x121
; 0000 0403     else if(Tracer_Diff>=70) TRACER_THRESHOLD   = Tracer_Gray + 65;
_0xF1:
	__CPWRN 16,17,70
	BRLT _0xF3
	MOVW R30,R20
	SUBI R30,LOW(-65)
	SBCI R31,HIGH(-65)
	RJMP _0x121
; 0000 0404     else if(Tracer_Diff>=65) TRACER_THRESHOLD   = Tracer_Gray + 60;
_0xF3:
	__CPWRN 16,17,65
	BRLT _0xF5
	MOVW R30,R20
	ADIW R30,60
	RJMP _0x121
; 0000 0405     else if(Tracer_Diff>=60) TRACER_THRESHOLD   = Tracer_Gray + 55;
_0xF5:
	__CPWRN 16,17,60
	BRLT _0xF7
	MOVW R30,R20
	ADIW R30,55
	RJMP _0x121
; 0000 0406     else if(Tracer_Diff>=50) TRACER_THRESHOLD   = Tracer_Gray + 45;
_0xF7:
	__CPWRN 16,17,50
	BRLT _0xF9
	MOVW R30,R20
	ADIW R30,45
	RJMP _0x121
; 0000 0407     else if(Tracer_Diff>=40) TRACER_THRESHOLD   = Tracer_Gray + 35;
_0xF9:
	__CPWRN 16,17,40
	BRLT _0xFB
	MOVW R30,R20
	ADIW R30,35
	RJMP _0x121
; 0000 0408     else if(Tracer_Diff>=30) TRACER_THRESHOLD   = Tracer_Gray + 25;
_0xFB:
	__CPWRN 16,17,30
	BRLT _0xFD
	MOVW R30,R20
	ADIW R30,25
	RJMP _0x121
; 0000 0409     else if(Tracer_Diff>=20) TRACER_THRESHOLD   = Tracer_Gray + 15;
_0xFD:
	__CPWRN 16,17,20
	BRLT _0xFF
	MOVW R30,R20
	ADIW R30,15
	RJMP _0x121
; 0000 040A     else if(Tracer_Diff>=10) TRACER_THRESHOLD   = Tracer_Gray + 7;
_0xFF:
	__CPWRN 16,17,10
	BRLT _0x101
	MOVW R30,R20
	ADIW R30,7
_0x121:
	STS  _TRACER_THRESHOLD,R30
	STS  _TRACER_THRESHOLD+1,R31
; 0000 040B 
; 0000 040C }
_0x101:
	RJMP _0x20A0001
; .FEND
;
;
;
;
;void TCS3200_Sampling(void)
; 0000 0412 {
_TCS3200_Sampling:
; .FSTART _TCS3200_Sampling
; 0000 0413 
; 0000 0414     int counter;
; 0000 0415 
; 0000 0416     MOV_AVG[TCS3200_RED]=0;
	RCALL __SAVELOCR2
;	counter -> R16,R17
	__POINTW1MN _MOV_AVG,10
	RCALL SUBOPT_0x34
; 0000 0417     MOV_AVG[TCS3200_GREEN]=0;
	__POINTW1MN _MOV_AVG,12
	RCALL SUBOPT_0x34
; 0000 0418     MOV_AVG[TCS3200_BLUE]=0;
	__POINTW1MN _MOV_AVG,14
	RCALL SUBOPT_0x34
; 0000 0419     MOV_AVG[TCS3200_WHITE]=0;
	__POINTW1MN _MOV_AVG,16
	RCALL SUBOPT_0x34
; 0000 041A 
; 0000 041B     for(counter=1;counter<=1;counter++)
	__GETWRN 16,17,1
_0x103:
	__CPWRN 16,17,2
	BRGE _0x104
; 0000 041C     {
; 0000 041D         TCS3200Read_R();
	RCALL SUBOPT_0x3
; 0000 041E         TCS3200Read_G();
; 0000 041F         TCS3200Read_B();
; 0000 0420         TCS3200Read_W();
; 0000 0421 
; 0000 0422         MOV_AVG[TCS3200_RED]+=TCS3200_Pulse_R;
	RCALL SUBOPT_0x10
	RCALL SUBOPT_0x35
	RCALL SUBOPT_0x12
; 0000 0423         MOV_AVG[TCS3200_GREEN]+=TCS3200_Pulse_G;
	RCALL SUBOPT_0x17
	RCALL SUBOPT_0x36
	RCALL SUBOPT_0x18
; 0000 0424         MOV_AVG[TCS3200_BLUE]+=TCS3200_Pulse_B;
	RCALL SUBOPT_0x1A
	LDS  R26,_TCS3200_Pulse_B
	LDS  R27,_TCS3200_Pulse_B+1
	RCALL SUBOPT_0x37
	RCALL SUBOPT_0x1B
; 0000 0425         MOV_AVG[TCS3200_WHITE]+=TCS3200_Pulse_W;
	RCALL SUBOPT_0x1D
	RCALL SUBOPT_0x38
	RCALL SUBOPT_0x1E
; 0000 0426 
; 0000 0427          TCS3200_TOTAL_SUM = TCS3200_Pulse_R + TCS3200_Pulse_B + TCS3200_Pulse_G + TCS3200_Pulse_W;
	RCALL SUBOPT_0x9
	RCALL SUBOPT_0x35
	RCALL SUBOPT_0x36
	RCALL SUBOPT_0x38
	RCALL SUBOPT_0x20
; 0000 0428 //         if(TCS3200_TOTAL_SUM >= 1800)
; 0000 0429 //         {
; 0000 042A //            DETECTED_COLOUR         = COLOUR_WHITE;
; 0000 042B //            TRACER_STAT             = TRACER_ACTIVE;
; 0000 042C //            printf("========== CONCLUSION: WHITE ============= \r");
; 0000 042D //
; 0000 042E //            Send_UART(COMMAND_FLAG_A);
; 0000 042F //            Send_UART(COMMAND_FLAG_B);
; 0000 0430 //            Send_UART(DETECTED_COLOUR);
; 0000 0431 //            Send_UART(TRACER_STAT);
; 0000 0432 //
; 0000 0433 //         }
; 0000 0434     }
	RCALL SUBOPT_0x2D
	RJMP _0x103
_0x104:
; 0000 0435 
; 0000 0436     MOV_AVG[TCS3200_RED]/=1;
	RCALL SUBOPT_0x10
	RCALL SUBOPT_0x12
; 0000 0437     MOV_AVG[TCS3200_GREEN]/=1;
	RCALL SUBOPT_0x17
	RCALL SUBOPT_0x18
; 0000 0438     MOV_AVG[TCS3200_BLUE]/=1;
	RCALL SUBOPT_0x1A
	RCALL SUBOPT_0x1B
; 0000 0439     MOV_AVG[TCS3200_WHITE]/=1;
	RCALL SUBOPT_0x1D
	RCALL SUBOPT_0x1E
; 0000 043A 
; 0000 043B 
; 0000 043C //    FRONT_THRESHOLD = FRONT_Pulse_R - FRONT_Pulse_B;
; 0000 043D //    FRONT_TOTAL_SUM = FRONT_Pulse_R + FRONT_Pulse_B + FRONT_Pulse_G + FRONT_Pulse_W;
; 0000 043E //
; 0000 043F //    printf("FRONT_THRESHOLD = %d \t\t FRONT_TOTAL_SUM %d \r",FRONT_THRESHOLD, FRONT_TOTAL_SUM);
; 0000 0440 
; 0000 0441     TCS3200_TOTAL_SUM = MOV_AVG[TCS3200_RED] + MOV_AVG[TCS3200_GREEN] + MOV_AVG[TCS3200_BLUE] + MOV_AVG[TCS3200_WHITE];
	__GETW2MN _MOV_AVG,10
	RCALL SUBOPT_0x17
	ADD  R26,R30
	ADC  R27,R31
	RCALL SUBOPT_0x1A
	ADD  R26,R30
	ADC  R27,R31
	RCALL SUBOPT_0x1D
	RCALL SUBOPT_0x37
	RCALL SUBOPT_0x20
; 0000 0442 
; 0000 0443 //    printf("TCS3200_TOTAL_SUM %d \r",TCS3200_TOTAL_SUM);
; 0000 0444 //
; 0000 0445 
; 0000 0446 
; 0000 0447 }
	LD   R16,Y+
	LD   R17,Y+
	RET
; .FEND
;
;//TCS3200_MODE
;// 1 -> FRONT
;// 2 -> MIDDLE
;void Display_Raw_Data(int TCS3200_MODE)
; 0000 044D {
; 0000 044E     switch(TCS3200_MODE)
;	TCS3200_MODE -> Y+0
; 0000 044F     {
; 0000 0450         case 1:
; 0000 0451                 {
; 0000 0452                     printf("============================================================================= \r",);
; 0000 0453                     printf("==========================FRONT TCS3200 MONITOR============================== \r",);
; 0000 0454                     printf("============================================================================= \r",);
; 0000 0455                     printf("============================================================================= \r",);
; 0000 0456                 }break;
; 0000 0457         case 2:
; 0000 0458                 {
; 0000 0459                     printf("============================================================================= \r",);
; 0000 045A                     printf("===========================MIDDLE TCS3200 MONITOR============================ \r",);
; 0000 045B                     printf("============================================================================= \r",);
; 0000 045C                     printf("Red  : %d \t",(int)MOV_AVG[TCS3200_RED]);
; 0000 045D                     printf("Green: %d \t",(int)MOV_AVG[TCS3200_GREEN]);
; 0000 045E                     printf("Blue: %d \t",(int)MOV_AVG[TCS3200_BLUE]);
; 0000 045F                     printf("White: %d \r",(int)MOV_AVG[TCS3200_WHITE]);
; 0000 0460                     printf("TCS3200_THRESHOLD = %d \t\t TCS3200_TOTAL_SUM %d \r",TCS3200_THRESHOLD, TCS3200_TOTAL_SUM);
; 0000 0461                     printf("============================================================================= \r",);
; 0000 0462                 }break;
; 0000 0463     }
; 0000 0464 }
;
;void TCS3200_GetRule(void)
; 0000 0467 {
_TCS3200_GetRule:
; .FSTART _TCS3200_GetRule
; 0000 0468     TCS3200_Sampling();
	RCALL _TCS3200_Sampling
; 0000 0469 
; 0000 046A   if(TCS3200_TOTAL_SUM >= Threshold_BW ) //WHITE
	RCALL SUBOPT_0x39
	BRLT _0x10A
; 0000 046B //    if(TCS3200_TOTAL_SUM >= 900 ) //WHITE
; 0000 046C     {
; 0000 046D         DETECTED_COLOUR       = COLOUR_WHITE;
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	RJMP _0x123
; 0000 046E         //TRACER_STAT           = TRACER_ACTIVE;
; 0000 046F //        printf("========== CONCLUSION: WHITE ============= \r");
; 0000 0470     }
; 0000 0471   else if (TCS3200_TOTAL_SUM < Threshold_BW) //GREY CARPET OR BLACK FLOOR
_0x10A:
	RCALL SUBOPT_0x39
	BRGE _0x10C
; 0000 0472 //    else if (TCS3200_TOTAL_SUM < 900) //GREY CARPET OR BLACK FLOOR
; 0000 0473     {
; 0000 0474         //BLACK FLOOR
; 0000 0475         if(TCS3200_TOTAL_SUM < Threshold_BG)
	RCALL SUBOPT_0x3A
	BRGE _0x10D
; 0000 0476 //        if(TCS3200_TOTAL_SUM < 380)
; 0000 0477         {
; 0000 0478             DETECTED_COLOUR   = COLOUR_BLACK;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	RJMP _0x123
; 0000 0479             //TRACER_STAT        = TRACER_INACTIVE;
; 0000 047A //            printf("========== CONCLUSION: BLACK ============= \r");
; 0000 047B         }
; 0000 047C 
; 0000 047D         //Grey Carpet
; 0000 047E         else if(TCS3200_TOTAL_SUM >= Threshold_BG)
_0x10D:
	RCALL SUBOPT_0x3A
	BRLT _0x10F
; 0000 047F //        else if( TCS3200_TOTAL_SUM >= 380)
; 0000 0480         {
; 0000 0481             DETECTED_COLOUR   = COLOUR_GRAY;
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	RJMP _0x123
; 0000 0482            // TRACER_STAT        = TRACER_INACTIVE;
; 0000 0483 //           printf("========== CONCLUSION: GRAY ============= \r");
; 0000 0484         }
; 0000 0485         else
_0x10F:
; 0000 0486         {
; 0000 0487             DETECTED_COLOUR     = COLOUR_ERROR;
	LDI  R30,LOW(6)
	LDI  R31,HIGH(6)
_0x123:
	MOVW R4,R30
; 0000 0488             //TRACER_STAT         = TRACER_INACTIVE;
; 0000 0489         }
; 0000 048A     }
; 0000 048B }
_0x10C:
	RET
; .FEND
;
;
;void TCS3200_Autocalibration(void)
; 0000 048F {
; 0000 0490     TCS3200_CMD[0] = getchar();
; 0000 0491 
; 0000 0492     while (TCS3200_CMD[0] != START_BUTTON)
; 0000 0493     {
; 0000 0494         TCS3200_CMD[0] = getchar();
; 0000 0495     }
; 0000 0496 }
;
;
;void Send_Threshold(void)
; 0000 049A {
_Send_Threshold:
; .FSTART _Send_Threshold
; 0000 049B     int Thold_BW,Thold_BG,Thold_Tracer;
; 0000 049C     Thold_BW= Threshold_BW;
	RCALL __SAVELOCR6
;	Thold_BW -> R16,R17
;	Thold_BG -> R18,R19
;	Thold_Tracer -> R20,R21
	__GETWRMN 16,17,0,_Threshold_BW
; 0000 049D     Thold_BG= Threshold_BG;
	__GETWRMN 18,19,0,_Threshold_BG
; 0000 049E     Thold_Tracer= TRACER_THRESHOLD;
	__GETWRMN 20,21,0,_TRACER_THRESHOLD
; 0000 049F 
; 0000 04A0     Send_UART(COMMAND_FLAG_A);
	RCALL SUBOPT_0xD
; 0000 04A1     Send_UART(COMMAND_FLAG_B);
; 0000 04A2     Send_UART(RAW_VAL_FLAG);
; 0000 04A3 
; 0000 04A4     //Threshold_BW VALUE
; 0000 04A5     MULTIPLY_COUNTER=0;
	RCALL SUBOPT_0xE
; 0000 04A6     if(Thold_BW>255)
	__CPWRN 16,17,256
	BRLT _0x114
; 0000 04A7     {
; 0000 04A8         while( Thold_BW >255)
_0x115:
	__CPWRN 16,17,256
	BRLT _0x117
; 0000 04A9         {
; 0000 04AA            Thold_BW-=255;
	__SUBWRN 16,17,255
; 0000 04AB            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x13
; 0000 04AC         }
	RJMP _0x115
_0x117:
; 0000 04AD     }
; 0000 04AE     Send_UART(MULTIPLY_COUNTER);
_0x114:
	RCALL SUBOPT_0x14
; 0000 04AF     Send_UART(Thold_BW);
	MOV  R26,R16
	RCALL SUBOPT_0x15
; 0000 04B0 
; 0000 04B1     //Threshold_BG VALUE
; 0000 04B2     MULTIPLY_COUNTER=0;
; 0000 04B3     if(Thold_BG>255)
	__CPWRN 18,19,256
	BRLT _0x118
; 0000 04B4     {
; 0000 04B5         while( Thold_BG >255)
_0x119:
	__CPWRN 18,19,256
	BRLT _0x11B
; 0000 04B6         {
; 0000 04B7            Thold_BG-=255;
	__SUBWRN 18,19,255
; 0000 04B8            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x13
; 0000 04B9         }
	RJMP _0x119
_0x11B:
; 0000 04BA     }
; 0000 04BB     Send_UART(MULTIPLY_COUNTER);
_0x118:
	RCALL SUBOPT_0x14
; 0000 04BC     Send_UART(Thold_BG);
	MOV  R26,R18
	RCALL _Send_UART
; 0000 04BD 
; 0000 04BE     //PHOTODIODE TRACER B/W THRESHOLD
; 0000 04BF     Send_UART(Thold_Tracer);
	MOV  R26,R20
	RCALL _Send_UART
; 0000 04C0 }
_0x20A0001:
	RCALL __LOADLOCR6
	ADIW R28,6
	RET
; .FEND
;
;
;
;/*=============== MOVING AVERAGE SMOOTHING ALGORITHM =================
;New average = old average * (n-1)/n + new value /n
;=====================================================================*/
;
;// Function Prototypes
;//int GetMov_AVG(unsigned int TCS_MODE, unsigned int NewVal)
;//{
;//    Mov_AVG[TCS_MODE]= Mov_AVG[TCS_MODE] * (MovAVG_Counter[TCS_MODE]-1) / MovAVG_Counter[TCS_MODE] + NewVal/MovAVG_Cou ...
;//    MovAVG_Counter[TCS_MODE]++;
;//    return Mov_AVG[TCS_MODE];
;//}
;
;//void GetRule_MovAVG(void)
;//{
;////    int buff_1,buff_2;
;////
;////    for(MovAVG_Counter=1;MovAVG_Counter<=5;MovAVG_Counter++)
;////    {
;////        NewVal=FRONT_Read_R();
;////        buff_1= Mov_AVG * (MovAVG_Counter-1);
;////        buff_1= buff_1/ MovAVG_Counter;
;////        buff_2= NewVal/MovAVG_Counter;
;////        Mov_AVG= buff_1 + buff_2 ;
;////    }
;////
;//
;////   NewVal[F_GREEN]=FRONT_Read_G();
;////   GetMov_AVG(F_GREEN,NewVal[F_GREEN]);
;////
;////   NewVal[F_BLUE]=FRONT_Read_B();
;////   GetMov_AVG(F_BLUE,NewVal[F_BLUE]);
;////
;////   NewVal[F_WHITE]=FRONT_Read_W();
;////   GetMov_AVG(F_WHITE,NewVal[F_WHITE]);
;//
;//    printf("============================================================================= \r",);
;//    printf("==========================FRONT TCS3200 MONITOR============================== \r",);
;//    printf("============================================================================= \r",);
;//    printf("Red  : %d \t",(int)Mov_AVG);
;////    printf("Green: %d \t",(int)Mov_AVG[F_GREEN]);
;////    printf("Blue : %d \t",(int)Mov_AVG[F_BLUE]);
;////    printf("White: %d \r",(int)Mov_AVG[F_WHITE]);
;//    printf("============================================================================= \r",);
;//}void Send_UART(unsigned char data)
;
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

	.CSEG

	.CSEG

	.DSEG
_TRACER_WHITEDATA:
	.BYTE 0x2
_Threshold_BW:
	.BYTE 0x2
_Threshold_BG:
	.BYTE 0x2
_TRACER_THRESHOLD:
	.BYTE 0x2
_COMMAND_FLAG_A:
	.BYTE 0x2
_COMMAND_FLAG_B:
	.BYTE 0x2
_START_BUTTON:
	.BYTE 0x2
_CMD_IDLE:
	.BYTE 0x2
_MOV_AVG:
	.BYTE 0x14
_TCS3200_COUNTER:
	.BYTE 0x2
_TCS3200_Pulse_R:
	.BYTE 0x2
_TCS3200_Pulse_G:
	.BYTE 0x2
_TCS3200_Pulse_B:
	.BYTE 0x2
_TCS3200_Pulse_W:
	.BYTE 0x2
_TCS3200_Pulse_Sum:
	.BYTE 0x2
_TCS3200_THRESHOLD:
	.BYTE 0x2
_TCS3200_TOTAL_SUM:
	.BYTE 0x2
_TCS3200_CMD:
	.BYTE 0x10

	.ESEG
_EEPROM_A:
	.BYTE 0x2
_EEPROM_B:
	.BYTE 0x2
_EEPROM_C:
	.BYTE 0x2
_EEPROM_D:
	.BYTE 0x2

	.DSEG
_Threshold_Diff:
	.BYTE 0x2
_RAW_VAL_FLAG:
	.BYTE 0x2
_MULTIPLY_COUNTER:
	.BYTE 0x2
_TRACER:
	.BYTE 0x6
_TRACER_STAT:
	.BYTE 0x2
_TRACER_SECTION:
	.BYTE 0x6
_rx_buffer:
	.BYTE 0x8
_rx_wr_index:
	.BYTE 0x1
_rx_rd_index:
	.BYTE 0x1
_rx_counter:
	.BYTE 0x1
__seed_G101:
	.BYTE 0x4

	.CSEG
;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x0:
	SUBI R30,LOW(1)
	LDI  R31,0
	SUBI R30,LOW(-_rx_buffer)
	SBCI R31,HIGH(-_rx_buffer)
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 8 TIMES, CODE SIZE REDUCTION:26 WORDS
SUBOPT_0x1:
	LD   R30,X+
	LD   R31,X+
	ADIW R30,1
	ST   -X,R31
	ST   -X,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x2:
	LDI  R30,LOW(0)
	OUT  0x2E,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x3:
	RCALL _TCS3200Read_R
	RCALL _TCS3200Read_G
	RCALL _TCS3200Read_B
	RJMP _TCS3200Read_W

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x4:
	CBI  0x15,3
	LDI  R26,LOW(5)
	LDI  R27,0
	RCALL _delay_ms
	LDI  R30,LOW(6)
	OUT  0x2E,R30
	LDI  R26,LOW(5)
	LDI  R27,0
	RCALL _delay_ms
	RJMP SUBOPT_0x2

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:19 WORDS
SUBOPT_0x5:
	LDS  R31,_TCS3200_COUNTER
	LDI  R30,LOW(0)
	MOVW R26,R30
	IN   R30,0x2C
	IN   R31,0x2C+1
	ADD  R30,R26
	ADC  R31,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:31 WORDS
SUBOPT_0x6:
	LDI  R30,LOW(0)
	LDI  R31,HIGH(0)
	OUT  0x2C+1,R31
	OUT  0x2C,R30
	STS  _TCS3200_COUNTER,R30
	STS  _TCS3200_COUNTER+1,R30
	LDI  R26,LOW(10)
	LDI  R27,0
	RJMP _delay_ms

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x7:
	SBI  0x15,3
	LDI  R26,LOW(5)
	LDI  R27,0
	RCALL _delay_ms
	LDI  R30,LOW(6)
	OUT  0x2E,R30
	LDI  R26,LOW(5)
	LDI  R27,0
	RCALL _delay_ms
	RJMP SUBOPT_0x2

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x8:
	LDS  R30,_TCS3200_Pulse_G
	LDS  R31,_TCS3200_Pulse_G+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x9:
	LDS  R30,_TCS3200_Pulse_B
	LDS  R31,_TCS3200_Pulse_B+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xA:
	LDS  R30,_TCS3200_Pulse_W
	LDS  R31,_TCS3200_Pulse_W+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0xB:
	LDI  R31,0
	ST   X+,R30
	ST   X,R31
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xC:
	LDS  R30,_TCS3200_CMD
	LDS  R31,_TCS3200_CMD+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:14 WORDS
SUBOPT_0xD:
	LDS  R26,_COMMAND_FLAG_A
	RCALL _Send_UART
	LDS  R26,_COMMAND_FLAG_B
	RCALL _Send_UART
	LDS  R26,_RAW_VAL_FLAG
	RJMP _Send_UART

;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:22 WORDS
SUBOPT_0xE:
	LDI  R30,LOW(0)
	STS  _MULTIPLY_COUNTER,R30
	STS  _MULTIPLY_COUNTER+1,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0xF:
	__GETW2MN _MOV_AVG,10
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x10:
	__GETW1MN _MOV_AVG,10
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x11:
	SUBI R30,LOW(255)
	SBCI R31,HIGH(255)
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x12:
	__PUTW1MN _MOV_AVG,10
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0x13:
	LDI  R26,LOW(_MULTIPLY_COUNTER)
	LDI  R27,HIGH(_MULTIPLY_COUNTER)
	RJMP SUBOPT_0x1

;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0x14:
	LDS  R26,_MULTIPLY_COUNTER
	RJMP _Send_UART

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x15:
	RCALL _Send_UART
	RJMP SUBOPT_0xE

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x16:
	__GETW2MN _MOV_AVG,12
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x17:
	__GETW1MN _MOV_AVG,12
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x18:
	__PUTW1MN _MOV_AVG,12
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x19:
	__GETW2MN _MOV_AVG,14
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x1A:
	__GETW1MN _MOV_AVG,14
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x1B:
	__PUTW1MN _MOV_AVG,14
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x1C:
	__GETW2MN _MOV_AVG,16
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x1D:
	__GETW1MN _MOV_AVG,16
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x1E:
	__PUTW1MN _MOV_AVG,16
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x1F:
	LDS  R26,_TCS3200_TOTAL_SUM
	LDS  R27,_TCS3200_TOTAL_SUM+1
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x20:
	STS  _TCS3200_TOTAL_SUM,R30
	STS  _TCS3200_TOTAL_SUM+1,R31
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x21:
	RCALL _Send_UART
	LDS  R26,_TRACER_STAT
	RJMP _Send_UART

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:5 WORDS
SUBOPT_0x22:
	RCALL _TCS3200_GetRule
	LDS  R26,_COMMAND_FLAG_A
	RCALL _Send_UART
	LDS  R26,_COMMAND_FLAG_B
	RCALL _Send_UART
	MOV  R26,R4
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:5 WORDS
SUBOPT_0x23:
	STS  _Threshold_Diff,R30
	STS  _Threshold_Diff+1,R31
	LDS  R26,_Threshold_Diff
	LDS  R27,_Threshold_Diff+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 36 TIMES, CODE SIZE REDUCTION:103 WORDS
SUBOPT_0x24:
	LDS  R26,_Threshold_Diff
	LDS  R27,_Threshold_Diff+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x25:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0xFB)
	LDI  R30,HIGH(0xFB)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x26:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0xC9)
	LDI  R30,HIGH(0xC9)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x27:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x97)
	LDI  R30,HIGH(0x97)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x28:
	RCALL SUBOPT_0x24
	CPI  R26,LOW(0x65)
	LDI  R30,HIGH(0x65)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x29:
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x2A:
	__GETWRN 16,17,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x2B:
	__CPWRN 16,17,5
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0x2C:
	MOVW R30,R16
	MOVW R26,R28
	ADIW R26,4
	LSL  R30
	ROL  R31
	ADD  R30,R26
	ADC  R31,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x2D:
	__ADDWRN 16,17,1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:42 WORDS
SUBOPT_0x2E:
	LDD  R30,Y+6
	LDD  R31,Y+6+1
	LDD  R26,Y+4
	LDD  R27,Y+4+1
	ADD  R30,R26
	ADC  R31,R27
	LDD  R26,Y+8
	LDD  R27,Y+8+1
	ADD  R30,R26
	ADC  R31,R27
	LDD  R26,Y+10
	LDD  R27,Y+10+1
	ADD  R30,R26
	ADC  R31,R27
	LDD  R26,Y+12
	LDD  R27,Y+12+1
	ADD  R30,R26
	ADC  R31,R27
	MOVW R18,R30
	MOVW R26,R18
	LDI  R30,LOW(5)
	LDI  R31,HIGH(5)
	RCALL __DIVW21
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x2F:
	LDS  R30,_TRACER_THRESHOLD
	LDS  R31,_TRACER_THRESHOLD+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x30:
	CP   R26,R30
	CPC  R27,R31
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x31:
	LDI  R26,LOW(0)
	LDI  R27,0
	RJMP _Tracer_Sampling

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x32:
	LDI  R26,LOW(1)
	LDI  R27,0
	RJMP _Tracer_Sampling

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x33:
	LDI  R26,LOW(2)
	LDI  R27,0
	RJMP _Tracer_Sampling

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x34:
	RCALL SUBOPT_0x29
	STD  Z+0,R26
	STD  Z+1,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:3 WORDS
SUBOPT_0x35:
	LDS  R26,_TCS3200_Pulse_R
	LDS  R27,_TCS3200_Pulse_R+1
	ADD  R30,R26
	ADC  R31,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:3 WORDS
SUBOPT_0x36:
	LDS  R26,_TCS3200_Pulse_G
	LDS  R27,_TCS3200_Pulse_G+1
	ADD  R30,R26
	ADC  R31,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x37:
	ADD  R30,R26
	ADC  R31,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x38:
	LDS  R26,_TCS3200_Pulse_W
	LDS  R27,_TCS3200_Pulse_W+1
	RJMP SUBOPT_0x37

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:6 WORDS
SUBOPT_0x39:
	LDS  R30,_Threshold_BW
	LDS  R31,_Threshold_BW+1
	LDS  R26,_TCS3200_TOTAL_SUM
	LDS  R27,_TCS3200_TOTAL_SUM+1
	RJMP SUBOPT_0x30

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:6 WORDS
SUBOPT_0x3A:
	LDS  R30,_Threshold_BG
	LDS  R31,_Threshold_BG+1
	LDS  R26,_TCS3200_TOTAL_SUM
	LDS  R27,_TCS3200_TOTAL_SUM+1
	RJMP SUBOPT_0x30


	.CSEG
_delay_ms:
	adiw r26,0
	breq __delay_ms1
__delay_ms0:
	__DELAY_USW 0xFA0
	wdr
	sbiw r26,1
	brne __delay_ms0
__delay_ms1:
	ret

__ANEGW1:
	NEG  R31
	NEG  R30
	SBCI R31,0
	RET

__DIVW21U:
	CLR  R0
	CLR  R1
	LDI  R25,16
__DIVW21U1:
	LSL  R26
	ROL  R27
	ROL  R0
	ROL  R1
	SUB  R0,R30
	SBC  R1,R31
	BRCC __DIVW21U2
	ADD  R0,R30
	ADC  R1,R31
	RJMP __DIVW21U3
__DIVW21U2:
	SBR  R26,1
__DIVW21U3:
	DEC  R25
	BRNE __DIVW21U1
	MOVW R30,R26
	MOVW R26,R0
	RET

__DIVW21:
	RCALL __CHKSIGNW
	RCALL __DIVW21U
	BRTC __DIVW211
	RCALL __ANEGW1
__DIVW211:
	RET

__CHKSIGNW:
	CLT
	SBRS R31,7
	RJMP __CHKSW1
	RCALL __ANEGW1
	SET
__CHKSW1:
	SBRS R27,7
	RJMP __CHKSW2
	COM  R26
	COM  R27
	ADIW R26,1
	BLD  R0,0
	INC  R0
	BST  R0,0
__CHKSW2:
	RET

__EEPROMWRW:
	RCALL __EEPROMWRB
	ADIW R26,1
	PUSH R30
	MOV  R30,R31
	RCALL __EEPROMWRB
	POP  R30
	SBIW R26,1
	RET

__EEPROMWRB:
	SBIS EECR,EEWE
	RJMP __EEPROMWRB1
	WDR
	RJMP __EEPROMWRB
__EEPROMWRB1:
	IN   R25,SREG
	CLI
	OUT  EEARL,R26
	OUT  EEARH,R27
	SBI  EECR,EERE
	IN   R24,EEDR
	CP   R30,R24
	BREQ __EEPROMWRB0
	OUT  EEDR,R30
	SBI  EECR,EEMWE
	SBI  EECR,EEWE
__EEPROMWRB0:
	OUT  SREG,R25
	RET

__SAVELOCR6:
	ST   -Y,R21
__SAVELOCR5:
	ST   -Y,R20
__SAVELOCR4:
	ST   -Y,R19
__SAVELOCR3:
	ST   -Y,R18
__SAVELOCR2:
	ST   -Y,R17
	ST   -Y,R16
	RET

__LOADLOCR6:
	LDD  R21,Y+5
__LOADLOCR5:
	LDD  R20,Y+4
__LOADLOCR4:
	LDD  R19,Y+3
__LOADLOCR3:
	LDD  R18,Y+2
__LOADLOCR2:
	LDD  R17,Y+1
	LD   R16,Y
	RET

__INITLOCB:
__INITLOCW:
	ADD  R26,R28
	ADC  R27,R29
__INITLOC0:
	LPM  R0,Z+
	ST   X+,R0
	DEC  R24
	BRNE __INITLOC0
	RET

;END OF CODE MARKER
__END_OF_CODE:
