#@copyright: Mark
P_NAME=lab3_unit3
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -mthumb -gdwarf-2 -g -std=c99 
#@to include files or other directories or even the pwd
INCS=-I .
#@other libraries to be included in the linkerscript
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
ASS=$(wildcard *.s)
A_OBJ=$(ASS:.s=.o)

all:$(P_NAME).bin
	@echo "DONE"
#@startup.o:startup.s
#@	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS)  $< -o $@

$(P_NAME).elf:$(A_OBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(A_OBJ) $(OBJ) -o $@ -Map=Map_file.map
	cp $(P_NAME).elf $(P_NAME).axf

$(P_NAME).bin:$(P_NAME).elf
	$(CC)objcopy.exe -O binary  $< $@

