program: flash
	gcc main.o message.o -o program

# main.o: $(FILE).c
#	gcc -c main.c

$(FILE).c:
	printf "lol\n"

elf: $(FILE).c
	cd src && avr-gcc -mmcu=atmega8 -Wall -Os -o $(FILE).elf $(FILE).c -DF_CPU=1000000UL

hex: elf
	cd src && avr-objcopy -j .text -j .data -O ihex $(FILE).elf $(FILE).hex

flash: hex
	cd src && avrdude -c usbasp -p m8 -e -U flash:w:$(FILE).hex

clean:
	cd src && rm -rf *.hex *.elf *.o