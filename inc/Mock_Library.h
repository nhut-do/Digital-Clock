#ifndef MOCK_LIBRARY_H
#define MOCK_LIBRARY_H

#include <stdint.h>
#include <string.h>

/************************************************************************/
/*****************************************************************************************************************************************************************
 * 
 * PCC MEMORY MAP
 * 
*****************************************************************************************************************************************************************/
typedef struct 
{
    uint32_t Rev0[32];
	
    uint32_t PCC_FTFC;
    uint32_t PCC_DMAMUX;
    uint32_t Rev1[2];
	
    uint32_t PCC_FlexCAN0;
    uint32_t PCC_FlexCAN1;
    uint32_t PCC_FTM3;
    uint32_t PCC_ADC1;
    uint32_t Rev2[3];
	
    uint32_t PCC_FlexCAN2;
    uint32_t PCC_LPSPI0;
    uint32_t PCC_LPSPI1;
    uint32_t PCC_LPSPI2;
    uint32_t Rev3[2];
	
    uint32_t PCC_PDB1;
    uint32_t PCC_CRC;
    uint32_t Rev4[3];
		
    uint32_t PCC_PDB0;
    uint32_t PCC_LPIT;
    uint32_t PCC_FTM0;
    uint32_t PCC_FTM1;
    uint32_t PCC_FTM2;
    uint32_t PCC_ADC0;
    uint32_t Rev5[1];
		
    uint32_t PCC_RTC;
    uint32_t Rev6[2];
		
    uint32_t PCC_LPTMR0;
    uint32_t Rev7[8];
		
    uint32_t PCC_PORTA;
    uint32_t PCC_PORTB;
    uint32_t PCC_PORTC;
    uint32_t PCC_PORTD;
    uint32_t PCC_PORTE;
    uint32_t Rev8[6];
		
    uint32_t PCC_SAI0;
    uint32_t PCC_SAI1;
    uint32_t Rev9[4];
		
    uint32_t PCC_FlexIO;
    uint32_t Rev10[6];
		
    uint32_t PCC_EWM;
    uint32_t Rev11[4];
		
    uint32_t PCC_LPI2C0;
    uint32_t PCC_LPI2C1;
    uint32_t Rev12[2];
		
    uint32_t PCC_LPUART0;
    uint32_t PCC_LPUART1;
    uint32_t PCC_LPUART2;
    uint32_t Rev13[1];
		
    uint32_t PCC_FTM4;
    uint32_t PCC_FTM5;
    uint32_t PCC_FTM6;
    uint32_t PCC_FTM7;
    uint32_t Rev14[1];
		
    uint32_t PCC_CMP0;
    uint32_t Rev15[2];
		
    uint32_t PCC_QSPI;
    uint32_t Rev16[2];
		
    uint32_t PCC_ENET;

} PCC_ADDRESS;
#define PCC__ADDRESS 0x40065000u
#define PCC ((PCC_ADDRESS*)(PCC__ADDRESS))

