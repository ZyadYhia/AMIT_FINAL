/*
 * SLAVE.c
 *
 * Created: 11/20/2020 2:43:59 PM
 * Author : himal
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include "SPI_PROTOCOL.h"
#include "UART_PROTOCOL.h"


int main(void)
{
    /* Replace with your application code */
	UART_PROTOCOL_init();
	SPI_PROTOCOL_init(SPI_PROTOCOL_SLAVE);
	DDRC = 0x07;
    while (1) 
    {
	    char c = SPI_PROTOCOL_SLAVE_recieve();
		if(c == '1'){//to open the first led
			PORTC |= (1<<0);
		}
		if(c  == '2'){//to open the second led
			PORTC |= (1<<1);
		}
		if(c == '3'){//to close the first led
			PORTC &= ~(1<<0);
		}
		if(c  == '4'){//to close the second led
			PORTC &= ~(1<<1);
		}
		if(c  == '5'){//to close the second led
			PORTC |= (1<<2);
		}
		if(c  == '6'){//to close the second led
			PORTC &= ~(1<<2);
		}
		else{
	
		}
    }
}

