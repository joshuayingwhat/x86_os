//设置编译链接脚本
SECTOINS{
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