/*
 * LCD_interface.h
 *
 * Created: 2/9/2024 10:50:31 PM
 *  Author: ELWALID EISSA
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_voidInit                (void);
void LCD_voidSendCommand         (u8 copy_u8Cmnd);
void LCD_voidDisplayChar         (u8 copy_u8Data);
void LCD_voidDisplayString       (u8* copy_pu8String);
void LCD_voidDisplayNumber       (u32 copy_u32Number);
void LCD_voidClear               (void); 
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position); 
void LCD_void_calc(u32 copy_u32Frequency,u32 copy_u32DutyCycle);
void LCD_void_display(u32 copy_u32DutyCycle);

#endif /* LCD_INTERFACE_H_ */