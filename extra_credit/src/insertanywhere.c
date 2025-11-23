/******************************************************************************************************************
  Author:         S. M. Sainju
  Files:          insertanywhere.c
  Function:       insert_anywhere()
  Date:           October 1, 2025
  Last modified:  October 10, 2025
  Purpose:        This function allows to insert a node in an existing list at the beginning, at the end or at any
                  nth place. Location is calulated using a random number. Pointer traverses thru the list until
		  the nth location if found and inserts the node into the list at that location.

                  2nd function is straight forward. It basically counts how many total nodes are present on the list.
                  The main purpose is to find a random number between 1 and this number where the node will be
                  inserted.
********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "listheader.h"

/********** Function: insert_anywhere **************************************/
struct node * insert_anywhere(struct node* ptr){
  int position=1;
  int num_nodes;
  
  struct node *tmp=(struct node *)malloc(sizeof(struct node));
  struct node *tmp1 = ptr;
  char name_to_insert[N_MAX];
  
  srand(time(NULL));
  printf("\t\t\t\t\tEnter a name to insert on the linked List: ");
  scanf("%s", name_to_insert);
  
  strcpy(tmp->names,name_to_insert);
  tmp->link = NULL;

  num_nodes = find_num_nodes(ptr);
  position = rand()%num_nodes+1;    // this finds out how many nodes are present on the list
                                    // can only insert within 1 and num_nodes+1
  printf("\t\t\t\t\tPosition to be inserted is at %d", position);

  if(position == 1){                 // first position
    tmp->link = ptr;
    ptr = tmp;
  }
  else if (position ==num_nodes){   // last position
    while(ptr->link != NULL)
      ptr = ptr->link;
    ptr->link = tmp;
    ptr = tmp1;
  }
  else{                           // any other positiony
    position--;
    while(position != 1){
      ptr = ptr->link;
      position--;
    }
    tmp->link = ptr->link;
    ptr->link = tmp;
    ptr = tmp1;
  }
  return (ptr);
}
/*********** This function just finds out how many nodes are there in a list **********/
int find_num_nodes(struct node *ptr){
  int counter=0;
  while(ptr!=NULL){
    ptr = ptr->link;
    counter++;
  }
  return counter;
}
  
