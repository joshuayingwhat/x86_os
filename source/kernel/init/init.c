#include "init.h"
#include "comm/boot_info.h"
#include "cpu/cpu.h"
#include "kernel/dev/time.h"
#include "cpu/irq.h"
#include "tools/log.h"
#include "os_cfg.h"
#include "tools/klib.h"
#include "core/task.h"
#include "comm/cpu_instr.h"

/**
 * 内核入口
 */
void kernel_init(boot_info_t *boot_info)
{
    cpu_init();

    init_log(); // 初始化打印函数
    irq_init();
    // 初始化定时器
    init_time();
}

static task_t first_task;
static uint32_t init_task_stack[1024];
static task_t init_task;
void init_task_entry(void)
{
    int count = 0;
    for (;;)
    {
        log_prinf("init_task_entry: %d", count++);
        task_switch_from_to(&init_task, &first_task);
    }
}
void init_main(void)
{
    log_prinf("os is running");
    log_prinf("version %s", OS_VERSION);
    log_prinf("%d %d %x %c", -10, 20, 0x30, 'c');
    // irq_enable_global();//暂时先关掉定时中断

    task_init(&init_task, (uint32_t)init_task_entry, (uint32_t)&init_task_stack[1024]);
    task_init(&first_task, 0, 0); //??为什么入口设置为0，堆栈也设置为0
    write_tr(first_task.tss_sel);
    int count = 0;
    for (;;)
    {
        log_prinf("init_main: %d", count++);
        // 手动切换
        task_switch_from_to(&first_task, &init_task);
    }
}