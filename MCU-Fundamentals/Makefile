# Prepared by Abdelrahman Kamal ($(Project_name))

CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS = -I.
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = Unit6-Labs

all: $(Project_name).bin
	@echo "--Build is Done--"

%.o: %.s 
	$(CC)as $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc $(CFLAGS) $(INCS) -c $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld $(OBJ) $(AsOBJ) $(LIBS)-o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy -O binary $< $@


clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin

