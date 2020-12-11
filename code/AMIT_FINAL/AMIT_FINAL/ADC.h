/*
 * ADC.h
 *
 * Created: 10/19/2020 4:39:30 PM
 *  Author: himal
 */ 
#include <avr/io.h>

#ifndef ADC_H_
#define ADC_H_

void ADC_channel(int);
void ADC_refrence(int);
void ADC_freq(int);
int readADC(void);
void ADC_init(int,int,int);
void ADC_StartConv(void);
void waitConversion(void);


#endif /* ADC_H_ */