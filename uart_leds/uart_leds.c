#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define BAUD 9600                     // Baud rate in bits per second (bps).
#define MY_UBRR F_CPU / 8 / BAUD - 1  // UART Baud Rate Register.

void usart_init(unsigned int ubrr) {
  // Set baud rate.
  UBRRH = (uint8_t)(ubrr >> 8);
  UBRRL = (uint8_t)(ubrr);

  // Enable receiver, transmitter, and receive interrupts.
  UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);

  // Double the USART transmission speed.
  UCSRA = (1 << U2X);

  // Set frame format: 1 stop bit, 8 data bits.
  UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

uint8_t usart_receive(void) {
  while (!(UCSRA & (1 << RXC))) {
  };

  return UDR;
}

ISR(USART_RXC_vect) {
  // Read a single byte from USART Data Register.
  uint8_t mask = UDR;

  DDRB = DDRB ^ mask;
}

int main(void) {
  usart_init(MY_UBRR);

  // Enable interrupts.
  sei();
  DDRB = 0xFF;

  while (1) {
    PORTB = 1;
    for (int i = 0; i < 8; i++) {
      _delay_ms(500);
      PORTB = PORTB << 1;
    }
  }
}
