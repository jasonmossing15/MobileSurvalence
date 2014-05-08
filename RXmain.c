#include <msp430.h> 

#include "uart.h"

/*
 * main.c
 */
void btns(unsigned char in);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    BCSCTL1 = CALBC1_8MHZ; // Set DCO to 8Mhz
    DCOCTL = CALDCO_8MHZ; // Set DCO to 8Mhz

	P2DIR |= (BIT0|BIT1|BIT2|BIT3);

	P2OUT |=  BIT0|BIT1|BIT2|BIT3;
	uart_init();

    __bis_SR_register(GIE);

	unsigned char i;

	while(1){

		i = uart_get();
		btns(i);
	}

	return 0;
}

void btns(unsigned char in){
	if(in == 0x01){
		P2OUT |= BIT1;
		P2OUT &=  ~(BIT0|BIT2|BIT3);
	}
	else if(in == 0x02){
		P2OUT |= BIT3;
		P2OUT &=  ~(BIT0|BIT1|BIT2);
	}
	else if(in == 0x04){
		P2OUT |= BIT0;
		P2OUT &=  ~(BIT1|BIT2|BIT3);
	}
	else if(in == 0x08){
		P2OUT |= BIT2;
		P2OUT &=  ~(BIT0|BIT1|BIT3);
	}
	else{
		P2OUT &=  ~(BIT0|BIT1|BIT2|BIT3);
	}
}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
	IFG2 &= ~UCA0RXIFG;
}
