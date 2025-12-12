/*
 * Timer0_normal_mode.c
 *
 * Created: 12/12/2025 09:37:05
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL




void delay_1s(void)
{
	TCNT0=0;
	TCCR0A&=~(1<<WGM00)|(1<<WGM01);
	
	TCCR0B&=~(1<<CS01)|(1<<CS02);
	TCCR0B|=(1<<CS00);
	
	for(long int  i = 0; i<62500; i++)
	{
		while(!(TIFR0&(1<<TOV0)));
		TIFR0|=(1<<TOV0);
	}
	
}
int main (void)
{
	DDRB|=(1<<DDB5);
	
    while (1) 
    {
		PORTB^=(1<<PB5);
		delay_1s();
    }
}

