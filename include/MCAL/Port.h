/**
 * @file    Port.h
 * @author  Mohamed Moaaz
 * @brief   Port module.
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __PORT_H__
#define __PORT_H__

//==============================================================================
// Includes
//==============================================================================

/**
 * @brief Standard data types.
 */
#include "Std_Types.h"

//==============================================================================
// Macros & Defines
//==============================================================================

//==============================================================================
// Typedefs
//==============================================================================

/**
 * @enum    Port_t
 * @brief   Supported port names.
 */
typedef enum
{
    PA = 0,
    PB = 1,
    PC = 2,
    PD = 3,
    PORT_COUNT
} Port_t;

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Global Functions Prototypes
//==============================================================================

/**
 * @brief       Set port value.
 * @param [in]  port: Selected port.
 * @param [in]  value: Port value.
 * @param [out] None.
 * @return      Error code.
 */
extern E_Status PORT_Set(Port_t port, uint8_t value);

/**
 * @brief       Get port value.
 * @param [in]  port: Selected port.
 * @param [out] value: Port value.
 * @return      Error code.
 */
extern E_Status PORT_Get(Port_t port, uint8_t *value);

/**
 * @brief       Set port bits.
 * @param [in]  port: Selected port.
 * @param [in]  value: Port bits.
 * @param [out] None.
 * @return      Error code.
 */
extern E_Status PORT_SetBits(Port_t port, uint8_t value);

/**
 * @brief       Clear port bits.
 * @param [in]  port: Selected port.
 * @param [in]  value: Port bits.
 * @param [out] None.
 * @return      Error code.
 */
extern E_Status PORT_ClearBits(Port_t port, uint8_t value);


#endif /* __PORT_H__ */