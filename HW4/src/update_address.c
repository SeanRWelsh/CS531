#include "address_t.h"
#include <stdlib.h>

/*
 * requests an alias from the user. If no entry with that alias is found
 * informs the user and returns to caller. If an entry with that alias is found
 * requests the new address from the user. If new address is valid and not
 * already in the list then the node is updated with the new address. Otherwise
 * inform the user and return to caller
 */
void update_address(){
	int octet[4];
	char *alias, *address;

	puts("please enter the alias for the address you would like to update");
	alias = get_input(stdin); //collects user input for an alias as a string

	/* if the address a user is looking for is found the node containing it is 
	 * saved to current
	 */
	struct address_t *update = find_address(head, alias); 
	if(update == NULL){
		puts("No address with that alias in the tree");
		free(alias);
		return;
	}
	
	puts("current item selected");
	printf("%-15s %-10s\n", "Address", "Alias");
	display_tree_item(update); //prints out node that will be modified
	puts("please enter a new address");
	address = get_input(stdin); //collects user input for an address as a string

	if(sscanf(address, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3])
		 != 4){
		puts("syntax error no updates were made please try again");
		free(address);
		free(alias);
		return;
	}
	
	//if duplicate address inform user and return to caller
	if(is_duplicate_address(head, octet) == 1){
		puts("update could not be completed. This address is already in the tree");
		free(address);
		free(alias);
		return;
	}

	//if an octect out of range inform user and return to caller
	if(is_octet_in_range(octet) == 1){
		puts("update could not be completed. An octet is out of range");
		free(address);
		free(alias);
		return;
	}
	
	//update address to new address
	update->octet[0] = octet[0];
	update->octet[1] = octet[1];
	update->octet[2] = octet[2];
	update->octet[3] = octet[3];
	display_tree_item(update); //prints out node after it has been modified
	free(address);
	free(alias);
}
