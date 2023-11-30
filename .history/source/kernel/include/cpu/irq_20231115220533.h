#ifndef IRQ_H
#define IRQ_H

//定义获取异常之前的栈中的信息
typedef struct _exception_frame_

//中断和异常初始化处理程序
void irq_init(void);
#endif