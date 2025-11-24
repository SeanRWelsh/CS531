#include "address_t.h"
#include <stdlib.h>

/* collects address information from a user and then attempts to find it in the
 * tree. If found node information is printed out otherwise it lets the user
 * know that no address was found
 */
void look_up_address(){
	char *alias;
	puts("please enter the alias you would like the address for");
	alias = get_input(stdin); //collects user input for an alias as a string
	struct address_t *current = NULL;
	current = find_address(head, alias); //if the address a user is looking for
																			 //is found the node containing it is 
																			 //saved to current
	if(current == NULL){
		puts("no address found");
	}else{
		puts("address found!!");
		printf("%-15s %-10s\n", "Address", "Alias");
		display_tree_item(current);
	}
	free(alias);
}
