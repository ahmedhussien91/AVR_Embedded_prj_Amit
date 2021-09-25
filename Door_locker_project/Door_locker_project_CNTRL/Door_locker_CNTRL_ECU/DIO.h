/** @file    DIO.c
 ** @brief   DIO Module for general use
 ** @author  Mohamed Tarek
 ** @date    22/1/2014
 ** @version 1.1
 */

#ifndef DIO_H_
#define DIO_H_

#define F_CPU 8000000

#include <util/delay.h>
#include <avr/interrupt.h>
#include "STD_TYPE.h"
#include "COMMON_MACROS.h"


#define INPUT 0
#define OUTPUT 1

#define LOGIC_HIGH 1
#define LOGIC_LOW 0

/****************************************************************************************************************/
/** Description: Structure to describe each individual PIN contains:
 *													   1. the PORT Which the pin belongs to. 'A 'B' 'C' or 'D'
 *													   2. the number of the pin in the PORT.
 *													   3. the direction of pin --> INPUT or OUTPUT
 *													   4. the value of the pin used for write */ 
typedef struct {
	uint8 port; 
	uint8 pin_num; 
	uint8 direction; 
	uint8 value; 
}DIO_Config;
/***************************************************************************************************************/

/* configure the PIN to input or output pin */
void DIO_Configuration (const DIO_Config *s_Config_Msg );

/* write 1 or 0 on the pin */
void DIO_Write_Pin(const DIO_Config * s_State);

/* read the pin */
uint8 DIO_Read_Pin(const DIO_Config * s_State);

#endif /* DIO_H_ */