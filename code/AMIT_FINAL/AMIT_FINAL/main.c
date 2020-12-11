/*
 * AMIT_FINAL.c
 *
 * Created: 11/20/2020 2:30:33 PM
 * Author : himal
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "UART_PROTOCOL.h"
#include "SPI_PROTOCOL.h"
#include "ADC.h"
#include "Timer0.h"


ISR(USART_RXC_vect){
	unsigned char data  =UDR;
	SPI_PROTOCOL_MASTER_send(data);
}

ISR(ADC_vect){ 
	int data = readADC() * 0.48875855327;
	if(data >= 30){ 
		SPI_PROTOCOL_MASTER_send_num(5);
	}else{
		SPI_PROTOCOL_MASTER_send_num(6);
	}
}

ISR(TIMER0_OVF_vect){
	static int n = 0;
	if(n % 61 == 0 && n != 0){
		ADC_StartConv();
	}
	n++;
}

int main(void)
{
    /* Replace with your application code */
	UART_PROTOCOL_init();
	SPI_PROTOCOL_init(SPI_PROTOCOL_MASTER);
	ADC_init(0,0,0);
	Timer0_init(Normal_mode ,Internal_1024,OC0_off,TOV_Interrupt);
	sei();
    while (1) 
    {
    }
}

