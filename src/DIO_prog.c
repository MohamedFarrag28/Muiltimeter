/************************************************/
/* Title       : DIO peripheral program file    */
/* Author      : Mohamed Alaa                   */
/* Release     : 1.0                            */
/* Last Update : Aug 15, 2021                   */
/************************************************/
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_priv.h"


void DIO_vid_Init(void)
{
	DDRA = DIO_u8_PORTA_DIR;
	DDRB = DIO_u8_PORTB_DIR;
	DDRC = DIO_u8_PORTC_DIR;
	DDRD = DIO_u8_PORTD_DIR;
}


void DIO_vid_SetPinDirection(u8 Copy_u8_PinNo , u8 Copy_u8_Direction)
{
	u8 Port_no = Copy_u8_PinNo/8 ;            // getting port Number as 0->PORTA / 1->PORTB / 3->PORTC / 4->PORTD
	Copy_u8_PinNo = Copy_u8_PinNo%8 ;
	switch(Port_no)
	{
		case DIO_PORTA :				//PORTA
		if (Copy_u8_Direction == DIO_INPUT)		//input
		{
			CLR_BIT(DDRA,Copy_u8_PinNo);
		}
		else if (Copy_u8_Direction == DIO_OUTPUT)	// output
		{
			SET_BIT(DDRA,Copy_u8_PinNo);
		}
		else if(Copy_u8_Direction == DIO_INPUT_PULLUP)	//input pullup
		{
			CLR_BIT(DDRA,Copy_u8_PinNo);
			SET_BIT(PORTA,Copy_u8_PinNo);
		}
		break ;
		
		case DIO_PORTB :				//PORTB
		if (Copy_u8_Direction == DIO_INPUT)		//input
		{
			CLR_BIT(DDRB,Copy_u8_PinNo);
		}
		else if (Copy_u8_Direction == DIO_OUTPUT)	// output
		{
			SET_BIT(DDRB,Copy_u8_PinNo);
		}
		else if(Copy_u8_Direction == DIO_INPUT_PULLUP)	//input pullup
		{
			CLR_BIT(DDRB,Copy_u8_PinNo);
			SET_BIT(PORTB,Copy_u8_PinNo);
		}
		break ;
		
		case DIO_PORTC :				//PORTC
		if (Copy_u8_Direction == DIO_INPUT)		//input
		{
			CLR_BIT(DDRC,Copy_u8_PinNo);
		}
		else if (Copy_u8_Direction == DIO_OUTPUT)	// output
		{
			SET_BIT(DDRC,Copy_u8_PinNo);
		}
		else if(Copy_u8_Direction == DIO_INPUT_PULLUP)	//input pullup
		{
			CLR_BIT(DDRC,Copy_u8_PinNo);
			SET_BIT(PORTC,Copy_u8_PinNo);
		}
		break ;
		
		case DIO_PORTD :				//PORTD
		if (Copy_u8_Direction == DIO_INPUT)		//input
		{
			CLR_BIT(DDRD,Copy_u8_PinNo);
		}
		else if (Copy_u8_Direction == DIO_OUTPUT)	// output
		{
			SET_BIT(DDRD,Copy_u8_PinNo);
		}
		else if(Copy_u8_Direction == DIO_INPUT_PULLUP)	//input pullup
		{
			CLR_BIT(DDRD,Copy_u8_PinNo);
			SET_BIT(PORTD,Copy_u8_PinNo);
		}
		break ;
		
		default:
		return ;
		
	}
}

