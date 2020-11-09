> work in progress

# AVR for beginners

This repository is intended to contain detailed instructions on how to
get started with programming Atmel AVR microcontrollers. It also contains
a bunch of thoroughly documented and explained example projects.

Recommended websites:

- http://mikrokontrolery.blogspot.com/p/spis-tresci.html (in Polish)

### Running the code

This repository contains several folders. Each of those folders is
a self-contained project that can be opened either in Atmel Studio
or VS Code.

The fast & easy way to get started: wire everything up properly, connect
the MCU to your PC using a USBasp programmer,

0. Wire up your circuit correctly on the breadboard.
1. Connect the MCU to your PC using a USBasp programmer
2. `cd <on of the project>`, for example `cd blink`
3. `make flash`

# What Makefiles do, explained

### Compile

First, you need to compile a C source file to an .elf object file.

`avr-gcc -mmcu=atmega8 -Wall -Os -o blink.elf blink.c -DF_CPU=1000000UL `

> `DF_CPU=1000000UL` sets `F_CPU` to 1MHz.

### Convert .elf to .hex

To flash the MCU using USBasp programmer, you need a .hex file. It can be
created out of the .elf file you generated in the previous step.

`avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex`

### Flash

Now it's time to run the code

`avrdude -c usbasp -p m8 -e -U flash:w:blink.hex`

# Setup with VSCode

## MacOS

First things first: you need [Homebrew](https://brew.sh).

1. Install avrdude - a small program used to flash AVR microcontrollers.

   `brew install avrdude`

2. Install avr-gcc - AVR-flavor of [GNU GCC](https://gcc.gnu.org)

   `brew tap osx-cross/avr`

   `brew install avr-gcc`

3. Install a [C/C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) for VSCode

4. To make VSCode's IntelliSense detect AVR header files, make the editor aware of them.
   For this, you'll need to know the exact version of your `avr-gcc` installation:
   `brew ls avr-gcc`

It prints a list which contains:

```
/usr/local/Cellar/avr-gcc/<version>/avr/include/
```

Copy that line, replacing <version> with your version.

Now, in project root, create a `.vscode` folder. In it, create `settings.json`
file with the following content:

```json
"C_Cpp.default.systemIncludePath": [
    "/usr/local/Cellar/avr-gcc/<version>/avr/include"
  ]
```

Voilà, IntelliSense should work now.

## Windows

coming soon

# Setup with Atmel Studio (only on Windows)

coming soon
