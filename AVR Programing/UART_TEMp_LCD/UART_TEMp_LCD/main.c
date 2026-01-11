/*
 * UART_TEMp_LCD.c
 *
 * Created: 06/01/2026 14:17:14
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "lcd.h"

void ADC_init(void) {
	ADMUX |= (1<<REFS0); // AVcc reference
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // Enable ADC, prescaler 128
}

uint16_t ADC_read(uint8_t channel) {
	channel &= 0x07; // limit to 0–7
	ADMUX = (ADMUX & 0xF0) | channel; // select channel
	ADCSRA |= (1<<ADSC); // start conversion
	while (ADCSRA & (1<<ADSC)); // wait until done
	return (ADCL | (ADCH << 8)); // return 10-bit result
}

void UART_init(void) {
	UBRR0H = 0;
	UBRR0L = 103; // Baud rate 9600 for 16 MHz
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00); // 8-bit data
	UCSR0B |= (1<<TXEN0); // Enable transmitter
}

void UART_transmit(char data) {
	while (!(UCSR0A & (1<<UDRE0))); // Wait until buffer empty
	UDR0 = data;
}

void UART_print(const char *str) {
	while (*str) {
		UART_transmit(*str++);
	}
}

void UART_print_number(int num) {
	char buffer[10];
	int i = 0;

	if (num == 0) {
		UART_transmit('0');
		return;
	}

	if (num < 0) {
		UART_transmit('-');
		num = -num;
	}

	while (num > 0) {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (i > 0) {
		UART_transmit(buffer[--i]);
	}
}

int main(void) {
	uint16_t adc_value;
	float temp;

	lcd_init();
	ADC_init();
	UART_init();

	while (1) {
		adc_value = ADC_read(0); // read channel 0
		temp = adc_value * 0.488; // LM35 conversion

		// LCD output
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_print("Temperature :");
		lcd_set_cursor(1,0);
		lcd_print_float(temp);
		lcd_data(0xDF); // degree symbol
		lcd_print("C");

		// UART output (manual float print)
		int whole = (int)temp;                // integer part
		int decimal = (int)((temp - whole)*10); // one decimal place

		UART_print("Temperature: ");
		UART_print_number(whole);
		UART_transmit('.');
		UART_print_number(decimal);
		UART_print(" C\r\n");

		_delay_ms(500);
	}
}