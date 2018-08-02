/*	Partner(s) Name & E-mail: Andres Sanchez
 *	Lab Section: B21
 *	Assignment: Lab # 2 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

// Bit-access function
//Sets bit k in register x to bit b
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

//GetBit returns the value of bit k in register x
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void){
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

	

    /* Replace with your application code */
    while (1) 
    {

	tmpA = PINA;
	tmpB = PINB;
	tmpC = 0x00;
	
		for(unsigned i = 0; i<8; i++){
			if (GetBit(tmpA, i)) { // True if PortA bit i is 1
			tmpC++;
			}
			if (GetBit(tmpB, i)) {
			tmpC++;
			}
		}
		// 3) write results to port	 
	PORTC = tmpC;

}

}

