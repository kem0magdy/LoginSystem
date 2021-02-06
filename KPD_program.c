/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 13/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : Keypad                  ****************/
/*******************************************************************/ 

/* Library Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


u8 KPD_u8GetState(u8 * Copy_pu8ReturnedSwitch)
{
	u8 Local_u8ReturnState=STD_TYPES_OK;
	u8 Local_u8PinValue,Local_u8Flag=0;
	static u8 Local_Au8RowsPinArr[KPD_u8_ROWS_NB]= KPD_ROWS_PINS;// static to add it to .data withouth pushing in stack every calling
	static u8 Local_Au8ColsPinArr[KPD_u8_COLS_NB]=KPD_ROWS_PIN; // static to add it to .data withouth pushing in stack every calling
	static Local_Au8KPDValues[KPD_u8_ROWS_NB][KPD_u8_COLS_NB] =KPD_KEYS;
	if(Copy_pu8ReturnedSwitch != NULL)
	{
		*Copy_pu8ReturnedSwitch= KPD_u8_NOT_PRESSED;
		for(u8 Local_u8RowCounter=0; Local_u8RowCounter<KPD_u8_ROWS_NB ;Local_u8RowCounter++)
		{
			/* Activate Each Row */
			DIO_u8SetPinVale(KPD_u8_ROWS_PORT,Local_Au8RowsPinArr[Local_u8RowCounter], DIO_u8_LOW);
			/* Loop To Check Cols Pins */
			for(u8 Local_u8ColsCounter = 0; Local_u8ColsCounter<KPD_u8_COLS_NB; Local_u8ColsCounter++)
			{
				/* Check If Col Is in Low State */
				DIO_u8GetPinVale(KPD_u8_COLS_PORT,Local_Au8ColsPinArr[Local_u8ColsCounter],&Local_u8PinValue);
				if(Local_u8PinValue == DIO_u8_LOW)
				{
					*Copy_pu8ReturnedSwitch= Local_Au8KPDValues[Local_u8RowCounter][Local_u8ColsCounter];
					while(Local_u8PinValue == DIO_u8_LOW)
					{
					DIO_u8GetPinVale(KPD_u8_COLS_PORT,Local_Au8ColsPinArr[Local_u8ColsCounter],&Local_u8PinValue);
					}
					Local_u8Flag = 1;
					break;
					}
				
			}
			/* Deactivate The Current Row */
			DIO_u8SetPinVale(KPD_u8_ROWS_PORT,Local_Au8RowsPinArr[Local_u8RowCounter], DIO_u8_HIGH);
			if(Local_u8Flag==1)
			{
				break;
			}

		}
	}
	else
	{
		Local_u8ReturnState=STD_TYPES_NOK;
	}
	return Local_u8ReturnState;
}
