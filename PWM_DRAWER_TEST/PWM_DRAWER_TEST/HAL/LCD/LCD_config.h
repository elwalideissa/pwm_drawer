/*
 * LCD_config.h
 *
 * Created: 2/9/2024 10:50:54 PM
 *  Author: ELWALID EISSA
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define LCD_RS_PORT         DIO_PORTB
#define LCD_RS_PIN          DIO_PIN1

#define LCD_RW_PORT			DIO_PORTB
#define LCD_RW_PIN          DIO_PIN2

#define LCD_E_PORT			DIO_PORTB
#define LCD_E_PIN           DIO_PIN3


/* 4 Bit Mode Pins Configurtion */
#define LCD_D4_PORT           DIO_PORTA
#define LCD_D4_PIN            DIO_PIN4

#define LCD_D5_PORT           DIO_PORTA							  
#define LCD_D5_PIN            DIO_PIN5

#define LCD_D6_PORT           DIO_PORTA							  
#define LCD_D6_PIN            DIO_PIN6

#define LCD_D7_PORT           DIO_PORTA							  
#define LCD_D7_PIN            DIO_PIN7




#endif /* LCD_CONFIG_H_ */