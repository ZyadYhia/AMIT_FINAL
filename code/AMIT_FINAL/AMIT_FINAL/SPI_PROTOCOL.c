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
	SPDR = data;
	while(!(SPSR &(1<<SPIF)));
}

void SPI_PROTOCOL_MASTER_send_str(char* data){
	for(int i = 0; data[i] !='\0';i++){
		SPI_PROTOCOL_MASTER_send(data[i]);
	}
}
void SPI_PROTOCOL_MASTER_send_num(int n){
	char str[10];
	itoa(n,str,10);
	SPI_PROTOCOL_MASTER_send_str(str);
}
char SPI_PROTOCOLL_SLAVE_recieve(){
	while(!(SPSR &(1<<SPIF)));
	return  SPDR;
	
}
