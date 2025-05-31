
;CodeVisionAVR C Compiler V2.05.3 Standard
;(C) Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
;http://www.hpinfotech.com

;Chip type                : ATmega8
;Program type             : Application
;Clock frequency          : 16,000000 MHz
;Memory model             : Small
;Optimize for             : Size
;(s)printf features       : int, width
;(s)scanf features        : int, width
;External RAM size        : 0
;Data Stack size          : 256 byte(s)
;Heap size                : 0 byte(s)
;Promote 'char' to 'int'  : Yes
;'char' is unsigned       : Yes
;8 bit enums              : Yes
;Global 'const' stored in FLASH     : No
;Enhanced function parameter passing: Yes
;Enhanced core instructions         : On
;Smart register allocation          : On
;Automatic register allocation      : On

	#pragma AVRPART ADMIN PART_NAME ATmega8
	#pragma AVRPART MEMORY PROG_FLASH 8192
	#pragma AVRPART MEMORY EEPROM 512
	#pragma AVRPART MEMORY INT_SRAM SIZE 1119
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
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMRDW
	ICALL
	.ENDM

	.MACRO __GETW1STACK
	IN   R26,SPL
	IN   R27,SPH
	ADIW R26,@0+1
	LD   R30,X+
	LD   R31,X
	.ENDM

	.MACRO __GETD1STACK
	IN   R26,SPL
	IN   R27,SPH
	ADIW R26,@0+1
	LD   R30,X+
	LD   R31,X+
	LD   R22,X
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
	.DEF _Threshold_White=R6
	.DEF _Threshold_Black=R8
	.DEF _Threshold_Gray=R10
	.DEF _TRACER_GRAYDATA=R12

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

_0x3:
	.DB  0x41,0x7
_0x4:
	.DB  0xB4,0x1
_0x5:
	.DB  0x90
_0x6:
	.DB  0x36
_0x7:
	.DB  0x3C
_0x8:
	.DB  0x3E
_0x9:
	.DB  0x7C
_0xA:
	.DB  0x29
_0xB:
	.DB  0x2A
_0xC:
	.DB  0x2B
_0xD:
	.DB  0x2C
_0xE:
	.DB  0x2D
_0xF:
	.DB  0x2E
_0x10:
	.DB  0x35
_0x11:
	.DB  0x5E
_0x12:
	.DB  0x53
_0x13:
	.DB  0x41
_0x14:
	.DB  0x42
_0x15:
	.DB  0x58
_0x16:
	.DB  0x5E
_0x17:
	.DB  0x41
_0x18:
	.DB  0x42
_0x19:
	.DB  0x43
_0x1A:
	.DB  0x5A
_0x1B:
	.DB  0x58
_0x1C:
	.DB  0x46
_0x1D:
	.DB  0x47
_0x1E:
	.DB  0x48
_0x1F:
	.DB  0x49
_0x20:
	.DB  0x4A
_0x21:
	.DB  0x4B
_0x22:
	.DB  0x4D
_0x23:
	.DB  0x4C
_0x24:
	.DB  0x52
_0x25:
	.DB  0x53
_0x26:
	.DB  0x1
_0x27:
	.DB  0xD0,0x7
_0x28:
	.DB  0x3F,0xC
_0x29:
	.DB  0x52
_0xD2:
	.DB  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
	.DB  0x0,0x0
_0x135:
	.DB  0x0,0x0
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
	.DW  _Threshold_BW
	.DW  _0x3*2

	.DW  0x02
	.DW  _Threshold_BG
	.DW  _0x4*2

	.DW  0x01
	.DW  _TRACER_THRESHOLD_UP
	.DW  _0x5*2

	.DW  0x01
	.DW  _TRACER_THRESHOLD_DOWN
	.DW  _0x6*2

	.DW  0x01
	.DW  _COMMAND_FLAG_A
	.DW  _0x7*2

	.DW  0x01
	.DW  _COMMAND_FLAG_B
	.DW  _0x8*2

	.DW  0x01
	.DW  _CMD_IDLE
	.DW  _0x16*2

	.DW  0x01
	.DW  _RAW_VAL_FLAG
	.DW  _0x29*2

	.DW  0x02
	.DW  0x04
	.DW  _0x135*2

	.DW  0x01
	.DW  __seed_G101
	.DW  _0x2020060*2

_0xFFFFFFFF:
	.DW  0

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
	BRNE _0x2A
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
	BRNE _0x2B
	LDI  R30,LOW(0)
	STS  _rx_wr_index,R30
; 0000 0064    if (++rx_counter == RX_BUFFER_SIZE)
_0x2B:
	LDS  R26,_rx_counter
	SUBI R26,-LOW(1)
	STS  _rx_counter,R26
	CPI  R26,LOW(0x8)
	BRNE _0x2C
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
_0x2C:
; 0000 006B }
_0x2A:
	RCALL __LOADLOCR2P
	LD   R30,Y+
	OUT  SREG,R30
	LD   R31,Y+
	LD   R30,Y+
	LD   R26,Y+
	RETI
