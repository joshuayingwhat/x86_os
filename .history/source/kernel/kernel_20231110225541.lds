//设置编译链接脚本
SECTOINS{
    . = 0x10000
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