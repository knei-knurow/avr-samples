# Running the code

### Compile

`DF_CPU=1000000UL` sets `F_CPU` to 1MHz

`avr-gcc -mmcu=atmega8 -Wall -Os -o blink.elf blink.c -DF_CPU=1000000UL `

### Link / copy objects ??? idk

`avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex`

### Flash

`avrdude -c usbasp -p m8 -e -U flash:w:blink.hex`

# Editor setup (VS Code)

To make IntelliSense detect AVR header files, make the editor aware of them.

E.g if you installed `avr-gcc` using Homebrew, do:

`homebrew ls avr-gcc`

it should print sth like this (among others):

/usr/local/Cellar/avr-gcc/9.3.0/avr/include/
...

now that `/usr/local/Cellar/avr-gcc/9.3.0/avr/include/` is the line that should be added to `<project_root>/.vscode/settings.json`

```json
"C_Cpp.default.systemIncludePath": [
    "/usr/local/Cellar/avr-gcc/9.3.0/avr/include"
  ]
```
