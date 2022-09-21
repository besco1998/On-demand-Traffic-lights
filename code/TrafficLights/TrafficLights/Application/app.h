/*
 * app.h
 *
 * Created: 9/12/2022 4:54:31 AM
 *  Author: Mohamed Ashraf Farouk
 */ 


#ifndef APP_H_
#define APP_H_

// Includes
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Interrupts Driver/interrupts.h"
#include "../MCAL/Timers Driver/timers.h"

// Definitions
#define NUMBER_OF_CAR_LEDS 3
#define NUMBER_OF_PEDESTRIAN_LEDS 3

#define NORMAL_MODE 0
#define PEDESTRIAN_MODE 1

// Global Variables

// Functions Prototypes
void APP_init(void);
void APP_start(void);


#endif /* APP_H_ */