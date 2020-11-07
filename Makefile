validate:
	if [ -z $(FILE) ]; then								\
		printf "error: file not entered\n";	\
		exit 1;															\
	fi;																		\
	make flash

flash: $(FILE).hex
	avrdude -c usbasp -p m8 -e -U flash:w:$(FILE).hex

$(FILE).hex: $(FILE).elf
	avr-objcopy -j .text -j .data -O ihex $(FILE).elf $(FILE).hex


$(FILE).elf: $(FILE).c
	avr-gcc -mmcu=atmega8 -Wall -Os -o $(FILE).elf $(FILE).c -DF_CPU=1000000UL


clean:
	rm -rf *.hex *.elf *.o