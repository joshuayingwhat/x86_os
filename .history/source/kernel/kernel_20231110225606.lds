//设置编译链接脚本
SECTOINS{
    . = 0x10000;//告诉编译器这些编译的字段都
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