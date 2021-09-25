/**
 * @file Timer.c
 * @brief Timer Module for Timers initializations to work in PWM mode &
 * @date 11/8/2014
 * @author a7med
 * @version 1.0
 **/ 


#include "Timer.h"


/*************************************************************************************************************************************/
/**
 *  Description: Function used to initialize timer 1 to work in PWM mode function take Duty Cycle to output 
					a signal on PIN  with pulse width equal to duty cycle ( Values entered is from 0 to 255 )
 **/ 
void Timer0_PWM_init (uint8 duty_cycle)
{
	DIO_Config timer0_pins = {'B',PB3,OUTPUT,LOGIC_HIGH};
	DIO_Configuration(&timer0_pins);													/*configuring OC0 Pin as Output */
 	
	TCCR0=(1<<WGM00)|(1<<COM01)|(1<<COM00)|(1<<CS02); 	/*pick up PWM,Phase correct mode , Set OC2 on compare match when up-counting. Clear OC2 on compare
																						match when down counting , set prescaler to 256 >> 16.32 ms period */
	OCR0=1-(duty_cycle);
	

	
}
/*************************************************************************************************************************************/
/**
 *  Description: Function used to initialize timer 1 to work in PWM mode function take Duty Cycle to output 
					a signal on PIN  with pulse width equal to duty cycle ( Values entered is from 0 to 255 )
 **/ 
void Timer0_PWM_Set_duty (uint8 duty_cycle)
{
	OCR0=1-(duty_cycle);		
}
/*************************************************************************************************************************************/
/**
 *  Description: Function used to initialize timer 2 to work in PWM mode function take Duty Cycle to output 
					a signal on PIN  with pulse width equal to duty cycle
 **/ 
void Timer2_PWM_init (uint8 duty_cycle)
{
	DIO_Config timer1_pins = {'D',PD7,OUTPUT,LOGIC_HIGH};
	DIO_Configuration(&timer1_pins);													/*configuring OC2 Pin as Output */	
	
	TCCR2=(1<<WGM20)|(1<<COM21)|(1<<COM20)|(1<<CS22)|(1<<CS21)|(1<<CS20);			/*pick up PWM,Phase correct mode , Set OC2 on compare match when up-counting. Clear OC2 on compare
																						match when down counting , set prescaler to 1024 */
	OCR2=1-(duty_cycle);
	
	
}
