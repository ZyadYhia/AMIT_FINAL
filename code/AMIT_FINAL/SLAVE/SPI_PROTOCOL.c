/*
 * SPI.c
 *
 * Created: 10/30/2020 1:54:26 PM
 *  Author: himal
 */
#include <avr/io.h>
#include <stdlib.h>
#include "SPI_PROTOCOL.h"
 
void SPI_PROTOCOL_init(int mode){
	/*
	This function init the SPI Either in master or slave mode
	*/
	if(mode == SPI_PROTOCOL_MASTER){
		DDRB |= (1<<SS)|(1<<MOSI)|(1<<SCK);
		SPCR |= (1<<MSTR);
	}
	else{
		DDRB |= (1<<MISO);
	}
	SPCR |= (1<<SPE)|(1<<SPR1)|(1<<SPR0);
}

void SPI_PROTOCOL_MASTER_send(char data){
	/*
	This function send chars over SPI 
	*/
	SPDR = data;
	while(!(SPSR &(1<<SPIF))); // pooling while sending end and SPDR is ready
}

void SPI_PROTOCOL_MASTER_send_str(char* data){
	/*
	  Sending strings over SPI
	*/
	for(int i = 0; data[i] !='\0';i++){
		SPI_PROTOCOL_MASTER_send(data[i]);
	}
}
void SPI_PROTOCOL_MASTER_send_num(int n){
	/*
	  Sending numbers over SPI
	*/
	char str[10];
	itoa(n,str,10);
	SPI_PROTOCOL_MASTER_send_str(str);
}
char SPI_PROTOCOL_SLAVE_recieve(){
	/*
	  This function receives data over SPI
	*/
	while(!(SPSR &(1<<SPIF)));//pooling while transmission complete 
	return  SPDR;
	
}
