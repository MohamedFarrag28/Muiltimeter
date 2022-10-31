/************************************************/
/* Title       : Main file 						*/
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 29, 2021                   */
/************************************************/

#include <stdlib.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "UART_int.h"
#include "util/delay.h"
#include <string.h>
#include <stdio.h>
#include "LCD_int.h"
#include "ADC_int.h"
#include"ICU_interface.h"
void ohmmeter(void);
void inductance(void);
void voltameter(void);
void frequencymeter(void);
void Ammeter(void);
void capacitor(void);
s8* Device_Type[6]={"Ammeter","Voltameter","Ohmmeter","Freq_Meter","Ind_Meter","Cap_Meter"};
void (*ptr_functions[6])(void)={&Ammeter,&voltameter,&ohmmeter,&frequencymeter,&inductance,&capacitor};
void LCD_intgerToString(u16 data);
void write_sentance(s8* copy_str,u8 start,u8 end , u8 delay);
void printstars(u8 length);
void choose_mode(void) ;

int main(void)
{
	DIO_vid_Init();
	UART_vid_UartIntialization() ;
	LCD_vidInit() ;
	ADC_vid_Initialize() ;
	ADC_vid_Enable();
	ICU_vidInit();
	DIO_vid_SetPinDirection(DIO_u8_PIN_30,DIO_INPUT_PULLUP);
	u8 Mode  , Flag=1 , res ;

	//_delay_ms(1000);
	LCD_vidWriteString("Hello !!!");
	write_sentance("Welcome to our simple multimeter",1,1,40) ;
	choose_mode() ;
	while(1)
	{

		UART_u8_ReadChar(&(Mode),0) ;


		if ((Mode-'0')>=0 &&(Mode-'0')<=5  )
		{
			while(Flag)
			{
					LCD_vidClearScreen();
					if((Mode-'0')!=3)
						LCD_vidWriteString( Device_Type[(Mode-'0')]);
					if(ptr_functions[Mode-'0']!=0)
					{
						ptr_functions[Mode-'0']();
					}

					UART_u8_ReadChar(&(res),65534) ;
					if(res == 'q')
						Flag = 0 ;
			}
			LCD_vidClearScreen();
			LCD_vidWriteString("Waiting...");
			Flag = 1 ;
			UART_vid_SendChar((char)13);
			UART_vid_SendString("Enter your mode : ",10);
		}
		else
		{
			LCD_vidClearScreen();
			LCD_vidWriteString("INVALID");
			UART_vid_SendChar((char)13);
			UART_vid_SendString("Enter your mode : ",10);
		}


	}


	return 0 ;
}

void write_sentance(s8* copy_str,u8 start,u8 end,u8 delay)
{
	u8 len = strlen(copy_str)+4;

	if (start)
		printstars(len);

	UART_vid_SendString("* ",delay);
	UART_vid_SendString(copy_str,delay);
	UART_vid_SendString(" *",delay);
	UART_vid_SendChar((char)13);

	if(end)
		printstars(len);
}

void printstars(u8 copy_length)
{
	for(u8 i=0 ; i<copy_length;i++)
	{
		UART_vid_SendChar('*');
		_delay_ms(40);
	}
	UART_vid_SendChar((char)13);
}

void choose_mode(void)
{
	write_sentance("Choose your mode  :                                    ",0,0,10);
	write_sentance("0--> For Ammeter          || 1--> For voltameter       ",0,0,10);
	write_sentance("2--> For Ohmmeter         || 3--> For Frequency-meter  ",0,0,10);
	write_sentance("4--> For Inductance-meter || 5--> For Capacitance-meter",0,0,10);
	write_sentance("# NOTE: Press q to exit current mode                  #",0,0,10);
	UART_vid_SendString("Enter your mode : ",10);
}

