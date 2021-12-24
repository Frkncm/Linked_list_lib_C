#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

list *list_create(int value, void *next_node)
{
   list *temp_list = (list *)malloc(sizeof(list));
   temp_list->list_node = node_create(value, next_node);

   temp_list->size = 1;
   return temp_list;
}

node *node_create(int value, void *next_node)
{
   node *list = (node *)malloc(sizeof(node));

   list->value = value;
   list->next = (node *)next_node;
   return list;
}

void list_pushBack(list **lst, int value)
{
   if ((*lst) == NULL)
   {
      (*lst) = list_create(value, NULL);
   }
   else
   {
      node *current_node = (*lst)->list_node;

      while (current_node->next != NULL)
      {
         current_node = current_node->next;
      }

      current_node->next = node_create(value, NULL);
      current_node->next->next = NULL;
      (*lst)->size++;
   }
}

int list_popBack(list **lst)
{
   if ((*lst)->list_node == NULL)
      return 0; // the list has not any instance

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

static node *get_node(list *lst, int index)
{
   // We need to create a linear search mechanism

   if (lst->size < index)
      return NULL;

   int i = 0;

   node *current_node = (lst)->list_node;

   for (i = 0; i < index - 1; i++)
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

void list_pushFront(node **list, int value)
{
   *list = node_create(value, *list);
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