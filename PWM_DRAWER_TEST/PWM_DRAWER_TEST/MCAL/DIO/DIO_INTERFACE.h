/*
 * DIO_INTERFACE.h
 *
 * Created: 2/4/2024 3:35:42 PM
 *  Author: ELWALIDEISSA
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*macros for port id*/
#define DIO_PORTA     0
#define DIO_PORTB     1
#define DIO_PORTC     2
#define DIO_PORTD     3

/*macros for pin directions */
#define DIO_PIN_INPUT    0
#define DIO_PIN_OUTPUT   1

/*macros for port directions */
#define DIO_PORT_INPUT    0x00
#define DIO_PORT_OUTPUT   0XFF

/*macros for pin id*/
#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7

/*macros for pin value*/
#define DIO_PIN_LOW   0
#define DIO_PIN_HIGH  1

#define NULL ((void*)0)
/**PIN API**/

void DIO_voidSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinDirction);
void DIO_voidSetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue);
void DIO_voidGetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8* copy_pu8PinValue);
void DIO_voidTogglePinValue(u8 copy_u8PortId,u8 copy_u8PinId);
void DIO_voidActivePinInPullUpResistans(u8 copy_u8PortId,u8 copy_u8PinId);


/**PORT API**/

void DIO_voidSetPortDirection(u8 copy_u8PortId,u8 copy_u8PortDirction);
void DIO_voidSetPortValue(u8 copy_u8PortId,u8 copy_u8PortValue);
void DIO_voidGetPortValue(u8 copy_u8PortId,u8* copy_pu8PortValue);
void DIO_voidTogglePortValue(u8 copy_u8PortId);
void DIO_voidActivePortInPullUpResistans(u8 copy_u8PortId);


#endif /* DIO_INTERFACE_H_ */