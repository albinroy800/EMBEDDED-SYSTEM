/*
 * GccApplication1.c
 *
 * Created: 01/01/2026 18:05:51
 * Author : user
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
	char a='A';
	UBRR0H=0;
	UBRR0L=103;                                 //SET BAND RATE TO 9600
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);              //  BIT MODE
	UCSR0C&=~((1<<UPM01)|(1<<UPM00)|(1<<USBS0));  // NO PARITY AND 1 STOP BIT
	UCSR0B|=(1<<TXEN0);                            // ENABLE TRANSMITTER 


  
    while (1) 
    {
		UDR0= a;
		while(!(UCSR0A&(1<<UDRE0)));
		_delay_ms(1000);
				
		
		
    }


}