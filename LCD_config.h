/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 11/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : LCD                     ****************/
/*******************************************************************/ 

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*Options :  1-LCD_u_8_BIT_MODE
			 2-LCD_u_4_BIT_MODE */
#define LCD_u8_MODE     LCD_u_4_BIT_MODE

#if LCD_u8_MODE == LCD_u_8_BIT_MODE
/* Macros For Pin Config 
OptionFor Port:        1- DIO_u8_PORTA 
                       2- DIO_u8_PORTB 
                       3- DIO_u8_PORTC 
                       4- DIO_u8_PORTD */
					   
#define LCD_u8_CONTROL_PORT   		DIO_u8_PORTC
#define LCD_u8_RS_PIN 				DIO_u8_PIN0
#define LCD_u8_RW_PIN 				DIO_u8_PIN1
#define LCD_u8_EN_PIN 				DIO_u8_PIN2


#define LCD_u8_DATA_PORT			DIO_u8_PORTD

/* 4 bit Configuration */
#elif LCD_u8_MODE == LCD_u_4_BIT_MODE
	#define LCD_u8_RS_PIN 				DIO_u8_PIN1
	#define LCD_u8_RS_PORT   		    DIO_u8_PORTA
	
	#define LCD_u8_RW_PIN 				DIO_u8_PIN0
	#define LCD_u8_RW_PORT   		    DIO_u8_PORTA
	
	#define LCD_u8_EN_PIN 				DIO_u8_PIN2
	#define LCD_u8_EN_PORT   		    DIO_u8_PORTA
	
	#define LCD_u8_D4_PIN				DIO_u8_PIN3
	#define LCD_u8_D4_PORT				DIO_u8_PORTA

	#define LCD_u8_D5_PIN				DIO_u8_PIN4
	#define LCD_u8_D5_PORT				DIO_u8_PORTA

	#define LCD_u8_D6_PIN				DIO_u8_PIN5
	#define LCD_u8_D6_PORT				DIO_u8_PORTA

	#define LCD_u8_D7_PIN				DIO_u8_PIN6
	#define LCD_u8_D7_PORT				DIO_u8_PORTA	
	
#endif
#endif

