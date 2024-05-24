/*
 * LCD_program.c
 *
 * Created: 2/9/2024 10:51:17 PM
 *  Author: ELWALID EISSA
 */ 


#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"





void LCD_voidInit(void)
{
	// Intialize LCD pins As OutPut Pins
	DIO_voidSetPinDirection(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_OUTPUT);
	
	
	_delay_ms(40);
	
	// Function Set command 
	// set Rs pin = 0 (command)
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	
	// set RW pin = 0 (write)
	DIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	
	PRV_voidWriteHalfPort(0b0010);
	
	/* Enable Pulse *//* H => L */
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);

	
	LCD_voidSendCommand(0b00101000);
    _delay_us(45);
	
	// Display on off Control (DisplayOn, Cursor on, Blink on)
	LCD_voidSendCommand(0b00001100);
	_delay_us(45);
	
	// Clear Display
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
	
	// Set Entry Mode (Increment on, Shift off)
	LCD_voidSendCommand(0b00000110);
}


void LCD_voidSendCommand(u8 copy_u8Cmnd)
{
	// set Rs pin = 0 (command)
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	
	// set RW pin = 0 (write)
	DIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	
	// Write The Most 4 bits Of command on Data Pins
	PRV_voidWriteHalfPort(copy_u8Cmnd>>4);
	
	/* Enable Pulse *//* H => L */
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);
	
	// Write The Least 4 bits Of command on Data Pins
	PRV_voidWriteHalfPort(copy_u8Cmnd);
	
	/* Enable Pulse *//* H => L */
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);
}


void LCD_voidDisplayChar(u8 copy_u8Data)
{
	// set Rs pin = 1 (data)
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
	
	// set RW pin = 0 (write)
	DIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	
	// Write The Most 4 bits Of data on Data Pins
	PRV_voidWriteHalfPort(copy_u8Data>>4);
	
	/* Enable Pulse *//* H => L */
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);
	
	// Write The Least 4 bits Of data on Data Pins
	PRV_voidWriteHalfPort(copy_u8Data);
	
	/* Enable Pulse *//* H => L */
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);
}


void LCD_voidDisplayString(u8* copy_pu8String)
{
	if(copy_pu8String!=NULL)
	{
		u8 local_u8Counter=0;
		while(copy_pu8String[local_u8Counter]!='\0')
		{
			LCD_voidDisplayChar(copy_pu8String[local_u8Counter]);
			local_u8Counter++;
		}
	}
	else
	{
		// return Error state
	}
}
void LCD_voidClear               (void)
{
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
}
void LCD_voidGoToSpecificPosition(u8 copy_u8row, u8 copy_u8col)
{
	u8 local_u8position=0;
	 if(1==copy_u8row)
	 {
		 local_u8position=0x80+copy_u8col-1;
	 }
	 else if(2==copy_u8row)
	 {
		 local_u8position=0xC0+copy_u8col-1;
	 }
	 else
	 {
		 //Invalid row value
	 }

	 LCD_voidSendCommand(local_u8position); // Send command to set cursor position
     
}
static void PRV_voidWriteHalfPort(u8 copy_u8Value)
{
	if(1 == READ_BIT(copy_u8Value,0))
	{
		DIO_voidSetPinValue(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_LOW);
	}
	
	if(1 == READ_BIT(copy_u8Value,1))
	{
		DIO_voidSetPinValue(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_LOW);
	}
	
	if(1 == READ_BIT(copy_u8Value,2))
	{
		DIO_voidSetPinValue(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_LOW);
	}
	
	if(1 == READ_BIT(copy_u8Value,3))
	{
		DIO_voidSetPinValue(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_LOW);
	}
}

void LCD_voidDisplayNumber(u32 copy_u32Number)
{
	u8 local_u8Str[50];
	sprintf(local_u8Str,"%lu",copy_u32Number);
	LCD_voidDisplayString(local_u8Str);
}

void LCD_void_calc(u32 copy_u32Frequency,u32 copy_u32DutyCycle)
{
	LCD_voidDisplayString((u8*)"DUTY=");
	LCD_voidDisplayNumber(copy_u32DutyCycle);
	LCD_voidDisplayChar('%');
	LCD_voidDisplayString((u8*)" PWM Signal:");
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString((u8*)" FREQ=");
	LCD_voidDisplayNumber(copy_u32Frequency);
	LCD_voidDisplayString((u8*)"HZ");
	
	
}
void LCD_void_display(u32 copy_u32DutyCycle)
{
	
	switch(copy_u32DutyCycle)
	{
		case 25:
		LCD_voidDisplayString((u8*)"|____|--|____|--|____|-");
		break;
		case 50:
		LCD_voidDisplayString((u8*)"|____|----|____|----|__");
		break;
		case 74:
		LCD_voidDisplayString((u8*)"|----|__|----|__|----|_");
		break;
		case 94:
		LCD_voidDisplayString((u8*)"|-----|_|-----|_|-----|_");
		break;
	}
}