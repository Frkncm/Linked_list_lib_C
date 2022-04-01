#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* After creating a list, we don't need to call
   this function again. The list struct is only 
   used for holding additional size info of the 
   list */
list *list_create(int value, void *next_node)
{
   list *temp_list = (list *)malloc(sizeof(list));
   temp_list->list_node = node_create(value, next_node);

   temp_list->size = 1;
   return temp_list;
}

/* Node create will called continuously as we
   add new data. */
node *node_create(int value, void *next_node)
{
   node *nd = (node *)malloc(sizeof(node));

   nd->value = value;
   nd->next = (node *)next_node;
   return nd;
}

/* Push back can be directly used even we didn't 
   create a list previously (it will create if the 
   list is empty). Since the address will be added 
   to the list, double pointer is needed. This design
   can be converted to the function returning the list
   address but, this one seems more convinient for now.  */
void list_pushBack(list **lst, int value)
{
   if ((*lst) == NULL)
   {
      /* If the list has not created, we should
      construct it at first before jumping into
      the node adding parts. */
      (*lst) = list_create(value, NULL);
   }
   else
   {
      node *current_node = (*lst)->list_node;

      /* Check the node where the next one is NULL */
      while (current_node->next != NULL)
      {
         current_node = current_node->next;
      }
      
      /* Now we find the empty node, so we can 
      constract that node */
      current_node->next = node_create(value, NULL);
      (*lst)->size++;
   }
}

int list_popBack(list **lst)
{
   if ((*lst) == NULL)
      return -1;

   if ((*lst)->list_node == NULL)
      return -1; // the list has not any instance

   int temp;

   if ((*lst)->list_node->next == NULL)
   {
      // We have only one value in the list
      temp = (*lst)->list_node->value;
      free((*lst)->list_node);
      (*lst)->list_node = NULL;
      (*lst)->size = 0;
   }
   else
   {
      node *current_node = (*lst)->list_node;
      node *prev_last = (*lst)->list_node;

      while (current_node->next != NULL)
      {
         if (current_node->next->next == NULL)
            prev_last = current_node;

         current_node = current_node->next;
      }

      temp = current_node->value;

      current_node = NULL;

      free(current_node);

      (*lst)->size--;

      prev_last->next = NULL;
   }
   return temp;
}

static node *get_node(list *lst, unsigned int index)
{
   // We need to create a linear search mechanism

   if (lst->size < index)
      return NULL;

   node *current_node = (lst)->list_node;

   for (int i = 0; i < index; i++)
   {
      current_node = current_node->next;
   }

   return current_node;
}

int list_get(list *lst, int index)
{
   node *temp_node = get_node(lst, index);

   if (temp_node != NULL)
      return temp_node->value;
   else
      return -1;
}

bool list_insertAfterIndex(list *lst, int value, int index)
{
   if (lst == NULL)
      return false;

   if (lst->list_node == NULL)
      return false;

   node *prev_node = get_node(lst, index);

   if (prev_node == NULL)
      return false;

   node *intended_node = node_create(value, prev_node->next);
   prev_node->next = intended_node;

   lst->size++;

   return true;
}

bool list_pushFront(list **lst, int value)
{
   if ((*lst) == NULL)
   {
      (*lst) = list_create(value, NULL);
      (*lst)->size++;
      return true;
   }
   else if ((*lst)->list_node != NULL)
   {
      (*lst)->list_node = node_create(value, (*lst)->list_node);
      (*lst)->size++;
      return true;
   }
   return false;
}

int list_popFront(list **lst)
{
   if ((*lst) == NULL)
      return -1;

   if ((*lst)->list_node == NULL)
      return -1;

   node *header = (*lst)->list_node;

   (*lst)->size--;

   int temp = (*lst)->list_node->value;

   (*lst)->list_node = (*lst)->list_node->next;
   free(header);

   return temp;
}

void list_free(list **lst)
{
   if ((*lst) == NULL)
      return;

   node *next;

   while ((*lst)->list_node != NULL)
   {
      next = (*lst)->list_node->next;
      free((*lst)->list_node);
      (*lst)->list_node = next;
   }

   /* Free the address allocated for lst.
      otherwise this will cause memory leak. */
   free(*lst);

   *lst = NULL;
}

bool list_to_array(list *lst, int *arr, int arr_size)
{
   if (lst->list_node == NULL)
      return false;

   if (arr_size < lst->size)
      return false;

   node *current_node = lst->list_node;
   int indx = 0;

   while (current_node != NULL)
   {
      arr[indx++] = current_node->value;
      current_node = current_node->next;
   }
   return true;
}