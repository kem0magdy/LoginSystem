/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 11/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : LCD                     ****************/
/*******************************************************************/ 

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_u8_LINE_ONE   		1
#define LCD_u8_LINE_TWO   		2

void LCD_voidInit			     (void);
void LCD_voidSendCmnd 	         (u8 Copy_u8Cmnd);
void LCD_voidSendChar		     (u8 Copy_u8Char);
void LCD_String				     (const u8 *ptr,u8 Line_Nb ,u8 Pos);
void LCD_voidSendNumber		     (u32 Number);
void LCD_voidSendNumber2         (f64 Number);
void LCD_voidGoToXY   		     (u8 Copy_u8LineNb, u8 Copy_u8Pos);
void LCD_voidWriteSpecialChar    (u8 *pattern, u8 PatterPos, u8 Line_Nb ,u8 Pos);



#endif /* LCD_INTERFACE_H */