void DIO_vid_SetPortDirection(u8 Copy_u8_PortNo , u8 Copy_u8_Direction)
{
	switch(Copy_u8_PortNo)
	{
		case DIO_PORTA :				//PORTA
		if (Copy_u8_Direction == DIO_INPUT)		//input
		{
			DDRA = 0 ;
		}
		else if (Copy_u8_Direction == DIO_OUTPUT)	// output
		{
			DDRA = 255 ;
		}
		else if(Copy_u8_Direction == DIO_INPUT_PULLUP)	//input pullup
		{
			DDRA  = 0 ;
			PORTA = 255 ;
		}
		break;
		
		case DIO_PORTB :				//PORTB
		if (Copy_u8_Direction == DIO_INPUT)		//input
		{
			DDRB = 0 ;
		}
		else if (Copy_u8_Direction == DIO_OUTPUT)	// output
		{
			DDRB = 255 ;
		}
		else if(Copy_u8_Direction == DIO_INPUT_PULLUP)	//input pullup
		{
			DDRB  = 0 ;
			PORTB = 255 ;
		}
		break;
		
		case DIO_PORTC :				//PORTC
		if (Copy_u8_Direction == DIO_INPUT)		//input
		{
			DDRC = 0 ;
		}
		else if (Copy_u8_Direction == DIO_OUTPUT)	// output
		{
			DDRC = 255 ;
		}
		else if(Copy_u8_Direction == DIO_INPUT_PULLUP)	//input pullup
		{
			DDRC  = 0 ;
			PORTC = 255 ;
		}
		break;
		case DIO_PORTD :				//PORTD
		if (Copy_u8_Direction == DIO_INPUT)		//input
		{
			DDRD = 0 ;
		}
		else if (Copy_u8_Direction == DIO_OUTPUT)	// output
		{
			DDRD = 255 ;
		}
		else if(Copy_u8_Direction == DIO_INPUT_PULLUP)	//input pullup
		{
			DDRD  = 0 ;
			PORTD = 255 ;
		}
		break ;
		
		default :
		return  ;
	}
	
}

void DIO_vid_SetPinValue(u8 Copy_u8_PinNo , u8 Copy_u8_PinValue)
{
	u8 Port_no = Copy_u8_PinNo/8 ;            // getting port Number as 0->PORTA / 1->PORTB / 3->PORTC / 4->PORTD
	Copy_u8_PinNo = Copy_u8_PinNo%8 ;
	
	switch(Port_no)
	{
		case DIO_PORTA :				//PORTA
		if(Copy_u8_PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTA,Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8_LOW)
		{
			CLR_BIT(PORTA,Copy_u8_PinNo);
		}
		break ;
		
		case DIO_PORTB :				//PORTB
		if(Copy_u8_PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTB,Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8_LOW)
		{
			CLR_BIT(PORTB,Copy_u8_PinNo);
		}
		break ;
		
		case DIO_PORTC :				//PORTC
		if(Copy_u8_PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTC,Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8_LOW)
		{
			CLR_BIT(PORTC,Copy_u8_PinNo);
		}
		break ;
		
		case DIO_PORTD :				//PORTD
		if(Copy_u8_PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTD,Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8_LOW)
		{
			CLR_BIT(PORTD,Copy_u8_PinNo);
		}
		break ;
		
		default:
		return ;
		
	}
}

void DIO_vid_SetPortValue(u8 Copy_u8_PortNo , u8 Copy_u8_PortValue)
{
	switch(Copy_u8_PortNo)
	{
		case DIO_PORTA :
		PORTA = Copy_u8_PortValue ;
		break ;
		
		case DIO_PORTB :
		PORTB = Copy_u8_PortValue ;
		break;
		
		case DIO_PORTC:
		PORTC = Copy_u8_PortValue ;
		break;
		
		case DIO_PORTD :
		PORTD = Copy_u8_PortValue ;
		break ;
	}
}


u8 DIO_u8_GetPinValue(u8 Copy_u8_PinNo)
{
	u8 Port_no = Copy_u8_PinNo/8 ;            // getting port Number as 0->PORTA / 1->PORTB / 3->PORTC / 4->PORTD
	Copy_u8_PinNo = Copy_u8_PinNo%8 ;
	
	switch(Port_no)
	{
		case DIO_PORTA :				//PORTA
		return (u8)(GET_BIT(PINA,Copy_u8_PinNo)) ;
		
		case DIO_PORTB :				//PORTB
		return (u8)(GET_BIT(PINB,Copy_u8_PinNo)) ;
		
		case DIO_PORTC :				//PORTC
		return (u8)(GET_BIT(PINC,Copy_u8_PinNo)) ;
		
		case DIO_PORTD :				//PORTD
		return (u8)(GET_BIT(PIND,Copy_u8_PinNo)) ;
		
		default :
		return 0 ;
		
	}
	
}

u8 DIO_u8_GetPortValue(u8 Copy_u8_PortNo)
{
	switch(Copy_u8_PortNo)
	{
		case DIO_PORTA :				//PORTA
		return PINA ;
		
		case DIO_PORTB :				//PORTB
		return PINB ;
		
		case DIO_PORTC :				//PORTC
		return PINC ;
		
		case DIO_PORTD :				//PORTD
		return PIND ;
		
		default :
		return 0 ;
	}
}

