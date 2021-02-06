/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 17/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : EXTI                    ****************/
/*******************************************************************/ 

/* Library Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


u8 EXI_Enable(u8 INT_NUMBER,u8 INT_TRIGER)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(INT_NUMBER){
		case EXTI_u8_INT0:
		switch(INT_TRIGER){
			/* Choose which edge from clear or set ISC00 & ISC01 */
			case EXTI_LOW_LEVEL:
			CLR_BIT(EXTI_u8_MCUCR_REG,ISC00_MCUCR);
			CLR_BIT(EXTI_u8_MCUCR_REG,ISC01_MCUCR);
			SET_BIT(EXTI_u8_GICR_REG,INT0_GICR); // enable inttrupt
			break;
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(EXTI_u8_MCUCR_REG,ISC00_MCUCR);
			CLR_BIT(EXTI_u8_MCUCR_REG,ISC01_MCUCR);
			SET_BIT(EXTI_u8_GICR_REG,INT0_GICR);  // enable inttrupt
			break;
			case EXTI_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCR_REG,ISC00_MCUCR);
			SET_BIT(EXTI_u8_MCUCR_REG,ISC01_MCUCR);
			SET_BIT(EXTI_u8_GICR_REG,INT0_GICR);  // enable inttrupt
			break;
			case EXTI_RISING_EDGE:
			SET_BIT(EXTI_u8_MCUCR_REG,ISC00_MCUCR);
			SET_BIT(EXTI_u8_MCUCR_REG,ISC01_MCUCR);
			SET_BIT(EXTI_u8_GICR_REG,INT0_GICR);  // enable inttrupt
			break;
			default: Local_u8ErrorState = STD_TYPES_NOK;
		}
		break;
		
		case EXTI_u8_INT1:
		switch(INT_TRIGER){
			/* Choose which edge from clear or set ISC10 & ISC11 */
			case EXTI_LOW_LEVEL:
			CLR_BIT(EXTI_u8_MCUCR_REG,ISC10_MCUCR);
			CLR_BIT(EXTI_u8_MCUCR_REG,ISC11_MCUCR);
			SET_BIT(EXTI_u8_GICR_REG,INT1_GICR);  // enable inttrupt
			break;
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(EXTI_u8_MCUCR_REG,ISC10_MCUCR);
			CLR_BIT(EXTI_u8_MCUCR_REG,ISC11_MCUCR);
			SET_BIT(EXTI_u8_GICR_REG,INT1_GICR);  // enable inttrupt
			break;
			case EXTI_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCR_REG,ISC10_MCUCR);
			SET_BIT(EXTI_u8_MCUCR_REG,ISC11_MCUCR);
			SET_BIT(EXTI_u8_GICR_REG,INT1_GICR);  // enable inttrupt
			break;
			case EXTI_RISING_EDGE:
			SET_BIT(EXTI_u8_MCUCR_REG,ISC10_MCUCR);
			SET_BIT(EXTI_u8_MCUCR_REG,ISC11_MCUCR);
			SET_BIT(EXTI_u8_GICR_REG,INT1_GICR);  // enable inttrupt
			break;
			default: Local_u8ErrorState = STD_TYPES_NOK;
		}
		break;
		
		case EXTI_u8_INT2:
		switch(INT_TRIGER){
			/* Choose which edge from clear or set ISC2 */
			case EXTI_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCSR_REG,ISC2_MCUCSR);
			SET_BIT(EXTI_u8_GICR_REG,INT2_GICR);
			break;
			case EXTI_RISING_EDGE:
			SET_BIT(EXTI_u8_MCUCSR_REG,ISC2_MCUCSR);
			SET_BIT(EXTI_u8_GICR_REG,INT2_GICR);
			break;
			default: Local_u8ErrorState = STD_TYPES_NOK;
		}
		break;
		default: Local_u8ErrorState = STD_TYPES_NOK;

	}
	return Local_u8ErrorState;
}


u8 EXI_Disable      (u8 INT_NUMBER)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(INT_NUMBER){
		case EXTI_u8_INT0:
		CLR_BIT(EXTI_u8_GICR_REG,INT0_GICR); // disable inttrupt INT0 bit 6 in GICR reg
		break;
		case EXTI_u8_INT1:
		CLR_BIT(EXTI_u8_GICR_REG,INT1_GICR); // disable inttrupt INT0 bit 7 in GICR reg
		break;
		case EXTI_u8_INT2:
		CLR_BIT(EXTI_u8_GICR_REG,INT2_GICR); // disable inttrupt INT0 bit 5 in GICR reg
		break;
		default: Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}