;
;#ifndef _DEBUG_TERMINAL_IO_
;// Get a character from the USART Receiver buffer
;#define _ALTERNATE_GETCHAR_
;#pragma used+
;char getchar(void)
; 0000 0072 {
_getchar:
; 0000 0073 char data;
; 0000 0074 while (rx_counter==0);
	ST   -Y,R17
;	data -> R17
_0x2D:
	LDS  R30,_rx_counter
	CPI  R30,0
	BREQ _0x2D
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
	BRNE _0x30
	LDI  R30,LOW(0)
	STS  _rx_rd_index,R30
; 0000 0078 #endif
; 0000 0079 #asm("cli")
_0x30:
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
;
;#define ADC_VREF_TYPE 0x60
;
;// Read the 8 most significant bits
;// of the AD conversion result
;unsigned char read_adc(unsigned char adc_input)
; 0000 0091 {
_read_adc:
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
_0x31:
	SBIS 0x6,4
	RJMP _0x31
; 0000 0099 ADCSRA|=0x10;
	SBI  0x6,4
; 0000 009A return ADCH;
	IN   R30,0x5
	RJMP _0x20A0003
; 0000 009B }
;
;// Declare your global variables here
;
;//int adc1,adc2,adc3;
;void main(void)
; 0000 00A1 {
_main:
; 0000 00A2 
; 0000 00A3     YUME_Initialization();
	RCALL _YUME_Initialization
; 0000 00A4     TCS3200_Config(3);
	LDI  R26,LOW(3)
	RCALL SUBOPT_0x2
	RCALL _TCS3200_Config
; 0000 00A5 
; 0000 00A6     while (1)
_0x34:
; 0000 00A7     {
; 0000 00A8 //        TRIGGER= getchar();
; 0000 00A9 //        printf("\r\r");
; 0000 00AA //        if(TRIGGER=='X')
; 0000 00AB //        {
; 0000 00AC //            Tracer_Sampling(FRONT);
; 0000 00AD //            Tracer_Sampling(MIDDLE);
; 0000 00AE //            Tracer_Sampling(REAR);
; 0000 00AF ////
; 0000 00B0 //            Tracer_GetRule();
; 0000 00B1 //
; 0000 00B2 //            //TCS3200_Sampling();
; 0000 00B3 ////            TCS3200_GetRule();
; 0000 00B4 //            TRIGGER=0;
; 0000 00B5 //        }
; 0000 00B6 
; 0000 00B7         Get_CMD();
	RCALL _Get_CMD
; 0000 00B8 //         adc1 = read_adc(0);
; 0000 00B9 //         adc2 = read_adc(1);
; 0000 00BA //         adc3 = read_adc(2);
; 0000 00BB //
; 0000 00BC //         printf("ADC 1 : %d \t",adc1);
; 0000 00BD //         printf("ADC 2 : %d \t",adc2);
; 0000 00BE //         printf("ADC 3 : %d \r",adc3);
; 0000 00BF //         delay_ms(10);
; 0000 00C0 
; 0000 00C1 
; 0000 00C2     }
	RJMP _0x34
; 0000 00C3 }
_0x37:
	RJMP _0x37
;
;
;void YUME_Initialization(void)
; 0000 00C7 {
_YUME_Initialization:
; 0000 00C8     // Declare your local variables here
; 0000 00C9 
; 0000 00CA     // Input/Output Ports initialization
; 0000 00CB     // Port B initialization
; 0000 00CC     // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=Out Func1=Out Func0=Out
; 0000 00CD     // State7=T State6=T State5=T State4=T State3=T State2=0 State1=0 State0=0
; 0000 00CE     PORTB=0x00;
	LDI  R30,LOW(0)
	OUT  0x18,R30
; 0000 00CF     DDRB=0x07;
	LDI  R30,LOW(7)
	OUT  0x17,R30
; 0000 00D0 
; 0000 00D1     // Port C initialization                                                        TRACER RGB PIN          D3 = GREEN
; 0000 00D2     // Func6=In Func5=Out Func4=Out Func3=Out Func2=In Func1=In Func0=In            C5      D3      D4      C5 = BLUE
; 0000 00D3     // State6=T State5=1 State4=0 State3=0 State2=T State1=T State0=T              0X20    0X08    0X10     D4 = RED
; 0000 00D4     PORTC=0x20; //BLUE
	LDI  R30,LOW(32)
	OUT  0x15,R30
; 0000 00D5     DDRC=0x38;
	LDI  R30,LOW(56)
	OUT  0x14,R30
; 0000 00D6 
; 0000 00D7     // Port D initialization
; 0000 00D8     // Func7=In Func6=In Func5=In Func4=Out Func3=Out Func2=In Func1=In Func0=In
; 0000 00D9     // State7=T State6=T State5=T State4=0 State3=0 State2=T State1=T State0=T
; 0000 00DA     PORTD=0x18;
	LDI  R30,LOW(24)
	OUT  0x12,R30
; 0000 00DB     DDRD=0x18;
	OUT  0x11,R30
; 0000 00DC 
; 0000 00DD     // Timer/Counter 0 initialization
; 0000 00DE     // Clock source: System Clock
; 0000 00DF     // Clock value: Timer 0 Stopped
; 0000 00E0     TCCR0=0x00;
	LDI  R30,LOW(0)
	OUT  0x33,R30
; 0000 00E1     TCNT0=0x00;
	OUT  0x32,R30
; 0000 00E2 
; 0000 00E3     // Timer/Counter 1 initialization
; 0000 00E4     // Clock source: System Clock
; 0000 00E5     // Clock value: Timer1 Stopped
; 0000 00E6     // Mode: Normal top=0xFFFF
; 0000 00E7     // OC1A output: Discon.
; 0000 00E8     // OC1B output: Discon.
; 0000 00E9     // Noise Canceler: Off
; 0000 00EA     // Input Capture on Falling Edge
; 0000 00EB     // Timer1 Overflow Interrupt: On
; 0000 00EC     // Input Capture Interrupt: Off
; 0000 00ED     // Compare A Match Interrupt: Off
; 0000 00EE     // Compare B Match Interrupt: Off
; 0000 00EF     TCCR1A=0x00;
	OUT  0x2F,R30
; 0000 00F0     TCCR1B=0x00;
	RCALL SUBOPT_0x3
; 0000 00F1     TCNT1H=0x00;
	LDI  R30,LOW(0)
	OUT  0x2D,R30
; 0000 00F2     TCNT1L=0x00;
	OUT  0x2C,R30
; 0000 00F3     ICR1H=0x00;
	OUT  0x27,R30
; 0000 00F4     ICR1L=0x00;
	OUT  0x26,R30
; 0000 00F5     OCR1AH=0x00;
	OUT  0x2B,R30
; 0000 00F6     OCR1AL=0x00;
	OUT  0x2A,R30
; 0000 00F7     OCR1BH=0x00;
	OUT  0x29,R30
; 0000 00F8     OCR1BL=0x00;
	OUT  0x28,R30
; 0000 00F9 
; 0000 00FA     // Timer/Counter 2 initialization
; 0000 00FB     // Clock source: System Clock
; 0000 00FC     // Clock value: Timer2 Stopped
; 0000 00FD     // Mode: Normal top=0xFF
; 0000 00FE     // OC2 output: Disconnected
; 0000 00FF     ASSR=0x00;
	OUT  0x22,R30
; 0000 0100     TCCR2=0x00;
	OUT  0x25,R30
; 0000 0101     TCNT2=0x00;
	OUT  0x24,R30
; 0000 0102     OCR2=0x00;
	OUT  0x23,R30
; 0000 0103 
; 0000 0104     // External Interrupt(s) initialization
; 0000 0105     // INT0: Off
; 0000 0106     // INT1: Off
; 0000 0107     MCUCR=0x00;
	OUT  0x35,R30
; 0000 0108 
; 0000 0109     // Timer(s)/Counter(s) Interrupt(s) initialization
; 0000 010A     TIMSK=0x04;
	LDI  R30,LOW(4)
	OUT  0x39,R30
; 0000 010B 
; 0000 010C     // USART initialization
; 0000 010D     // Communication Parameters: 8 Data, 1 Stop, No Parity
; 0000 010E     // USART Receiver: On
; 0000 010F     // USART Transmitter: On
; 0000 0110     // USART Mode: Asynchronous
; 0000 0111     // USART Baud Rate: 9600
; 0000 0112     UCSRA=0x00;
	LDI  R30,LOW(0)
	OUT  0xB,R30
; 0000 0113     UCSRB=0x98;
	LDI  R30,LOW(152)
	OUT  0xA,R30
; 0000 0114     UCSRC=0x86;
	LDI  R30,LOW(134)
	OUT  0x20,R30
; 0000 0115     UBRRH=0x00;
	LDI  R30,LOW(0)
	OUT  0x20,R30
; 0000 0116     UBRRL=0x67;
	LDI  R30,LOW(103)
	OUT  0x9,R30
; 0000 0117 
; 0000 0118     // Analog Comparator initialization
; 0000 0119     // Analog Comparator: Off
; 0000 011A     // Analog Comparator Input Capture by Timer/Counter 1: Off
; 0000 011B     ACSR=0x80;
	LDI  R30,LOW(128)
	OUT  0x8,R30
; 0000 011C     SFIOR=0x00;
	LDI  R30,LOW(0)
	OUT  0x30,R30
; 0000 011D 
; 0000 011E     // ADC initialization
; 0000 011F     // ADC Clock frequency: 500.000 kHz
; 0000 0120     // ADC Voltage Reference: AVCC pin
; 0000 0121     // Only the 8 most significant bits of
; 0000 0122     // the AD conversion result are used
; 0000 0123     ADMUX=ADC_VREF_TYPE & 0xff;
	LDI  R30,LOW(96)
	OUT  0x7,R30
; 0000 0124     ADCSRA=0x85;
	LDI  R30,LOW(133)
	OUT  0x6,R30
; 0000 0125 
; 0000 0126     // SPI initialization
; 0000 0127     // SPI disabled
; 0000 0128     SPCR=0x00;
	LDI  R30,LOW(0)
	OUT  0xD,R30
; 0000 0129 
; 0000 012A     // TWI initialization
; 0000 012B     // TWI disabled
; 0000 012C     TWCR=0x00;
	OUT  0x36,R30
; 0000 012D 
; 0000 012E     // Global enable interrupts
; 0000 012F     #asm("sei")
	sei
; 0000 0130 
; 0000 0131 }
	RET
;
;void Send_UART(unsigned char data)
; 0000 0134 {
_Send_UART:
; 0000 0135     while(!(UCSRA & (1<<UDRE))){};
	ST   -Y,R26
;	data -> Y+0
_0x38:
	SBIS 0xB,5
	RJMP _0x38
; 0000 0136     UDR=data;
	LD   R30,Y
	OUT  0xC,R30
; 0000 0137 }
_0x20A0003:
	ADIW R28,1
	RET
;
;
;void TCS3200_Config(unsigned int mode)
; 0000 013B {
_TCS3200_Config:
; 0000 013C     if(mode==0)         //output frequency scaling power down
	ST   -Y,R27
	ST   -Y,R26
;	mode -> Y+0
	LD   R30,Y
	LDD  R31,Y+1
	SBIW R30,0
	BRNE _0x3B
; 0000 013D     {
; 0000 013E         TCS3200_S0=0;
	CBI  0x18,0
; 0000 013F         TCS3200_S1=0;
	CBI  0x18,1
; 0000 0140     }
; 0000 0141     if(mode==1)         //output frequency scaling 1:50
_0x3B:
	LD   R26,Y
	LDD  R27,Y+1
	SBIW R26,1
	BRNE _0x40
; 0000 0142     {
; 0000 0143         TCS3200_S0=0;
	CBI  0x18,0
; 0000 0144         TCS3200_S1=1;
	SBI  0x18,1
; 0000 0145     }
; 0000 0146     if(mode==2)         //output frequency scaling 1:5
_0x40:
	LD   R26,Y
	LDD  R27,Y+1
	SBIW R26,2
	BRNE _0x45
; 0000 0147     {
; 0000 0148         TCS3200_S0=1;
	SBI  0x18,0
; 0000 0149         TCS3200_S1=0;
	CBI  0x18,1
; 0000 014A     }
; 0000 014B     if(mode==3)         //output frequency scaling 1:1
_0x45:
	LD   R26,Y
	LDD  R27,Y+1
	SBIW R26,3
	BRNE _0x4A
; 0000 014C     {
; 0000 014D         TCS3200_S0=1;
	SBI  0x18,0
; 0000 014E         TCS3200_S1=1;
	SBI  0x18,1
; 0000 014F     }
; 0000 0150     return;
_0x4A:
	ADIW R28,2
	RET
; 0000 0151 }
;
;
;void TCS3200Read(void)
; 0000 0155 {
_TCS3200Read:
; 0000 0156     TCS3200Read_R();
	RCALL _TCS3200Read_R
; 0000 0157     TCS3200Read_G();
	RCALL _TCS3200Read_G
; 0000 0158     TCS3200Read_B();
	RCALL _TCS3200Read_B
; 0000 0159     TCS3200Read_W();
	RCALL _TCS3200Read_W
; 0000 015A 
; 0000 015B //    printf("Red  : %d \t",(int)TCS3200_Pulse_R);
; 0000 015C //    printf("Green: %d \t",(int)TCS3200_Pulse_G);
; 0000 015D //    printf("Blue: %d \t",(int)TCS3200_Pulse_B);
; 0000 015E //    printf("White: %d \r",(int)TCS3200_Pulse_W);
; 0000 015F }
	RET
;
;int TCS3200Read_R(void)
; 0000 0162 {
_TCS3200Read_R:
; 0000 0163      TCS3200_S2=0;
	CBI  0x18,2
; 0000 0164      TCS3200_S3=0;
	RCALL SUBOPT_0x4
; 0000 0165      delay_ms(5);
; 0000 0166      TCCR1B=0x06;
; 0000 0167      delay_ms(5);
; 0000 0168      TCCR1B=0x00;
; 0000 0169      TCS3200_Pulse_R=((int)TCS3200_COUNTER*256)+(int)TCNT1;
	RCALL SUBOPT_0x5
	STS  _TCS3200_Pulse_R,R30
	STS  _TCS3200_Pulse_R+1,R31
; 0000 016A      TCNT1=0;
	RCALL SUBOPT_0x6
; 0000 016B      TCS3200_COUNTER=0;
; 0000 016C      delay_ms(10);
; 0000 016D      return TCS3200_Pulse_R;
	LDS  R30,_TCS3200_Pulse_R
	LDS  R31,_TCS3200_Pulse_R+1
	RET
; 0000 016E 
; 0000 016F }
;
;int TCS3200Read_G(void)
; 0000 0172 {
_TCS3200Read_G:
; 0000 0173      TCS3200_S2=1;
	SBI  0x18,2
; 0000 0174      TCS3200_S3=1;
	RCALL SUBOPT_0x7
; 0000 0175      delay_ms(5);
; 0000 0176      TCCR1B=0x06;
; 0000 0177      delay_ms(5);
; 0000 0178      TCCR1B=0x00;
; 0000 0179      TCS3200_Pulse_G=((int)TCS3200_COUNTER*256)+(int)TCNT1;
	RCALL SUBOPT_0x5
	STS  _TCS3200_Pulse_G,R30
	STS  _TCS3200_Pulse_G+1,R31
; 0000 017A //    TCS3200_Pulse_G=((int)MIDDLE_COUNTER*65536)+(int)TCNT1;
; 0000 017B      TCNT1=0;
	RCALL SUBOPT_0x6
; 0000 017C      TCS3200_COUNTER=0;
; 0000 017D      delay_ms(10);
; 0000 017E      return TCS3200_Pulse_G;
	RCALL SUBOPT_0x8
	RET
; 0000 017F 
; 0000 0180 }
;
;int TCS3200Read_B(void)
; 0000 0183 {
_TCS3200Read_B:
; 0000 0184      TCS3200_S2=0;
	CBI  0x18,2
; 0000 0185      TCS3200_S3=1;
	RCALL SUBOPT_0x7
; 0000 0186      delay_ms(5);
; 0000 0187      TCCR1B=0x06;
; 0000 0188      delay_ms(5);
; 0000 0189      TCCR1B=0x00;
; 0000 018A      TCS3200_Pulse_B=((int)TCS3200_COUNTER*256)+(int)TCNT1;
	RCALL SUBOPT_0x5
	STS  _TCS3200_Pulse_B,R30
	STS  _TCS3200_Pulse_B+1,R31
; 0000 018B //     TCS3200_Pulse_B=((int)TCS3200_COUNTER*65536)+(int)TCNT1;
; 0000 018C      TCNT1=0;
	RCALL SUBOPT_0x6
; 0000 018D      TCS3200_COUNTER=0;
; 0000 018E      delay_ms(10);
; 0000 018F      return TCS3200_Pulse_B;
	RCALL SUBOPT_0x9
	RET
; 0000 0190 
; 0000 0191 }
;
;int TCS3200Read_W(void)
; 0000 0194 {
_TCS3200Read_W:
; 0000 0195      TCS3200_S2=1;
	SBI  0x18,2
; 0000 0196      TCS3200_S3=0;
	RCALL SUBOPT_0x4
; 0000 0197      delay_ms(5);
; 0000 0198      TCCR1B=0x06;
; 0000 0199      delay_ms(5);
; 0000 019A      TCCR1B=0x00;
; 0000 019B      TCS3200_Pulse_W=((int)TCS3200_COUNTER*256)+(int)TCNT1;
	RCALL SUBOPT_0x5
	STS  _TCS3200_Pulse_W,R30
	STS  _TCS3200_Pulse_W+1,R31
; 0000 019C //    TCS3200_Pulse_W=((int)TCS3200_COUNTER*65536)+(int)TCNT1;
; 0000 019D      TCNT1=0;
	RCALL SUBOPT_0x6
; 0000 019E      TCS3200_COUNTER=0;
; 0000 019F      delay_ms(10);
; 0000 01A0      return TCS3200_Pulse_W;
	RCALL SUBOPT_0xA
	RET
; 0000 01A1 
; 0000 01A2 }
;
;
;
;/*
; * DATA PACKET STRUCTURE
; * [COMMAND_FLAG_A] [COMMAND_FLAG_B] [F_DETECTED_COLOUR] [M_DETECTED_COLOUR] [TRACER_STAT] [COLOUR_STAT]
; *
;*/
;void Send_TCS3200_Conclusion(void)
; 0000 01AC {
; 0000 01AD     Send_UART(COMMAND_FLAG_A);
; 0000 01AE     Send_UART(COMMAND_FLAG_B);
; 0000 01AF     Send_UART(DETECTED_COLOUR);
; 0000 01B0     Send_UART(TRACER_STAT);
; 0000 01B1 }
;
;void Get_CMD(void)
; 0000 01B4 {
_Get_CMD:
; 0000 01B5     TCS3200_CMD[TEMPORARY] = getchar();;
	RCALL _getchar
	__POINTW2MN _TCS3200_CMD,4
	RCALL SUBOPT_0xB
; 0000 01B6 
; 0000 01B7     if(TCS3200_CMD[TEMPORARY]!=CMD_IDLE)
	__GETW2MN _TCS3200_CMD,4
	LDS  R30,_CMD_IDLE
	LDS  R31,_CMD_IDLE+1
	RCALL SUBOPT_0xC
	BREQ _0x5F
; 0000 01B8     {
; 0000 01B9         TCS3200_CMD[1] = TCS3200_CMD[0];
	RCALL SUBOPT_0xD
	__PUTW1MN _TCS3200_CMD,2
; 0000 01BA         TCS3200_CMD[0] = TCS3200_CMD[TEMPORARY];
	__GETW1MN _TCS3200_CMD,4
	STS  _TCS3200_CMD,R30
	STS  _TCS3200_CMD+1,R31
; 0000 01BB     }
; 0000 01BC 
; 0000 01BD     //Switch-case version
; 0000 01BE     switch(TCS3200_CMD[0])
_0x5F:
	RCALL SUBOPT_0xD
; 0000 01BF     {
; 0000 01C0         case TCS3200_CMD_SEND_RAW:{
	CPI  R30,LOW(0x41)
	LDI  R26,HIGH(0x41)
	CPC  R31,R26
	BREQ PC+2
	RJMP _0x63
; 0000 01C1 ////                                TCS3200_Sampling();
; 0000 01C2                                     Send_UART(COMMAND_FLAG_A);
	RCALL SUBOPT_0xE
; 0000 01C3                                     Send_UART(COMMAND_FLAG_B);
; 0000 01C4                                     Send_UART(RAW_VAL_FLAG);
; 0000 01C5 
; 0000 01C6                                     //RED FILTER RAW VALUE
; 0000 01C7                                     MULTIPLY_COUNTER=0;
	RCALL SUBOPT_0xF
; 0000 01C8                                     if(MOV_AVG[TCS3200_RED]>255)
	RCALL SUBOPT_0x10
	BRLT _0x64
; 0000 01C9                                     {
; 0000 01CA                                         while( MOV_AVG[TCS3200_RED] >255)
_0x65:
	RCALL SUBOPT_0x10
	BRLT _0x67
; 0000 01CB                                         {
; 0000 01CC                                            MOV_AVG[TCS3200_RED]-=255;
	__GETW1MN _MOV_AVG,10
	RCALL SUBOPT_0x11
	__PUTW1MN _MOV_AVG,10
; 0000 01CD                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x12
; 0000 01CE                                         }
	RJMP _0x65
_0x67:
; 0000 01CF                                     }
; 0000 01D0                                     Send_UART(MULTIPLY_COUNTER);
_0x64:
	RCALL SUBOPT_0x13
; 0000 01D1                                     Send_UART(MOV_AVG[TCS3200_RED]);
	__GETB2MN _MOV_AVG,10
	RCALL SUBOPT_0x14
; 0000 01D2 
; 0000 01D3                                     //GREEN FILTER RAW VALUE
; 0000 01D4                                     MULTIPLY_COUNTER=0;
; 0000 01D5                                     if(MOV_AVG[TCS3200_GREEN]>255)
	RCALL SUBOPT_0x15
	BRLT _0x68
; 0000 01D6                                     {
; 0000 01D7                                         while( MOV_AVG[TCS3200_GREEN] >255)
_0x69:
	RCALL SUBOPT_0x15
	BRLT _0x6B
; 0000 01D8                                         {
; 0000 01D9                                            MOV_AVG[TCS3200_GREEN]-=255;
	__GETW1MN _MOV_AVG,12
	RCALL SUBOPT_0x11
	__PUTW1MN _MOV_AVG,12
; 0000 01DA                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x12
; 0000 01DB                                         }
	RJMP _0x69
_0x6B:
; 0000 01DC                                     }
; 0000 01DD                                     Send_UART(MULTIPLY_COUNTER);
_0x68:
	RCALL SUBOPT_0x13
; 0000 01DE                                     Send_UART(MOV_AVG[TCS3200_GREEN]);
	__GETB2MN _MOV_AVG,12
	RCALL SUBOPT_0x14
; 0000 01DF 
; 0000 01E0                                     //BLUE FILTER RAW VALUE
; 0000 01E1                                     MULTIPLY_COUNTER=0;
; 0000 01E2                                     if(MOV_AVG[TCS3200_BLUE]>255)
	RCALL SUBOPT_0x16
	BRLT _0x6C
; 0000 01E3                                     {
; 0000 01E4                                         while( MOV_AVG[TCS3200_BLUE] >255)
_0x6D:
	RCALL SUBOPT_0x16
	BRLT _0x6F
; 0000 01E5                                         {
; 0000 01E6                                            MOV_AVG[TCS3200_BLUE]-=255;
	__GETW1MN _MOV_AVG,14
	RCALL SUBOPT_0x11
	__PUTW1MN _MOV_AVG,14
; 0000 01E7                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x12
; 0000 01E8                                         }
	RJMP _0x6D
_0x6F:
; 0000 01E9                                     }
; 0000 01EA                                     Send_UART(MULTIPLY_COUNTER);
_0x6C:
	RCALL SUBOPT_0x13
; 0000 01EB                                     Send_UART(MOV_AVG[TCS3200_BLUE]);
	__GETB2MN _MOV_AVG,14
	RCALL SUBOPT_0x14
; 0000 01EC 
; 0000 01ED                                     //WHITE FILTER RAW VALUE
; 0000 01EE                                     MULTIPLY_COUNTER=0;
; 0000 01EF                                     if(MOV_AVG[TCS3200_WHITE]>255)
	RCALL SUBOPT_0x17
	BRLT _0x70
; 0000 01F0                                     {
; 0000 01F1                                         while( MOV_AVG[TCS3200_WHITE] >255)
_0x71:
	RCALL SUBOPT_0x17
	BRLT _0x73
; 0000 01F2                                         {
; 0000 01F3                                            MOV_AVG[TCS3200_WHITE]-=255;
	__GETW1MN _MOV_AVG,16
	RCALL SUBOPT_0x11
	__PUTW1MN _MOV_AVG,16
; 0000 01F4                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x12
; 0000 01F5                                         }
	RJMP _0x71
_0x73:
; 0000 01F6                                     }
; 0000 01F7                                     Send_UART(MULTIPLY_COUNTER);
_0x70:
	RCALL SUBOPT_0x13
; 0000 01F8                                     Send_UART(MOV_AVG[TCS3200_WHITE]);
	__GETB2MN _MOV_AVG,16
	RCALL SUBOPT_0x14
; 0000 01F9 
; 0000 01FA                                     //SUM FILTER RAW VALUE
; 0000 01FB                                     MULTIPLY_COUNTER=0;
; 0000 01FC                                     if(TCS3200_TOTAL_SUM>255)
	RCALL SUBOPT_0x18
	BRLT _0x74
; 0000 01FD                                     {
; 0000 01FE                                         while( TCS3200_TOTAL_SUM >255)
_0x75:
	RCALL SUBOPT_0x18
	BRLT _0x77
; 0000 01FF                                         {
; 0000 0200                                            TCS3200_TOTAL_SUM-=255;
	LDS  R30,_TCS3200_TOTAL_SUM
	LDS  R31,_TCS3200_TOTAL_SUM+1
	RCALL SUBOPT_0x11
	STS  _TCS3200_TOTAL_SUM,R30
	STS  _TCS3200_TOTAL_SUM+1,R31
; 0000 0201                                            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x12
; 0000 0202                                         }
	RJMP _0x75
_0x77:
; 0000 0203                                     }
; 0000 0204                                     Send_UART(MULTIPLY_COUNTER);
_0x74:
	RCALL SUBOPT_0x13
; 0000 0205                                     Send_UART(TCS3200_TOTAL_SUM);
	LDS  R26,_TCS3200_TOTAL_SUM
	RCALL _Send_UART
; 0000 0206 
; 0000 0207                                 }break;
	RJMP _0x62
; 0000 0208 
; 0000 0209 
; 0000 020A         case TRACER_CMD_SEND_RAW:{
_0x63:
	CPI  R30,LOW(0x42)
	LDI  R26,HIGH(0x42)
	CPC  R31,R26
	BRNE _0x78
; 0000 020B                                         Tracer_GetRule();
	RCALL _Tracer_GetRule
; 0000 020C                                         Send_UART(COMMAND_FLAG_A);
	RCALL SUBOPT_0xE
; 0000 020D                                         Send_UART(COMMAND_FLAG_B);
; 0000 020E                                         Send_UART(RAW_VAL_FLAG);
; 0000 020F                                         Send_UART(TRACER[FRONT]);
	LDS  R26,_TRACER
	RCALL _Send_UART
; 0000 0210                                         Send_UART(TRACER[MIDDLE]);
	__GETB2MN _TRACER,2
	RCALL _Send_UART
; 0000 0211                                         Send_UART(TRACER[REAR]);
	__GETB2MN _TRACER,4
	RCALL SUBOPT_0x19
; 0000 0212                                         Send_UART(TRACER_STAT);             //yang akan dirubah tracer stat
; 0000 0213                                         Send_UART(TRACER_THRESHOLD_UP);
	LDS  R26,_TRACER_THRESHOLD_UP
	RCALL _Send_UART
; 0000 0214                                         Send_UART(TRACER_THRESHOLD_DOWN);
	LDS  R26,_TRACER_THRESHOLD_DOWN
	RCALL _Send_UART
; 0000 0215 
; 0000 0216                                 }break;
	RJMP _0x62
; 0000 0217 
; 0000 0218         case HYBRID_CMD_SEND_CONCLUSION:
_0x78:
	CPI  R30,LOW(0x43)
	LDI  R26,HIGH(0x43)
	CPC  R31,R26
	BRNE _0x79
; 0000 0219                                     {
; 0000 021A                                         Tracer_GetRule();
	RCALL SUBOPT_0x1A
; 0000 021B                                         //TCS3200_GetRule();
; 0000 021C                                         Send_UART(COMMAND_FLAG_A);
; 0000 021D                                         Send_UART(COMMAND_FLAG_B);
; 0000 021E                                         Send_UART(DETECTED_COLOUR);
	MOV  R26,R4
	RCALL SUBOPT_0x19
; 0000 021F                                         Send_UART(TRACER_STAT);
; 0000 0220 //                                        Send_UART(TRACER[FRONT]);
; 0000 0221 //                                        Send_UART(TRACER[MIDDLE]);
; 0000 0222 //                                        Send_UART(TRACER[REAR]);
; 0000 0223 
; 0000 0224                                     }break;
	RJMP _0x62
; 0000 0225         case CMD_GET_TCS3200            :
_0x79:
	CPI  R30,LOW(0x52)
	LDI  R26,HIGH(0x52)
	CPC  R31,R26
	BRNE _0x7A
; 0000 0226                                     {
; 0000 0227 //                                        TCS3200_GetRule();
; 0000 0228                                         Send_UART(COMMAND_FLAG_A);
	LDS  R26,_COMMAND_FLAG_A
	RCALL _Send_UART
; 0000 0229                                         Send_UART(COMMAND_FLAG_B);
	LDS  R26,_COMMAND_FLAG_B
	RCALL _Send_UART
; 0000 022A                                         Send_UART(DETECTED_COLOUR);
	MOV  R26,R4
	RCALL _Send_UART
; 0000 022B                                         Send_UART(0x00);
	LDI  R26,LOW(0)
	RCALL _Send_UART
; 0000 022C                                     }break;
	RJMP _0x62
; 0000 022D         case CMD_GET_TRACER            :
_0x7A:
	CPI  R30,LOW(0x53)
	LDI  R26,HIGH(0x53)
	CPC  R31,R26
	BRNE _0x7B
; 0000 022E                                     {
; 0000 022F                                         Tracer_GetRule();
	RCALL SUBOPT_0x1A
; 0000 0230                                         Send_UART(COMMAND_FLAG_A);
; 0000 0231                                         Send_UART(COMMAND_FLAG_B);
; 0000 0232                                         Send_UART(0x00);
	LDI  R26,LOW(0)
	RCALL SUBOPT_0x19
; 0000 0233                                         Send_UART(TRACER_STAT);
; 0000 0234                                     }break;
	RJMP _0x62
; 0000 0235 
; 0000 0236         case TCS3200_CMD_SAVE_EEPROM:
_0x7B:
	CPI  R30,LOW(0x5A)
	LDI  R26,HIGH(0x5A)
	CPC  R31,R26
	BRNE _0x7C
; 0000 0237                                     {
; 0000 0238                                         TCS3200Read();
	RCALL _TCS3200Read
; 0000 0239                                         EEPROM_A= TCS3200_Pulse_G;
	RCALL SUBOPT_0x8
	LDI  R26,LOW(_EEPROM_A)
	LDI  R27,HIGH(_EEPROM_A)
	RCALL __EEPROMWRW
; 0000 023A                                         EEPROM_B= TCS3200_Pulse_B;
	RCALL SUBOPT_0x9
	LDI  R26,LOW(_EEPROM_B)
	LDI  R27,HIGH(_EEPROM_B)
	RCALL __EEPROMWRW
; 0000 023B                                         EEPROM_C= TCS3200_Pulse_W;
	RCALL SUBOPT_0xA
	LDI  R26,LOW(_EEPROM_C)
	LDI  R27,HIGH(_EEPROM_C)
	RCALL __EEPROMWRW
; 0000 023C                                         EEPROM_D= TCS3200_Pulse_Sum;
	LDS  R30,_TCS3200_Pulse_Sum
	LDS  R31,_TCS3200_Pulse_Sum+1
	LDI  R26,LOW(_EEPROM_D)
	LDI  R27,HIGH(_EEPROM_D)
	RCALL __EEPROMWRW
; 0000 023D                                     }break;
	RJMP _0x62
; 0000 023E 
; 0000 023F         case HYBRID_CMD_SEND_THRESHOLD:
_0x7C:
	CPI  R30,LOW(0x58)
	LDI  R26,HIGH(0x58)
	CPC  R31,R26
	BRNE _0x7D
; 0000 0240                                     {
; 0000 0241                                         Send_Threshold();
	RCALL _Send_Threshold
; 0000 0242                                     }break;
	RJMP _0x62
; 0000 0243 
; 0000 0244         case TCS3200_CALIBRATE_WHITE:
_0x7D:
	CPI  R30,LOW(0x46)
	LDI  R26,HIGH(0x46)
	CPC  R31,R26
	BRNE _0x7E
; 0000 0245                                     {
; 0000 0246 //                                        TCS3200_Sampling();
; 0000 0247                                         Threshold_White= TCS3200_TOTAL_SUM;
	__GETWRMN 6,7,0,_TCS3200_TOTAL_SUM
; 0000 0248                                     }break;
	RJMP _0x62
; 0000 0249         case TCS3200_CALIBRATE_BLACK:
_0x7E:
	CPI  R30,LOW(0x47)
	LDI  R26,HIGH(0x47)
	CPC  R31,R26
	BRNE _0x7F
; 0000 024A                                     {
; 0000 024B 
; 0000 024C //                                        TCS3200_Sampling();
; 0000 024D                                         Threshold_Black = TCS3200_TOTAL_SUM;
	__GETWRMN 8,9,0,_TCS3200_TOTAL_SUM
; 0000 024E                                     }break;
	RJMP _0x62
; 0000 024F         case TCS3200_CALIBRATE_GRAY:
_0x7F:
	CPI  R30,LOW(0x48)
	LDI  R26,HIGH(0x48)
	CPC  R31,R26
	BRNE _0x80
; 0000 0250                                     {
; 0000 0251 
; 0000 0252 //                                        TCS3200_Sampling();
; 0000 0253                                         Threshold_Gray = TCS3200_TOTAL_SUM;
	__GETWRMN 10,11,0,_TCS3200_TOTAL_SUM
; 0000 0254                                     }break;
	RJMP _0x62
; 0000 0255         case TCS3200_CALIBRATE_GETRULE:
_0x80:
	CPI  R30,LOW(0x49)
	LDI  R26,HIGH(0x49)
	CPC  R31,R26
	BREQ PC+2
	RJMP _0x81
; 0000 0256                                     {
; 0000 0257                                         Threshold_Diff = Threshold_White-Threshold_Gray;
	MOVW R30,R6
	SUB  R30,R10
	SBC  R31,R11
	RCALL SUBOPT_0x1B
; 0000 0258 
; 0000 0259                                         if(Threshold_Diff>1400)
	CPI  R26,LOW(0x579)
	LDI  R30,HIGH(0x579)
	CPC  R27,R30
	BRLT _0x82
; 0000 025A                                         {
; 0000 025B                                             Threshold_BW = Threshold_Gray + 1390;
	MOVW R30,R10
	SUBI R30,LOW(-1390)
	SBCI R31,HIGH(-1390)
	RJMP _0x12D
; 0000 025C                                         }
; 0000 025D                                         else if(Threshold_Diff>1350)
_0x82:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x547)
	LDI  R30,HIGH(0x547)
	CPC  R27,R30
	BRLT _0x84
; 0000 025E                                         {
; 0000 025F                                             Threshold_BW = Threshold_Gray + 1340;
	MOVW R30,R10
	SUBI R30,LOW(-1340)
	SBCI R31,HIGH(-1340)
	RJMP _0x12D
; 0000 0260                                         }
; 0000 0261 
; 0000 0262                                         else if(Threshold_Diff>1300)
_0x84:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x515)
	LDI  R30,HIGH(0x515)
	CPC  R27,R30
	BRLT _0x86
; 0000 0263                                         {
; 0000 0264                                             Threshold_BW = Threshold_Gray + 1290;
	MOVW R30,R10
	SUBI R30,LOW(-1290)
	SBCI R31,HIGH(-1290)
	RJMP _0x12D
; 0000 0265                                         }
; 0000 0266                                         else if(Threshold_Diff>1250)
_0x86:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x4E3)
	LDI  R30,HIGH(0x4E3)
	CPC  R27,R30
	BRLT _0x88
; 0000 0267                                         {
; 0000 0268                                             Threshold_BW = Threshold_Gray + 1240;
	MOVW R30,R10
	SUBI R30,LOW(-1240)
	SBCI R31,HIGH(-1240)
	RJMP _0x12D
; 0000 0269                                         }
; 0000 026A 
; 0000 026B                                         else if(Threshold_Diff>1200)
_0x88:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x4B1)
	LDI  R30,HIGH(0x4B1)
	CPC  R27,R30
	BRLT _0x8A