/* Macro for function to choose PORT A -> B */
#define PORTA  1
#define PORTB  2
#define PORTC  3
#define PORTD  4
#define PORTE  5
/*****************************************************************************************************************************************************************
 * 
 * SCG MEMORY MAP
 * 
*****************************************************************************************************************************************************************/
typedef struct 
{
    uint32_t SCG_VERID;
    uint32_t SCG_PARAM;
    uint32_t Rev1[2];

    uint32_t SCG_CSR;
    uint32_t SCG_RCCR;
    uint32_t SCG_VCCR;
    uint32_t SCG_HCCR;
    uint32_t SCG_CLKOUTCNFG;
    uint32_t Rev2[55];

    uint32_t SCG_SOSCCSR;
    uint32_t SCG_SOSCDIV;
    uint32_t SCG_SOSCCFG;
    uint32_t Rev3[61];

    uint32_t SCG_SIRCCSR;
    uint32_t SCG_SIRCDIV;
    uint32_t SCG_SIRCCFG;
    uint32_t Rev4[61];

    uint32_t SCG_FIRCCSR;
    uint32_t SCG_FIRCDIV;
    uint32_t SCG_FIRCCFG;
    uint32_t Rev5[189];

    uint32_t SCG_SPLLCSR;
    uint32_t SCG_SPLLDIV;
    uint32_t SCG_SPLLCFG;
} SCG_ADDRESS;
#define SCG_BASE_ADDRESS (0x40064000)
#define SCG ((SCG_ADDRESS *) SCG_BASE_ADDRESS)
/*****************************************************************************************************************************************************************
 * 
 * PORT MEMORY MAP
 * 
*****************************************************************************************************************************************************************/
typedef struct 
{
    uint32_t PORT_PCR0;
    uint32_t PORT_PCR1;
    uint32_t PORT_PCR2;
    uint32_t PORT_PCR3;
    uint32_t PORT_PCR4;
    uint32_t PORT_PCR5;
    uint32_t PORT_PCR6;
    uint32_t PORT_PCR7;
    uint32_t PORT_PCR8;
    uint32_t PORT_PCR9;
    uint32_t PORT_PCR10;
    uint32_t PORT_PCR11;
    uint32_t PORT_PCR12;
    uint32_t PORT_PCR13;
    uint32_t PORT_PCR14;
    uint32_t PORT_PCR15;
    uint32_t PORT_PCR16;
    uint32_t PORT_PCR17;
    uint32_t PORT_PCR18;
    uint32_t PORT_PCR19;
    uint32_t PORT_PCR20;
    uint32_t PORT_PCR21;
    uint32_t PORT_PCR22;
    uint32_t PORT_PCR23;
    uint32_t PORT_PCR24;
    uint32_t PORT_PCR25;
    uint32_t PORT_PCR26;
    uint32_t PORT_PCR27;
    uint32_t PORT_PCR28;
    uint32_t PORT_PCR29;
    uint32_t PORT_PCR30;
    uint32_t PORT_PCR31;
    uint32_t PORT_GPCLR;
    uint32_t PORT_GPCHR;
    uint32_t PORT_GICLR;
    uint32_t PORT_GICHR;
    uint32_t Rev1[4];
    uint32_t PORT_ISFR;
    uint32_t Rev2[7];
    uint32_t PORT_DFER;
    uint32_t PORT_DFCR;
    uint32_t PORT_DFWR;
} PORT;
#define PORT_A_BASE_ADDRESS (0x40049000)
#define PORT_A ((PORT *) PORT_A_BASE_ADDRESS)

#define PORT_B_BASE_ADDRESS (0x4004A000)
#define PORT_B ((PORT *) PORT_B_BASE_ADDRESS)

#define PORT_C_BASE_ADDRESS (0x4004B000)
#define PORT_C ((PORT *) PORT_C_BASE_ADDRESS)

#define PORT_D_BASE_ADDRESS (0x4004C000)
#define PORT_D ((PORT *) PORT_D_BASE_ADDRESS)

#define PORT_E_BASE_ADDRESS (0x4004D000)
#define PORT_E ((PORT *) PORT_E_BASE_ADDRESS)
/*****************************************************************************************************************************************************************
 * 
 * GPIO MEMORY MAP
 * 
*****************************************************************************************************************************************************************/
typedef struct 
{
    uint32_t PDOR;
    uint32_t PSOR;
    uint32_t PCOR;
    uint32_t PTOR;
    uint32_t PDIR;
    uint32_t PDDR;
    uint32_t PIDR;
} GPIO;
#define GPIO_A_BASE_ADDRESS (0x400FF000)
#define GPIO_A ((GPIO *) GPIO_A_BASE_ADDRESS)

#define GPIO_B_BASE_ADDRESS (0x400FF040)
#define GPIO_B ((GPIO *) GPIO_B_BASE_ADDRESS)

