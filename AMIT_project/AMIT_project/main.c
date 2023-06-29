/*
 * main.c
 *
 * Created: 6/25/2023 11:50:51 AM
 *  Author: mido9
 */ 

#include <xc.h>
#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 8000000UL
#include "HHAL/H7segment/H7segment-interface.h"
#include "HHAL/PB/PB-interface.h"
#include "MCAL/MEEPROM/MEEPROM-interface.h"


int main(void)
{
	DDRA &= ~(1<<0);
	DDRB = 0xff;
	int temp = 60;
	int button = 0;
	int flag;
	double voltage;
	double temperature;
	int _temperature;
	int average_cel =0;
	char first_num;
	char sec_num;
	int right_n;
	int left_n;
	
	PB_init();
    init_ADC();
	H7sgment_init(); 
    while(1)
    {
		
			if (PINC&(1<<2))
			{
				while(PINC&(1<<2));
				button =1;
				flag =0;
			}
		if ((flag == 0) & (button ==1))
		
		{
	
			for (int i=0; i<10 ;i++)
			{
				voltage = (ADC_read(0)/2)*76;
				_temperature = (((int)voltage)/84)-1;
				average_cel += _temperature;
				_delay_ms(25);
			}
			average_cel /=10;
			H7segment_operation(average_cel);
			
			if ((PINC&(1<<0))|(PINC&(1<<1)))
			{
				if(PINC & (1<<0))
				{
					while( PINC&(1<<0));
					temp+=5;
				}
				else if(PINC&(1<<1))
				{
					while(PINC&(1<<1));
					temp -=5;
				}
				if ((temp>=35)&&(temp<=75))
				{
					for(int i=0 ; i<5 ; i++)
					{
						H7segment_operation(temp);
						_delay_ms(1000);            //1000
				}
			}
				}
			
			if (average_cel < temp-5)
			{
				PORTB |= (1<<0);
				PORTB &= ~(1<<2); 
				PORTB ^= (1<<1);
				_delay_ms(25);     //1000
				                 
			}
			else if (average_cel==temp)
			{
				PORTB &= ~(1<<1);
			}
			else if (average_cel > temp+5)
			{
				PORTB &= ~(1<<0);
				PORTB |= (1<<2);
				PORTB |= (1<<1);
			}
						//first_num = MEEPROM_read(0x00) - '0';
						//sec_num = MEEPROM_read(0x01) - '0';
						//temp = (first_num * 10) + sec_num;
			if ((PINC&(1<<2)))
			{
				while(PINC&(1<<2));
				DDRD = 0x00;
				button = 0;
				flag = 1;
				
					right_n = temp%10;
					left_n = temp/10;
				MEEPROM_write(0x00 ,(left_n+'0'));
				MEEPROM_write(0x01 ,(right_n+'0'));
	
			}
		}
		
    }
	
	
	return 0;
}