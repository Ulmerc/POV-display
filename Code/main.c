#include <avr/io.h>
#include <avr/interrupt.h>
#include "spi.h"
#include "usart.h"
#include "timer0.h"
#include "photodiode.h"
#include "interrupts.h"
#include "character_storage.h"

#define MAX_CHARS 75
#define MAX_FRAMES 5

volatile uint8_t advance = 0;
volatile uint8_t reset = 0;

uint8_t characterNum = 0;
uint8_t element = 0;
uint8_t message[MAX_CHARS];
int newMessage = 0;


// ISR for when Timer 1 reaches a set value (when the LEDs should be output to because a degree has been advanced)
ISR(TIMER1_COMPA_vect)
{
	advance++;
}

// ISR for when D2 transitions from low to high (the home position has been reached)
ISR(INT0_vect)
{
	// The home position has been reached
	reset++;
}

void pattern_step(uint8_t character, uint8_t frame){
	
	if(frame >= MAX_FRAMES | characterNum >= element){
		return;	
	}

	output_to_leds((uint16_t)get_character_frame(message[character], frame));
}

void pattern_clear(){
	
	output_to_leds(0x0000);
}

int main(void){
	
	config_global_interupts();
	config_photodiode();
	config_timer();
	config_spi();
	config_usart();

	uint8_t playing = 0;
	uint8_t frame = 0;
	uint8_t character;

	while(1){

		if((UCSR0A & (1 << RXC0))){
			
			playing = 0;

			if(newMessage){

				for(int i = 0; i < element; i++){
					message[element] = '\0';
				}

				newMessage = 0;
				element = 0;
			}

			character = usart_recieve();

				// If the Enter key was not pressed
				if(character != 13 & element < MAX_CHARS) {
					message[element] = character;
					element++;
				}
				else{
					
					newMessage = 1;
				}
   		 }
	  			
	    // If the home position has been reached
		if(reset){
			
			reset--;
			// Set pattern to restart
			frame = 0;
			characterNum = 0;
			// Set the pattern to start playing
			playing = 1;
		}

		// If a degree has been traversed
		if(advance){
			// If a pattern should be playing
			if(playing){

				pattern_step(characterNum, frame);
				frame++;

				if(frame >= MAX_FRAMES){
					frame = 0;
					characterNum++;
				}

				if(characterNum >= element){
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
