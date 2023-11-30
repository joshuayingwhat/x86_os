    .text
    .extern kernel_init
    .global 
_start:
    call kernel_init
    jmp .