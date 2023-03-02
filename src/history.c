#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *list = (List*)malloc(sizeof(List));
  list->root = NULL;
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *item = (Item*)malloc(sizeof(Item));
  item->str = str;
  item->next = NULL;
  if(list->root == NULL){
    list->root = item;
    item->id = 1;
  }else{
    Item *temp = list->root;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = item;
    item->id = temp->id + 1;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *temp = list->root;
  while(temp != NULL){
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL;
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *temp = list->root;

  while (temp != NULL) {
    printf("%s\n", temp->str);
    temp = temp->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *temp = list->root;
  while (temp != NULL) {
    Item *next_temp = temp->next;
    free(temp->str);
    free(temp);
    temp = next_temp;
  }
  free(list);
}