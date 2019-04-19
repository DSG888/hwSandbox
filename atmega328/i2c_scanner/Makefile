CC = avr-gcc
MCU = -mmcu=atmega328p
HEXMAKER = avr-objcopy
CFLAGS = -std=c99 -Os -Wall
SOURCES = main.c i2c.c uart.c
EXECUTABLE = main.hex

all: $(SOURCES)
	$(CC) $(MCU) $(CFLAGS) -o main.o $(SOURCES)
	$(HEXMAKER) -O ihex main.o $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) main.o

flash: all
	avrdude -c usbtiny -p atmega328p -U flash:w:$(EXECUTABLE)
