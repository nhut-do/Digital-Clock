#ifndef LPUART_H
#define LPUART_H

/************************************************************************/
/*****************************************************************************************************************************************************************
 * 
 * DEFINE
 * 
*****************************************************************************************************************************************************************/
/* LPUART options */
#define LPUART0     0
#define LPUART1     1
#define LPUART2     2

/* Oversampling Ratio */
#define OSR_4       (unsigned char*)"00011"
#define OSR_5       (unsigned char*)"00100"
#define OSR_6       (unsigned char*)"00101"
#define OSR_7       (unsigned char*)"00110"
#define OSR_8       (unsigned char*)"00111"
#define OSR_9       (unsigned char*)"01000"
#define OSR_10      (unsigned char*)"01001"
#define OSR_11      (unsigned char*)"01010"
#define OSR_12      (unsigned char*)"01011"
#define OSR_13      (unsigned char*)"01100"
#define OSR_14      (unsigned char*)"01101"
#define OSR_15      (unsigned char*)"01110"
#define OSR_16      (unsigned char*)"01111"
#define OSR_17      (unsigned char*)"10000"

/* Stop Bit Number */
#define One_Stop_Bit    0
#define Two_Stop_Bit    1

/* Data characters number */
#define Mode_8_bit   0
#define Mode_9_bit   1

/* Parity bit */
#define Parity_Disable   0 
#define Parity_Enable    1 

/* LPUART Interrupt options */
#define TIE_Enable      1
#define TIE_Disable     0
#define RIE_Enable      1
#define RIE_Disable     0

/* LPUART Enable */
#define Transmit_Enable     1
#define Transmit_Disable    0
#define Receive_Enable      1
#define Receive_Disable     0

/*****************************************************************************************************************************************************************
 * 
 * LPUART FUNCTIONs
 * 
*****************************************************************************************************************************************************************/
/* Setting Tx/Rx pin */
void LPUART_RxTx_Config(uint8_t cPORT, uint8_t cPin, uint8_t* pPinMux);
/* Select clock source LPUART */
void Clock_Source_LPUART(uint8_t cLPUART, uint8_t* pClock_Select);
/* Setting baud rate */
void Set_Baud_Rate(uint8_t cLPUART, uint16_t iBaudRate, uint8_t* pOSR);
/* Setting frame */
void Set_Frame(uint8_t cLPUART, uint8_t cSBNS, uint8_t cMode, uint8_t cParity);
/* Enable Receiver/Transmitter Interrupt */
void LPUART_Interrupt(uint8_t cLPUART, uint8_t cTIE, uint8_t cRIE);
/* Enable transmitter & receiver */
void Enable_LPUART(uint8_t cLPUART, uint8_t cTrasmit, uint8_t cReceive);


#endif    /* LPUART */


