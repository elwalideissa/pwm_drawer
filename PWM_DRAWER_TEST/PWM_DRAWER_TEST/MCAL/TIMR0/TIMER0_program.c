/*
 * TIMER0_program.c
 *
 * Created: 2/25/2024 2:22:09 PM
 *  Author: ELWALIDEISSA
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "DIO_INTERFACE.h"

static void(*PER_pFunCallBackOVF)(void)= NULL;
static void(*PER_pFunCallBackCTC)(void)= NULL;

void TIMER0_voidInit(void)
{ 
	// Select Mode = Normal Mode
	CLEAR_BIT(TCCR0_REG,WGM00);
	CLEAR_BIT(TCCR0_REG,WGM01);
	
	// Enable OVF Interrupt
	SET_BIT(TIMSK_REG,TOIE0);
}
void TIMER0_voidStart(void)
{
	//SELECT PRESCALER =64
	SET_BIT(TCCR0_REG,CS00);
	SET_BIT(TCCR0_REG,CS01);
	CLEAR_BIT(TCCR0_REG,CS02);
}
void TIMER0_voidStop(void)
{
    CLEAR_BIT(TCCR0_REG,CS00);
    CLEAR_BIT(TCCR0_REG,CS01);
    CLEAR_BIT(TCCR0_REG,CS02);
}
void TIMER0_voidSetCallBackOVF(void(*copy_pFunAction)(void))
{
	if(copy_pFunAction != NULL)
	{ 
		PER_pFunCallBackOVF = copy_pFunAction;
		
	}
	else
	{
		//return error state
	}
}


void TIMER0_voidSetCallBackCTC(void(*copy_pFunAction)(void))
{
	if(copy_pFunAction != NULL)
	{
		PER_pFunCallBackCTC = copy_pFunAction;
		
	}
	else
	{
		//return error state
	}
}
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	static u16 local_u16OCTCcounter=0;
	local_u16OCTCcounter++;
	if(TIMER0_OUTPUT_COMPARE_COUNTER==local_u16OCTCcounter)
	{ 
		//CLEAR COUNTER
	       local_u16OCTCcounter=0;
		   if(PER_pFunCallBackCTC!=NULL)
		   {
			   PER_pFunCallBackCTC();
		   }
		   else
		   {
			   //return error state
		   }
	}
}
