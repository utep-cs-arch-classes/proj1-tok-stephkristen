#include "history.h"
#include <stdio.h>
#include <stdlib.h>


/* From history.h

 typedef struct s_Item {
   int id;
   char *str;
   struct s_Item *next;
} Item;

 typedef struct s_List {
   struct s_Item *root;
} List;

 */

//Initialize the linked list to keep the history.

List* init_history(){

  List *history = (List *)malloc(sizeof(List) *1);
  history -> root = NULL;
  return history;
}

//Add a history item to the end of the list.

void add_history(List *list, char* str){

  Item *item = (Item *)malloc(sizeof(Item) * 1);

  Item *item_temp = list -> root;
  item -> str = str;
  int counter = 1;

  //if history is empty, meaning "NULL" then the new item will become the root

  if (list -> root == NULL){
    item -> id = counter;
    list -> root = item;
    
  } else {

    counter = 2;

    while((item_temp != NULL) && (item_temp -> next != NULL)){

      item_temp = item_temp -> next;
      counter++;
    }

    item_temp -> next = item;
    item -> id = counter;
  }
}

//Retrieve thr string stored in the node where Item -> id == id.

char *get_history(List *list, int id){

  Item *item_temp = list -> root;

  while(item_temp != NULL){

    if(item_temp -> id == id){
      return item_temp -> str;    //if we find id that matches we return the string located in the                                     history
    }
    
    item_temp = item_ temp -> next;
  }
  return NULL;
}

//Print the entire contents of the history list

void print_history(List *list){

  Item *item_temp = list -> root;

  while(item_temp != NULL){

    printf("\nIndex: %d ",item_temp -> id);
    printf("Input: %s \n",item_temp -> str);
    item_temp = item_temp -> next;
  }
}

/* Free the history list and the strings it refrences */

void free_history(List *list){

  Item *item_temp;            

  while(list -> root != NULL) {
    item_temp = list -> root;
    list -> root = list -> root -> next;
    free(item_temp);                        //frees each item in list
  }
  free(list);   //then frees all memory allocated in list
}
