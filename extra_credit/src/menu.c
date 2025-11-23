/***********************************************************************************************************************
  Author:         S. M. Sainju
  Files:          Menu.c
  Functions:      int menu()
  Purpose:        The function in this file provides a menu. User makes a choice. Based on the selection
                  program does a specific task.
  Limitation:  
  Date:           September 20, 2025
  Last Modified:  October 10, 2025
  
**************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "listheader.h"

int menu(){
  int choice;
  /* This is the main menu for the program */
  do{
    printf("\n\t\t\t\t\t\t Main Menu\n");
    printf("\n\t\t\t\t\t1. Create a Linked List of Names");
    printf("\n\t\t\t\t\t2. Display the Linked List");
    printf("\n\t\t\t\t\t3. Reverse the Linked List");
    printf("\n\t\t\t\t\t4. Sort the Linked List");
    printf("\n\t\t\t\t\t5. Search a name");
    printf("\n\t\t\t\t\t6. Add a node at a random position");
    printf("\n\t\t\t\t\t7. Delete a node from the Linked List");
    printf("\n\t\t\t\t\t8. Delete the entire Linked List");
    printf("\n\t\t\t\t\t9. Clear the screen");
    printf("\n\t\t\t\t\t10. Quit");
    printf("\n\n\t\t\t\t\t Enter your choice: ==>  ");
    
    if(scanf("%d", &choice) !=1){
      choice = 100;
      printf("\n\t\t\t\t\t\tInvalid input, Not an integer...\n");
      int c;
      while((c=getchar())!='\n' && c !=EOF);  // cleans buffer
      continue;      // start the loop again ....
    }
    if (choice <1 || choice >10)
      printf("\n\t\t\t\t\t\tInvalid Choice.... Enter your choice again.....\n");
  }while (choice <1|| choice >10);
  
  return choice;
}
