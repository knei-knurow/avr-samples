#define __AVR_ATmega8A__
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRB = DDRB | (1 << PB1);  // Data Direction Register for port B

  while (1) {
    PORTB = 0;
    for (int i = 0; i < 3; i++) {
      PORTB = PORTB + 1;
      _delay_ms(500);
    }
  }
}
