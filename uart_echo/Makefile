flash: uart_echo.hex
	avrdude -c usbasp -p m8 -e -U flash:w:uart_echo.hex

uart_echo.hex: uart_echo.elf
	avr-objcopy -j .text -j .data -O ihex uart_echo.elf uart_echo.hex

uart_echo.elf: uart_echo.c
	avr-gcc -mmcu=atmega8 -Wall -Os -o uart_echo.elf uart_echo.c -DF_CPU=1000000UL

clean:
	rm -rf *.hex *.elf *.o
