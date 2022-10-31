/************************************************/
/* Title       : INTERRUPT file				    */
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 22, 2021                   */
/************************************************/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define SREG_IBIT								7
#define SREG							*((volatile u8*)0x5F)

#define INT_ENABLE_GLOBAL_INT			(SET_BIT(SREG,SREG_IBIT))
#define INT_DISABLE_GLOBAL_INT			(CLR_BIT(SREG,SREG_IBIT))

#endif /* INTERRUPT_H_ */
