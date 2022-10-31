/************************************************/
/* Title       : ADC peripheral private file    */
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 23, 2021                   */
/************************************************/

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_


#define ADMUX						*((volatile u8*)0x27)
#define ADCSRA						*((volatile u8*)0x26)
#define SFIOR						*((volatile u8*)0x50)

#define ADCL						*((volatile u8*)0x24)
#define ADCH						*((volatile u8*)0x25)



#define ADC_AREF							0
#define ADC_AVCC							1
#define ADC_INTERNAL_VOL					3

#define ADC_8_BIT_RESOLUTION				1
#define ADC_10_BIT_RESOLUTION				0

#define ADC_2_PRESCALER						1
#define ADC_4_PRESCALER						2
#define ADC_8_PRESCALER						3
#define ADC_16_PRESCALER					4
#define ADC_32_PRESCALER					5
#define ADC_64_PRESCALER					6
#define ADC_128_PRESCALER					7

#endif /* ADC_PRIV_H_ */
