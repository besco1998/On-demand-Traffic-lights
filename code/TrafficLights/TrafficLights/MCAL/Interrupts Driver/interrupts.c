/*
 * interrupts.c
 *
 * Created: 9/10/2022 7:47:14 PM
 *  Author: Mohamed Ashraf Farouk
 */ 
#include "interrupts.h"
#include "../../Utilities/bit_operations.h"

EN_interruptError_t INT0_init(uint8_t value){
	
	/* 1. Enable Global interrupts - sit bit 7 in status reg to 1 */
	SET_GLOBAL_INT();
	/* 2. Choose the ext int sense */
	switch(value){
		case ON_LOW_LEVEL:
			break;
		case ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,0);
			break;	
		case ON_FALLING_EDGE:
			SET_BIT(MCUCR,1);
			break;		
		case ON_RISING_EDGE:
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
		default:
			return WRONG_INTERRPUT_TRIGGER;
	}
	/* 3. Enable ext int 0 - INT0 */
	SET_BIT(GICR,6);
	return INTERRPUT_OK;
}

