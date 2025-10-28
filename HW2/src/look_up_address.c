#include "address_t.h"
#include <stdlib.h>
void look_up_address(){
	char *alias;
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
}
