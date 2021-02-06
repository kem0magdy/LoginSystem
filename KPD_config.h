/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 13/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : Keypad                  ****************/
/*******************************************************************/ 

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H


#define KPD_u8_ROWS_NB       4
#define KPD_u8_COLS_NB       4

/* ROWS => Output */
#define KPD_u8_ROWS_PORT     DIO_u8_PORTB
#define KPD_u8_R1_PIN        DIO_u8_PIN4
#define KPD_u8_R2_PIN        DIO_u8_PIN5
#define KPD_u8_R3_PIN        DIO_u8_PIN6
#define KPD_u8_R4_PIN        DIO_u8_PIN7

/* COLS => Input */ // pull up
#define KPD_u8_COLS_PORT     DIO_u8_PORTD
#define KPD_u8_C1_PIN        DIO_u8_PIN2
#define KPD_u8_C2_PIN        DIO_u8_PIN3
#define KPD_u8_C3_PIN        DIO_u8_PIN4
#define KPD_u8_C4_PIN        DIO_u8_PIN5

#define KPD_ROWS_PINS		 {KPD_u8_R1_PIN, KPD_u8_R2_PIN, KPD_u8_R3_PIN, KPD_u8_R4_PIN}
#define KPD_ROWS_PIN		 {KPD_u8_C1_PIN, KPD_u8_C2_PIN, KPD_u8_C3_PIN, KPD_u8_C4_PIN}
#define KPD_KEYS 	         {{'1','2','3','+'},     \
					          {'4','5','6','-'},      \
					          {'7','8','9','*'},      \
					          {'0','%','/','='}}      
	


#endif
