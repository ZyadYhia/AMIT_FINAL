/*
 * UART.c
 *
 * Created: 10/25/2020 2:26:05 PM
 *  Author: himal
 */
#include <avr/io.h>
#include <stdlib.h>
 
void UART_PROTOCOL_init(){
	UCSRB |= (1<<TXEN)|(1<<RXEN)|(1<<RXCIE);
	UBRRL  = 103;
}

void UART_PROTOCOL_send(char data){
	while(!(UCSRA &(1<<UDRE)));
	UDR = data;
}

void UART_PROTOCOL_send_str(char*data){
	for(int i = 0 ; data[i]!= '\0' ;i++){
		UART_send(data[i]);
	}
}

void UART_PROTOCOL_send_num(int data){
	char str[10];
	itoa(data,str,10);
	UART_send_str(str);
}
char UART_PROTOCOL_recieve(){
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}