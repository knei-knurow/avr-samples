#define __AVR_ATmega8A__
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRB = DDRB | (1 << PB1);  // Data Direction Register for port B. Set it to 1.
                             // 1 means it is output pin.

  while (1) {
    _delay_ms(1000);
    PORTB = PORTB ^ (1 << PB0);
    PORTB = PORTB ^ (1 << PB1);
  }
}
