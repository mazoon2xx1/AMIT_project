/*
 * H7segment_interface.h
 *
 * Created: 6/25/2023 12:25:43 PM
 *  Author: mido9
 */ 


#ifndef H7SEGMENT-INTERFACE_H_
#define H7SEGMENT-INTERFACE_H_
//********************************************

void H7sgment_init();
void H7segment_write_number(int enable ,int number);
void H7segment_Enable_left();
void H7segment_Disable_left();
void H7segment_Enable_right();
void H7segment_Disable_right();
void H7segment_operation(uint16_t number);



#endif /* H7SEGMENT-INTERFACE_H_ */