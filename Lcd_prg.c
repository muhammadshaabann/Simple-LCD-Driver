/*
 * Lcd_prg.c
 *
 *  Created on: Aug 23, 2019
 *      Author: merro
 */


#include "Dio_int.h"
#include "Std_types.h"
#include "Bit_math.h"
#define F_CPU 8000000
#include <util/delay.h>
#include"Lcd_cfg.h"
#include"Lcd_int.h"

void Lcd_vidInit(void)
{
	Dio_vidSetPinDir(LCD_u8D0,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D4,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D5,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D6,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D7,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RS,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RW,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8EN,DIO_u8OUTPUT);
	Lcd_vidSendCommand(0x38);
	_delay_ms(2);
	Lcd_vidSendCommand(0x0C);
	_delay_ms(2);
	Lcd_vidSendCommand(0x01);
	_delay_ms(2);
}
void Lcd_vidWriteChar(u8 Character)
{
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8D0,GET_BIT(Character,0));
	Dio_vidSetPinVal(LCD_u8D1,GET_BIT(Character,1));
	Dio_vidSetPinVal(LCD_u8D2,GET_BIT(Character,2));
	Dio_vidSetPinVal(LCD_u8D3,GET_BIT(Character,3));
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Character,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Character,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Character,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Character,7));
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);
}
void Lcd_vidSendCommand(u8 Cmd)
{
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8D0,GET_BIT(Cmd,0));
	Dio_vidSetPinVal(LCD_u8D1,GET_BIT(Cmd,1));
	Dio_vidSetPinVal(LCD_u8D2,GET_BIT(Cmd,2));
	Dio_vidSetPinVal(LCD_u8D3,GET_BIT(Cmd,3));
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Cmd,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Cmd,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Cmd,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Cmd,7));
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);
}
void Lcd_vidWriteString(u8 *ptr)
{
	u8 Lcd_Counter;
	for(Lcd_Counter=0;ptr[Lcd_Counter];Lcd_Counter++)
	{
		Lcd_vidWriteChar(ptr[Lcd_Counter]);
	}
}

void Lcd_vidGoTo(u8 Row,u8 Col)
{
	if (Col>=0 && Col<=15)
	{
	    if(Row==0)
	    {
		    	Lcd_vidSendCommand(Col+0x80);
	    }
	    else if (Row==1)
	    {
		    	Lcd_vidSendCommand(Col+0xC0);
	    }
	}
}
