#include "../inc/Mock_Library.h"
#include "../inc/LPUART.h"

/************************************************************************/
/*****************************************************************************************************************************************************************
 * 
 * SETTING Tx/Rx PIN
 * 
*****************************************************************************************************************************************************************/
void LPUART_RxTx_Config(uint8_t cPORT, uint8_t cPin, uint8_t* pPinMux)
{
   switch (cPORT)
    {
        uint32_t* pPointer = NULL;				/* Pointer used to get which PORT has pin choosen to be LPUART RxTx */

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
 * SELECT CLOCK SOURCE FOR LPUART
 * 
*****************************************************************************************************************************************************************/
void Clock_Source_LPUART(uint8_t cLPUART, uint8_t* pClock_Select)
{
    switch (cLPUART)
    {
        case LPUART0:
            SetClearListOfBit(&(PCC ->PCC_LPUART0), 24, 26, pClock_Select);
            SetClearBit(&(PCC ->PCC_LPUART0), 30, HIGH);
            break;

        case LPUART1:
            SetClearListOfBit(&(PCC ->PCC_LPUART1), 24, 26, pClock_Select);
            SetClearBit(&(PCC ->PCC_LPUART1), 30, HIGH);
            break;

        case LPUART2:
            SetClearListOfBit(&(PCC ->PCC_LPUART2), 24, 26, pClock_Select);
            SetClearBit(&(PCC ->PCC_LPUART2), 30, HIGH);
            break;
    }
    
}
/*****************************************************************************************************************************************************************
 * 
 * SETTING BAUD RATE
 * 
*****************************************************************************************************************************************************************/
void Set_Baud_Rate(uint8_t cLPUART, uint16_t iBaudRate, uint8_t* pOSR)
{
    /* Calculate SBR value from Baudrate input */
    uint16_t iSBR = (uint16_t)(48000000 / (16 * iBaudRate));

    switch (cLPUART)
    {
        case LPUART0:
            LPUART_0 -> BAUD = iSBR;
            SetClearListOfBit(&(LPUART_0 -> BAUD), 13, 15, (unsigned char*)"000");
            SetClearListOfBit(&(LPUART_0 -> BAUD), 24, 28, pOSR);
            break;

        case LPUART1:
            LPUART_1 -> BAUD = iSBR;
            SetClearListOfBit(&(LPUART_1 -> BAUD), 13, 15, (unsigned char*)"000");
            SetClearListOfBit(&(LPUART_1 -> BAUD), 24, 28, pOSR);
            break;

        case LPUART2:
             LPUART_2 -> BAUD = iSBR;
            SetClearListOfBit(&(LPUART_2 -> BAUD), 13, 15, (unsigned char*)"000");
            SetClearListOfBit(&(LPUART_2 -> BAUD), 24, 28, pOSR);
            break;
    }

}
/*****************************************************************************************************************************************************************
 * 
 * SETTING FRAME
 * 
*****************************************************************************************************************************************************************/
void Set_Frame(uint8_t cLPUART, uint8_t cSBNS, uint8_t cMode, uint8_t cParity)
{
    switch (cLPUART)
    {
        case LPUART0:
        SetClearBit(&(LPUART_0 -> BAUD), 13, cSBNS);
        SetClearBit(&(LPUART_0 -> CTRL), 4, cMode);
        SetClearBit(&(LPUART_0 -> CTRL), 1, cParity);
        break;

        case LPUART1:
        SetClearBit(&(LPUART_1 -> BAUD), 13, cSBNS);
        SetClearBit(&(LPUART_1 -> CTRL), 4, cMode);
        SetClearBit(&(LPUART_1 -> CTRL), 1, cParity);
        break;

        case LPUART2:
        SetClearBit(&(LPUART_2 -> BAUD), 13, cSBNS);
        SetClearBit(&(LPUART_2 -> CTRL), 4, cMode);
        SetClearBit(&(LPUART_2 -> CTRL), 1, cParity);
        break;
    }
    
}
/*****************************************************************************************************************************************************************
 * 
 * ENABLE TRANSMITTER & RECEIVER
 * 
*****************************************************************************************************************************************************************/
void Enable_LPUART(uint8_t cLPUART, uint8_t cTrasmit, uint8_t cReceive)
{
    switch (cLPUART)
    {
        case LPUART0:
        SetClearBit(&(LPUART_0 -> CTRL), 19, cTrasmit);
        SetClearBit(&(LPUART_0 -> CTRL), 18, cReceive);
        break;

        case 1:
        SetClearBit(&(LPUART_1 -> CTRL), 19, cTrasmit);
        SetClearBit(&(LPUART_1 -> CTRL), 18, cReceive);
        break;

        case LPUART2:
        SetClearBit(&(LPUART_2 -> CTRL), 19, cTrasmit);
        SetClearBit(&(LPUART_2 -> CTRL), 18, cReceive);
        break;
    }
}
/*****************************************************************************************************************************************************************
 * 
 * LPUART INTERRUPT
 * 
*****************************************************************************************************************************************************************/
void LPUART_Interrupt(uint8_t cLPUART, uint8_t cTIE, uint8_t cRIE)
{
    switch (cLPUART)
    {
        case LPUART0:
        SetClearBit(&(LPUART_0 -> CTRL), 23, cTIE);
        SetClearBit(&(LPUART_0 -> CTRL), 21, cRIE);
        break;

        case LPUART1:
        SetClearBit(&(LPUART_1 -> CTRL), 23, cTIE);
        SetClearBit(&(LPUART_1 -> CTRL), 21, cRIE);
        break;

        case LPUART2:
        SetClearBit(&(LPUART_2 -> CTRL), 23, cTIE);
        SetClearBit(&(LPUART_2 -> CTRL), 21, cRIE);
        break;
    }
}






