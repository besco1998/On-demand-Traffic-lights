/*
 * Led.c
 *
 * Created: 9/5/2022 10:27:05 PM
 *  Author: Mohamed Ashraf Farouk
 */ 

#include "led.h"


EN_ledError_t LED_init(uint8_t ledPort,uint8_t ledPin){
	switch(DIO_init(ledPort,ledPin,OUTPUT)){
		case WRONG_DIO_PORT_NUMBER:
			return WRONG_LED_PORT_NUMBER;
			break;
		case WRONG_DIO_PIN_NUMBER:
			return WRONG_LED_PIN_NUMBER;
			break;
		case DIO_OK:
			return LED_OK;
			break;
	}
}

EN_ledError_t LED_on(uint8_t ledPort,uint8_t ledPin){
	switch(DIO_write(ledPort,ledPin,HIGH)){
		case WRONG_DIO_PORT_NUMBER:
			return WRONG_LED_PORT_NUMBER;
			break;
		case WRONG_DIO_PIN_NUMBER:
			return WRONG_LED_PIN_NUMBER;
			break;
		case DIO_OK:
			return LED_OK;
			break;
	}
}


EN_ledError_t LED_off(uint8_t ledPort,uint8_t ledPin){
	switch(DIO_write(ledPort,ledPin,LOW)){
		case WRONG_DIO_PORT_NUMBER:
			return WRONG_LED_PORT_NUMBER;
			break;
		case WRONG_DIO_PIN_NUMBER:
			return WRONG_LED_PIN_NUMBER;
			break;
		case DIO_OK:
			return LED_OK;
			break;
	}
}


EN_ledError_t LED_toggle(uint8_t ledPort,uint8_t ledPin){
	switch(DIO_toggle(ledPort,ledPin)){
		case WRONG_DIO_PORT_NUMBER:
			return WRONG_LED_PORT_NUMBER;
			break;
		case WRONG_DIO_PIN_NUMBER:
			return WRONG_LED_PIN_NUMBER;
			break;
		case DIO_OK:
			return LED_OK;
			break;
	}
	
}

