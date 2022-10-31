/************************************************/
/* Title       : UART  program file 			*/
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 29, 2021                   */
/************************************************/

#include "BIT_math.h"
#include "STD_types.h"

#include "INTERRUPT.h"
#include "UART_int.h"
#include "UART_priv.h"
#include "UART_conf.h"
#include "util/delay.h"

void UART_vid_UartIntialization(void)
{
	/* Set Baud rate  */


	u16 Local_16_BaudRate = (UART_CPU_CLOCK)/(16*(f32)UART_BAUD_RATE); //note : using always Normal Mode "Static"

	/*
	UBRRH &= 0x7F ;  // make sure URSEL is cleared to write in UBRRH
	UBRRH &= 0xF0 ;  // make sure that first 4 bits are cleared
	*/
	UBRRH = (Local_16_BaudRate>>8)&0x0F ;
	UBRRL = Local_16_BaudRate&0xFF ;
	//UBRRL = 51 ;

	/* Enable UART Stare FULL/HALF(R/T) DUPLEX */
	UCSRB = UART_STATE<< 3 ;


	/* Select frame format /  Mode /  Parity Mode / Stop Bit /Clock Polarity  */
	// UCSRB &= 0xFB ;   // clear UCSZ2 bit first to make sure
	UCSRB |= ((UART_DSIZE>>2)&1)<<2 ;
	UCSRC |= 1 << 7 ;  // to write in UCSRC
	UCSRC = 1<<7  | UART_MODE<<6 | UART_PARITY_T<<4 | UART_STOPBIT_T<<3| (UART_DSIZE&3)<<1 |UART_CLK_POLARITY ;
}


void UART_vid_SendChar(u8 Copy_u8_char)
{
	while(!(GET_BIT(UCSRA,5))) ;

	UDR = Copy_u8_char ;
}

void UART_vid_SendString(s8* Copy_pu8_Str , u8 delay)
{
	while(*Copy_pu8_Str != '\0')
	{
		UART_vid_SendChar(*Copy_pu8_Str) ;
		Copy_pu8_Str++ ;
		_delay_ms(delay) ;
	}
}

void UART_u8_ReadChar(u8* Copy_pu8_char,u32 Copy_Time_Out)
{
	if (Copy_Time_Out ==0)			// disabled
	{
	while(!(GET_BIT(UCSRA,7))) ;

	*Copy_pu8_char = UDR ;
	}
	else
	{
		while((!(GET_BIT(UCSRA,7))) && Copy_Time_Out  ) Copy_Time_Out-- ;
		if (Copy_Time_Out==0)
		{
			*Copy_pu8_char = 0 ;
		}
		else
		{
			*Copy_pu8_char = UDR ;
		}
	}

}

void UART_vid_ReadStr(u8* Copy_pu8_str,u16 Copy_u16_StrLen,u32 Copy_TimeOut)
{
	for(u8 i=0;i< Copy_u16_StrLen;i++)
	{
		while(!(GET_BIT(UCSRA,7)))  Copy_TimeOut-- ;
		if (Copy_TimeOut == 0)
			Copy_pu8_str[i] = '\0' ;
		else
			Copy_pu8_str[i] = UDR ;

		if(Copy_pu8_str[i]=='\0')    // finished or time out
			break ;
	}
}

void UART_vid_Enable_RXInt(void)
{
	INT_ENABLE_GLOBAL_INT ;
	SET_BIT(UCSRB,7) ;
}

void UART_vid_Disable_RXInt(void)
{
	CLR_BIT(UCSRB,7);
}

void UART_vid_Enable_TXInt(void)
{
	INT_ENABLE_GLOBAL_INT;
	SET_BIT(UCSRB,6) ;
}
void UART_vid_Disable_TXInt(void)
{
	CLR_BIT(UCSRB,6);
}

void UART_vid_Enable_DataEmptyInt(void)
{
	INT_ENABLE_GLOBAL_INT;
	SET_BIT(UCSRB,5);
}

void UART_vid_Disable_DataEmptyInt(void)
{
	CLR_BIT(UCSRB,5);
}

void UART_voidSetCallBack(enum UART_INTERRUPT_TYPE Copy_InterruptType, void (*CallBack)(void) )
{
	if(Copy_InterruptType > UART_COMP_TX)
				return;
	PUART_vid_CallBacks[Copy_InterruptType] = CallBack ;
}

void UART_VECTOR_ISR_COMP_RX()
{
	if (PUART_vid_CallBacks[0] !=0)
			PUART_vid_CallBacks[0]() ;
}

void UART_VECTOR_ISR_DATA_EMBTY()
{
	if (PUART_vid_CallBacks[1] !=0)
			PUART_vid_CallBacks[1]() ;
}

void UART_VECTOR_ISR_COMP_TX()
{
	if (PUART_vid_CallBacks[2] !=0)
			PUART_vid_CallBacks[2]() ;
}
