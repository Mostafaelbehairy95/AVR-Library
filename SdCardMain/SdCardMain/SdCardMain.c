/*
 * SdCardMain.c
 *
 * Created: 6/11/2017 12:45:21 AM
 *  Author: elbehairy
 */ 

#include <avr/io.h>
#include "SD.h"
#include "UART.h"


int main(void)
{
	//initalization Pin;
	//SPI
	DDRB |= (1 << PORTB3) | (1 << PORTB1) | (1 << PORTB5); // make SCK and MOSI as output pin
	
	//////////////////////////////////////////////////////////
	//SD
	DDRB |= (1 << PORTB2);
	////////////////////////////////////////////////////////
	//Serial Communication <UART?	
	init_uart(9600);
	////////////////////////////////////////////////////////
	
	while(1){
		if(avaliable_Uartdata()){
			if(uart_receive() == 'i'){
				init_SD();
				printstr("Inilization Card\n");			
			}			
		}
	}		
		
}