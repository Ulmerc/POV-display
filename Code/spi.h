#ifndef SPI
#define SPI

#define SHIFT_REGISTER DDRB
#define SHIFT_PORT PORTB
// MOSI
#define DATA (1<<PB3)   
// SS
#define LATCH (1<<PB2)
// SCK
#define CLOCK (1<<PB5)

void config_spi();
void output_to_leds(uint16_t output);

#endif // SPI
