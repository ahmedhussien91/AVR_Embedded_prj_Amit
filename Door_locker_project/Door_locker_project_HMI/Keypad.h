/**
 * @file Keypad.h
 * @brief Keypad Module for door locker program
 * @date 11/1/2014
 * @author a7med
 * @version 1.1
 **/ 





#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"



#define keypad_DIR DDRA
#define Keypad_PORT PORTA					
#define keypad_PIN PINA


#define NO_KEY_IS_PRESSED 0xff



uint8 Keypad_get_pressed_key ();




#endif /* KEYPAD_H_ */