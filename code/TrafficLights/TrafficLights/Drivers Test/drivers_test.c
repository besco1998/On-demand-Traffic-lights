/*
 * driver_tests.c
 *
 * Created: 9/13/2022 8:20:56 PM
 *  Author: compu zone
 */ 

#include "drivers_test.h"

//global test variables
uint8_t x=0;

uint8_t test_DIO_init =0;
uint8_t test_DIO_write =0;
uint8_t test_DIO_toggle =0;
uint8_t test_DIO_read =0;

uint8_t test_Interrupt_init =0;

uint8_t test_Timer_init =0;
uint8_t test_Timer_delay =0;


uint8_t test_LED_init =0;
uint8_t test_LED_on =0;
uint8_t test_LED_off =0;
uint8_t test_LED_toggle =0;

uint8_t test_BUTTON_init =0;
uint8_t test_BUTTON_read =0;

void test_DIO_driver(){
	
	// 1. Test DIO Init
	if (DIO_init(PORT_A,0,OUTPUT)==DIO_OK) // valid input
	{
		if (DIO_init('E',0,OUTPUT)==WRONG_DIO_PORT_NUMBER) //invalid port
		{
			if (DIO_init(PORT_A,9,OUTPUT)==WRONG_DIO_PIN_NUMBER) //invalid pin
			{
				if (DIO_init(PORT_A,0,2)==WRONG_DIO_DIRECTION) //invalid pin direction
				{
					test_DIO_init = 1;
				}
			}
		}
	}
	// 2. test DIO Write
	if (DIO_write(PORT_A,0,HIGH)==DIO_OK)// valid input
	{
		if (DIO_write('E',0,HIGH)==WRONG_DIO_PORT_NUMBER)//invalid port
		{
			if (DIO_write(PORT_A,9,HIGH)==WRONG_DIO_PIN_NUMBER)//invalid pin
			{
				if (DIO_write(PORT_A,0,5)==WRONG_DIO_PIN_VALUE)//invalid pin value
				{
					test_DIO_write =1;
				}
			}
		}
	}
	// 3. test DIO toggle
	if (DIO_toggle(PORT_A,0)==DIO_OK)// valid input
	{
		if (DIO_toggle('E',0)==WRONG_DIO_PORT_NUMBER)//invalid port
		{
			if (DIO_toggle(PORT_A,9)==WRONG_DIO_PIN_NUMBER)//invalid pin
			{
				test_DIO_toggle =1;
			}
		}
	}
	// 4. test DIO Read
	if (DIO_read(PORT_A,0,&x)==DIO_OK)// valid input
	{
		if (DIO_read('E',0,&x)==WRONG_DIO_PORT_NUMBER)//invalid port
		{
			if (DIO_read(PORT_A,9,&x)==WRONG_DIO_PIN_NUMBER)//invalid pin
			{
				test_DIO_toggle =1;
			}
		}
	}
}
void test_Interrupt_driver(){
	// 1. Test INT0_init
	if (INT0_init(ON_RISING_EDGE)==INTERRPUT_OK) // valid input
	{
		if (INT0_init(4)==WRONG_INTERRPUT_TRIGGER)//invalid trigger
		{
			test_Interrupt_init=1;
		}
	}
}
void test_Timers_driver(){
	//1. Test timer init
	if (TIMER_init(TIMER_0,NORMAL)==TIMER_OK) // valid input
	{
		if (TIMER_init(3,NORMAL)==WRONG_TIMER_NAME) //invalid timer name
		{
			if (TIMER_init(TIMER_0,5)==WRONG_TIMER_MODE) //invalid timer mode
			{
				test_Timer_init=1;
			}
		}
	}
	//2. Test timer delay
	if (delay(TIMER_0,1)==TIMER_OK) // valid input
	{
		if (delay(3,5)==WRONG_TIMER_NAME) //invalid timer name
		{
			test_Timer_delay=1;
		}
	}
}
void test_LED_driver(){
	// 1. Test LED_init
	if (LED_init(PORT_B,0)==LED_OK) // valid input
	{
		if (LED_init('E',0)==WRONG_LED_PORT_NUMBER) //invalid port
		{
			if (LED_init(PORT_A,9)==WRONG_LED_PIN_NUMBER) //invalid pin
			{
				test_LED_init = 1;
			}
		}
	}
	// 2. test LED_on
	if (LED_on(PORT_A,0)==LED_OK) // valid input
	{
		if (LED_on('E',0)==WRONG_LED_PORT_NUMBER) //invalid port
		{
			if (LED_on(PORT_A,9)==WRONG_LED_PIN_NUMBER) //invalid pin
			{
				test_LED_on = 1;
			}
		}
	}
	// 3. test LED_off
	if (LED_off(PORT_A,0)==LED_OK) // valid input
	{
		if (LED_off('E',0)==WRONG_LED_PORT_NUMBER) //invalid port
		{
			if (LED_off(PORT_A,9)==WRONG_LED_PIN_NUMBER) //invalid pin
			{
				test_LED_off = 1;
			}
		}
	}
	// 4. test LED_toggle
	if (LED_toggle(PORT_A,0)==LED_OK) // valid input
	{
		if (LED_toggle('E',0)==WRONG_LED_PORT_NUMBER) //invalid port
		{
			if (LED_toggle(PORT_A,9)==WRONG_LED_PIN_NUMBER) //invalid pin
			{
				test_LED_toggle = 1;
			}
		}
	}
}
void test_Button_driver(){
	// 1. Test BUTTON_init
	if (BUTTON_init(PORT_B,0)==BUTTON_OK) // valid input
	{
		if (BUTTON_init('E',0)==WRONG_BUTTON_PORT_NUMBER) //invalid port
		{
			if (BUTTON_init(PORT_A,9)==WRONG_BUTTON_PIN_NUMBER) //invalid pin
			{
				test_BUTTON_init = 1;
			}
		}
	}
	// 2. test BUTTON_read
	if (BUTTON_read(PORT_B,0,&x)==BUTTON_OK) // valid input
	{
		if (BUTTON_read('E',0,&x)==WRONG_BUTTON_PORT_NUMBER) //invalid port
		{
			if (BUTTON_read(PORT_A,9,&x)==WRONG_BUTTON_PIN_NUMBER) //invalid pin
			{
				test_BUTTON_read = 1;
			}
		}
	}
}