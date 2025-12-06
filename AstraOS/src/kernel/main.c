#include "installer_screen.h"

void kmain() {
    vga_init();
    gui_init();

    show_installer();

    while (1) {
        gui_update();
    }
}
