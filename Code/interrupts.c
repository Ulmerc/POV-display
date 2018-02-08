#include <avr/io.h>

void config_global_interupts(void)
{
	// Enabling global interrupts 
	SREG |= (1<<7);

	return;
}

