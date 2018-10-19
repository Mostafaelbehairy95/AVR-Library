/*
 * RTC_Example.c
 *
 * Created: 10/11/2018 3:57:47 PM
 *  Author: Nucleus
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "RTC.h"
#include "UART.h"

char day[8][6] = {"Sun","Mon","Tues","Wed","Thu","Fri","Sat"};

int main(void)
{
	// Initial Section
	RTC_Init();
	uart_init();
	//
	RTC t;
	t.sec = 00;
	t.min = 28;
	t.hour = 40 + 20 +  5;// (0100 0000) First term for active 12 hour mode 
						  // (0010 0000)Second term for config AM = 0 or PM == 20 
						  // Third Term for Set Wanted hour
						  //Note I write First and second term with BCD style 
	t.weekDay = 6;
	t.date = 19;
	t.month = 10;
	t.year = 18;
	RTC_WriteDataTime(&t);

    while(1)
    {
		RTC_ReadDataTime(&t);
		// TIME
		printstr("TIME:");
		printInt(t.hour);
		printstr(":");
		printInt(t.min);
		printstr(":");
		printInt(t.sec);
		if(t.AmPm){
			printstr(" PM");
		}else{
			printstr(" AM");
		}
		printstr("\n");
		//Data
		printstr("Data");
		printInt(t.month);
		printstr("/");
		printInt(t.date);
		printstr("/");
		printInt(t.year+2000);
		printstr(" ");
		printstr(day[t.weekDay - 1]);
		printstr("\n******************");
		printstr("\n");
		_delay_ms(1000);
    }
}