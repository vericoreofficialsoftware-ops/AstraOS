[bits 16]
[org 0x7c00]

mov ax, 0
mov ds, ax
mov es, ax

jmp 0x0000:load_kernel

load_kernel:
    ; Kernel'i yükleme kodu buraya gelir (kısa tutuyorum)
    mov si, msg
    call print_string

    jmp $

print_string:
    mov ah, 0x0E
    .loop:
        lodsb
        cmp al, 0
        je .done
        int 0x10
        jmp .loop
    .done:
    ret

msg db "Bootloader Yuklendi!", 0

times 510-($-$$) db 0
dw 0xAA55
