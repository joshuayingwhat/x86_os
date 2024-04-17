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
    list_node_t *first; // 头节点
    list_node_t *last;  // 尾节点
    int count;
} list_t;

void list_init(list_t *list);

// 判断链表是否为空
static inline int list_is_empty(list_t *list)
{
    return list->count == 0;
}

// 返回链表数量
static inline int list_count(list_t *list)
{
    return list->count;
}

// 取第一个节点
static inline list_node_t *list_first(list_t *list)
{
    return list->first;
}

// 取最后一个节点
static inline list_node_t *list_last(list_t *list)
{
    return list->last;
}

// 往链表的头部插入节点
void list_insert_first(list_t *list, list_node_t *node);

// 往链表的尾部插入节点
void list_insert_last(list_t *list, list_node_t *node);

// 删除链表的头部
list_node_t *list_remove_first(list_t *list);

list_node_t *list_remove(list_t *list, list_node_t *node);
#endif