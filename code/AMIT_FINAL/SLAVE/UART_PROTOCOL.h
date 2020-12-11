/*
 * UART.h
 *
 * -This driver Initiate and Send or Receive over UART
 *
 * Created: 10/25/2020 2:26:21 PM
 *  Author: himal
 */ 


#ifndef UART_PROTOCOL_H_
#define UART_PROTOCOL_H_


void UART_PROTOCOL_init();
void UART_PROTOCOL_send(char);
void UART_PROTOCOL_send_str(char*);
void UART_PROTOCOL_send_num(int);
char UART_PROTOCOL_recieve();


#endif /* UART_H_ */