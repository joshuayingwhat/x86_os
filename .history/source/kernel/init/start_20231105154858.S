    .text
    .extern kernel_init
    .global _start
_start:
    push %ebp
    mov %
    call kernel_init
    jmp .