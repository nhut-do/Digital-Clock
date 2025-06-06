#ifndef LPIT_H
#define LPIT_H

/************************************************************************/
/*****************************************************************************************************************************************************************
 * 
 * DEFINE
 * 
*****************************************************************************************************************************************************************/
/*4 Channel Of LPIT Timer*/
#define  Channel_0  0
#define  Channel_1  1
#define  Channel_2  2
#define  Channel_3  3

/* LPIT Timer Operation Mode */
#define  Operation_Mode_1   (unsigned char*)"00"
#define  Operation_Mode_2   (unsigned char*)"01"
#define  Operation_Mode_3   (unsigned char*)"10"
#define  Operation_Mode_4   (unsigned char*)"11"

/* Interrupt Enable */
#define Interrupt_Enable    1
#define Interrupt_Disable   0

/*****************************************************************************************************************************************************************
 * 
 * LPIT FUNCTIONS
 * 
*****************************************************************************************************************************************************************/
void LPIT_Init(uint8_t* pClock_Select);
void LPIT_Initilazation(void);
void LPIT_Config(uint8_t cChannel, uint8_t* pOperation, uint8_t cInterrupt, uint32_t iValue);


#endif    /* LPIT_H */

