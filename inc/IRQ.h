#ifndef IRQ_H
#define IRQ_H

/************************************************************************/
/*****************************************************************************************************************************************************************
 * 
 * IRQ HANDLER
 * 
*****************************************************************************************************************************************************************/
void PORTC_IRQHandler(void);
void SysTick_Handler(void);
void LPIT0_Ch1_IRQHandler(void);
void LPUART1_RxTx_IRQHandler(void);


#endif



