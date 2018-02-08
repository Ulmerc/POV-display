#include <avr/io.h>
#include <stdint.h>

// 8 Mega hertz
#define F_CPU 20000000UL
#include <util/delay.h>


#define SHIFT_REGISTER DDRB
#define SHIFT_PORT PORTB
#define DATA (1<<PB3)    //MOSI (SI)  (Data is output on this pin)
#define LATCH (1<<PB2)   //SS   (RCK) (The latch is output on this line)
#define CLOCK (1<<PB5)   //SCK  (SCK) (The clock is output on this line)


#define shushJoel1 14
#define shushJoel2 2

int main(void)
{
  // Setting SPI related pins to outputs
  SHIFT_REGISTER |= (DATA | LATCH | CLOCK); 

  // Setting SPI related pins low
  SHIFT_PORT &= ~(DATA | LATCH | CLOCK);        
 
  // Enabeling SPI and setting it to Master mode 
  // SPCR is the SPI control register
  // SPE = SPI enable (when SPE is written to 1 SPI is enabled)
  // MSTR = Master/Slave select (When MSTR is written to 1, Master SPI mode is selected)
  SPCR = (1<<SPE) | (1<<MSTR);  
 
  // Pulling the LED driver's latch enable pin low (see LED driver timing diagram on datasheet)
  SHIFT_PORT &= ~LATCH;


   uint8_t characterArray[shushJoel1][shushJoel2] =
	  {
		{0b11111111, 0b11111111},
		{0b11111111, 0b11111110},
		{0b11111111, 0b11111100},
		{0b11111111, 0b11111000},
		{0b11111111, 0b11110000},
		{0b11111111, 0b11100000},
		{0b11111111, 0b11000000},
		{0b00000000, 0b00111111},
		{0b00000000, 0b00011111},
		{0b00000000, 0b00001111},
		{0b00000000, 0b00000111},
		{0b00000000, 0b00000011},
		{0b00000000, 0b00000001},
		{0b00000000, 0b00000000},
	  };

   while(1)
   {
		for(int index = 0; index < shushJoel1; index += 1)
		{

			// Write the first 8 bits of the selected index in the character arrayt o the SPDR, it will automatically be strobed into 
			// the shift registers
			// SPDR is the SPI data register
			SPDR = characterArray[index][0];        
    
			// SPSR is the SPI status register
			// SPIF = SPI interrupt flag (When a serial transfer is complete, the SPIF Flag is set)
			// Wait for SPI process to finish
			while(!(SPSR & (1<<SPIF)));
   
			//Write the second 8 bits of the selected index in the character array to the SPDR
			//This should light alternating LEDs
			SPDR = characterArray[index][1];      
    
			//Wait for SPI process to finish
			while(!(SPSR & (1<<SPIF)));
   
			// Toggle the latch to display the data on the LEDs ~~~
			//Toggle latch to copy data to the storage register
			// Set high (to shift the data out)

			SHIFT_PORT |= LATCH;
			// Set low (so the data can be shifted into the storage register)
			SHIFT_PORT &= ~LATCH;

			_delay_ms(10);
	   
		 }
	}
}





