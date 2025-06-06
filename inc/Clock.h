#ifndef CLOCK_H
#define CLOCK_H

/************************************************************************/
/*****************************************************************************************************************************************************************
 * 
 * DEFINE
 * 
*****************************************************************************************************************************************************************/
/* Select clock source */
#define FIRC    0
#define SIRC    1
#define SOSC    2
#define SPLL    3
#define LPO     4

/* Select reference clock source for SOSC */
#define EXTERNAL    0
#define INTERNAL    1

/* Peripheral Clock divider */
#define Devide_0    (unsigned char*)"000"
#define Devide_1    (unsigned char*)"001"
#define Devide_2    (unsigned char*)"010"
#define Devide_4    (unsigned char*)"011"
#define Devide_8    (unsigned char*)"100"
#define Devide_16   (unsigned char*)"101"
#define Devide_32   (unsigned char*)"110"
#define Devide_64   (unsigned char*)"111"

/*****************************************************************************************************************************************************************
 * 
 * CLOCK SOURCE FUNCTION
 * 
*****************************************************************************************************************************************************************/
/* Enable available clock source for peripheral */
void Init_Available_Peripheral_Clock(uint8_t cSourceClock, uint8_t* pDIV);
/* Enable SOSC clock source for peripheral */
void Init_SOSC_Peripheral_Clock(uint8_t cSourceClock, uint8_t* pDIV);


#endif   /* CLOCK_H */


