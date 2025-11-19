/*
 * MOTOR.c
 *
 * Created: 19/11/2025 08:36:35
 * Author : user
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB|=(1<<DDB1) |(1<<DDB2);
	
	
	while (1)
	{PORTB |=(1<<PB1);
		PORTB&=~(1<<PB2);
		_delay_ms(5000);
		
		PORTB &=~(1<<PB1);
		PORTB &=~(1<<PB2);
		_delay_ms(5000);
		
		PORTB&=~(1<<PB1);
		PORTB|=(1<<PB2);
		_delay_ms(5000);
		
		PORTB &=~(1<<PB1);
		PORTB &=~(1<<PB2);
		_delay_ms(5000);
	}
}

