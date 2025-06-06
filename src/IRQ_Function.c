#include "../inc/Mock_Library.h"
#include "../inc/IRQ.h"


/* Variable for IRQ Handler */
uint8_t cButton1 = 0;       /* Display time/date */
uint8_t cButton2 = 0;       /* Turn on/of display mode */
uint8_t cCountBlink = 0;    /* Count  for blinking LED */


/*****************************************************************************************************************************************************************
 * 
 * PORTC IRQ HANDLER
 * 
*****************************************************************************************************************************************************************/
void PORTC_IRQHandler(void)
{
    /* Interrupt that change varible cState = 0 or = 1 to dislay "Time" or "Date" */
    if(CheckBit(&(PORT_C -> PORT_PCR13), 24) == 1)
    {
        SetClearBit(&(PORT_C -> PORT_PCR13), 24, SET_BIT);
        cButton1 = !cButton1;
    }

    /* Interrupt thaat change variable cstate = 2 to turn off all led or turn on all led */
    if(CheckBit(&(PORT_C -> PORT_PCR12), 24) == 1)
    {
        SetClearBit(&(PORT_C -> PORT_PCR12), 24, SET_BIT);
        cButton2 = !cButton2;
    }
}
/*****************************************************************************************************************************************************************
 * 
 * SYSTICK HANDLER
 * 
*****************************************************************************************************************************************************************/
void SysTick_Handler(void) 
{
   
}
/*****************************************************************************************************************************************************************
 * 
 * LPUART1 RX/TX IRQ HANDLER
 * 
*****************************************************************************************************************************************************************/
void LPUART1_RxTx_IRQHandler(void)
{
    /* Receive string get character at each interrupt*/ 
	sReceiveData[cNumOfChar] = (char)(LPUART_1 -> DATA);
    /* Index + 1 */
	cNumOfChar++;
}
/*****************************************************************************************************************************************************************
 * 
 * LPIT0 CHANNEL 1 IRQ HANDLER
 * 
*****************************************************************************************************************************************************************/
void LPIT0_Ch1_IRQHandler(void)
{
    /* Clear flag */
    SetClearBit(&(LPIT -> MSR), 1, SET_BIT);

    /*After 1 second -> +1 */
    cSecond++;
    /* Current second */
    cSecondVar++;
}
/*****************************************************************************************************************************************************************
 * 
 * LPIT0 CHANNEL 0 IRQ HANDLER
 * 
*****************************************************************************************************************************************************************/
void LPIT0_Ch0_IRQHandler(void)
{
    /* Clear flag */
    SetClearBit(&(LPIT -> MSR), 0, SET_BIT);

    /* Check flag */
    if(cAlarmCheck == 1)
    {
        cCountBlink++;
        
        if(cCountBlink < 11)
        {
            cButton2 = !cButton2;
        }
        else
        {
            cCountBlink = 0;
            cAlarmCheck = 0;
        }
    }
    /************************************************************************/
}




