/* 
 * File:   Seven_Segment.h
 * Author: En.Ahmed
 *
 * Created on April 15, 2024, 7:12 PM
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

/*  section  : includes  */
#include"Seven_Segment_Cfg.h"
#include"../../MCAL_Layer/GPIO/hal_gpio.h"


/*section  : Macro Declarations */
#define SEVEN_SEGMENT_PIN0   0
#define SEVEN_SEGMENT_PIN1   1
#define SEVEN_SEGMENT_PIN2   2
#define SEVEN_SEGMENT_PIN3   3
/*section  : Macro function Declarations */


/*section  : Data Type Declarations  */
typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE    
}segment_type_t;

typedef struct{
    pin_config_t  segments_pins[4];
    segment_type_t segment_type; 
}segment_t;
/*section  : function Declarations  */
std_ReturnType seven_segment_intialize(const segment_t* segment);
std_ReturnType seven_segment_write_number(const segment_t* segment,uint8 number);

#endif	/* SEVEN_SEGMENT_H */