; 0000 026C                                         {
; 0000 026D                                             Threshold_BW = Threshold_Gray + 1190;
	MOVW R30,R10
	SUBI R30,LOW(-1190)
	SBCI R31,HIGH(-1190)
	RJMP _0x12D
; 0000 026E                                         }
; 0000 026F                                         else if(Threshold_Diff>1150)
_0x8A:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x47F)
	LDI  R30,HIGH(0x47F)
	CPC  R27,R30
	BRLT _0x8C
; 0000 0270                                         {
; 0000 0271                                             Threshold_BW = Threshold_Gray + 1140;
	MOVW R30,R10
	SUBI R30,LOW(-1140)
	SBCI R31,HIGH(-1140)
	RJMP _0x12D
; 0000 0272                                         }
; 0000 0273 
; 0000 0274                                         else if(Threshold_Diff>1100)
_0x8C:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x44D)
	LDI  R30,HIGH(0x44D)
	CPC  R27,R30
	BRLT _0x8E
; 0000 0275                                         {
; 0000 0276                                             Threshold_BW = Threshold_Gray + 1190;
	MOVW R30,R10
	SUBI R30,LOW(-1190)
	SBCI R31,HIGH(-1190)
	RJMP _0x12D
; 0000 0277                                         }
; 0000 0278                                         else if(Threshold_Diff>1050)
_0x8E:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x41B)
	LDI  R30,HIGH(0x41B)
	CPC  R27,R30
	BRLT _0x90
