/*
 * bit_operations.h
 *
 * Created: 9/5/2022 10:09:37 PM
 *  Author: Mohamed Ashraf Farouk
 */ 


#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_

#define SET_BIT(X,BIT_NO) X|=(1<<BIT_NO) // Set bit Macro

#define CLR_BIT(X,BIT_NO) X&=~(1<<BIT_NO) // Clear bit Macro

#define READ_BIT(X,BIT_NO) ((X & (1<<BIT_NO))>>BIT_NO) // Read bit Macro

#define TOGGLE_BIT(X,BIT_NO) X^=(1<<BIT_NO) //Toggle bit Macro



#endif /* BIT_OPERATIONS_H_ */