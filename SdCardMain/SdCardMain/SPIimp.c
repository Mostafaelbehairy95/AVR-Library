/*
 * SPIimp.c
 *
 * Created: 6/11/2017 12:46:45 AM
 *  Author: elbehairy
 */ 
#include "SPI.h"


void init_spiMaster(){
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0)| (1 << SPR1);	//SPE for enable SPi & MSTR for make AVR as master & SPR0 Make Prescaler 16
}

void init_spislave(){
	SPCR |= (1 << SPE); 
}

unsigned char Transmit(unsigned char data){
	
	SPDR = data;
	while(!SPSR & (1 << SPIF)); //Wait for flag SPIF Set
	return SPDR;
}
bool available_spiData(){
	return (SPSR & (1 << SPIF));
}
unsigned char Receive(){
	unsigned char data;
	SPDR = 0xff;
	while(!(SPSR & (1 << SPIF)));
	data = SPDR;
	return data;
}