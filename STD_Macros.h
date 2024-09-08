/*
 * STD_Macros.h
 *
 * Created: 8/17/2024
 *  Author: REEM Mohamed
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define Register_Size 8
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define READ_BIT(reg,bit)    (reg&(1<<bit))>>bit


#endif /* STD_MACROS_H_ */