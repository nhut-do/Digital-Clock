#include "../inc/Mock_Library.h"

/*****************************************************************************************************************************************************************
 * 
 * DEFINE,  VARIABLE
 * 
*****************************************************************************************************************************************************************/
/* Macro used for function: Character_To_Decimal(),  Decimal_To_Character() */
#define TIME    0
#define DATE    1
#define ALARM   2
/************************************************************************/

/* Macro used for function: Print_Notification_LPUART() */
#define TIME_SUCCESS	0
#define TIME_ERROR		1
#define DATE_SUCCESS	2
#define DATE_ERROR		3
#define ALARM_SUCCESS	4
#define ALARM_ERROR		5

enum MonthOfYear
{
    January = 1,
    Febuary,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

/* Variable that use to transmit value of SECOND - MINUTE - HOUR to LED */
uint16_t cSecond = 0x0100;          /* LED 0 */
uint16_t cCountSecond = 0x0200;     /* LED 1 */
uint16_t cMinute = 0x0400;          /* LED 4 */
uint16_t cCountMinute = 0x0500;     /* LED 5 */
uint16_t cHour = 0x0700;            /* LED 7 */
uint16_t cCountHour = 0x0800;       /* LED 8 */

/* Variable that use to transmit value of DAY - MONTH - YEAR to LED */
uint16_t cYear = 0x0101;            /* LED 0 */
uint16_t cCountYear_1 = 0x0207;     /* LED 1 */
uint16_t cCountYear_2 = 0x0309;     /* LED 2 */
uint16_t cCountYear_3 = 0x0401;     /* LED 3 */
uint16_t cMonth = 0x0501;           /* LED 4 */
uint16_t cCountMonth = 0x0600;      /* LED 5 */
uint16_t cDay = 0x0701;             /* LED 6 */
uint16_t cCountDay = 0x0800;        /* LED 7 */

/* Variable that check current time when the program running */
uint8_t cSecondVar = 0;         /* Variable take Day current value */
uint8_t cMinuteVar = 0;         /* Variable take Month current value */
uint8_t cHourVar = 0;           /* Variable take Hour current value */
uint8_t cDayVar = 1;            /* Variable take Day current value */
uint8_t cMonthVar = 1;          /* Variable take Month current value */
uint16_t cYearVar = 1971;       /* Variable take Year current value */

/* Variable that check alarm clock */
uint8_t cAlarmSecondUART = 0;         /* Variable take Alarm Second value from LPUART */
uint8_t cAlarmMinuteUART = 0;         /* Variable take Alarm Minute value from LPUART */
uint8_t cAlarmHourUART = 0;           /* Variable take Alarm Hour value from LPUART */

uint8_t cAlarmSecond = 'A';         /* Variable take Alarm Second value */
uint8_t cAlarmMinute = 'A';         /* Variable take Alarm Minute value */
uint8_t cAlarmHour = 'A';           /* Variable take Alarm Hour value */
uint8_t cAlarmCheck = 0;           /* Variable check Alarm status */   


/* String to get data from LPUART */
char sReceiveData[20];
/* Number of character sReceiveData[20] receive */
uint8_t cNumOfChar = 0;


/*****************************************************************************************************************************************************************
 * 
 * RECEIVE DATA FROM LPUART
 * 
*****************************************************************************************************************************************************************/
void Receive_Time_Data(void)
{
    Receive_Time_LPUART();
    Receive_Date_LPUART();
    Receive_Alarm_LPUART();
}
/*****************************************************************************************************************************************************************
 * 
 * COUNT TIME TO DISPLAY ON LED
 * 
*****************************************************************************************************************************************************************/
void Count_Date_Time(void)
{
    Count_Time();
    Count_Date();
}
/*****************************************************************************************************************************************************************
 * 
 * DISPLAY TIME ON LED
 * 
*****************************************************************************************************************************************************************/
void Display_Time(void)
{
    /* SECOND */
    Transmit(cSecond);
    Transmit(cCountSecond);

    /* DISTANCE BETWEEN SECOND AND MINUTE */
    Transmit(0x030A);

    /* MINUTE */ 
    Transmit(cMinute);
    Transmit(cCountMinute);

    /* DISTANCE BETWEEN MINUTE AND HOUR */
    Transmit(0x060A);

    /* HOUR */
    Transmit(cHour);
    Transmit(cCountHour);
}
/*****************************************************************************************************************************************************************
 * 
 * DISPLAY DATE ON LED
 * 
*****************************************************************************************************************************************************************/
void Display_Date(void)
{
    /* DAY */
    /* Set Decimal point at day */
	cDay = cDay | (1 << 7);
    Transmit(cDay);
    Transmit(cCountDay);

    /* MONTH */ 
    /* Set decimal point at month */
	cMonth = cMonth | (1 << 7);
    Transmit(cMonth);
    Transmit(cCountMonth);

    /* YEAR */
    Transmit(cYear);
    Transmit(cCountYear_1);
    Transmit(cCountYear_2);
    Transmit(cCountYear_3);
	
	/* Clear decimal point at day */
	cDay = cDay & ~(1 << 7);
	/* Clear decimal point at month */
	cMonth = cMonth & ~(1 << 7);
}
/*****************************************************************************************************************************************************************
 * 
 * ASSIGN TIME/DATE VALUEs FROM LPUART TO LED VARIABLES
 * 
*****************************************************************************************************************************************************************/
void Assign_Time_Date_Value_LED(uint8_t cTimeValue)
{
    if(cTimeValue == DATE)
    {
        /* DAY */
        cDay = (0x07 << 8) | (sReceiveData[1] - 48);
        cCountDay = (0x08 << 8) | (sReceiveData[0] - 48);

        /* MONTH */
        cMonth = (0x05 << 8) | (sReceiveData[4] - 48);
        cCountMonth = (0x06 << 8) | (sReceiveData[3] - 48);

        /* YEAR */
        cYear = (0x01 << 8) | (sReceiveData[9] - 48);
        cCountYear_1 = (0x02 << 8) | (sReceiveData[8] - 48);
        cCountYear_2 = (0x03 << 8) | (sReceiveData[7] - 48);
        cCountYear_3 = (0x04 << 8) | (sReceiveData[6] - 48);
    }

    if(cTimeValue == TIME)
    {
         /* SECOND */
        cSecond = (0x01 << 8) | (sReceiveData[7] - 48);
        cCountSecond = (0x02 << 8) | (sReceiveData[6] - 48);

        /* MINUTE */
        cMinute = (0x04 << 8) | (sReceiveData[4] - 48);
        cCountMinute = (0x05 << 8) | (sReceiveData[3] - 48);

        /* HOUR */
        cHour = (0x07 << 8) | (sReceiveData[1] - 48);
        cCountHour = (0x08 << 8) | (sReceiveData[0] - 48);
    }
    
}
/*****************************************************************************************************************************************************************
 * 
 * PRINT "ASSIGN TIME/DATE SUCCESSFULLY" OR "ERROR" THROUGH LPUART
 * 
*****************************************************************************************************************************************************************/
void Print_Notification_LPUART(uint8_t cNotification)
{
	char* pPointer = NULL;       /* Pointer that point to string */
	char cIndex = 0;             /* Length of string */
	
	switch (cNotification)
	{
		case TIME_SUCCESS:
		pPointer = "\nAssign TIME successfully.\n";
		cIndex = 27;
		break;
		
		case TIME_ERROR:
		pPointer = "\nAssign TIME fail!\n";
		cIndex = 19;
		break;
		
		case DATE_SUCCESS:
		pPointer = "\nAssign DATE successfully.\n";
		cIndex = 27;
		break;
		
		case DATE_ERROR:
		pPointer = "\nAssign DATE fail!\n";
		cIndex = 19;
		break;

        case ALARM_SUCCESS:
		pPointer = "\nAssign ALARM successfully.\n";
		cIndex = 28;
		break;
		
		case ALARM_ERROR:
		pPointer = "\nAssign ALARM fail!\n";
		cIndex = 20;
		break;
	}
	
    /*Transmit string via LPUART1*/
	for(int iCount = 0; iCount < cIndex; iCount++)
	{
        /* Wait for transmit buffer to be empty */
		while(CheckBit(&(LPUART_1 -> STAT), 23) == 0);
		
		LPUART_1 -> DATA = pPointer[iCount];
	}
}
/*****************************************************************************************************************************************************************
 * 
 * CHANGE CHARACTER FROM LPUART TO DECIMAL VALUE
 * 
*****************************************************************************************************************************************************************/
void Character_To_Decimal(uint8_t cTimeValue)
{
    if(cTimeValue == TIME)
    {
        /* Assign value for varible that take second value */
        cSecondVar = (sReceiveData[6] - 48) * 10 + (sReceiveData[7] - 48) * 1;
        /* Assign value for varible that take minute value */
        cMinuteVar = (sReceiveData[3] - 48) * 10 + (sReceiveData[4] - 48) * 1;       
        /* Assign value for varible that take hour value */
        cHourVar = (sReceiveData[0] - 48) * 10 + (sReceiveData[1] - 48) * 1;
    }

    if(cTimeValue == ALARM)
    {
        /* Assign value for varible that take second value */
        cAlarmSecondUART = (sReceiveData[6] - 48) * 10 + (sReceiveData[7] - 48) * 1;
        /* Assign value for varible that take minute value */
        cAlarmMinuteUART = (sReceiveData[3] - 48) * 10 + (sReceiveData[4] - 48) * 1;       
        /* Assign value for varible that take hour value */
        cAlarmHourUART = (sReceiveData[0] - 48) * 10 + (sReceiveData[1] - 48) * 1;
    }

    if(cTimeValue == DATE)
    {
         /* Assign value for varible that take day value */
        cDayVar = (sReceiveData[0] - 48) * 10 + (sReceiveData[1] - 48) * 1;      
        /* Assign value for varible that take month value */
        cMonthVar = (sReceiveData[3] - 48) * 10 + (sReceiveData[4] - 48) * 1;       
        /* Assign value for varible that take year value */
        cYearVar = (sReceiveData[6] - 48) * 1000 + (sReceiveData[7] - 48) * 100 + (sReceiveData[8] - 48) * 10 + (sReceiveData[9] - 48) * 1;
    }
}
/*****************************************************************************************************************************************************************
 * 
 * TRANSMIT DATA TO LED
 * 
*****************************************************************************************************************************************************************/
void Transmit(uint32_t iValue)
{
	while( CheckBit(&(LPSPI_0 -> SR), 0) == 0);
	LPSPI_0 -> TDR = iValue;
	SetClearBit(&(LPSPI_0 -> SR), 10, SET_BIT);
}
/*****************************************************************************************************************************************************************
 * 
 * CALCULATE DAY IN MONTH
 * 
*****************************************************************************************************************************************************************/
uint8_t Days_In_Month_30_Or_31_Days(uint8_t cMonth)
{
    switch (cMonth) 
    {
        /* 31 days month */
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            return 31;
        /* 30 days month */
        case April:
        case June:
        case September:
        case November:
            return 30;
        /*  Febuary or invalid month */
        default:
            return 0; 
    }
}
/*****************************************************************************************************************************************************************
 * 
 * Check alarm time with current time
 * 
*****************************************************************************************************************************************************************/
void Check_Alarm_Time(void)
{
    if(cAlarmSecond == cSecondVar && cAlarmMinute == cMinuteVar && cAlarmHour == cHourVar)
    {
        cAlarmCheck = 1;    /* Alarm Flag */

        /* Reset  Alarm Time */
        cAlarmHour = 'A';
        cAlarmMinute = 'A';
        cAlarmSecond = 'A';
    }

}
/*****************************************************************************************************************************************************************
*
* LPUART RECEIVE DATA FOR SECOND - MINUTE - HOUR
*
*****************************************************************************************************************************************************************/    
void Receive_Time_LPUART(void)
{
     /* Check last character fom LPUART */
    if( sReceiveData[cNumOfChar - 1] == 't')
    {
        /* Check format of data (length) transmit from LPUART */
		if ((cNumOfChar - 1) != 8 )
		{
		    Print_Notification_LPUART(TIME_ERROR);
			/* Reset String receive data */
			memset(sReceiveData, 0, 10);
			cNumOfChar = 0;
			return;
		}
    
        /* Change character of time from LPUART to decimal value */
        Character_To_Decimal(TIME);

        /* Assign value for LED through SPI */
        if(cSecondVar <= 59 && cMinuteVar <= 59 && cHourVar <= 23)
        {
            /* Assign Time value for LED through SPI */
            Assign_Time_Date_Value_LED(TIME);
            /* Assign success through LPUART */
			Print_Notification_LPUART(TIME_SUCCESS);
        }
        else
        {
            /* Assign fail through LPUART */
	        Print_Notification_LPUART(TIME_ERROR);
        }

        /* Reset String receive data */
        memset(sReceiveData, 0, 10);
        cNumOfChar = 0;
    }
}
/*****************************************************************************************************************************************************************
*
* LPUART RECEIVE DATA FOR DAY - MONTH - YEAR
*
*****************************************************************************************************************************************************************/   
void Receive_Date_LPUART(void)
{
    /* Check last character fom LPUART */
    if( sReceiveData[cNumOfChar - 1] == 'd')
    {
        /* Check format of data (length) transmit from LPUART */
		if ((cNumOfChar - 1) != 10 )
		{
		    Print_Notification_LPUART(TIME_ERROR);
			/* Reset String receive data */
			memset(sReceiveData, 0, 10);
			cNumOfChar = 0;
			return;
		}

        /* Change character of date from LPUART to decimal value for day - month - year */
        Character_To_Decimal(DATE);

        /*****************************************************************************************************************************************************************
        * CHECK DATE VALUE OF FEBUARY FROM LPUART
        *****************************************************************************************************************************************************************/
		if(cMonthVar == Febuary && cDayVar > 0 && cDayVar <= 29)
		{
            /* If year is leap year */
			if((((cYearVar % 4 == 0) && (cYearVar % 100!= 0)) || (cYearVar%400 == 0)) && cDayVar <= 29)
			{
                /* Assign Date value for LED through SPI */
                Assign_Time_Date_Value_LED(DATE);

                /* Assign success through LPUART */
				Print_Notification_LPUART(DATE_SUCCESS);
			}
			
            /* If year is not leap year */
			else if(cDayVar <= 28)
			{
                /* Assign Date value for LED through SPI */
				Assign_Time_Date_Value_LED(DATE);
                /* Assign success through LPUART */
				Print_Notification_LPUART(DATE_SUCCESS);
            }
			
			/* If DAY or MONTH invalid */
			else 
			{
				/* Assign fail through LPUART */
				Print_Notification_LPUART(DATE_ERROR);
			}
        }

        /*****************************************************************************************************************************************************************
        * CHECK DATE VALUE OF 30-31 DAYS MONTH FROM LPUART
        *****************************************************************************************************************************************************************/
        else if (cDayVar > 0 && cDayVar <= Days_In_Month_30_Or_31_Days(cMonthVar))
        {
            /* Assign Date value for LED through SPI */
            Assign_Time_Date_Value_LED(DATE);
            /* Assign success through LPUART */
            Print_Notification_LPUART(DATE_SUCCESS);
        } 

        /* If DAY or MONTH invalid */
        else 
        {
            /* Assign fail through LPUART */
            Print_Notification_LPUART(DATE_ERROR);
        }

        /* Reset String receive data from LPUART for new command */
        memset(sReceiveData, 0, 10);
        cNumOfChar = 0;
                
    }
}
/*****************************************************************************************************************************************************************
*
* LPUART RECEIVE DATA FOR ALARM TIME
*
*****************************************************************************************************************************************************************/	
void Receive_Alarm_LPUART(void)
{	
    /* Check last character fom LPUART */
	if( sReceiveData[cNumOfChar - 1] == 'a')
    {
		/* Check format of data (length) transmit from LPUART */
		if ((cNumOfChar - 1) != 8 )
		{
		    Print_Notification_LPUART(ALARM_ERROR);
			/* Reset String receive data */
			memset(sReceiveData, 0, 10);
			cNumOfChar = 0;
			return;
		}
		
        /* Change character of time from LPUART to decimal value for alarmm time */
        Character_To_Decimal(ALARM);

        /* Assign value for LED variables */
        if(cAlarmSecondUART <= 59 && cAlarmMinuteUART <= 59 && cAlarmHourUART <= 23)
        {
            /* Assign Alarm Time value for LED through SPI */
            /* SECOND */
            cAlarmSecond = cAlarmSecondUART;                   
            /* MINUTE */
            cAlarmMinute = cAlarmMinuteUART;
            /* HOUR */
            cAlarmHour = cAlarmHourUART;
            
            /* Assign success through LPUART */
			Print_Notification_LPUART(ALARM_SUCCESS);
        }
        else
        {
            /* Assign fail through LPUART */
	        Print_Notification_LPUART(ALARM_ERROR);
        }

        /* Reset String receive data */
        memset(sReceiveData, 0, 10);
        cNumOfChar = 0;
    }
	
}
/*****************************************************************************************************************************************************************
*
* CALCULATE SECOND - MINUTE - HOUR
*
*****************************************************************************************************************************************************************/  
void Count_Time(void)
{
    /* If cSecond is 10, reset to 0 and increment cCountSecond */
    if(cSecond == 0x010A)              
    {
        cSecond = 0X0100;
        cCountSecond++;
    }

    /* If cCountSecond is 6 (Second is 60s), reset to 0 and increment cMinute */
    if(cCountSecond == 0X0206)
    {
        cCountSecond = 0X0200;
        cMinute++;
        cMinuteVar++;   /* Variable keep current minute value */
    }

    /* If cMinute is 10, reset to 0 and increment cCountMinute */
	if(cMinute == 0X040A)
    {
	    cMinute = 0x0400;
        cCountMinute++; 
    }

    /* If cCountMinute is 6 (Minute is 60 minutes), reset to 0 and increment cHour */
    if(cCountMinute == 0x0506)
    {
		cCountMinute = 0x0500;
        cHour++;
        cHourVar++;     /* Variable keep current hour value */
	}

    /* If cHour is 10, reset to 0 and increment cCountHour */ 
	if(cHour == 0x070A)
    {
        cHour = 0x0700;
        cCountHour++;
    }
	
    /* If time is 24:00:00, reset all value, increment cDay */
    if(cCountHour == 0x0802 && cHour == 0x0704)
    {
        cSecond = 0x0100;
		cCountSecond = 0x0200;
        cMinute = 0x0400;
        cCountMinute = 0x0500;
        cHour = 0x0700;
        cCountHour = 0x0800;

        cDay++;
        cDayVar++;      /* Variable keep current day value */
    }
}
/*****************************************************************************************************************************************************************
*
* CALCULATE DAY - MONTH - YEAR
*
*****************************************************************************************************************************************************************/  
void Count_Date(void)
{
    /* If cDay is 10, reset to 0 and increment cCountDay */ 
    if(cDay == 0x070A)
    {
        cDay = 0x0700;
        cCountDay++;
    }

    /*****************************************************************************************************************************************************************
    *  31 DAYS IN MONTH
    *****************************************************************************************************************************************************************/
    /* Calculate day if month have 31 days is 1, 3, 5, 7, 8, 10, 12 */
    if(Days_In_Month_30_Or_31_Days(cMonthVar) == 31)
    {
        /* If day is 32, reset day to 1 and increment cMonth */
        if(cCountDay == 0x0803 && cDay == 0x0702)
        {
            cDay = 0x0701;
            cCountDay = 0x0800;

            cMonth++;
            cMonthVar++;       /* Variable keep current month value */
        }

    }

    /*****************************************************************************************************************************************************************
    *  30 DAYS IN MONTH
    *****************************************************************************************************************************************************************/
    /* Calculate day if month have 30 days is 4, 6, 9, 11 */  
    if(Days_In_Month_30_Or_31_Days(cMonthVar) == 30)
    {
        /* If day is 31, reset day to 1 and increment cMonth */
        if(cCountDay == 0x0803 && cDay == 0x0701)
        {
            cDay = 0x0701;
            cCountDay = 0x0800;

            cMonth++;
            cMonthVar++;        /* Variable keep current month value */
        }
        
    }

    /*****************************************************************************************************************************************************************
    *  MONTH IS FEBUARY
    *****************************************************************************************************************************************************************/
    if(cMonthVar == Febuary)
    {

        /* If Year is leap year */
        if(((cYearVar % 4 == 0) && (cYearVar % 100 != 0)) || (cYearVar % 400 == 0))
        {
            /* If day is 30, reset day to 1 and increment cMonth */
            if(cCountDay == 0x0803 && cDay == 0x0700)
            {
                cDay = 0x0701;
                cCountDay = 0x0800;

                cMonth++;
                cMonthVar++;        /* Variable keep current month value */
            }

        }
        /* If year is not leap year */
        else
        {
            /* If day is 29, reset day to 01 and increment cMonth */
            if(cCountDay == 0x0802 && cDay == 0x0709)
            {
                cDay = 0x0701;
                cCountDay = 0x0800;

                cMonth++;
                cMonthVar++;    /* Variable keep current month value */
            }

        }
        
    }

    /* If cMonth is 10, reset to 0, increment cCountMonth */
    if(cMonth == 0x050A)
    {
        cMonth = 0x0500;
        cCountMonth++;
    }

     /* If month is 13, reset month to 01 and increment cYear */
    if(cCountMonth == 0x0601 && cMonth == 0x0503)
    {
        cCountMonth = 0x0600;
        cMonth = 0x0501;
		
		cYear++;
        cYearVar++;     /* Variable keep current year value */
    }

    /* If cYear is 10, reset to 0, increment cCountYear_1 */
	if(cYear == 0x010A)
	{
		cYear = 0x0100;
		cCountYear_1++;
	}
	
    /* If cCountYear_1 is 10, reset to 0, increment cCountYear_2 */
	if(cCountYear_1 == 0x020A && cYear == 0x0100)
	{
		cCountYear_1 = 0x0200;
        cCountYear_2++;
	}

    /* If cCountYear_2 is 10, reset to 0, increment cCountYear_3 */
    if(cCountYear_2 == 0x030A && cCountYear_1 == 0x0200 && cYear == 0x0100)
    {
        cCountYear_2 = 0x0300;
        cCountYear_3++;
    }
	
	/* If year is 10000 */
	if(cYearVar == 10000)
    {
        /* Reset year to be 1971 */
		cYear = 0x0101;
		cCountYear_1 = 0x0207;
		cCountYear_2 = 0x0309;
		cCountYear_3 = 0x0401;
    }
}







