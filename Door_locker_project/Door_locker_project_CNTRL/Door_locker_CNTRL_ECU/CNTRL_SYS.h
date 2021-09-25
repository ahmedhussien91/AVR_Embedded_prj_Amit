 /**
 * @file CNTRL_SYS.h
 * @brief Module for CNTRL ECU used to initialize cntrol system, setup password and execute the received menu option
 * @date 11/19/2014
 * @author a7med
 * @version 1.1
 **/ 


#ifndef CNTRL_SYS_H_
#define CNTRL_SYS_H_

#include "Timer.h"
#include "motor.h"
#include "EEPROM.h"
#include "UART.h"

/*******************************************************************************************************************************************************************************/
/****************************************************************************************************************/
/** Description: Structure to carry password and its status it contain
 *													   1. the frist_time_flag --> the frist time to use system (0) or not (1)    
 *													   2. the password_saved_flag --> password saved (1) or (0)
 *													   3. the password_correctly_entered_flag --> password match with password on EEPROM (1) or mismatch(0)
 *													   4. the password */
typedef struct passwords
{
	uint8 frist_time_flag;
	uint8 password_saved_flag;
	uint8 password_correctly_enterd_flag;
	uint8 passwrd[4];
} pass;

/*****************************************************************************************************************************************************************************/
/* initialize control system */
void SYS_CNTRL_Init (void);
/*send password status to HMI */
uint8 SYS_send_password_status(void );
/*send password status, setup password in the EEPROM if needed and check for password of system */
uint8 SYS_CNTRL_setup_password (void);
/*open safe door */
void SYS_CNTRL_open(uint8 servo_angle);
/*close safe door */
void SYS_CNTRL_close(void);
/*change password*/
void SYS_CNTRL_change_password( void );
/*apply the option received from the HMI unit */
void SYS_CNTRL_menu_option (void);



#endif /* CNTRL_SYS_H_ */