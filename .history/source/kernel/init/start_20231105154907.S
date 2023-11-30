    .text
    .extern kernel_init
    .global _start
_start:
    push %ebp
    mov %esp,%
    call kernel_init
    jmp .