#include "os_cfg.h"

    .text
    .extern kernel_init
    .global _start
    .extern init_main
_start:
    push %ebp
    mov  %esp,%ebp
    mov  0x8(%ebp),%eax

    push %eax
    call kernel_init

    jmp $KERNEL_SELECTOR_CS, $gdt_reload
gdt_reload:
    mov $KERNEL_SELECTOR_DS, %ax
	mov %ax, %ds
	mov %ax, %ss
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs

    mov $(stack+KERNEL_STACK_SIZE), %esp
    jmp init_main

    .bss
.comm stack,KERNEL_STACK_SIZE

.macro exception_handle name num with_error_code
    .text
    .extern do_handler_\name
    .global exception_handle_\name
exception_handle_\name:
    .if \with_error_code == 0
        push $0
    .endif

    push $\num
    pusha
    push %ds
    push %es
    push %fs
    push %gs

    push %esp
    call do_handler_\name
    add $(1*4), %esp

    pop %gs
    pop %fs
    pop %es
    pop %ds
    popa

    add $(2*4), %esp
    iret
.endm

exception_handle  unknow,-1,0
exception_handle  divider,0,0
exception_handle Debug, 1, 0
exception_handle NMI, 2, 0
exception_handle breakpoint, 3, 0
exception_handle overflow, 4, 0
exception_handle bound_range, 5, 0
exception_handle invalid_opcode, 6, 0
exception_handle device_unavailable, 7, 0
exception_handle double_fault, 8, 1
exception_handle invalid_tss, 10, 1
exception_handle segment_not_present, 11, 1
exception_handle stack_segment_fault, 12, 1
exception_handle general_protection, 13, 1
exception_handle page_fault, 14, 1
exception_handle fpu_error, 16, 0
exception_handle alignment_check, 17, 1
exception_handler machine_check, 18, 0
exception_handler smd_exception, 19, 0
exception_handler virtual_exception, 20, 0