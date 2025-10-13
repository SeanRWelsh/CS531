#include <string.h>
#include <stdlib.h>
#include "read_files.h"


struct address_t *head = NULL;
int main(void){
	char *menu_selection; //holds input from the user in string format
	int selection;        //holds input from the user in integer format

	read_file(); //read in data from file CS531.txt

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
				char *address, *alias; //string pointers for holding user input
				int octet[4];          //integer array for holding an address that a user input

				case 1: //add address to the linked list
				puts("please enter and IPV4 address with a format between 0.0.0.0 and 255.255.255.255");
				address = get_input(stdin); //collects user input for an address as a string
				puts("please enter and alias for this address no longer than 10 characters");
				alias = get_input(stdin); //collects user input for an alias as a string
				int combined_len = strlen(address) +1 +strlen(alias) + 1;
				char *combined_string = malloc(combined_len);
				snprintf(combined_string, combined_len, "%s %s", address, alias);
				add_to_list(combined_string);
				//add_to_list(strcat(strcat(address, " "), alias)); //verifies user input and if in appropriate ranges adds to list
				free(combined_string);
				free(address);
				free(alias);
				break;

				case 2:
				puts("please enter the alias you would like the address for");
				alias = get_input(stdin); //collects user input for an alias as a string
				struct address_t *current = NULL;
				current = find_address(alias); //if the address a user is looking for is found the node containing it is saved to current
				if(current == NULL){
					puts("no address found");
				}else{
					puts("address found!!");
					printf("%-15s %-10s\n", "Address", "Alias");
					display_list_item(current);
				}
				free(alias);
				break;

				case 3:
				puts("please enter the alias for the address you would like to update");
				alias = get_input(stdin); //collects user input for an alias as a string
				struct address_t *update = find_address(alias); //if the address a user is looking for is found the node containing it is saved to current
				if(update == NULL){
					puts("No address with that alias in the list");
				}else{
					puts("current item selected");
					printf("%-15s %-10s\n", "Address", "Alias");
					display_list_item(update); //prints out node that will be modified
					puts("please enter a new address");
					address = get_input(stdin); //collects user input for an address as a string
					sscanf(address, "%d.%d.%d.%d", &octet[0], &octet[1], 
							&octet[2], &octet[3]); //converts string address to octet array
					if(is_duplicate_address(update->octet, octet) == 1){
						puts("update could not be completed. This address is already in the list");
					}else if(is_octet_in_range(octet) ==1){
						puts("update could not be completed. An octet is out of range");
					}else{
						update->octet[0] = octet[0];
						update->octet[1] = octet[1];
						update->octet[2] = octet[2];
						update->octet[3] = octet[3];
					}
				}
				display_list_item(update); //prints out node after it has been modified
				free(alias);
				free(address);
				break;

				case 4:
				puts("please enter the alias for the address you would like to update");
				alias = get_input(stdin); //collects user input for an alias as a string
				struct address_t *delete = find_address(alias); //if the address a user is looking for is found the node containing it is saved to current
				if(delete == NULL){
					puts("No address with that alias in the list");
				}else{
					delete_list_item(delete);
				}
				free(alias);
				break;

				case 5:
				display_list(); //prints out the linked list
				break;
				
				case 6:
				int len, octet1, octet2, is_valid = 0;
				char *user_input;

				while(is_valid == 0){
					puts("please enter the first address octet (0-255)");
					user_input = get_input(stdin); //collects the first octet from the user as a string
					len = sscanf(user_input, "%d", &octet1); //converts address from a string to an int. If successfull saves 1 in len
					if(octet1 < 0 || octet1 > 255 || len != 1){
						puts("invalid input please try again");
					}else{
						is_valid = 1;
					}
					free(user_input);
					len = 0;
				}

				is_valid = 0;

				while(is_valid == 0){
					puts("please enter the first address octet (0-255)");
					user_input = get_input(stdin); //collects the first octet from the user as a string
					int len = sscanf(user_input, "%d", &octet2); //converts address from a string to an int. If successfull saves 1 in len
					if(octet2 < 0 || octet2 > 255 || len != 1){
						puts("invalid input please try again");
					}else{
						is_valid = 1;
					}
					free(user_input);
					len = 0;
				}

				print_location_list(octet1, octet2); //prints out nodes in the location specified by the user or an error message if none
				break;

				case 7:
				write_file(); //saves the linked list to a file specified by the user
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
	}
	return 0;
}
