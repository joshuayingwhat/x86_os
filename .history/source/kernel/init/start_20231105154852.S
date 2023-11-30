    .text
    .extern kernel_init
    .global _start
_start:
    push %ebp
    call kernel_init
    jmp .