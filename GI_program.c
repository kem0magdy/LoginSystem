/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 17/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : EXTI                    ****************/
/*******************************************************************/ 

/* Library Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GI_interface.h"
#include "GI_config.h"
#include "GI_private.h"

void GI_Enable        (void)
{
	SET_BIT(GLOBAL_u8_SREG_REG,GLOBAL_INTER_EN);

}
void GI_Disable       (void)
{
	CLR_BIT(GLOBAL_u8_SREG_REG,GLOBAL_INTER_EN);

}







