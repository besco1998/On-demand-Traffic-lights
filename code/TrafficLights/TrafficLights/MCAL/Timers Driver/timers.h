/*
 * timers.h
 *
 * Created: 9/11/2022 12:46:06 AM
 *  Author: Mohamed Ashraf Farouk
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

// Includes
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_operations.h"

// Driver Definitions
 
// Define CPU Clock
#define F_CPU 1000000U //1MHz

// Define Timer formulas
#define PRESCALAR_1 1
#define PRESCALAR_8 8
#define PRESCALAR_64 64
#define PRESCALAR_256 256
#define PRESCALAR_1024 1024

#define T_TICK(PS,F) PS*1000.0/F
#define TIMER_MAX_DELAY(TT) TT*256;
#define N_OF(TD,TMD) TD/TMD;
#define T_I(TMD,TD,TT) ((TMD-TD)/TT)
#define T_I_OF(TD,TT,NOF) 256-((TD/TT)/NOF)

#define Counter_OnRisingEdge 0
#define Counter_OnFallingEdge 1

// Driver Typedefs
typedef enum EN_Timers
{
	TIMER_0,TIMER_1,TIMER_2
}EN_Timers_t;
typedef enum EN_timerModes
{
	NORMAL,CTC,PWM_FAST,PWM_PHASE_CORRECT,COUNTER
}EN_timerModes_t;
typedef enum EN_timerError
{
	TIMER_OK,WRONG_TIMER_NAME,WRONG_TIMER_MODE,WRONG_DELAY_VALUE
}EN_timerError_t;

// Driver Function Prototypes
EN_timerError_t TIMER_init(EN_Timers_t timer,EN_timerModes_t mode); // Initialize Timer to work in the selected mode
EN_timerError_t delay(EN_Timers_t timer,unsigned int value); // Calculate Timer parameters and enable/start timer to delay in milliseconds




#endif /* TIMERS_H_ */