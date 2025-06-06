#include "../inc/Mock_Library.h"
#include "../inc/LPIT.h"


/*****************************************************************************************************************************************************************
 * 
 * SETTING CLOCK
 * 
*****************************************************************************************************************************************************************/
void LPIT_Init(uint8_t* pClock_Select)
{
    /* Peripheral Clock Source Select: PCC[PCS] */
    SetClearListOfBit(&(PCC -> PCC_LPIT), 24, 26, pClock_Select);
    /* Enable clock for LPIT: PCC[CGC] */
    SetClearBit(&(PCC -> PCC_LPIT), 30, SET_BIT);
}
/*****************************************************************************************************************************************************************
 * 
 * LPIT INITIALIZATION
 * 
*****************************************************************************************************************************************************************/
void LPIT_Initilazation(void)
{
    /* Module Clock Enable: MCR[M_CEN] */
    SetClearBit(&(LPIT -> MCR), 0, SET_BIT);
    /* Run in Debug mode: MCR[DBG_EN] */
    SetClearBit(&(LPIT -> MCR), 3, SET_BIT);
}
/*****************************************************************************************************************************************************************
 * 
 * LPIT CONFIGURATION
 * 
*****************************************************************************************************************************************************************/
void LPIT_Config(uint8_t cChannel, uint8_t* pOperation, uint8_t cInterrupt, uint32_t iValue)
{

    switch(cChannel)
    {
        case Channel_0:
            /* Enable Channel Timer Interrupt: MIER[TIEn] */
            SetClearBit(&(LPIT -> MIER), 0, cInterrupt);
            /* Set Timer Value start: TVALn */
            LPIT -> TVAL0 = iValue;
            /* Configuration for channel: TCTR​Ln[MODE] */
            SetClearListOfBit(&(LPIT -> TCTRL0), 2, 3, pOperation);
            /* Timer Channel + Enable Timer Channel: TCTR​Ln[T_EN] */
            SetClearBit(&(LPIT -> TCTRL0), 0, SET_BIT);          
            break;
        case Channel_1:
            /* Enable Channel Timer Interrupt: MIER[TIEn] */
            SetClearBit(&(LPIT -> MIER), 1, cInterrupt);
            /* Set Timer Value start: TVALn */
            LPIT -> TVAL1 = iValue;
            /* Configuration for channel: TCTR​Ln[MODE] */
            SetClearListOfBit(&(LPIT -> TCTRL1), 2, 3, pOperation);
            /* Timer Channel + Enable Timer Channel: TCTR​Ln[T_EN] */
            SetClearBit(&(LPIT -> TCTRL1), 0, SET_BIT);        
            break;
        case Channel_2:
            /* Enable Channel Timer Interrupt: MIER[TIEn] */
            SetClearBit(&(LPIT -> MIER), 2, cInterrupt);
            /* Set Timer Value start: TVALn */
            LPIT -> TVAL2 = iValue;
            /* Configuration for channel: TCTR​Ln[MODE] */
            SetClearListOfBit(&(LPIT -> TCTRL2), 2, 3, pOperation);
            /* Timer Channel + Enable Timer Channel: TCTR​Ln[T_EN] */
            SetClearBit(&(LPIT -> TCTRL2), 0, SET_BIT);          
            break;
        case Channel_3:
            /* Enable Channel Timer Interrupt: MIER[TIEn] */    
            SetClearBit(&(LPIT -> MIER), 3, cInterrupt);
            /* Set Timer Value start: TVALn */
            LPIT -> TVAL3 = iValue;
            /* Configuration for channel: TCTR​Ln[MODE] */
            SetClearListOfBit(&(LPIT -> TCTRL3), 2, 3, pOperation);
            /* Timer Channel + Enable Timer Channel: TCTR​Ln[T_EN] */
            SetClearBit(&(LPIT -> TCTRL3), 0, SET_BIT);
            break;
    }
/************************************************************************/
}




