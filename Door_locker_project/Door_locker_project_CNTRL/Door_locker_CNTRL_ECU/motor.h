/**
 * @file motor.h
 * @brief motor Module contain functions to control all motors in the system
 * @date 11/9/2014
 * @author a7med
 * @version 1.0
 **/ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "Timer.h"

#define DC_MOTOR_WORKING_DELAY 1000
#define L293D_IN1 PD2
#define L293D_IN2 PD3
#define L293D_EN1 PC5
#define L293D_IN1_PORT 'D'
#define L293D_IN2_PORT 'D'
#define L293D_EN1_PORT 'C'
#define ULN2003_PORT 'A'
#define ULN2003_A PA0
#define ULN2003_B PA1
#define ULN2003_Abar PA2
#define ULN2003_Bbar PA3
#define STEPPER_MOTOR_RESPONSE_TIME 500
#define DUTY_1MS 16


/* initialize Pins of DC motor */
void MOTOR_DC_Init(void);
/* initialize Pins of Stepper motor */
void MOTOR_STEPPER_Init(void);
/* initialize Pins of Servo motor */
void MOTOR_SERVO_Init(void);
/* activate motor on anticlockwise direction for 1 sec to open lock */
void MOTOR_DC_Open(void);
/* rotate the stepper motor 360 degree rotation in clockwise direction to open lock   */
void MOTOR_STEPPER_Open(void);
/* activate motor on clockwise direction for 1 sec to close the lock */
void MOTOR_DC_close(void);
/*rotate the stepper motor 360 degree rotation in anticlockwise direction to close lock   */
void MOTOR_STEPPER_Close(void);
/* set angle of Servo motor */ 
void MOTOR_SERVO_Set_angle (uint8 angle);









#endif /* MOTOR_H_ */