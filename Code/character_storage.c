#include <avr/io.h>

uint8_t character_bitmaps[][5] = {
	{ // SPACE (temp input as @ on terminal)
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},	
	{ // A
		0b01111110,  // 0 * * * * * * 0
		0b00001001,  // 0 0 0 0 * 0 0 *
		0b00001001,  // 0 0 0 0 * 0 0 *
		0b00001001,  // 0 0 0 0 * 0 0 *
		0b01111110,  // 0 * * * * * * 0
	},
	{ // B
		0b01111111, // 0 * * * * * * *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b00110110, // 0 0 * * 0 * * 0
	},
	{ // C
		0b01111111, // 0 * * * * * * *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
	},
	{ // D
		0b01111111, // 0 * * * * * * *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b00111110, // 0 0 * * * * * 0
	},
	{ // E
		0b01111111, // 0 * * * * * * *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
	},
	{ // F
		0b01111111, // 0 * * * * * * *
		0b00001001, // 0 0 0 0 * 0 0 *
		0b00001001, // 0 0 0 0 * 0 0 *
		0b00001001, // 0 0 0 0 * 0 0 *
		0b00000001, // 0 0 0 0 0 0 0 *
	},
	{ // G
		0b01111111, // 0 * * * * * * *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01010001, // 0 * 0 * 0 0 0 *
		0b01110001, // 0 * * * 0 0 0 *
	},
	{ // H
		0b01111111, // 0 * * * * * * *
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b01111111, // 0 * * * * * * *
	},
	{ // I
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01111111, // 0 * * * * * * *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
	},
	{ // J
		0b01100001, // 0 * * 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01111111, // 0 * * * * * * *
		0b00000001, // 0 0 0 0 0 0 0 *
		0b00000001, // 0 0 0 0 0 0 0 *
	},
	{ // K
		0b01111111, // 0 * * * * * * *
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00010100, // 0 0 0 * 0 * 0 0
		0b00100010, // 0 0 * 0 0 0 * 0
		0b01000000, // 0 * 0 0 0 0 0 0
	},
	{ // L
		0b01111111, // 0 * * * * * * *
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
	},
	{ // M
		0b00000000, // 0 * * * * * * *
		0b00000000, // 0 0 0 0 0 0 * 0
		0b00000000, // 0 0 0 0 0 * 0 0
		0b00000000, // 0 0 0 0 0 0 * 0
		0b00000000, // 0 * * * * * * *
	},
	{ // N
		0b01111111, // 0 * * * * * * *
		0b00000010, // 0 0 0 0 0 0 * 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00100000, // 0 0 * 0 0 0 0 0
		0b00111111, // 0 * * * * * * *
	},
	{ // O
		0b00111110, // 0 0 * * * * * 0
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b00111100, // 0 0 * * * * 0 0
	},
	{ // P
		0b01111110, // 0 * * * * * * 0
		0b00001001, // 0 0 0 0 * 0 0 *
		0b00001001, // 0 0 0 0 * 0 0 *
		0b00001001, // 0 0 0 0 * 0 0 *
		0b00000110, // 0 0 0 0 0 * * 0
	},
	{ // Q
		0b00011110, // 0 0 0 * * * * 0
		0b00100001, // 0 0 * 0 0 0 0 *
		0b00110001, // 0 0 * * 0 0 0 *
		0b00111110, // 0 0 * * * * * 0
		0b01000000, // 0 * 0 0 0 0 0 0
	},
	{ // R
		0b01111110, // 0 * * * * * * 0
		0b00011001, // 0 0 0 * * 0 0 *
		0b00101001, // 0 0 * 0 * 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b10000110, // * 0 0 0 0 * * 0
	},
	{ // S
		0b00100110, // 0 0 * 0 0 * * 0
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b00110010, // 0 0 * * 0 0 * 0
	},
	{ // T
		0b00000001, // 0 0 0 0 0 0 0 *
		0b00000001, // 0 0 0 0 0 0 0 *
		0b01111111, // 0 * * * * * * *
		0b00000001, // 0 0 0 0 0 0 0 *
		0b00000001, // 0 0 0 0 0 0 0 *
	},
	{ // U
		0b00111111, // 0 0 * * * * * *
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b00111111, // 0 0 * * * * * *
	},
	{ // V
		0b00011111, // 0 0 0 * * * * *
		0b00100000, // 0 0 * 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b00100000, // 0 0 * 0 0 0 0 0
		0b00011111, // 0 0 0 * * * * *
	},
	{ // W
		0b01111111, // 0 * * * * * * *
		0b00100000, // 0 0 * 0 0 0 0 0
		0b00010000, // 0 0 0 * 0 0 0 0
		0b00100000, // 0 0 * 0 0 0 0 0
		0b01111111, // 0 * * * * * * *
	},
	{ // X
		0b01000001, // 0 * 0 0 0 0 0 *
		0b00100100, // 0 0 * 0 0 * 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00100010, // 0 0 * 0 0 0 * 0
		0b01000001, // 0 * 0 0 0 0 0 *
	},
	{ // Y
		0b00000001, // 0 0 0 0 0 0 0 *
		0b00000010, // 0 0 0 0 0 0 * 0
		0b01111100, // * * * * * * 0 0
		0b00000010, // 0 0 0 0 0 0 * 0
		0b00000001, // 0 0 0 0 0 0 0 *
	},	
	{ // Z
		0b01100001, // 0 * 0 0 0 0 0 *
		0b01010001, // 0 * 0 * 0 0 0 *
		0b01001001, // 0 * 0 0 * 0 0 *
		0b01000101, // 0 * 0 0 0 * 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
	},
	{ // [
		0b01111111, // 0 * * * * * * *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b01000001, // 0 * 0 0 0 0 0 *
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // \
		0b00000000, // 0 0 0 0 0 * 0 0
		0b00000000, // 0 0 0 0 * 0 0 0
		0b00000000, // 0 0 0 * 0 0 0 0
		0b00000000, // 0 0 * 0 0 0 0 0
		0b00000000, // 0 * 0 0 0 0 0 0
	},
	{ // ]
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b10000001, // 0 * 0 0 0 0 0 *
		0b10000001, // 0 * 0 0 0 0 0 *
		0b01111111, // 0 * * * * * * *
	},	
	{ // ^
		0b00000000, // 0 0 0 0 0 * 0 0
		0b00000000, // 0 0 0 0 0 0 * 0
		0b00000000, // 0 0 0 0 0 0 0 *
		0b00000000, // 0 0 0 0 0 0 * 0
		0b00000000, // 0 0 0 0 0 * 0 0
	},
	{ // _
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
	},
	{ // `
		0b00000001, // 0 0 0 0 0 0 0 *
		0b00000010, // 0 0 0 0 0 0 * 0
		0b00000100, // 0 0 0 0 0 * 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // a
		0b00***000, // 0 0 * * * 0 0 0
		0b0*0000*0, // 0 * 0 0 0 * 0 0
		0b0*0000*0, // 0 * 0 0 0 * 0 0
		0b0*****00, // 0 * * * * 0 0 0
		0b10000000, // * 0 0 0 0 0 0 0
	},
	{ // b
		0b01111110, // 0 * * * * * * 0
		0b01001000, // 0 * 0 0 * 0 0 0
		0b00110000, // 0 0 * * 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // c
		0b00111100, // 0 0 * * * * 0 0
		0b01000010, // 0 * 0 0 0 0 * 0
		0b00100100, // 0 0 * 0 0 * 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // d
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00110000, // 0 0 * * 0 0 0 0
		0b01001000, // 0 * 0 0 * 0 0 0
		0b01111110, // 0 * * * * * * 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // e
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00011100, // 0 0 0 * * * 0 0
		0b01001010, // 0 0 * 0 * 0 * 0
		0b01011100, // 0 0 * 0 * * 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // f
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00010000, // 0 0 0 * 0 0 0 0
		0b01111100, // 0 * * * * * 0 0
		0b00010010, // 0 0 0 * 0 0 * 0
		0b00000100, // 0 0 0 0 0 * 0 0
	},
	{ // g
		0b00001100, // 0 0 0 0 * * 0 0
		0b01010010, // 0 * 0 * 0 0 * 0
		0b01010010, // 0 * 0 * 0 0 * 0
		0b00111100, // 0 0 * * * * 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // h
		0b01111110, // 0 * * * * * * 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b01110000, // 0 * * * 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // i
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b011111010, // 0 * * * * 0 * 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // j
		0b00100000, // 0 0 * 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b00111010, // 0 0 * * * 0 * 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // k
		0b01111100, // 0 * * * * * 0 0
		0b00010000, // 0 0 0 * 0 0 0 0
		0b00101000, // 0 0 * 0 * 0 0 0
		0b01000100, // 0 * 0 0 0 * 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // l
		0b00000000, // 0 0 0 0 0 0 0 0
		0b01000010, // 0 * 0 0 0 0 * 0
		0b01111110, // 0 * * * * * * 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // m
		0b01111000, // 0 * * * * 0 0 0
		0b00000100, // 0 0 0 0 0 * 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00000100, // 0 0 0 0 0 * 0 0
		0b01111000, // 0 * * * * 0 0 0
	},
	{ // n
		0b00000000, // 0 * * * 0 0 0 0
		0b00000000, // 0 0 0 0 * 0 0 0
		0b00000000, // 0 0 0 0 * 0 0 0
		0b00000000, // 0 * * * 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // o
		0b00111000, // 0 0 * * * 0 0 0
		0b01000100, // 0 * 0 0 0 * 0 0
		0b01000100, // 0 * 0 0 0 * 0 0
		0b00111000, // 0 0 * * * 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // p
		0b01111100, // 0 * * * * * 0 0
		0b00010100, // 0 0 0 * 0 * 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // q
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 * 0 0 0
		0b00000000, // 0 0 0 * 0 * 0 0
		0b00000000, // 0 * * * * * 0 0
	},
	{ // r
		0b01111100, // 0 * * * * 0 0 0
		0b00000010, // 0 0 0 0 0 * 0 0
		0b00000100, // 0 0 0 0 * 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // s
		0b10010000, // * 0 0 * 0 0 0 0
		0b10101000, // * 0 * 0 * 0 0 0
		0b10101000, // * 0 * 0 * 0 0 0
		0b01001000, // 0 * 0 0 * 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // t
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b01111100, // 0 * * * * * 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // u
		0b00000000, // 0 0 0 0 0 0 0 0
		0b01111000, // 0 * * * * 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b01111000, // 0 * * * * 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // v
		0b00000000, // 0 0 0 0 0 0 0 0
		0b00111000, // 0 0 * * * 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b00111000, // 0 0 * * * 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
	{ // w
		0b00111000, // 0 0 * * * 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b00100000, // 0 0 * 0 0 0 0 0
		0b01000000, // 0 * 0 0 0 0 0 0
		0b00111000, // 0 0 * * * 0 0 0
	},
	{ // x
		0b01000100, // 0 * 0 0 0 * 0 0
		0b00101000, // 0 0 * 0 * 0 0 0
		0b00010000, // 0 0 0 * 0 0 0 0
		0b00101000, // 0 0 * 0 * 0 0 0
		0b01000100, // 0 * 0 0 0 * 0 0
	},
	{ // y
		0b00000100, // 0 0 0 0 0 * 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b01110000, // 0 * * * 0 0 0 0
		0b00001000, // 0 0 0 0 * 0 0 0
		0b00000100, // 0 0 0 0 0 * 0 0
	},
	{ // z
		0b01001000, // 0 * 0 0 * 0 0 0
		0b01101000, // 0 * * 0 * 0 0 0
		0b01011000, // 0 * 0 * * 0 0 0
		0b01001000, // 0 * 0 0 * 0 0 0
		0b00000000, // 0 0 0 0 0 0 0 0
	},
};

/* character is a raw ASCII character */
uint8_t get_character_frame(uint8_t character, uint8_t frame){
	return character_bitmaps[character - 64][frame];
}
