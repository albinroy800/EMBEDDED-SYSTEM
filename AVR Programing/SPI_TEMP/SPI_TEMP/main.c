/*
 * SPI_TEMP.c
 *
 * Created: 09/01/2026 21:09:27
 * Author : user
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main(void)
{
	UART_Init();
	uint8_t chip_id,msb,lsb,xlsb;
	uint32_t temp;
	DDRB|=(1<<DDB3)|(1<<DDB5)|(1<<DDB2); // MOSI, SCK AND CSB are configured as output
	DDRB&=~(1<<DDB4); //MISO is configured as input
	
	SPCR |= ((1 << SPE) |( 1 << MSTR) | (1 << SPR0));
	SPCR &= ~((1 << SPR1) |( 1 << CPHA) | (1 << CPOL));
	while (1)
	{
		PORTB&=~(1<<PB2); //Selecting slave
		SPDR= (0XD0|0X80); // Ensuring 1 on MSB (Reading)
		while (!(SPSR & (1<<SPIF))); // Waiting until flag is set
		(void)SPDR; // reading SPDR(for dummy garbage value)
		
		SPDR=0X00;    // Sending dummy to read the data from BMP280
		while (!(SPSR & (1<<SPIF)));//waiting until flag is set.
		chip_id = SPDR;   // reading chip ID
		
		PORTB|=(1<<PB2); // De selecting slave
		
		//Enabling measurement by writing 0x27 to 0xF4 register of bmp280
		
		PORTB&=~(1<<PB2); //Selecting slave
		SPDR= (0XF4&0X7F); // Ensuring 1 on MSB (Writing)
		while (!(SPSR & (1<<SPIF))); // Waiting until flag is set
		(void)SPDR; // reading SPDR(for dummy garbage value)
		
		SPDR=0X27;    // writing to F4 the data from BMP280
		while (!(SPSR & (1<<SPIF)));//waiting until flag is set.
		(void)SPDR;   // dummy reading
		PORTB|=(1<<PB2); // De selecting slave
		
		// Reading Data from 0xFA
		
		PORTB&=~(1<<PB2); //Selecting slave
		SPDR= (0XFA|0X80); // Ensuring 1 on MSB (Reading)
		while (!(SPSR & (1<<SPIF))); // Waiting until flag is set
		(void)SPDR; // reading SPDR(for dummy garbage value)
		
		SPDR=0X00;    // Sending dummy to read the data from BMP280
		while (!(SPSR & (1<<SPIF)));//waiting until flag is set.
		msb = SPDR;   // reading chip ID
		
		//Reading Data from 0XFB
		SPDR=0X00;    // Sending dummy to read the data from BMP280
		while (!(SPSR & (1<<SPIF)));//waiting until flag is set.
		lsb = SPDR;   // reading chip ID
		
		SPDR=0X00;    // Sending dummy to read the data from BMP280
		while (!(SPSR & (1<<SPIF)));//waiting until flag is set.
		xlsb = SPDR;   // reading chip ID
		
		temp = ((uint32_t)msb << 12) | ((uint32_t)lsb << 4) | ((uint32_t)xlsb >> 4);
		UART_TxNumber(temp);
		UART_TxChar('\n');
		_delay_ms(1000);
	}
}

