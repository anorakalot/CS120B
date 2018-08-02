/*	Partner(s) Name & E-mail: Andres Sanchez
 *	Lab Section: B21
 *	Assignment: Lab # 1 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs,
	unsigned char tmpB = 0x00; 	// Temporary variable to hold the value of B
	
	unsigned char tmpA_1 = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpA_0 = 0x00;

	while(1)
	{
	tmpA_1 = PINA & 0x02;
	
	tmpA_0 = PINA & 0x01;
	
	if ( tmpA_1 == 0x00 && tmpA_0 == 0x01) { // True if PA0 is 1
			tmpB = (tmpB & 0x00) | 0x01; // Sets tmpB to bbbbbb01
							// (clear rightmost 2 bits, then set to 01)
		}
	else   {
			tmpB = (tmpB & 0x00) | 0x00; // Sets tmpB to bbbbbb10
							// (clear rightmost 2 bits, then set to 10)
		}	
		PORTB = tmpB;
	}
	
	return 0;
}

