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
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs,
	unsigned char tmpC = 0x00; 	// Temporary variable to hold the value of C
	
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
/*
	unsigned char tmpA_1 = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpA_2= 0x00; // Temporary variable to hold the value of A
	unsigned char tmpA_3 = 0x03; // Temporary variable to hold the value of A
	unsigned char tmpA_4 = 0x04; // Temporary variable to hold the value of A
	unsigned char tmpA_5 = 0x05; // Temporary variable to hold the value of A
	unsigned char tmpA_6 = 0x06; // Temporary variable to hold the value of A
	unsigned char tmpA_7 = 0x07; // Temporary variable to hold the value of A
	unsigned char tmpA_8 = 0x08; // Temporary variable to hold the value of A
	unsigned char tmpA_9 = 0x09; // Temporary variable to hold the value of A
	unsigned char tmpA_10 = 0x0A; // Temporary variable to hold the value of A
	unsigned char tmpA_11 = 0x0B; // Temporary variable to hold the value of A
	unsigned char tmpA_12 = 0x0C; // Temporary variable to hold the value of A
	unsigned char tmpA_13 = 0x0D; // Temporary variable to hold the value of A
	unsigned char tmpA_14 = 0x0E; // Temporary variable to hold the value of A
	unsigned char tmpA_15 = 0x0F; // Temporary variable to hold the value of A
*/
	//unsigned char cntavail;

	while(1){
	tmpA = PINA & 0x0F;
	

	if (tmpA == 0x0F) { 
		//cntavail = 0;
		//PORTC = cntavail;
		tmpC = (tmpC & 0x00) | 0x80; 
	}
	
	else if (tmpA == 0x0E || tmpA == 0x0D||tmpA == 0x0B||tmpA== 0x07) {
		//cntavail = 0;
		//PORTC = cntavail;
		tmpC = (tmpC & 0x00) | 0x01;
	}

	else if (tmpA == 0x0C || tmpA == 0x0A || tmpA == 0x09||tmpA == 0x06||tmpA == 0x05||tmpA == 0x03) {
		//cntavail = 0;
		//PORTC = cntavail;
		tmpC = (tmpC & 0x00) | 0x02;
	}

	else if (tmpA == 0x08||tmpA==0x04||tmpA==0x02||tmpA==0x01) {
		//cntavail = 0;
		//PORTC = cntavail;
		tmpC = (tmpC & 0x00) | 0x03;
	}

	//else{
	//tmpC =(tmpC & 0x00) | 0x80;
	//}

	






	// (3) Write output
	PORTC = tmpC;
	}
}