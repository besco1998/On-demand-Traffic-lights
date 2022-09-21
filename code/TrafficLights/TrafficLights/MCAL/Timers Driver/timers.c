/*
 * timers.c
 *
 * Created: 9/11/2022 12:45:52 AM
 *  Author: Mohamed Ashraf Farouk
 */ 
#include "timers.h"

// Global variables 
float T_tick=0.0;
float T8_max_delay = 0.0;
unsigned int NUMBER_OF_OVERFLOWS =0;
unsigned int overflowCounter=0;
unsigned int T_delay=0;


EN_timerError_t TIMER_init(EN_Timers_t timer,EN_timerModes_t mode){
		switch (timer){
			case TIMER_0:
				// 1. choose Timer Mode
				if (mode == NORMAL)
				{
					CLR_BIT(TCCR0,6);
					CLR_BIT(TCCR0,3);
				}
				else if (mode == CTC)
				{
					CLR_BIT(TCCR0,6);
					SET_BIT(TCCR0,3);
				}
				else if (mode == PWM_FAST)
				{
					SET_BIT(TCCR0,6);
					SET_BIT(TCCR0,3);
				}
				else if (mode == PWM_PHASE_CORRECT)
				{
					SET_BIT(TCCR0,6);
					CLR_BIT(TCCR0,3);
				}
				else{
					return WRONG_TIMER_MODE;
				}
				// 2. Set Timer initial Value
				TCNT0=0x00;
				break;
				
			case TIMER_2:
				// 1. choose Timer Mode
				if (mode == NORMAL)
				{
					CLR_BIT(TCCR2,6);
					CLR_BIT(TCCR2,3);
				}
				else if (mode == CTC)
				{
					CLR_BIT(TCCR2,6);
					SET_BIT(TCCR2,3);
				}
				else if (mode == PWM_FAST)
				{
					SET_BIT(TCCR2,6);
					SET_BIT(TCCR2,3);
				}
				else if (mode == PWM_PHASE_CORRECT)
				{
					SET_BIT(TCCR2,6);
					CLR_BIT(TCCR2,3);
				}
				else{
					return WRONG_TIMER_MODE;
				}				
				// 2. Set Timer initial Value
				TCNT2=0x00;
			
			case TIMER_1:
				//...Timer1 initialization
				return TIMER_OK ;
				break;
			default:
				return WRONG_TIMER_NAME;
		}// Switch
}

