/*	Partner(s) Name & E-mail: Andres Sanchez
 *	Lab Section: B21
 *	Assignment: Lab # 2 Exercise # 2-3
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
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs,
	// initialize to 0s
	unsigned char tmpC = 0x00; // intermediate variable used for port updates
	unsigned char tmpA = 0x00;

    /* Replace with your application code */
    while (1) 
    {
	tmpA = PINA & 0x0F;
	if (tmpA == 0x00){
	tmpC = 0x00;
	}
	else if (tmpA < 0x03){
	tmpC = 0x20;
	}
	else if (tmpA < 0x05){
	tmpC = 0x30;
	}
	else if (tmpA < 0x07){
	tmpC = 0x38;
	}
	else if (tmpA < 0x0A){
	tmpC = 0x3C;
	}
	else if (tmpA < 0x0D){
	tmpC = 0x3E;
	}
	else {
	tmpC = 0x3F;
	}

	//for the low light button
	if (tmpA < 0x04){
	tmpC = (tmpC & 0x3F) | 0x40;
	}

	//on register x set bit k to bit b
	//unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	//if (GetBit(tmpA,4) == 1 && GetBit(tmpA,5) == 1 && GetBit(tmpA,6) == 0){
	//SetBit(tmpC,7,1);
	//}
	
	tmpA = PINA & 0x70;
	if (tmpA == 0x30){
	tmpC = (tmpC & 0x7F) | 0x80;
	}
	

	PORTC = tmpC;
    }
}

