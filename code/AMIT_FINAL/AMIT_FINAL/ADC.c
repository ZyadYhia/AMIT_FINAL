/*
 * ADC.c
 *
 * Created: 10/19/2020 4:40:28 PM
 *  Author: himal
 */ 
#include "ADC.h"
#include <avr/io.h>


void ADC_channel(int channel){
	if(channel < 8) ADMUX =(ADMUX & 0xE0) | channel;
}
void ADC_refrence(int ref){
	ADMUX = (ADMUX & 0x3F) | (ref<<6);
}
void ADC_freq(int prescaler){
	if(ADCSRA & (1<<ADIE)){
		ADCSRA &= ~(1<<ADIE);
		ADCSRA  =  (ADCSRA & 0xF8)|prescaler;
		ADCSRA |= (1<<ADIE);
	}else{
		ADCSRA  =  (ADCSRA & 0xF8)|prescaler;
	}
}
void ADC_init(int ch,int ref,int presc){
	ADC_channel(ch);
	ADC_refrence(ref);
	ADC_freq(presc);
	ADCSRA |= (1<<ADIE);
	ADCSRA |= (1<<ADEN);
}
void ADC_StartConv(void){
	ADCSRA |= (1<<ADSC);
}
int readADC(void){
	int val  = ADCL;
	val |= (ADCH << 8);
	return val;
}

void waitConversion(void){
	while(ADCSRA & (1<<ADIF)); 
}
