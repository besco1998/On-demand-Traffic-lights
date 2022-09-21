/*
 * TrafficLights.c
 *
 * Created: 9/10/2022 4:56:36 AM
 * Author : Mohamed Ashraf Farouk
 */ 

// #include "Drivers Test/drivers_test.h"
#include "Application/app.h"
	

int main(void)
{
	/* Testing Section*/
	
	/*
	test_DIO_driver();
	test_Interrupt_driver();
	test_Timers_driver();
	test_LED_driver();
	test_Button_driver();
	*/
	
	/* Application Section */
	APP_init(); // initialize the peripherals
	
	APP_start(); // stat application
   
}// main function


