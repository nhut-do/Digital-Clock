#include "../inc/Mock_Library.h"
#include "../inc/LPSPI.h"

/*****************************************************************************************************************************************************************
 * 
 * SELECT CLOCK SOURCE FOR LPSPI
 * 
*****************************************************************************************************************************************************************/
void Setting_LPSPI_Pin(uint8_t cPort, uint8_t cPin, uint8_t* pPinMux)
{
    uint32_t* pPointer = NULL;				/* Pointer used to get which PORT has pin choosen to be LPSPI pin */

    switch(cPort)
	{
		case PORTA:
            pPointer = (uint32_t*) PORT_A;  
			SetClearBit(&(PCC -> PCC_PORTA), 30, SET_BIT);
            SetClearListOfBit(&pPointer[cPin], 8, 10, pPinMux);
			break;

		case PORTB:
            pPointer = (uint32_t*) PORT_B;
			SetClearBit(&(PCC -> PCC_PORTB), 30, SET_BIT);
            SetClearListOfBit(&pPointer[cPin], 8, 10, pPinMux);
			break;

		case PORTC:
            pPointer = (uint32_t*) PORT_C;
			SetClearBit(&(PCC -> PCC_PORTC), 30, SET_BIT);
            SetClearListOfBit(&pPointer[cPin], 8, 10, pPinMux);
			break;

		case PORTD:
            pPointer = (uint32_t*) PORT_D;
			SetClearBit(&(PCC -> PCC_PORTD), 30, SET_BIT);
            SetClearListOfBit(&pPointer[cPin], 8, 10, pPinMux);
			break;

		case PORTE:
            pPointer = (uint32_t*) PORT_E;
			SetClearBit(&(PCC -> PCC_PORTE), 30, SET_BIT);
            SetClearListOfBit(&pPointer[cPin], 8, 10, pPinMux);
			break;
	}
}
/*****************************************************************************************************************************************************************
 * 
 * SELECT CLOCK SOURCE FOR LPSPI
 * 
*****************************************************************************************************************************************************************/
void Clock_Source_LPSPI(uint8_t cLPSPI, uint8_t* pClock_Select)
{
    switch (cLPSPI)
    {
        case LPSPI0:
            //Peripheral Clock Source Select: PCC[PCS]
            SetClearListOfBit(&(PCC -> PCC_LPSPI0), 24, 26, (unsigned char* )"010");
            //Enable clock for LPSPI: PCC[CGC]
            SetClearBit(&(PCC -> PCC_LPSPI0), 30, SET_BIT);
            break;

        case LPSPI1:
            //Peripheral Clock Source Select: PCC[PCS]
            SetClearListOfBit(&(PCC -> PCC_LPSPI1), 24, 26, (unsigned char* )"010");
            //Enable clock for LPSPI: PCC[CGC]
            SetClearBit(&(PCC -> PCC_LPSPI1), 30, SET_BIT);
            break;

        case LPSPI2:
            //Peripheral Clock Source Select: PCC[PCS]
            SetClearListOfBit(&(PCC -> PCC_LPSPI2), 24, 26, (unsigned char* )"010");
            //Enable clock for LPSPI: PCC[CGC]
            SetClearBit(&(PCC -> PCC_LPSPI2), 30, SET_BIT);
            break;            
    }
}
/*****************************************************************************************************************************************************************
 * 
 * SETTING CLOCK FOR LPSPI
 * 
*****************************************************************************************************************************************************************/
void LPSPI_Setting_Clock(uint8_t cLPSPI, uint8_t* pPRESCALE, uint8_t cSCKDIV)
{
    /* The SCK period is equal to (SCKDIV+2) cycles */
    cSCKDIV = cSCKDIV - 2;

    switch(cLPSPI)
    {
        case LPSPI0:
            //Set Prescaler Value: TCR[PRESCALE]
            SetClearListOfBit(&(LPSPI_0 -> TCR), 27, 29, pPRESCALE);
            //Set divide ratio of the SCK pin: CCR[SCKDIV]
            LPSPI_0 -> CCR |= cSCKDIV;
            break;

        case LPSPI1:
            //Set Prescaler Value: TCR[PRESCALE]
            SetClearListOfBit(&(LPSPI_1 -> TCR), 27, 29, pPRESCALE);
            //Set divide ratio of the SCK pin: CCR[SCKDIV]
            LPSPI_1 -> CCR |= cSCKDIV;
            break;

        case LPSPI2:
            //Set Prescaler Value: TCR[PRESCALE]
            SetClearListOfBit(&(LPSPI_2 -> TCR), 27, 29, pPRESCALE);
            //Set divide ratio of the SCK pin: CCR[SCKDIV]
            LPSPI_2 -> CCR |= cSCKDIV;
            break;       
    }
}


