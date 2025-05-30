/**
 * @file    Port.c
 * @author  Mohamed Moaaz
 * @brief   Port module.
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

/**
 * @brief Port registers.
 */
#include "MCAL/Port_Regs.h"

/**
 * @brief Port module.
 */
#include "MCAL/Port.h"

//==============================================================================
// Extern Variables
//==============================================================================

//==============================================================================
// Private Macros & Defines
//==============================================================================

//==============================================================================
// Private Typedefs
//==============================================================================

//==============================================================================
// Static Variables
//==============================================================================

//==============================================================================
// Global Variables
//==============================================================================

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Static Functions Prototypes
//==============================================================================

//==============================================================================
// Static Functions
//==============================================================================

//==============================================================================
// Global Functions
//==============================================================================

E_Status PORT_Set(Port_t port, uint8_t value)
{
    Reg_t rDDR;

    if (port >= PORT_COUNT)
    {
        return E_NOK;
    }

    rDDR      = DDR(port);
    REG(rDDR) = value;

    return E_OK;
}

E_Status PORT_Get(Port_t port, uint8_t *value)
{
    Reg_t rDDR;

    if (port >= PORT_COUNT)
    {
        return E_NOK;
    }

    rDDR   = DDR(port);
    *value = REG(rDDR);

    return E_OK;
}

E_Status PORT_SetBits(Port_t port, uint8_t value)
{
    Reg_t rDDR;

    if (port >= PORT_COUNT)
    {
        return E_NOK;
    }

    rDDR = DDR(port);
    REG(rDDR) |= value;

    return E_OK;
}

E_Status PORT_ClearBits(Port_t port, uint8_t value)
{
    Reg_t rDDR;

    if (port >= PORT_COUNT)
    {
        return E_NOK;
    }

    rDDR = DDR(port);
    REG(rDDR) &= ~value;

    return E_OK;
}
