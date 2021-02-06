#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "util/delay.h"

#include"DIO_interface.h"
#include"KPD_interface.h"
#include"LCD_Interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"

#define PW 1234

int main(void)
{
	u8 Local_u8Key;
	s32 pw,Try=3;
	u8 Enter[]= "Enter Password:";
	u8 Wrong[]= "Wrong Password!";
	u8 Tries  []= "Tries Left:  ";
	u8 LoginS[]= "Loggin Success!";
	u8 LoginF[]= "Loggin Fail!";

	DIO_voidInit();
	LCD_voidInit();
	EXI_Enable(EXTI_u8_INT2,EXTI_FALLING_EDGE);
	/* Enable Global Interrupt */
	GI_Enable();



	while(Try>=0)
	{
		LCD_voidSendCmnd(0x1);
		LCD_String(Enter,LCD_u8_LINE_ONE,0);
		LCD_voidGoToXY(LCD_u8_LINE_TWO,0);
		while(Local_u8Key!= '=')
		{
			KPD_u8GetState(&Local_u8Key);
			if (Local_u8Key!=KPD_u8_NOT_PRESSED)
			 {
			   if(Local_u8Key>='0' && Local_u8Key <='9')
				{
				 LCD_voidSendChar('*');
				 pw=(pw*10)+Local_u8Key-'0';
				}
			 }
		}
		if(pw==PW)
		{
			LCD_voidSendCmnd(0x1);
			LCD_String(LoginS,LCD_u8_LINE_ONE,0);
			_delay_ms(1000);
			break;

		}
		if(pw != PW)
		{
			LCD_voidSendCmnd(0x1);
			LCD_String(Wrong,LCD_u8_LINE_ONE,0);
			_delay_ms(1000);
			LCD_voidSendCmnd(0x1);
			LCD_String(Tries,LCD_u8_LINE_ONE,0);
			if(Try==3 || Try==2 || Try==1)
			LCD_voidSendNumber(Try);
			else
			{
			LCD_voidSendChar('0');
			LCD_voidSendCmnd(0x1);
			LCD_String(LoginF,LCD_u8_LINE_ONE,0);
			}
			_delay_ms(1000);
		Try--;
		}
		pw=0;
		Local_u8Key=0;
	}


	while (1)
	{

	}




	return 0;

}

void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	/* Tog Led */
	static u8 Local_u8Flag =0;
	if(Local_u8Flag==0)
	{
		DIO_u8SetPinVale(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		Local_u8Flag=1;
	}
	else
	{
		DIO_u8SetPinVale(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		Local_u8Flag=0;
	}
}