#define GPIO_C_BASE_ADDRESS (0x400FF080)
#define GPIO_C ((GPIO *) GPIO_C_BASE_ADDRESS)

#define GPIO_D_BASE_ADDRESS (0x400FF0C0)
#define GPIO_D ((GPIO *) GPIO_D_BASE_ADDRESS)

#define GPIO_E_BASE_ADDRESS (0x400FF100)
#define GPIO_E ((GPIO *) GPIO_E_BASE_ADDRESS)
/*****************************************************************************************************************************************************************
 * 
 * SYSTICK TIMER MEMORY MAP
 * 
*****************************************************************************************************************************************************************/
typedef struct 
{
    uint32_t CONTROL;
    uint32_t RELOAD_VALUE;
    uint32_t CURRENT_VALUE;
    uint32_t CALIBRATION;
}SYSTICK_ADDRESS;
#define SYSTICK_BASE_ADDRESS (0xE000E010)
#define SYSTICK ((SYSTICK_ADDRESS *) SYSTICK_BASE_ADDRESS)
/*****************************************************************************************************************************************************************
 * 
 * LPIT MEMORY MAP
 * 
*****************************************************************************************************************************************************************/
typedef struct 
{
    uint32_t VERID;
    uint32_t PARAM;
    uint32_t MCR;
    uint32_t MSR;
    uint32_t MIER;
    uint32_t SETTEN;
    uint32_t CLRTEN;
    uint32_t Rev1[1];
    uint32_t TVAL0;
    uint32_t CVAL0;
    uint32_t TCTRL0;
    uint32_t Rev2[1];
    uint32_t TVAL1;
    uint32_t CVAL1;
    uint32_t TCTRL1;
    uint32_t Rev3[1];
    uint32_t TVAL2;
    uint32_t CVAL2;
    uint32_t TCTRL2;
    uint32_t Rev4[1];
    uint32_t TVAL3;
    uint32_t CVAL3;
    uint32_t TCTRL3;
} LPIT_ADDRESS;
#define LPIT_BASE_ADDRESS (0x40037000)
#define LPIT ((LPIT_ADDRESS *) LPIT_BASE_ADDRESS)
/*****************************************************************************************************************************************************************
 * 
 * LPUART MEMORY MAP
 * 
*****************************************************************************************************************************************************************/
typedef struct 
{
    uint32_t VERID;
    uint32_t PARAM;
    uint32_t GLOBAL;
    uint32_t PINCFG;
    uint32_t BAUD;
    uint32_t STAT;
    uint32_t CTRL;
    uint32_t DATA;
    uint32_t MATCH;
    uint32_t MODIR;
    uint32_t FIFO;
    uint32_t WATER;
} LPUART;
#define LPUART_0_BASE_ADDRESS (0x4006A000)
#define LPUART_0 ((LPUART *) LPUART_0_BASE_ADDRESS)

#define LPUART_1_BASE_ADDRESS (0x4006B000)
#define LPUART_1 ((LPUART *) LPUART_1_BASE_ADDRESS)

#define LPUART_2_BASE_ADDRESS (0x4006C000)
#define LPUART_2 ((LPUART *) LPUART_2_BASE_ADDRESS)
/*****************************************************************************************************************************************************************
 * 
 * SPI MEMORY MAP
 * 
*****************************************************************************************************************************************************************/
typedef struct 
{
    unsigned int VERID;
    unsigned int PARAM;
    unsigned int Rev1[2];

    unsigned int CR;
    unsigned int SR;
    unsigned int IER;
    unsigned int DER;
    unsigned int CFGR0;
    unsigned int CFGR1;
    unsigned int Rev2[2];

    unsigned int DMR0;
    unsigned int DMR1;
    unsigned int Rev3[2];

    unsigned int CCR;
    unsigned int Rev4[5];

    unsigned int FCR;
    unsigned int FSR;
    unsigned int TCR;
    unsigned int TDR;
    unsigned int Rev5[2];

    unsigned int RSR;
    unsigned int RDR;

} LPSPI_Type;
#define LPSPI0_BASE_ADDRESS (0x4002C000u)
#define LPSPI_0 ((LPSPI_Type *) LPSPI0_BASE_ADDRESS)

