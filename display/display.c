#include <avr/io.h>
#include <util/delay.h>
#include "../libraries/hd44780/HD44780.h"

int main(void) {
  DDRB = 0b11111111;  // set all pins to OUT

  LCD_Initalize();
  LCD_GoTo(0, 0);
  LCD_Clear();

  char* msg = "hey";

  LCD_WriteText(msg);

  while (1) {
  }
}
