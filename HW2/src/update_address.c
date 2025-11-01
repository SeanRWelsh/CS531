#include "address_t.h"
#include <stdlib.h>

void update_address(){
	int is_valid = 0;
	int octet[4];
	char *alias, *address;

	puts("please enter the alias for the address you would like to update");
	alias = get_input(stdin); //collects user input for an alias as a string
	struct address_t *update = find_address(alias); //if the address a user is looking for is found the node containing it is saved to current
	if(update == NULL){
		puts("No address with that alias in the list");
	}else{
		puts("current item selected");
		printf("%-15s %-10s\n", "Address", "Alias");
		display_list_itemf(update); //prints out node that will be modified
		puts("please enter a new address");
		address = get_input(stdin); //collects user input for an address as a string

		if(sscanf(address, "%d.%d.%d.%d", &octet[0], &octet[1], 
					&octet[2], &octet[3]) != 4){
			puts("syntax error no updates were made please try again");
		}else{
			struct address_t *current = head;
			while(current != NULL){
				if(is_duplicate_address(current->octet, octet) == 1){
					puts("update could not be completed. This address is already in the list");
					is_valid +=1;
					break;
				}
				current = current->next;
			}
			if(is_octet_in_range(octet) == 1){
				is_valid +=1;
				puts("update could not be completed. An octet is out of range");
			}else if(is_valid == 0){
				update->octet[0] = octet[0];
				update->octet[1] = octet[1];
				update->octet[2] = octet[2];
				update->octet[3] = octet[3];
				display_list_itemf(update); //prints out node after it has been modified
			}
		}
		free(address);
	}
	free(alias);
}
