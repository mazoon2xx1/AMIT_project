/*
 * MEEPROM_interface.h
 *
 * Created: 6/29/2023 5:36:36 PM
 *  Author: mido9
 */ 


#ifndef MEEPROM-INTERFACE_H_
#define MEEPROM-INTERFACE_H_

void MEEPROM_write(unsigned int EAddress , unsigned char Data);
unsigned char MEEPROM_read(unsigned int EAddress);




#endif /* MEEPROM-INTERFACE_H_ */