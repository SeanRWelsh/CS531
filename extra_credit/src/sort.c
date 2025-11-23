/**********************************************************************************************************
  Author:          S. M. Sainju
  File:            sort.c
  Function:        sort_names()
                   sort_data()
  Date:            October 1, 2025
  Last modified:   October 10, 2025
  Purpose:         sort_name function sorts name on the original list. while sort_data sorts the entire
                   newly created list that has name and how many times each name exists on the list based
                   on the number of occurence. 
***********************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listheader.h"
/*  This function sorts the names on the original list that has only names. */
void sort_names(struct node *ptr){
  struct node *i, *j;
  char *tmp = (char *)malloc(sizeof(char)*20);;
  
  for (i=ptr;i->link!=NULL;i=i->link){
    for(j=i->link;j!=NULL; j=j->link){
      if (strcmp(i->names, j->names)>0){
        strcpy(tmp, i->names);
        strcpy(i->names, j->names);
        strcpy(j->names, tmp);
      }
    }
  }
}
/*********************************************************************************************************
  Function to sort the new list based on how many time each name has occurred on the list.
  This function sorts the data using bubble sort. Pick the best sort as you see fit. 
**********************************************************************************************************/
void sort_data(struct newnode *ptr){
  struct newnode *i, *j;
  int tmpdata;
  char *tmp = (char *)malloc(sizeof(char)*20);;
  
  for (i=ptr;i->link!=NULL;i=i->link){
    for(j=i->link;j!=NULL; j=j->link){
      if (i->data < j->data){
        tmpdata = i->data;
	strcpy(tmp, i->names);
	i->data = j->data;
        strcpy(i->names, j->names);
	j->data = tmpdata;
        strcpy(j->names, tmp);
      }
    }
  }
                /* print the names and count data for each name on the list */
  int counter =0;
  printf("\n\t\t\tTable: Shows how many times each name is present on the list");
  printf("\n\t      Name   Number\t      Name    Number\t      Name   Number\t      Name    Number\t      Name    Number");
  printf("\n\t     ======  ======\t     ======   ======\t     ======  ======\t     ======   ======\t     ======   ======\n");
  while(ptr !=NULL){
    printf("\t%10s: %5d", ptr->names, ptr->data);
    ptr = ptr->link;
    counter++;
    if (counter%5 == 0)
      printf("\n");
  }
  printf("\n\t\t\t\t[==> There are total of %d names on the list]", counter);
}

