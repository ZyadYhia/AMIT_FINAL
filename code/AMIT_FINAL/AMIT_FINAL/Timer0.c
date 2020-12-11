/*
 * Timer0.c
 *
 * Created: 10/25/2020 2:16:07 PM
 *  Author: himal
 */
#include <avr/io.h>
#include "Timer0.h"
 
void Timer0_source(int clk){
	/*
	 Choose the clock source
	*/
	TCCR0 |= clk;
}
void Timer0_mode(int mode){
	/*
	  Chooses the mode
	*/
	TCCR0 |= (mode<<3);
}
void Timer0_Oc0(int mode){
	DDRB |=(1<<3);
	TCCR0 |= (mode<<4);
}
void Timer0_InterruptEn(int Timer_Interrupt)
{
	/*
	  Enable and Choose the interrupt or Disable it
	*/
	if(Timer_Interrupt == Timer0_Int_OFF)
	{
		TIMSK &= ~((1<<0)|(1<<1));
	}
	else
	{
		TIMSK |= (1<<Timer_Interrupt);

	}
	
}
void Timer0_dutyCycle(int duty){
	/*
	  Determine the duty cycle
	*/
	OCR0 = 2.55 * duty;
}

void Timer0_init(int mode,int clk,int oc0_mode,int interrupt){
	Timer0_mode(mode);
	Timer0_Oc0(oc0_mode);
	Timer0_dutyCycle(50);
	Timer0_InterruptEn(interrupt);
	Timer0_source(clk);
	
}