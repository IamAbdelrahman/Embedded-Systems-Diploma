# Prepared by Abdelrahman Kamal ($(Project_name))

# Define the cross-compiler and compiler flags
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m3 -mthumb -gdwarf-2 -g
INCS = -I.

# Directories
APP_DIR = APP
MCAL_DIR = MCAL
HAL_DIR = HAL
GPIO_DIR = $(MCAL_DIR)/GPIO
LED_DIR = $(HAL_DIR)/LED
PSENSOR_DIR = $(HAL_DIR)/Pressure_Sensor

# Source files
APP_SRC = $(wildcard $(APP_DIR)/*.c)
MCAL_SRC = $(wildcard $(MCAL_DIR)/*.c) $(wildcard $(GPIO_DIR)/*.c)
HAL_SRC = $(wildcard $(LED_DIR)/*.c) $(wildcard $(PSENSOR_DIR)/*.c)
SRC = $(wildcard *.c)

# Object files
APP_OBJ = $(patsubst %.c, %.o, $(APP_SRC))
MCAL_OBJ = $(patsubst %.c, %.o, $(MCAL_SRC))
HAL_OBJ = $(patsubst %.c, %.o, $(HAL_SRC))
OBJ = $(SRC:.c=.o)

# Specify the project name
Project_name = Pressure_Detection_System

all: $(Project_name).bin
	@echo "--Build is Done--"

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(Project_name).elf: $(APP_OBJ) $(MCAL_OBJ) $(HAL_OBJ) $(OBJ)
	$(LD) -T linker_script.ld $(APP_OBJ) $(MCAL_OBJ) $(HAL_OBJ) $(OBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f $(APP_OBJ) $(MCAL_OBJ) $(HAL_OBJ) $(OBJ) $(Project_name).elf $(Project_name).bin Map_file.map

.PHONY: all clean
