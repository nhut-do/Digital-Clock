#include "../inc/Mock_Library.h"
#include "../inc/Clock.h"

/************************************************************************/
void Init_Available_Peripheral_Clock(uint8_t cSourceClock, uint8_t* pDIV)
{
    switch (cSourceClock)
    {
        case FIRC:
            /* Disable FIRC */
            SetClearBit(&(SCG -> SCG_FIRCCSR), 0, 0);
            /* Enable FIRC DIV 2 */
            SetClearListOfBit(&(SCG -> SCG_FIRCDIV), 8, 10, pDIV);
            /* Enable FIRC */
            SetClearBit(&(SCG -> SCG_FIRCCSR), 0, 1);
        case SIRC:
            /* Disable SIRC */
            SetClearBit(&(SCG -> SCG_SIRCCSR), 0, 0);
            /* Enable SIRC DIV 2 */
            SetClearListOfBit(&(SCG -> SCG_SIRCDIV), 8, 10, pDIV);
            /* Enable SIRC */
            SetClearBit(&(SCG -> SCG_SIRCCSR), 0, 1);
            break;

    }
}


void Init_SOSC_Peripheral_Clock(uint8_t cSourceClock, uint8_t* pDIV)
{
    /* Choose external/internal clock */
    SetClearBit(&(SCG -> SCG_SOSCCFG), 2, cSourceClock);
    /* Disable SOSC */
    SetClearBit(&(SCG -> SCG_SOSCCSR), 0, 0);
    /* Enable SOSC DIV 2 */
    SetClearListOfBit(&(SCG -> SCG_SOSCDIV), 8, 10, pDIV);
    /* Enable SOSC */
    SetClearBit(&(SCG -> SCG_SOSCCSR), 0, 1);
}
