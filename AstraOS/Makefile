ASM = nasm
CC = i686-elf-gcc
LD = i686-elf-ld

CFLAGS = -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -T linker.ld -nostdlib

OBJS =  \
 src/kernel/boot/boot.o \
 src/kernel/kernel.o \
 src/kernel/drivers/keyboard.o \
 src/kernel/drivers/timer.o \
 src/kernel/drivers/vga.o \
 src/kernel/memory/paging.o \
 src/userland/apps/shell/main.o

all: os-image.bin

src/kernel/boot/boot.o: src/kernel/boot/boot.asm
	$(ASM) -f elf32 $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o kernel.bin $(OBJS)

os-image.bin: kernel.bin
	cat src/kernel/boot/bootloader.bin kernel.bin > os-image.bin

run:
	qemu-system-i386 -drive format=raw,file=os-image.bin

clean:
	rm -f $(OBJS) kernel.bin os-image.bin
