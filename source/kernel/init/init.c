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
#include "tools/list.h"

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

void list_test(void)
{
    list_t list;
    list_node_t nodes[5];

    list_init(&list);
    log_prinf("list: first=0x%x, last=0x%x, count=%d", list_first(&list), list_last(&list), list_count(&list));

    // 插入
    for (int i = 0; i < 5; i++)
    {
        list_node_t *node = nodes + i;
        log_prinf("insert first to list: %d, 0x%x", i, (uint32_t)node);
        list_insert_first(&list, node);
    }
    log_prinf("list: first=0x%x, last=0x%x, count=%d", list_first(&list), list_last(&list), list_count(&list));

    list_init(&list);
    for (int i = 0; i < 5; i++)
    {
        list_node_t *node = nodes + i;
        log_prinf("insert last to list: %d, 0x%x", i, (uint32_t)node);
        list_insert_last(&list, node);
    }
    log_prinf("list: first=0x%x, last=0x%x, count=%d", list_first(&list), list_last(&list), list_count(&list));

    for (int i = 0; i < 5; i++)
    {
        list_node_t *node = list_remove_first(&list);
        log_prinf("remove first from list: %d, 0x%x", i, (uint32_t)node);
    }
    log_prinf("list: first=0x%x, last=0x%x, count=%d", list_first(&list), list_last(&list), list_count(&list));

    // 插入
    for (int i = 0; i < 5; i++)
    {
        list_node_t *node = nodes + i;
        log_prinf("insert last to list: %d, 0x%x", i, (uint32_t)node);
        list_insert_last(&list, node);
    }
    log_prinf("list: first=0x%x, last=0x%x, count=%d", list_first(&list), list_last(&list), list_count(&list));

    for (int i = 0; i < 5; i++)
    {
        list_node_t *node = nodes + i;
        log_prinf("remove first from list: %d, 0x%x", i, (uint32_t)node);
        list_remove(&list, node);
    }
    log_prinf("list: first=0x%x, last=0x%x, count=%d", list_first(&list), list_last(&list), list_count(&list));
}

void init_main(void)
{
    list_test();
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