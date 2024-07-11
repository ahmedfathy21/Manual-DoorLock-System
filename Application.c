

#include "application.h"
void Write_Char_U(void);
void Write_Char_L(void);
   std_ReturnType ret = E_NOT_OK;
   button_state_t MOTOR_MOVE_BUTTON_STATUS = BUTTON_RELEASED;
   button_state_t LOCK_BUTTON_STATUS = BUTTON_RELEASED; 
   button_state_t UNLOCK_BUTTON_STATUS = BUTTON_RELEASED; 
    led_t led_red = {.port_name = PORTA_INDEX, .pin = PIN2, .led_status = GPIO_LOW};
    led_t led_green = {.port_name = PORTA_INDEX, .pin = PIN1, .led_status = GPIO_LOW};
  button_t button_Motor_Move = { 
      .button_pin.port =PORTB_INDEX,
      .button_pin.pin = PIN0, 
      .button_pin.direction =GPIO_DIRECTION_INPUT,
      .button_pin.logic = GPIO_LOW,
      .button_connection = BUTTON_ACTIVE_HIGH ,
      .button_state = BUTTON_RELEASED,
                       };  
   button_t button_Lock = { 
      .button_pin.port =PORTB_INDEX,
      .button_pin.pin = PIN1, 
      .button_pin.direction =GPIO_DIRECTION_INPUT,
      .button_pin.logic = GPIO_LOW,
      .button_connection = BUTTON_ACTIVE_HIGH ,
      .button_state = BUTTON_RELEASED,
                       };  
    button_t button_Unlock = { 
      .button_pin.port =PORTB_INDEX,
      .button_pin.pin = PIN2, 
      .button_pin.direction =GPIO_DIRECTION_INPUT,
      .button_pin.logic = GPIO_LOW,
      .button_connection = BUTTON_ACTIVE_HIGH ,
      .button_state = BUTTON_RELEASED,
                       };  
  dc_motor_t Motor = {.dc_motor_pin[0].port = PORTD_INDEX , .dc_motor_pin[0].pin = PIN0 ,
                      .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT ,.dc_motor_pin[0].logic = GPIO_LOW,
                      .dc_motor_pin[1].port = PORTD_INDEX , .dc_motor_pin[1].pin = PIN1 ,
                      .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT ,.dc_motor_pin[1].logic = GPIO_LOW,};

int main() { 
    std_ReturnType ret = E_NOT_OK;
   ret = led_initialize(&led_red);
   ret = led_initialize(&led_green);
   ret = button_initialize(&button_Lock);
   ret = button_initialize(&button_Unlock);
   ret = dc_motor_initialize(&Motor);
   
   ret = gpio_port_direction_initialize(PORTC_INDEX , GPIO_DIRECTION_OUTPUT);
    while(1){
        ret = button_read_status(&button_Lock,&LOCK_BUTTON_STATUS);
        ret = button_read_status(&button_Motor_Move,&MOTOR_MOVE_BUTTON_STATUS);
        ret = button_read_status(&button_Unlock,&UNLOCK_BUTTON_STATUS); 
        if(MOTOR_MOVE_BUTTON_STATUS == BUTTON_PRESSED){
            ret = dc_motor_move_right(&Motor);
            if(LOCK_BUTTON_STATUS == BUTTON_PRESSED){
                 ret = dc_motor_stop(&Motor);
                 Write_Char_L();  
                 ret = led_turn_on(&led_red);
                 ret = led_turn_off(&led_green);
            }
            else if(UNLOCK_BUTTON_STATUS == BUTTON_PRESSED){
                 ret = dc_motor_stop(&Motor);
                 Write_Char_U();  
                 ret = led_turn_off(&led_red);
                 ret = led_turn_on(&led_green);
            }   
               
       
    }
    return (EXIT_SUCCESS);
}
}
void Write_Char_U(void){
    gpio_port_write_logic(PORTC_INDEX , 65);
    
}
void Write_Char_L(void){
    gpio_port_write_logic(PORTC_INDEX , 71);
    
}


