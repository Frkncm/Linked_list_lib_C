#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

 
 node * list_ctor(int value, void * next_node)
 {
     node * list = (node *)malloc(sizeof(node));
     
     list->value = value;
     list->next = (node*)next_node;
     return list;
 }
 
 void list_pushBack(node * list, int value)
 {
    node * current_node = list;
    
    while(current_node->next != NULL )
    {
        current_node = current_node->next;
    }
    
    current_node->next = list_ctor(value, NULL);
    current_node->next->next = NULL;
    
 }
 
 
 list_status list_popBack(node * list)
 {  
    node * current_node = list;
    node * prev_last = list;
    
    if(current_node == NULL)
    	return LIST_EMPTY; // the list has not any instance
    
    while(current_node->next != NULL)
    {
    	if(current_node->next->next == NULL)
    	   prev_last = current_node;
    	   
    	current_node = current_node->next;
    }
        
    free(current_node);
    prev_last->next = NULL;
    
    return LIST_OK;
 } 
 
 
 static node * get_node(node * list, int index)
 {
    // We need to create a linear search mechanism
    int i = 0;
    
    node * current_node = list;
    
    for(i = 0; i < index-1; i++)
    {
    	current_node = current_node->next;
    }
    
    return current_node;
 }
 
 int list_get(node * list, int index)
 {
    return get_node(list, index)->value;
 }
 
 void list_pushFront(node ** list, int value)
 {    
    *list = list_ctor(value, *list);
 }
 
 void list_insertAfterIndex(node * list, int value, int index)
 {
    node * prev_node = get_node(list, index);
    
    node * intended_node = list_ctor(value, prev_node->next);
    prev_node->next = intended_node;
        
 }
 
 void list_popFront(node ** list)
 {
    node * header = *list;
    
    *list = (*list)->next;
    free(header);
 }
 
 void list_print(const node * list)
 {
    const node * current_node = list;
    
    while(current_node != NULL)
    {
    	printf("%d\n", current_node->value);
    	current_node = current_node->next;
    }
    printf("\n");    
 }
 
 
