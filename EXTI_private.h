/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 17/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : EXTI                    ****************/
/*******************************************************************/ 

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Macros for EXTI Registers */
#define EXTI_u8_MCUCR_REG        *((volatile u8*)(0x55))
#define ISC00_MCUCR                        0
#define ISC01_MCUCR                        1
#define ISC10_MCUCR                        2
#define ISC11_MCUCR                        3


#define EXTI_u8_MCUCSR_REG       *((volatile u8*)(0x54))
#define ISC2_MCUCSR                        6


#define EXTI_u8_GICR_REG         *((volatile u8*)(0x5B))
#define INT1_GICR                          7
#define INT0_GICR                          6
#define INT2_GICR                          5



#define EXTI_u8_GIFR_REG         *((volatile u8*)(0x5A))

/* Macros For Global Interrupt Reg */

#define GLOBAL_u8_SREG_REG 		*((volatile u8*)(0x5F))
#define GLOBAL_INTER_EN                    7






#endif
