/*
 * MEEPROM_program.c
 *
 * Created: 6/29/2023 5:36:53 PM
 *  Author: mido9
 */ 
#include <avr/io.h>
#include <avr/delay.h>


void MEEPROM_write(unsigned int EAddress , unsigned char Data)
{
	while (EECR & (1<<EEWE));
	
	EEAR = EAddress;
	EEDR = Data;
	
	EECR |= (1<<EEMWE);
	EECR |= (EEWE);
}

unsigned char MEEPROM_read(unsigned int EAddress)
{
	while(EECR & (1<<EEWE));
	EEAR = EAddress;
	EECR |=(1<<EERE);
	
	return EEDR;
}