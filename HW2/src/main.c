#include <string.h>
#include <stdlib.h>
#include "address_t.h"
#include <mysql.h>
struct address_t *head = NULL;
int main(void){
	char *menu_selection; //holds input from the user in string format
	int selection;        //holds input from the user in integer format
//	read_file();
	my_connect();
	read_db();
	//main part of the program continues to loop through the menu until the user chooses to exit
	while(1){
		puts("***********************************");
		printf("* %19s %13s\n", "Menu","*");
		printf("%s %18s\n", "* 1) Add address","*");
		printf("%s %14s\n","* 2) Look up address","*");
		printf("%s %15s\n","* 3) Update address","*");
		printf("%s %15s\n","* 4) Delete address","*");
		printf("%s %17s\n","* 5) Display list","*");
		printf("%s %1s\n","* 6) Display aliases for location","*");
		printf("%s %17s\n","* 7) Save to file","*");
		printf("%s %25s\n","* 8) Quit","*");
		puts("***********************************");

		menu_selection = get_input(stdin); //collects user input as a string
		if((sscanf(menu_selection, "%d", &selection)) != 1 || selection < 1 || selection > 8){
			puts("\n\nincorrect input please try again\n\n"); //verifies user input and saves it as an int
		}else{
			switch(selection){
				case 1: 
				add_address();
				break;

				case 2:
				look_up_address();
				break;								

				case 3:
				update_address();	
				break;

				case 4:
				delete_address();
				break;

				case 5:
				display_list(); //prints out the linked list
				break;
				
				case 6:
				aliases_for_location();
				break;

				case 7:
				save_db();
				//write_file(); //saves the linked list to a file specified by the user
				break;

				case 8:
				puts("thank you for using the program");
				struct address_t *temp;
				//frees all linked list items before exiting
				while(head != NULL){
					temp = head;
					head=head->next;
					free(temp);
				}
				free(menu_selection);
				exit(0); //exits the program
			}
		}
		free(menu_selection);
	}
	return 0; 
}
