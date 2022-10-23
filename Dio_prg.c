/*
 * Dio_prg.c
 *
 *  Created on: Aug 19, 2019
 *      Author: merro
 */

#include "Dio_int.h"
#include "Std_types.h"
#include "Bit_math.h"
#include <avr/io.h>
#define F_CPU 8000000

void Dio_vidSetPinDir(u8 Pin,u8 Dir)
{
	u8 Loc_u8Port ;
	u8 Loc_u8Pin ;
	Loc_u8Port=Pin/8 ;
	Loc_u8Pin=Pin%8 ;
	switch(Loc_u8Port)
	{
	case 0:
		if (Dir==1)
		{
			SET_BIT(DDRA,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(DDRA,Loc_u8Pin);
		}
		break ;
	case 1:
		if (Dir==1)
		{
			SET_BIT(DDRB,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(DDRB,Loc_u8Pin);
		}
		break ;
	case 2:
		if (Dir==1)
		{
			SET_BIT(DDRC,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(DDRC,Loc_u8Pin);
		}
		break ;
	case 3 :
		if (Dir==1)
		{
			SET_BIT(DDRD,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(DDRD,Loc_u8Pin);
		}
		break ;

	}
}
	void Dio_vidSetPinVal(u8 Pin,u8 Val)
	{
		u8 Loc_u8Port ;
		u8 Loc_u8Pin ;
		Loc_u8Port=Pin/8 ;
		Loc_u8Pin=Pin%8 ;
		switch(Loc_u8Port)
		{
		case 0:
			if (Val==1)
			{
				SET_BIT(PORTA,Loc_u8Pin);
			}
			else
			{
				CLEAR_BIT(PORTA,Loc_u8Pin);
			}
			break ;
		case 1:
			if (Val==1)
			{
				SET_BIT(PORTB,Loc_u8Pin);
			}
			else
			{
				CLEAR_BIT(PORTB,Loc_u8Pin);
			}
			break ;
		case 2:
			if (Val==1)
			{
				SET_BIT(PORTC,Loc_u8Pin);
			}
			else
			{
				CLEAR_BIT(PORTC,Loc_u8Pin);
			}
			break ;
		case 3 :
			if (Val==1)
			{
				SET_BIT(PORTD,Loc_u8Pin);
			}
			else
			{
				CLEAR_BIT(PORTD,Loc_u8Pin);
			}
			break ;




		}
	}
