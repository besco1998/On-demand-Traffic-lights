/*
 * button.h
 *
 * Created: 9/5/2022 10:44:49 PM
 *  Author: Mohamed Ashraf Farouk
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

// Includes
#include "../../MCAL/DIO Driver/dio.h"

// Driver typedefs
typedef enum EN_buttonError
{
	BUTTON_OK,WRONG_BUTTON_PORT_NUMBER,WRONG_BUTTON_PIN_NUMBER
}EN_buttonError_t;


// Driver Function Prototypes
EN_buttonError_t BUTTON_init(uint8_t buttonPort,uint8_t buttonPin); // Initialize button pin to be INPUT
EN_buttonError_t BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t* value); // Get status of the button

#endif /* BUTTON_H_ */