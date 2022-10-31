/************************************************/
/* Title       : LCD Configuration file         */
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_u8_PIN_RS		    DIO_u8_PIN_8
#define LCD_u8_PIN_RW 		    DIO_u8_PIN_9
#define LCD_u8_PIN_E			DIO_u8_PIN_10

#define LCD_u8_PIN_D0			DIO_u8_PIN_16
#define LCD_u8_PIN_D1    		DIO_u8_PIN_17
#define LCD_u8_PIN_D2			DIO_u8_PIN_18
#define LCD_u8_PIN_D3    		DIO_u8_PIN_19
#define LCD_u8_PIN_D4    		DIO_u8_PIN_20
#define LCD_u8_PIN_D5    		DIO_u8_PIN_21
#define LCD_u8_PIN_D6    		DIO_u8_PIN_22
#define LCD_u8_PIN_D7    		DIO_u8_PIN_23

#define LCD_u8_DATA_PORT    	DIO_PORTC

#define FUNCTION_SET			0b00111000
#define DISPLAY_ON				0b00001100
#define DISPLAY_CLR				0b00000001
#define ENTRY_MODE				0b00000110

#define LCD_MODE				LCD_u8_8BitMode



#endif /* LCD_CONFIG_H_ */