void ohmmeter(void)
{
	u16 r=0;
	r = ADC_u16_Read(ADC_0) ;
	r=(30000)*((5000.0/(((f32)r*5000)/(1023)))-1);
	LCD_vidGoToRowCol(1,0);
	LCD_vidWriteString("Res=");
	LCD_intgerToString(r);
	LCD_vidWriteString(" [Ohm]");
	_delay_ms(500);
}

void inductance(void)
{
	DIO_vid_SetPinValue(DIO_u8_PIN_15,DIO_u8_HIGH);
	u16 x=0 ,y=0 ,z=0 ;
	f32 ind =0 ;
	f32 const_cap= 0.000002;
	DIO_vid_SetPinValue(DIO_u8_PIN_31,DIO_u8_HIGH);
	_delay_ms(10);
	DIO_vid_SetPinValue(DIO_u8_PIN_31,DIO_u8_LOW);
	ICU_vidGetProperties(&x,&y,&z);
	ind = 1000000/(4*9.8696*z*z*const_cap);
	LCD_vidGoToRowCol(1,0);
	LCD_vidWriteString("ind = ");
	LCD_intgerToString(ind);
	LCD_vidWriteString(" [uH]");
}
void Ammeter(void)
{
	u16 r = 0 ;
	r = ADC_u16_Read(ADC_2) ;
	r = ((f32)r*4.88758553);
	r = (f32)(((f32)r -2380)/0.195) ;
	LCD_vidGoToRowCol(1,0);
	LCD_vidWriteString("Amb=");
	LCD_intgerToString(r);
	LCD_vidWriteString(" [mA]");
}

void voltameter(void)
{
	u16 r = 0 ;
	r = ADC_u16_Read(ADC_1) ;
	r = ((f32)r*4.88758553);
	r = ((f32)r * 6 ) ;
	LCD_vidGoToRowCol(1,0);
	LCD_vidWriteString("Volt=");
	LCD_intgerToString(r);
	LCD_vidWriteString(" [mV]");

}
void LCD_intgerToString(u16 data)
{
   s8 buff[16]; // String to hold the ascii result
   itoa(data,buff,10); //10 for decimal
   LCD_vidWriteString(buff);

}

void frequencymeter(void)
{
	LCD_vidClearScreen();
	u16 x=0 ,y=0 ,z=0 ;
	DIO_vid_SetPinValue(DIO_u8_PIN_31,DIO_u8_HIGH);
	_delay_ms(10);
	DIO_vid_SetPinValue(DIO_u8_PIN_31,DIO_u8_LOW);
	ICU_vidGetProperties(&x,&y,&z);
	//LCD_vidGoToRowCol(1,0);
	LCD_vidWriteString("Duty=");
	LCD_intgerToString(y);
	LCD_vidWriteCharacter('%');
	LCD_vidGoToRowCol(1,0);
	LCD_vidWriteString("Per=");
	LCD_intgerToString(x);
	LCD_vidWriteString(" [uS]");
	_delay_ms(700);
	LCD_vidClearScreen();
	LCD_vidWriteString("Freq=");
	LCD_intgerToString(z);
	LCD_vidWriteString(" [Hz]");
	_delay_ms(700);
}
void capacitor(void)
{
	DIO_vid_SetPinValue(DIO_u8_PIN_15,DIO_u8_LOW);
	u16 x=0 ,y=0 ,z=0 ;
	f32 cap =0 ;
	f32 const_ind=0.00005;
	DIO_vid_SetPinValue(DIO_u8_PIN_31,DIO_u8_HIGH);
	_delay_ms(10);
	DIO_vid_SetPinValue(DIO_u8_PIN_31,DIO_u8_LOW);
	ICU_vidGetProperties(&x,&y,&z);
	cap = 1000000/(4*9.8696*z*z*const_ind);
	LCD_vidGoToRowCol(1,0);
	LCD_vidWriteString("cap = ");
	LCD_intgerToString(cap);
	LCD_vidWriteString(" [uF]");
}


