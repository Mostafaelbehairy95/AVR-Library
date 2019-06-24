/*
 * SDimp.c
 *
 * Created: 6/11/2017 12:46:13 AM
 *  Author: elbehairy
 */ 

#include "SD.h"

void init_SD(){
	unsigned char res;
	char test[20];
	int c = 0;
	init_uart(9600);
	init_spiMaster();
	for(int i = 0; i < 10; i ++){
		Transmit(0xff);
	}

	do 
	{
		res = sendCmd(0x40,0);
		if(c ++ > 8){
			printstr("Breakinit\n");
			return 1;
		}			


	} while (res != 0x01);
	sprintf(test, "%02X", res);
	printstr(test);
	return res;
}


unsigned char sendCmd(unsigned char cmd, unsigned long arg){
	unsigned char res;
	int count = 0;
	PORTB &= ~(1 << PORTB1);
	Transmit(cmd);
	Transmit(arg >> 24);
	Transmit(arg >> 16);
	Transmit(arg >> 8);
	Transmit(arg);
	Transmit(0x95); // CRC
	
	while((res = Receive()) == 0xff){
		count ++;
		if(count  > 8){
			break;
		}			
	}
	
	Receive();	
	PORTB |= (1 << PORTB1);
	return res;	
}