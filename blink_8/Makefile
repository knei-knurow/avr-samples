flash: blink_8.hex
	avrdude -c usbasp -p m8 -e -U flash:w:blink_8.hex

blink_8.hex: blink_8.elf
	avr-objcopy -j .text -j .data -O ihex blink_8.elf blink_8.hex


blink_8.elf: blink_8.c
	avr-gcc -mmcu=atmega8 -Wall -Os -o blink_8.elf blink_8.c -DF_CPU=1000000UL


clean:
	rm -rf *.hex *.elf *.o