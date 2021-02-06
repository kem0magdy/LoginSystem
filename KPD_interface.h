/*******************************************************************/ 
/**************** Name    : Kamal Magdy Kamal ElDin ****************/
/**************** Date    : 13/1/2020               ****************/
/**************** Version : 1.0.0                   ****************/
/**************** SWC     : Keypad                  ****************/
/*******************************************************************/ 

#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define KPD_u8_NOT_PRESSED      0xFF
u8 KPD_u8GetState(u8 * Copy_pu8ReturnedSwitch);

#endif