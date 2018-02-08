#include <avr/io.h>

uint8_t character_bitmaps[2][5] = {
	{
		0b01111110,  // 0 * * * * * * 0
		0b00001001,  // 0 0 0 0 * 0 0 *
		0b00001001,  // 0 0 0 0 * 0 0 *
		0b00001001,  // 0 0 0 0 * 0 0 *
		0b01111110,  // 0 * * * * * * 0
	},
	{
		0b01111111, // 0 * * * * * * *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b00110110, // 0 0 * * 0 * * 0
	},
};

/* character is a raw ASCII character */
uint8_t get_character_frame(uint8_t character, uint8_t frame){
	return character_bitmaps[character - 65][frame];
}
