/**
 * @file Buzzer_LED.c
 * @brief module to control buzzer and LEDs
 * @date 11/23/2014
 * @author a7med
 * @version 1.0
 **/ 


#include "Buzzer_LED.h"

/* red & green & buzzer PINS */

static DIO_Config RED_LED={'B',PB2,OUTPUT,LOGIC_LOW};
static DIO_Config GREEN_LED={'B',PB3,OUTPUT,LOGIC_LOW};
static DIO_Config BUZZER={'B',PB6,OUTPUT,LOGIC_LOW};

/*********************************************************************************************************************************************************************/
/**
 *  Description: Function used to initialize the buzzer ,green and red LED  Pins in the microcontroller 
 **/ 
void LED_buzzer_init( void)
{
	DIO_Configuration(&RED_LED);
	DIO_Configuration(&GREEN_LED);
	DIO_Configuration(&BUZZER);
}
/*********************************************************************************************************************************************************************/
/**
 *  Description: Function used to turn on the green led 
 **/ 
void LED_GREEN_ON()
{
	GREEN_LED.value = LOGIC_HIGH;
	DIO_Write_Pin(&GREEN_LED);
}
/*********************************************************************************************************************************************************************/
/**
 *  Description: Function used to turn off the green led 
 **/ 
void LED_GREEN_OFF()
{
	GREEN_LED.value = LOGIC_LOW;
	DIO_Write_Pin(&GREEN_LED);
}
/*********************************************************************************************************************************************************************/
/**
 *  Description: Function used to turn on the red led 
 **/ 
void LED_RED_ON()
{
	RED_LED.value = LOGIC_HIGH;
	DIO_Write_Pin(&RED_LED);
}
/*********************************************************************************************************************************************************************/
/**
 *  Description: Function used to turn off the red led 
 **/ 
void LED_RED_OFF()
{
	RED_LED.value = LOGIC_LOW;
	DIO_Write_Pin(&RED_LED);
}
/*********************************************************************************************************************************************************************/
/**
 *  Description: Function used to beeb the buzzer for 1 sec one time 
 **/ 
void BUZZER_BEEB(void)
{
	BUZZER.value=LOGIC_HIGH;
	DIO_Write_Pin(&BUZZER);
	_delay_ms(1000);
	BUZZER.value=LOGIC_LOW;
	DIO_Write_Pin(&BUZZER);
}
/*********************************************************************************************************************************************************************/
/**
 *  Description: Function used to flash on the red led for 1 sec
 **/ 
void LED_RED_flash (void)
{
	LED_RED_ON();
	_delay_ms(1000);
	LED_RED_OFF();
}
/*********************************************************************************************************************************************************************/
/**
 *  Description: Function used to flash on the green led for 1 sec
 **/ 
void LED_GREEN_flash (void)
{
	LED_GREEN_ON();
	_delay_ms(1000);
	LED_GREEN_OFF();
}