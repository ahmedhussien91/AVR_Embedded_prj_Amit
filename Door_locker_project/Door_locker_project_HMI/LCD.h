/**
 * @file LCD.h
 * @brief LCD Module for general use
 * @date 11/1/2014
 * @author a7med
 * @version 1.1
 **/ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include <util/delay.h>
#include <stdlib.h>
#include "DIO.h"



#define Data_DIR DDRC
#define Data_PORT PORTC
#define CTRL_DIR DDRD
#define CTRL_PORT PORTD
#define RS PD2
#define E PD4
#define RW PD3


#define Mode8_4lines 0x38
#define Display_off 0x08
#define Mode8_1line 0x32
#define Entry_Mode_init 0x06
#define Entry_Mode 0x04
#define Display_on 0x0f
#define Clear_display 0x01
#define return_home 0x03
#define DDRAM_add_2ndline 0xc0
#define DDRAM_add_3rdline 0x94                       
#define DDRAM_add_4thline 0xd4


/*initialize LCD in 8bit 4 line mode */
void LCD_Init (void);
/*send cmd to LCD */
void LCD_send_cmd (uint8 cmd );
/*display char on LCD */
void LCD_display_char(uint8 data);
/*display string on LCD */
void LCD_display_string(uint8 *string);
/* display integer on LCD */
void LCD_display_int(uint16 integer);
/*clear LCD */
void LCD_clear ();
void int2str (uint16 integer1,uint8* b);
/*move cursor to 2nd line */
void LCD_move_2ndline ();
/*move cursor to 3rd line */
void LCD_move_3rdline ();
/*move cursor to 4thline */
void LCD_move_4thline ();
/* clear a character on LCD */
void LCD_clear_character (void);










#endif /* INCFILE1_H_ */