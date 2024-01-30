#include "tools/list.h"

// 初始化链表
void list_init(list_t *list)
{
    list->first = list->next = (list_node_t *)0;
    list->count = 0;
}