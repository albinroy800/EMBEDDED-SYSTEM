/*
 * blink.c
 *
 * Created: 16/11/2025 06:35:47
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
DDRB=0b00100000;

	while (1)
	{PORTB=0b00100000;
	_delay_ms(3000);
	PORTB=0b00000000;
	_delay_ms(3000);
	
	}
}