; 0000 0279                                         {
; 0000 027A                                             Threshold_BW = Threshold_Gray + 1040;
	MOVW R30,R10
	SUBI R30,LOW(-1040)
	SBCI R31,HIGH(-1040)
	RJMP _0x12D
; 0000 027B                                         }
; 0000 027C                                         else if(Threshold_Diff>1000)
_0x90:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x3E9)
	LDI  R30,HIGH(0x3E9)
	CPC  R27,R30
	BRLT _0x92
; 0000 027D                                         {
; 0000 027E                                             Threshold_BW = Threshold_Gray + 990;
	MOVW R30,R10
	SUBI R30,LOW(-990)
	SBCI R31,HIGH(-990)
	RJMP _0x12D
; 0000 027F                                         }
; 0000 0280 
; 0000 0281                                         else if(Threshold_Diff>950)
_0x92:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x3B7)
	LDI  R30,HIGH(0x3B7)
	CPC  R27,R30
	BRLT _0x94
; 0000 0282                                         {
; 0000 0283                                             Threshold_BW = Threshold_Gray + 940;
	MOVW R30,R10
	SUBI R30,LOW(-940)
	SBCI R31,HIGH(-940)
	RJMP _0x12D
; 0000 0284                                         }
; 0000 0285 
; 0000 0286                                         else if(Threshold_Diff>900)
_0x94:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x385)
	LDI  R30,HIGH(0x385)
	CPC  R27,R30
	BRLT _0x96
; 0000 0287                                         {
; 0000 0288                                             Threshold_BW = Threshold_Gray + 890;
	MOVW R30,R10
	SUBI R30,LOW(-890)
	SBCI R31,HIGH(-890)
	RJMP _0x12D
; 0000 0289                                         }
; 0000 028A 
; 0000 028B                                         else if(Threshold_Diff>850)
_0x96:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x353)
	LDI  R30,HIGH(0x353)
	CPC  R27,R30
	BRLT _0x98
; 0000 028C                                         {
; 0000 028D                                             Threshold_BW = Threshold_Gray + 840;
	MOVW R30,R10
	SUBI R30,LOW(-840)
	SBCI R31,HIGH(-840)
	RJMP _0x12D
; 0000 028E                                         }
; 0000 028F 
; 0000 0290                                         else if(Threshold_Diff>800)
_0x98:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x321)
	LDI  R30,HIGH(0x321)
	CPC  R27,R30
	BRLT _0x9A
; 0000 0291                                         {
; 0000 0292                                             Threshold_BW = Threshold_Gray + 790;
	MOVW R30,R10
	SUBI R30,LOW(-790)
	SBCI R31,HIGH(-790)
	RJMP _0x12D
; 0000 0293                                         }
; 0000 0294                                         else if(Threshold_Diff>700)
_0x9A:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x2BD)
	LDI  R30,HIGH(0x2BD)
	CPC  R27,R30
	BRLT _0x9C
; 0000 0295                                         {
; 0000 0296                                             Threshold_BW = Threshold_Gray + 690;
	MOVW R30,R10
	SUBI R30,LOW(-690)
	SBCI R31,HIGH(-690)
	RJMP _0x12D
; 0000 0297                                         }
; 0000 0298                                         else if(Threshold_Diff>600)
_0x9C:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x259)
	LDI  R30,HIGH(0x259)
	CPC  R27,R30
	BRLT _0x9E
; 0000 0299                                         {
; 0000 029A                                             Threshold_BW = Threshold_Gray + 590;
	MOVW R30,R10
	SUBI R30,LOW(-590)
	SBCI R31,HIGH(-590)
	RJMP _0x12D
; 0000 029B                                         }
; 0000 029C                                         else if(Threshold_Diff>500)
_0x9E:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x1F5)
	LDI  R30,HIGH(0x1F5)
	CPC  R27,R30
	BRLT _0xA0
; 0000 029D                                         {
; 0000 029E                                             Threshold_BW = Threshold_Gray + 490;
	MOVW R30,R10
	SUBI R30,LOW(-490)
	SBCI R31,HIGH(-490)
	RJMP _0x12D
; 0000 029F                                         }
; 0000 02A0                                         else if(Threshold_Diff>450)
_0xA0:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x1C3)
	LDI  R30,HIGH(0x1C3)
	CPC  R27,R30
	BRLT _0xA2
; 0000 02A1                                         {
; 0000 02A2                                             Threshold_BW = Threshold_Gray + 440;
	MOVW R30,R10
	SUBI R30,LOW(-440)
	SBCI R31,HIGH(-440)
	RJMP _0x12D
; 0000 02A3                                         }
; 0000 02A4                                         else if(Threshold_Diff>400)
_0xA2:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x191)
	LDI  R30,HIGH(0x191)
	CPC  R27,R30
	BRLT _0xA4
; 0000 02A5                                         {
; 0000 02A6                                             Threshold_BW = Threshold_Gray + 390;
	MOVW R30,R10
	SUBI R30,LOW(-390)
	SBCI R31,HIGH(-390)
	RJMP _0x12D
; 0000 02A7                                         }
; 0000 02A8                                         else if(Threshold_Diff>350)
_0xA4:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x15F)
	LDI  R30,HIGH(0x15F)
	CPC  R27,R30
	BRLT _0xA6
; 0000 02A9                                         {
; 0000 02AA                                             Threshold_BW = Threshold_Gray + 340;
	MOVW R30,R10
	SUBI R30,LOW(-340)
	SBCI R31,HIGH(-340)
	RJMP _0x12D
; 0000 02AB                                         }
; 0000 02AC                                         else if(Threshold_Diff>300)
_0xA6:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x12D)
	LDI  R30,HIGH(0x12D)
	CPC  R27,R30
	BRLT _0xA8
