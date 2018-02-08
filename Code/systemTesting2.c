#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#define F_CPU 20000000UL

#define SHIFT_REGISTER DDRB
#define SHIFT_PORT PORTB
// MOSI
#define DATA (1<<PB3)   
// SS
#define LATCH (1<<PB2)
// SCK
#define CLOCK (1<<PB5)

uint16_t characterArray[16] =
	  {
		0b1111111111111111,
		0b1111111111111110,
		0b1111111111111100,
		0b1111111111111000,
		0b1111111111110000,
		0b1111111111100000,
		0b1111111111000000,
		0b1111111110000000,
		0b1111111100000000,
		0b1111111000000000,
		0b1111110000000000,
		0b1111100000000000,
		0b1111000000000000,
		0b1110000000000000,
		0b1100000000000000,
		0b1000000000000000,
	  };

uint16_t wew[16] = {
	0x00FF,
	0x00F0,
	0x000F,
	0x00AA,
	0x0FFF,
	0x0FF0,
	0x0F0F,
	0x0FAA,
	0xF0FF,
	0xF0F0,
	0xF00F,
	0xF0AA,
	0xFFFF,
	0xFFF0,
	0xFF0F,
	0xFFAA,
};

uint8_t charA[] =
	{
   		0b01111110,  // 0 * * * * * * 0
		0b00001001,  // 0 0 0 0 * 0 0 *
		0b00001001,  // 0 0 0 0 * 0 0 *
		0b00001001,  // 0 0 0 0 * 0 0 *
		0b01111110,  // 0 * * * * * * 0
	};

uint8_t charB[] =
	{
		0b01111111, // 0 * * * * * * * 
		0b01001001, // 0 * 0 0 * 0 0 * 
		0b01001001, // 0 * 0 0 * 0 0 * 
		0b01001001, // 0 * 0 0 * 0 0 * 
		0b00110110, // 0 0 * * 0 * * 0 
	};




void output_to_leds(uint16_t output);

unsigned char data = 0;
uint8_t playing = 0;
uint8_t frame = 0;
uint8_t frame_max = 5;
volatile uint8_t advance = 0;
volatile uint8_t reset = 0;


//==================================================================================================

// ISR for when Timer 1 reaches a set value (when the LEDs should be output to)
ISR(TIMER1_COMPA_vect)
{
	advance++;
}

// ISR for when D2 transitions from low to high (the home position has been reached)
ISR(INT0_vect)
{
	// Indicating that the Home position has been reached and that the pattern needs to be restarted
	reset++;
}

//==================================================================================================

void config_global_interupts()
{
	// Enabling global interrupts 
	SREG |= (1<<7);

	return;
}

void config_photodiode()
{
	// Configuring PD2 as input
	DDRD &= ~(1 << PD2);		

	// Enabling interrupt INT0 
	EIMSK |= (1<<0);

	// Configuring a rising edge to trigger an interrupt on INT0
	EICRA |= ((1<<0) | (1<<1));

	return;
}

void config_timer()
{
	// Configuring Timer1 to be in CTC mode
	TCCR1B |= (1 << WGM12);

	// Enabling an interrupt to trigger when Timer1 reaches the value set in OCR1A
	TIMSK1 |= (1 << OCIE1A);

	// Setting the value that the interrupt will trigger on when Timer1 matches it
	OCR1A = 20000;
	
	// Enabling the timer clock with a prescaler of 64 (clock for timer = 20 MHz / 64)
	TCCR1B |= (1 << CS10) | (1 << CS11);

	// Initlizing Timer1 to 0
	TCNT1 = 0;

	return;
}

void config_spi()
{
	// Setting SPI related pins to outputs
	SHIFT_REGISTER |= (DATA | LATCH | CLOCK); 

    // Setting SPI related pins low
    SHIFT_PORT &= ~(DATA | LATCH | CLOCK);        
 
    // Enabeling SPI and setting it to Master mode 
    SPCR = (1<<SPE) | (1<<MSTR) | 0x3;  
 
    // Pulling the LED driver's latch enable pin low (see LED driver timing diagram on datasheet)
    SHIFT_PORT &= ~LATCH;

	return;
}

