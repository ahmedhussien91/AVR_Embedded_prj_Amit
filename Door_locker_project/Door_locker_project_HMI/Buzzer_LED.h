/**
 * @file Buzzer_LED.c
 * @brief module to control buzzer and LEDs
 * @date 11/23/2014
 * @author a7med
 * @version 1.0
 **/ 


#ifndef BUZZER_LED_H_
#define BUZZER_LED_H_

#include "DIO.h"

/* initialize the LEDs  and Buzzer Ports */
void LED_buzzer_init(void);
/* red LED turn on */
void LED_RED_ON (void);
/* red LED turn off */
void LED_RED_OFF (void);
/* green LED turn on */
void LED_GREEN_ON (void);
/* green LED turn off */
void LED_GREEN_OFF (void);
/* buzzer beeb 1 time */
void BUZZER_BEEB(void);
/* flash the Red light one time for 1 sec */ 
void LED_RED_flash (void);
/* flash the green light one time for 1 sec */
void LED_GREEN_flash (void);



#endif /* BUZZER_LED_H_ */