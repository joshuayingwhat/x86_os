#include "init.h"
#include "comm/boot_info.h"
#include "cpu/cpu.h"
#include "dev/time.h"
#include "cpu/irq.h"
#include "tools/log.h"
#include "os_cfg.h"
#include "tools/klib.h"
#include "core/task.h"
#include "comm/cpu_instr.h"
#include "tools/list.h"
#include "ipc/sem.h"

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

    // 初始化任务管理
    task_manager_init();
}

static uint32_t init_task_stack[1024];
static task_t init_task;
static sem_t sem;
void init_task_entry(void)
{
    int count = 0;
    for (;;)
    {
        sem_wait(&sem);
        log_prinf("init task: %d", count++);
    }
}

void init_main(void)
{
    log_prinf("os is running");
    log_prinf("version %s", OS_VERSION);
    log_prinf("%d %d %x %c", -10, 20, 0x30, 'c');

    task_init(&init_task, "init task", (uint32_t)init_task_entry, (uint32_t)&init_task_stack[1024]);
    task_first_init();

    sem_init(&sem, 0);
    irq_enable_global();
    int count = 0;
    for (;;)
    {
        log_prinf("init_main: %d", count++);
        sem_notify(&sem);
        sys_sleep(1000);
    }
}