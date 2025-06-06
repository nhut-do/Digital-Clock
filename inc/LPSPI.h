#ifndef LPSPI_H
#define LPSPI_H

/************************************************************************/
/*****************************************************************************************************************************************************************
 * 
 * DEFINE
 * 
*****************************************************************************************************************************************************************/
/* LPSPI options */
#define LPSPI0  0
#define LPSPI1  1
#define LPSPI2  2

/* Prescale options */
#define Prescale_Divide_by_1     (unsigned char*)"000"
#define Prescale_Divide_by_2     (unsigned char*)"001"
#define Prescale_Divide_by_4     (unsigned char*)"010"
#define Prescale_Divide_by_8     (unsigned char*)"011"
#define Prescale_Divide_by_16    (unsigned char*)"100"
#define Prescale_Divide_by_32    (unsigned char*)"101"
#define Prescale_Divide_by_64    (unsigned char*)"110"
#define Prescale_Divide_by_128   (unsigned char*)"111"

/* Clock Phase and Polarity options */
#define CPOL_1      1
#define CPOL_0      0
#define CPHA_1      1
#define CPHA_0      0

/* Type of transfer */
#define LSBF_MSB    0
#define LSBF_LSB    1

/* peripheral chip select */
#define LPSPI_PCS0      (unsigned char*)"00"
#define LPSPI_PCS1      (unsigned char*)"01"
#define LPSPI_PCS2      (unsigned char*)"10"
#define LPSPI_PCS3      (unsigned char*)"11"

/* TXWATER options */
#define TXWATER0    (unsigned char*)"00"
#define TXWATER1    (unsigned char*)"01"
#define TXWATER2    (unsigned char*)"10"
#define TXWATER3    (unsigned char*)"11"

/* RXWATER options */
#define RXWATER0    (unsigned char*)"00"
#define RXWATER1    (unsigned char*)"01"
#define RXWATER2    (unsigned char*)"10"
#define RXWATER3    (unsigned char*)"11"

/* FIFO underrun */
#define NOSTALL_0   0
#define NOSTALL_1   1

/* LPSPI mode */
#define Slave_Mode   0
#define Master_Mode  1

/* Module enable */
#define Module_Disable   0
#define Module_Enable  1

/* Debug enable */
#define Debug_Disable   0
#define Debug_Enable    1

/*****************************************************************************************************************************************************************
 * 
 * LPSPI FUNCTIONS
 * 
*****************************************************************************************************************************************************************/
/* Setting SCK/PCS/SOUT/SIN pin */
void Setting_LPSPI_Pin(uint8_t cPort, uint8_t cPin, uint8_t* pPinMux);
/* Select clock source LPSPI */
void Clock_Source_LPSPI(uint8_t cLPSPI, uint8_t* pClock_Select);
/* Setting LPSPI Clock */
void LPSPI_Setting_Clock(uint8_t cLPSPI, uint8_t* pPRESCALE, uint8_t cSCKDIV);
/* Configures Clock Phase and Polarity */
void LPSPI_CPOL_CPHA(uint8_t cLPSPI, uint8_t cCPOL, uint8_t cCPHA);
/* Setting Frame data */
void LPSPI_Frame_Data(uint8_t cLPSPI, uint8_t cFRAMESZ, uint8_t cLSBF);
/* Configures the peripheral chip select */
void Config_LPSPI_PCS(uint8_t cLPSPI, uint8_t* pPCS);
/*Setting Transmit/Receive FIFO */
void LPSPI_Transmit_Receive_FIFO(uint8_t cLPSPI, uint8_t* pRXWATER, uint8_t* pTXWATER, uint8_t cNOSTALL);
/* Configures LPSPI mode */
void LPSPI_Config_Mode(uint8_t cLPSPI, uint8_t cLPSPIMode, uint8_t DebugEnable);
/* Enable LPSPI module */
void Enable_LPSPI(uint8_t cLPSPI, uint8_t cEnable);


#endif    /* LPSPI_H */


