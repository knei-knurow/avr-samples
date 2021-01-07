all: HD44780.c
	avr-gcc -mmcu=atmega8 -Wall -Os -DF_CPU=1000000UL -c HD44780.c
	avr-ar rcs libhd44780.a HD44780.o

clean:
	rm -rf *.o *.a
