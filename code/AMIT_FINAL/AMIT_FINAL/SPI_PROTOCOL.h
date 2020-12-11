/*
 * SPI.h
 *
 * Created: 10/30/2020 1:51:07 PM
 *  Author: himal
 */ 


#ifndef SPI_PROTOCOL_H_
#define SPI_PROTOCOL_H_

#define  SPI_PROTOCOL_MASTER 1
#define  SPI_PROTOCOL_SLAVE  0


#define SS   4
#define MOSI 5
#define MISO 6
#define SCK  7

void SPI_PROTOCOL_init(int);
void SPI_PROTOCOL_MASTER_send(char);
void SPI_PROTOCOL_MASTER_send_str(char*);
void SPI_PROTOCOL_MASTER_send_num(int);
char SPI_PROTOCOL_SLAVE_recieve();


#endif /* SPI_PROTOCOL_H_ */