; 0000 02AD                                         {
; 0000 02AE                                             Threshold_BW = Threshold_Gray + 290;
	MOVW R30,R10
	SUBI R30,LOW(-290)
	SBCI R31,HIGH(-290)
	RJMP _0x12D
; 0000 02AF                                         }
; 0000 02B0                                         else if(Threshold_Diff>250)
_0xA8:
	RCALL SUBOPT_0x1D
	BRLT _0xAA
; 0000 02B1                                         {
; 0000 02B2                                             Threshold_BW = Threshold_Gray + 240;
	MOVW R30,R10
	SUBI R30,LOW(-240)
	SBCI R31,HIGH(-240)
	RJMP _0x12D
; 0000 02B3                                         }
; 0000 02B4                                         else if(Threshold_Diff>200)
_0xAA:
	RCALL SUBOPT_0x1E
	BRLT _0xAC
; 0000 02B5                                         {
; 0000 02B6                                             Threshold_BW = Threshold_Gray + 190;
	MOVW R30,R10
	SUBI R30,LOW(-190)
	SBCI R31,HIGH(-190)
	RJMP _0x12D
; 0000 02B7                                         }
; 0000 02B8                                         else if(Threshold_Diff>150)
_0xAC:
	RCALL SUBOPT_0x1F
	BRLT _0xAE
; 0000 02B9                                         {
; 0000 02BA                                             Threshold_BW = Threshold_Gray + 140;
	MOVW R30,R10
	SUBI R30,LOW(-140)
	SBCI R31,HIGH(-140)
	RJMP _0x12D
; 0000 02BB                                         }
; 0000 02BC                                         else if(Threshold_Diff>100)
_0xAE:
	RCALL SUBOPT_0x20
	BRLT _0xB0
; 0000 02BD                                         {
; 0000 02BE                                             Threshold_BW = Threshold_Gray + 90;
	MOVW R30,R10
	SUBI R30,LOW(-90)
	SBCI R31,HIGH(-90)
	RJMP _0x12D
; 0000 02BF                                         }
; 0000 02C0                                         else if(Threshold_Diff>50)
_0xB0:
	RCALL SUBOPT_0x1C
	SBIW R26,51
	BRLT _0xB2
; 0000 02C1                                         {
; 0000 02C2                                             Threshold_BW = Threshold_Gray + 40;
	MOVW R30,R10
	ADIW R30,40
	RJMP _0x12D
; 0000 02C3                                         }
; 0000 02C4                                         else
_0xB2:
; 0000 02C5                                         {
; 0000 02C6                                             Threshold_BW = Threshold_Gray + 30;
	MOVW R30,R10
	ADIW R30,30
_0x12D:
	STS  _Threshold_BW,R30
	STS  _Threshold_BW+1,R31
; 0000 02C7                                         }
; 0000 02C8 
; 0000 02C9 
; 0000 02CA                                         Threshold_Diff= Threshold_Gray - Threshold_Black;
	MOVW R30,R10
	SUB  R30,R8
	SBC  R31,R9
	RCALL SUBOPT_0x1B
; 0000 02CB 
; 0000 02CC //                                        if(Threshold_Diff>400)
; 0000 02CD //                                        {
; 0000 02CE //                                            Threshold_BG = Threshold_Black + 375;
; 0000 02CF //                                        }
; 0000 02D0 //                                        if(Threshold_Diff>375)
; 0000 02D1 //                                        {
; 0000 02D2 //                                            Threshold_BG = Threshold_Black + 350;
; 0000 02D3 //                                        }
; 0000 02D4 //                                        else if(Threshold_Diff>350)
; 0000 02D5 //                                        {
; 0000 02D6 //                                            Threshold_BG = Threshold_Black + 325;
; 0000 02D7 //                                        }
; 0000 02D8 
; 0000 02D9 //======COMMENT 03-10-2016======//
; 0000 02DA /*
; 0000 02DB                                         if(Threshold_Diff>310)
; 0000 02DC                                         {
; 0000 02DD                                             Threshold_BG = Threshold_Black + 300;
; 0000 02DE                                         }
; 0000 02DF 
; 0000 02E0                                         else if(Threshold_Diff>300)
; 0000 02E1                                         {
; 0000 02E2                                             Threshold_BG = Threshold_Black + 290;
; 0000 02E3                                         }
; 0000 02E4 */
; 0000 02E5 
; 0000 02E6                                        // else
; 0000 02E7                                         if(Threshold_Diff>290)
	CPI  R26,LOW(0x123)
	LDI  R30,HIGH(0x123)
	CPC  R27,R30
	BRLT _0xB4
; 0000 02E8                                         {
; 0000 02E9                                             Threshold_BG = Threshold_Black + 280;
	MOVW R30,R8
	SUBI R30,LOW(-280)
	SBCI R31,HIGH(-280)
	RJMP _0x12E
; 0000 02EA                                         }
; 0000 02EB 
; 0000 02EC 
; 0000 02ED                                         else if(Threshold_Diff>280)
_0xB4:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x119)
	LDI  R30,HIGH(0x119)
	CPC  R27,R30
	BRLT _0xB6
; 0000 02EE                                         {
; 0000 02EF                                             Threshold_BG = Threshold_Black + 270;
	MOVW R30,R8
	SUBI R30,LOW(-270)
	SBCI R31,HIGH(-270)
	RJMP _0x12E
; 0000 02F0                                         }
; 0000 02F1 
; 0000 02F2                                         else if(Threshold_Diff>270)
_0xB6:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x10F)
	LDI  R30,HIGH(0x10F)
	CPC  R27,R30
	BRLT _0xB8
; 0000 02F3                                         {
; 0000 02F4                                             Threshold_BG = Threshold_Black + 260;
	MOVW R30,R8
	SUBI R30,LOW(-260)
	SBCI R31,HIGH(-260)
	RJMP _0x12E
; 0000 02F5                                         }
; 0000 02F6 
; 0000 02F7                                         else if(Threshold_Diff>260)
_0xB8:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x105)
	LDI  R30,HIGH(0x105)
	CPC  R27,R30
	BRLT _0xBA
; 0000 02F8                                         {
; 0000 02F9                                             Threshold_BG = Threshold_Black + 250;
	MOVW R30,R8
	SUBI R30,LOW(-250)
	SBCI R31,HIGH(-250)
	RJMP _0x12E
; 0000 02FA                                         }
; 0000 02FB 
; 0000 02FC                                         else if(Threshold_Diff>250)
_0xBA:
	RCALL SUBOPT_0x1D
	BRLT _0xBC
; 0000 02FD                                         {
; 0000 02FE                                             Threshold_BG = Threshold_Black + 225;
	MOVW R30,R8
	SUBI R30,LOW(-225)
	SBCI R31,HIGH(-225)
	RJMP _0x12E
; 0000 02FF                                         }
; 0000 0300                                         else if(Threshold_Diff>225)
_0xBC:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0xE2)
	LDI  R30,HIGH(0xE2)
	CPC  R27,R30
	BRLT _0xBE
; 0000 0301                                         {
; 0000 0302                                             Threshold_BG = Threshold_Black + 200;
	MOVW R30,R8
	SUBI R30,LOW(-200)
	SBCI R31,HIGH(-200)
	RJMP _0x12E
; 0000 0303                                         }
; 0000 0304 
; 0000 0305                                         else if(Threshold_Diff>200)
_0xBE:
	RCALL SUBOPT_0x1E
	BRLT _0xC0
; 0000 0306                                         {
; 0000 0307                                             Threshold_BG = Threshold_Black + 175;
	MOVW R30,R8
	SUBI R30,LOW(-175)
	SBCI R31,HIGH(-175)
	RJMP _0x12E
; 0000 0308                                         }
; 0000 0309                                         else if(Threshold_Diff>175)
_0xC0:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0xB0)
	LDI  R30,HIGH(0xB0)
	CPC  R27,R30
	BRLT _0xC2
; 0000 030A                                         {
; 0000 030B                                             Threshold_BG = Threshold_Black + 150;
	MOVW R30,R8
	SUBI R30,LOW(-150)
	SBCI R31,HIGH(-150)
	RJMP _0x12E
; 0000 030C                                         }
; 0000 030D 
; 0000 030E                                         else if(Threshold_Diff>150)
_0xC2:
	RCALL SUBOPT_0x1F
	BRLT _0xC4
; 0000 030F                                         {
; 0000 0310                                             Threshold_BG = Threshold_Black + 125;
	MOVW R30,R8
	SUBI R30,LOW(-125)
	SBCI R31,HIGH(-125)
	RJMP _0x12E
; 0000 0311                                         }
; 0000 0312                                         else if(Threshold_Diff>125)
_0xC4:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x7E)
	LDI  R30,HIGH(0x7E)
	CPC  R27,R30
	BRLT _0xC6
; 0000 0313                                         {
; 0000 0314                                             Threshold_BG = Threshold_Black + 100;
	MOVW R30,R8
	SUBI R30,LOW(-100)
	SBCI R31,HIGH(-100)
	RJMP _0x12E
; 0000 0315                                         }
; 0000 0316                                         else if(Threshold_Diff>100)
_0xC6:
	RCALL SUBOPT_0x20
	BRLT _0xC8
; 0000 0317                                         {
; 0000 0318                                             Threshold_BG = Threshold_Black + 75;
	MOVW R30,R8
	SUBI R30,LOW(-75)
	SBCI R31,HIGH(-75)
	RJMP _0x12E
; 0000 0319                                         }
; 0000 031A                                         else if(Threshold_Diff>75)
_0xC8:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x4C)
	LDI  R30,HIGH(0x4C)
	CPC  R27,R30
	BRLT _0xCA
; 0000 031B                                         {
; 0000 031C                                             Threshold_BG = Threshold_Black + 50;
	MOVW R30,R8
	ADIW R30,50
	RJMP _0x12E
; 0000 031D                                         }
; 0000 031E                                         else if(Threshold_Diff>50)
_0xCA:
	RCALL SUBOPT_0x1C
	SBIW R26,51
; 0000 031F                                         {
; 0000 0320                                             Threshold_BG = Threshold_Black + 25;
; 0000 0321                                         }
; 0000 0322                                         else
; 0000 0323                                         {
; 0000 0324                                             Threshold_BG = Threshold_Black + 25;
_0x12F:
	MOVW R30,R8
	ADIW R30,25
_0x12E:
	STS  _Threshold_BG,R30
	STS  _Threshold_BG+1,R31
; 0000 0325                                         }
; 0000 0326                                     }break;
	RJMP _0x62
; 0000 0327 
; 0000 0328             case TRACER_CALIBRATE_GRAY:
_0x81:
	CPI  R30,LOW(0x4A)
	LDI  R26,HIGH(0x4A)
	CPC  R31,R26
	BRNE _0xCE
; 0000 0329                                     {
; 0000 032A                                         Tracer_GetData_Gray();
	RCALL _Tracer_GetData_Gray
; 0000 032B                                     }break;
	RJMP _0x62
; 0000 032C 
; 0000 032D             case TRACER_CALIBRATE_WHITE:
_0xCE:
	CPI  R30,LOW(0x4B)
	LDI  R26,HIGH(0x4B)
	CPC  R31,R26
	BRNE _0xCF
; 0000 032E                                     {
; 0000 032F                                         Tracer_GetData_White();
	RCALL _Tracer_GetData_White
; 0000 0330                                     }break;
	RJMP _0x62
; 0000 0331 
; 0000 0332             case TRACER_CALIBRATE_BLACK:
_0xCF:
	CPI  R30,LOW(0x4D)
	LDI  R26,HIGH(0x4D)
	CPC  R31,R26
	BRNE _0xD0
; 0000 0333                                     {
; 0000 0334                                         Tracer_GetData_Black();
	RCALL _Tracer_GetData_Black
; 0000 0335                                     }break;
	RJMP _0x62
; 0000 0336 
; 0000 0337             case TRACER_CALIBRATE_GETRULE:
_0xD0:
	CPI  R30,LOW(0x4C)
	LDI  R26,HIGH(0x4C)
	CPC  R31,R26
	BRNE _0x62
; 0000 0338                                     {
; 0000 0339                                         Tracer_Calibrate_GetRule();
	RCALL _Tracer_Calibrate_GetRule
; 0000 033A                                     }break;
; 0000 033B     }
_0x62:
; 0000 033C 
; 0000 033D }
	RET
