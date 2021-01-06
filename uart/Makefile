flash: uart.hex
	avrdude -c usbasp -p m8 -e -U flash:w:uart.hex

uart.hex: uart.elf
	avr-objcopy -j .text -j .data -O ihex uart.elf uart.hex

uart.elf: uart.c
	avr-gcc -mmcu=atmega8 -Wall -Os -o uart.elf uart.c -DF_CPU=1000000UL

clean:
	rm -rf *.hex *.elf *.o
