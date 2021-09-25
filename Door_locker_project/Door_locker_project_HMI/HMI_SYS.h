 /**
 * @file HMI_SYS.h
 * @brief Module for HMI ECU used to initialize HMI system,interface with user to setup password and receive menu option and send it to CNTRL ECU
 * @date 11/19/2014
 * @author a7med
 * @version 1.1
 **/


#ifndef HMI_SYS_H_
#define HMI_SYS_H_

#include "Keypad.h"
#include "LCD.h"
#include "UART.h"
#include "Buzzer_LED.h"
#include <string.h>

/********************************************************************************************/

typedef struct passwords
{
	uint8 frist_time_flag;
	uint8 password_saved_flag;
	uint8 password_correctly_enterd_flag;
	uint8 passwrd[4];
} pass;

/*********************************************************************************************/

/**/
void SYS_HMI_Init (void);
/**/
uint8 SYS_HMI_setup_password (void);
/**/
void SYS_check_Password_EEPROM(void );
/**/
void SYS_HMI_menu_option_send (uint8 menu_option);
/**/
uint8 SYS_HMI_get_menu_option (void);
/**/
void SYS_HMI_resend_menu_option (void);

#endif /* HMI_SYS_H_ */