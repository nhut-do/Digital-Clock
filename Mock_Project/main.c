#include "Mock_Library.h"
#include "IRQ.h"
#include "LPIT.h"
#include "LPUART.h"
#include "LPSPI.h"
#include "Clock.h"

/************************************************************************/

int main(void)
{	
   	/*****************************************************************************************************************************************************************
	* SET UP LPUART
	*****************************************************************************************************************************************************************/
	/* Setting Tx/Rx pin */
	LPUART_RxTx_Config(PORTC, 6, Alternative_2);		/*  LPUART Rx pin is connected to PORTC.6 */
	LPUART_RxTx_Config(PORTC, 7, Alternative_2);		/* LPUART Tx pin is connected to PORTC.7 */
	/* Enable FIRC divide 2 */
	Init_Available_Peripheral_Clock(FIRC, Devide_1);
	/* Configuration NVIC */
	NVIC(33);
	/* Select clock source LPUART */
	Clock_Source_LPUART(LPUART1, OPTION_3);
	/* Setting baud rate */
	Set_Baud_Rate(LPUART1, 9600, OSR_16);
	/* Setting Frame */
	Set_Frame(LPUART1, One_Stop_Bit, Mode_8_bit, Parity_Disable);
	/* Enable Receiver Interrupt */
	LPUART_Interrupt(LPUART1, TIE_Disable, RIE_Enable);
	/* Enable transmitter & receiver */
	Enable_LPUART(1, Transmit_Enable, Receive_Enable);
	/*****************************************************************************************************************************************************************
	* SET UP LPSPI
	*****************************************************************************************************************************************************************/
	/* Set alternate function pin */	
	Setting_LPSPI_Pin(PORTB, 2, Alternative_3);		/* SCK */	
	Setting_LPSPI_Pin(PORTB, 5, Alternative_4);		/* PCS */	
	Setting_LPSPI_Pin(PORTB, 4, Alternative_3);		/* SOUT */
	Setting_LPSPI_Pin(PORTB, 3, Alternative_3);		/* SIN */
	/* Enable SIRC divide 2 */
	Init_Available_Peripheral_Clock(SIRC, Devide_1);
	/* Select clock source LPSPI */
	Clock_Source_LPSPI(LPSPI0, OPTION_2);
	/* Setting Clock */
	LPSPI_Setting_Clock(LPSPI0, Prescale_Divide_by_1, 8);
	/* Configures Clock Phase and Polarity */
	LPSPI_CPOL_CPHA(LPSPI0, CPOL_0, CPHA_0);
	/* Setting Frame data */
	LPSPI_Frame_Data(LPSPI0, 16, LSBF_MSB);
	/* Configures the peripheral chip select */
	Config_LPSPI_PCS(LPSPI0, LPSPI_PCS0);
	/* Setting Transmit/Receive FIFO */
	LPSPI_Transmit_Receive_FIFO(LPSPI0, RXWATER0, TXWATER0, NOSTALL_1);
	/* Configures LPSPI mode */
	LPSPI_Config_Mode(LPSPI0, Master_Mode, Debug_Enable);
	/* Enable LPSPI module */
	Enable_LPSPI(LPSPI0, ENABLE);
	/*****************************************************************************************************************************************************************
	* SET UP LED
	*****************************************************************************************************************************************************************/
	Transmit(0x0C01);   /* Normal operation for all led */
	Transmit(0x0F00);   /* Display test */
	Transmit(0x09FF);   /* Enable decode mode for all led */
    Transmit(0x0BFF);   /* Display all led */
	Transmit(0x0AFF);   /* Intensity for all led */ 
	/*****************************************************************************************************************************************************************
	* SET UP INTERRUPT BUTTON PORT C
	*****************************************************************************************************************************************************************/
	/* Enable clock for Port C */
	Gpio_Init(PORTC);
	/* Set up button for pressing to display time or date */
	Gpio_SetMode(PORTC, 13, INPUT, Interrupt_Rising_Edge);
	/* Set up button for pressing to display OR NOT */
	Gpio_SetMode(PORTC, 12, INPUT, Interrupt_Rising_Edge);
	/* Setting NVIC for por C */
	NVIC(61);
	/*****************************************************************************************************************************************************************
	* SET UP LPIT TIMER
	*****************************************************************************************************************************************************************/
	/* Setting Clocking */
	LPIT_Init(OPTION_3);
	/* LPIT Initialization */
	LPIT_Initilazation();
	/* Configuration channel 1 for count time */
	LPIT_Config(Channel_1, (uint8_t*)Operation_Mode_1, Interrupt_Enable, 48000000);
	/* Setting NVIC for channel 1 */
	NVIC(49);
	/* Configuration channel 2 for blink LED */
	LPIT_Config(Channel_0, (uint8_t*)Operation_Mode_1, Interrupt_Enable, 12000000);
	/* Setting NVIC for channel 2 */
	NVIC(48);
	/*****************************************************************************************************************************************************************
	* MAIN PROGRAM
	*****************************************************************************************************************************************************************/
	while(1)
	{
		/* Receive data from LPUART */
		Receive_Time_Data();

		/* Algorithm to caculate time */
		Count_Date_Time();

		/* Check turn on or turn off led */
		if(cButton2 == 0)
		{
			/* Turn on all LED */
			Transmit(0x0C01);
		}
		else
		{
			/* Turn off all led */
			Transmit(0x0C00);
		}

		/* Display time */
		if(cButton1 == 0)
		{
			Display_Time();
		}
		/* Display date */
		else if(cButton1 == 1)
		{
			Display_Date();
		}

		/* Check Alarm */
		Check_Alarm_Time();

	}
  
}














