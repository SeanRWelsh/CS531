#include "address_t.h"
#include <stdlib.h>
#include <string.h>

/*
 * requests an alias from the user. If no entry found informs the user and 
 * returns to caller. If the alias is found removes it from the tree
 */
void delete_address(){
	char *alias; //string pointer for user input
	puts("please enter the alias for the address you would like to delete");
	alias = get_input(stdin); //collects user input for an alias as a string

	/*if the address a user is looking for is found the node containing it is
	 * saved to *delete
	 */
	struct address_t *delete = find_address(head, alias); 
	if(delete == NULL){
		puts("No address with that alias in the tree");
	}else{
		char *confirm;
		printf("%s", "are you sure you want to delete ");
		display_tree_item(delete);
		printf("%s","[y/n]");
		confirm = get_input(stdin);
		if(strcasecmp(confirm, "y") == 0){
			printf("%s", "deleting ");
			display_tree_item(delete);
			delete_tree_item(delete);
		}else{
			puts("ok no items deleted");
		}
		free(confirm);
	}
	free(alias);
}
