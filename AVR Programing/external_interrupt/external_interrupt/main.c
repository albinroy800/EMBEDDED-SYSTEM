/*
 * external_interrupt.c
 *
 * Created: 07/12/2025 08:18:49
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect)
{
	PORTB^=(1<<PB5);
	_delay_ms(10000);
}

int main(void)
{
   sei();
   EIFR|=(1<<INTF0);//CLEAR INTERRUPT FLAG INTIALLY
   DDRD&=~(1<<PD2);
   
   DDRB|=(1<<DDB5);
  EIMSK|=(1<<INT0);
  EICRA|=(1<<ISC00)|(1<<ISC01);
   
    while (1) 
    {
		PORTB|=(1<<PB5);
		PORTB&=~(1<<PB4);
		_delay_ms(1000);
    }
}

