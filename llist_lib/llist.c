#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

node *list_ctor(int value, void *next_node)
{
   node *list = (node *)malloc(sizeof(node));

   list->value = value;
   list->next = (node *)next_node;
   return list;
}

void list_pushBack(node **list, int value)
{

   if (*list == NULL)
   {
      *list = list_ctor(value, NULL);
   }
   else
   {
      node *current_node = *list;

      while (current_node->next != NULL)
      {
         current_node = current_node->next;
      }

      current_node->next = list_ctor(value, NULL);
      current_node->next->next = NULL;
   }
}

void list_pushBack(list **lst, int value)
{
   if ((*lst)->list_node == NULL)
   {
      (*lst)->list_node = list_ctor(value, NULL);
      (*lst)->size = 1;
   }
   else
   {
      node *current_node = (*lst)->list_node;

      while (current_node->next != NULL)
      {
         current_node = current_node->next;
      }

      current_node->next = list_ctor(value, NULL);
      current_node->next->next = NULL;
      (*lst)->size++;
   }
}

int list_popBack_size(list **lst)
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

int list_popBack(node **list)
{
   if (*list == NULL)
      return 0; // the list has not any instance

   int temp;

   if ((*list)->next == NULL)
   {
      // We have only one value in the list
      temp = (*list)->value;
      free(*list);
      *list = NULL;
   }
   else
   {
      node *current_node = *list;
      node *prev_last = *list;

      while (current_node->next != NULL)
      {
         if (current_node->next->next == NULL)
            prev_last = current_node;

         current_node = current_node->next;
      }

      temp = current_node->value;

      current_node = NULL;

      free(current_node);

      if (prev_last != NULL)
         prev_last->next = NULL;
   }

   return temp;
}

static node *get_node(node *list, int index)
{
   // We need to create a linear search mechanism
   int i = 0;

   node *current_node = list;

   for (i = 0; i < index - 1; i++)
   {
      current_node = current_node->next;
   }

   return current_node;
}

int list_get(node *list, int index)
{
   return get_node(list, index)->value;
}

void list_pushFront(node **list, int value)
{
   *list = list_ctor(value, *list);
}

void list_insertAfterIndex(node *list, int value, int index)
{
   node *prev_node = get_node(list, index);

   node *intended_node = list_ctor(value, prev_node->next);
   prev_node->next = intended_node;
}

void list_popFront(node **list)
{
   node *header = *list;

   *list = (*list)->next;
   free(header);
}

void list_free(node **list)
{
   node *next;

   while ((*list) != NULL)
   {
      next = (*list)->next;
      free(*list);
      (*list) = next;
   }
}

void list_to_array(node *list, int *arr)
{
   if (list == NULL)
      return;

   node *current_node = list;
   int indx = 0;

   while (current_node != NULL)
   {
      arr[indx++] = current_node->value;
      current_node = current_node->next;
   }
}