void config_usart(){

	uint16_t baud_rate_setting = 519;

	// Configuring the reciever to be enabled (transmitter is enabled also, for testing purposes)
	UCSR0B |= (1<<RXEN0) | (1 << RXEN0);

	// Configuring USART to asynchronous normal mode
	UCSR0C &= ~(1<<UMSEL01) | ~(1<<UMSEL00);

	// Configuring the character size to 8 bits
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);

	// Configuring the Parity mode to enabled with odd parity
	UCSR0C |= (1<<UPM01) | (1<<UPM00);

	// Configuring the number of stop bits to 1
	UCSR0C &= ~(1<<USBS0);

	// Configuring the Baud rate
	UBRR0H = (unsigned char)(baud_rate_setting>>8);
	UBRR0L = (unsigned char)baud_rate_setting;

	// FEn DORn UPEn
}

//==================================================================================================
 


//==================================================================================================

void pattern_step(uint8_t frame){
	if(frame >= frame_max){
		return;	
	}
	
	output_to_leds((uint16_t)charB[frame]);

	return;
}

void pattern_clear(){
	output_to_leds(0x0000);
	return;
}

void output_to_leds(uint16_t output){	
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

//==================================================================================================

unsigned char usart_recieve(void){
	//Wait until the recieve buffer has data
	while (!(UCSR0A & (1<<RXC0)));
	// If frame error is set
	if(FE0){
		
		flush_reciever();
	}

	else {
		PORTC = (1<<PB2);
		_delay_ms(50);
		PORTC = 0x00;
		// Return what is in the recieve buffer
		return UDR0;
	}
}

void usart_transmit(unsigned char data){
	// Wait until the transmit buffer to be empty
	while (!(UCSR0A & (1<<UDRE0)));
	// Put data into the buffer, which initiates transmission
	UDR0 = data;
}

void flush_reciever(){
	int empty_buffer;
	
	// Read the buffer until it is empty
	while(UCSR0A & (1<<RXC0)){
		empty_buffer = UDR0; 
		PORTC = (1<<PB1);
		_delay_ms(50);
		PORTC = 0x00;
	}
	
}



//=====================================================================================================

int main(void){
	config_global_interupts();
	config_photodiode();
	config_timer();
	config_spi();
	//config_usart();
	DDRC = 0xFF;
	
	while(1){

			/* Getting the microcontroller to talk to itself via USART*/ 
            /*
			// Sending 8 bits (1 char of data)
			usart_transmit(0b01010101);
			// Getting information from the register 
			data = usart_recieve();
			output_to_leds((uint16_t) data);
			*/
			/* Sending characters from the computer, to the microcontroller via USART, back to the computer */
		    /*
			data = usart_recieve();
			output_to_leds(data);
			_delay_ms(200);
			pattern_clear();
		    */
			/* Sending characters from the computer to the microcontroller via USART, the ASCII value is output onto 8 leds*/
			/*
				// Setting PORTC to be outputs


				// Setting PB0 to be an output
				DDRB |= (1<<PB0);

				// Getting information from the register 
				data = usart_recieve();

				// Outputting first 7 bits to PC0 - PC6
				PORTC = (data & 0b01111111);
				// Getting the MSB of data and sending it to PB0
				PORTB |= (data >> 7);

				_delay_ms(100);
				PORTC = 0x00;
				PORTB &= ~(1<<PB0); 
			*/

			/* Sending characters from the computer to the microcontroller via USART, the ASCII value is output to the shift registers*/
			/*
				data = usart_recieve();
				output_to_leds((uint16_t) data);
			*/

			
		
	    // If the home position has been reached
		if(reset){
			reset--;
			// Set pattern to restart
			frame = 0;
			// If a pattern is currently playing
			playing = 1;
		}

		// If a degree has been traversed
		if(advance){
			// If a pattern is currently playing
			if(playing){

				// Handle outputting to the LEDs
				pattern_step(frame);
				frame++;

				if(frame >= frame_max){
					playing = 0;
					frame = 0;
				}
			}
			
			else{
				pattern_clear();
			}

			advance--;
			}
	}
}
