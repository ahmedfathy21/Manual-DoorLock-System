/* 
 * File:   ecu_button.h
 * Author: En.Ahmed
 *
 * Created on March 30, 2024, 1:56 AM
 */

#include"ecu_button.h"
#include"ecu_button_cfg.h"
/**
 * @brief  initialize the assigned pin to be input.
 * @param btn pointer to the button configurations
 @return status of the function
 *            E_OK  : function done successfully 
 *         E_NOT_OK : the function has issue to perform this action
 * */
std_ReturnType button_initialize(const button_t *btn){
     std_ReturnType ret = E_OK;
     if (NULL == btn){
         ret = E_NOT_OK;   
    }   
     else{
         ret = gpio_pin_direction_initialize(&(btn->button_pin));
     }
     return ret;
}
/**
 * @brief  initialize the assigned pin to be input.
 * @param btn pointer to the button configurations
 * @param state
 @return status of the function
 *            E_OK  : function done successfully 
 *         E_NOT_OK : the function has issue to perform this action
 */
std_ReturnType button_read_status(const button_t *btn, button_state_t *btn_state){
    std_ReturnType ret = E_NOT_OK;
    logic_t Pin_Logic_Status = GPIO_LOW;
    if((NULL == btn) || (NULL == btn_state)){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_read_logic(&(btn->button_pin), &Pin_Logic_Status);
        if(BUTTON_ACTIVE_HIGH == btn->button_connection){
            if(GPIO_HIGH == Pin_Logic_Status){
                *btn_state = BUTTON_PRESSED;
            }
            else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_connection){
            if(GPIO_HIGH == Pin_Logic_Status){
                *btn_state = BUTTON_RELEASED;
            }
            else{
                *btn_state = BUTTON_PRESSED;
            }
        }
        else { /* Nothing */ }
        ret = E_OK;
    }
    return ret;
}