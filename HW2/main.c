#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_files.h"


struct address_t *head = NULL;
int main(void){
	char *user_input;
	int selection;

	/*	struct address_t *head = (struct address_t*)malloc(sizeof(struct address_t));
		head-> next = NULL;*/

	read_file();

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

		user_input = get_input(stdin);
		if((sscanf(user_input, "%d", &selection)) != 1 || selection < 1 || selection > 8){
			puts("\n\nincorrect input please try again\n\n");
		}else{
			switch(selection){
				char *address, *alias;
				int octet[4];
				case 1:
					puts("please enter and IPV4 address with a format between 0.0.0.0 and 255.255.255.255");
					address = get_input(stdin);
					puts("please enter and alias for this address no longer than 10 characters");
					alias = get_input(stdin);
					add_to_list(strcat(strcat(address, " "), alias));
					free(address);
					free(alias);
					break;
				case 2:
					puts("please enter the alias you would like the address for");
					alias = get_input(stdin);
					struct address_t *current = NULL;
					current = find_address(alias);
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
					alias = get_input(stdin);
					struct address_t *update = find_address(alias);
					if(update == NULL){
						puts("No address with that alias in the list");
					}else{
						puts("current item selected");
						printf("%-15s %-10s\n", "Address", "Alias");
						display_list_item(update);
						puts("please enter a new address");
						address = get_input(stdin);
						sscanf(address, "%d.%d.%d.%d", &octet[0], &octet[1], 
						       &octet[2], &octet[3]);
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
						display_list_item(update);
						free(alias);
						free(address);
					break;
				case 4:
					puts("please enter the alias for the address you would like to update");
					alias = get_input(stdin);
					struct address_t *delete = find_address(alias);
					if(delete == NULL){
						puts("No address with that alias in the list");
					}else{
						delete_list_item(delete);
					}
					free(alias);

					break;
				case 5:
					display_list();
					break;
				case 6:
					int len, octet1, octet2, is_valid = 0;
					char *user_input;
					
					while(is_valid == 0){
					puts("please enter the first address octet (0-255)");
						user_input = get_input(stdin);
						len = sscanf(user_input, "%d", &octet1);
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
						user_input = get_input(stdin);
						int len = sscanf(user_input, "%d", &octet2);
						if(octet2 < 0 || octet2 > 255 || len != 1){
							puts("invalid input please try again");
						}else{
							is_valid = 1;
						}
						free(user_input);
						len = 0;
					}

					print_location_list(octet1, octet2);


					break;
				case 7:
					printf("%d", selection);
					break;
				case 8:
					puts("thank you for using the program");
					exit(0);	

			}
		}
	}
	free(user_input);
	return 0;
}
