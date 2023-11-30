
SECTOINS{
    . = 0x10000;//告诉编译器这些编译的字段都放在内存中0x10000处
    .text : {
         *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }
}