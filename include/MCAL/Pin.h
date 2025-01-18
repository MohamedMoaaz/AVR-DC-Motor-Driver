/**
 * @file    Pin.h
 * @author  Mohamed Moaaz
 * @brief   Pin module.
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __PIN_H__
#define __PIN_H__

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
 * @enum    State_t
 * @brief   Standard pin state.
 */
typedef enum
{
    STD_LOW  = 0,
    STD_HIGH = 1,
} State_t;

/**
 * @enum    Pin_t
 * @brief   Supported pin names.
 */
typedef enum
{
    PA0 = 0,
    PA1 = 1,
    PA2 = 2,
    PA3 = 3,
    PA4 = 4,
    PA5 = 5,
    PA6 = 6,
    PA7 = 7,
    PB0 = 8,
    PB1 = 9,
    PB2 = 10,
    PB3 = 11,
    PB4 = 12,
    PB5 = 13,
    PB6 = 14,
    PB7 = 15,
    PC0 = 16,
    PC1 = 17,
    PC2 = 18,
    PC3 = 19,
    PC4 = 20,
    PC5 = 21,
    PC6 = 22,
    PC7 = 23,
    PD0 = 24,
    PD1 = 25,
    PD2 = 26,
    PD3 = 27,
    PD4 = 28,
    PD5 = 29,
    PD6 = 30,
    PD7 = 31,
    PIN_COUNT
} Pin_t;

/**
 * @enum    PinMode_t
 * @brief   Supported pin modes.
 */
typedef enum
{
    INPUT    = 0,
    INPUT_PU = 1,
    OUTPUT   = 2,
    PIN_MODE_ERROR
} PinMode_t;

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Global Functions Prototypes
//==============================================================================

/**
 * @brief       Init pin.
 * @param [in]  pin: Selected pin.
 * @param [in]  mode: Pin mode.
 * @param [out] None.
 * @return      Error code.
 */
extern E_Status PIN_Init(Pin_t pin, PinMode_t mode);

/**
 * @brief       Set pin value.
 * @param [in]  pin: Selected pin.
 * @param [in]  value: Pin value.
 * @param [out] None.
 * @return      Error code.
 */
extern E_Status PIN_Set(Pin_t pin, State_t value);

/**
 * @brief       Get pin value.
 * @param [in]  pin: Selected pin.
 * @param [out] value: Pin value.
 * @return      Error code.
 */
extern E_Status PIN_Get(Pin_t pin, State_t *value);

/**
 * @brief       Toggle pin value.
 * @param [in]  pin: Selected pin.
 * @param [out] None.
 * @return      Error code.
 */
extern E_Status PIN_Toggle(Pin_t pin);

#endif /* __PIN_H__ */