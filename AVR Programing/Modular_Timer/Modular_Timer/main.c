/*
 * Modular_Timer.c
 *
 * Created: 04/12/2025 08:52:15
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "delay.h" //user defined header file




int main(void)
{
   DDRB|=(1<<DDB5);
   timer0_init();
   
   
   
    while (1) 
    {
		PORTB^=(1<<PB5);
		delay_ms(3000);
    }
}

