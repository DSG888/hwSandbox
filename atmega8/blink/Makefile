#avr-gcc -mmcu=atmega8 -I. -gdwarf-2 -Os -o main.o z.c
#avr-objcopy -O ihex main.o main.hex

CC = avr-gcc
MCU = -mmcu=atmega8
HEXMAKER = avr-objcopy
CFLAGS = -std=c99 -Os -Wall
SOURCES = main.c
OBJECT_FILES = $(SOURCES:.c=.o)
EXECUTABLE = main.hex

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECT_FILES)
	$(HEXMAKER) -O ihex $(OBJECT_FILES) $@

%.o: %.c
	$(CC) $(MCU) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(EXECUTABLE) $(OBJECT_FILES)

flash: all
	avrdude -c usbtiny -p atmega8 -U flash:w:$(EXECUTABLE)
