[bits 64]

global vga_set_mode13h

vga_set_mode13h:
    mov ax, 0x0013
    int 0x10
    ret
