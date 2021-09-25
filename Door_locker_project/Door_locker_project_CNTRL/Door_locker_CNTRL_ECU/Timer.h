/**
 * @file Timer.h
 * @brief Timer Module for Timers initializations to work in PWM mode &
 * @date 11/8/2014
 * @author a7med
 * @version 1.0
 **/ 


#ifndef TIMER_H_
#define TIMER_H_

#include "DIO.h"

/*initialize timer 0 in PWM mode */
void Timer0_PWM_init (uint8 duty_cycle);
/*initialize timer 2 in PWM mode */
void Timer2_PWM_init (uint8 duty_cycle);
/* set duty cycle of Timer0 */
void Timer0_PWM_Set_duty (uint8 duty_cycle);




#endif /* TIMER_H_ */