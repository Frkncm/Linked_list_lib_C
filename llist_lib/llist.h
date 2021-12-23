#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

// Interface

#define CREATE_LIST(list_name)   \
    list *list_name;             \
    list_name->list_node = NULL; \
    list_name->size = 0

typedef struct element node; // Forward decleration

struct element
{
    int value;
    node *next;
};

typedef struct list
{
    node *list_node;
    int size;
} list;

node *list_ctor(int value, void *next_node);

void list_pushBack(node **list, int value);

void list_pushBack_size(list **lst, int value);

int list_popBack_size(list **lst);

int list_popBack(node **list);

int list_get(node *list, int index);

void list_pushFront(node **list, int value);

void list_insertAfterIndex(node *list, int value, int index);

void list_popFront(node **list);

void list_free(node **list);

void list_to_array(node *list, int *arr);

#endif //_LINKED_LIST_H_