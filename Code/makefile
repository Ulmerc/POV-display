# -*- MakeFile -*-

MCU = -mmcu=atmega168p
CC = avr-gcc $(MCU)
OBJCOPY = avr-objcopy
CFLAGS = -c -O0
LDFLAGS = 
OBJCFLAGS = -O ihex
OBJS = main.o character_storage.o interrupts.o photodiode.o timer0.o usart.o spi.o usartTestCode.o
EXE = main

# Target: dependencies/prerequsites
#	action

all: $(OBJS)
	 $(CC) $(LDFLAGS) $(OBJS) -o $(EXE).elf
	 $(OBJCOPY) $(OBJCFLAGS) $(EXE).elf $(EXE).hex

main.o: main.c  
	$(CC) $(CFLAGS) $^ -o $@

character_storage.o: character_storage.c
	$(CC) $(CFLAGS) $^ -o $@

interrupts.o: interrupts.c
	$(CC) $(CFLAGS) $^ -o $@

photodiode.o: photodiode.c
	$(CC) $(CFLAGS) $^ -o $@

timer0.o: timer0.c
	$(CC) $(CFLAGS) $^ -o $@

usart.o: usart.c
	$(CC) $(CFLAGS) $^ -o $@

spi.o: spi.c
	$(CC) $(CFLAGS) $^ -o $@

usartTestCode.o: usartTestCode.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm *.o $(EXE).elf $(EXE).hex

flash: all
	sudo avrdude -c avrispmkII -p m168p -P usb -U flash:w:$(EXE).hex
