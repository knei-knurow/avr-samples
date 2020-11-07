#define __AVR_ATmega8A__
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRB = 7;  // set all pins to OUT

  while (1) {
    PORTB = 1;
    for (int i = 0; i < 8; i++) {
      PORTB = PORTB << 1;
      _delay_ms(500);
    }
  }
}
