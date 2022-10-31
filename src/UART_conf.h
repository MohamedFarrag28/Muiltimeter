/************************************************/
/* Title       : UART  config file 				*/
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 29, 2021                   */
/************************************************/
#ifndef UART_CONF_H_
#define UART_CONF_H_


#define UART_CPU_CLOCK			8000000UL
#define UART_BAUD_RATE			9600


/*
 * Options:	UART_FULL_DUPLEX
 *			UART_HALF_DUPLEX_TRANSMIT
 *			UART_HALF_DUPLEX_RECIEVE
*/
#define UART_STATE				UART_FULL_DUPLEX


/*
 * Options:	UART_ASYNCHRONOUS
 *			UART_SYNCHRONOUS
*/
#define UART_MODE				UART_ASYNCHRONOUS



/*
 * Options:	UART_5_BITS
 *			UART_6_BITS
 *			UART_7_BITS
 *			UART_8_BITS
 *			UART_9_BITS
*/
#define UART_DSIZE				UART_8_BITS



/*
 * Options:	UART_NO_PARITY
 *			UART_EVEN_PARITY
 *			UART_ODD_PARITY
*/
#define UART_PARITY_T			UART_NO_PARITY




/*
 * Options:	UART_ONE_BIT
 *			UART_TWO_BITS
*/
#define UART_STOPBIT_T			UART_ONE_BIT


/*
 * Options:
 * 			For UART_SYNCHRONOUS :
 * 								UART_RISING_EDGE
 *								UART_FALLING_EDGE
 *			For UART_ASYNCHRONOUS :
 *								UART_DISABLE
*/
#define UART_CLK_POLARITY		UART_DISABLE
#endif /* UART_CONF_H_ */
