/*
 * TRAFFIC Signal.c
 *
 * Created: 20/11/2025 08:46:20
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


     void red(){
		PORTB|= (1<<PB1);
		PORTB&=~(1<<PB2);
		PORTB&=~(1<<PB3);
		_delay_ms(5000);
	}
      void yellow(){
		 PORTB&=~(1<<PB1);
		 PORTB|=(1<<PB2);
		 PORTB&=~(1<<PB3);
		 _delay_ms(4000);
		 
	 }
	 
	  void green(){
		  PORTB&=~(1<<PB1);
		  PORTB&=~(1<<PB2);
		  PORTB|=(1<<PB3);
		  _delay_ms(10000);
	  }

int main(void){
	DDRB|=(1<<DDB1)|(1<<DDB2)|(1<<DDB3);
	
		  
    while (1){   
		red();
		yellow();
		green();
		
    }
}

