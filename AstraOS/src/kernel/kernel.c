#include "kernel.h"
#include "drivers/keyboard.h"
#include "drivers/timer.h"
#include "drivers/vga.h"

void kernel_main() {
    vga_clear();
    vga_print("AstraOS Kernel Yuklendi!\n");

    init_timer(50);
    init_keyboard();

    while(1);
}
extern void installer_screen();

void kernel_main()
{
    installer_screen();
    while (1);
}
