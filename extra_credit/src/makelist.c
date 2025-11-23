/***********************************************************************************************************************
 Author:         S. M. Sainju
 Files:          makelist.c
 Functions:      insert_names(struct node *)
 Purpose:        The function in this file adds names to a linked list.
 Limitation:
 Date:           September 20, 2025
 Last Modified:  September 22, 2025
**************************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "listheader.h"

struct node *insert_names(struct node *ptr){
  long num_names;
  extern char list_of_names[100][10]; // no memory allocated. list_of_names defined elsewhere. 
  char (*nameptr)[10];
  struct node *tmp;
  struct node *headNode;
  nameptr = list_of_names;
  srand(time(NULL));                  // This allows to create random numbers. Seeds the random number with the
                                      // current time so the results varry on each run. 
  int result;
  /* catch invalid input for number of names here */
  while(1){
    printf("\t\t\t\t\tHow many names do you want to insert? ==> ");
    result = scanf("%ld", &num_names);
    if (result ==1){
      break;
    }else{
      printf("\n\tInvalid input. Try again.\n");
      while(getchar() !='\n');   // clear input buffer
    }
  }
      
  if (num_names> 0){
    for(int i=0;i<num_names;i++){
      tmp = (struct node *)malloc(sizeof(struct node));
      strcpy(tmp->names, nameptr[rand()%100]);
      tmp->link = NULL;      
      if (i==0){                           // this is the first node
	ptr = tmp;
	headNode = tmp;
      }
      else{
	ptr->link = tmp;
	ptr = ptr->link;
      }
    }       // end of for
  }         // end of 1st if
  else{
    headNode = NULL;
  }
  return headNode;
}
