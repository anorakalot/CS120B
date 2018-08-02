/*	Partner(s) Name & E-mail: Andres Sanchez
 *	Lab Section: B21
 *	Assignment: Lab # 2 Exercise # 4
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

//on register x set bit k to bit b
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

//GetBit returns the value of bit k in register x
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs,
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs


	// initialize to 0s
	unsigned char tmpB = 0x00; // intermediate variable used for port updates
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;

    /* Replace with your application code */
    while (1) 
    {
	tmpB = 0x00;
	tmpC = 0x00;
	//upper nibble of A
	tmpA = PINA & 0xF0;
	tmpA = tmpA >> 4;



	tmpB = (tmpB & 0x0F) | tmpA;
    
	
	//WORKS
	//lower nibble of A
	tmpA = PINA & 0x0F;

	tmpA = tmpA << 4;

    tmpC = (tmpC & 0xF0) | tmpA;
    
	PORTC = tmpC;
	PORTB = tmpB;
	}
}

