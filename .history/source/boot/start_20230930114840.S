/**
 * 自己动手写操作系统
 *
 * 系统引导部分，启动时由硬件加载运行，然后完成对二级引导程序loader的加载
 * 该部分程序存储于磁盘的第1个扇区，在计算机启动时将会由BIOS加载到0x7c00处
 * 之后，将由BIOS跳转至0x7c00处开始运行
 * 
 * 作者：李述铜
 * 联系邮箱: 527676163@qq.com
 */
	#include "boot.h"

  	// 16位代码，务必加上
  	.code16
 	.text
	.global _start
_start:
	mov $0, %ax  //将所有的段寄存器设置为0
	mov %ax, %ds
	mov %ax, %ss
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs

	mov $_start, %esp //设置栈寄存器从0x7c00开始，_start就是0x7c00

	//软中断int10显示字符
	mov $0xe, %ah
	mov $'L', %al
	int $0x10

read_loader:
	mov $0x8000, %bx //将在loader到0x8000
	mov $0x02, %ah  //
	mov $0x02, %cx //ch =


	jmp .

	// 引导结束段
	.section boot_end, "ax"
boot_sig: .byte 0x55, 0xaa
