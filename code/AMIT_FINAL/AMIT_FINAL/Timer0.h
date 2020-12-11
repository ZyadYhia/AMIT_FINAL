/*
 * Timer0.h
 *
 * Created: 10/25/2020 2:14:39 PM
 *  Author: himal
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_


#define Timer_off         0
#define Internal_NO       1
#define Internal_8        2
#define Internal_64       3
#define Internal_256      4
#define Internal_1024     5
#define External_fall     6
#define External_rise     7


#define Normal_mode   0X00
#define PWM_PHASE     0X40
#define CTC           0x08
#define Fast_PWM      0x48


#define OC0_off           0
#define OC0_CTC_TOGGEL    1
#define OC0_CLEAR         2
#define OC0_SET           3


#define TOV_Interrupt      0
#define TOC_Interrupt      1
#define Timer0_Int_OFF     3

void Timer0_source(int);
void Timer0_mode(int);
void Timer0_Oc0(int);
void Timer0_InterruptEn(int);
void Timer0_init(int,int,int,int);


#endif /* TIMER0_H_ */