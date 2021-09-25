 /**
 * @file Door_locker_project.c
 * @brief Main Program of HMI ECU
 * @date 11/1/2014
 * @author a7med
 * @version 1.1
 **/



#include "HMI_SYS.h"


int main(void)
{
		uint8 menu_option;
		SYS_HMI_Init();
		
				
		menu_option= SYS_HMI_setup_password ();
		
		SYS_HMI_menu_option_send(menu_option);
		
		

    while(1)
    {

		SYS_HMI_resend_menu_option ();

    }
}