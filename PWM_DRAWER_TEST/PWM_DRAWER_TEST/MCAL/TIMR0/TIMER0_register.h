/*
 * TIMERO_register.h
 *
 * Created: 2/25/2024 2:20:22 PM
 *  Author: ELWALIDEISSA
 */ 


#ifndef TIMERO_REGISTER_H_
#define TIMERO_REGISTER_H_

#define TCCR0_REG  (*(volatile u8*)0X53)
#define CS00                0
#define CS01                1
#define CS02                2
#define WGM01               3
#define COM00               4
#define COM01               5
#define WGM00               6
#define FOC0                7

#define TCNT0_REG  (*(volatile u8*)0X52)

#define OCR0_REG   (*(volatile u8*)0X5C)

#define TIMSK_REG  (*(volatile u8*)0X59)
#define TOIE0               0
#define OCIE0               1

#define TIFR_REG   (*(volatile u8*)0X58)
#define TOV0                0
#define OCF0                1



#endif /* TIMERO_REGISTER_H_ */