/*
 * Switch.c
 *
 * Created: 22/11/2025 08:51:05
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)


{ DDRB|=(1<<DDB2);
	DDRD&=~(1<<DDD2);

	
    while (1) 
	
    {
		if(PIND&&(1<<PD2))
		{
			
		PORTB|=(1<<PB2);	
    }
	else
	{ 
		PORTB&=~(1<<PB2);
		
	}
		
}
}