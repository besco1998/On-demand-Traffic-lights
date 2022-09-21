/*
 * interrupts.h
 *
 * Created: 9/10/2022 6:40:44 PM
 *  Author: Mohamed Ashraf Farouk
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_operations.h"

/* External Interrupt request 0 */
#define EXT_INT_0 __vector_1
/* External Interrupt request 1 */
#define EXT_INT_1 __vector_2
/* External Interrupt request 2 */
#define EXT_INT_2 __vector_3

#define ON_LOW_LEVEL 0
#define ANY_LOGICAL_CHANGE 1
#define ON_FALLING_EDGE 2
#define ON_RISING_EDGE 3

#define SET_GLOBAL_INT()  __asm__ __volatile__ ("sei" ::: "memory")
#define CLEAR_GLOBAL_INT()  __asm__ __volatile__ ("cli" ::: "memory")

#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)

// Driver typedefs
typedef enum EN_interruptError
{
	INTERRPUT_OK,WRONG_INTERRPUT_TRIGGER
}EN_interruptError_t;

EN_interruptError_t INT0_init(uint8_t value); // Initialize INTERRUPT 0 




#endif /* INTERRUPTS_H_ */