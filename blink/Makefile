CC := avr-gcc
MCU := atmega328p

flash: blink.hex
	avrdude -c usbasp -p m8 -e -U flash:w:blink.hex

blink.hex: blink.elf
	avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex

blink.elf: blink.c
	$(CC) -mmcu=atmega8 -Wall -Os -o blink.elf blink.c -DF_CPU=1000000UL

clean:
	rm -rf *.hex *.elf *.o
