#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "stdbool.h"

/* Interface */

#define CREATE_LIST(list_name) \
    list *list_name = NULL;

typedef struct element node; // Forward decleration

/* element will be presenting the each node on the
   linked list */
struct element
{
    int value;
    node *next;
};

/* list struct will be the higher level type which is
   holding the size counting the node size in a list */
typedef struct list
{
    node *list_node;
    int size;
} list;

list *list_create(int value, void *next_node);

node *node_create(int value, void *next_node);

void list_pushBack(list **lst, int value);

int list_popBack(list **lst);

int list_get(list *lst, int index);

bool list_pushFront(list **lst, int value);

bool list_insertAfterIndex(list *lst, int value, int index);

int list_popFront(list **lst);

void list_free(list **lst);

bool list_to_array(list *lst, int *arr, int arr_size);

#endif //_LINKED_LIST_H_