#include <stdint.h>

uint8_t* framebuffer = (uint8_t*)0x000B8000;

void putpixel(int x, int y, uint8_t color)
{
    framebuffer[(y * 80 + x) * 2] = ' ';
    framebuffer[(y * 80 + x) * 2 + 1] = color;
}
