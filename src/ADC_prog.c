/************************************************/
/* Title       : ADC peripheral prog file       */
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 23, 2021                   */
/************************************************/

#include "BIT_math.h"
#include "STD_types.h"

#include "INTERRUPT.h"
#include "ADC_int.h"
#include "ADC_priv.h"
#include "ADC_config.h"

void ADC_vid_Initialize(void)
{
	ADMUX =0 ; 					// make sure it is cleared
	ADMUX |= ADC_VOLTAGE_REFERANCE<<6 ;
	ADMUX |= ADC_MODE <<5 ;		// if 8_bit_res LEFR ADJ will activate , if 10_bit_res RIGHT ADJ will activate
	ADCSRA &= ~(3) ; 			// clear first 3 bits
	ADCSRA |= ADC_PRESCALER ;
}

void ADC_vid_Enable(void)
{
	SET_BIT(ADCSRA,7) ;
}
void ADC_vid_Disable(void)
{
	CLR_BIT(ADCSRA,7) ;
}

u16 ADC_u16_Read(enum ADC_NO ADC_NUMBER)
{
	u16 result = 0 ;
	ADMUX &= 224 ;			   //clear first 5 bits
	ADMUX |= ADC_NUMBER ;
	SET_BIT(ADCSRA,6) ;

	while(GET_BIT(ADCSRA,4)==0);

	if (ADC_MODE == ADC_8_BIT_RESOLUTION)			//LEFT ADJ
	{
		result = ADCH;
	}

	else if (ADC_MODE == ADC_10_BIT_RESOLUTION)		//RIGHT ADJ
	{
		result = ADCL ;
		result += (ADCH*256) ;    					//we only need first 2 bit of ADCH
	}

	return result ;
}

