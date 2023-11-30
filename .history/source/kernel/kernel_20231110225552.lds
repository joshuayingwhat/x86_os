//设置编译链接脚本
SECTOINS{
    . = 0x10000;//告诉编译器这些
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