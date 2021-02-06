/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 17/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : EXTI                    ****************/
/*******************************************************************/ 


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_u8_INT0	        	0
#define EXTI_u8_INT1	        	1
#define EXTI_u8_INT2                2
                               
#define EXTI_LOW_LEVEL				0
#define EXTI_ANY_LOGICAL_CHANGE		1
#define EXTI_FALLING_EDGE           2
#define EXTI_RISING_EDGE            3


u8   EXI_Enable		  (u8 INT_NUMBER,u8 INT_TRIGER);
u8   EXI_Disable      (u8 INT_NUMBER);




#endif
