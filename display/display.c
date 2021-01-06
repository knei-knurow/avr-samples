#include <avr/io.h>
#include <util/delay.h>
#include "HD44780.h"

int main(void) {
  DDRB = 0b11111111;  // set all pins to OUT

  LCD_Initalize();
  LCD_Clear();

  char* msg = "hey";

  LCD_WriteText(msg);

  while (1) {
  }
}
