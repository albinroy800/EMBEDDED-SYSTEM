/*
 * blink 2.1.c
 *
 * Created: 18/11/2025 09:24:06
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



void cw0(){
     PORTB |=(1<<PB1);
	PORTB&=~(1<<PB2);
	_delay_ms(5000);
}
void stp0(){
	PORTB &=~(1<<PB1);
	PORTB &=~(1<<PB2);
	_delay_ms(5000);
}

void ccw0(){
	PORTB&=~(1<<PB1);
	PORTB|=(1<<PB2);
	_delay_ms(5000);
}

	int main(void){
		DDRB|=(1<<DDB1)|(1<<DDB2);
		
		while(1){
			cw0();
			stp0();
			ccw0();
		}
	}



