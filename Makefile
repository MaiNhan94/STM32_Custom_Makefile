CC=arm-none-eabi-gcc
PROJ_NAM=uart_test
All:
	make clear
	$(CC) -mcpu=cortex-m3 -c -x assembler-with-cpp -o "startup.o" "startup_stm32f103c8tx.s"
	$(CC) "main.c" -mcpu=cortex-m3 -std=gnu11 -c -o "main.o"
	$(CC) -o $(PROJ_NAM).elf "main.o" "startup.o"   -mcpu=cortex-m3 -T"link.ld" -Wl,-Map="mapFile.map" -Wl,--gc-sections -static 
	arm-none-eabi-objcopy  -O binary  $(PROJ_NAM).elf   $(PROJ_NAM).bin
clear:
	-rm *.bin
	-rm *.elf
	-rm *.o


