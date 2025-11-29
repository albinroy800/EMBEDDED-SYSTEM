/*
 * Timer.1.c
 *
 * Created: 29/11/2025 09:55:36
 * Author : user
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	for (int i = 0; i < 61; i++)   
	{
		while (!(TIFR0 & (1<<TOV0)));  
		TIFR0 |= (1<<TOV0);            
	}
}

int main(void)
{
	TCNT0 = 0;                           
		TCCR0A &= ~((1<<WGM00) | (1<<WGM01)); 
	TCCR0B |= (1<<CS02) | (1<<CS00);    
	TCCR0B &= ~(1<<CS01);

	DDRB |= (1<<DDB5);                   

	while (1)
	{
		PORTB ^= (1<<PB5);              
		delay_1s();                      
	}
}

