/************************************************/
/* Title       : UART  interface file 			*/
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 29, 2021                   */
/************************************************/

#ifndef UART_INT_H_
#define UART_INT_H_


enum UART_INTERRUPT_TYPE{UART_COMP_RX,UART_DATA_EMBTY,UART_COMP_TX};


// initialization
void UART_vid_UartIntialization(void);

// send character and string
void UART_vid_SendChar(u8 Copy_u8_char) ;
void UART_vid_SendString(s8* Copy_pu8_Str, u8 delay) ;

// read character and string
void UART_u8_ReadChar(u8* Copy_pu8_char,u32 Copy_Time_Out) ;
void UART_vid_ReadStr(u8* Copy_pu8_str,u16 Copy_u16_StrLen,u32 Copy_TimeOut) ;

//Enable and disable Receive completed Interrupt
void UART_vid_Enable_RXInt(void);
void UART_vid_Disable_RXInt(void);

//Enable and disable Transmit completed Interrupt
void UART_vid_Enable_TXInt(void);
void UART_vid_Disable_TXInt(void);

//Enable and disable Data Register Empty Interrupt
void UART_vid_Enable_DataEmptyInt(void);
void UART_vid_Disable_DataEmptyInt(void);

//set call back functions
void UART_voidSetCallBack(enum UART_INTERRUPT_TYPE Copy_InterruptType, void (*CallBack)(void) );


#endif /* UART_INT_H_ */
