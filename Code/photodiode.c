#include <avr/io.h>

void config_photodiode(){
	// Configuring PD2 as input
	DDRD &= ~(1 << PD2);		

	// Enabling interrupt INT0 
	EIMSK |= (1<<0);

	// Configuring a rising edge to trigger an interrupt on INT0
	EICRA |= ((1<<0) | (1<<1));

	return;
}