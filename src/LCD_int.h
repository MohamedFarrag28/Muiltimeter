/************************************************/
/* Title       : LCD Interface file             */
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_


void LCD_vidInit(void);

void LCD_vidWriteCharacter(u8 Copy_u8data);

void LCD_vidWriteString(s8 * Copy_pString);

void LCD_vidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col );

void LCD_vidClearScreen(void);

#endif /* LCD_INT_H_ */
