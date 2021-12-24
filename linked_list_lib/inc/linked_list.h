#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "stdbool.h"

// Interface

#define CREATE_LIST(list_name)   \
    list *list_name = NULL;      \

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

void *list_ctor(list **lst);

list *list_create(int value, void *next_node);

node *node_create(int value, void *next_node);

void list_pushBack(list **lst, int value);

int list_popBack(list **lst);

int list_get(node *list, int index);

void list_pushFront(node **list, int value);

void list_insertAfterIndex(node *list, int value, int index);

int list_popFront(node **list);

void list_free(list **lst);

bool list_to_array(list *lst, int *arr, int arr_size);

#endif //_LINKED_LIST_H_