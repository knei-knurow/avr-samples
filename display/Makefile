MCU := atmega8
INCLUDE := -I${CURDIR}/../libraries/hd44780
LIBDIRS := -L${CURDIR}/../libraries/hd44780
LIBS := -lhd44780

flash: display.hex
	avrdude -c usbasp -p m8 -e -U flash:w:display.hex

display.hex: display.elf
	avr-objcopy -j .text -j .data -O ihex display.elf display.hex

display.elf: display.c
	avr-gcc -o display.elf -mmcu=$(MCU) -Wall -Os display.c -DF_CPU=1000000UL $(INCLUDE) $(LIBDIRS) $(LIBS)

clean:
	rm -rf *.hex *.elf *.o
