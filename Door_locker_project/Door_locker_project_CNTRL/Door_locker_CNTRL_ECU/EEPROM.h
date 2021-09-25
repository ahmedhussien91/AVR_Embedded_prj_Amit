/**
 * @file EEPROM.h
 * @brief EEPROM module to write and read from EEPROM using I2C 
 * @date 11/17/2014
 * @author a7med
 * @version 1.0
 **/ 

#ifndef EEPROM_H_
#define EEPROM_H_

#include "I2C.h"

/*************************************************************/
#define SUCCESS 1
#define ERROR 0

/************************************************************/
/**/
void EEPROM_Init (void);
/**/
uint8 EEPROM_write_byte (uint16 addr ,uint8 data);
/**/
uint8 EEPROM_read_byte (uint16 addr ,uint8 *data);
/**/
uint8 EEPROM_write_page (uint8 Page ,uint8 *data);
/**/
uint8 EEPROM_read_Page (uint8 Page ,uint8 *data);


#endif /* EEPROM_H_ */