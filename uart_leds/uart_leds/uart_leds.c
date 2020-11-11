#define __AVR_ATmega8A__
#include <avr/io.h>
#include <util/delay.h>

#define BAUD 9600                     // Baud rate in bits per second (bps).
#define MY_UBRR F_CPU / 8 / BAUD - 1  // UART Baud Rate Register.

void usart_init(unsigned int ubrr) {
  // Set baud rate.
  UBRRH = (uint8_t)(ubrr >> 8);
  UBRRL = (uint8_t)(ubrr);

  // Enable receiver and transmitter.
  UCSRB = (1 << RXEN) | (1 << TXEN);

  // Double the USART transmission speed.
  UCSRA = (1 << U2X);

  // Set frame format: 1 stop bit, 8 data bits.
  UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void usart_transmit(uint8_t data) {
  // Wait for empty transmit buffer.
  while (!(UCSRA & (1 << UDRE))) {
  }

  UDR = data;
}

uint8_t usart_receive(void) {
  while (!(UCSRA & (1 << RXC))) {
  };

  return UDR;
}

int main(void) {
  usart_init(MY_UBRR);
  DDRB = 0xFF;
  PORTB = 0xFF;

  while (1) {
    // From interrupt.
    uint8_t mask = usart_receive();
    DDRB = DDRB ^ mask;

    // PORTB = 1;
    // for (int i = 0; i < 8; i++) {
    //   PORTB = PORTB << 1;
    // }
  }
}
