#Cross Compiler
CC=arm-none-eabi-gcc

#Config files directory
CONFIGDIR=config/

#Source files directory
SRC=src/

#Build files directory
BUILD=build/

#Drivers include files directory
DRIVERINC=drivers/inc/

#Drivers source files directory
DRIVERSRC=drivers/src/

#Bsp files directory
BSPDIR=bsp/

#Target Machine
MACH=cortex-m4

#Compiler flags
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
#linker flags
LDFLAGS= -nostdlib -T $(CONFIGDIR)STM32F411VETX_LINKER.ld -Wl,-Map=$(BUILD)main.map

SOURCES= $(CONFIGDIR)stm32f411vetx_startup.c $(SRC)main.c $(DRIVERSRC)stm32f411xx_gpio.c $(DRIVERSRC)stm32f411xx_spi.c #Add other source files
OBJ= $(patsubst %.c, $(BUILD)%.o, $(notdir $(SOURCES)))

#-------------------------------------------------------------------------------------------------------------------

all:$(BUILD)main.elf

# Create the build directory if it doesn't exists
$(BUILD):
	mkdir -p $(BUILD)

#compile stm32f411vetx_startup.c
$(BUILD)stm32f411vetx_startup.o: $(CONFIGDIR)stm32f411vetx_startup.c | $(BUILD)
	$(CC) $(CFLAGS) -o $@ $^

#compile main.c
$(BUILD)main.o: $(SRC)main.c | $(BUILD)
	$(CC) $(CFLAGS) -I$(DRIVERINC) -o $@ $^

#compile stm32f411xx_gpio.c
$(BUILD)stm32f411xx_gpio.o: $(DRIVERSRC)stm32f411xx_gpio.c | $(DRIVERSRC)
	$(CC) $(CFLAGS) -I$(DRIVERINC) -o $@ $^

#compile stm32f411xx_spi.c
$(BUILD)stm32f411xx_spi.o: $(DRIVERSRC)stm32f411xx_spi.c | $(DRIVERSRC)
	$(CC) $(CFLAGS) -I$(DRIVERINC) -o $@ $^

#Link all the object files
$(BUILD)main.elf: $(BUILD) | $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(BUILD)*.o

#Clean the build directory
clean:
	rm -rf $(BUILD)

#Load the executable and linkable file into the target
load:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
