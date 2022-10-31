/************************************************/
/* Title       : ADC peripheral config file     */
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 23, 2021                   */
/************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

// 2 Options : ADC_8_BIT_RESOLUTION OR ADC_10_BIT_RESOLUTION
#define ADC_MODE						ADC_10_BIT_RESOLUTION

// 3 Options : ADC_AREF OR ADC_AVCC OR ADC_INTERNAL_VOL
#define ADC_VOLTAGE_REFERANCE			ADC_AVCC


#define ADC_PRESCALER					ADC_64_PRESCALER

#endif /* ADC_CONFIG_H_ */
