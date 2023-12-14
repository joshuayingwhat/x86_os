# x86_os
tiny os

## 虚拟化CPU
多个进程不断切换执行，切换的时候需要把进程的状态保存下来，这个保存的机制就是tss。
恢复运行的时候再从tss中恢复出来。
保存程序中的内容cs/ds/cs/ds/fs/es/cs/ds/fs/es/gs，还有栈相关的指令ss/esp，以及通用寄存器eax，。。。，edx，
