/**
 * @file I2C.c
 * @brief I2C communication module 
 * @date 11/15/2014
 * @author a7med
 * @version 1.0
 **/ 

#include "I2C.h"
/******************************************************************************************************************************/
/**
 *  Description: Function is used to Initialize I2C module to be ready for using 
 **/ 
void TWI_Init(void)
{
	/* setting SCL to 400KHz */
	TWSR=0x00;				
	TWBR=0x02;
	/* enable TWI */
	TWCR=(1<<TWEN);
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to Send start signal
 **/ 
void TWI_start(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR & (1<<TWINT)) == 0);
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to Send stop signal
 **/ 
void TWI_stop(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to write data or address on SDA line 
 **/ 
void TWI_write(uint8 data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT)) == 0);
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to receive data and send acknowledge signal 
 **/ 
uint8 TWI_read_ack(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to receive data without sending an acknowledgment  
 **/ 
uint8 TWI_read_Nack(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to get status of TWI
 **/ 
uint8 TWI_get_status(void)
{
	uint8 status;
	status = TWSR & 0xF8;
	return status;
}