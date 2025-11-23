/*********************************************************************************************************************
  Author:         S. M. Sainju
  Files:          main.c
  Function:       main Funciton
  purpose:        This function has 10 option tasks from the main menu to create, display, reverse
                  sort, search, add, delete, clear screen and exit.
  Date:           September 10, 2025
  Date modified:  October 10, 2025
*********************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "listheader.h"

// 100 names are hard coded here in an array. perhaps storing in a FILE would be better for future.
char list_of_names[MAX][10] = {"Tom", "James", "patrick", "Patrick", "David", "Jennifer", "Carla", "Faisal", "Sarah",
			       "Maya","Sofi", "Jane", "Ruth", "Helen", "Grace", "Mia", "Amelia", "Anne", "Liz",
			       "Maria", "Anna", "Aisha", "Fatima", "Mei", "Yuna", "Priya", "Carmen", "Harper",
			       "Evelyn", "Ella", "Mary", "Emma", "Watson", "Bill", "William", "Thomas", "Bob",
			       "Robert", "David", "Henry", "Bagus", "King", "Ming", "Lieng", "Xio", "Edward",
			       "George", "Mason", "Liam", "Noah", "Oliver", "Mateo", "Lucas", "Ethan", "Logan",
			       "Aiden", "Ali", "Thomas", "Elijah", "Jose", "Juan", "Ahmed", "Luca", "Marco",
			       "Donnie", "Daniel", "Hiroshi", "Charles", "John", "Roberto", "Sam", "Ram", "Hari",
			       "Alisha", "Sweta", "Rupa", "Niva", "Nisha", "Sneha", "Sameer", "Mohan", "Rita",
			       "Sita", "Anil", "Koji", "Hiroshi", "Taro", "Yuki", "Taizo", "Ren", "Yoko", "Keiko",
			       "Fumiye", "Kenji", "Takashi", "Hiroko", "Hidenobu", "Akiko", "Fuji", "Honda"
                               };

//*********** Main Function *****************//
int main(){
  bool list_created = false;    // set the flag to false so the list is empty
  int choice;                   // menu choice
  struct node *list;            // linked list
  struct node *ptr;             // pointer to the list

  ptr = list = NULL;
  system ("clear");             // clears the screen
  do{
    switch(choice=menu()){
    case 1: {    /* Option 1 from the menu allows to create a list */
      srand(time(NULL));        
	/* this makes the random function different on each run if the list was already created
	   and option 1 is selected again, then previously created list is completely deleted
	   before creating a new list.
	*/
      if(list!= NULL){
	printf("\t\t\t\t{Previously created list now deleted.......}\n");
	list =delete_entirelist(ptr);      //after deleting the list, list is NULL;
	list_created = false;
      }
      list = insert_names(ptr);                             // list is always the first node of the list or NULL if empty
      if(list !=NULL)
	list_created = true;                                // list is created....
      printf("\t\t\t\t{List created. Press 2 from the menu to view the list}\n");
      break;
    }
    case 2:{  /* This option from the menu displays the list */
      if(list_created){
	ptr = list;
	printf("\n\tNames on the List:............");
	print_names(ptr);
      }
      else
	printf("\t\t\t\t{List is empty ... Nothing to display.....}\n");
      break;
    }
    case 3: { /* This option reverses the list */
      if(list_created){
	ptr = reverse(ptr);           // this function reverses the entire list
	list=ptr;                     // ptr is the pointing to the last node so make the last node as the first node. 
	printf("\t\t\t\t{List is reversed now. Press 2 from the menu to view the list}\n");
      }
      else
      printf("\t\t\t\t{List is empty.......Nothing ro reverse.....}");
      break;
    }
    case 4:{  /* This option sorts the list using bubble sort */
      if(list_created){
	ptr = list;                        // always move the traversing pointer to the beginning of the node. 
	sort_names(ptr);
	printf("\t\t\t\t{List is sorted now. Press 2 from the menu to view the list}\n");
      }
      else
	printf("\n\t\t\t\t{List is empty.......Nothing to sort.....}\n");
      break;
    }
    case 5:{ /* Linear search is performed using this option */
      if(list_created){
	ptr = list;
	search_list(ptr);       
      }
      else
	printf("\t\t\t\t{List is empty......Nothing to search for.....}\n");
      break;
    }
    case 6: /* Node is added using this option from the menu */
      if(list_created){
	ptr = list;
	list = insert_anywhere(ptr);
       	printf("\n\t\t\t\t{A Node is added to the list, Press 2 to view the list.........}\n");
      }
      else
	printf("\t\t\t\t{List is empty......First create a list.....}\n");
      break;
    case 7:{  /* Node is deleted from the list using this option from the menu */
      if(list_created){
	ptr = list;
	list = delete_node(ptr, list, &list_created);
      }
      else
	printf("\t\t\t\t{List is empty....Nothing to delete.....}\n");
      break;
    }
    case 8: {    /* entire list is deleted using this option */
      if(list_created){
	printf("\t\t\t\t\t{Entire list is deleted now, Press 2 to view the list.........}\n");
	ptr = list;
	list = delete_entirelist(ptr);
	list_created = false;    //Once the list is deleted, set the flag created to false to indicate it is empty
      }
      else
	printf("\t\t\t\t{List is empty.... Nothing to delete...}\n");
      break;
    }
    case 9:{
      system("clear");
      break;
    }
    case 10:
      printf("\t\t\t\t\t\t{Good Bye!}\n");
      exit(0);                  //succefully exits......
      break;
    }
  }while(choice >=1&&choice <=10);
  
  printf("\n");
  return (0);
}
