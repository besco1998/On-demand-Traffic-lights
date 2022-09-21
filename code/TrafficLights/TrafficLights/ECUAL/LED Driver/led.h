/*
 * led.h
 *
 * Created: 9/5/2022 10:26:52 PM
 *  Author: Mohamed Ashraf Farouk
 */ 


#ifndef LED_H_
#define LED_H_
// Includes
#include "../../MCAL/DIO Driver/dio.h"

// Driver typedefs
typedef enum EN_ledError
{
	LED_OK,WRONG_LED_PORT_NUMBER,WRONG_LED_PIN_NUMBER
}EN_ledError_t;


// Driver Function Prototypes
EN_ledError_t LED_init(uint8_t ledPort,uint8_t ledPin); // Initialize the LED pin to be output
EN_ledError_t LED_on(uint8_t ledPort,uint8_t ledPin); // Write HIGH to LED pin
EN_ledError_t LED_off(uint8_t ledPort,uint8_t ledPin); // Write Low to LED pin
EN_ledError_t LED_toggle(uint8_t ledPort,uint8_t ledPin); // Toggle LED pin

#endif /* LED_H_ */