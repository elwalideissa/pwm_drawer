/*
 * EXTI_register.h
 *
 * Created: 2/18/2024 6:26:39 PM
 *  Author:ElwalidEissa
 */ 


#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

                 /* EXTERNAL INTERRUPT REGISTER */
//MCU Control Register
#define MCUCR_REG   (*(volatile u8*)0x55)
#define ISC00       0
#define ISC01       1
#define ISC10       2
#define ISC11       3
//MCU Control and Status Register
#define MCUCSR_REG  (*(volatile u8*)0x54)
#define ISC2        6
//General Interrupt Control Register
#define GICR_REG    (*(volatile u8*)0x5B)
#define INT0        6
#define INT1        7
#define INT2        5
//General Interrupt Flag Register
#define GIFR_REG    (*(volatile u8*)0x5A)
#define INT0        6
#define INT1        7
#define INT2        5


#endif /* EXTI_REGISTER_H_ */