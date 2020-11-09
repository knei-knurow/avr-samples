#define __AVR_ATmega8A__
#include <avr/io.h>
#include <util/delay.h>

#define FOSC 1843200  // System oscillator clock frequency (Hz).
#define BAUD 9600     // Baud rate in bits per second (bps).
#define MY_UBRR FOSC/16/BAUD-1  // UART Baud Rate Register.

void usart_init(unsigned int ubrr) {
	// Set baud rate.
	UBRRH = (unsigned char)(ubrr >> 8);
	UBRRL = (unsigned char)(ubrr);
	// UBRRH = USART Baud Rate Register High.
	// UBRRL = USART Baud Rate Register Low.

	// Enable receiver and transmitter.
	UCSRB = (1 << RXEN) | (1 << TXEN);
	// UCSRB = USART Control and Status Register B.
	// RXEN = Receiver Enabled.
	// TXEN = Transmitter Enabled.

	// Set frame format: 1 stop bit, 8 data bits.
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	// UCSRC = (1 << URSEL) | (0 << USBS) | (1 << UCSZ0) | (1 << UCSZ1);
	// UCSRC = USART Control and Status Register C.
	// URSEL = USART Register Select.
	// USBS = USART Stop Bit Select (0 -> 1b, 1 -> 2b).
	// USZ0 = USART Character Size.
	
	
	// For debugging purposes.
	DDRB = DDRB | (1 << PB0) | (1 << PB1);
}

void usart_transmit(uint8_t data) {
	// Wait for empty transmit buffer.
	while (!(UCSRA & (1 << UDRE))) {
	};
	// UCSRA = USART Control and Status Register A.
	// UDRE = USART Data Register Empty.
	
	// TODO: What about buffer overflow etc?
	UDR = data;
	// UDR = USART Data Register.
	
	PORTB = PORTB ^ (1 << PB1);
	_delay_ms(500);
}

uint8_t usart_receive(void) {
	while (!(UCSRA & (1 << RXC))) {
	};
	
	PORTB = PORTB ^ (1 << PB1);
	_delay_ms(500);
	
	return UDR;
	// UCSRA = USART Control and Status Register A.
	// RXC = USART Receive Complete.
}

int main(void) {
	usart_init(1);
	
	while (1) {
		// PORTB = PORTB ^ (1 << PB0);
		// usart_transmit(usart_receive());
		
		// Wait for empty transmit buffer.
		while (!(UCSRA & (1 << UDRE))) {
		};
		// UCSRA = USART Control and Status Register A.
		// UDRE = USART Data Register Empty.
		
		// TODO: What about buffer overflow etc?
		// unsigned char data = 0b0111111111;
		UDR = 0b11111111;
		// UDR = USART Data Register.
		
		PORTB = PORTB ^ (1 << PB1);
		_delay_ms(500);
	}
}