#define LPSPI1_BASE_ADDRESS (0x4002D000u)
#define LPSPI_1 ((LPSPI_Type *) LPSPI1_BASE_ADDRESS)

#define LPSPI2_BASE_ADDRESS (0x4002E000u)
#define LPSPI_2 ((LPSPI_Type *) LPSPI2_BASE_ADDRESS)

/*****************************************************************************************************************************************************************
 * 
 * DEFINE
 * 
*****************************************************************************************************************************************************************/
/* Parameter to choose Intterupt edge */
#define Disable_IRQ             1
#define Interrupt_logic_0       2
#define Interrupt_Rising_Edge   3
#define Interrupt_Falling_Edge  4
#define Interrupt_Either_Edge   5
#define Interrupt_logic_1       6

/* Interrup edge config */
#define Disable_Interrupt       (unsigned char*)"0000"
#define Logic_0                 (unsigned char*)"1000"
#define Rising_Edge             (unsigned char*)"1001"
#define Falling_Edge            (unsigned char*)"1010"
#define Either_Edge             (unsigned char*)"1011"
#define Logic_1                 (unsigned char*)"1100"

/* Config direction for pin */
#define OUTPUT      1 
#define INPUT       0 

/* Cofig level for pin */
#define HIGH        1 
#define LOW         0

/* Macro to choose enable or disable module */
#define DISABLE     0
#define ENABLE      1

/* Macro to choose set bit or clear bit */
#define SET_BIT     1
#define CLEAR_BIT   0

/* Pin MUX control */
#define Alternative_0    (unsigned char*)"000"
#define Alternative_1    (unsigned char*)"001"
#define Alternative_2    (unsigned char*)"010"
#define Alternative_3    (unsigned char*)"011"
#define Alternative_4    (unsigned char*)"100"
#define Alternative_5    (unsigned char*)"101"
#define Alternative_6    (unsigned char*)"110"
#define Alternative_7    (unsigned char*)"111"

/* Peripheral Clock Source Select */
#define OPTION_0    (unsigned char*)"000"
#define OPTION_1    (unsigned char*)"001"
#define OPTION_2    (unsigned char*)"010"
#define OPTION_3    (unsigned char*)"011"
#define OPTION_4    (unsigned char*)"100"
#define OPTION_5    (unsigned char*)"101"
#define OPTION_6    (unsigned char*)"110"
#define OPTION_7    (unsigned char*)"111"

/*****************************************************************************************************************************************************************
 * 
 * VARIABLES
 * 
*****************************************************************************************************************************************************************/
/* Variable for IRQ Handler */
extern uint8_t cButton1;        /* Display time/date */
extern uint8_t cButton2;        /* Turn on/of display mode */
extern uint8_t cCountBlink;      /* Count  for blinking LED */

/* Variable that use to transmit value of SECOND - MINUTE - HOUR to LED */
extern uint16_t cSecond;            /* LED 1 */
extern uint16_t cCountSecond;       /* LED 2 */
extern uint16_t cMinute;            /* LED 4 */
extern uint16_t cCountMinute;       /* LED 5 */
extern uint16_t cHour;              /* LED 7 */
extern uint16_t cCountHour;         /* LED 8 */

/* Variable that use to transmit value of DAY - MONTH - YEAR to LED */
extern uint16_t cYear;              /* LED 1 */
extern uint16_t cCountYear_1;       /* LED 2 */
extern uint16_t cCountYear_2;       /* LED 3 */
extern uint16_t cCountYear_3;       /* LED 4 */
extern uint16_t cMonth;             /* LED 5 */
extern uint16_t cCountMonth;        /* LED 6 */
extern uint16_t cDay;               /* LED 7 */
extern uint16_t cCountDay;          /* LED 8 */

