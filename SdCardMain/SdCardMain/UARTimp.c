/*
 * UARTimp.c
 *
 * Created: 2/22/2017 7:01:45 PM
 *  Author: elbehairy
 */ 

#include "UART.h"

void init_uart(int baud){
	int baud_Rate = (F_CPU/(16UL*baud)-1);
	UBRR0H = (baud_Rate >> 8);
	UBRR0L = baud_Rate;
	UCSR0B |=(1 << RXEN0)|(1 << TXEN0);
	UCSR0C |=(1<<USBS0)|(3<<UCSZ00);
}

void uart_transmit(unsigned char data){
	while(!(UCSR0A & ( 1 << UDRE0)));
	UDR0 = data;
}
void printstr(unsigned char * str){
	for(int i = 0; i < strlen(str); i ++){
		uart_transmit(str[i]);
	}
}
void printInt(int integer){
	char num[16];
	itoa(integer,num,10);
	printstr(num);
}

bool avaliable_Uartdata(){
	return (UCSR0A & ( 1 << RXC0));
}
unsigned  char uart_receive(){
	return UDR0;
}