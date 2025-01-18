/**
 * @file    Pin_Regs.h
 * @author  Mohamed Moaaz
 * @brief   Pin register values.
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __PIN_REGS_H__
#define __PIN_REGS_H__

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

/**
 * @brief Base address of PORTA.
 */
#define PORT_BASE   (0x3B)

/**
 * @brief PORT offset between consecutive PORT.
 */
#define PORT_OFFSET (-3)

/**
 * @brief       Calculate PORT address.
 * @param [in]  port: Port name.
 */
#define PORT(port) (PORT_BASE + (PORT_OFFSET * port))

/**
 * @brief Base address of PINA.
 */
#define PIN_BASE    (0x39)

/**
 * @brief PIN offset between consecutive PIN.
 */
#define PIN_OFFSET  (-3)

/**
 * @brief       Calculate PIN address.
 * @param [in]  port: Port name.
 */
#define PIN(port) (PIN_BASE + (PIN_OFFSET * port))

//==============================================================================
// Typedefs
//==============================================================================

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Global Functions Prototypes
//==============================================================================

#endif /* __PIN_REGS_H__ */
