MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Iinc

all: firmware.hex

firmware.elf: src/main.c
	$(CC) $(CFLAGS) src/main.c -o firmware.elf

firmware.hex: firmware.elf
	$(OBJCOPY) -O ihex firmware.elf firmware.hex

clean:
	rm -f *.elf *.hex