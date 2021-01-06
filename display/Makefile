flash: display.hex
	avrdude -c usbasp -p m8 -e -U flash:w:display.hex flash:w:HD44780.hex

display.hex: display.elf HD44780.elf
	avr-objcopy -j .text -j .data -O ihex display.elf display.hex
	avr-objcopy -j .text -j .data -O ihex HD44780.elf HD44780.hex

display.elf: display.c HD44780.c
	avr-gcc -mmcu=atmega8 -Wall -Os -o display.elf display.c -DF_CPU=1000000UL -L
	avr-gcc -mmcu=atmega8 -Wall -Os -o HD44780.elf HD44780.c -DF_CPU=1000000UL -L

clean:
	rm -rf *.hex *.elf *.o