;
;int Tracer_Sampling(int MODE)
; 0000 0340 {
_Tracer_Sampling:
; 0000 0341 
; 0000 0342     int counter=0;
; 0000 0343     int TRACER_TEMP[5]={0,0,0,0,0};
; 0000 0344     int TRACER_SUM=0;
; 0000 0345 
; 0000 0346 
; 0000 0347     switch(MODE)
	ST   -Y,R27
	ST   -Y,R26
	SBIW R28,10
	LDI  R24,10
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	LDI  R30,LOW(_0xD2*2)
	LDI  R31,HIGH(_0xD2*2)
	RCALL __INITLOCB
	RCALL __SAVELOCR4
;	MODE -> Y+14
;	counter -> R16,R17
;	TRACER_TEMP -> Y+4
;	TRACER_SUM -> R18,R19
	RCALL SUBOPT_0x21
	__GETWRN 18,19,0
	LDD  R30,Y+14
	LDD  R31,Y+14+1
; 0000 0348     {
; 0000 0349         case 0: {
	SBIW R30,0
	BRNE _0xD6
; 0000 034A                     for(counter=0;counter<=4;counter++)
	RCALL SUBOPT_0x21
_0xD8:
	RCALL SUBOPT_0x22
	BRGE _0xD9
; 0000 034B                     {
; 0000 034C                         TRACER_TEMP[counter]= read_adc(2);
	RCALL SUBOPT_0x23
	PUSH R31
	PUSH R30
	LDI  R26,LOW(2)
	RCALL _read_adc
	POP  R26
	POP  R27
	RCALL SUBOPT_0xB
; 0000 034D                     }
	__ADDWRN 16,17,1
	RJMP _0xD8
_0xD9:
; 0000 034E 
; 0000 034F                     TRACER_SUM= TRACER_TEMP[0]+TRACER_TEMP[1]+TRACER_TEMP[2]+TRACER_TEMP[3]+TRACER_TEMP[4];
	RCALL SUBOPT_0x24
; 0000 0350                     TRACER[FRONT]=TRACER_SUM/5;
	STS  _TRACER,R30
	STS  _TRACER+1,R31
; 0000 0351 
; 0000 0352                     if(TRACER[FRONT]>=TRACER_THRESHOLD_UP)
	RCALL SUBOPT_0x25
	RCALL SUBOPT_0x26
	CP   R26,R30
	CPC  R27,R31
	BRLT _0xDA
; 0000 0353                     {
; 0000 0354 //                        printf("TRACER FRONT WHITE \r");                         !!!!!!!!    diganti 3 if else tiap warna  !!!!!!!!!
; 0000 0355                         TRACER_SECTION[FRONT]= TRACER_WHITE;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	RJMP _0x130
; 0000 0356                     }
; 0000 0357 
; 0000 0358                     else if(TRACER[FRONT]<=TRACER_THRESHOLD_DOWN)
_0xDA:
	RCALL SUBOPT_0x27
	RCALL SUBOPT_0x26
	RCALL SUBOPT_0xC
	BRLT _0xDC
; 0000 0359                     {
; 0000 035A //                        printf("TRACER FRONT BLACK \r");
; 0000 035B                         TRACER_SECTION[FRONT]= TRACER_BLACK;
	LDI  R30,LOW(0)
	STS  _TRACER_SECTION,R30
	STS  _TRACER_SECTION+1,R30
; 0000 035C                     }
; 0000 035D                     else
	RJMP _0xDD
_0xDC:
; 0000 035E                     {
; 0000 035F //                        printf("TRACER FRONT GRAY \r");
; 0000 0360                         TRACER_SECTION[FRONT]= TRACER_GRAY;
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
_0x130:
	STS  _TRACER_SECTION,R30
	STS  _TRACER_SECTION+1,R31
; 0000 0361                     }
_0xDD:
; 0000 0362                     return TRACER[FRONT];
	LDS  R30,_TRACER
	LDS  R31,_TRACER+1
	RJMP _0x20A0002
; 0000 0363                 }break;
; 0000 0364 
; 0000 0365         case 1: {
_0xD6:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0xDE
; 0000 0366 
; 0000 0367                     for(counter=0;counter<=4;counter++)
	RCALL SUBOPT_0x21
_0xE0:
	RCALL SUBOPT_0x22
	BRGE _0xE1
; 0000 0368                     {
; 0000 0369                         TRACER_TEMP[counter]= read_adc(1);
	RCALL SUBOPT_0x23
	PUSH R31
	PUSH R30
	LDI  R26,LOW(1)
	RCALL _read_adc
	POP  R26
	POP  R27
	RCALL SUBOPT_0xB
; 0000 036A                     }
	__ADDWRN 16,17,1
	RJMP _0xE0
_0xE1:
; 0000 036B 
; 0000 036C                     TRACER_SUM= TRACER_TEMP[0]+TRACER_TEMP[1]+TRACER_TEMP[2]+TRACER_TEMP[3]+TRACER_TEMP[4];
	RCALL SUBOPT_0x24
; 0000 036D                     TRACER[MIDDLE]=TRACER_SUM/5;
	__PUTW1MN _TRACER,2
; 0000 036E 
; 0000 036F                     if(TRACER[MIDDLE]>=TRACER_THRESHOLD_UP)
	RCALL SUBOPT_0x28
	RCALL SUBOPT_0x25
	CP   R26,R30
	CPC  R27,R31
	BRLT _0xE2
; 0000 0370                     {
; 0000 0371 //                        printf("TRACER FRONT WHITE \r");
; 0000 0372                         TRACER_SECTION[MIDDLE]= TRACER_WHITE;
	__POINTW1MN _TRACER_SECTION,2
	LDI  R26,LOW(1)
	LDI  R27,HIGH(1)
	RJMP _0x131
; 0000 0373                     }
; 0000 0374 
; 0000 0375                     else if(TRACER[MIDDLE]<=TRACER_THRESHOLD_DOWN)
_0xE2:
	RCALL SUBOPT_0x28
	RCALL SUBOPT_0x27
	RCALL SUBOPT_0xC
	BRLT _0xE4
; 0000 0376                     {
; 0000 0377 //                        printf("TRACER FRONT BLACK \r");
; 0000 0378                         TRACER_SECTION[MIDDLE]= TRACER_BLACK;
	__POINTW1MN _TRACER_SECTION,2
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	RJMP _0x131
; 0000 0379                     }
; 0000 037A                     else
_0xE4:
; 0000 037B                     {
; 0000 037C //                        printf("TRACER FRONT GRAY \r");
; 0000 037D                         TRACER_SECTION[MIDDLE]= TRACER_GRAY;
	__POINTW1MN _TRACER_SECTION,2
	LDI  R26,LOW(2)
	LDI  R27,HIGH(2)
_0x131:
	STD  Z+0,R26
	STD  Z+1,R27
; 0000 037E                     }
; 0000 037F                     return TRACER[MIDDLE];
	__GETW1MN _TRACER,2
	RJMP _0x20A0002
; 0000 0380                 }break;
; 0000 0381 
; 0000 0382         case 2: {
_0xDE:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0xD5
; 0000 0383                     for(counter=0;counter<=4;counter++)
	RCALL SUBOPT_0x21
_0xE8:
	RCALL SUBOPT_0x22
	BRGE _0xE9
; 0000 0384                     {
; 0000 0385                         TRACER_TEMP[counter]= read_adc(0);
	RCALL SUBOPT_0x23
	PUSH R31
	PUSH R30
	LDI  R26,LOW(0)
	RCALL _read_adc
	POP  R26
	POP  R27
	RCALL SUBOPT_0xB
; 0000 0386                     }
	__ADDWRN 16,17,1
	RJMP _0xE8
_0xE9:
; 0000 0387 
; 0000 0388                     TRACER_SUM= TRACER_TEMP[0]+TRACER_TEMP[1]+TRACER_TEMP[2]+TRACER_TEMP[3]+TRACER_TEMP[4];
	RCALL SUBOPT_0x24
; 0000 0389                     TRACER[REAR]=TRACER_SUM/5;
	__PUTW1MN _TRACER,4
; 0000 038A 
; 0000 038B                     if(TRACER[REAR]>=TRACER_THRESHOLD_UP)
	RCALL SUBOPT_0x29
	RCALL SUBOPT_0x25
	CP   R26,R30
	CPC  R27,R31
	BRLT _0xEA
; 0000 038C                     {
; 0000 038D //                        printf("TRACER FRONT WHITE \r");
; 0000 038E                         TRACER_SECTION[REAR]= TRACER_WHITE;
	__POINTW1MN _TRACER_SECTION,4
	LDI  R26,LOW(1)
	LDI  R27,HIGH(1)
	RJMP _0x132
; 0000 038F                     }
; 0000 0390 
; 0000 0391                     else if(TRACER[REAR]<=TRACER_THRESHOLD_DOWN)
_0xEA:
	RCALL SUBOPT_0x29
	RCALL SUBOPT_0x27
	RCALL SUBOPT_0xC
	BRLT _0xEC
; 0000 0392                     {
; 0000 0393 //                        printf("TRACER FRONT BLACK \r");
; 0000 0394                         TRACER_SECTION[REAR]= TRACER_BLACK;
	__POINTW1MN _TRACER_SECTION,4
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	RJMP _0x132
; 0000 0395                     }
; 0000 0396                     else
_0xEC:
; 0000 0397                     {
; 0000 0398 //                        printf("TRACER FRONT GRAY \r");
; 0000 0399                         TRACER_SECTION[REAR]= TRACER_GRAY;
	__POINTW1MN _TRACER_SECTION,4
	LDI  R26,LOW(2)
	LDI  R27,HIGH(2)
_0x132:
	STD  Z+0,R26
	STD  Z+1,R27
; 0000 039A                     }
; 0000 039B                     return TRACER[REAR];
	__GETW1MN _TRACER,4
; 0000 039C                 }break;
; 0000 039D     }
_0xD5:
; 0000 039E }
_0x20A0002:
	RCALL __LOADLOCR4
	ADIW R28,16
	RET
;
;
;void Tracer_GetRule(void)                 //harus dirubah untuk navigasi memakai tracer saja
; 0000 03A2 {
_Tracer_GetRule:
; 0000 03A3     Tracer_Sampling(FRONT);
	RCALL SUBOPT_0x2A
; 0000 03A4     Tracer_Sampling(MIDDLE);
	RCALL SUBOPT_0x2B
; 0000 03A5     Tracer_Sampling(REAR);
	RCALL SUBOPT_0x2C
; 0000 03A6 
; 0000 03A7 //    printf("TRACER[FRONT]: %d \t TRACER[MIDDLE]: %d \t TRACER[REAR]: %d  \r",TRACER[FRONT],TRACER[MIDDLE],TRACER[REAR] );
; 0000 03A8 
; 0000 03A9     if( (TRACER_SECTION[FRONT]==TRACER_WHITE) || (TRACER_SECTION[MIDDLE]==TRACER_WHITE) || (TRACER_SECTION[REAR]==TRACER_WHITE) )
	RCALL SUBOPT_0x2D
	SBIW R26,1
	BREQ _0xEF
	RCALL SUBOPT_0x2E
	SBIW R30,1
	BREQ _0xEF
	RCALL SUBOPT_0x2F
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0xEE
_0xEF:
; 0000 03AA     {
; 0000 03AB //        printf("TRACER STAT WHITE \r");
; 0000 03AC         TRACER_STAT=TRACER_WHITE;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	RCALL SUBOPT_0x30
; 0000 03AD     }
; 0000 03AE     else if( (TRACER_SECTION[FRONT]==TRACER_GRAY) || (TRACER_SECTION[MIDDLE]==TRACER_GRAY) || (TRACER_SECTION[REAR]==TRACER_GRAY) )
	RJMP _0xF1
_0xEE:
	RCALL SUBOPT_0x2D
	SBIW R26,2
	BREQ _0xF3
	RCALL SUBOPT_0x2E
	SBIW R30,2
	BREQ _0xF3
	RCALL SUBOPT_0x2F
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0xF2
_0xF3:
; 0000 03AF     {
; 0000 03B0 //        printf("TRACER STAT GRAY \r");
; 0000 03B1         TRACER_STAT=TRACER_GRAY;
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	RCALL SUBOPT_0x30
; 0000 03B2     }
; 0000 03B3     else
	RJMP _0xF5
_0xF2:
; 0000 03B4     {
; 0000 03B5 //        printf("TRACER STAT BLACK \r");
; 0000 03B6         TRACER_STAT=TRACER_BLACK;
	LDI  R30,LOW(0)
	STS  _TRACER_STAT,R30
	STS  _TRACER_STAT+1,R30
; 0000 03B7     }
_0xF5:
_0xF1:
; 0000 03B8 
; 0000 03B9 }
	RET
