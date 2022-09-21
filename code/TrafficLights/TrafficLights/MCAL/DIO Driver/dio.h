/*
 * dio.h
 *
 * Created: 9/5/2022 9:21:36 PM
 *  Author: Mohamed Ashraf Farouk
 */ 


#ifndef DIO_H_
#define DIO_H_

// Includes
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_operations.h"

// Driver typedefs
typedef enum EN_dioError
{
	DIO_OK=0,WRONG_DIO_PORT_NUMBER=1,WRONG_DIO_PIN_NUMBER=2,WRONG_DIO_DIRECTION=3,WRONG_DIO_PIN_VALUE=4
}EN_dioError_t;

// Driver Macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

// Driver Function Prototypes
EN_dioError_t DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction); //initialize direction of pins
EN_dioError_t DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value); //write data to DIO pin
EN_dioError_t DIO_toggle(uint8_t portNumber,uint8_t pinNumber); // toggle a DIO Pin
EN_dioError_t DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t* value); //read DIO Data


#endif /* DIO_H_ */