EN_timerError_t delay(EN_Timers_t timer,unsigned int value){
	T_delay=value;
	if (value<0 || value > 4294967295)
	{
		return WRONG_DELAY_VALUE;
	}	
	T_tick=T_TICK(PRESCALAR_1,F_CPU);
	T8_max_delay = TIMER_MAX_DELAY(T_tick);
	
	switch(timer){
		case TIMER_0:
			if (T_delay<T8_max_delay)					// Delay < Max Delay
			{
				// Set initial value
				TCNT0=T_I(T8_max_delay,T_delay,T_tick);
				// Timer Start -> set a prescaler
				TCCR0 |= (1<<0); //No prescaler
				// Wait for the overflow flag is set
				while((TIFR & (1<<0))==0);
				// Clear the overflow
				TIFR |= (1<<0);
				// Stop the timer
				TCCR0 = 0x00;
				return TIMER_OK;
			}
			else if (T_delay == T8_max_delay)			// Delay = Max Delay
			{
				// Set initial value
				TCNT0=0x00;
				// Timer Start -> set a prescaler
				TCCR0 |= (1<<0); //No prescaler
				// Wait for the overflow flag is set
				while((TIFR & (1<<0))==0);
				// Clear the overflow
				TIFR |= (1<<0);
				// Stop the timer
				TCCR0 = 0x00;
				return TIMER_OK;
			}
			else										// Delay > Max Delay
			{
				NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
				// Setting Automatic Prescalar
				if (NUMBER_OF_OVERFLOWS>=8 && NUMBER_OF_OVERFLOWS<64 )
				{
					// Recalculate Timer parameters with new Prescalar
					T_tick=T_TICK(PRESCALAR_8,F_CPU);
					T8_max_delay = TIMER_MAX_DELAY(T_tick);
					NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
					// Set initial value
					TCNT0=T_I_OF(T_delay,T_tick,NUMBER_OF_OVERFLOWS);
					// Timer Start -> set a prescaler
					TCCR0 |= (1<<1); // Prescaler = 8
					// Wait for the Delay
					while(overflowCounter<NUMBER_OF_OVERFLOWS){
						// Wait for the overflow flag is set
						while((TIFR & (1<<0))==0);
						// Clear the overflow
						TIFR |= (1<<0);
						overflowCounter++;
					}
					
					// Reset Overflow Counter
					overflowCounter =0;
					// Stop the timer
					TCCR0 = 0x00;
					return TIMER_OK;
					
				}
				else if (NUMBER_OF_OVERFLOWS>=64 && NUMBER_OF_OVERFLOWS<256)
				{
					// Recalculate Timer parameters with new Prescalar
					T_tick=T_TICK(PRESCALAR_64,F_CPU);
					T8_max_delay = TIMER_MAX_DELAY(T_tick);
					NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
					// Set initial value
					TCNT0=T_I_OF(T_delay,T_tick,NUMBER_OF_OVERFLOWS);
					// Timer Start -> set a prescaler
					TCCR0 |= (0x03<<0); // Prescaler = 64
					// Wait for the Delay
					while(overflowCounter<NUMBER_OF_OVERFLOWS){
						// Wait for the overflow flag is set
						while((TIFR & (1<<0))==0);
						// Clear the overflow
						TIFR |= (1<<0);
						overflowCounter++;
					}
					
					// Reset Overflow Counter
					overflowCounter =0;
					// Stop the timer
					TCCR0 = 0x00;
					return TIMER_OK;
				}
				else if (NUMBER_OF_OVERFLOWS>=256 && NUMBER_OF_OVERFLOWS<1024)
				{
					// Recalculate Timer parameters with new Prescalar
					T_tick=T_TICK(PRESCALAR_256,F_CPU);
					T8_max_delay = TIMER_MAX_DELAY(T_tick);
					NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
					// Set initial value
					TCNT0=T_I_OF(T_delay,T_tick,NUMBER_OF_OVERFLOWS);
					// Timer Start -> set a prescaler
					TCCR0 |= (1<<2); // Prescaler = 256
					// Wait for the Delay
					while(overflowCounter<NUMBER_OF_OVERFLOWS){
						// Wait for the overflow flag is set
						while((TIFR & (1<<0))==0);
						// Clear the overflow
						TIFR |= (1<<0);
						overflowCounter++;
					}
					
					// Reset Overflow Counter
					overflowCounter =0;
					// Stop the timer
					TCCR0 = 0x00;
					return TIMER_OK;
				}
				else if (NUMBER_OF_OVERFLOWS>=1024)
				{
					// Recalculate Timer parameters with new Prescalar
					T_tick=T_TICK(PRESCALAR_1024,F_CPU);
					T8_max_delay = TIMER_MAX_DELAY(T_tick);
					NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
					// Set initial value
					TCNT0=T_I_OF(T_delay,T_tick,NUMBER_OF_OVERFLOWS);
					// Timer Start -> set a prescaler
					TCCR0 |= (0x05<<0); // Prescaler = 1024
					// Wait for the Delay
					while(overflowCounter<NUMBER_OF_OVERFLOWS){
						// Wait for the overflow flag is set
						while((TIFR & (1<<0))==0);
						// Clear the overflow
						TIFR |= (1<<0);
						overflowCounter++;
					}
					
					// Reset Overflow Counter
					overflowCounter =0;
					// Stop the timer
					TCCR0 = 0x00;
					return TIMER_OK;
				}
			}
			break;
		case TIMER_2:
			if (T_delay<T8_max_delay)					// Delay < Max Delay
			{
				// Set initial value
				TCNT2=T_I(T8_max_delay,T_delay,T_tick);
				// Timer Start -> set a prescaler
				TCCR2 |= (1<<0); //No prescaler
				// Wait for the overflow flag is set
				while((TIFR & (1<<6))==0);
				// Clear the overflow
				TIFR |= (1<<6);
				// Stop the timer
				TCCR2 = 0x00;
				return TIMER_OK;
			}
			else if (T_delay == T8_max_delay)			// Delay = Max Delay
			{
				// Set initial value
				TCNT2=0x00;
				// Timer Start -> set a prescaler
				TCCR2 |= (1<<0); //No prescaler
				// Wait for the overflow flag is set
				while((TIFR & (1<<6))==0);
				// Clear the overflow
				TIFR |= (1<<6);
				// Stop the timer
				TCCR2 = 0x00;
				return TIMER_OK;
			}
			else										// Delay > Max Delay
			{
				NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
				// Setting Automatic Prescalar
				if (NUMBER_OF_OVERFLOWS>=8 )
				{
					// Recalculate Timer parameters with new Prescalar
					T_tick=T_TICK(PRESCALAR_8,F_CPU);
					T8_max_delay = TIMER_MAX_DELAY(T_tick);
					NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
					// Set initial value
					TCNT2=T_I_OF(T_delay,T_tick,NUMBER_OF_OVERFLOWS);
					// Timer Start -> set a prescaler
					TCCR2 |= (1<<1); // Prescaler = 8
					// Wait for the Delay
					while(overflowCounter<NUMBER_OF_OVERFLOWS){
						// Wait for the overflow flag is set
						while((TIFR & (1<<6))==0);
						// Clear the overflow
						TIFR |= (1<<6);
						overflowCounter++;
					}
					
					// Reset Overflow Counter
					overflowCounter =0;
					// Stop the timer
					TCCR2 = 0x00;
					return TIMER_OK;
					
				}
				else if (NUMBER_OF_OVERFLOWS>=64)
				{
					// Recalculate Timer parameters with new Prescalar
					T_tick=T_TICK(PRESCALAR_64,F_CPU);
					T8_max_delay = TIMER_MAX_DELAY(T_tick);
					NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
					// Set initial value
					TCNT2=T_I_OF(T_delay,T_tick,NUMBER_OF_OVERFLOWS);
					// Timer Start -> set a prescaler
					TCCR2 |= (3<<0); // Prescaler = 64
					// Wait for the Delay
					while(overflowCounter<NUMBER_OF_OVERFLOWS){
						// Wait for the overflow flag is set
						while((TIFR & (1<<6))==0);
						// Clear the overflow
						TIFR |= (1<<6);
						overflowCounter++;
					}
					
					// Reset Overflow Counter
					overflowCounter =0;
					// Stop the timer
					TCCR2 = 0x00;
					return TIMER_OK;
				}
				else if (NUMBER_OF_OVERFLOWS>=256)
				{
					// Recalculate Timer parameters with new Prescalar
					T_tick=T_TICK(PRESCALAR_256,F_CPU);
					T8_max_delay = TIMER_MAX_DELAY(T_tick);
					NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
					// Set initial value
					TCNT2=T_I_OF(T_delay,T_tick,NUMBER_OF_OVERFLOWS);
					// Timer Start -> set a prescaler
					TCCR2 |= (1<<2); // Prescaler = 256
					// Wait for the Delay
					while(overflowCounter<NUMBER_OF_OVERFLOWS){
						// Wait for the overflow flag is set
						while((TIFR & (1<<6))==0);
						// Clear the overflow
						TIFR |= (1<<6);
						overflowCounter++;
					}
					
					// Reset Overflow Counter
					overflowCounter =0;
					// Stop the timer
					TCCR2 = 0x00;
					return TIMER_OK;
				}
				else if (NUMBER_OF_OVERFLOWS>=1024)
				{
					// Recalculate Timer parameters with new Prescalar
					T_tick=T_TICK(PRESCALAR_8,F_CPU);
					T8_max_delay = TIMER_MAX_DELAY(T_tick);
					NUMBER_OF_OVERFLOWS = N_OF(T_delay,T8_max_delay);
					// Set initial value
					TCNT2=T_I_OF(T_delay,T_tick,NUMBER_OF_OVERFLOWS);
					// Timer Start -> set a prescaler
					TCCR2 |= (5<<0); // Prescaler = 1024
					// Wait for the Delay
					while(overflowCounter<NUMBER_OF_OVERFLOWS){
						// Wait for the overflow flag is set
						while((TIFR & (1<<6))==0);
						// Clear the overflow
						TIFR |= (1<<6);
						overflowCounter++;
					}
					
					// Reset Overflow Counter
					overflowCounter =0;
					// Stop the timer
					TCCR2 = 0x00;
					return TIMER_OK;
				}
			}
			break;
		case TIMER_1:
			//..code for Timer 1
			return TIMER_OK;
			break;
		default:
			return WRONG_TIMER_NAME;
			
	}
}
