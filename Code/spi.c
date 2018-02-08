#include <avr/io.h>
#include "spi.h"

void config_spi() {
	// Setting SPI related pins to outputs
	SHIFT_REGISTER |= (DATA | LATCH | CLOCK); 

    // Setting SPI related pins low
    SHIFT_PORT &= ~(DATA | LATCH | CLOCK);        
 
    // Enabeling SPI and setting it to Master mode 
    SPCR = (1<<SPE) | (1<<MSTR) | 0x3;  
 
    // Pulling the LED driver's latch enable pin low (see LED driver timing diagram on datasheet)
    SHIFT_PORT &= ~LATCH;

}

void output_to_leds(uint16_t output) {	
	for(int i = 0; i < 2; i++){
		// Write 8 bits into the SPI data register (SPDR)
		SPDR = (uint8_t)(0x00FF & (output >> (i * 8)));
		
		// Wait for serial transfer to be complete
		while(!(SPSR & (1<<SPIF)));
	}

	// Toggle the latch to display the data on the LEDs
	SHIFT_PORT |= LATCH;
	SHIFT_PORT &= ~LATCH;
}