;
;void Tracer_GetData_Black(void)
; 0000 03BC {
_Tracer_GetData_Black:
; 0000 03BD      int TRC_FRONT,TRC_MIDDLE,TRC_REAR;
; 0000 03BE      int THold_Temp;
; 0000 03BF 
; 0000 03C0      TRC_FRONT  = Tracer_Sampling(FRONT);
	RCALL SUBOPT_0x31
;	TRC_FRONT -> R16,R17
;	TRC_MIDDLE -> R18,R19
;	TRC_REAR -> R20,R21
;	THold_Temp -> Y+6
	MOVW R16,R30
; 0000 03C1      TRC_MIDDLE = Tracer_Sampling(MIDDLE);
	RCALL SUBOPT_0x2B
	MOVW R18,R30
; 0000 03C2      TRC_REAR   = Tracer_Sampling(REAR);
	RCALL SUBOPT_0x2C
	MOVW R20,R30
; 0000 03C3 
; 0000 03C4 //     THold_Temp = max(TRC_FRONT, TRC_MIDDLE);
; 0000 03C5 //     THold_Temp = max(THold_Temp, TRC_REAR);
; 0000 03C6      if(TRC_FRONT >= TRC_MIDDLE) THold_Temp = TRC_FRONT;
	__CPWRR 16,17,18,19
	BRLT _0xF6
	__PUTWSR 16,17,6
; 0000 03C7      else THold_Temp= TRC_MIDDLE;
	RJMP _0xF7
_0xF6:
	__PUTWSR 18,19,6
; 0000 03C8 
; 0000 03C9      if(TRC_REAR >= THold_Temp) THold_Temp = TRC_REAR;
_0xF7:
	RCALL SUBOPT_0x32
	CP   R20,R30
	CPC  R21,R31
	BRLT _0xF8
	__PUTWSR 20,21,6
; 0000 03CA 
; 0000 03CB      TRACER_BLACKDATA= THold_Temp;
_0xF8:
	RCALL SUBOPT_0x32
	STS  _TRACER_BLACKDATA,R30
	STS  _TRACER_BLACKDATA+1,R31
; 0000 03CC 
; 0000 03CD }
	RJMP _0x20A0001
;
;void Tracer_GetData_Gray(void)
; 0000 03D0 {
_Tracer_GetData_Gray:
; 0000 03D1      int TRC_FRONT,TRC_MIDDLE,TRC_REAR;
; 0000 03D2      int THold_Temp;
; 0000 03D3 
; 0000 03D4      TRC_FRONT  = Tracer_Sampling(FRONT);
	RCALL SUBOPT_0x31
;	TRC_FRONT -> R16,R17
;	TRC_MIDDLE -> R18,R19
;	TRC_REAR -> R20,R21
;	THold_Temp -> Y+6
	MOVW R16,R30
; 0000 03D5      TRC_MIDDLE = Tracer_Sampling(MIDDLE);
	RCALL SUBOPT_0x2B
	MOVW R18,R30
; 0000 03D6      TRC_REAR   = Tracer_Sampling(REAR);
	RCALL SUBOPT_0x2C
	MOVW R20,R30
; 0000 03D7 
; 0000 03D8 //     THold_Temp = max(TRC_FRONT, TRC_MIDDLE);
; 0000 03D9 //     THold_Temp = max(THold_Temp, TRC_REAR);
; 0000 03DA      if(TRC_FRONT >= TRC_MIDDLE) THold_Temp = TRC_FRONT;
	__CPWRR 16,17,18,19
	BRLT _0xF9
	__PUTWSR 16,17,6
; 0000 03DB      else THold_Temp= TRC_MIDDLE;
	RJMP _0xFA
_0xF9:
	__PUTWSR 18,19,6
; 0000 03DC 
; 0000 03DD      if(TRC_REAR >= THold_Temp) THold_Temp = TRC_REAR;
_0xFA:
	RCALL SUBOPT_0x32
	CP   R20,R30
	CPC  R21,R31
	BRLT _0xFB
	__PUTWSR 20,21,6
; 0000 03DE 
; 0000 03DF      TRACER_GRAYDATA= THold_Temp;
_0xFB:
	__GETWRS 12,13,6
; 0000 03E0 
; 0000 03E1 }
	RJMP _0x20A0001
;
;void Tracer_GetData_White(void)
; 0000 03E4 {
_Tracer_GetData_White:
; 0000 03E5      int TRC_FRONT,TRC_MIDDLE,TRC_REAR;
; 0000 03E6      int THold_Temp;
; 0000 03E7 
; 0000 03E8      TRC_FRONT  = Tracer_Sampling(FRONT);
	RCALL SUBOPT_0x31
;	TRC_FRONT -> R16,R17
;	TRC_MIDDLE -> R18,R19
;	TRC_REAR -> R20,R21
;	THold_Temp -> Y+6
	MOVW R16,R30
; 0000 03E9      TRC_MIDDLE = Tracer_Sampling(MIDDLE);
	RCALL SUBOPT_0x2B
	MOVW R18,R30
; 0000 03EA      TRC_REAR   = Tracer_Sampling(REAR);
	RCALL SUBOPT_0x2C
	MOVW R20,R30
; 0000 03EB 
; 0000 03EC //     THold_Temp = min(TRC_FRONT, TRC_MIDDLE);
; 0000 03ED //     THold_Temp = min(THold_Temp, TRC_REAR);
; 0000 03EE 
; 0000 03EF      if(TRC_FRONT <= TRC_MIDDLE) THold_Temp = TRC_FRONT;
	__CPWRR 18,19,16,17
	BRLT _0xFC
	__PUTWSR 16,17,6
; 0000 03F0      else THold_Temp= TRC_MIDDLE;
	RJMP _0xFD
_0xFC:
	__PUTWSR 18,19,6
; 0000 03F1 
; 0000 03F2      if(TRC_REAR <= THold_Temp) THold_Temp = TRC_REAR;
_0xFD:
	RCALL SUBOPT_0x32
	CP   R30,R20
	CPC  R31,R21
	BRLT _0xFE
	__PUTWSR 20,21,6
; 0000 03F3 
; 0000 03F4      TRACER_WHITEDATA= THold_Temp;
_0xFE:
	RCALL SUBOPT_0x32
	STS  _TRACER_WHITEDATA,R30
	STS  _TRACER_WHITEDATA+1,R31
; 0000 03F5 }
	RJMP _0x20A0001
;
;void Tracer_Calibrate_GetRule(void)
; 0000 03F8 {
_Tracer_Calibrate_GetRule:
; 0000 03F9     int Tracer_Diff_Up;
; 0000 03FA     int Tracer_Diff_Down;
; 0000 03FB     int Tracer_White= TRACER_WHITEDATA;
; 0000 03FC     int Tracer_Gray= TRACER_GRAYDATA;
; 0000 03FD     int Tracer_Black= TRACER_BLACKDATA;
; 0000 03FE 
; 0000 03FF     //Tracer_Diff= TRACER_WHITEDATA-TRACER_GRAYDATA;
; 0000 0400     Tracer_Diff_Up= Tracer_White-Tracer_Gray;
	SBIW R28,4
	RCALL __SAVELOCR6
;	Tracer_Diff_Up -> R16,R17
;	Tracer_Diff_Down -> R18,R19
;	Tracer_White -> R20,R21
;	Tracer_Gray -> Y+8
;	Tracer_Black -> Y+6
	__GETWRMN 20,21,0,_TRACER_WHITEDATA
	__PUTWSR 12,13,8
	LDS  R30,_TRACER_BLACKDATA
	LDS  R31,_TRACER_BLACKDATA+1
	STD  Y+6,R30
	STD  Y+6+1,R31
	LDD  R26,Y+8
	LDD  R27,Y+8+1
	MOVW R30,R20
	SUB  R30,R26
	SBC  R31,R27
	MOVW R16,R30
; 0000 0401     Tracer_Diff_Down= Tracer_Gray-Tracer_Black;
	LDD  R26,Y+6
	LDD  R27,Y+6+1
	RCALL SUBOPT_0x33
	SUB  R30,R26
	SBC  R31,R27
	MOVW R18,R30
; 0000 0402 
; 0000 0403     if(Tracer_Diff_Up>=80)     TRACER_THRESHOLD_UP   = Tracer_Gray + 75;
	__CPWRN 16,17,80
	BRLT _0xFF
	RCALL SUBOPT_0x33
	SUBI R30,LOW(-75)
	SBCI R31,HIGH(-75)
	RJMP _0x133
; 0000 0404     else if(Tracer_Diff_Up>=75) TRACER_THRESHOLD_UP   = Tracer_Gray + 70;
_0xFF:
	__CPWRN 16,17,75
	BRLT _0x101
	RCALL SUBOPT_0x33
	SUBI R30,LOW(-70)
	SBCI R31,HIGH(-70)
	RJMP _0x133
; 0000 0405     else if(Tracer_Diff_Up>=70) TRACER_THRESHOLD_UP   = Tracer_Gray + 65;
_0x101:
	__CPWRN 16,17,70
	BRLT _0x103
	RCALL SUBOPT_0x33
	SUBI R30,LOW(-65)
	SBCI R31,HIGH(-65)
	RJMP _0x133
; 0000 0406     else if(Tracer_Diff_Up>=65) TRACER_THRESHOLD_UP   = Tracer_Gray + 60;
_0x103:
	__CPWRN 16,17,65
	BRLT _0x105
	RCALL SUBOPT_0x33
	ADIW R30,60
	RJMP _0x133
; 0000 0407     else if(Tracer_Diff_Up>=60) TRACER_THRESHOLD_UP   = Tracer_Gray + 55;
_0x105:
	__CPWRN 16,17,60
	BRLT _0x107
	RCALL SUBOPT_0x33
	ADIW R30,55
	RJMP _0x133
; 0000 0408     else if(Tracer_Diff_Up>=50) TRACER_THRESHOLD_UP   = Tracer_Gray + 45;
_0x107:
	__CPWRN 16,17,50
	BRLT _0x109
	RCALL SUBOPT_0x33
	ADIW R30,45
	RJMP _0x133
; 0000 0409     else if(Tracer_Diff_Up>=40) TRACER_THRESHOLD_UP   = Tracer_Gray + 35;
_0x109:
	__CPWRN 16,17,40
	BRLT _0x10B
	RCALL SUBOPT_0x33
	ADIW R30,35
	RJMP _0x133
; 0000 040A     else if(Tracer_Diff_Up>=30) TRACER_THRESHOLD_UP   = Tracer_Gray + 25;
_0x10B:
	__CPWRN 16,17,30
	BRLT _0x10D
	RCALL SUBOPT_0x33
	ADIW R30,25
	RJMP _0x133
; 0000 040B     else if(Tracer_Diff_Up>=20) TRACER_THRESHOLD_UP   = Tracer_Gray + 15;
_0x10D:
	__CPWRN 16,17,20
	BRLT _0x10F
	RCALL SUBOPT_0x33
	ADIW R30,15
	RJMP _0x133
; 0000 040C     else if(Tracer_Diff_Up>=10) TRACER_THRESHOLD_UP   = Tracer_Gray + 7;
_0x10F:
	__CPWRN 16,17,10
	BRLT _0x111
	RCALL SUBOPT_0x33
	ADIW R30,7
_0x133:
	STS  _TRACER_THRESHOLD_UP,R30
	STS  _TRACER_THRESHOLD_UP+1,R31
; 0000 040D 
; 0000 040E         if(Tracer_Diff_Down>=80) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 75;
_0x111:
	__CPWRN 18,19,80
	BRLT _0x112
	RCALL SUBOPT_0x33
	SUBI R30,LOW(75)
	SBCI R31,HIGH(75)
	RJMP _0x134
; 0000 040F     else if(Tracer_Diff_Down>=75) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 70;
_0x112:
	__CPWRN 18,19,75
	BRLT _0x114
	RCALL SUBOPT_0x33
	SUBI R30,LOW(70)
	SBCI R31,HIGH(70)
	RJMP _0x134
; 0000 0410     else if(Tracer_Diff_Down>=70) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 65;
_0x114:
	__CPWRN 18,19,70
	BRLT _0x116
	RCALL SUBOPT_0x33
	SUBI R30,LOW(65)
	SBCI R31,HIGH(65)
	RJMP _0x134
; 0000 0411     else if(Tracer_Diff_Down>=65) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 60;
_0x116:
	__CPWRN 18,19,65
	BRLT _0x118
	RCALL SUBOPT_0x33
	SBIW R30,60
	RJMP _0x134
; 0000 0412     else if(Tracer_Diff_Down>=60) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 55;
_0x118:
	__CPWRN 18,19,60
	BRLT _0x11A
	RCALL SUBOPT_0x33
	SBIW R30,55
	RJMP _0x134
; 0000 0413     else if(Tracer_Diff_Down>=50) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 45;
_0x11A:
	__CPWRN 18,19,50
	BRLT _0x11C
	RCALL SUBOPT_0x33
	SBIW R30,45
	RJMP _0x134
; 0000 0414     else if(Tracer_Diff_Down>=40) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 35;
_0x11C:
	__CPWRN 18,19,40
	BRLT _0x11E
	RCALL SUBOPT_0x33
	SBIW R30,35
	RJMP _0x134
; 0000 0415     else if(Tracer_Diff_Down>=30) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 25;
_0x11E:
	__CPWRN 18,19,30
	BRLT _0x120
	RCALL SUBOPT_0x33
	SBIW R30,25
	RJMP _0x134
; 0000 0416     else if(Tracer_Diff_Down>=20) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 15;
_0x120:
	__CPWRN 18,19,20
	BRLT _0x122
	RCALL SUBOPT_0x33
	SBIW R30,15
	RJMP _0x134
; 0000 0417     else if(Tracer_Diff_Down>=10) TRACER_THRESHOLD_DOWN   = Tracer_Gray - 7;
_0x122:
	__CPWRN 18,19,10
	BRLT _0x124
	RCALL SUBOPT_0x33
	SBIW R30,7
_0x134:
	STS  _TRACER_THRESHOLD_DOWN,R30
	STS  _TRACER_THRESHOLD_DOWN+1,R31
; 0000 0418 
; 0000 0419 }
_0x124:
	RCALL __LOADLOCR6
	ADIW R28,10
	RET
