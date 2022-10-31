#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"ICU_interface.h"
#include"ICU_config.h"
#include"ICU_private.h"

void (*ICU_ptr)(void);
void __vector_6(void) __attribute__((signal,used));
void __vector_6(void)
{
	ICU_ptr();

}

void ICU_vidInit(void)
{
	#if ICU_TRIGGER==ICP1_PIN
	SET_BIT(ACSR,ACD);
	CLR_BIT(ACSR,ACIC);
	#elif ICU_TRIGGER==ANALOG_COMPARATER
	CLR_BIT(ACSR,ACD);
	CLR_BIT(ACSR,ACIC);
	#endif
	
	#if TIM1_MODE==NORMAL
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	#endif
	#if INPUT_NOISE_CANCELER==DISABLE
	CLR_BIT(TCCR1B,ICNC1);
	#elif INPUT_NOISE_CANCELER==ENSABLE
	SET_BIT(TCCR1B,ICNC1);
	#endif
	#if CLOCK_SELECT==NO_PRE
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	#elif CLOCK_SELECT==div_8
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	#elif CLOCK_SELECT==div_64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	#elif CLOCK_SELECT==div_256
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	#elif CLOCK_SELECT==div_1024
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	#endif
	
	CLR_BIT(TCCR1B,RESERVED);
}
void ICU_vidSetCallBack(void (*copy_ptr)(void))
{
	ICU_ptr=copy_ptr;
}

void ICU_VidEnableInterrupt(void)
{
	 SET_BIT(TIMSK,TICIE1);
}
void ICU_vidLatchEdge(u8 copy_u8Edge)
{
	switch(copy_u8Edge)
	{
		case FALLIN_EDGE:CLR_BIT(TCCR1B,ICES1);  break;
		case RISING_EDGE:SET_BIT(TCCR1B,ICES1);  break;
	}
}
u16 ICU_u16GetTimer()
{
	u16 Local_u16Result=0;
	Local_u16Result=TCNT1H;
	Local_u16Result=(Local_u16Result<<8)|TCNT1L;
	return Local_u16Result;
}


void ICU_vidGetProperties(u16* copy_Period ,u16* copy_DutyCycle , u16* copy_Frequency )
{
	u16 High ,first_trig,sec_trig,third_trig,local_period;
	u8 flag = 0 ;

	while(flag != 1)
	{
	TCNT1L = 0 ;
	TCNT1H = 0 ;
	SET_BIT(TIFR,5) ;
	ICU_vidLatchEdge(RISING_EDGE) ;

	while(GET_BIT(TIFR,5)==0) ;
	first_trig = ICR1L ;
	first_trig+=ICR1H *256;
	SET_BIT(TIFR,5) ;

	ICU_vidLatchEdge(FALLIN_EDGE) ;
	while(GET_BIT(TIFR,5)==0) ;
	sec_trig = ICR1L ;
	sec_trig+=ICR1H *256;
	SET_BIT(TIFR,5) ;


	ICU_vidLatchEdge(RISING_EDGE) ;
	while(GET_BIT(TIFR,5)==0) ;
	third_trig = ICR1L ;
	third_trig+=ICR1H *256;
	SET_BIT(TIFR,5) ;
	if(first_trig<sec_trig && sec_trig<third_trig)
	{
	High = sec_trig - first_trig ;
	local_period=(third_trig-first_trig);
	*copy_Frequency = (f32)F_CPU/(f32)local_period;
	*copy_Period=(1000000.0/ (f32)(*copy_Frequency));
	*copy_DutyCycle = ((f32)High/(f32)local_period)*100 ;
	flag = 1 ;
	}
	}

	flag = 0 ;
	/*
	else
	{
		*copy_Period=0 ;
	}
	*/
}
