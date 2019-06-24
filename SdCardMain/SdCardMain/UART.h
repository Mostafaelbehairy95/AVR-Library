/*
 * UART.h
 *
 * Created: 2/22/2017 7:01:29 PM
 *  Author: elbehairy
 */ 
#define F_CPU 16000000UL


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>

void init_uart(int baud);

void uart_transmit(unsigned char data);
void printstr(unsigned char * str);
void printInt(int integer);
bool avaliable_Uartdata();
unsigned char uart_receive();


#endif /* UART_H_ */