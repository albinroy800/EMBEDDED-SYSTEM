/*
 * PWM(motor).c
 *
 * Created: 01/12/2025 09:04:39
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>




int main(void)
{
	DDRD|=(1<<DDD6);
	DDRD|=(1<<DDD5);
	
	//phase correct
	
	TCCR0A|=(1<<WGM00);
	TCCR0A&=~(1<<WGM01);
	
	//non inverting
	
	TCCR0A|=(1<<COM0A1);
	TCCR0A&=~(1<<COM0A0);
	
	//presaclar

	TCCR0B&=~(1<<CS01);
	TCCR0B|=(1<<CS02)|(1<<CS00);


	while (1)
	
	{
		for( int i=0;i<=76;i++)
		{
			OCR0A=i;
			//_delay_ms(50);
		}
		
		
		/*for( int i=0;i>255;i--)
		{
			OCR0A=i;
			_delay_ms(20);
			
		}*/
	}
}

