flash: uart_leds.hex
	avrdude -c usbasp -p m8 -e -U flash:w:uart_leds.hex

uart_leds.hex: uart_leds.elf
	avr-objcopy -j .text -j .data -O ihex uart_leds.elf uart_leds.hex

uart_leds.elf: uart_leds.c
	avr-gcc -mmcu=atmega8 -Wall -Os -o uart_leds.elf uart_leds.c -DF_CPU=1000000UL

clean:
	rm -rf *.hex *.elf *.o
