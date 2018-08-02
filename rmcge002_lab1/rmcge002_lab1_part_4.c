/*	Partner(s) Name & E-mail: Andres Sanchez
 *	Lab Section: B21
 *	Assignment: Lab # 1 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <stdlib.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF; // Configure port A's 8 pins as inputs
    

	DDRD = 0xFF; PORTD = 0x00; // Configure port B's 8 pins as outputs,
    
	// initialize to 0s
	unsigned short max_value = 140;
	unsigned short max_diff = 80;
	unsigned short sum_comp;
	unsigned char tmpD = 0x00;
	unsigned char tmpC = 0x00;
    unsigned char tmpB = 0x00; 	// Temporary variable to hold the value of B
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	
	while (1) 
    {
	tmpA = PINA & 0xFF;
	tmpB = PINB & 0xFF;
	tmpC = PINC & 0xFF;

	//CHECKING IF SUM IS OVER
	sum_comp = tmpA + tmpB + tmpC;
	if ( sum_comp > max_value){
		tmpD = (tmpD & 0xFE) | 0x01;
	}

	//CHECKING FOR THE MAX DIFF
	if (abs(tmpA - tmpC) > max_diff ){//| tmpC-tmpA > max_diff){
		tmpD = (tmpD & 0xFD) | 0x02;	
	}
	
	//APPROXIMATION
	if (sum_comp < 100){
		tmpD = (tmpD & 0xFB) | 0x04;
	}
	else if (sum_comp < 200){
		tmpD = (tmpD & 0xF3) | 0x0C;
	}
	else if (sum_comp < 300){
		tmpD = (tmpD & 0xE3) | 0x1C;
	}
	else if (sum_comp < 400){
		tmpD = (tmpD & 0xC3) | 0x3C;
	}

	else if (sum_comp < 500){
		tmpD = (tmpD & 0x83) | 0x7C;
	}
	else {
	tmpD = (tmpD & 0x03) | 0xFC;
	}
	PORTD = tmpD;	
    }
	return 0;
}



//APPROXIMATION
//if (tmpA < approx_num){
//	tmpD = (tmpD & 0xFB) | 0x04;
//}


//else if (tmpA >= approx_num){
//	tmpD = (tmpD & 0xF7) | 0x08;
//}


//
//if (tmpB < approx_num){
//	tmpD = (tmpD & 0xEF) | 0x10;
//}

//else if (tmpB >= approx_num){
//	tmpD = (tmpD & 0xDF) | 0x20;
//}

//
//if (tmpC < approx_num){
//	tmpD = (tmpD & 0xBF) | 0x40;
//}

//else if (tmpC >= approx_num){
//	tmpD = (tmpD & 0x7F) | 0x80;
//}
//unsigned short temp_sum;
	//unsigned char temp_sum;
	//unsigned short tmp_shifted_sum;
	//unsigned char tmp_shifted_sum;
	//unsigned short approx_num = 128;
	