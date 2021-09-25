/**
 * @file EEPROM.c
 * @brief EEPROM module to write and read from EEPROM using I2C 
 * @date 11/17/2014
 * @author a7med
 * @version 1.0
 **/ 

#include "EEPROM.h"
/*****************************************************************************************************************************************************************************/
/**
 *Description : Function is used to initialize I2C module inside the Micro controller to initialize the EEPROM writing and reading 
 **/
void EEPROM_Init (void)
{
	TWI_Init();
}

/****************************************************************************************************************************************************************************/
/**
 *Description : Function is used to write a byte to EEPROM it takes the address and data to be written and it return 1 to tell if it successfully did it
 **/
uint8 EEPROM_write_byte (uint16 addr ,uint8 data)
{
	TWI_start();
	if(TWI_get_status() != 0x08 )
	{
		return ERROR;
	}
	
	/* select EEPROM and send upper 3 address bits + write bits */
	TWI_write((0xA0)|(uint8)((addr &0x0700)>>7));
	if(TWI_get_status() != 0x18 )
	{
		return ERROR;
	}
	
	/* sending the rest of the address */ 
	TWI_write((uint8) (addr) );
	if(TWI_get_status() != 0x28 )
	{
		return ERROR;
	}
	
	/* write the data byte to EEPROM */
	TWI_write(data);
	if(TWI_get_status() != 0x28 )
	{
		return ERROR;
	}
	
	TWI_stop();
	return SUCCESS;
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to read a byte from EEPROM it takes the address of data byte to be read and a pointer to uint8 to recive data in , it return SUCCESS to tell if it successfully did it
 **/
uint8 EEPROM_read_byte (uint16 addr ,uint8 *data)
{
	TWI_start();
	if(TWI_get_status() != 0x08 )
	{
		return ERROR;
	}
	
	/* select EEPROM and send upper 3 address bits + write bits */
	TWI_write((0xA0)|(uint8)((addr &0x0700)>>7));
	if(TWI_get_status() != 0x18 )
	{
		return ERROR;
	}

	/* sending the rest of the address */ 
	TWI_write((uint8) (addr) );
	if(TWI_get_status() != 0x28 )
	{
		return ERROR;
	}
	
	/* send a repeated start */
	TWI_start();
	if(TWI_get_status() != 0x10 )
	{
		return ERROR;
	}
	
	/* select EEPROM & send read bit */
	TWI_write((0xA0)|((uint8)((addr & 0x0700) >> 7 ))|1);
	if(TWI_get_status() != 0x40 )
	{
		return ERROR;
	}
	
	/* get data from EEPROM */
	*data = TWI_read_Nack();
	if(TWI_get_status() != 0x58)
	{
		return ERROR;
	}
	TWI_stop();
	return SUCCESS;
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to write to a Page ( of size 8 bytes ) to EEPROM it takes the address and data to be written and it return 1 to tell if it successfully did it
 **/
uint8 EEPROM_write_page (uint8 Page ,uint8 *data)
{
	uint8 P_addr = 0;
	uint8 i;
	P_addr = Page << 2;
	
	TWI_start();
	if(TWI_get_status() != 0x08 )
	{
		return ERROR;
	}
	
	/* select EEPROM and send upper 3 address bits + write bits */
	TWI_write((0xA0)|(( Page  &0xE0)>>4));
	if(TWI_get_status() != 0x18 )
	{
		return ERROR;
	}
	
	/* sending the rest of the address */ 
	TWI_write( P_addr );
	if(TWI_get_status() != 0x28 )
	{
		return ERROR;
	}
	
	/* write the data byte to EEPROM */
	for(i=0; i<4; i++)
	{
		TWI_write(data[i]);
		if(TWI_get_status() != 0x28 )
			{
				return ERROR;
			}
	}
	TWI_stop();
	return SUCCESS;
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to read a byte from EEPROM it takes the address of data byte to be read and a pointer to uint8 to recive data in , it return SUCCESS to tell if it successfully did it
 **/
uint8 EEPROM_read_Page (uint8 Page ,uint8 *data)
{
	uint8 p_addr=0;
	uint8 i;
	p_addr = Page << 2;
	
	TWI_start();
	if(TWI_get_status() != 0x08 )
	{
		return ERROR;
	}
	
	/* select EEPROM and send upper 3 address bits + write bits */
	TWI_write((0xA0)|(( Page & 0xE0)>>4));
	if(TWI_get_status() != 0x18 )
	{
		return ERROR;
	}

	/* sending the rest of the address */ 
	TWI_write(p_addr);
	if(TWI_get_status() != 0x28 )
	{
		return ERROR;
	}
	
	/* send a repeated start */
	TWI_start();
	if(TWI_get_status() != 0x10 )
	{
		return ERROR;
	}
	
	/* select EEPROM & send read bit */
	TWI_write((0xA0)|((Page & 0xE0) >> 4)|1);
	if(TWI_get_status() != 0x40 )
	{
		return ERROR;
	}
	
	/* get data from EEPROM */
	for(i=0; i<3; i++)
	{
		data[i] = TWI_read_ack();
		if(TWI_get_status() != 0x50)
		{
			return ERROR;
		}
	}
	data[i] = TWI_read_Nack();
	if(TWI_get_status() != 0x58)
	{
		return ERROR;
	}
	TWI_stop();
	return SUCCESS;
}