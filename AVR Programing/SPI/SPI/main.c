/*
 * SPI.c
 *
 * Created: 07/01/2026 21:07:07
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

int main(void)
{
	UART_Init();
	uint8_t chip_id;

	DDRB |= (1<<DDB3) | (1<<DDB5) | (1<<DDB2); // MOSI, SCK, SS as output
	DDRB &= ~(1<<DDB4);                      // MISO as input

	SPCR |= (1<<SPE)| (1<<MSTR)|(1<<SPR0);
	SPCR &= ~(1<<SPR1);
	SPCR &= ~((1<<SPR1)|(1<<CPHA) | (1<<CPOL)); 

	while (1)
	{
		PORTB&= ~(1<<PB2);        // Select slave
		SPDR = 0xD0|0x80;        // Send register address with read bit
		while(!(SPSR & (1<<SPIF))); // Wait for transmission complete
		(void)SPDR;                // Dummy read
		
		SPDR = 0x00;               // Send dummy byte to receive data
		while(!(SPSR & (1<<SPIF))); // Wait for transmission complete
		chip_id = SPDR;            // Store received data
		UART_TxHex(chip_id);
		_delay_ms(1000);
        //PORTB |= (1<<PB2);         // Deselect slave

		
	}
}