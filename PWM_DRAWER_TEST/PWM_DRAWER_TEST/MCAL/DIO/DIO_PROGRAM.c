/*
 * DIO_PROGRAM.c
 *
 * Created: 2/4/2024 3:35:23 PM
 *  Author: ELWALIDEISSA
 */ 

#include<avr/io.h>
/*UTILES_LIB*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/*MCAL*/
#include"DIO_INTERFACE.h"
#include"DIO_register.h"

void DIO_voidSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinDirction)
{
	if((copy_u8PortId<4)&&(copy_u8PinId<8)&&(copy_u8PinDirction<2))
	{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		switch(copy_u8PinDirction)
		{
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRA_REG,copy_u8PinId);
			break;
			case DIO_PIN_INPUT:
			CLEAR_BIT(DDRA_REG,copy_u8PinId);
			break;
		}
		break;
		
		case DIO_PORTB:
		switch(copy_u8PinDirction)
		{
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRB_REG,copy_u8PinId);
			break;
			case DIO_PIN_INPUT:
			CLEAR_BIT(DDRB_REG,copy_u8PinId);
			break;
		}
		break;
		
		case DIO_PORTC:
		switch(copy_u8PinDirction)
		{
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRC_REG,copy_u8PinId);
			break;
			case DIO_PIN_INPUT:
			CLEAR_BIT(DDRC_REG,copy_u8PinId);
			break;
		}
		break;
		
		case DIO_PORTD:
		switch(copy_u8PinDirction)
		{
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRD_REG,copy_u8PinId);
			break;
			case DIO_PIN_INPUT:
			CLEAR_BIT(DDRD_REG,copy_u8PinId);
			break;
		}
		break;
	}
}
else
{
	//Do Nothing
	
}
	
}

void DIO_voidSetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue)
{
	
	if((copy_u8PortId<4)&&(copy_u8PinId<8)&&(copy_u8PinValue<2))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_HIGH:
				SET_BIT(PORTA_REG,copy_u8PinId);
				break;
				case DIO_PIN_LOW:
				CLEAR_BIT(PORTA_REG,copy_u8PinId);
				break;
			}
			break;
			case DIO_PORTB:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_HIGH:
				SET_BIT(PORTB_REG,copy_u8PinId);
				break;
				case DIO_PIN_LOW:
				CLEAR_BIT(PORTB_REG,copy_u8PinId);
				break;
			}
			break;
			case DIO_PORTC:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_HIGH:
				SET_BIT(PORTC_REG,copy_u8PinId);
				break;
				case DIO_PIN_LOW:
				CLEAR_BIT(PORTC_REG,copy_u8PinId);
				break;
			}
			break;
			case DIO_PORTD:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_HIGH:
				SET_BIT(PORTD_REG,copy_u8PinId);
				break;
				case DIO_PIN_LOW:
				CLEAR_BIT(PORTD_REG,copy_u8PinId);
				break;
			}
			break;
		}
	}
	else
	{
		//Do Nothing
		
	}
	
}

void DIO_voidGetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8* copy_pu8PinValue)
{
	if((copy_u8PortId<4)&&(copy_u8PinId<8)&&(copy_pu8PinValue!=NULL))
	{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		*copy_pu8PinValue =READ_BIT(PINA_REG,copy_u8PinId);
		break;
		case DIO_PORTB:
		*copy_pu8PinValue =READ_BIT(PINB_REG,copy_u8PinId);
		break;	
		case DIO_PORTC:
		*copy_pu8PinValue =READ_BIT(PINC_REG,copy_u8PinId);
		break;
		case DIO_PORTD:
		*copy_pu8PinValue =READ_BIT(PIND_REG,copy_u8PinId);
		break;
		
	}
	}
	else
	{
		//Do Nothing
		
	}
}
void DIO_voidTogglePinValue(u8 copy_u8PortId,u8 copy_u8PinId)
{
	if((copy_u8PortId<4)&&(copy_u8PinId<8))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			TOGGLE_BIT(PORTA_REG,copy_u8PinId);
			break;
			case DIO_PORTB:
			TOGGLE_BIT(PORTB_REG,copy_u8PinId);
			break;
			case DIO_PORTC:
			TOGGLE_BIT(PORTC_REG,copy_u8PinId);
			break;
			case DIO_PORTD:
			TOGGLE_BIT(PORTD_REG,copy_u8PinId);
			break;
		}
	}
	else
	{
		//Do Nothing
		
	}
}
void DIO_voidActivePinInPullUpResistans(u8 copy_u8PortId,u8 copy_u8PinId)
{
	if((copy_u8PortId<4)&&(copy_u8PinId<8))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			SET_BIT(PORTA_REG,copy_u8PinId);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB_REG,copy_u8PinId);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC_REG,copy_u8PinId);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD_REG,copy_u8PinId);
			break;
		}
	}
	else
	{
		//do nothing
	}
}
void DIO_voidSetPortDirection(u8 copy_u8PortId,u8 copy_u8PortDirction)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA :
		switch(copy_u8PortDirction)
		{
			case DIO_PORT_INPUT:
			DDRA_REG=DIO_PORT_INPUT;
			break;
			case DIO_PORT_OUTPUT:
			DDRA_REG=DIO_PORT_OUTPUT;
			break;
		}
		break;
		case DIO_PORTB :
		switch(copy_u8PortDirction)
		{
			case DIO_PORT_INPUT:
			DDRB_REG=DIO_PORT_INPUT;
			break;
			case DIO_PORT_OUTPUT:
			DDRB_REG=DIO_PORT_OUTPUT;
			break;
		}
		break;
		case DIO_PORTC :
		switch(copy_u8PortDirction)
		{
			case DIO_PORT_INPUT:
			DDRC_REG=DIO_PORT_INPUT;
			break;
			case DIO_PORT_OUTPUT:
			DDRC_REG=DIO_PORT_OUTPUT;
			break;
		}
		break;
		case DIO_PORTD :
		switch(copy_u8PortDirction)
		{
			case DIO_PORT_INPUT:
			DDRD_REG=DIO_PORT_INPUT;
			break;
			case DIO_PORT_OUTPUT:
			DDRD_REG=DIO_PORT_OUTPUT;
			break;
		}
		break;
		
	}
}

void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection);
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue);
void DIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue);
void DIO_voidTogglePortValue(u8 copy_u8PortId);
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId);