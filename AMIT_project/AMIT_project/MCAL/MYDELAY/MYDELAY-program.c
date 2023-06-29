/*
 * MYDELAY_program.c
 *
 * Created: 6/29/2023 2:38:58 PM
 *  Author: mido9
 */ 

#include <xc.h>
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
void myDelay (long int x)
{
	TCCR1B = (1<<CS10) | (1<<CS12); //set the pre_scaler as 1024
	OCR1A = (65536*x)/8;
	TCNT1 =0;
	while(!(TIFR & (1<<OCF1A)));
	TCNT1 = 0;
	TIFR |= (1<<OCF1A); //clear timer1 overflow flag
}
