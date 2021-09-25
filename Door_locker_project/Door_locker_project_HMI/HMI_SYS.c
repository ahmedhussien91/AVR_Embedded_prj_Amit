 /**
 * @file HMI_SYS.c
 * @brief Module for HMI ECU used to initialize HMI system,interface with user to setup password and receive menu option and send it to CNTRL ECU
 * @date 11/19/2014
 * @author a7med
 * @version 1.1
 **/ 
#include "HMI_SYS.h"

pass password= {.frist_time_flag = 0, .passwrd={0,0,0,0} ,.password_correctly_enterd_flag = 0, .password_saved_flag = 0 } ;

/********************************************************************************************/
/**
 *  Description: Function is used to Initialize HMI system 
 **/
void SYS_HMI_Init (void)
{	
	UART_init();
	sei();
	LCD_Init();
    LED_buzzer_init();
}
/********************************************************************************************/
/**
 *  Description: Function is used to Initialize HMI system and setup password if not set and return the value of menu option
 **/
uint8 SYS_HMI_setup_password (void)
{
	uint8 i,Mismatch_counter=1;
	uint8 menu_option;
	uint8 tmp;
	uint8 password_recheck[]={0xff,0xff,0xff,0xff};
		
		
	/* get the password status and the password */

	SYS_check_Password_EEPROM();
	
	
	if(password.frist_time_flag == 0 )
	{
		/* password entering and ensuring the user know the password he just entered by reentering it  */
		do 
		{
l1:			LCD_display_string(" Plz Setup Passwrd ");
			LCD_move_3rdline();
			/* getting password from user  */
			for(i=0;i<4;i++)
			{
				while(Keypad_get_pressed_key() == NO_KEY_IS_PRESSED)
				;
				password.passwrd[i]=Keypad_get_pressed_key();
				LCD_display_char(password.passwrd[i]);
				_delay_ms(500);					// delay for the LCD to appear on the screen 
				 if(password.passwrd[i] == 'c')
				{
					LCD_clear();
					LCD_display_string(" passwrd cleared ");
					_delay_ms(1000);				// wait on screen for one sec
					LCD_clear();
					for(i=0;i<4;i++)
					password.passwrd[i]=0;
					goto l1;
				}
				else
				{
					
				}
								
			}
			/* followed by '=' or 'c' or other characters*/
			while( (Keypad_get_pressed_key() == NO_KEY_IS_PRESSED ) )
			;
			tmp=Keypad_get_pressed_key();
			
			/* followed by '=' */
			if (tmp == '=')
			{
				LCD_display_char('=');
				_delay_ms(1000);
				LCD_clear();
l2:				LCD_display_string(" Plz reenter passwrd ");
				LCD_move_3rdline();
				/* user enter the password again */
				for(i=0;i<4;i++)
				{
					while(Keypad_get_pressed_key() == NO_KEY_IS_PRESSED)
					;
					password_recheck[i]=Keypad_get_pressed_key();
					LCD_display_char(password_recheck[i]);
					_delay_ms(500);				// for the character to appear on screen
					 if(password_recheck[i] == 'c')
					 {
						 LCD_clear();
						 LCD_display_string(" passwrd cleared ");
						 _delay_ms(1000);				// wait on screen for one sec
						 LCD_clear();
						 for(i=0;i<4;i++)
						 password_recheck[i]=0;
						 goto l2;
					 }
				}
				/* checking if two password match */
				/* if match send password to EEPROM and update the frist_time_flag */
				if ( (password_recheck[0] == password.passwrd[0]) && (password_recheck[1] == password.passwrd[1]) && (password_recheck[2] == password.passwrd[2]) && (password_recheck[3] == password.passwrd[3]) )
				{
					UART_send(password.passwrd[0]);
					UART_send(password.passwrd[1]);
					UART_send(password.passwrd[2]);
					UART_send(password.passwrd[3]);
					
					LED_GREEN_flash();
					LCD_clear();
					LCD_display_string(" plz restart system ");
					return 0;
				}
					/* password mismatch with previously entered password */
				else
				{
						LCD_clear();
						LCD_display_string(" password mismatch ");
						LED_RED_flash();
						BUZZER_BEEB();
						_delay_ms(1000);		// wait on screen for one sec
						LCD_clear();
				}
				
			}
			
				/* or enter 'c' to clear the password to write a new one  */
			else if (Keypad_get_pressed_key() == 'c') 
			{
				LCD_clear();
				LCD_display_string(" passwrd cleared ");
				_delay_ms(1000);				// wait on screen for one sec
				LCD_clear();		
				for(i=0;i<4;i++)
				password.passwrd[i]=0;
			}
			else
			{
		
			}
			/* or entering another character which will lead to system error */
		}
		while(1);
	}
	
	/* entering the password and send it to CNTRL to check if password matches with that is on EEPROM the system will open */
	else
	{
		do
		{	
			LCD_display_string(" Plz enter Passwrd ");
			LCD_move_3rdline();
			/* getting password from user  */
			for(i=0;i<4;i++)
			{
				while(Keypad_get_pressed_key() == NO_KEY_IS_PRESSED)
				;
				password.passwrd[i]=Keypad_get_pressed_key();
				LCD_display_char(password.passwrd[i]);
				_delay_ms(500);				// delay for the LCD to appear on the screen
			}
		
			/* sending password for checking */
			UART_send(password.passwrd[0]);
			UART_send(password.passwrd[1]);
			UART_send(password.passwrd[2]);
			UART_send(password.passwrd[3]);
			

			/* getting confirmation on sent password */	
			while( UART_isreceived() == 0 )
			;
			password.password_correctly_enterd_flag = UART_receive_byte();
			
			
			/* right password entered */
			if (password.password_correctly_enterd_flag == 1)
			{
				LCD_clear();
				LCD_display_string(" passwrd is correct ");
				LED_GREEN_flash();
				_delay_ms(1000);
				LCD_clear();
				LCD_display_string(" choose an option ");
				LCD_move_2ndline();
				LCD_display_string(" 1-open Door ");
				LCD_move_3rdline();
				LCD_display_string(" 2-close Door ");
				LCD_move_4thline();
				LCD_display_string(" 3-change passwrd ");
				_delay_ms(1000);
				/* getting the right menu option */
			
				menu_option = SYS_HMI_get_menu_option ();
			
				/* sending this option to function to do this option */
			
				return (menu_option);
			
			}
			/* wrong entered password */
			else
			{
				if (Mismatch_counter < 3)
				{
					Mismatch_counter++;
					LCD_clear();
					LCD_display_string(" passwrd is wrong ");
					LED_RED_flash();
					BUZZER_BEEB();
					_delay_ms(1000);
					LCD_clear();
				}
				else
				{
						LCD_clear();
						LCD_display_string(" system is locked");
						LED_RED_ON();
						for(;;)
						BUZZER_BEEB();
						return 0;
				}

			}
		}while(1);
	} 

}
/************************************************************************************************************************************************************************************************/
/**
 *  Description: Function is used to get the status of password form CNTRL unit using UART 
 **/
