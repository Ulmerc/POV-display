#include <avr/io.h>
#include "usart.h"
#include "spi.h"

uint8_t data; 

/* Configure ports for LEDs */
void configTestingUnits(void){
	
	// Setting PORTC to be outputs
	DDRC = 0xFF;
	// Setting all outputs to low
	PORTC = 0x00;
}

/* If there is unread data in the recieve buffer, toggle debugging LEDs and clear the buffer */
void toggleLEDOnRecieve(void){
	
	if(UCSR0A & (1 << RXC0)){

		// Toggle LED 1 (the flag was set)
		PORTC ^= (0b0000001);
		data = UDR0;
	  
	}
}

/* If there is unread data in the recieve buffer, toggle debugging LEDs and return the data to the computer via USART */
void returnDataToComputer(void){

	if(UCSR0A & (1 << RXC0)){

		// Toggle LED 1 (the flag was set)
		PORTC ^= (0b0000001);
		data = usart_recieve();

		usart_transmit(data);
	}

}

void sendData(void){
	UDR0 = 0b10101010;
}

/* If there is unread data in the recieve buffer, send the data to the debugging LEDs */
void outputToDebugLeds(void){

	if(UCSR0A & (1 << RXC0)){
		
		data = usart_recieve();

		PORTC |= (data & 0b0000001);
		PORTC |= (data & 0b0000010);
		PORTC |= (data & 0b0000100);
	}
}


/* If there is unread data in the recieve buffer, toggle debugging LEDs and send the data to the shift registers */
void outputToShiftRegister(void){

	if(UCSR0A & (1 << RXC0)){

		// Toggle LED 1 (the flag was set)
		PORTC ^= (0b0000001);
		
		data = usart_recieve();
		usart_transmit(data);

		output_to_leds((uint16_t)data);

	}
}
