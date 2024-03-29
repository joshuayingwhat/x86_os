#include "tools/list.h"

// 初始化链表
void list_init(list_t *list)
{
    list->first = list->last = (list_node_t *)0;
    list->count = 0;
}

// 往链表的头部插入节点
void list_insert_first(list_t *list, list_node_t *node)
{
    node->next = list->first;
    node->pre = (list_node_t *)0;

    if (list_is_empty(list))
    {
        list->first = list->last = node;
    }
    else
    {
        list->first->pre = node;
        list->first = node;
    }

    list->count++;
}

// 往链表的尾部插入节点
void list_insert_last(list_t *list, list_node_t *node)
{
    node->next = (list_node_t *)0;
    node->pre = list->last;

    if (list_is_empty(list))
    {
        list->first = list->last = node;
    }
    else
    {
        list->last->next = node;
        list->last = node;
    }
    list->count++;
}