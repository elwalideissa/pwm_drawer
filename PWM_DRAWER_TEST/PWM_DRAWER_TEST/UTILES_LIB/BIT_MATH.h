/*
/////////////////////////////// swc     : BIT MATH        /////////////////////////////////
//////////////////////////////  data    : 12/01/2024     /////////////////////////////////
/////////////////////////////   name    : Elwalid Eissa /////////////////////////////////
////////////////////////////    version : 1.0          /////////////////////////////////
*/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT_NUM)			REG|=(1<<BIT_NUM)
#define CLEAR_BIT(REG,BIT_NUM)			REG&=(~(1<<BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM)			REG^=(1<<BIT_NUM)
#define READ_BIT(REG,BIT_NUM)		    ((REG>>BIT_NUM)&0X01)


#endif