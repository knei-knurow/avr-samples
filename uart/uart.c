#define __AVR_ATmega8A__
#include <avr/io.h>
#include <util/delay.h>

const long int FOSC = 1843200;  // System oscilator clock frequency (Hz).
const long int BAUD = 9600;     // Baud rate in bits per second (bps).
const long int MY_UBRR = (FOSC / (16 * BAUD)) - 1;  // UART Baud Rate Register.

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
  UCSRC = (1 << URSEL) | (0 << USBS) | (3 << UCSZ0);
  // UCSRC = (1 << URSEL) | (1 << USBS) | (1 << UCSZ0) | (1 << UCSZ1);
  // UCSRC = USART Control and Status Register C.
  // URSEL = USART Register Select.
  // USBS = USART Stop Bit Select (0 -> 1b, 1 -> 2b).
  // USZ0 = USART Character Size.
}

inline void usart_transmit(unsigned char data) {
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
  return '0';
}

int main(void) {
  usart_init(MY_UBRR);
  while (1) {
    for (int i = 0; i < 4; i++) {
      _delay_ms(1000);
      usart_transmit(0b0001100001);
    }
  }
}