/*****************************************************************************************************************************************************************
 * 
 * CONFIGURES CLOCK PHASE AND POLARITY
 * 
*****************************************************************************************************************************************************************/
void LPSPI_CPOL_CPHA(uint8_t cLPSPI, uint8_t cCPOL, uint8_t cCPHA)
{
    switch(cLPSPI)
    {
        case LPSPI0:
            //Set Clock Polarity: TCR[CPOL]
            SetClearBit(&(LPSPI_0 -> TCR), 31, cCPOL);
            //Set Clock Phase: TCR[CPHA]
            SetClearBit(&(LPSPI_0 -> TCR), 30, cCPHA);
            break;

        case LPSPI1:
            //Set Clock Polarity: TCR[CPOL]
            SetClearBit(&(LPSPI_1 -> TCR), 31, cCPOL);
            //Set Clock Phase: TCR[CPHA]
            SetClearBit(&(LPSPI_1 -> TCR), 30, cCPHA);
            break;

        case LPSPI2:
            //Set Clock Polarity: TCR[CPOL]
            SetClearBit(&(LPSPI_2 -> TCR), 31, cCPOL);
            //Set Clock Phase: TCR[CPHA]
            SetClearBit(&(LPSPI_2 -> TCR), 30, cCPHA);
            break;       
    }
}
/*****************************************************************************************************************************************************************
 * 
 * SETTING FRAME DATA
 * 
*****************************************************************************************************************************************************************/
void LPSPI_Frame_Data(uint8_t cLPSPI, uint8_t cFRAMESZ, uint8_t cLSBF)
{
    /* Configures the frame size in number of bits equal to (FRAMESZ + 1) */
    cFRAMESZ = cFRAMESZ - 1;

    switch(cLPSPI)
    {
        case LPSPI0:
            //Set Frame Size: TCR[FRAMESZ]
            LPSPI_0 -> TCR |= cFRAMESZ;      
            //Set type of transfer data: TCR[LSBF]
            SetClearBit(&(LPSPI_0 -> TCR), 23, cLSBF);                                 
            break;

        case LPSPI1:
            //Set Frame Size: TCR[FRAMESZ]
            LPSPI_1 -> TCR |= cFRAMESZ;     
            //Set type of transfer data: TCR[LSBF]
            SetClearBit(&(LPSPI_1 -> TCR), 23, cLSBF);                                
            break;

        case LPSPI2:
            //Set Frame Size: TCR[FRAMESZ]
            LPSPI_2 -> TCR |= cFRAMESZ;     
            //Set type of transfer data: TCR[LSBF]
            SetClearBit(&(LPSPI_2 -> TCR), 23, cLSBF);                                
            break;       
    }
}
/*****************************************************************************************************************************************************************
 * 
 * CONFIGURES THE PERIPHERAL CHIP SELECT
 * 
*****************************************************************************************************************************************************************/
void Config_LPSPI_PCS(uint8_t cLPSPI, uint8_t* pPCS)
{
    switch(cLPSPI)
    {
        case LPSPI0:
            /*Configures the peripheral chip select: TCR[PCS]*/
            SetClearListOfBit(&(LPSPI_0 -> TCR), 24, 25, pPCS);                              
            break;

        case LPSPI1:
            /*Configures the peripheral chip select: TCR[PCS]*/
            SetClearListOfBit(&(LPSPI_1 -> TCR), 24, 25, pPCS);                             
            break;

        case LPSPI2:
            /*Configures the peripheral chip select: TCR[PCS]*/
            SetClearListOfBit(&(LPSPI_2 -> TCR), 24, 25, pPCS);                           
            break;       
    }
}
/*****************************************************************************************************************************************************************
 * 
 * SETTING TRANSMIT/RECEIVE FIFO
 * 
*****************************************************************************************************************************************************************/
void LPSPI_Transmit_Receive_FIFO(uint8_t cLPSPI, uint8_t* pRXWATER, uint8_t* pTXWATER, uint8_t cNOSTALL)
{
    switch(cLPSPI)
    {
        case LPSPI0:
            //Set Receive FIFO Watermark: FCR[RXWATER]
            SetClearListOfBit(&(LPSPI_0 -> FCR), 16, 17, pRXWATER);
            //Set Receive FIFO Watermark: FCR[TXWATER]
            SetClearListOfBit(&(LPSPI_0 -> FCR), 0, 1, pTXWATER);
            //Set FIFO underrun: CFGR1[NOSTALL]
            SetClearBit(&(LPSPI_0 -> CFGR1), 3, cNOSTALL);                            
            break;

        case LPSPI1:
            //Set Receive FIFO Watermark: FCR[RXWATER]
            SetClearListOfBit(&(LPSPI_1 -> FCR), 16, 17, pRXWATER);
            //Set Receive FIFO Watermark: FCR[TXWATER]
            SetClearListOfBit(&(LPSPI_1 -> FCR), 0, 1, pTXWATER);
            //Set FIFO underrun: CFGR1[NOSTALL]
            SetClearBit(&(LPSPI_1 -> CFGR1), 3, cNOSTALL);                             
            break;

        case LPSPI2:
            //Set Receive FIFO Watermark: FCR[RXWATER]
            SetClearListOfBit(&(LPSPI_2 -> FCR), 16, 17, pRXWATER);
            //Set Receive FIFO Watermark: FCR[TXWATER]
            SetClearListOfBit(&(LPSPI_2 -> FCR), 0, 1, pTXWATER);
            //Set FIFO underrun: CFGR1[NOSTALL]
            SetClearBit(&(LPSPI_2 -> CFGR1), 3, cNOSTALL);                            
            break;       
    } 
}
/*****************************************************************************************************************************************************************
 * 
 * CONFIGURES LPSPI MODE
 * 
*****************************************************************************************************************************************************************/
void LPSPI_Config_Mode(uint8_t cLPSPI, uint8_t cLPSPIMode, uint8_t DebugEnable)
{
    switch(cLPSPI)
    {
        case LPSPI0:
            //Set Mode: CFGR1[MASTER]
            SetClearBit(&(LPSPI_0 -> CFGR1), 0, cLPSPIMode);
            /* Debug Enable: CR[DBGEN] */
            SetClearBit(&(LPSPI_0 -> CR), 3, DebugEnable);                            
            break;

        case LPSPI1:
            //Set Mode: CFGR1[MASTER]
            SetClearBit(&(LPSPI_1 -> CFGR1), 0, cLPSPIMode);
            /* Debug Enable: CR[DBGEN] */
            SetClearBit(&(LPSPI_1 -> CR), 3, DebugEnable);                       
            break;

        case LPSPI2:
            //Set Mode: CFGR1[MASTER]
            SetClearBit(&(LPSPI_2 -> CFGR1), 0, cLPSPIMode);
            /* Debug Enable: CR[DBGEN] */
            SetClearBit(&(LPSPI_2 -> CR), 3, DebugEnable);                        
            break;       
    }
}
/*****************************************************************************************************************************************************************
 * 
 * ENABLE LPSPI MODULE
 * 
*****************************************************************************************************************************************************************/
void Enable_LPSPI(uint8_t cLPSPI, uint8_t cEnable)
{
    switch(cLPSPI)
    {
        case LPSPI0:
            /*Enable LPSPI module: CR[MEN]*/
            SetClearBit(&(LPSPI_0 -> CR), 0, cEnable);                           
            break;

        case LPSPI1:
            /*Enable LPSPI module: CR[MEN]*/
            SetClearBit(&(LPSPI_1 -> CR), 0, cEnable);                       
            break;

        case LPSPI2:
            /*Enable LPSPI module: CR[MEN]*/
            SetClearBit(&(LPSPI_2 -> CR), 0, cEnable);                  
            break;       
    }
/************************************************************************/    
}
