/*
 * SPI.h
 *
 * Created: 6/11/2017 12:47:01 AM
 *  Author: elbehairy
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef SPI_H_
#define SPI_H_

#include <stdbool.h>
#include <avr/io.h>


void init_spiMaster();
void init_spislave();
unsigned char Transmit(unsigned char data);
bool available_spiData();
unsigned char Receive();



#endif /* SPI_H_ */