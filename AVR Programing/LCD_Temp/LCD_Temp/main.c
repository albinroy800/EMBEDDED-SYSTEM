/*
 * LCD_Temp.c
 *
 * Created: 30/12/2025 08:42:43
 * Author :albin_roy
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "lcd.h"

void ADC_int(void)
{
	ADMUX|= (1<<REFS0); // 5V REF VOLTAGE
	ADCSRA|=(1<<ADEN) | (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);    // PRESCALAR 128
	
}
uint16_t ADC_read(uint8_t channel)
{
	channel&= 0x07; //channel limiting to 7
	ADMUX = (ADMUX&0XF0)|channel;// channel selection
	ADCSRA|=(1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return(ADCL|(ADCH<<8)); // left adjust	
}

int main(void)
{
   uint16_t adc_value;
   lcd_init();
   ADC_int();
 
    while (1) 
    {
		adc_value=ADC_read(0);
		float temp = adc_value *0.488; // converting the adc value tom temperature
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_print("Temperature :");
		lcd_set_cursor(1,0);
		lcd_print_float(temp);
		lcd_data(0xDF); // temp symbol
		lcd_print("C");
		_delay_ms(500);S			
    }
}

