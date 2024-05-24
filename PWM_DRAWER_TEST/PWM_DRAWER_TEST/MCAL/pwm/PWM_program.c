/*
 * PWM_program.c
 *
 * Created: 3/1/2024 7:51:06 PM
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "PWM_interface.h"
#include "PWM_register.h"



void PWM_voidInitChannel_1A(void)
{
	// Select Mode = Fast PWM Mode(14)
	CLEAR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1B_REG,WGM13);
	
	// Select Non Inverting Mode
	CLEAR_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);
}


void PWM_voidGenerate_PWM_Channel_1A(u16 copy_u16Frequency_hz,f32 copy_f32DutyCycle)
{
	if(copy_f32DutyCycle<=100)
	{
		// under condition tick time 4 MS by setting prescaller 64
		ICR1_u16_REG = ((1000000UL/copy_u16Frequency_hz)/4)-1;
		
		// under condition non inverting fast PWM
		OCR1A_u16_REG = ((copy_f32DutyCycle*(ICR1_u16_REG+1))/100)-1;
		
		// Select Prescaler Value = 64
		SET_BIT(TCCR1B_REG,CS10);
		SET_BIT(TCCR1B_REG,CS11);
		CLEAR_BIT(TCCR1B_REG,CS12);
	}
	else
	{
		// return Error state
	}
}

void PWM_void_CALC_Duty (u32* copy_pu32DutyCycle,u32 copy_pu32onTicks,u32 copy_pu32onCounter,u32 copy_pu32totalTicks,u32 copy_pu32totalCounter)
{
	if( copy_pu32DutyCycle!= NULL)
	{
		*copy_pu32DutyCycle = (copy_pu32onTicks + (copy_pu32onCounter * 256)) * 100 / (copy_pu32totalTicks + (copy_pu32totalCounter * 256));
	}
	else
	{
		//return any error state
	}
}

void PWM_void_calc_freq(u32* copy_pu32Frequency ,u32 copy_pu32totalTicks,u32 copy_pu32totalCounter)
{
	if(  copy_pu32Frequency!= NULL)
	{
		*copy_pu32Frequency = 1000000UL / ((copy_pu32totalTicks + (copy_pu32totalCounter * 256)  ) * 4);
	}
	else
	{
		//return any error state
	}
}