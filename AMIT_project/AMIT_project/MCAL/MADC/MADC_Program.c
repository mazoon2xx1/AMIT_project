/*
 * MADC_Program.c
 *
 * Created: 5/26/2023 8:21:47 AM
 *  Author: mido9
 */ 
#include <util/delay.h>
#include <avr/io.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "MADC_interface.h"

void init_ADC(void)
{
	ADMUX  |= (1<<REFS0);   //voltage reference from internal (REFS1(bit no. 7) ,, REFS0(bit no. 6))
	ADCSRA |= (1<<ADEN);    // turn on ADC (bit no. 7)
	ADCSRA |= (1<<ADSC);
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));  //8MHZ/128 = 62,500HZ the ADC reference clock
}
uint16_t ADC_read(int channel)
{
	int Ain;
	int Ainlow;
	ADMUX &= 0xF0;                    // clear the older channel that was read
	ADMUX |= channel;                // Defines the new ADC channel to be read
	ADCSRA |= (1<<ADSC);            //start a new conversion (single conversion)
	while((ADCSRA&(1<<ADSC))==1);   //wait until the conversion is done
	_delay_ms(10);
	Ainlow = (int) ADCL;
	Ain = (int)ADCH*256;
	Ain = Ain + Ainlow;
	return Ain;
	
}
