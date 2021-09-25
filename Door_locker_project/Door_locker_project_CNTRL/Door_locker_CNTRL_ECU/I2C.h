/**
 * @file I2C.h
 * @brief I2C communication module 
 * @date 11/15/2014
 * @author a7med
 * @version 1.0
 **/ 


#ifndef I2C_H_
#define I2C_H_

#include "DIO.h"


/* initialize TWI */ 
void TWI_Init(void);
/* send start signal on TWI pins */
void TWI_start(void);
/* send stop signal on TWI pins */
void TWI_stop(void);
/* send one byte of data on SDA PIN */
void TWI_write(uint8 data);
/* read one byte of data from SDA PIN and send an acknowledgment  */
uint8 TWI_read_ack(void);
/* read one byte of data from SDA PIN but dont send an acknowledgement*/
uint8 TWI_read_Nack(void);
/* get status of the TWI */
uint8 TWI_get_status(void);


#endif /* I2C_H_ */