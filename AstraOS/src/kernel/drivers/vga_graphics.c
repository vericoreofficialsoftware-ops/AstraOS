#include "vga_graphics.h"
#include "font.h"   /* basit 8x8 bitmap font */

uint8_t *framebuffer = 0;
uint32_t fb_width = 0, fb_height = 0, fb_pitch = 0, fb_bpp = 0;

/* Initialize using data from bootloader (pass these values from GRUB multiboot) */
void vga_init_from_bootinfo(uint8_t *fb, uint32_t width, uint32_t height, uint32_t pitch, uint32_t bpp) {
    framebuffer = fb;
    fb_width = width; fb_height = height; fb_pitch = pitch; fb_bpp = bpp;
}

/* Put pixel: assume 32bpp (ARGB/BGRA depending on bootloader) */
void putpixel(int x, int y, uint32_t color) {
    if (!framebuffer) return;
    if (x<0||x>=(int)fb_width||y<0||y>=(int)fb_height) return;
    uint8_t *pix = framebuffer + y * fb_pitch + x * (fb_bpp/8);
    /* assume 32bpp little-endian BGRA or ARGB; we write as 0xRRGGBB (RGB) mapped to 0x00RRGGBB */
    *(uint32_t*)pix = color;
}

void draw_rect(int x, int y, int w, int h, uint32_t color) {
    for (int yy=y; yy<y+h; ++yy)
        for (int xx=x; xx<x+w; ++xx)
            putpixel(xx, yy, color);
}

void draw_background(uint32_t color) {
    draw_rect(0, 0, fb_width, fb_height, color);
}

/* Oval-ish window: use ellipse equation (rx, ry) */
void draw_window_oval(int x, int y, int w, int h, uint32_t color) {
    int cx = x + w/2;
    int cy = y + h/2;
    double rx = w/2.0;
    double ry = h/2.0;
    for (int yy=y; yy<y+h; ++yy) {
        for (int xx=x; xx<x+w; ++xx) {
            double dx = (xx - cx) / rx;
            double dy = (yy - cy) / ry;
            if (dx*dx + dy*dy <= 1.0) {
                putpixel(xx, yy, color);
            }
        }
    }
}

/* Very basic text drawing using 8x8 font */
void draw_text(int x, int y, const char *s, uint32_t color) {
    while (*s) {
        font_draw_char(*s++, x, y, color); /* implement in font.c */
        x += 8;
    }
}
