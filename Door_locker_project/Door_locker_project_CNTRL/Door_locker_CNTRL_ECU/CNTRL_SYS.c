 /**
 * @file CNTRL_SYS.c
 * @brief Module for CNTRL ECU used to initialize cntrol system, setup password and execute the received menu option
 * @date 11/19/2014
 * @author a7med
 * @version 1.1
 **/ 

#include "CNTRL_SYS.h"

/******************************************************************************************************************************************************/
pass password= {.frist_time_flag = 1, .passwrd={0xff,0xff,0xff,0xff} ,.password_correctly_enterd_flag = 0, .password_saved_flag = 0 } ;


/********************************************************************************************/
/**
 *  Description: Function is used to Initialize Control system 
 **/
void SYS_CNTRL_Init (void)
{
		UART_init();
		sei();
		MOTOR_DC_Init();
		MOTOR_STEPPER_Init();
		MOTOR_SERVO_Init();
		EEPROM_Init();	
}
/******************************************************************************************************************************************************/
/**
 *  Description: Function is used to send the status of the password in EEPROM
 **/
uint8 SYS_send_password_status(void )
{		
	uint8 Error;
	/* checking if the EEPROM contain any old passwords */
	Error=EEPROM_read_Page(0, password.passwrd);
	if (Error == SUCCESS)
	{
		if ( (0xff == password.passwrd[0]) && (0xff == password.passwrd[1]) && (0xff == password.passwrd[2]) && (0xff == password.passwrd[3]) )
			password.frist_time_flag=0;
		else
			password.frist_time_flag=1;
		
		/*sending the Password status */
	
		UART_send(password.frist_time_flag) ;

		UART_send(password.password_correctly_enterd_flag);
	
		UART_send(password.password_saved_flag); 
	
		UART_send(password.passwrd[0]);

		UART_send(password.passwrd[1]); 

		UART_send(password.passwrd[2]);

		UART_send(password.passwrd[3]);
	
		return SUCCESS;
	}
	else
	return ERROR;
  }
/*********************************************************************************************************************************************************/
/**
 *  Description: Function is used to setup the password
 **/
uint8 SYS_CNTRL_setup_password (void)
{
	uint8 Error;
	uint8 password_entered[4];
	
	/* get status of password and send it to decide if its the first time to use the program */
	Error=SYS_send_password_status();
	
	

	if( Error == SUCCESS )
	{
		/* get the password and save it on EEPROM if its the first time */
		if (password.frist_time_flag==0)
		{
			while( UART_isreceived() == 0 )
			;
			password.passwrd[0] = UART_receive_byte();
		
			while( UART_isreceived() == 0 )
			;
			password.passwrd[1] = UART_receive_byte();
			
			while( UART_isreceived() == 0 )
			;
			password.passwrd[2] = UART_receive_byte();
			
			while( UART_isreceived() == 0 )
			;
			password.passwrd[3] = UART_receive_byte();
			
			/* save new password to the EEPROM & rise first time flag   */
			EEPROM_write_page(0,password.passwrd);
		}
		/* not the first time so get password and check if its right */
		else
		{
			
			do 
			{
				/* get password */
				while( UART_isreceived() == 0 )
				;
				password_entered[0] = UART_receive_byte();
		
				while( UART_isreceived() == 0 )
				;
				password_entered[1] = UART_receive_byte();
		
				while( UART_isreceived() == 0 )
				;
				password_entered[2] = UART_receive_byte();
		
				while( UART_isreceived() == 0 )
				;
				password_entered[3] = UART_receive_byte();
		
				EEPROM_read_Page(0,password.passwrd);
				
				/* check if its correctly entered */
				if ( (password_entered[0] == password.passwrd[0]) && (password_entered[1] == password.passwrd[1]) && (password_entered[2] == password.passwrd[2]) && (password_entered[3] == password.passwrd[3]) )
				{
					password.password_correctly_enterd_flag=1;
					UART_send(password.password_correctly_enterd_flag);
					break;
				}
				/* if its wrong */
				else
				{
					password.password_correctly_enterd_flag=0;
					UART_send(password.password_correctly_enterd_flag);
				}
		
			} while (1);
			
		}
		return SUCCESS;
	}
	else
	return ERROR;
	

}
/**************************************************************************************************************************************************/
/**
 *  Description: Function is used to open the door of the system by moving the motors in the right direction
 **/
void SYS_CNTRL_open(uint8 servo_angle )
{
	
	MOTOR_DC_Open();
	MOTOR_SERVO_Set_angle(servo_angle);
	MOTOR_STEPPER_Open();
	
}
/**************************************************************************************************************************************************/
/**
 *  Description: Function is used to close the door of the system by moving the motors in the right direction
 **/
void SYS_CNTRL_close(void)
{
	MOTOR_DC_close();
	MOTOR_STEPPER_Close();
	MOTOR_SERVO_Init();
}
/**************************************************************************************************************************************************/
/**.
 *  Description: Function is used to change the password in EEPROM
 **/
void SYS_CNTRL_change_password( void )
{
	/* Receive new password */
	while( UART_isreceived() == 0 )
	;
	password.passwrd[0] = UART_receive_byte();
			
	while( UART_isreceived() == 0 )
	;
	password.passwrd[1] = UART_receive_byte();
			
	while( UART_isreceived() == 0 )
	;
	password.passwrd[2] = UART_receive_byte();
			
	while( UART_isreceived() == 0 )
	;
	password.passwrd[3] = UART_receive_byte();
	
	/* write password to EEPROM */
	EEPROM_write_page(0,password.passwrd);
	
}
/**************************************************************************************************************************************************/
/**
 *  Description: Function is used to receive menu option and apply it  
 **/
void SYS_CNTRL_menu_option (void)
{
	uint8 menu_option;
	uint8 servo_angle;
	/*receive the option */
	while( UART_isreceived() == 0 )
	;
	menu_option = UART_receive_byte();
	/* applying the option */
	/* 1 open the door */
	if (menu_option == '1' )
	{
		/* receive servo angle */
		while( UART_isreceived() == 0 )
		;
		servo_angle = UART_receive_byte();
		
		SYS_CNTRL_open(servo_angle);		
	}
	/* 2 close the door */
	else if (menu_option == '2')
	{
		SYS_CNTRL_close();
	}
	/* 3 change Password */
	else
	{
		SYS_CNTRL_change_password();
	}
}