/* Variable that check current time when the program running */
extern uint8_t cSecondVar;        /* Variable take Day current value */
extern uint8_t cMinuteVar;        /* Variable take Month curren value */
extern uint8_t cHourVar;          /* Variable take Hour current value */
extern uint8_t cDayVar;           /* Variable take Day current value */
extern uint8_t cMonthVar;         /* Variable take Month current value */
extern uint16_t cYearVar;         /* Variable take Year current value */

/* Variable that check alarm clock */
extern uint8_t cAlarmSecond;            /* Variable take Alarm Second value from LPUART */
extern uint8_t cAlarmMinute;            /* Variable take Alarm Minute value from LPUART */
extern uint8_t cAlarmHour;              /* Variable take Alarm Hour value from LPUART */
extern uint8_t cAlarmCheck;             /* Variable check Alarm status from LPUART */ 

/* Variable that check alarm clock */
extern uint8_t cAlarmSecondUART;         /* Variable take Alarm Second value */
extern uint8_t cAlarmMinuteUART;         /* Variable take Alarm Minute value */
extern uint8_t cAlarmHourUART;           /* Variable take Alarm Hour value */

/* String to get data from LPUART */
extern char sReceiveData[20];
/* Number of character sReceiveData[20] receive */
extern uint8_t cNumOfChar;
/*****************************************************************************************************************************************************************
 * 
 * BASIC FUNCTION
 * 
*****************************************************************************************************************************************************************/
/* Set or clear 1 bit */
void SetClearBit(uint32_t *pPointer, unsigned char cPos, unsigned char cAction);
/* Set or clear each bit in a bit field */
void SetClearListOfBit(uint32_t *pPointer, unsigned char cPos1, unsigned char cPos2, unsigned char sListOfBit[32]);
/* Check a bit if it is 1 or 0 */
short CheckBit(uint32_t *pPointer, unsigned char cPos);
/* Enable clock for Port */
void Gpio_Init(uint8_t cPort);
/* Set pin as GPIO, disable pull up/down, set direction, set inerrupt type */
void Gpio_SetMode(uint8_t cPort, uint8_t cPin, uint8_t cDirect, uint8_t cIRQ);
void Gpio_WriteChannel(uint8_t cPort, uint8_t cPin, uint8_t cLevel);
short Gpio_ReadChannel(uint8_t cPort, uint8_t cPin);
/* Set NVIC for modules */
void NVIC(uint16_t iNVIC_ID);
/*****************************************************************************************************************************************************************
 * 
 * MOCK PROJECT FUNCTIONS
 * 
*****************************************************************************************************************************************************************/
/* Receive data of time/dae/alarm from LPUART */
void Receive_Time_Data(void);
/* Receive data of time from LPUART */
void Receive_Time_LPUART(void);
/* Receive data of date from LPUART */
void Receive_Date_LPUART(void);
/* Receive data of alarm from LPUART */
void Receive_Alarm_LPUART(void);
/* Change character from LPUART to deciaml value */
void Character_To_Decimal(uint8_t cTimeValue);
/* Assign time/date values to LED variables */
void Assign_Time_Date_Value_LED(uint8_t cTimeValue);
/* Print notification when transmit data to digital clock through LPUART */
void Print_Notification_LPUART(uint8_t cNotification);
/* Check how many days in month */
uint8_t Days_In_Month_3_Or_31_Days(uint8_t cMonth);

/* Count date and time */
void Count_Date_Time(void);
/* Count time */
void Count_Time(void);
/* Count date */
void Count_Date(void);

/* Display time on lED */
void Display_Time(void);
/* Display date on lED */
void Display_Date(void);

/* Check alarm timme with curren time */
void Check_Alarm_Time(void);

/*Transmit data through LPSPI  to digital clock */
void Transmit(uint32_t iValue);

#endif   /* MOCK_LIBRARY_H */






