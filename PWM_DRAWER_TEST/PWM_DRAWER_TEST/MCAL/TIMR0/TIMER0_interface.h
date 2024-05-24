/*
 * TIMER0_interface.h
 *
 * Created: 2/25/2024 2:19:59 PM
 *  Author: ELWALIDEISSA
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInit(void);
void TIMER0_voidStart(void);
void TIMER0_voidStop(void);
void TIMER0_voidSetCallBackOVF(void(*copy_pFunAction)(void));
void TIMER0_voidSetCallBackCTC(void(*copy_pFunAction)(void));
void TIMER0_VoidSetDelayUsingCTC(u16 copy_u16Delay_ms);



#endif /* TIMER0_INTERFACE_H_ */