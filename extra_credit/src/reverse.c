/********************************************************************************************************
 Author:         S. M. Sainju
 File:           reverse.c
 Function:       reverse()
 Date:           October 1, 2025
 Last Modified:  October 10, 2025
 Purpose:        This function reverses the list if the list exists.
**********************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listheader.h"

struct node *reverse(struct node * ptr){
  struct node * prev, *next;
  prev = NULL;
  next = NULL;
  
  while(ptr!=NULL){
    next = ptr->link; //move the pointer to the next node;
    ptr->link =prev;  //change the value of the link part the previous node to NULL and
    prev = ptr;
    ptr = next;
  }
  ptr = prev;
  
  return ptr;
}

