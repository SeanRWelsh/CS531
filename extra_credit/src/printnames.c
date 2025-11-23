/***************************************************************************************************************
  Author:          S. M. Sainju
  Files:           printnames.c
  Functions:       print_names(struct node *)
                   namecountdisplay(struct node *)
  Date:            September 10, 2025
  Last modified:   October 10, 2025
  Purpose:         print_names function prints the names from the list in a specific formatted manner. namecount
                   display counts how many time each name on the list is present and keeps track of the number
                   and prints a table with names in a sorted manner based on the number of occurence
***************************************************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listheader.h"

/***************************************************************************************************************
   This is a simple print function to print the linked list. namecountdisplay() function is called from this
   function. 
****************************************************************************************************************/
void print_names(struct node * ptr){
  int pos = 1;
  struct node *headNode = ptr;
  printf("\t");
  printf("\n\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  printf("+++++++++++\n");
  while(ptr!= NULL){
    if(pos == 1)
      printf("\t");
    printf("%9s", ptr->names);
    
    if((ptr->link !=NULL) && pos >0)
      printf(", ");

    if (pos%10==0 && ptr->link !=NULL)
      printf("\n\t");
    
    ptr = ptr->link;
    pos++;
  }
  printf("\n\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  printf("+++++++++++\n");
  ptr = headNode;
  namecountdisplay(ptr);
  printf("\n");
}
/*****************************************************************************************************************
  Function:    namecountdisplay()
  Purpose:     This function goes through the list and counts how many time each name is printed and
               then displays.
	       Key here is to make inner loop and outer loop. compare the first outer value with each and every
	       member of the inner and keep the count. just like in bubble sort.
******************************************************************************************************************/
void namecountdisplay(struct node *ptr){
  struct newnode *newList = NULL;
  struct newnode *tmpnewList;
  struct newnode *newptr;
  struct node *outer = ptr;
  int i =0;
  while(outer != NULL){
    struct node *tmp = ptr;
    int alreadyCounted =0;

    while(tmp != outer){
      if(strcmp(tmp->names, outer->names)==0){
	alreadyCounted = 1;
	break;
      }
      tmp = tmp->link;
    }   // first while
    // if not counted yet, count occurences
    
    if(!alreadyCounted){
      int count =0;
      struct node *inner = ptr;
      
      while(inner !=NULL){
	if(strcmp(inner->names, outer->names)==0){
	  count++;
	}
	inner = inner->link;
      }
      /*  this is the first new node name is saved on the first node, inner loop counts all the names
          matched with the outer name and keeps track of how many. this is then saved in a new
          list with name and data(count)
      */
	tmpnewList = (struct newnode *)malloc(sizeof(struct newnode));
	strcpy(tmpnewList->names, outer->names);
	tmpnewList->data = count;
	tmpnewList->link = NULL;
	
      if (i==0){
	newptr = tmpnewList;
	newList = tmpnewList;
      }
      else{            //other subsequent nodes follow here.....
	newptr->link = tmpnewList;
	newptr = newptr->link;
      }
      i++;
    }
    outer = outer->link;
  }
  newptr=newList;      // make the pointer point to the first node of the newly created list.
  sort_data(newptr);   // sort and print the table with its count value.
}
