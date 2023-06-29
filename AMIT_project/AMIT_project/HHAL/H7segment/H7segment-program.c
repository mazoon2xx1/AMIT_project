/*
 * H7segment_program.c
 *
 * Created: 6/25/2023 12:25:21 PM
 *  Author: mido9
 */ 

#include <avr/io.h>
#include <avr/delay.h>

void H7sgment_init()
{
	DDRD = 0b00001111;
	DDRB = 0xff;
}
void H7segment_write_number(int number)
{
	switch (number)
	{
		case 0:
		PORTD = 0b00111111;
		break;
		
		case 1:
		PORTD = 0b00000110;
		break;
		
		case 2:
		PORTD = 0b11011011;
		break;
		
		case 3:
		PORTD = 0b11001111;
		break;
		
		case 4:
		PORTD = 0b01100110;
		break;
		
		case 5:
		PORTD = 0b01101101;
		break;
		
		case 6:
		PORTD = 0b01111101;
		break;
		
		case 7:
		PORTD = 0b00000111;
		break;
		
		case 8:
		PORTD = 0b01111111;
		break;
		
		case 9:
		PORTD = 0b01100111;
		break;	
	}
}

void H7segment_Enable_left()
{PORTB &= ~(1<<6);}
	
void H7segment_Disable_left()
{PORTB |= (1<<6);}
	
void H7segment_Enable_right()
{PORTB &= ~(1<<7);}
	
void H7segment_Disable_right()
{PORTB |= (1<<7);}
	
void H7segment_operation(uint16_t number)
{
	int right_num;
	int left_num;
		right_num = number%10;
		left_num = number/10;
		H7segment_write_number(left_num);
		H7segment_Enable_left();
		H7segment_Disable_right();
		_delay_ms(10);
		H7segment_Disable_left();
		H7segment_Disable_right();
		H7segment_write_number(right_num);
		H7segment_Enable_right();
		H7segment_Disable_left();
		_delay_ms(10);
		H7segment_Disable_right();
        H7segment_Disable_left();		
}

