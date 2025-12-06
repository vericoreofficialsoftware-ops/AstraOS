#pragma once
#include <stdint.h>
#include <stddef.h>

/* Framebuffer info (bootloader tarafından doldurulacak) */
extern uint8_t *framebuffer; /* pointer to framebuffer */
extern uint32_t fb_width;
extern uint32_t fb_height;
extern uint32_t fb_pitch;
extern uint32_t fb_bpp; /* bits per pixel, e.g. 32 */

void vga_init_from_bootinfo(uint8_t *fb, uint32_t width, uint32_t height, uint32_t pitch, uint32_t bpp);
void putpixel(int x, int y, uint32_t color);
void draw_rect(int x, int y, int w, int h, uint32_t color);
void draw_background(uint32_t color);
void draw_window_oval(int x, int y, int w, int h, uint32_t color);
void draw_text(int x, int y, const char *s, uint32_t color);
