#include "../inc/Mock_Library.h"
#include "../inc/SysTick.h"

/************************************************************************/
void Config_SysTick(uint32_t iReloadValue)
{
    /* Disable the SysTick timer */
    SYSTICK -> CONTROL = 0;
    /* Write the new reload value */
    SYSTICK -> RELOAD_VALUE = iReloadValue;
    SetClearListOfBit(&(SYSTICK -> CONTROL), 1, 2, (unsigned char*)"11");
    /* Write to the SysTick Current Value register */
    SYSTICK -> CURRENT_VALUE = 7;
    /* start the SysTick timer */
    SetClearBit(&(SYSTICK -> CONTROL), 0, SET_BIT);
}


