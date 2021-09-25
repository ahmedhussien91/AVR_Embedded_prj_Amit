/**
 * @file LCD.c
 * @brief LCD Module for general use
 * @date 11/1/2014
 * @author a7med
 * @version 1.1
 **/ 

#include "LCD.h"

/*************************************************************************************************************************************/
/**
 *  Description: Function used to initialize the LCD in 8 bit 4 Line Mode & ligth on Display
 **/ 
void LCD_Init() 
{
	Data_DIR= 0xff;										// set direction of data Pins as output to send commands to LCD 
	CTRL_DIR= (1<<RS)|(1<<E)|(1<<RW);										// set direction of control Pins as output to send commands to LCD
	
	LCD_clear();										// clear ,followed by 8bit 1 line followed by entry mode initialization 
	LCD_send_cmd(Mode8_1line);							// all together are used to reset LCD module
	LCD_send_cmd(Display_off);
	LCD_send_cmd(Entry_Mode_init);						
	LCD_send_cmd(Mode8_4lines);							//initialize the LCD to 8 bit 4 line Mode
	LCD_send_cmd(Display_on);							// light on display
	
}
/************************************************************************************************************************************/
/**
 *  Description: Function used to send instruction to LCD 
 **/ 
void LCD_send_cmd(uint8 cmd)
{
	Data_PORT = cmd;									// command to be sent
	CLR_BIT(CTRL_PORT,RS);								// selecting to transfer instruction data
	CLR_BIT(CTRL_PORT,RW);								// selecting write to LCD
	CLR_BIT(CTRL_PORT,E);								// enable LCD to read instruction data 
	_delay_ms(1);										// wait for instruction to be accepted 
	SET_BIT(CTRL_PORT,E);								// disable LCD
}
/**************************************************************************************************************************************/
/**
 *  Description: Function is used to display data to LCD 
 **/ 
void LCD_display_char(uint8 data)
{
	Data_PORT = data;										// character to be displayed on LCD
	SET_BIT(CTRL_PORT,RS);									// selecting to transfer display data	
	CLR_BIT(CTRL_PORT,RW);									// selecting to write to LCD
	CLR_BIT(CTRL_PORT,E);									// enable LCD to read instruction data 
	_delay_ms(1);											// wait for instruction to be accepted
	SET_BIT(CTRL_PORT,E);									// disable LCD	
}
/****************************************************************************************************************************************/
/**
 *  Description: Function is used to display string on screen 
 **/ 
void LCD_display_string(uint8 *string)
{
	uint8 Count=0;											// counter to point to characters in the string 
	while(string[Count]!='\0')								//Display characters of string until END of string '\0'
	{
			LCD_display_char(string[Count]); 
			Count++;
	}
	
}
/*****************************************************************************************************************************************/
/**
 *  Description: Function is used to display integers on screen 
 **/ 
void LCD_display_int(uint16 integer1)
{
		uint8 string[16];										//array to carry string  <<<<<<<<<<<<<<<<<<<<<<<<<<<<(optimize u only need 3 characters )
		int2str (integer1 ,string);								//convert from int to string
		LCD_display_string(string);								// display string
}
/*****************************************************************************************************************************************/
/**
 *  Description: Function is used to clear screen and return crusor to its initial position 
 **/ 
void LCD_clear()
{
		LCD_send_cmd(Clear_display);
}
/*****************************************************************************************************************************************/
/**
 *  Description: Function is used to convert form integer to string 
 **/ 
void int2str (uint16 integer1,uint8* string)
{
	const uint8 digit[] = {'0','1','2','3','4','5','6','7','8','9'};	// characters that combine any number 
	uint8* string1=string;													//array to carry converted integer 
	uint8 int_count=0;
	uint16 shifter=integer1;											// dummy variable used to know integer count  
	while(shifter)														//knowing integer count
	{
		shifter=shifter/10;
		int_count++;
	}
	string1[int_count]='\0';											//putting end of string @ end of converted string
	int_count--;

	while(integer1)														//converting each integer to string character
	{
		string1[int_count]=digit[integer1%10];
		integer1=integer1/10;
		int_count--;
	}

	 
}
/*********************************************************************************************************************/
/**
 *  Description: Function is used to move cursor to the 2nd line 
 **/ 
void LCD_move_2ndline()
{
	LCD_send_cmd(DDRAM_add_2ndline);
}

/*********************************************************************************************************************/
/**
 *  Description: Function is used to move cursor to the 3rd line 
 **/ 
void LCD_move_3rdline()
{
	LCD_send_cmd(DDRAM_add_3rdline);
}

/*********************************************************************************************************************/
/**
 *  Description: Function is used to move cursor to the 4th line 
 **/ 
void LCD_move_4thline( )
{
	LCD_send_cmd(DDRAM_add_4thline);
}

/*********************************************************************************************************************/
/**
 *  Description: Function is used to move cursor to the 4th line 
 **/ 
void LCD_clear_character()
{
LCD_send_cmd(Entry_Mode);
LCD_display_char(0x00);
LCD_display_char(0x00);
LCD_send_cmd(Entry_Mode_init);


}