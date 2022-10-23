/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: merro
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "Lcd_int.h"

int main (void)
{
	Lcd_vidInit();

	Lcd_vidWriteString("Muhammad Mahmoud");

	while (1);
	return 0;
}
