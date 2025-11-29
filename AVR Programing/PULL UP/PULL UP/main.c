/*
 * PULL UP.c
 *
 * Created: 24/11/2025 08:49:31
 * Author : user
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
	DDRD&=~(1<<DDD1);
	PORTD |=(1<<PD1);
	DDRB|=(1<<DDB4);
	
while(1)
{
	if(!(PIND&(1<<PD1)))
	{
		PORTB|=(1<<PB4);
	
	}
	else
	{
		PORTB&=~(1<<PB4);
		
	}
}
}