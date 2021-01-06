#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRB = 0b11111111;  // set all pins to OUT

  while (1) {
    PORTB = 1;
    for (int i = 0; i < 8; i++) {
      _delay_ms(500);  // delay has to be first (because of pin0)
      PORTB = PORTB << 1;
    }
  }
}
