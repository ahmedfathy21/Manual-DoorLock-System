/* 
 * File:   ecu_button.h
 * Author: En.Ahmed
 *
 * Created on March 30, 2024, 1:56 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/*  section  : includes  */

#include"../../MCAL_Layer/GPIO/hal_gpio.h"
#include"ecu_button_cfg.h"

/*section  : Macro Declarations */


/*section  : Macro function Declarations */


/*section  : Data Type Declarations  */
typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED         
    
}button_state_t;
typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW        
    
}button_active_t;
typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
    
}button_t;

/*section  : function Declarations  */
std_ReturnType button_initialize(const button_t *btn);
std_ReturnType button_read_status(const button_t *btn,button_state_t *state);
#endif	/* ECU_BUTTON_H */

