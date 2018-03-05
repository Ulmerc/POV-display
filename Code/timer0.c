#include <avr/io.h>

void config_timer(){
	
	// Configuring Timer1 to be in CTC mode
	TCCR1B |= (1 << WGM12);

	// Enabling an interrupt to trigger when Timer1 reaches the value set in OCR1A
	TIMSK1 |= (1 << OCIE1A);

	// Setting the value that the interrupt will trigger on when Timer1 matches it
	OCR1A = 350;
	
	// Enabling the timer clock with a prescaler of 64 (clock for timer = 20 MHz / 64)
	TCCR1B |= (1 << CS10) | (1 << CS11);

	// Initlizing Timer1 to 0
	TCNT1 = 0;

	return;
}
