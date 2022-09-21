/*
 * app.c
 *
 * Created: 9/12/2022 4:54:40 AM
 *  Author: compu zone
 */ 

// Includes
#include "app.h"

// Global Variables
uint8_t carsLedNumber =0 ;
uint8_t pedestrianLedNumber =0 ;
uint8_t nextLight=0;
uint8_t mode =0;

void APP_init(void){
	/* 1. Set direction for button pin to input */
	BUTTON_init(PORT_D,2); /* pin 2 port D */
	
	/* 2. Set all led pins to output */
	LED_init(PORT_A,0); /* pin 0 port A */
	LED_init(PORT_A,1); /* pin 3 port A */
	LED_init(PORT_A,2); /* pin 7 port A */
	
	LED_init(PORT_B,0); /* pin 0 port A */
	LED_init(PORT_B,1); /* pin 3 port A */
	LED_init(PORT_B,2); /* pin 7 port A */
	
	/* 3. Initialize INT0 */
	INT0_init(ON_FALLING_EDGE);
	
	/* 4. Initialize INT0 */
	TIMER_init(TIMER_0,NORMAL);
	
	/* 4. Pedestrian red lights on */
	LED_on(PORT_B,0);
}
void APP_start(void){
	while (1)
	{
		switch(mode){
			case NORMAL_MODE:
			/* RED LIGHT */
			if (nextLight == 0)
			{
				carsLedNumber =0 ;
				nextLight=1;
				LED_on(PORT_A,0);
				delay(TIMER_0,5000);
				LED_off(PORT_A,0);
				break;
			}
			/* Yellow LIGHT */
			else if (nextLight == 1)
			{
				if (carsLedNumber==2)
				{
					nextLight = 0 ;
				}
				else if (carsLedNumber ==0)
				{
					nextLight =2 ;
				}
				carsLedNumber=1;
				for (int i=0 ; i<20;i++)
				{
					LED_toggle(PORT_A,1);
					delay(TIMER_0,500);
				}
				
				break;
			}
			/* Green LIGHT */
			else if (nextLight ==2)
			{
				carsLedNumber =2 ;
				nextLight =1;
				LED_on(PORT_A,2);
				delay(TIMER_0,5000);
				LED_off(PORT_A,2);
				break;
			}

			
			case PEDESTRIAN_MODE:
			
			if (carsLedNumber== 0) // if cars red lights on
			{
				LED_on(PORT_A,0); // cars red lights on
				LED_off(PORT_B,0);// pedestrian red lights off
				LED_on(PORT_B,2); // pedestrian green lights on
				delay(TIMER_0,5000); // wait 5 seconds
			}
			else if (carsLedNumber == 1 || carsLedNumber == 2 )  // if cars green or yellow lights on
			{
				LED_on(PORT_B,0); // pedestrian red lights on
				// Blinking both yellow lights
				for (int i=0 ; i<20;i++)
				{
					LED_toggle(PORT_A,1);
					LED_toggle(PORT_B,1);
					delay(TIMER_0,500);
				}
				LED_off(PORT_B,0); // pedestrian red lights off
				
				LED_on(PORT_B,2); // pedestrian green lights on
				LED_on(PORT_A,0); // cars red lights on
				delay(TIMER_0,5000); // wait 5 seconds
			}
			
			LED_off(PORT_A,0); // cars red lights off
			// Blinking both yellow lights
			for (int i=0 ; i<20;i++)
			{
				LED_toggle(PORT_A,1);
				LED_toggle(PORT_B,1);
				delay(TIMER_0,500);
			}
			LED_off(PORT_B,2); //pedestrian green lights off
			LED_on(PORT_B,0); // pedestrian red lights on
			LED_on(PORT_A,2); // cars green lights on
			//carsLedNumber =2;
			nextLight =2;
			mode=NORMAL_MODE;
			break;
			
			
		} //switch case
	} // while loop
}

ISR(EXT_INT_0){
	mode=PEDESTRIAN_MODE;
}