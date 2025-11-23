/*************************************************************************************************************************
  Author:        S. M. Sainju
  File:          searchlist.c
  Function:      search_list()
  Date:          September 10, 2025
  Last modified: October 13, 2025
  Purpose:       This funcion searches a name on the list if the list exists. It does a simple strcmp to find the name
                 on the list. This is a linear search. 
**************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listheader.h"
/*
  This function does a linear search for a string on the existing list using strcmp. Searched sequentially and if found
  prints the location 
 */
void search_list(struct node * ptr){
  char *name_to_search = (char *)malloc(sizeof(char)*10);
  int location=1;
  bool not_found = true;
  bool print_once = true;
  struct node *tmp;
  
  printf("\n\t\t\t\t\tEnter a name to search on the list: ");
  scanf("%s", name_to_search);

    while(ptr != NULL){
      if(strcmp(ptr->names, name_to_search)== 0){
	if(print_once){
	  printf("\t\t\t\t\t%s found at location: [", name_to_search);
	  print_once = false;
	}
	printf("%d", location);

	tmp=ptr->link; // tmp points to the next node. this is to simply print comma.

	/** this section is to print comma after how many times each names is listed on the
	    list. tmp traverses thru the remaing of the list and if there are no other
	    names that matches the name to search then no need to print comma else
	    print comma.
	*/
	while(tmp !=NULL){
	  if (strcmp(name_to_search, tmp->names)==0){
	    printf(", ");
	    tmp = NULL;
	  }
	  else
	    tmp = tmp->link;
	}
	not_found = false;
      }
      ptr = ptr->link;
      location++;
    }

  if(not_found)
    printf("\t\t\t\t\t{%s is not on the list}", name_to_search);
  else
    printf("]");
  printf("\n");
}

