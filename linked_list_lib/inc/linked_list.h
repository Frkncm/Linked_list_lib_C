#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

// Interface

#define CREATE_LIST(list_name)   \
    list *list_name;             \
    list_name->list_node = NULL

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

void list_pushBack(list **lst, int value);

int list_popBack(list **lst);

int list_get(node *list, int index);

void list_pushFront(node **list, int value);

void list_insertAfterIndex(node *list, int value, int index);

int list_popFront(node **list);

void list_free(list **lst);

void list_to_array(list *lst, int *arr);

#endif //_LINKED_LIST_H_