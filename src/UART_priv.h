/************************************************/
/* Title       : UART  private file 			*/
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 29, 2021                   */
/************************************************/

#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define		UDR									*((volatile u8*)0x2C)
#define		UCSRA								*((volatile u8*)0x2B)
#define		UCSRB								*((volatile u8*)0x2A)
#define		UCSRC								*((volatile u8*)0x40)
#define		UBRRH								*((volatile u8*)0x40)
#define		UBRRL								*((volatile u8*)0x29)


#define UART_VECTOR_ISR_COMP_RX					__vector_13
#define UART_VECTOR_ISR_DATA_EMBTY				__vector_14
#define UART_VECTOR_ISR_COMP_TX					__vector_15

void UART_VECTOR_ISR_COMP_RX()__attribute__((signal,used)) ;
void UART_VECTOR_ISR_DATA_EMBTY() __attribute__((signal,used));
void UART_VECTOR_ISR_COMP_TX() __attribute__((signal,used));


void (* PUART_vid_CallBacks[3])(void) = {0,0,0};



//  UART_STATE{UART_F_DUPLEX,UART_H_DUPLEX_TRANSMIT,UART_H_DUPLEX_RECIEVE}

#define UART_HALF_DUPLEX_TRANSMIT		1
#define UART_HALF_DUPLEX_RECIEVE		2
#define UART_FULL_DUPLEX				3

//	 UART_MODE{UART_ASYNCHRONOUS,UART_SYNCHRONOUS}
#define	UART_ASYNCHRONOUS				0
#define	UART_SYNCHRONOUS				1


//	 UART_DATA_SIZE{UART_5BIT,UART_6BIT,UART_7BIT,UART_8BIT,UART_9BIT};
#define	UART_5_BITS						0
#define	UART_6_BITS						1
#define UART_7_BITS						2
#define	UART_8_BITS						3
#define	UART_9_BITS						7


// UART_PARITY_TYPE{UART_NO_PARITY,UART_EVEN_PARITY,UART_ODD_PARITY};
#define	UART_NO_PARITY					0
#define	UART_EVEN_PARITY				2
#define	UART_ODD_PARITY					3

//  UART_STOPBIT_T{UART_ONE_BIT,UART_TWO_BIT}
#define	UART_ONE_BIT					0
#define	UART_TWO_BITS					1


// UART_CLK_POLARITY{UART_RISING_EDGE,UART_FALLING_EDGE,UART_DISABLE}
#define UART_RISING_EDGE				0
#define UART_FALLING_EDGE				1
#define UART_DISABLE					0

#endif /* UART_PRIV_H_ */
