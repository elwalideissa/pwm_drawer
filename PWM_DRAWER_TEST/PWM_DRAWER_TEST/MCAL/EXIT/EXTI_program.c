/*
 * EXTI_program.c
 *
 * Created: 2/18/2024 6:25:42 PM
 *  Author: ElwalidEissa
 */ 
/*UTILES_LIB*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/*MCAL*/
#include"EXTI_interface.h"
#include"EXTI_register.h"
/////////////////////////////////////////////////

void EXTI_voidEnable (u8 copy_u8InterruptSource,u8 copy_u8TriggerEdge)
{
	switch(copy_u8InterruptSource)
	{
		case EXTI_INT0:
		switch(copy_u8TriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
			
			case EXTI_FALLING_EDGE:
			CLEAR_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR_REG,ISC00);
			CLEAR_BIT(MCUCR_REG,ISC01);
			break;
			
			case EXTI_LOW_LEVE:
			CLEAR_BIT(MCUCR_REG,ISC00);
			CLEAR_BIT(MCUCR_REG,ISC01);
			break;
		}
		//Enable EXTI_0
		SET_BIT(GICR_REG,INT0);
		break;
	}
	




}
void EXTI_voidDisable(u8 copy_u8InterruptSource)
{
	switch(copy_u8InterruptSource)
	{
		case EXTI_INT0:
		CLEAR_BIT(GICR_REG,INT0);
		break;
		case EXTI_INT1:
		CLEAR_BIT(GICR_REG,INT1);
		break;
		case EXTI_INT2:
		CLEAR_BIT(GICR_REG,INT2);
		break;
	}
}