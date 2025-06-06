#include "../inc/Mock_Library.h"

/************************************************************************/
/*****************************************************************************************************************************************************************
 * 
 * SET OR CLEAR 1 BIT
 * 
*****************************************************************************************************************************************************************/
void SetClearBit(uint32_t *pPointer, unsigned char cPos, unsigned char cAction)
{
	/* Set bit */
    if(cAction == SET_BIT)
    {
        *pPointer = *pPointer | (1 << cPos);
    }

	/* Clear bit */
    if(cAction == CLEAR_BIT)
    {
        *pPointer = *pPointer & ~(1 << cPos);
    }
		
}
/*****************************************************************************************************************************************************************
 * 
 * SET OR CLEAR LIST OF BIT IN OWN WAY
 * 
*****************************************************************************************************************************************************************/
void SetClearListOfBit(uint32_t *pPointer, unsigned char cPos1, unsigned char cPos2, unsigned char sListOfBit[32])
{
	/* Index that check length of sListOfBit[] */
  	unsigned char cIndex = 0;

	uint32_t iPointerValue = 0;
	iPointerValue = *pPointer;					/* Variable get value from register */

	char sTempString[32];						/* String that take value of bit field input */
	memset(sTempString, 0, 32);
		
	/* Reverse string */
	for(unsigned char iCount = 0; iCount < strlen((char*)sListOfBit); iCount++)     /* Implicate sListOfBit for not wwarning */
	{
		sTempString[iCount] = sListOfBit[strlen((char*)sListOfBit) - 1 - iCount];
	}

	/* Change value of register */
    for(int iCount = cPos1; iCount <= cPos2; iCount++)
    {
			
        if(sTempString[cIndex] == '0')
        {
            iPointerValue= (iPointerValue & ~(1 << iCount));
        }

        if(sTempString[cIndex] == '1')
        {
            iPointerValue = (iPointerValue | (1 << iCount));
        }
				
		cIndex++;
    }
		
	/* Assign value from variable to register */
	*pPointer = iPointerValue;

}
/*****************************************************************************************************************************************************************
 * 
 * CHECK BIT IF IT IS 0 OR 1
 * 
*****************************************************************************************************************************************************************/
short CheckBit(uint32_t *pPointer, unsigned char cPos)
{
	/* Return 1 if bit is 1 */
	if (((*pPointer >> cPos) & 1) != 0)
	{
		return 1;
	}
	
	/* Return 0 if bit is 0 */
	if (((*pPointer >> cPos) & 1) == 0)
	{
		return 0;
	}

	/* If ERROR */	
	return 2;
}
/*****************************************************************************************************************************************************************
 * 
 * SET CLOCK FOR PORT A -> E
 * 
*****************************************************************************************************************************************************************/
void Gpio_Init(uint8_t cPort)
{
	
	switch(cPort)
	{
		case PORTA:
			SetClearBit(&(PCC -> PCC_PORTA), 30, SET_BIT);
			break;

		case PORTB:
			SetClearBit(&(PCC -> PCC_PORTB), 30, SET_BIT);
			break;

		case PORTC:
			SetClearBit(&(PCC -> PCC_PORTC), 30, SET_BIT);
			break;

		case PORTD:
			SetClearBit(&(PCC -> PCC_PORTD), 30, SET_BIT);
			break;

		case PORTE:
			SetClearBit(&(PCC -> PCC_PORTE), 30, SET_BIT);
			break;
	}
}
/*****************************************************************************************************************************************************************
 * 
 * ENABLE GPIO, SET DIRECTION OF PIN, ENABLE ISR (IF REQUEST)
 * 
*****************************************************************************************************************************************************************/
void Gpio_SetMode(uint8_t cPort, uint8_t cPin, uint8_t cDirect, uint8_t cIRQ)
{
	/* Pointer that point to pins in struct PORT A -> E */
	uint32_t* pPointer = NULL;				/* Pointer used to get which PORT has pin choosen to be GPIO */
	uint8_t* pPointer1 = NULL;				/* Pointer used to get bit field for GPIO Interrupt */

	/* Choose IRQ options */
	switch(cIRQ)				
	{
		/* Pointer get bit field for Interrupt Option */
		case Disable_IRQ:
			pPointer1 = (uint8_t*) Disable_Interrupt;
			break;

		case Interrupt_logic_0:
			pPointer1 = (uint8_t*) Logic_0;
			break;

		case Interrupt_Rising_Edge:
			pPointer1 = (uint8_t*) Rising_Edge;
			break;

		case Interrupt_Falling_Edge:
			pPointer1 = (uint8_t*) Falling_Edge;
			break;

		case Interrupt_Either_Edge:
			pPointer1 = (uint8_t*) Either_Edge;
			break;

		case Interrupt_logic_1:
			pPointer1 = (uint8_t*) Logic_1;
			break;
	}

	/* Enable GPIO, set direction of pin */
    switch (cPort)
    {
        case PORTA:
			pPointer = (uint32_t*) PORT_A;
			/* Enable GPIO */
			SetClearListOfBit(&pPointer[cPin], 8, 10, (unsigned char*)"001");
			/* Disable pull up/pull down */
			SetClearBit(&pPointer[cPin], 1, CLEAR_BIT);
			/* Set direction */
			SetClearBit(&(GPIO_A -> PDDR), cPin, cDirect);
			/* Interrupt Config */
			SetClearListOfBit(&(pPointer[cPin]), 16, 19, pPointer1);
			break;

        case PORTB:
			pPointer = (uint32_t*) PORT_B;
			/* Enable GPIO */
			SetClearListOfBit(&pPointer[cPin], 8, 10, (unsigned char*)"001");
			/* Disable pull up/pull down */
			SetClearBit(&pPointer[cPin], 1, CLEAR_BIT);
			/* Set direction */
			SetClearBit(&(GPIO_B -> PDDR), cPin, cDirect);
			/* Interrupt Config */
			SetClearListOfBit(&(pPointer[cPin]), 16, 19, pPointer1);
			break;

        case PORTC:
			pPointer = (uint32_t*) PORT_C;
			/* Enable GPIO */
			SetClearListOfBit(&pPointer[cPin], 8, 10, (unsigned char*)"001");
			/* Disable pull up/pull down */
			SetClearBit(&pPointer[cPin], 1, CLEAR_BIT);
			/* Set direction */
			SetClearBit(&(GPIO_C -> PDDR), cPin, cDirect);
			/* Interrupt Config */
			SetClearListOfBit(&(pPointer[cPin]), 16, 19, pPointer1);
			break;

        case PORTD:
			pPointer = (uint32_t*) PORT_D;
			/* Enable GPIO */
			SetClearListOfBit(&pPointer[cPin], 8, 10, (unsigned char*)"001");
			/* Disable pull up/pull down */
			SetClearBit(&pPointer[cPin], 1, CLEAR_BIT);
			/* Set direction */
			SetClearBit(&(GPIO_D -> PDDR), cPin, cDirect);
			/* Interrupt Config */
			SetClearListOfBit(&(pPointer[cPin]), 16, 19, pPointer1);
			break;

        case PORTE:
			pPointer = (uint32_t*) PORT_E;
			/* Enable GPIO */
			SetClearListOfBit(&pPointer[cPin], 8, 10, (unsigned char*)"001");
			/* Disable pull up/pull down */
			SetClearBit(&pPointer[cPin], 1, CLEAR_BIT);
			/* Set direction */
			SetClearBit(&(GPIO_E -> PDDR), cPin, cDirect);
			/* Interrupt Config */
			SetClearListOfBit(&(pPointer[cPin]), 16, 19, pPointer1);
			break;
    }

}
/*****************************************************************************************************************************************************************
 * 
 * WRITE FOR GPIO
 * 
*****************************************************************************************************************************************************************/
void Gpio_WriteChannel(uint8_t cPort, uint8_t cPin, uint8_t cLevel)
{
	/* Temp pointer take address and value of GPIO PDDR register */
	uint32_t *pTempPointer = NULL;
	
	switch(cPort)
	{
		case PORTA:
			pTempPointer = &(GPIO_A -> PDDR);
			break;

		case PORTB:
			pTempPointer = &(GPIO_B -> PDDR);
			break;

		case PORTC:
			pTempPointer = &(GPIO_C -> PDDR);
			break;

		case PORTD:
			pTempPointer = &(GPIO_D -> PDDR);
			break;

		case PORTE:
			pTempPointer = &(GPIO_E -> PDDR);
			break;
	}
	
	/* Check if the PDDR pin is configured as OUTPUT */
	if(CheckBit(pTempPointer, cPin) == OUTPUT)
	{
		switch (cPort)
		{
			case PORTA:
				SetClearBit(&(GPIO_A -> PDOR), cPin, cLevel);
				break;

			case PORTB:
				SetClearBit(&(GPIO_B -> PDOR), cPin, cLevel);
				break;

			case PORTC:
				SetClearBit(&(GPIO_C -> PDOR), cPin, cLevel);
				break;

			case PORTD:
				SetClearBit(&(GPIO_D -> PDOR), cPin, cLevel);
				break;

			case PORTE:
				SetClearBit(&(GPIO_E -> PDOR), cPin, cLevel);
				break;
		}
	}
}
/*****************************************************************************************************************************************************************
 * 
 * READ FOR GPIO
 * 
*****************************************************************************************************************************************************************/
short Gpio_ReadChannel(uint8_t cPort, uint8_t cPin)
{
		/* Temp pointer take address and value of GPIO PDDR register */
		uint32_t *pTempPointer = NULL;

		/* Get address of PDDR register */
		switch(cPort)
		{
			case PORTA:
				pTempPointer = &(GPIO_A -> PDDR);
				break;

			case PORTB:
				pTempPointer = &(GPIO_B -> PDDR);
				break;

			case PORTC:
				pTempPointer = &(GPIO_C -> PDDR);
				break;

			case PORTD:
				pTempPointer = &(GPIO_D -> PDDR);
				break;

			case PORTE:
				pTempPointer = &(GPIO_E -> PDDR);
				break;
		}
		
		/* Check if the PDDR pin is configured as INPUT */
		if(CheckBit(pTempPointer, cPin) == INPUT)
		{
	
			switch (cPort)
			{
				case PORTA:
						
					if(CheckBit(&(GPIO_A -> PDIR), cPin) == HIGH)
					{
						return 1;
					}
						
					if(CheckBit(&(GPIO_A -> PDIR), cPin) == LOW)
					{
						return 0;
					}
						
					break;

				case PORTB:
						
					if(CheckBit(&(GPIO_B -> PDIR), cPin) == HIGH)
					{
						return 1;
					}
						
					if(CheckBit(&(GPIO_B -> PDIR), cPin) == LOW)
					{
						return 0;
					}

					break;

				case PORTC:
						
					if(CheckBit(&(GPIO_C -> PDIR), cPin) == HIGH)
					{
						return 1;
					}
						
					if(CheckBit(&(GPIO_C -> PDIR), cPin) == LOW)
					{
						return 0;
					}
						
					break;

				case PORTD:
					
					if(CheckBit(&(GPIO_D -> PDIR), cPin) == HIGH)
					{
						return 1;
					}
						
					if(CheckBit(&(GPIO_D -> PDIR), cPin) == LOW)
					{
						return 0;
					}
						
					break;

				case PORTE:
						
					if(CheckBit(&(GPIO_E -> PDIR), cPin) == HIGH)
					{
						return 1;
					}
						
					if(CheckBit(&(GPIO_E -> PDIR), cPin) == LOW)
					{
						return 0;
					}
					
					break;
			}
		}
		
		/* If the PDDR pin is not configured as INPUT */
		return 2;
}
/*****************************************************************************************************************************************************************
 * 
 * SET NVIC FOR PERIPHERAL
 * 
*****************************************************************************************************************************************************************/
extern inline void NVIC(uint16_t iNVIC_ID)
{
	SetClearBit((uint32_t *)(0xE000E100u + 4*(iNVIC_ID / 32)), iNVIC_ID % 32, SET_BIT);
}




