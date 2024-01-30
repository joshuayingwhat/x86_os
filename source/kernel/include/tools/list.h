#ifndef LIST_H
#define LIST_H

typedef struct _list_node_t
{
    struct _list_node_t *pre;  // 前一个节点
    struct _list_node_t *next; // 后一个节点
} list_node_t;

static inline void list_node_init(list_node_t *node)
{
    node->pre = node->next = (list_node_t *)0;
}

static inline list_node_t *list_node_pre(list_node_t *node)
{
    return node->pre;
}

static inline list_node_t *list_node_next(list_node_t *node)
{
    return node->next;
}

typedef struct _list_t
{
    list_node_t *first;
    list_node_t *next;
    int count;
} list_t;

void list_init(list_t *list);
#endif