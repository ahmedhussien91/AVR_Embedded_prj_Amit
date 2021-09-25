/**
 * @file Keypad.c
 * @brief Keypad Module for door locker program
 * @date 11/1/2014
 * @author a7med
 * @version 1.1
 **/ 

#include "Keypad.h"

/*****************************************************************************************************************/

uint8 key_table[4][4]={ {'/','9','8','7'},{'x','6','5','4'},{'-','3','2','1'},{'+','=','0','c'} }; // characters that can be pressed on keypad
	
/****************************************************************************************************************/
/**
 *  Description: Function used to get the keypad pressed key 
 **/ 
uint8 Keypad_get_pressed_key (void)
{
	 
	for(uint8 row=0;row<4;row++)																	// loop on four PINS 
	{
		keypad_DIR =  (1<<row);																		// set one pin of Four PINs of keypad as input	
		Keypad_PORT= ~(1<<row);																		//for this pin enable pull up network
		for( uint8 col=0;col<4;col++)																// loop other 4 pins to discover which botton is pressd
		{
			if((keypad_PIN & (0b11110000))==((~(1<<(col+4)))&(0b11110000)))
				return( key_table[row][col]);														// return pressed botton 
		}	
	}
	return NO_KEY_IS_PRESSED;																		// if nothing is pressed return no key is pressed
}