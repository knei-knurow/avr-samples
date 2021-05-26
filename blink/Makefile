flash: blink.hex
	avrdude -c usbasp -p m328p -e -U flash:w:blink.hex

blink.hex: blink.elf
	avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex

blink.elf: blink.c
	avr-gcc -mmcu=atmega328p -Wall -Os -o blink.elf blink.c -DF_CPU=16000000UL

clean:
	rm -rf *.hex *.elf *.o
