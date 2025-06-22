#Cross Compiler
CC=arm-none-eabi-gcc

#Config files directory
CONFIGDIR=config/

#Source files directory
SRC=app/

#Build files directory
BUILD=build/

#Drivers include files directory
DRIVERINC=drivers/inc/

#Drivers source files directory
DRIVERSRC=drivers/src/

#Bsp files directory
#Uncomment if you want to add bsp
#BSPDIR=bsp/

#Target Machine
MACH=cortex-m4

#Compiler flags
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
#linker flags
LDFLAGS= -nostdlib -T $(CONFIGDIR)STM32F411VETX_LINKER.ld -Wl,-Map=$(BUILD)app.map

SOURCES= $(CONFIGDIR)stm32f411vetx_startup.c $(SRC)app.c $(DRIVERSRC)stm32f411xx_gpio.c $(DRIVERSRC)stm32f411xx_spi.c #Add other source files
OBJ= $(patsubst %.c, $(BUILD)%.o, $(notdir $(SOURCES)))

#-------------------------------------------------------------------------------------------------------------------

# Build all outputs
all: $(BUILD)app.hex $(BUILD)app.bin

# Create the build directory if it doesn't exists
$(BUILD):
	mkdir -p $(BUILD)

#compile stm32f411vetx_startup.c
$(BUILD)stm32f411vetx_startup.o: $(CONFIGDIR)stm32f411vetx_startup.c | $(BUILD)
	$(CC) $(CFLAGS) -o $@ $^

#compile app.c
$(BUILD)app.o: $(SRC)app.c | $(BUILD)
	$(CC) $(CFLAGS) -I$(DRIVERINC) -o $@ $^

#compile stm32f411xx_gpio.c
$(BUILD)stm32f411xx_gpio.o: $(DRIVERSRC)stm32f411xx_gpio.c | $(DRIVERSRC)
	$(CC) $(CFLAGS) -I$(DRIVERINC) -o $@ $^

#compile stm32f411xx_spi.c
$(BUILD)stm32f411xx_spi.o: $(DRIVERSRC)stm32f411xx_spi.c | $(DRIVERSRC)
	$(CC) $(CFLAGS) -I$(DRIVERINC) -o $@ $^

#Link all the object files
$(BUILD)app.elf: $(BUILD) | $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(BUILD)*.o

# Generate hex file
$(BUILD)app.hex: $(BUILD)app.elf
	arm-none-eabi-objcopy -O ihex $< $@

# Generate binary file
$(BUILD)app.bin: $(BUILD)app.elf
	arm-none-eabi-objcopy -O binary $< $@

#Clean the build directory
clean:
	rm -rf $(BUILD)

#Load the executable and linkable file into the target
load:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
