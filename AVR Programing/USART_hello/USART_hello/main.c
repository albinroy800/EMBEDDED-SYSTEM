/*
 * USART_hello.c
 *
 * Created: 01/01/2026 18:57:13
 * Author : user
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
	char hello[5]="HELLO";
	uint8_t i;
	UBRR0H=0;
	UBRR0L=103;                                 //SET BAND RATE TO 9600
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);              //  BIT MODE
	UCSR0C&=~((1<<UPM01)|(1<<UPM00)|(1<<USBS0));  // NO PARITY AND 1 STOP BIT
	UCSR0B|=(1<<TXEN0);                            // ENABLE TRANSMITTER

    while (1)
    {
	    for (i = 0; i < 5; i++)
	    {
		    while (!(UCSR0A & (1<<UDRE0))); // wait For empty the Register
		    UDR0 =hello[i] ;                 //and sending the charters one by one
	    }
	    while (!(UCSR0A & (1<<UDRE0)));     // wait For empty the Register
	    UDR0 = '\n';                        // send newline
	    _delay_ms(1000);                    // delay 1 second
    }
}