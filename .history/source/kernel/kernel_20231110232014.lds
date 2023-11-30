SECTIONS {
    . = 0x10000;// 设置编译结果从0x10000处开始

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