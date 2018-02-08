#include <avr/io.h>
#include "usart.h"

#define FOSC 20000000
#define BAUD 9600
//#define BAUDSETTING (FOSC/16/BAUD) - 1
#define BAUDSETTING 129UL

void config_usart() {
	//uint16_t baud_rate_setting = 519;

	// Configuring the Baud rate
	UBRR0H = (unsigned char)(BAUDSETTING >> 8);
	UBRR0L = (unsigned char)BAUDSETTING;

	// Configuring the character size to 8 bits
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);

	// Configuring the number of stop bits to 1
	UCSR0C &= ~(1<<USBS0);

	// Configuring USART to asynchronous normal mode
	UCSR0C &= ~(1<<UMSEL01) | ~(1<<UMSEL00);

	// Configuring the reciever to be enabled (transmitter is enabled also, for testing purposes)
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

	// Configuring the Parity mode to enabled with odd parity
	//UCSR0C |= (1<<UPM01) | (1<<UPM00);

}

unsigned char usart_recieve(void) {
		// Return what is in the recieve buffer
	return UDR0;
}

void usart_transmit(unsigned char data) { // IF USING THIS FUNCTION IT NEEDS TO BE FIXED

	// Wait until the transmit buffer is empty
	while (!(UCSR0A & (1<<UDRE0)));

	UDR0 = data;
}

void flush_reciever() {
	int empty_buffer;
	
	// Read the buffer until it is empty
	while(UCSR0A & (1<<RXC0)){
		empty_buffer = UDR0; 
	}
	
}
