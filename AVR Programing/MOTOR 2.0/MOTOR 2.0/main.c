/*
 * MOTOR 2.0.c
 *
 * Created: 22/11/2025 09:05:49
 * Author : user
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL

void rd(void)
{
	PORTC |= (1<<PC4);
	PORTC &= ~(1<<PC5);
}

void ld(void)
{
	PORTC &= ~(1<<PC4);
	PORTC |= (1<<PC5);
}

void nd(void)
{
	PORTC &= ~(1<<PC4);
	PORTC &= ~(1<<PC5);
}

int main(void)
{
	DDRC |= (1<<PC4) | (1<<PC5);        
	PORTD |= (1<<PD1) | (1<<PD2);       
	DDRD &= ~((1<<PD1) | (1<<PD2));     

	while (1)
	{
		if ((PIND & (1<<PD1)) && !(PIND & (1<<PD2)))
		{
			ld();
		}
		else if ((PIND & (1<<PD2)) && !(PIND & (1<<PD1)))
		{
			rd();
		}
		else
		{
			nd();
		}
	}
}