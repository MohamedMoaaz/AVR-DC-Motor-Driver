/**
 * @file    Pin.c
 * @author  Mohamed Moaaz
 * @brief   Pin module.
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

/**
 * @brief Pin registers.
 */
#include "MCAL/Pin_Regs.h"

/**
 * @brief Port module.
 */
#include "MCAL/Port.h"

/**
 * @brief Pin module.
 */
#include "MCAL/Pin.h"

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

E_Status PIN_Init(Pin_t pin_id, PinMode_t mode)
{
    uint8_t port;
    uint8_t pin;
    Reg_t rPORT;

    if (pin_id >= PIN_COUNT)
    {
        return E_NOK;
    }
    if (mode >= PIN_MODE_ERROR)
    {
        return E_NOK;
    }

    port = (pin_id / 8);
    pin  = (1U << (pin_id % 8));

    if (mode == OUTPUT)
    {
        PORT_SetBits(port, pin);
    }
    else
    {
        PORT_ClearBits(port, pin);

        rPORT = PORT(port);

        if (mode == INPUT_PU)
        {
            REG(rPORT) |= pin;
        }
        else
        {
            REG(rPORT) &= ~pin;
        }
    }

    return E_OK;
}

E_Status PIN_Set(Pin_t pin_id, State_t value)
{
    uint8_t port;
    uint8_t pin;
    Reg_t rPORT;

    if (pin_id >= PIN_COUNT)
    {
        return E_NOK;
    }

    port = (pin_id / 8);
    rPORT = PORT(port);

    pin  = (pin_id % 8);
    REG(rPORT) |= (value << pin);

    return E_OK;
}

E_Status PIN_Get(Pin_t pin_id, State_t *value)
{
    uint8_t port;
    uint8_t pin;
    Reg_t rPIN;

    if (pin_id >= PIN_COUNT)
    {
        return E_NOK;
    }

    port = (pin_id / 8);
    pin  = (1U << (pin_id % 8));

    rPIN = PIN(port);
    *value = GET_BIT(REG(rPIN), pin);

    return E_OK;
}

E_Status PIN_Toggle(Pin_t pin_id)
{
    uint8_t port;
    uint8_t pin;
    Reg_t rPORT;

    if (pin_id >= PIN_COUNT)
    {
        return E_NOK;
    }

    port = (pin_id / 8);
    rPORT = PORT(port);

    pin  = (pin_id % 8);
    REG(rPORT) ^= (1U << pin);

    return E_OK;
}