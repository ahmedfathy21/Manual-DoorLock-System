/* 
 * File:   Seven_Segment.c
 * Author: En.Ahmed
 *
 * Created on April 15, 2024, 7:12 PM
 */

#include"Seven_Segment.h"
/**
 * 
 * @param segment
 * @return 
 */
std_ReturnType seven_segment_intialize(const segment_t* segment){
     std_ReturnType ret = E_OK ;
    if(segment == NULL){
        ret = E_NOT_OK;
    }
    else 
    {
        ret = gpio_pin_initialize(&(segment->segments_pins[SEVEN_SEGMENT_PIN0]));
        ret = gpio_pin_initialize(&(segment->segments_pins[SEVEN_SEGMENT_PIN1]));
        ret = gpio_pin_initialize(&(segment->segments_pins[SEVEN_SEGMENT_PIN2]));
        ret = gpio_pin_initialize(&(segment->segments_pins[SEVEN_SEGMENT_PIN3]));
    }
    return ret;
    
}

/**
 * 
 * @param segment
 * @param number
 * @return 
 */
std_ReturnType seven_segment_write_number(const segment_t* segment,uint8 number){
    std_ReturnType ret = E_OK ;
    if((segment == NULL)&&(number > 9)){
        ret = E_NOT_OK;
    }
    else 
    {
        ret =  gpio_pin_write_logic(&(segment->segments_pins[SEVEN_SEGMENT_PIN0]),(number&0x01));
        ret =  gpio_pin_write_logic(&(segment->segments_pins[SEVEN_SEGMENT_PIN1]),(number>>1)&0x01);
        ret =  gpio_pin_write_logic(&(segment->segments_pins[SEVEN_SEGMENT_PIN2]),(number>>2)&0x01);
        ret =  gpio_pin_write_logic(&(segment->segments_pins[SEVEN_SEGMENT_PIN3]),(number>>3)&0x01);
    }
    return ret;
    
}