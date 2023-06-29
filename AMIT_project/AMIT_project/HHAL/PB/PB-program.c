/*
 * PB_program.c
 *
 * Created: 6/25/2023 1:09:05 PM
 *  Author: mido9
 */ 

#include <avr/io.h>
#include <avr/delay.h>


void PB_init()
{
	DDRC = 0b00000000;
	
}