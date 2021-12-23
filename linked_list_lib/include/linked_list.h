 #ifndef _LINKED_LIST_H_
 #define _LINKED_LIST_H_
 
 // Interface


 // Error messages
 typedef enum {
    LIST_OK,
    LIST_EMPTY,
 }list_status;

 typedef struct element node; // Forward decleration
 
 struct element {
     int value;
     node* next;
 }; 
 
 node * list_ctor(int value, void * next_node);
 
 void list_pushBack(node * list, int value);
 
 list_status list_popBack(node * list);
  
 int list_get(node * list, int index);
 
 void list_pushFront(node ** list, int value);
 
 void list_insertAfterIndex(node * list, int value, int index);
 
 void list_popFront(node ** list);
 
 void list_print(const node * list);
 
 
 #endif //_LINKED_LIST_H_
