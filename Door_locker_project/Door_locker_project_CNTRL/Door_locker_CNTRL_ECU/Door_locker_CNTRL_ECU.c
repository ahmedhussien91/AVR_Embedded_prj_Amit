 /**
 * @file Door_locker_CNTRL_ECU.c
 * @brief Main Program of CNTRL ECU
 * @date 11/8/2014
 * @author a7med
 * @version 1.1
 **/
  
#include "CNTRL_SYS.h"


int main(void)
{
	uint8 i;
	/* initializing the system */
	SYS_CNTRL_Init();
	_delay_ms(100);


	/* sending the password status, receiving the password and acknowledging if its correct */
	i=SYS_CNTRL_setup_password();
	

    while(1)
    {
		/* receiving the menu option and applying it */
		SYS_CNTRL_menu_option ();
    }
}