#include <msp430.h> 

#include "uart.h"
#include "btns.h"
/*
 * main.c
 */

void uart_tx_isr(unsigned char c) {
	uart_send(c);
	P1OUT ^= BIT0;		// toggle P1.0 (red led)
}

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    BCSCTL1 = CALBC1_8MHZ; // Set DCO to 8Mhz
    DCOCTL = CALDCO_8MHZ; // Set DCO to 8Mhz
    P1DIR  = BIT0; 		// P1.0 and P1.6 are the red+green LEDs
    	P1OUT  = BIT0;

    btn_init();
    uart_init();

    uart_send('>');

   // uart_set_tx_isr_ptr(uart_tx_isr);

    __bis_SR_register(GIE);

    while(1){
    	uart_send(btn_sequence());
    	P1OUT ^= BIT0;
    }

	return 0;
}

#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void)
{

	P1OUT ^= BIT0;
	IE2 &= ~UCA0TXIE;
}
