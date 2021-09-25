/**
 * @file UART.h
 * @brief UART Module contain functions to communicate using UART 
 * @date 9/20/2014
 * @author a7med
 * @version 1.1
 **/ 

#ifndef UART_H_
#define UART_H_

#include "DIO.h"

/********************************************************************************************************************/

/**Initialize UART Module */
void UART_init (void);
/**Send character */
void UART_send (uint8 data);
/**Receive byte  */
uint8 UART_receive_byte (void);
/**Check if byte is received */
uint8 UART_isreceived (void);


#endif /* UART_H_ */