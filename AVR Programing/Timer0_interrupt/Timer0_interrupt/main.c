/*
 * Timer0_interrupt.c
 *
 * Created: 05/12/2025 08:43:10
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>

volatile uint16_t count=0;
ISR(TIMER0_OVF_vect)// over flow 
{
	if(count>977)
	{
		PORTB^=(1<<PB5);
		count=0;
	}
	else
	{
		count ++;
		
	}
}
int main(void)
{
	DDRB|=(1<<DDB5);
	
  sei();
  TCNT0=0;
  TCCR0A&=~(1<<WGM00)|(1<<WGM01);
  TCCR0B|=(1<< CS01)|(1<<CS00);
  TCCR0B&=~(1<<CS02);
  TIMSK0|=(1<<TOIE0);
  
    while (1) 
    {
		
    }
}

