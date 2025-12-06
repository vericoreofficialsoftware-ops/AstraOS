#include "framebuffer.h"

void installer_screen()
{
    for (int y = 0; y < 25; y++)
        for (int x = 0; x < 80; x++)
            putpixel(x, y, 1);  // mavi background

    // Basit yazı
    print_text(30, 2, "ASTRAOS KERNEL INSTALLER SIMULATION");
}
#include "vga.h"
#include "gui.h"

void show_installer() {
    gui_clear_screen(0x001F); // mavi
    gui_draw_rounded_rect(200, 100, 400, 300, 30, 0x000000);  // panel
    gui_draw_text(280, 130, "AstraOS Kurulum", 0xFFFFFF);

    gui_button(300, 220, 200, 40, "AstraOS'i Yükle", 0x0057FF);
    gui_button(300, 280, 200, 40, "Çıkış", 0x0057FF);
}
