/************************************************/
/* Title       : LCD Private file               */
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

static void LCD_SvidExecute(u8 Copy_u8DataCmd);
static void LCD_vidWriteCommand(u8 Copy_u8cmd);

#define LCD_u8_4BitMode     0
#define LCD_u8_8BitMode     1


#endif /* LCD_PRIV_H_ */
