/*
 * GI_programc.c
 *
 * Created: 2/25/2024 2:49:50 PM
 *  Author: ELWALIDEISSA
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "GI_interface.h"
#include "GI_register.h"




void GI_voidEnable(void)
{
	//ENABLE GI
	SET_BIT(SREG_REG,I);
}
void GI_voidDisable(void)
{
	//DISABLE GI
	CLEAR_BIT(SREG_REG,I);
}