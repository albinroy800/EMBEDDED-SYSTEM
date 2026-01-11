/*
 * Traffic_signal_MOTOR.c
 *
 * Created: 14/12/2025 08:06:01
 * Author : user
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t interrupt_flag = 0;

ISR(INT0_vect)
{
	interrupt_flag = 1;
}

void red() {
	PORTB |= (1<<PB1);
	PORTB &= ~((1<<PB2) | (1<<PB3));
	_delay_ms(5000);
}

void yellow() {
	PORTB |= (1<<PB2);
	PORTB &= ~((1<<PB1) | (1<<PB3));
	_delay_ms(4000);
}

void green() {
	PORTB |= (1<<PB3);
	PORTB &= ~((1<<PB1) | (1<<PB2));
	_delay_ms(10000);
}

int main(void)
{
	DDRB |= (1<<DDB1)|(1<<DDB2)|(1<<DDB3);
	DDRC |= (1<<PC4) | (1<<PC5);
	DDRD &= ~((1<<PD2));
	PORTD |= (1<<PD2);

	EIMSK |= (1<<INT0);
	EICRA |= (1<<ISC01) | (1<<ISC00);  // rising edge
	sei();

	while (1)
	{
		red();
		yellow();
		green();

		if (interrupt_flag)
		{
			PORTC |= (1<<PC4);
			PORTC &= ~(1<<PC5);
			_delay_ms(5000);
			PORTC &= ~(1<<PC4);
			PORTC |= (1<<PC5);

			interrupt_flag = 0;
		}
	}
}