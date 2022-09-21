/*
 * dio.c
 *
 * Created: 9/5/2022 9:21:09 PM
 *  Author: Mohamed Ashraf Farouk
 */ 


//Including
#include "dio.h"


// all global Variables

// all function implementation

EN_dioError_t DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction)
{
	if (pinNumber<0 || pinNumber>7 )
	{
		return WRONG_DIO_PIN_NUMBER;
	}
	switch (portNumber)
	{
	case PORT_A :
		if (direction == INPUT)
		{
			CLR_BIT(DDRA,pinNumber);
		}
		else if (direction == OUTPUT)
		{
			SET_BIT(DDRA,pinNumber);
		}
		else{
			return WRONG_DIO_DIRECTION;
		}
		break;
	case PORT_B :
		if (direction == INPUT)
		{
			CLR_BIT(DDRB,pinNumber);
		}
		else if (direction == OUTPUT)
		{
			SET_BIT(DDRB,pinNumber);
		}
		else{
			return WRONG_DIO_DIRECTION;
		}
		break;
	case PORT_C :
		if (direction == INPUT)
		{
			CLR_BIT(DDRC,pinNumber);
		}
		else if (direction == OUTPUT)
		{
			SET_BIT(DDRC,pinNumber);
		}
		else{
			return WRONG_DIO_DIRECTION;
		}
		break;	
	case PORT_D :
		if (direction == INPUT)
		{
			CLR_BIT(DDRD,pinNumber);
		}
		else if (direction == OUTPUT)
		{
			SET_BIT(DDRD,pinNumber);
		}
		else{
			return WRONG_DIO_DIRECTION;
		}
		break;
	default:
		return WRONG_DIO_PORT_NUMBER;
	}
	return DIO_OK;
}
EN_dioError_t DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value)
{
	if (pinNumber<0 || pinNumber>7 )
	{
		return WRONG_DIO_PIN_NUMBER;
	}
	switch (portNumber)
	{
	case PORT_A :
		if (value == LOW)
		{
			CLR_BIT(PORTA,pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTA,pinNumber);
		}
		else{
			return WRONG_DIO_PIN_VALUE;
		}
		return DIO_OK;
		break;
	case PORT_B :
		if (value == LOW)
		{
			CLR_BIT(PORTB,pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTB,pinNumber);
		}
		else{
			return WRONG_DIO_PIN_VALUE;
		}
		return DIO_OK;
		break;
	case PORT_C :
		if (value == LOW)
		{
			CLR_BIT(PORTC,pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTC,pinNumber);
		}
		else{
			return WRONG_DIO_PIN_VALUE;
		}
		return DIO_OK;
		break;
	case PORT_D :
		if (value == LOW)
		{
			CLR_BIT(PORTD,pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTD,pinNumber);
		}
		else{
			return WRONG_DIO_PIN_VALUE;
		}
		return DIO_OK;
		break;
	default:
		return WRONG_DIO_PORT_NUMBER;		
	}
}
EN_dioError_t DIO_toggle(uint8_t portNumber,uint8_t pinNumber)
{
	if (pinNumber<0 || pinNumber>7 )
	{
		return WRONG_DIO_PIN_NUMBER;
	}
	switch (portNumber)
	{
		case PORT_A :
			TOGGLE_BIT(PORTA,pinNumber);
			break;
		case PORT_B :
			TOGGLE_BIT(PORTB,pinNumber);
			break;
		case PORT_C :
			TOGGLE_BIT(PORTC,pinNumber);
			break;
		case PORT_D :
			TOGGLE_BIT(PORTD,pinNumber);
			break;
		default:
		return WRONG_DIO_PORT_NUMBER;
	}
	return DIO_OK;
}
EN_dioError_t DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t* value)
{
	if (pinNumber<0 || pinNumber>7 )
	{
		return WRONG_DIO_PIN_NUMBER;
	}
	switch (portNumber)
	{
		case PORT_A :
			*value= READ_BIT(PINA,pinNumber);
			break;
		case PORT_B :
			*value=READ_BIT(PINB,pinNumber);
			break;
		case PORT_C :
			*value=READ_BIT(PINC,pinNumber);
			break;
		case PORT_D :
			*value=READ_BIT(PIND,pinNumber);
			break;
		default:
			return WRONG_DIO_PORT_NUMBER;
	}
	return DIO_OK;
}