TARGET = main

MCU = atmega328p

F_CPU = 16000000UL

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra

AVRDUDE_PROGRAMMER = arduino
#AVRDUDE_PORT = /dev/ttyUSB0 linux
AVRDUDE_PORT = COM5 #window
AVRDUDE_BAUDRATE = 115200

SRCS = $(shell ls *.c)

OBJS = $(SRCS:.c=.o)

all: $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

upload: $(TARGET).hex
	$(AVRDUDE) -p $(MCU) -c $(AVRDUDE_PROGRAMMER) -P $(AVRDUDE_PORT) -b $(AVRDUDE_BAUDRATE) -U flash:w:$<:i

clean:
	rm -f *.o *.elf *.hex

.PHONY: all clean upload