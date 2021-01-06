/**
 * This program listens for a byte on RX and responds with the byte on TX.
 */

#define __AVR_ATmega8A__
#include <avr/io.h>
#include <util/delay.h>

#define BAUD 9600                     // Baud rate in bits per second (bps).
#define MY_UBRR F_CPU / 8 / BAUD - 1  // UART Baud Rate Register.

void usart_init(unsigned int ubrr) {
  // Set baud rate.
  UBRRH = (uint8_t)(ubrr >> 8);
  UBRRL = (uint8_t)(ubrr);
  // UBRRH = USART Baud Rate Register High.
  // UBRRL = USART Baud Rate Register Low.

  // Enable receiver and transmitter.
  UCSRB = (1 << RXEN) | (1 << TXEN);
  // UCSRB = USART Control and Status Register B.
  // RXEN = Receiver Enabled.
  // TXEN = Transmitter Enabled.

  // Double the USART transmission speed.
  UCSRA = (1 << U2X);

  // Set frame format: 1 stop bit, 8 data bits.
  UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
  // UCSRC = (1 << URSEL) | (1 << USBS) | (1 << UCSZ0) | (1 << UCSZ1);
  // UCSRC = USART Control and Status Register C.
  // URSEL = USART Register Select.
  // USBS = USART Stop Bit Select (0 -> 1b, 1 -> 2b).
  // USZ0 = USART Character Size.
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
}

uint8_t usart_receive(void) {
  while (!(UCSRA & (1 << RXC))) {
  };
  // UCSRA = USART Control and Status Register A.
  // RXC = USART Receive Complete.

  return UDR;
}

int main(void) {
  usart_init(MY_UBRR);

  while (1) {
    usart_transmit(usart_receive());
  }
}
