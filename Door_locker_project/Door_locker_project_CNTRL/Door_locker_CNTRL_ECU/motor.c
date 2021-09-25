/**
 * @file motor.c
 * @brief motor Module contain functions to control all motors in the system
 * @date 11/9/2014
 * @author a7med
 * @version 1.0
 **/ 


#include "motor.h"



/*******************************************************************************************************************************/
/* Pins of DC motor */
static DIO_Config DC_motor_A={L293D_IN1_PORT,L293D_IN1,OUTPUT,LOGIC_LOW};
static DIO_Config DC_motor_b={L293D_IN2_PORT,L293D_IN2,OUTPUT,LOGIC_LOW};
static DIO_Config DC_motor_enable={L293D_EN1_PORT,L293D_EN1,OUTPUT,LOGIC_HIGH};
/*******************************************************************************************************************************/
/* Pins of Stepper motor */
static DIO_Config Stepper_motor_A={ULN2003_PORT,ULN2003_A,OUTPUT,LOGIC_LOW};
static DIO_Config Stepper_motor_B={ULN2003_PORT,ULN2003_B,OUTPUT,LOGIC_LOW};
static DIO_Config Stepper_motor_Abar={ULN2003_PORT,ULN2003_Abar,OUTPUT,LOGIC_LOW};
static DIO_Config Stepper_motor_Bbar={ULN2003_PORT,ULN2003_Bbar,OUTPUT,LOGIC_LOW};
	
/******************************************************************************************************************************/
/**
 *  Description: Function is used to configure DC motor pins to output
 **/ 
void MOTOR_DC_Init(void)
{
	DIO_Configuration(&DC_motor_A);				/*pin A & b used to determine direction of rotation and whether the motor is on or off */
	DIO_Configuration(&DC_motor_b);
	DIO_Configuration(&DC_motor_enable);			/* enable Pin enable the chip */
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to configure stepper motor pins to output
 **/ 
void MOTOR_STEPPER_Init(void)
{
	DIO_Configuration(&Stepper_motor_A);				
	DIO_Configuration(&Stepper_motor_B);
	DIO_Configuration(&Stepper_motor_Abar);			
	DIO_Configuration(&Stepper_motor_Bbar);
}

/*****************************************************************************************************************************/
/**
 *  Description: Function is used to o/p PIN_A=1 ,PIN_b=0 ,PIN_enable=1 for 1 sec to open lock then configure PIN_b=1 to stop motor
 **/ 
void MOTOR_DC_Open(void)
{
	DC_motor_A.value=LOGIC_HIGH;
	DIO_Write_Pin(&DC_motor_A);
	DIO_Write_Pin(&DC_motor_b);
	DIO_Write_Pin(&DC_motor_enable);
	_delay_ms(DC_MOTOR_WORKING_DELAY);
	
	DC_motor_b.value=LOGIC_HIGH;
	DIO_Write_Pin(&DC_motor_b);
}
/*****************************************************************************************************************************/
/**
 *  Description: Function is used to rotate the stepper motor 360 degree rotation in the clockwise direction to open lock
 **/ 
void MOTOR_STEPPER_Open(void)
{
	Stepper_motor_A.value=LOGIC_HIGH;
	Stepper_motor_B.value=LOGIC_HIGH;
	DIO_Write_Pin(&Stepper_motor_A);
	DIO_Write_Pin(&Stepper_motor_B);
	DIO_Write_Pin(&Stepper_motor_Abar);
	DIO_Write_Pin(&Stepper_motor_Bbar);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
	
	Stepper_motor_A.value=LOGIC_LOW;
	Stepper_motor_Abar.value=LOGIC_HIGH;
	DIO_Write_Pin(&Stepper_motor_A);
	DIO_Write_Pin(&Stepper_motor_Abar);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
	
	Stepper_motor_B.value=LOGIC_LOW;
	Stepper_motor_Bbar.value=LOGIC_HIGH;
	DIO_Write_Pin(&Stepper_motor_B);
	DIO_Write_Pin(&Stepper_motor_Bbar);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
	
	Stepper_motor_Abar.value=LOGIC_LOW;
	Stepper_motor_A.value=LOGIC_HIGH;
	DIO_Write_Pin(&Stepper_motor_A);
	DIO_Write_Pin(&Stepper_motor_Abar);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
	
	Stepper_motor_A.value=LOGIC_LOW;
	Stepper_motor_Bbar.value=LOGIC_LOW;
	DIO_Write_Pin(&Stepper_motor_A);
	DIO_Write_Pin(&Stepper_motor_Bbar);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
}
/*****************************************************************************************************************************/
/**
 *  Description: Function is used to o/p PIN_A=0 ,PIN_b=1 ,PIN_enable=1 for 1 sec to close lock then configure PIN_b=0 to stop motor
 **/ 
void MOTOR_DC_close(void)
{
	DC_motor_A.value=LOGIC_LOW;
	DIO_Write_Pin(&DC_motor_A);
	_delay_ms(DC_MOTOR_WORKING_DELAY);
	DC_motor_b.value=LOGIC_LOW;
	DIO_Write_Pin(&DC_motor_b);
}
/*****************************************************************************************************************************/
/**
 *  Description: Function is used to rotate the stepper motor 360 degree rotation in the anticlockwise direction to close lock
 **/ 
void MOTOR_STEPPER_Close(void)
{
	Stepper_motor_Bbar.value=LOGIC_HIGH;
	Stepper_motor_Abar.value=LOGIC_HIGH;
	DIO_Write_Pin(&Stepper_motor_A);
	DIO_Write_Pin(&Stepper_motor_B);
	DIO_Write_Pin(&Stepper_motor_Abar);
	DIO_Write_Pin(&Stepper_motor_Bbar);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
	
	Stepper_motor_Bbar.value=LOGIC_LOW;
	Stepper_motor_B.value=LOGIC_HIGH;
	DIO_Write_Pin(&Stepper_motor_Bbar);
	DIO_Write_Pin(&Stepper_motor_B);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
	
	Stepper_motor_Abar.value=LOGIC_LOW;
	Stepper_motor_A.value=LOGIC_HIGH;
	DIO_Write_Pin(&Stepper_motor_Abar);
	DIO_Write_Pin(&Stepper_motor_A);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
	
	Stepper_motor_B.value=LOGIC_LOW;
	Stepper_motor_Bbar.value=LOGIC_HIGH;
	DIO_Write_Pin(&Stepper_motor_B);
	DIO_Write_Pin(&Stepper_motor_Bbar);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
	
	Stepper_motor_A.value=LOGIC_LOW;
	Stepper_motor_Bbar.value=LOGIC_LOW;
	DIO_Write_Pin(&Stepper_motor_A);
	DIO_Write_Pin(&Stepper_motor_Bbar);
	_delay_ms(STEPPER_MOTOR_RESPONSE_TIME);
}
/******************************************************************************************************************************/
/**
 *  Description: Function is used to configure servo motor pin ( timer 0 OC0) to output and set its angle to 0 which is equivalent to 1ms duty cycle
 **/ 
void MOTOR_SERVO_Init(void)
{
	Timer0_PWM_init(DUTY_1MS);
}
/*****************************************************************************************************************************/
/**
 *  Description: Function is used to set angle of servo motor function take angles between 0 and 180
 **/ 
void MOTOR_SERVO_Set_angle (uint8 angle)
{
	uint8 Duty_cycle;
	
	Duty_cycle=(angle*(191.0-16.32)/180.0)+16.32;
	Timer0_PWM_Set_duty(Duty_cycle);
	

}
/*****************************************************************************************************************************/

