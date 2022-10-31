#ifndef ICU_PRIVATE_H
#define ICU_PRIVATE_H

#define TCCR1B    *((volatile u8*)0x4E)
#define TCCR1A    *((volatile u8*)0x4f)
#define ACSR      *((volatile u8*)0x28)
#define ICR1H     *((volatile u8*)0x47)
#define ICR1L     *((volatile u8*)0x46)
#define TIMSK     *((volatile u8*)0x59)		
#define TCNT1L    *((volatile u8*)0x4C)
#define TCNT1H    *((volatile u8*)0x4D)
#define TIFR	  *((volatile u8*)0x58)


#define ICP1_PIN            0
#define ANALOG_COMPARATER   1 
#define NORMAL              1
#define ACD  				7
#define ACIC 				2
#define WGM10 				0 //bit 0 in TCCR1A
#define WGM11 				1 //bit 1 in TCCR1A
#define WGM12 				3 //bit 3 in TCCR1B
#define WGM13 				4 //bit 4 in TCCR1B
#define RESERVED 			5
#define ICNC1  				7
#define DISABLE  			0
#define ENSABLE  			1


#define div_8     0
#define div_64    1 
#define div_256   2
#define div_1024  3
#define NO_PRE    4

#define CS10  0
#define CS11  1
#define CS12  2

#define FALLIN_EDGE 0
#define RISING_EDGE 1
#define TICIE1 5
#define ICES1  6

#endif
