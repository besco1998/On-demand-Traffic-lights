/*
 * drivers_test.h
 *
 * Created: 9/13/2022 8:20:41 PM
 *  Author: compu zone
 */ 


#ifndef DRIVERS_TEST_H_
#define DRIVERS_TEST_H_

#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/Interrupts Driver/interrupts.h"
#include "../MCAL/Timers Driver/timers.h"
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"



void test_DIO_driver();
void test_Interrupt_driver();
void test_Timers_driver();
void test_LED_driver();
void test_Button_driver();



#endif /* DRIVERS_TEST_H_ */