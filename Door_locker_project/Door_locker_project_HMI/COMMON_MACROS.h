/**
 * @file COMMON_MACROS.h
 * @brief Common macros that is used in Door locker program
 * @date 11/1/2014 
 * @author: a7med
 **/ 


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


#define SET_BIT(REG,BIT) (REG= REG | (1<<BIT)) /// set a certain BIT in REG

#define CLR_BIT(REG,BIT) (REG= REG & (~(1<<BIT))) /// clear a certain BIT in REG

#define BIT_IS_SET(REG,BIT) ((REG & (1<<BIT))) /// Check if any BIT of REG is set 

#define BIT_IS_CLR(REG,BIT) ((REG & (1<<BIT) == 0)) /// Check if any BIT of REG is cleared 


#endif /* COMMON_MACROS_H_ */