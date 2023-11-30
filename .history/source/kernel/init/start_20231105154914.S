    .text
    .extern kernel_init
    .global _start
_start:
    push %ebp
    mov  %esp,%ebp
    call kernel_init
    jmp .