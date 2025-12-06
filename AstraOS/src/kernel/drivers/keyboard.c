#include <stdint.h>
#include "keyboard.h"

volatile uint8_t last_scancode = 0;

uint8_t keyboard_read_scancode_poll() {
    uint8_t status = 0;
    __asm__ volatile ("inb %%dx, %%al" : "=a"(status) : "d"(0x64));
    if (status & 1) {
        uint8_t sc;
        __asm__ volatile ("inb %%dx, %%al" : "=a"(sc) : "d"(0x60));
        last_scancode = sc;
        return sc;
    }
    return 0;
}

/* translate a few scancodes to virtual keys */
int keyboard_translate_scancode(uint8_t sc) {
    if (sc == 0x1C) return KEY_ENTER;
    if (sc == 0x48) return KEY_UP;
    if (sc == 0x50) return KEY_DOWN;
    if (sc == 0x4B) return KEY_LEFT;
    if (sc == 0x4D) return KEY_RIGHT;
    /* map numbers/letters if you want */
    return 0;
}
