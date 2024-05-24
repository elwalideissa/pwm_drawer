/*
 * PWM_interface.h
 *
 * Created: 3/1/2024 7:50:48 PM
 *  Author: Kareem Hussein
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

void PWM_voidInitChannel_1A         (void);
void PWM_voidGenerate_PWM_Channel_1A(u16 copy_u16Frequency_hz,f32 copy_f32DutyCycle);
void PWM_void_calc_freq(u32* copy_pu32Frequency ,u32 copy_pu32totalTicks,u32 copy_pu32totalCounter);
void PWM_void_CALC_Duty (u32* copy_pu32DutyCycle,u32 copy_pu32onTicks,u32 copy_pu32onCounter,u32 copy_pu32totalTicks,u32 copy_pu32totalCounter);
#endif /* PWM_INTERFACE_H_ */