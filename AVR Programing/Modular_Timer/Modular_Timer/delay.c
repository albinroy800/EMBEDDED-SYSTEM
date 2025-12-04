/*
 * delay.c
 *
 * Created: 04/12/2025 08:57:31
 *  Author: user
 */ 
#include <avr/io.h>
#include "delay.h"

void timer0_init(void)
{
	TCNT0=0;
	OCR0A=259;
	//CTC MODE
	TCCR0A=(1<<WGM01);
	TCCR0A&=~(1<<WGM00);
	TCCR0B|=(1<<CS00)|(1<<CS01);
	TCCR0B&=~(1<<CS02);
	
}
void delay_ms(uint16_t ms)
{

	while(ms--)
{
	while(!(TIFR0&(1<<OCF0A)));
	TIFR0|=(1<<OCF0A);
	
}
}