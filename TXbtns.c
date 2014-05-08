/*
 * btns.c
 *
 *  Created on: May 6, 2014
 *      Author: Administrator
 */
#include <msp430.h>

#include "btns.h"


void btn_init(){
	P2DIR &= ~BIT2|BIT3|BIT4|BIT5;
	P2OUT |= BIT2|BIT3|BIT4|BIT5;

}

char btn_sequence(){
	char output = 0x00;

	if(!(P2IN & BIT2)){
		output = 0x01;
	}
	else if(!(P2IN & BIT4)){
		output = 0x02; //"00000010";
	}
	else if(!(P2IN & BIT3)){
		output = 0x04; //"00000100";
	}
	else if(!(P2IN & BIT5)){
		output = 0x08; //"00001000";
	}
	else{
		output = 0x00; //"00000000";
	}
	return output;
}



