#include "address_t.h"
#include <stdlib.h>
#include <string.h>

void delete_address(){
	char *alias; //string pointer for user input
	puts("please enter the alias for the address you would like to delete");
	alias = get_input(stdin); //collects user input for an alias as a string
	struct address_t *delete = find_address(alias); //if the address a user is looking for is found the node containing it is saved to current
	if(delete == NULL){
		puts("No address with that alias in the list");
	}else{
		char *confirm;
		printf("%s", "are you sure you want to delete ");
		display_list_item(delete);
		printf("%s","[y/n]");
		confirm = get_input(stdin);
		if(strcasecmp(confirm, "y") == 0){
			printf("%s", "deleting ");
			display_list_item(delete);
			delete_list_item(delete);
		}else{
			puts("ok no items deleted");
		}
		free(confirm);
	}
	free(alias);
}
