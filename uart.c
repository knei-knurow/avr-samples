#define __AVR_ATmega8A__
#include <avr/io.h>
#include <util/delay.h>

const int FOSC = 1843200;  // System oscilator clock frequency (Hz).
const int BAUD = 9600;     // Baud rate in bits per second (bps).
const int MY_UBRR = (FOSC / (16 * BAUD)) - 1;  // UART Baud Rate Register.

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

  // Set frame format: 8 data bits, 2 stop bits.
  UCSRC = (1 << URSEL) | (1 << USBS) | (3 << UCSZ0);
  // UCSRC = USART Control and Status Register C.
  // URSEL = USART Register Select.
  // USBS = USART Stop Bit Select (0 -> 1b, 1 -> 2b).
  // USZ0 = USART Character Size.
}

void usart_transmit(unsigned char data) {
  // Wait for empty transmit buffer.
  while (!(UCSRA & (1 << UDRE))) {
  };
  // UCSRA = USART Control and Status Register A.
  // UDRE = USART Data Register Empty.

  // TODO: What about buffer overflow etc?
  UDR = data;
  // UDR = USART Data Register.
}

unsigned char usart_receive(void) {
  // TODO
}

int main(void) {
  usart_init(MY_UBRR);
  for (int i = 0; i < 4; i++) {
  }
}
