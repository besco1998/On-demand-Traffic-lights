/*
 * button.c
 *
 * Created: 9/5/2022 10:44:38 PM
 *  Author: Mohamed Ashraf Farouk
 */ 

#include "button.h"

//initialize button
EN_buttonError_t BUTTON_init(uint8_t buttonPort,uint8_t buttonPin){
	switch(DIO_init(buttonPort,buttonPin,INPUT)){
		case WRONG_DIO_PORT_NUMBER:
			return WRONG_BUTTON_PORT_NUMBER;
			break;
		case WRONG_DIO_PIN_NUMBER:
			return WRONG_BUTTON_PIN_NUMBER;
			break;
		case DIO_OK:
			return BUTTON_OK;
			break;
	}
}

//read button value
EN_buttonError_t BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t* value){
		switch(DIO_read(buttonPort,buttonPin,value)){
		case WRONG_DIO_PORT_NUMBER:
			return WRONG_BUTTON_PORT_NUMBER;
			break;
		case WRONG_DIO_PIN_NUMBER:
			return WRONG_BUTTON_PIN_NUMBER;
			break;
		case DIO_OK:
			return BUTTON_OK;
			break;
	}
}