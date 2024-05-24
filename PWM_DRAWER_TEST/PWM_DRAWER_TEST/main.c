/*
 * PWM_DRAWER_TEST.c
 *
 * Created: 5/1/2024 12:32:38 AM
 * Author : ELWALID EISSA
 */ 


#define F_CPU 16000000UL
#include<util/delay.h>


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"
#include "TIMER0_interface.h"
#include "TIMER0_register.h"
#include "PWM_interface.h"


/* HAL */
#include "LCD_interface.h"
#include "SWITCH_interface.h"

u32 OVFcounter,onticks,oncounter,totalticks,totalcounter,state;

int main() {
	u32 local_u32Dutycycle,local_u32freyuency;
	u8 local_u8SWs0tate,local_u8SWs1tate,local_u8SWs2tate;
	u8 local_first=1;
	
	LCD_voidInit();
	GI_voidEnable();
	TIMER0_voidInit();
	PWM_voidInitChannel_1A();
	
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	
    SWITCH_voidInit(DIO_PORTC,DIO_PIN0);
    SWITCH_voidInit(DIO_PORTC,DIO_PIN1);
    SWITCH_voidInit(DIO_PORTC,DIO_PIN2);
	
	EXTI_voidEnable(EXTI_INT0,EXTI_RISING_EDGE);
	TIMER0_voidStart();
	
	while (1) 
  {
	  
	  SWITCH_voidGetState(DIO_PORTC,DIO_PIN0,SWITCH_FORWARD_CONNECTION,&local_u8SWs0tate);
	  SWITCH_voidGetState(DIO_PORTC,DIO_PIN1,SWITCH_FORWARD_CONNECTION,&local_u8SWs1tate);
	  SWITCH_voidGetState(DIO_PORTC,DIO_PIN2,SWITCH_FORWARD_CONNECTION,&local_u8SWs2tate);
	  if(local_u8SWs0tate==SWITCH_PRESSED)
	  {
		  
		  PWM_voidGenerate_PWM_Channel_1A(25,25);

	  }
	  if (local_u8SWs1tate == SWITCH_PRESSED)
	  {
		 PWM_voidGenerate_PWM_Channel_1A(35,50);
		  
	  }
	  
	  if(local_u8SWs2tate == SWITCH_PRESSED)
	  {
		  PWM_voidGenerate_PWM_Channel_1A(45,75);
		 
	  }
	  if(local_u8SWs0tate != SWITCH_PRESSED && local_u8SWs1tate != SWITCH_PRESSED && local_u8SWs2tate != SWITCH_PRESSED)
	  {
		  PWM_voidGenerate_PWM_Channel_1A(55,95);
		  
	  }
	   if(state==3)
		{
			EXTI_voidEnable(EXTI_INT0,EXTI_RISING_EDGE);
			state=0;
			OVFcounter=0;
		   PWM_void_CALC_Duty(&local_u32Dutycycle,onticks,oncounter,totalticks,totalcounter);
		   PWM_void_calc_freq(&local_u32freyuency,totalticks,totalcounter);
		  if(local_first)
		  {
			  local_first = 0;
		  }
		  else
		  {
			  LCD_void_calc(local_u32freyuency,local_u32Dutycycle);
			  LCD_void_display(local_u32Dutycycle);
			  _delay_ms(250);
			  LCD_voidClear();
		  }
	   
	 
	 	
    }
}

}


//ISR FOR TIMER0 OVF
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	OVFcounter++;
}
// ISR FOR INT0
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	
	if(state==0)
	{ 
		TCNT0_REG=0;
	    OVFcounter=0;
	    EXTI_voidEnable(EXTI_INT0,EXTI_FALLING_EDGE);
	    state++;
		
	}else if(state==1)
	{
		onticks=TCNT0_REG;
	    oncounter= OVFcounter;
	    EXTI_voidEnable(EXTI_INT0,EXTI_RISING_EDGE);
	    state++;
		
	}else if(state==2)
	{
		totalticks=TCNT0_REG;
	    totalcounter=OVFcounter;
	    state++;
		
	}
}

			
			
		
		
