#include "init.h"
#include "comm/boot_info.h"
#include "cpu/cpu.h"
#include "kernel/dev/time.h"
#include "cpu/irq.h"
#include "tools/log.h"
#include "os_cfg.h"
#include "tools/klib.h"
#include "core/task.h"

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

static task_t init_task;
void init_task_entry(void)
{
    int count = 0;
    for (;;)
    {
        log_prinf("init_task_entry: %d", count++);
    }
}
void init_main()
{
    log_prinf("os is running");
    log_prinf("version %s", OS_VERSION);
    log_prinf("%d %d %x %c", -10, 20, 0x30, 'c');
    // irq_enable_global();//暂时先关掉定时中断

    task_init(&init_task, (uint32_t)init_task_entry, 0);
    task_init(&first_task, 0, 0);
    int count = 0;
    for (;;)
    {
        log_prinf("init_main: %d", count++);
    }
}