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
the MCU (micro-controller unit) to your PC using a [USBasp](https://www.fischl.de/usbasp) programmer.

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

## macOS

First things first: you need [Homebrew](https://brew.sh).

1. Install [`avrdude`](https://www.nongnu.org/avrdude) - a small program used to flash AVR microcontrollers

   `brew install avrdude`

2. Install [`avr-gcc`](https://gcc.gnu.org/wiki/avr-gcc) - an AVR-flavor of [GNU GCC](https://gcc.gnu.org)

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

Example (for avr-gcc v9.3.0 and using headers for ATmega8A)

```json
{
  "C_Cpp.default.includePath": [" /usr/local/Cellar/avr-gcc@9/9.3.0_2/avr/include/"],
  "C_Cpp.default.defines": ["__AVR_ATmega8A__"]
}
```

Voilà, IntelliSense should work now.

## Windows

1. Install `avr-gcc` - an AVR-flavor of [GNU GCC](https://gcc.gnu.org).
   [This version](https://blog.zakkemble.net/avr-gcc-builds) (which we recommend ) contains
   also `avrdude`, `make` and a couple other GNU tools, so you won't have to install them
   separately. Install it to your home directory (e.g `C:\Users\Bartek`) so that it'll be easy
   to find - in our case, it's `C:\Users\Bartek\avr-gcc`

2. Add the location where you installed `avr-gcc` to `$PATH` ([how to add items to path on Windows?](https://helpdeskgeek.com/windows-10/add-windows-path-environment-variable))

3. Install a [C/C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) for VSCode

4. To make VSCode's IntelliSense detect AVR header files, make the editor aware of them.
   For this, you'll need to know the exact location of your `avr-gcc` installation. In our case
   it was `C:\Users\Bartek\avr-gcc`. To that location, we need append `\bin`, like
   this: `C:\Users\Bartek\avr-gcc\bin`

Example (using headers for ATmega8A)

**.vscode/settings.json**

```json
{
  "C_Cpp.default.includePath": ["C:\\Users\\Bartek\\avr-gcc\\avr\\include"],
  "C_Cpp.default.defines": ["__AVR_ATmega8A__"]
}
```

This is almost enough, but chances are, if you use `sei()` or `ISR` functions for interrupts,
your IntelliSense will show errors. To fix them, create a new file named `c_cpp_properties.json`
in `.vscode` directory in this project's root with the following content:

**.vscode/c_cpp_properties.json**

```json
{
  "configurations": [
    {
      "name": "Win32",
      "includePath": ["${default}"],
      "cStandard": "c99",
      "cppStandard": "c++17",
      "intelliSenseMode": "gcc-x64"
    }
  ],
  "version": 4
}
```

Voilà, IntelliSense should work just fine.
