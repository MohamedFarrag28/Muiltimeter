/************************************************/
/* Title       : ADC peripheral interface file 	*/
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 23, 2021                   */
/************************************************/

#ifndef ADC_INT_H_
#define ADC_INT_H_


enum ADC_NO{ADC_0,ADC_1,ADC_2,ADC_3,ADC_4,ADC_5,ADC_6,ADC_7} ;


void ADC_vid_Initialize(void) ;
void ADC_vid_Enable(void);
void ADC_vid_Disable(void);
u16 ADC_u16_Read(enum ADC_NO ADC_NUMBER);

#endif /* ADC_INT_H_ */
