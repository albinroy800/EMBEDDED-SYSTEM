/*
 * Interrupt_CTC.c
 *
 * Created: 06/12/2025 09:08:36
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
uint16_t count=0;

ISR(TIMER0_COMPA_vect)
{
	
	count++;
	if(count >= 1000)   
	{
		PORTB ^= (1<<PORTB5); 
		count = 0;            

	}
}

int main(void)
{
	DDRB|=(1<<DDB5);
	OCR0A=249;
	
	sei();
	TCNT0=0;
	TCCR0A&=~(1<<WGM00);//CTC Mode
	TCCR0A|=(1<<WGM01);
	TCCR0B|=(1<<CS00)|(1<<CS01);
	TCCR0B&=~(1<<CS02);
    TIMSK0 |= (1<<OCIE0A);
	
    while (1) 
    {
    }
}

