/*
 * SerialCommunication.c
 *
 * Created: 7/13/2018 5:21:38 PM
 *  Author: Nucleus
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

int main(void)
{
	uart_init();
	while(1){
			printInt(1253);
			printstr("\n");
			_delay_ms(1000);
	}
}