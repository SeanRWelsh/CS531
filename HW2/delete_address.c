#include "address_t.h"
#include <stdlib.h>

void delete_address(){
	char *alias; //string pointer for user input
	puts("please enter the alias for the address you would like to delete");
	alias = get_input(stdin); //collects user input for an alias as a string
	struct address_t *delete = find_address(alias); //if the address a user is looking for is found the node containing it is saved to current
	if(delete == NULL){
		puts("No address with that alias in the list");
	}else{
		printf("%s", "deleting ");
		display_list_item(delete);
		delete_list_item(delete);
	}
	free(alias);
}
