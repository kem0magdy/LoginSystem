/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 11/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : LCD                     ****************/
/*******************************************************************/ 


/* Library Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"


/* HAL */
#include "LCD_Interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

u32 ArrNumb[10];

void LCD_voidInit			(void)
{
	_delay_ms(35);
#if LCD_u8_MODE == LCD_u_8_BIT_MODE
	/* Function Send Cmnd  */
	LCD_voidSendCmnd(0b00111000); // as data sheet
#elif LCD_u8_MODE == LCD_u_4_BIT_MODE
	DIO_u8SetPinVale(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);

	DIO_u8SetPinVale(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	Private_voidWriteHalfPort(0b0010);
	
	/*Enable Pulse */
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
	LCD_voidSendCmnd(0b00101000);
#endif

	_delay_us(45);
	/* Display On / OFF Control  */
	LCD_voidSendCmnd(0b00001111); 
	_delay_us(45);
	/* Display Clear */
	LCD_voidSendCmnd(0b00000001); 
	_delay_ms(2);
	/* Entery Mode Set */
	LCD_voidSendCmnd(0b00000110); 


}
void LCD_voidSendCmnd 	    (u8 Copy_u8Cmnd)
{
#if LCD_u8_MODE == LCD_u_8_BIT_MODE
	/* Rs pin = 0 */
	DIO_u8SetPinVale(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* Rw pin = 0 */
	DIO_u8SetPinVale(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);

	/* Write Command on Data Pins */
	DIO_u8SetPortVale(LCD_u8_DATA_PORT,Copy_u8Cmnd);
	
	/* Enable Pulse Latch  */ // High => LOW //
	DIO_u8SetPinVale(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinVale(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
#elif LCD_u8_MODE == LCD_u_4_BIT_MODE
	/* Rs pin = 0 */
	DIO_u8SetPinVale(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* Rw pin = 0 */
	DIO_u8SetPinVale(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* Send To LCD MOST 4 BITs */
	Private_voidWriteHalfPort(Copy_u8Cmnd>>4);
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
	
	/* Send To LCD Lease 4 BITs of the cmnd */
	Private_voidWriteHalfPort(Copy_u8Cmnd);
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
#endif
}
void LCD_voidSendChar		(u8 Copy_u8Char)
{
#if LCD_u8_MODE == LCD_u_8_BIT_MODE
		/* Rs pin = 1 */
	DIO_u8SetPinVale(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	/* Rw pin = 0 */
	DIO_u8SetPinVale(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);

	/* Write Char on Data Pins */
	DIO_u8SetPortVale(LCD_u8_DATA_PORT,Copy_u8Char);
	
	/* Enable Pulse Latch  */ // High => LOW //
	DIO_u8SetPinVale(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinVale(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
	
#elif LCD_u8_MODE == LCD_u_4_BIT_MODE
/* Rs pin = 0 */
	DIO_u8SetPinVale(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	/* Rw pin = 0 */
	DIO_u8SetPinVale(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* Send To LCD MOST 4 BITs */
	Private_voidWriteHalfPort(Copy_u8Char>>4);
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
	
	/* Send To LCD Lease 4 BITs of the cmnd */
	Private_voidWriteHalfPort(Copy_u8Char);
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinVale(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
#endif
}

void LCD_String	(const u8 *ptr,u8 Line_Nb ,u8 Pos)
{
	LCD_voidGoToXY(Line_Nb,Pos);
	for(u8 i=0; ptr[i]!='\0';i++)
	{

		LCD_voidSendChar(ptr[i]);

	}

}
void LCD_voidSendNumber(u32 Number)
{
	u8 temp;
	u8 count=0;
	while(Number>0)
	{
		ArrNumb[count]=Number%10;
		Number=Number/10;
		count++;
	}
	count--;
	for(s8 j=count; j>=0 ;j--)
	{
		temp=ArrNumb[j]+48;
		LCD_voidSendChar(temp);
		_delay_ms(100);


	}

}

void LCD_voidGoToXY   		(u8 Copy_u8LineNb, u8 Copy_u8Pos)
{
	
	switch(Copy_u8LineNb)
	{
		case LCD_u8_LINE_ONE: LCD_voidSendCmnd(0x80+Copy_u8Pos);break;
		case LCD_u8_LINE_TWO: LCD_voidSendCmnd(0xC0+Copy_u8Pos);break;

	}
}

static void Private_voidWriteHalfPort(u8 Copy_u8Value) //0b11110000
{
	u8 Local_u8_BitValue;
	Local_u8_BitValue = GET_BIT(Copy_u8Value,0);
	Local_u8_BitValue==0?DIO_u8SetPinVale(LCD_u8_D4_PORT,LCD_u8_D4_PIN,DIO_u8_LOW):DIO_u8SetPinVale(LCD_u8_D4_PORT,LCD_u8_D4_PIN,DIO_u8_HIGH);

	Local_u8_BitValue = GET_BIT(Copy_u8Value,1);
	Local_u8_BitValue==0?DIO_u8SetPinVale(LCD_u8_D5_PORT,LCD_u8_D5_PIN,DIO_u8_LOW):DIO_u8SetPinVale(LCD_u8_D5_PORT,LCD_u8_D5_PIN,DIO_u8_HIGH);
	
	Local_u8_BitValue = GET_BIT(Copy_u8Value,2);
	Local_u8_BitValue==0?DIO_u8SetPinVale(LCD_u8_D6_PORT,LCD_u8_D6_PIN,DIO_u8_LOW):DIO_u8SetPinVale(LCD_u8_D6_PORT,LCD_u8_D6_PIN,DIO_u8_HIGH);
	
	Local_u8_BitValue = GET_BIT(Copy_u8Value,3);
	Local_u8_BitValue==0?DIO_u8SetPinVale(LCD_u8_D7_PORT,LCD_u8_D7_PIN,DIO_u8_LOW):DIO_u8SetPinVale(LCD_u8_D7_PORT,LCD_u8_D7_PIN,DIO_u8_HIGH);
}

void LCD_voidWriteSpecialChar    (u8 *pattern, u8 PatterPos, u8 Line_Nb ,u8 Pos)
{
	LCD_voidSendCmnd(0x40 + (PatterPos*8));   //0b01000000 + 1*8 // to set CGRAM
	for(u8 i=0; i<8 ; i++)
	{
		LCD_voidSendChar(pattern[i]);
	}
	LCD_voidGoToXY(Line_Nb,Pos);
	LCD_voidSendChar(PatterPos);
	
	
}
	
void LCD_voidSendNumber2(f64 Number)
{

	if(Number<0)
	{
		Number*=-1;
		LCD_voidSendChar('-');
	}

	u32 NoFloat=(u32)Number;
	if(Number==0)
	{
		LCD_voidSendChar('0');

	}
	else
	{
		if(NoFloat==0)
		{
			LCD_voidSendChar('0');
		}

		u32 Rev=1;
		while(NoFloat)
		{
			Rev=(Rev*10)+(NoFloat%10);
			NoFloat/=10;
		}
		NoFloat=Rev;
		while(NoFloat !=1)
		{
			LCD_voidSendChar((NoFloat%10)+'0');
			NoFloat/=10;
		}
		f64 Copy_f64Float=(Number-(u32)Number);
		if(Copy_f64Float>0)
		{
			LCD_voidSendChar('.');
			Copy_f64Float*=10.0;
			LCD_voidSendChar((u8)Copy_f64Float+'0');
			Copy_f64Float*=10.0;
			LCD_voidSendChar(((u8)Copy_f64Float%10)+'0');

		}
	}

}
	

	