;
;
;void Send_Threshold(void)
; 0000 041D {
_Send_Threshold:
; 0000 041E     int Thold_BW,Thold_BG,Thold_Tracer_Up,Thold_Tracer_Down;
; 0000 041F     Thold_BW= Threshold_BW;
	SBIW R28,2
	RCALL __SAVELOCR6
;	Thold_BW -> R16,R17
;	Thold_BG -> R18,R19
;	Thold_Tracer_Up -> R20,R21
;	Thold_Tracer_Down -> Y+6
	__GETWRMN 16,17,0,_Threshold_BW
; 0000 0420     Thold_BG= Threshold_BG;
	__GETWRMN 18,19,0,_Threshold_BG
; 0000 0421     Thold_Tracer_Up= TRACER_THRESHOLD_UP;
	__GETWRMN 20,21,0,_TRACER_THRESHOLD_UP
; 0000 0422     Thold_Tracer_Down= TRACER_THRESHOLD_DOWN;
	RCALL SUBOPT_0x27
	STD  Y+6,R30
	STD  Y+6+1,R31
; 0000 0423     Send_UART(COMMAND_FLAG_A);
	RCALL SUBOPT_0xE
; 0000 0424     Send_UART(COMMAND_FLAG_B);
; 0000 0425     Send_UART(RAW_VAL_FLAG);
; 0000 0426 
; 0000 0427     //Threshold_BW VALUE
; 0000 0428     MULTIPLY_COUNTER=0;
	RCALL SUBOPT_0xF
; 0000 0429     if(Thold_BW>255)
	__CPWRN 16,17,256
	BRLT _0x125
; 0000 042A     {
; 0000 042B         while( Thold_BW >255)
_0x126:
	__CPWRN 16,17,256
	BRLT _0x128
; 0000 042C         {
; 0000 042D            Thold_BW-=255;
	__SUBWRN 16,17,255
; 0000 042E            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x12
; 0000 042F         }
	RJMP _0x126
_0x128:
; 0000 0430     }
; 0000 0431     Send_UART(MULTIPLY_COUNTER);
_0x125:
	RCALL SUBOPT_0x13
; 0000 0432     Send_UART(Thold_BW);
	MOV  R26,R16
	RCALL SUBOPT_0x14
; 0000 0433 
; 0000 0434     //Threshold_BG VALUE
; 0000 0435     MULTIPLY_COUNTER=0;
; 0000 0436     if(Thold_BG>255)
	__CPWRN 18,19,256
	BRLT _0x129
; 0000 0437     {
; 0000 0438         while( Thold_BG >255)
_0x12A:
	__CPWRN 18,19,256
	BRLT _0x12C
; 0000 0439         {
; 0000 043A            Thold_BG-=255;
	__SUBWRN 18,19,255
; 0000 043B            MULTIPLY_COUNTER++;
	RCALL SUBOPT_0x12
; 0000 043C         }
	RJMP _0x12A
_0x12C:
; 0000 043D     }
; 0000 043E     Send_UART(MULTIPLY_COUNTER);
_0x129:
	RCALL SUBOPT_0x13
; 0000 043F     Send_UART(Thold_BG);
	MOV  R26,R18
	RCALL _Send_UART
; 0000 0440 
; 0000 0441     //PHOTODIODE TRACER B/W THRESHOLD
; 0000 0442     Send_UART(Thold_Tracer_Up);
	MOV  R26,R20
	RCALL _Send_UART
; 0000 0443     Send_UART(Thold_Tracer_Down);
	LDD  R26,Y+6
	RCALL _Send_UART
; 0000 0444 }
_0x20A0001:
	RCALL __LOADLOCR6
	ADIW R28,8
	RET
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
;//    Mov_AVG[TCS_MODE]= Mov_AVG[TCS_MODE] * (MovAVG_Counter[TCS_MODE]-1) / MovAVG_Counter[TCS_MODE] + NewVal/MovAVG_Counter[TCS_MODE];
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
_TRACER_BLACKDATA:
	.BYTE 0x2
_Threshold_BW:
	.BYTE 0x2
_Threshold_BG:
	.BYTE 0x2
_TRACER_THRESHOLD_UP:
	.BYTE 0x2
_TRACER_THRESHOLD_DOWN:
	.BYTE 0x2
_COMMAND_FLAG_A:
	.BYTE 0x2
_COMMAND_FLAG_B:
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
;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:3 WORDS
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

;OPTIMIZER ADDED SUBROUTINE, CALLED 25 TIMES, CODE SIZE REDUCTION:46 WORDS
SUBOPT_0x2:
	LDI  R27,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x3:
	LDI  R30,LOW(0)
	OUT  0x2E,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x4:
	CBI  0x15,3
	LDI  R26,LOW(5)
	RCALL SUBOPT_0x2
	RCALL _delay_ms
	LDI  R30,LOW(6)
	OUT  0x2E,R30
	LDI  R26,LOW(5)
	RCALL SUBOPT_0x2
	RCALL _delay_ms
	RJMP SUBOPT_0x3

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
	RCALL SUBOPT_0x2
	RJMP _delay_ms

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x7:
	SBI  0x15,3
	LDI  R26,LOW(5)
	RCALL SUBOPT_0x2
	RCALL _delay_ms
	LDI  R30,LOW(6)
	OUT  0x2E,R30
	LDI  R26,LOW(5)
	RCALL SUBOPT_0x2
	RCALL _delay_ms
	RJMP SUBOPT_0x3

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x8:
	LDS  R30,_TCS3200_Pulse_G
	LDS  R31,_TCS3200_Pulse_G+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x9:
	LDS  R30,_TCS3200_Pulse_B
	LDS  R31,_TCS3200_Pulse_B+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xA:
	LDS  R30,_TCS3200_Pulse_W
	LDS  R31,_TCS3200_Pulse_W+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0xB:
	LDI  R31,0
	ST   X+,R30
	ST   X,R31
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xC:
	CP   R30,R26
	CPC  R31,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xD:
	LDS  R30,_TCS3200_CMD
	LDS  R31,_TCS3200_CMD+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:14 WORDS
SUBOPT_0xE:
	LDS  R26,_COMMAND_FLAG_A
	RCALL _Send_UART
	LDS  R26,_COMMAND_FLAG_B
	RCALL _Send_UART
	LDS  R26,_RAW_VAL_FLAG
	RJMP _Send_UART

;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:22 WORDS
SUBOPT_0xF:
	LDI  R30,LOW(0)
	STS  _MULTIPLY_COUNTER,R30
	STS  _MULTIPLY_COUNTER+1,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x10:
	__GETW2MN _MOV_AVG,10
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x11:
	SUBI R30,LOW(255)
	SBCI R31,HIGH(255)
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0x12:
	LDI  R26,LOW(_MULTIPLY_COUNTER)
	LDI  R27,HIGH(_MULTIPLY_COUNTER)
	RJMP SUBOPT_0x1

;OPTIMIZER ADDED SUBROUTINE, CALLED 7 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0x13:
	LDS  R26,_MULTIPLY_COUNTER
	RJMP _Send_UART

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x14:
	RCALL _Send_UART
	RJMP SUBOPT_0xF

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x15:
	__GETW2MN _MOV_AVG,12
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x16:
	__GETW2MN _MOV_AVG,14
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x17:
	__GETW2MN _MOV_AVG,16
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x18:
	LDS  R26,_TCS3200_TOTAL_SUM
	LDS  R27,_TCS3200_TOTAL_SUM+1
	CPI  R26,LOW(0x100)
	LDI  R30,HIGH(0x100)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x19:
	RCALL _Send_UART
	LDS  R26,_TRACER_STAT
	RJMP _Send_UART

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x1A:
	RCALL _Tracer_GetRule
	LDS  R26,_COMMAND_FLAG_A
	RCALL _Send_UART
	LDS  R26,_COMMAND_FLAG_B
	RJMP _Send_UART

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:5 WORDS
SUBOPT_0x1B:
	STS  _Threshold_Diff,R30
	STS  _Threshold_Diff+1,R31
	LDS  R26,_Threshold_Diff
	LDS  R27,_Threshold_Diff+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 36 TIMES, CODE SIZE REDUCTION:103 WORDS
SUBOPT_0x1C:
	LDS  R26,_Threshold_Diff
	LDS  R27,_Threshold_Diff+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x1D:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0xFB)
	LDI  R30,HIGH(0xFB)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x1E:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0xC9)
	LDI  R30,HIGH(0xC9)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x1F:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x97)
	LDI  R30,HIGH(0x97)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x20:
	RCALL SUBOPT_0x1C
	CPI  R26,LOW(0x65)
	LDI  R30,HIGH(0x65)
	CPC  R27,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x21:
	__GETWRN 16,17,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x22:
	__CPWRN 16,17,5
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:10 WORDS
SUBOPT_0x23:
	MOVW R30,R16
	MOVW R26,R28
	ADIW R26,4
	LSL  R30
	ROL  R31
	ADD  R30,R26
	ADC  R31,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:42 WORDS
SUBOPT_0x24:
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
SUBOPT_0x25:
	LDS  R30,_TRACER_THRESHOLD_UP
	LDS  R31,_TRACER_THRESHOLD_UP+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x26:
	LDS  R26,_TRACER
	LDS  R27,_TRACER+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0x27:
	LDS  R30,_TRACER_THRESHOLD_DOWN
	LDS  R31,_TRACER_THRESHOLD_DOWN+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x28:
	__GETW2MN _TRACER,2
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x29:
	__GETW2MN _TRACER,4
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x2A:
	LDI  R26,LOW(0)
	RCALL SUBOPT_0x2
	RJMP _Tracer_Sampling

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x2B:
	LDI  R26,LOW(1)
	RCALL SUBOPT_0x2
	RJMP _Tracer_Sampling

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x2C:
	LDI  R26,LOW(2)
	RCALL SUBOPT_0x2
	RJMP _Tracer_Sampling

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x2D:
	LDS  R26,_TRACER_SECTION
	LDS  R27,_TRACER_SECTION+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x2E:
	__GETW1MN _TRACER_SECTION,2
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x2F:
	__GETW1MN _TRACER_SECTION,4
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x30:
	STS  _TRACER_STAT,R30
	STS  _TRACER_STAT+1,R31
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x31:
	SBIW R28,2
	RCALL __SAVELOCR6
	RJMP SUBOPT_0x2A

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x32:
	LDD  R30,Y+6
	LDD  R31,Y+6+1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 21 TIMES, CODE SIZE REDUCTION:18 WORDS
SUBOPT_0x33:
	LDD  R30,Y+8
	LDD  R31,Y+8+1
	RET


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

__LOADLOCR2P:
	LD   R16,Y+
	LD   R17,Y+
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
