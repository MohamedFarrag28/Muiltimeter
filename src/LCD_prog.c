/************************************************/
/* Title       : LCD Program file               */
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#include "BIT_MATH.h"
#include "STD_Types.h"

#include <util/delay.h>


#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_priv.h"
#include "DIO_int.h"

void LCD_vidInit(void)
{
	_delay_ms(35);
	LCD_vidWriteCommand(FUNCTION_SET);
	_delay_ms(1);
	LCD_vidWriteCommand(DISPLAY_ON);
	_delay_ms(1);
	LCD_vidWriteCommand(DISPLAY_CLR);
	_delay_ms(2);
	LCD_vidWriteCommand(ENTRY_MODE);


}

void LCD_vidWriteCharacter(u8 Copy_u8data)
{
	DIO_vid_SetPinValue( LCD_u8_PIN_RS ,  DIO_u8_HIGH); // RS high for data
	LCD_SvidExecute(Copy_u8data);

}

void LCD_vidWriteCommand(u8 Copy_u8cmd)
{
	DIO_vid_SetPinValue( LCD_u8_PIN_RS ,  DIO_u8_LOW); // RS low for commands
	LCD_SvidExecute(Copy_u8cmd);
}

void LCD_vidWriteString(s8 * Copy_pString)
{
	u8 Local_u8Index = 0 ;
	while(Copy_pString[Local_u8Index]  != '\0' )
	{
		LCD_vidWriteCharacter(Copy_pString[Local_u8Index]);
		Local_u8Index++ ;
	}

}

void LCD_vidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col )
{
	u8 Local_u8Address ;
	switch(Copy_u8Row)
	{
	case 0 :
		Local_u8Address = 0x00 + Copy_u8Col ; // first row address
		break ;
	case 1 :
		Local_u8Address = 0x40 + Copy_u8Col ; // second row address
		break ;
	}
	LCD_vidWriteCommand(0x80 | Local_u8Address ); // DDRAM address

}

void LCD_vidClearScreen(void)
{
	LCD_vidWriteCommand(0b00000001);

}

static void LCD_SvidExecute(u8 Copy_u8DataCmd)
{

	DIO_vid_SetPinValue( LCD_u8_PIN_RW ,  DIO_u8_LOW ); // means write
	_delay_ms(1);
	DIO_vid_SetPinValue( LCD_u8_PIN_E ,  DIO_u8_HIGH);
	_delay_ms(1);
	DIO_vid_SetPortValue(LCD_u8_DATA_PORT ,Copy_u8DataCmd );
	_delay_ms(1);
	DIO_vid_SetPinValue( LCD_u8_PIN_E ,  DIO_u8_LOW);
	_delay_ms(1);


}
