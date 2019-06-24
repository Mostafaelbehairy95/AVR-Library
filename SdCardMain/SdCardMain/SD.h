/*
 * SD.h
 *
 * Created: 6/11/2017 12:45:53 AM
 *  Author: elbehairy
 */ 

#define F_CPU 1600000UL

#ifndef SD_H_
#define SD_H_

#include "SPI.h"
#include "UART.h"


typedef enum{
	mask  = 64,
	cmd0  =	 0 | mask,// IDLE_STATE
	cmd1  =  1 | mask,//SEND_OP_COND  
	cmd8  =  8 | mask,//SEND_IF_COND	
	cmd9  =  9 | mask,//SEND_CSD 
	cmd10 = 10 | mask,//SEND_CID
	cmd12 = 12 | mask,//STOP_TRANSMISSION
	cmd16 = 16 | mask,//SET_BLOCKLEN
	cmd17 = 17 | mask,//READ_SINGLE_BLOCK
	cmd18 = 18 | mask,//READ_MULTIPLE_BLOCK
	cmd24 = 24 | mask,//WRITE_BLOCK
	cmd25 = 25 | mask,//WRITE_MULTIPLE_BLOCK
	cmd55 = 55 | mask,//
	cmd58 = 58 | mask,//READ_OCR
	cmd59 = 58 | mask,//CRC_ON_OFF	
}command;

void init_SD();
unsigned char sendCmd(unsigned char cmd, unsigned long arg);	






















#endif /* SD_H_ */