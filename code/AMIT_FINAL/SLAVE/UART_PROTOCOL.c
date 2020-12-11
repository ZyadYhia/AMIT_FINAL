/*
 * UART.c
 *
 * Created: 10/25/2020 2:26:05 PM
 *  Author: himal
 */
#include <avr/io.h>
#include <stdlib.h>
 
void UART_PROTOCOL_init(){
	/*
	  Initiating the UART and set the BaudRate
	*/
	UCSRB |= (1<<TXEN)|(1<<RXEN)|(1<<RXCIE);
	UBRRL  = 103;
}

void UART_PROTOCOL_send(char data){
	/*
	  sending the chars over UART
	*/
	while(!(UCSRA &(1<<UDRE)));//pooling while UDRE is ready
	UDR = data;
}

void UART_PROTOCOL_send_str(char*data){
	/*
	  sending strings over UART
	*/
	for(int i = 0 ; data[i]!= '\0' ;i++){
		UART_PROTOCOL_send(data[i]);
	}
}

void UART_PROTOCOL_send_num(int data){
	/*
	  Sending Numbers over UART
	*/
	char str[10];
	itoa(data,str,10);
	UART_PROTOCOL_send_str(str);
}
char UART_PROTOCOL_recieve(){
	/*
	  Receiving strings over SPI
	*/
	while(!(UCSRA&(1<<RXC)));//pooling until receiving complete
	return UDR;
}