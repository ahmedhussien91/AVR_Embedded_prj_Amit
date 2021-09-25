/**
 * @file UART.c
 * @brief UART Module contain functions to communicate using UART 
 * @date 9/20/2014
 * @author a7med
 * @version 1.1
 **/ 


#include "UART.h"


static uint8 data , new_flag = 0;
/**************************************************************************************/
/**
 *  Description: Interrupt service routine that rise a flag when receiving frame is complete
 **/ 
ISR(USART_RXC_vect)
{
	new_flag = 1;
	data=UDR;
}
/**************************************************************************************/
/**
 *  Description: function is used to initialize the UART module in the 8-bit with 9600 bit/sec baud rate 
 **/ 
void UART_init(void)
{
	UCSRA=0x00;
	UCSRB=(1<<TXEN)|(1<<RXEN)|(1<<RXCIE);			/* enable transmitter ,enable receiver and enable receiver interrupt */   
	UCSRC=(1<<UCSZ1)|(1<<UCSZ0)|(1<<URSEL);			/* enable 8-bit transmission ,asynchronous operation , parity bit is disabled */
	UBRRH=0;
	UBRRL=51;
}
/***********************************************************************************/
/**
 *  Description: Function is used to send character using UART 
 **/ 
void UART_send(uint8 sent_data)
{
	while(!(UCSRA & (1<<UDRE) ))
	;									// Do nothing until UDR is ready for more data to be written to it
	UDR=sent_data;
	
}
/*************************************************************************************/
/**
 *  Description: Function is used to receive a byte using the UART
 **/ 
uint8 UART_receive_byte(void)
{
	new_flag=0;
	return data;
}
/**************************************************************************************/
/**
 *  Description: Function return 1 when the reception is complete and 0 otherwise 
 **/ 
uint8 UART_isreceived()
{
	return new_flag;
}