void SYS_check_Password_EEPROM(void )
{
	while( UART_isreceived() == 0 )
	;
	password.frist_time_flag = UART_receive_byte();
	
	while( UART_isreceived() == 0 )
	;
	password.password_correctly_enterd_flag = UART_receive_byte();
	
	while( UART_isreceived() == 0 )
	;
	password.password_saved_flag = UART_receive_byte();
	
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
	
}

/**********************************************************************************************************************************************************************/
/**
 *  Description: Function is used to send menu option to CNTRL unit
 **/
void SYS_HMI_menu_option_send (uint8 menu_option)
{
	uint8 i;
	uint8 servo_angle[3]={0};
	uint8 password_recheck[4]={0};
	uint16 servo_angle_int;
	/* send menu option */
	UART_send(menu_option);
	/* open the system */
	if (menu_option == '1')
	{
		/* get the servo angle from user */
		do 
		{		
			LCD_clear();
			LCD_display_string(" plz enter servo angle ");
			for(i=0;i<3;i++)
			{
				while(Keypad_get_pressed_key() == NO_KEY_IS_PRESSED)
				;
				servo_angle[i]=Keypad_get_pressed_key();
				LCD_display_char(servo_angle[i]);
				_delay_ms(500);
			}
			/* translating the servo angle into integer */
			servo_angle_int = atoi(servo_angle);
			/* wrong servo input */	
			if (servo_angle_int >= 180 )
			{
				LCD_clear();
				LCD_display_string(" wrong value ");
				_delay_ms(1000);
			}
			/* right servo input */
			else
			{
				UART_send((uint8)servo_angle_int);
				LCD_clear();                                                                                            
				LCD_display_string(" opening the Door ");
				_delay_ms(1000);
				break;
			}
		} while (1);
	}
	else if (menu_option == '2')
	{
		LCD_clear();
		LCD_display_string(" closing the Door ");
		_delay_ms(1000);	
	}
	else if(menu_option == '3')
	{
		do 
		{
			/* getting password from user  */
			LCD_clear();
			LCD_display_string(" Plz enter Passwrd ");
			LCD_move_3rdline();
			for(i=0;i<4;i++)
			{
				while(Keypad_get_pressed_key() == NO_KEY_IS_PRESSED)
				;
				password.passwrd[i]=Keypad_get_pressed_key();
				LCD_display_char(password.passwrd[i]);
				_delay_ms(500);				// delay for the LCD to appear on the screen
			}
			/* getting password confirmation */
			LCD_clear();
			LCD_display_string(" plz reenter passwrd");
			LCD_move_3rdline();
			for(i=0;i<4;i++)
			{
				while(Keypad_get_pressed_key() == NO_KEY_IS_PRESSED)
				;
				password_recheck[i]=Keypad_get_pressed_key();
				LCD_display_char(password_recheck[i]);
				_delay_ms(500);				// for the character to appear on screen
			}
			/* password match */
			if ( (password_recheck[0] == password.passwrd[0]) && (password_recheck[1] == password.passwrd[1]) && (password_recheck[2] == password.passwrd[2]) && (password_recheck[3] == password.passwrd[3]) )
			{
				UART_send(password.passwrd[0]);
				UART_send(password.passwrd[1]);
				UART_send(password.passwrd[2]);
				UART_send(password.passwrd[3]);
					
				LCD_clear();
				LCD_display_string(" password changed ");
				_delay_ms(1000);
				break;
			}
			/* password mismatch with previously entered password */
			else
			{
				LCD_clear();
				LCD_display_string(" password mismatch ");
				_delay_ms(1000);		// wait on screen for one sec
				LCD_clear();
			}
		} while (1);
	}
	else
	{
		while(1)
		;
	}
}
/*************************************************************************************************************************************************************************/
/**
 *  Description: Function is used to get menu option from user
 **/
uint8 SYS_HMI_get_menu_option (void)
{
	uint8 menu_option;
		do
		{
			while(Keypad_get_pressed_key() == NO_KEY_IS_PRESSED)
			;
			menu_option=Keypad_get_pressed_key();
			if (( menu_option == '1') || ( menu_option == '2' ) || (menu_option =='3') )
			{
				LCD_display_char(menu_option);
				_delay_ms(500);
				break;
			}
		} while (1);
		return menu_option;
}

/*************************************************************************************************************************************************************************/
/**
 *  Description: Function is used to resend the menu option
 **/
void SYS_HMI_resend_menu_option (void)
{
	uint8 menu_option;
	LCD_clear();
	LCD_display_string(" choose an option ");
	LCD_move_2ndline();
	LCD_display_string(" 1-open Door ");
	LCD_move_3rdline();
	LCD_display_string(" 2-close Door ");
	LCD_move_4thline();
	LCD_display_string(" 3-change passwrd ");
	_delay_ms(1000);
	
	menu_option=SYS_HMI_get_menu_option();
	
	SYS_HMI_menu_option_send(menu_option);
}